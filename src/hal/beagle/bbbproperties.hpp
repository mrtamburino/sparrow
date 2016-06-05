/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bbbproperties.hpp
 * Author: ale
 *
 * Created on June 5, 2016, 7:23 PM
 */

#ifndef BBBPROPERTIES_HPP
#define BBBPROPERTIES_HPP

#include "../../preader.hpp"

namespace hal
{
    class BBBProperties: public PpropertiesStore
    {
    public:
        
        BBBProperties ():_sEhrPWMA0(NULL),
                        _sEhrPWMA1(NULL),
                        _sEhrPWMB0(NULL),
                        _sEhrPWMB1(NULL){}
        ~BBBProperties ();
        
        void setProperty (char* sName_IN, char*);
        char* getProperty (const char*);
        unsigned char isEmpty (const char*);

    private:
        char* _sEhrPWMA0;
        char* _sEhrPWMA1;
        char* _sEhrPWMB0;
        char* _sEhrPWMB1;
        
        void setEHRPWMA0 (char* sValue_IN);
        void setEHRPWMA1 (char* sValue_IN);
        void setEHRPWMB0 (char* sValue_IN);
        void setEHRPWMB1 (char* sValue_IN);
    };
    
}


#endif /* BBBPROPERTIES_HPP */

