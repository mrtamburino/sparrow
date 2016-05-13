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
#include "vehiclemgr.hpp"

namespace sparrow
{
    
    class SparrowMgr;
    
    DEFINE_APP_EXCEPTION(InitializeException, "Subsystems initialization error!");

    
    class VehicleFactory
    {
        public:
            static void initSystemsFor(sfa::multirotor_t);
            static VehicleMgr* getVehicleMgr(void);
            
        private:
            static SparrowMgr sparrowMgr;

    };

    
}

#endif /* SPARROW_HPP */

