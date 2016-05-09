/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sparrow.hpp"

int main(void)
{

    sfa::SparrowMgr::initializeSubsystems(sfa::quadricopter);
    
    sfa::MotorCtrl* m0_ctrl = sfa::SparrowMgr::getMotorCtrl(0);
    
//    sfa::MotorCtrl* m0_ctrl = sfa::SparrowVehicleMgr::getMotorCtrl(0);
    
   /*
  sfa::SparrowVehicleMgr sparrow(sfa::quadricopter);
  
  sparrow.initializeSubsystems ();
  
  sfa::MotorCtrl* m0_ctrl = sparrow.getMotorCtrl (0);
  */
  //m0_ctrl->setPower(25.0);
  //m0_ctrl->powerOff();
  
  return 0;
}