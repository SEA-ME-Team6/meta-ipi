#include "racer.h"
#include <iostream>

Racer::Racer() {
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

Racer::~Racer() {
    Py_XDECREF(pVoltage);
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    Py_FinalizeEx();
}


void Racer::setGear(uint8_t gear){
    gearStatus = gear;
}

void Racer::setLight(bool light){
    std::cout << "Light : " << light << std::endl;
    lightStatus = light;
}

void Racer::set_steering_percent(float steering) {
    std::cout << "Steering : " << steering << std::endl;
    PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", steering);
}

void Racer::set_throttle_percent(float throttle) {
    if (gearStatus == 1 || gearStatus == 3) {
        std::cout << "Throttle : " << throttle << std::endl;
        PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", throttle);
    }
}

uint32_t Racer::getBatttery() {
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltage = PyFloat_AsDouble(pVoltage);
    batteryStatus = (uint32_t)((voltage/3-3.1)*100/1.1);
    std::cout<<"battery: " << batteryStatus << std::endl;
    return batteryStatus;
}

uint8_t Racer::getGear() const{
    return gearStatus;
}

bool Racer::getLight() const{
    return lightStatus;
}

