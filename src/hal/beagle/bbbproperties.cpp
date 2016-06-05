/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string.h>
#include "bbbproperties.hpp"

hal::BBBProperties::~BBBProperties ()
{
  if(_sEhrPWMA0)
    {
      free(_sEhrPWMA0);
      _sEhrPWMA0 = NULL;
    }
  
  if(_sEhrPWMA1)
    {
      free(_sEhrPWMA1);
      _sEhrPWMA1 = NULL;
    }
  
  if(_sEhrPWMB0)
    {
      free(_sEhrPWMB0);
      _sEhrPWMB0 = NULL;
    }
  
  if(_sEhrPWMB1)
    {
      free(_sEhrPWMB1);
      _sEhrPWMB1 = NULL;
    }
}

void hal::BBBProperties::setEHRPWMA0(char* sValue_IN)
{
  if(_sEhrPWMA0)
    {
      free(_sEhrPWMA0);
      _sEhrPWMA0 = NULL;
    }

  if(sValue_IN)
    {
      unsigned int len = strlen(sValue_IN);
      if(!(_sEhrPWMA0 = (char*)malloc(len+1)))
        {
          // ERRORE
        }
      memcpy(sValue_IN, _sEhrPWMA0, len);
      _sEhrPWMA0[len]='\0';
    }
}
  
void hal::BBBProperties::setEHRPWMA1 (char* sValue_IN)
{
  if(_sEhrPWMA1)
    {
      free(_sEhrPWMA1);
      _sEhrPWMA1 = NULL;
    }

  if(sValue_IN)
    {
      unsigned int len = strlen(sValue_IN);
      if(!(_sEhrPWMA1 = (char*)malloc(len+1)))
        {
          // ERRORE
        }
      memcpy(sValue_IN, _sEhrPWMA1, len);
      _sEhrPWMA1[len]='\0';
    }  
}
  
void hal::BBBProperties::setEHRPWMB0 (char* sValue_IN)
{
  if(_sEhrPWMB0)
    {
      free(_sEhrPWMB0);
      _sEhrPWMB0 = NULL;
    }

  if(sValue_IN)
    {
      unsigned int len = strlen(sValue_IN);
      if(!(_sEhrPWMB0 = (char*)malloc(len+1)))
        {
          // ERRORE
        }
      memcpy(sValue_IN, _sEhrPWMB0, len);
      _sEhrPWMB0[len]='\0';
    }  
}
  
void hal::BBBProperties::setEHRPWMB1 (char* sValue_IN)
{
  if(_sEhrPWMB1)
    {
      free(_sEhrPWMA0);
      _sEhrPWMB1 = NULL;
    }

  if(sValue_IN)
    {
      unsigned int len = strlen(sValue_IN);
      if(!(_sEhrPWMB1 = (char*)malloc(len+1)))
        {
          // ERRORE
        }
      memcpy(sValue_IN, _sEhrPWMB1, len);
      _sEhrPWMB1[len]='\0';
    }
}

void hal::BBBProperties::setProperty (char* sName_IN, char* sValue_IN)
{
  if(!sName_IN)
    return;
  
  if(!strcmp (sName_IN, "EHRPWMA0"))
    {
      setEHRPWMA0 (sValue_IN);
      return;
    }
  
  if(!strcmp (sName_IN, "EHRPWMA1"))
    {
      setEHRPWMA1 (sValue_IN);
      return;
    }
  
  if(!strcmp (sName_IN, "EHRPWMB0"))
    {
      setEHRPWMB0 (sValue_IN);
      return;
    }
  
  if(!strcmp (sName_IN, "EHRPWMB1"))
    {
      setEHRPWMB1 (sValue_IN);
      return;
    }
  
}

unsigned char hal::BBBProperties::isEmpty (const char* sName_IN)
{
   if(!strcmp (sName_IN, "EHRPWMA0"))
    {
      return _sEhrPWMA0==NULL;
    }
  
   if(!strcmp (sName_IN, "EHRPWMA1"))
    {
      return _sEhrPWMA1==NULL;
    }
   
   if(!strcmp (sName_IN, "EHRPWMB0"))
    {
      return _sEhrPWMB0==NULL;
    }
   
   if(!strcmp (sName_IN, "EHRPWMB1"))
    {
      return _sEhrPWMB1==NULL;
    }  
}

char* hal::BBBProperties::getProperty (const char* sName_IN)
{
   if(!strcmp (sName_IN, "EHRPWMA0"))
    {
      return _sEhrPWMA0;
    }
  
   if(!strcmp (sName_IN, "EHRPWMA1"))
    {
      return _sEhrPWMA1;
    }
   
   if(!strcmp (sName_IN, "EHRPWMB0"))
    {
      return _sEhrPWMB0;
    }
   
   if(!strcmp (sName_IN, "EHRPWMB1"))
    {
      return _sEhrPWMB1;
    }

}