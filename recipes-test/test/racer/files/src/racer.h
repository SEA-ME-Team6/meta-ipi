#ifndef RACER_H
#define RACER_H

//#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Racer
{
public:
    Racer();
    ~Racer();

    void setGear(uint8_t gear);
    void setLight(bool light);
    void set_steering_percent(float steering);
    void set_throttle_percent(float throttle);

    uint32_t getBatttery();
    uint8_t getGear() const;
    bool getLight() const;

private:
    PyObject *pModule, *pClass, *pInstance;
    PyObject *pVoltage;
    double voltage;
   
    //original resource
    uint32_t batteryStatus; 
    uint8_t gearStatus; 
    bool lightStatus; 
};

#endif //Racer_H
