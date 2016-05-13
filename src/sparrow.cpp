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

SparrowVehicleMgr VehicleFactory::vehicleMgr;


void VehicleFactory::initSystemsFor(sfa::multirotor_t eMultirotors_IN)
{
    spwILOG( "Initializing Sparrow subsystems\n");
    
    try
    {
        vehicleMgr._eMotorsNum = eMultirotors_IN;
        for(unsigned char indx = 0 ; indx < sfa::numSubsystems; indx++)
        {
            vehicleMgr._initializeSubsystems(indx);
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
    return (vehicleMgr._ptrMotorsCtrl && ucIndx_IN<vehicleMgr._eMotorsNum ? 
        vehicleMgr._ptrMotorsCtrl[ucIndx_IN]:
        NULL);
}

sfa::FlyAssistant* VehicleFactory::getFlyAssistant(void)
{
    return (vehicleMgr._ptrFlyAssistant?vehicleMgr._ptrFlyAssistant:NULL);
}
