#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/gamepad.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build"

# $SCRIPT_DIR/build/gamepad -platform eglfs
$SCRIPT_DIR/gamepad

