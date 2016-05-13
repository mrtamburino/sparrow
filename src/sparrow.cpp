/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "sparrow.hpp"
#include "stdlib.h"
#include "hdctrl.hpp"
#include "spwlog.hpp"
#include "vehiclemgr.hpp"

using namespace sparrow;

SparrowVehicleMgr VehicleFactory::sparrowMgr;


void VehicleFactory::initSystemsFor(sfa::multirotor_t eMultirotors_IN)
{
    spwILOG( "Initializing Sparrow subsystems\n");
    
    try
    {
        sparrowMgr._eMotorsNum = eMultirotors_IN;
        for(unsigned char indx = 0 ; indx < sfa::numSubsystems; indx++)
        {
            sparrowMgr._initializeSubsystems(indx);
        }
    }
    catch(composite::excps::GenericException* ge)
    {
      WRAP_EXCEPTION(InitializeException,ge);
    }
    catch(...)
    {
      THROW_EXCEPTION(InitializeException);
    }
    spwILOG( "Subsystems initialized!\n");
    
}

sfa::MotorCtrl* VehicleFactory::getMotorCtrl(unsigned char ucIndx_IN)
{
    return (sparrowMgr._ptrMotorsCtrl && ucIndx_IN<sparrowMgr._eMotorsNum ? 
        sparrowMgr._ptrMotorsCtrl[ucIndx_IN]:
        NULL);
}

sfa::FlyAssistant* VehicleFactory::getFlyAssistant(void)
{
    return (sparrowMgr._ptrFlyAssistant?sparrowMgr._ptrFlyAssistant:NULL);
}
