/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   flyctl.hpp
 * Author: ale
 *
 * Created on May 7, 2016, 7:02 PM
 */

#ifndef FLYCTL_HPP
#define FLYCTL_HPP

#include "fclog.hpp"
#include "../../../composite/src/exceptions/excps.hpp"

namespace sfa
{
    
    typedef enum {e_boardctrl, e_motorsctrl, e_instumentsctrl, e_flyassistant, e_numSubsystems} subsystems_t;
    typedef enum { e_quadricopter=4, e_esocopter=6, e_octocopter=8 } multirotor_t;
    typedef double motor_power_t;
 
    
    class MotorCtrl
    {
    public:
        MotorCtrl(void):_fPower(0){}
        virtual ~MotorCtrl(){}

        virtual void setPower(const motor_power_t)=0;
        
        void powerOff(void){setPower(0);}
        
    protected:
        motor_power_t _fPower;
    };
    
    class InstrumentCtrl
    {
    public:
        InstrumentCtrl(void){}
        virtual ~InstrumentCtrl(){}
        
        virtual char* read(void) = 0;

    };
    
    class FlyAssistant
    {
    public:
        FlyAssistant(){}
        virtual ~FlyAssistant(){}
        
        virtual void up(double) = 0;
    };

    
}

#endif /* FLYCTL_HPP */

