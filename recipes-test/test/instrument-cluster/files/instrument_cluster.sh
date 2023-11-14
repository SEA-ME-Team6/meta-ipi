#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/instrument_cluster.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build"

$SCRIPT_DIR/instrument_cluster -platform linuxfb
# $SCRIPT_DIR/build/instrument_cluster

