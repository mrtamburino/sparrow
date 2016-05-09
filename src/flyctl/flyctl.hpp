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
    
    DEFINE_APP_EXCEPTION(InitializeException, "Subsystems initialization error!");
    
    typedef enum {boardctrl, motorsctrl, instumentsctrl, flyassistant, numSubsystems} subsystems_t;
    typedef enum { quadricopter=4, esocopter=6, octocopter=8 } multirotor_t;
    typedef double motor_power_t;
 
    
    class MotorCtrl
    {
    public:
        MotorCtrl(void):_fPower(0){}
        virtual ~MotorCtrl(){}

        virtual void operator<<(MotorCtrl&, const motor_power_t)=0;
        
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
    
    class SystemMgr
    {
    public:
        
        SystemMgr(const multirotor_t eMoltirotor_IN):_eMotorsNum(eMoltirotor_IN){}
        virtual ~SystemMgr(){}
        
        virtual void initializeSubsystems(void) = 0;
        virtual void shutDownSubsystems(void) = 0;
        
        virtual FlyAssistant* getFlyAssistant(void) = 0;
        virtual MotorCtrl* getMotorCtrl(unsigned char) = 0;
        
    protected:
        multirotor_t _eMotorsNum;

    };
    
}

#endif /* FLYCTL_HPP */

