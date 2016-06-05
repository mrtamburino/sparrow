/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sparrow.hpp"
#include "preader.hpp"

int main(void)
{
  PropertiesFilesReader preader;
  PStoreTest pstest;
  
  preader.load ("/home/ale/workspace/Projects/sparrow/debug/conf/bbb.properties", &pstest);
  
    //sparrow::VehicleMgr* vehicle = sparrow::VehicleFactory::initSystemsFor(sfa::e_quadricopter);

    //vehicle->getFlyAssistant();
            
//    sfa::MotorCtrl* m0_ctrl = sparrow::VehicleFactory::getMotorCtrl(0);
    
//    sfa::FlyAssistant* flyAssistant = sparrow::VehicleFactory::getFlyAssistant();
    
    //flyAssistant->up(10);
  
  return 0;
}