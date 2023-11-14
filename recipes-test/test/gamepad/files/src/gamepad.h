#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Gamepad
{
public:
    Gamepad();
    ~Gamepad();

    void read_data();
    float get_inputLX() const;
    float get_inputRY() const;
    bool get_inputBY() const;

private:
    PyObject *pGModule, *pGClass, *pGInstance;
    PyObject *pInput, *pInputL, *pInputR, *pInputLX, *pInputRY, *pInputBY;
    float gamepad_inputLX, gamepad_inputRY;
    bool gamepad_inputBY;
};