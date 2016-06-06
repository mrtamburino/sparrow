/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string.h>
#include "bbbproperties.hpp"

hal::BBBProperties::~BBBProperties ()
{
  if(_sEhrPWM0A)
    {
      free(_sEhrPWM0A);
      _sEhrPWM0A = NULL;
    }
  
  if(_sEhrPWM0B)
    {
      free(_sEhrPWM0B);
      _sEhrPWM0B = NULL;
    }
  
  if(_sEhrPWM1A)
    {
      free(_sEhrPWM1A);
      _sEhrPWM1A = NULL;
    }
  
  if(_sEhrPWM1B)
    {
      free(_sEhrPWM1B);
      _sEhrPWM1B = NULL;
    }
}

void hal::BBBProperties::setEHRPWM0A(char* sValue_IN)
{
  if(_sEhrPWM0A)
    {
      free(_sEhrPWM0A);
      _sEhrPWM0A = NULL;
    }

  if(sValue_IN)
    {
      unsigned int len = strlen(sValue_IN);
      if(!(_sEhrPWM0A = (char*)malloc(len+1)))
        {
          // ERRORE
        }
      memcpy(sValue_IN, _sEhrPWM0A, len);
      _sEhrPWM0A[len]='\0';
    }
}
  
void hal::BBBProperties::setEHRPWM0B (char* sValue_IN)
{
  if(_sEhrPWM0B)
    {
      free(_sEhrPWM0B);
      _sEhrPWM0B = NULL;
    }

  if(sValue_IN)
    {
      unsigned int len = strlen(sValue_IN);
      if(!(_sEhrPWM0B = (char*)malloc(len+1)))
        {
          // ERRORE
        }
      memcpy(sValue_IN, _sEhrPWM0B, len);
      _sEhrPWM0B[len]='\0';
    }  
}
  
void hal::BBBProperties::setEHRPWM1A (char* sValue_IN)
{
  if(_sEhrPWM1A)
    {
      free(_sEhrPWM1A);
      _sEhrPWM1A = NULL;
    }

  if(sValue_IN)
    {
      unsigned int len = strlen(sValue_IN);
      if(!(_sEhrPWM1A = (char*)malloc(len+1)))
        {
          // ERRORE
        }
      memcpy(sValue_IN, _sEhrPWM1A, len);
      _sEhrPWM1A[len]='\0';
    }  
}
  
void hal::BBBProperties::setEHRPWM1B (char* sValue_IN)
{
  if(_sEhrPWM1B)
    {
      free(_sEhrPWM1B);
      _sEhrPWM1B = NULL;
    }

  if(sValue_IN)
    {
      unsigned int len = strlen(sValue_IN);
      if(!(_sEhrPWM1B = (char*)malloc(len+1)))
        {
          // ERRORE
        }
      memcpy(sValue_IN, _sEhrPWM1B, len);
      _sEhrPWM1B[len]='\0';
    }
}

void hal::BBBProperties::setProperty (char* sName_IN, char* sValue_IN)
{
  if(!sName_IN)
    return;
  
  if(!strcmp (sName_IN, "EHRPWM0A"))
    {
      setEHRPWM0A (sValue_IN);
      return;
    }
  
  if(!strcmp (sName_IN, "EHRPWM0B"))
    {
      setEHRPWM0B (sValue_IN);
      return;
    }
  
  if(!strcmp (sName_IN, "EHRPWM1A"))
    {
      setEHRPWM1A (sValue_IN);
      return;
    }
  
  if(!strcmp (sName_IN, "EHRPWM1B"))
    {
      setEHRPWM1B (sValue_IN);
      return;
    }
  
}

char* hal::BBBProperties::getProperty (const char* sName_IN)
{
   if(!strcmp (sName_IN, "EHRPWM0A"))
    {
      return _sEhrPWM0A;
    }
  
   if(!strcmp (sName_IN, "EHRPWM0B"))
    {
      return _sEhrPWM0B;
    }
   
   if(!strcmp (sName_IN, "EHRPWM1A"))
    {
      return _sEhrPWM1A;
    }
   
   if(!strcmp (sName_IN, "EHRPWM1B"))
    {
      return _sEhrPWM1B;
    }

}