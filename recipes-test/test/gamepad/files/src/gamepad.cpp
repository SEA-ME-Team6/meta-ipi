#include "gamepad.h"
#include <iostream>

Gamepad::Gamepad() {
    Py_Initialize();
    pGModule = PyImport_ImportModule("piracer.gamepads");
    pGClass = PyObject_GetAttrString(pGModule, "ShanWanGamepad");
    pGInstance = PyObject_CallObject(pGClass, NULL);
}

Gamepad::~Gamepad() {
    Py_XDECREF(pInputBY);
    Py_XDECREF(pInputLX);
    Py_XDECREF(pInputRY);
    Py_XDECREF(pInputL);
    Py_XDECREF(pInputR);
    Py_XDECREF(pInput);

    Py_XDECREF(pGInstance);
    Py_XDECREF(pGClass);
    Py_XDECREF(pGModule);
    Py_FinalizeEx();
}

void Gamepad::read_data() {
    pInput = PyObject_CallMethod(pGInstance, "read_data", NULL);

    pInputL = PyObject_GetAttrString(pInput, "analog_stick_left");
    pInputLX = PyObject_GetAttrString(pInputL, "x");
    gamepad_inputLX = (float)PyFloat_AsDouble(pInputLX);

    pInputR = PyObject_GetAttrString(pInput, "analog_stick_right");
    pInputRY = PyObject_GetAttrString(pInputR, "y");
    gamepad_inputRY = (float)PyFloat_AsDouble(pInputRY);

    pInputBY = PyObject_GetAttrString(pInput, "button_x");
    gamepad_inputBY = (bool)PyFloat_AsDouble(pInputBY);
}

float Gamepad::get_inputLX() const {
    return gamepad_inputLX;
}

float Gamepad::get_inputRY() const {
    return gamepad_inputRY;
}

bool Gamepad::get_inputBY() const {
    return gamepad_inputBY;
}
