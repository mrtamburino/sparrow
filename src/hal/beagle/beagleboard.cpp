/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../hal.hpp"
#include "../hallog.hpp"
#include "beagleboard.hpp"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "bbbproperties.hpp"

/*! Beagle Board Controller singleton
 */
static hal::BeagleBoneFactory BBBFactory;

// --------------------------------------------------

/*! Return a pointer to BBB controller
 */
hal::BoardCtrl* hal::getBoardCtrl(void)
{
  return BBBFactory.getBBBContoller ();
}
/*! Destroy BBB controller
 */
void hal::destroyBoardCtrl(BoardCtrl** ptrBoardCtrl_IN)
{
}

// --------------------------------------------------



// --------------------------------------------------
// --- BBB PWM
// --------------------------------------------------

void hal::BBBPWMSignal::setDutyCycle(double)
{
  
}

void hal::BBBPWMSignal::setFrequence(double)
{
  
}


// --------------------------------------------------
// --- BBB
// --------------------------------------------------



hal::BeagleBoardCtrl::BeagleBoardCtrl()
{
  
  halIMLOG(BEAGLE_SUBSYSTEM, "Initialize BeagleBone-Black controller\n");
  
  halWMLOG(BEAGLE_SUBSYSTEM, "Load the tree overlay and export the pin in user space before run the application\n");
  
  BBBProperties bbbProperties;
  
  char* sConfFile = getenv("BEAGLE_CONF_FILE");
  if(sConfFile)
    {
      halIIMLOG(BEAGLE_SUBSYSTEM, "Load configuration from file: %s\n", sConfFile);
      PropertiesFilesReader pfr;
      pfr.load (sConfFile, &bbbProperties);
    }
  
  // Initialize the array of PWM controllers
  memset( _aptrPWMSignals, 
          0, 
          e_pwmSignalsAvailable * sizeof(BBBPWMSignal*));
  

  char* sPropertyValue = NULL;
  
  sPropertyValue = bbbProperties.getProperty ("EHRPWM0A");
  if(sPropertyValue)
    {
      _aptrPWMSignals[e_ehrpwm0a] = new BBBPWMSignal(sPropertyValue);
    }
  sPropertyValue = bbbProperties.getProperty ("EHRPWM0B");
  if(sPropertyValue)
    {
      _aptrPWMSignals[e_ehrpwm0b] = new BBBPWMSignal(sPropertyValue);
    }
  sPropertyValue = bbbProperties.getProperty ("EHRPWM1A");
  if(sPropertyValue)
    {
      _aptrPWMSignals[e_ehrpwm1a] = new BBBPWMSignal(sPropertyValue);
    }
  sPropertyValue = bbbProperties.getProperty ("EHRPWM1B");
  if(sPropertyValue)
    {
      _aptrPWMSignals[e_ehrpwm1b] = new BBBPWMSignal(sPropertyValue);
    }
}

hal::BeagleBoardCtrl::~BeagleBoardCtrl()
{
  for(unsigned char indx = 0; indx < hal::e_pwmSignalsAvailable; indx++)
    {
      if(_aptrPWMSignals[indx])
        {
          delete _aptrPWMSignals[indx];
        }
    }
}

hal::PWM* hal::BeagleBoardCtrl::getPWMCtrl (const unsigned char uIndx_IN)
{
  halIMLOG(BEAGLE_SUBSYSTEM, "Create PWM controller: %d\n", uIndx_IN);
  if (uIndx_IN >= hal::e_pwmSignalsAvailable)
    {
      halWMLOG(BEAGLE_SUBSYSTEM, "Wrong PWM signal required: %c\n", uIndx_IN);
      return NULL;
    }
  
  return _aptrPWMSignals[uIndx_IN];
}

hal::I2CMaster* hal::BeagleBoardCtrl::getI2CMasterChannelCtrl (const unsigned char uIndx_IN)
{
  halIMLOG(BEAGLE_SUBSYSTEM, "Create I2C master controller: %d\n", uIndx_IN);
  return NULL;
}

unsigned char hal::BeagleBoardCtrl::countPWMSignals (void)
{
  unsigned char ucAmount = 0;
  for(unsigned char indx = 0; indx < hal::e_pwmSignalsAvailable; indx++)
    {
      if(_aptrPWMSignals[indx])
        {
          ucAmount++;
          
        }
    }
  return ucAmount;
}


// --------------------------------------------------
// --- BBB Factory
// --------------------------------------------------

hal::BeagleBoardCtrl* hal::BeagleBoneFactory::getBBBContoller (void)
{
  if(!_ptrBBBController)
    {
      _ptrBBBController = new BeagleBoardCtrl();
    }
  return _ptrBBBController;
}

hal::BeagleBoneFactory::~BeagleBoneFactory()
{
  if(_ptrBBBController)
    delete _ptrBBBController;
}

