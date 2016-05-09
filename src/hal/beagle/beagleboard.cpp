/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../hal.hpp"
#include "../hallog.hpp"
#include "beagleboard.hpp"
#include "stdlib.h"

hal::BoardCtrl* hal::getBoardCtrl(void)
{
  halIMLOG(BEAGLE_SUBSYSTEM, "Initialize BeagleBoard controller\n");
  return new BeagleBoardCtrl();
}

void hal::destroyBoardCtrl(BoardCtrl** ptrBoardCtrl_IN)
{
  if(ptrBoardCtrl_IN)
    {
      halIMLOG(BEAGLE_SUBSYSTEM, "Destroy BeagleBoard controller\n");
      delete *ptrBoardCtrl_IN;
      *ptrBoardCtrl_IN = NULL;
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