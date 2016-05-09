/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sparrow.hpp
 * Author: ale
 *
 * Created on May 7, 2016, 8:44 PM
 */

#ifndef SPARROW_HPP
#define SPARROW_HPP

#include "flyctl/flyctl.hpp"
#include "hal/hal.hpp"
#include "spwlog.hpp"
#include "spwflymgr.hpp"

namespace sfa
{
    
    DEFINE_APP_EXCEPTION(InitializeException, "Subsystems initialization error!");

    enum instruments{ accelerometer=0, gyroscope, instrumentsNum};

    
    class SparrowVehicleMgr
    {
    public:
        SparrowVehicleMgr(void):_eMotorsNum(0),
                                _ptrBoardCtrl(NULL),
                                _ptrMotorsCtrl(NULL),
                                _ptrInstrumnentsCtrl(NULL),
                                _ptrFlyAssistant(NULL){}
       // SparrowVehicleMgr(const multirotor_t eMoltirotor_IN);
        virtual ~SparrowVehicleMgr();
        
        /*! Start and stop functions
         * 
         */
        static void initializeSubsystems(multirotor_t);
        virtual void shutDownSubsystems(void);
        
        virtual FlyAssistant* getFlyAssistant(void){return _ptrFlyAssistant;}
        static MotorCtrl* getMotorCtrl(unsigned char ucIndx_IN)
        {return (sparrowMgr._ptrMotorsCtrl && ucIndx_IN<sparrowMgr._eMotorsNum ? 
            sparrowMgr._ptrMotorsCtrl[ucIndx_IN]:
            NULL);}

        
    protected:
        
        virtual void _initBoardCtrl(void);
        virtual void _initMotorsCtrl(void);
        virtual void _initInstrumentsCtrl(void);
        virtual void _initFlyAssistant(void);
        
    private:
        
        static SparrowVehicleMgr sparrowMgr;
        
        unsigned char _eMotorsNum;
        hal::BoardCtrl* _ptrBoardCtrl;
        MotorCtrl**      _ptrMotorsCtrl;
        InstrumentCtrl** _ptrInstrumnentsCtrl;
        FlyAssistant*   _ptrFlyAssistant;
        
        void _initializeSubsystems(unsigned char);
        void _initInstAccelerometer(void);
        void _initInstGyroscope(void);
    };

    
}

#endif /* SPARROW_HPP */

