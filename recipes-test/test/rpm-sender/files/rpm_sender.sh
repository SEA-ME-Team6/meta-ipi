#!/bin/sh

# Real CAN
#sudo ifconfig can0 down
#sudo ip link set can0 up type can bitrate 500000 dbitrate 8000000 restart-ms 1000 berr-reporting on fd on

# Virtual CAN
# sudo modprobe vcan
# sudo ip link add dev can0 type vcan
# sudo ip link set up can0

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/rpm_sender.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build"

# $SCRIPT_DIR/build/rpm_sender -platform eglfs
$SCRIPT_DIR/build/rpm_sender

