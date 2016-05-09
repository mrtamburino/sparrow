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

#include "../hal/hal.hpp"
#include "fclog.hpp"
#include "../../../composite/src/exceptions/excps.hpp"

namespace sfa
{
    
    DEFINE_APP_EXCEPTION(InitializeException, "Subsystems initialization error!");
    
    typedef enum { quadricopter=4, esocopter=6, octocopter=8 } multirotor_t;
    typedef double motor_power_t;
 
    
    class MotorCtrl
    {
    public:
        MotorCtrl(void):_fPower(0){}
        virtual ~MotorCtrl(){}

        virtual void operator<<(const motor_power_t gPower_IN)=0;
        
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
        //virtual void getInitialPosition(void);
    };
    
    class System_i
    {
    public:
        
        System_i(const multirotor_t eMoltirotor_IN):_eMotorsNum(eMoltirotor_IN){}
        virtual ~System_i(){}
        
        virtual void initializeSubsystems(void);
        virtual void shutDownSubsystems(void) = 0;
        
        virtual FlyAssistant* getFlyAssistant(void) = 0;
        virtual MotorCtrl* getMotorCtrl(unsigned char)=0;
        
    protected:
        multirotor_t _eMotorsNum;
        
        virtual void _initBoardCtrl(void) = 0;
        virtual void _initMotorsCtrl(void) = 0;
        virtual void _initInstrumentsCtrl(void) = 0;
        virtual void _initFlyAssistant(void) = 0;
    };
    
}

#endif /* FLYCTL_HPP */

