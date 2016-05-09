/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   spwflymgr.hpp
 * Author: ale
 *
 * Created on May 7, 2016, 8:44 PM
 */

#ifndef SPWFLYMGR_HPP
#define SPWFLYMGR_HPP

#include "spwlog.hpp"

namespace sfa
{
    
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
        
        virtual void up(double dVel_IN){}


    };  
    
}

  


#endif