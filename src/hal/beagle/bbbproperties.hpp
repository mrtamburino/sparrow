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
        
        BBBProperties ():_sEhrPWM0A(NULL),
                         _sEhrPWM0B(NULL),
                         _sEhrPWM1A(NULL),
                         _sEhrPWM1B(NULL){}
        ~BBBProperties ();
        
        void setProperty (char* sName_IN, char*);
        char* getProperty (const char*);

    private:
        char* _sEhrPWM0A;
        char* _sEhrPWM0B;
        char* _sEhrPWM1A;
        char* _sEhrPWM1B;
        
        void setEHRPWM0A (char* sValue_IN);
        void setEHRPWM0B (char* sValue_IN);
        void setEHRPWM1A (char* sValue_IN);
        void setEHRPWM1B (char* sValue_IN);
    };
    
}


#endif /* BBBPROPERTIES_HPP */

