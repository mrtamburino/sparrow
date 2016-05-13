/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sparrow.hpp"

int main(void)
{

    sparrow::VehicleMgr* vehicle = sparrow::VehicleFactory::initSystemsFor(sfa::quadricopter);

    vehicle->getFlyAssistant();
            
//    sfa::MotorCtrl* m0_ctrl = sparrow::VehicleFactory::getMotorCtrl(0);
    
//    sfa::FlyAssistant* flyAssistant = sparrow::VehicleFactory::getFlyAssistant();
    
    //flyAssistant->up(10);
  
  return 0;
}