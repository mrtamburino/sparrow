/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "flyctl.hpp"
#include "fclog.hpp"


using namespace sfa;

void System_i::initializeSubsystems(void)
{
  
  fcILOG("Initializing subsystems\n");
  
  try
    {
      _initBoardCtrl ();
      _initMotorsCtrl ();
      _initInstrumentsCtrl ();
      _initFlyAssistant ();
    }
  catch(composite::excps::GenericException* ge)
    {
      WRAP_EXCEPTION(InitializeException,ge);
    }
  catch(...)
    {
      THROW_EXCEPTION(InitializeException);
    }
  
  
}