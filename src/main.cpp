/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sparrow.hpp"

int main(void)
{
  
  sfa::Sparrow sparrow(sfa::quadricopter);
  
  sparrow.initializeSubsystems ();
  
  //sfa::FlyAssistant* fa = sparrow.getFlyAssistant ();
  
  sfa::MotorCtrl* m0_ctrl = sparrow.getMotorCtrl (0);
  m0_ctrl << 25.0;
  
  
  return 0;
}