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

hal::BeagleBoardCtrl::BeagleBoardCtrl()
{
  
  halIMLOG(BEAGLE_SUBSYSTEM, "Initialize Beablebone Black controller\n");
  
  char* sConfFile = getenv("BEAGLE_CONF_FILE");
  if(sConfFile)
    {
      halIMLOG(BEAGLE_SUBSYSTEM, "Load configuration file: %s\n", sConfFile);
    }
}

hal::PWM* hal::BeagleBoardCtrl::getPWMCtrl(const unsigned char uIndx_IN)
{
  halIMLOG(BEAGLE_SUBSYSTEM, "Create PWM controller: %d\n", uIndx_IN);
  return NULL;
}

hal::I2CMaster* hal::BeagleBoardCtrl::getI2CMasterChannelCtrl(const unsigned char uIndx_IN)
{
  halIMLOG(BEAGLE_SUBSYSTEM, "Create I2C master controller: %d\n", uIndx_IN);
  return NULL;
}

hal::BeagleBoardCtrl* hal::BeagleBoneFactory::getBBBContoller(void)
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