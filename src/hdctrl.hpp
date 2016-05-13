/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hdctrl.hpp
 * Author: ale
 *
 * Created on May 9, 2016, 6:09 AM
 */

#ifndef HDCTRL_HPP
#define HDCTRL_HPP

#include "flyctl/fclog.hpp"
#include "hal/hal.hpp"
#include "spwlog.hpp"

namespace sparrow
{
    class BLDCCtrl: public sfa::MotorCtrl
    {
    public:
        BLDCCtrl(hal::PWM* ptrPWN_IN):sfa::MotorCtrl(),_ptrPWMCtrl(ptrPWN_IN)
        {
            spwIMLOG(SPARROW_SUBMODULE_MOTORCTRL, "Initializing BLDC Motor controller\n");
        }
        virtual ~BLDCCtrl(){}

        void setPower(const sfa::motor_power_t dPower_IN)
        {
             _ptrPWMCtrl->setDutyCycle (dPower_IN);
        }
        
        void setPWMFrequency(const sfa::motor_power_t dFreq_IN)
        {
            _ptrPWMCtrl->setFrequence (dFreq_IN);
        }
        
    protected:
        hal::PWM* _ptrPWMCtrl;
    };
    
    class I2CInstrumentCtrl: public sfa::InstrumentCtrl
    {
    public:
        I2CInstrumentCtrl(hal::I2CMaster* prtrI2CMaterCtrl_IN):_ptrI2CMaterCtrl(prtrI2CMaterCtrl_IN){}
        virtual ~I2CInstrumentCtrl(){}

        virtual char* read(void){return _ptrI2CMaterCtrl->read();}
        
    protected:
        hal::I2CMaster* _ptrI2CMaterCtrl;
    };
    
    class AccelerometerCtrl: public I2CInstrumentCtrl
    {
    public:
        AccelerometerCtrl(hal::I2CMaster* prtrI2CMaterCtrl_IN):
            I2CInstrumentCtrl(prtrI2CMaterCtrl_IN)
        {
            spwIMLOG(SPARROW_SUBMODULE_ACCELEROMETERCTRL, "Initializing Accelerometer controller\n");
        }
            
        virtual ~AccelerometerCtrl()
        {
            spwIMLOG(SPARROW_SUBMODULE_ACCELEROMETERCTRL, "Shut down Accelerometer controller\n");
        }
        
    };
    
    class GyroscopeCtrl: public I2CInstrumentCtrl
    {
    public:
        GyroscopeCtrl(hal::I2CMaster* prtrI2CMaterCtrl_IN):
            I2CInstrumentCtrl(prtrI2CMaterCtrl_IN)
        {
            spwIMLOG(SPARROW_SUBMODULE_GYROSCOPECTRL, "Initializing Gyroscope controller\n");
        }
            
        virtual ~GyroscopeCtrl()
        {
            spwIMLOG(SPARROW_SUBMODULE_GYROSCOPECTRL, "Shut down Gyroscope controller\n");
        }
        
    };
}

#endif /* HDCTRL_HPP */

