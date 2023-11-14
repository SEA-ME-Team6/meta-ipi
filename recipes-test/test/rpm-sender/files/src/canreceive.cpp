#include "canreceive.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

CanReceive::CanReceive(const char* interface_name) : ifname(interface_name), filtered_rpm(0), prev_filtered_rpm(0), alpha(0.7), threshold(0.01) {
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Error while opening socket");
        exit(-1);
    }

    std::strcpy(ifr.ifr_name, ifname);
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family  = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error in socket bind");
        exit(-2);
    }
}

CanReceive::~CanReceive() {
    close(s);
}

float CanReceive::getRpm() {
    float current_rpm =0;
    int nbytes = read(s, &frame, sizeof(struct can_frame));

    //Receiveing CAN data
    if (nbytes < 0) {
        perror("Error reading from CAN socket");
        return false;
    }
    std::memcpy(&current_rpm, frame.data, sizeof(float));
    // float current_speed = rpm * (2 * M_PI * WheelRadius);
    
    //Filtering
    if (current_rpm < threshold) {
        filtered_rpm = 0;
        prev_filtered_rpm = 0;
    }
    else {
    	filtered_rpm = alpha * current_rpm + (1 - alpha) * prev_filtered_rpm;
    	prev_filtered_rpm = filtered_rpm;
    }

    std::cout << "Origin Speed: " << current_rpm << std::endl;
    std::cout << "Filltering Speed: " << filtered_rpm << std::endl;

    return filtered_rpm;
}