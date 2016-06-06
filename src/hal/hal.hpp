/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hal.hpp
 * Author: ale
 *
 * Created on May 7, 2016, 7:11 PM
 */

#ifndef HAL_HPP
#define HAL_HPP

namespace hal
{
    
    class PWM
    {
    public:
        PWM(){}
        virtual ~PWM(){}
        
        virtual void setDutyCycle(double) = 0;
        virtual void setFrequence(double) = 0;
    };
    
    class I2CMaster
    {
    public:
        I2CMaster(){}
        virtual ~I2CMaster(){}
        
        virtual char* read(void) = 0;
    };

    class BoardCtrl
    {
    public:
        BoardCtrl(void){}
        virtual ~BoardCtrl(void){}
        
        virtual unsigned char countPWMSignals(void) = 0;
        virtual PWM* getPWMCtrl(const unsigned char)=0;
        virtual I2CMaster* getI2CMasterChannelCtrl(const unsigned char)=0;
    };
    
    BoardCtrl* getBoardCtrl(void);
    void destroyBoardCtrl(BoardCtrl**);
}

#endif /* HAL_HPP */

