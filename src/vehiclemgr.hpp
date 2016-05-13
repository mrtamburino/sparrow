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

#ifndef VEHICLEMGR_HPP
#define VEHICLEMGR_HPP

#include "stdlib.h"
#include "flyctl/flyctl.hpp"
#include "hal/hal.hpp"

namespace sparrow
{
    
    enum instruments{ accelerometer=0, gyroscope, instrumentsNum};
    
    class SparrowVehicleMgr
    {
    public:
        SparrowVehicleMgr(void):_eMotorsNum(0),
                                _ptrBoardCtrl(NULL),
                                _ptrMotorsCtrl(NULL),
                                _ptrInstrumnentsCtrl(NULL),
                                _ptrFlyAssistant(NULL){}
        virtual ~SparrowVehicleMgr();
        
        /*! Start and stop functions
         * 
         */
        virtual void shutDownSubsystems(void);
        virtual sfa::FlyAssistant* getFlyAssistant(void){return _ptrFlyAssistant;}

        
    protected:
        
        virtual void _initBoardCtrl(void);
        virtual void _initMotorsCtrl(void);
        virtual void _initInstrumentsCtrl(void);
        virtual void _initFlyAssistant(void);
        
    private:

        unsigned char _eMotorsNum;
        hal::BoardCtrl* _ptrBoardCtrl;
        sfa::MotorCtrl**      _ptrMotorsCtrl;
        sfa::InstrumentCtrl** _ptrInstrumnentsCtrl;
        sfa::FlyAssistant*   _ptrFlyAssistant;
        
        void _initializeSubsystems(unsigned char);
        void _initInstAccelerometer(void);
        void _initInstGyroscope(void);
        
        friend class VehicleFactory;
    };
    
}

#endif /* VEHICLEMGR_HPP */

