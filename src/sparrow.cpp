/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "sparrow.hpp"
#include "stdlib.h"
#include "hdctrl.hpp"
#include "spwlog.hpp"
#include "sparrowmgr.hpp"

using namespace sparrow;

SparrowMgr VehicleFactory::sparrowMgr;


VehicleMgr* VehicleFactory::initSystemsFor(sfa::multirotor_t eMultirotors_IN)
{
    sparrowMgr.initSystem(eMultirotors_IN); 
    return (&sparrowMgr);
}


