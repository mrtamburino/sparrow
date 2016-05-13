/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vehiclemgr.hpp
 * Author: alza
 *
 * Created on May 13, 2016, 3:36 PM
 */

#ifndef VEHICLEMGR_HPP
#define VEHICLEMGR_HPP

#include "flyctl/flyctl.hpp"

namespace sparrow
{
    class VehicleMgr
    {
    public:
        virtual void initSystem(unsigned char) = 0;
        virtual sfa::FlyAssistant* getFlyAssistant(void) = 0;
    };
}

#endif /* VEHICLEMGR_HPP */

