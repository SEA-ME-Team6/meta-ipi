#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/racer.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build"

# $SCRIPT_DIR/build/racer -platform eglfs
$SCRIPT_DIR/racer

