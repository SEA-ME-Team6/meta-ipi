#!/bin/sh

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/head-unit.ini"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SCRIPT_DIR/build"

$SCRIPT_DIR/build/head_unit

