/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vehiclemgr.hpp
 * Author: alza
 *
 * Created on May 13, 2016, 11:39 AM
 */

#ifndef SPARROEMGR_HPP
#define SPARROWMGR_HPP

#include "stdlib.h"

# include "../../composite/src/exceptions/excps.hpp"

#include "flyctl/flyctl.hpp"
#include "hal/hal.hpp"
#include "vehiclemgr.hpp"

namespace sparrow
{
    
    enum instruments{ accelerometer=0, gyroscope, instrumentsNum};
    
    class SparrowMgr: public VehicleMgr
    {
    public:
        SparrowMgr(void):_eMotorsNum(0),
                                _ptrBoardCtrl(NULL),
                                _ptrMotorsCtrl(NULL),
                                _ptrInstrumnentsCtrl(NULL),
                                _ptrFlyAssistant(NULL){}
        virtual ~SparrowMgr();
        
        virtual void initSystem(unsigned char);
        
        /*! Start and stop functions
         * 
         */
        virtual sfa::FlyAssistant* getFlyAssistant(void){return _ptrFlyAssistant;}
       

        
    protected:
        
        void _initSubsystem(unsigned char);
        void _shutDownSubsystems(void);
        
        
    private:

        unsigned char _eMotorsNum;
        hal::BoardCtrl* _ptrBoardCtrl;
        sfa::MotorCtrl**      _ptrMotorsCtrl;
        sfa::InstrumentCtrl** _ptrInstrumnentsCtrl;
        sfa::FlyAssistant*   _ptrFlyAssistant;
        
        
        void _initInstAccelerometer(void);
        void _initInstGyroscope(void);
        void _initBoardCtrl(void);
        void _initMotorsCtrl(void);
        void _initInstrumentsCtrl(void);
        void _initFlyAssistant(void);
        
        friend class VehicleFactory;
    };
    
    // Exception definition
    DEFINE_APP_EXCEPTION(FewPWMSignalsException, "Not enought PWM signals availabe!");
    
}

#endif /* VEHICLEMGR_HPP */

