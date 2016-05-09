/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   beagleboard.hpp
 * Author: ale
 *
 * Created on May 8, 2016, 7:50 AM
 */

#ifndef BEAGLEBOARD_HPP
#define BEAGLEBOARD_HPP

#include "../hal.hpp"

#define BEAGLE_SUBSYSTEM "beagleboard"

namespace hal
{
    class BeagleBoardCtrl: public BoardCtrl
    {
    public:
        BeagleBoardCtrl(){}
        ~BeagleBoardCtrl(){}

        virtual PWM* getPWMCtrl(const unsigned char);
        virtual I2CMaster* getI2CMasterChannelCtrl(const unsigned char);
    };
}

#endif /* BEAGLEBOARD_HPP */

