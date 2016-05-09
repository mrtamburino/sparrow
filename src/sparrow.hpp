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

namespace sfa
{
    
    enum instruments{ accelerometer=0, gyroscope, instrumentsNum};
    
    class SparrowFlyAssistant: public FlyAssistant 
    {
    public:
        SparrowFlyAssistant()
        {
            spwIMLOG(SPARROW_SUBMODULE_FLYASSISTAN, "Initializing Fly Assistant\n");
        }
        virtual ~SparrowFlyAssistant()
        {
            spwIMLOG(SPARROW_SUBMODULE_FLYASSISTAN, "Shut down Fly Assistant\n");
        }

        
    };
    
    class Sparrow: public System_i
    {
    public:
        
        Sparrow(const multirotor_t eMoltirotor_IN);
        virtual ~Sparrow();
        
        virtual void shutDownSubsystems(void);
        virtual FlyAssistant* getFlyAssistant(void){return _ptrFlyAssistant;}
        virtual MotorCtrl* getMotorCtrl(unsigned char ucIndx_IN)
        {return (_ptrMotorsCtrl && ucIndx_IN<_eMotorsNum ? 
            _ptrMotorsCtrl[ucIndx_IN]:
            NULL);}
        
    protected:
        
        virtual void _initBoardCtrl(void);
        virtual void _initMotorsCtrl(void);
        virtual void _initInstrumentsCtrl(void);
        virtual void _initFlyAssistant(void);
        
        
        
    private:
        hal::BoardCtrl* _ptrBoardCtrl;
        MotorCtrl**      _ptrMotorsCtrl;
        InstrumentCtrl** _ptrInstrumnentsCtrl;
        FlyAssistant*   _ptrFlyAssistant;
        
        void _initInstAccelerometer(void);
        void _initInstGyroscope(void);
    };

    
}

#endif /* SPARROW_HPP */
