/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "sparrow.hpp"
#include "stdlib.h"
#include "hdctrl.hpp"

using namespace sfa;

SparrowVehicleMgr SparrowVehicleMgr::sparrowMgr;

/*
SparrowVehicleMgr::SparrowVehicleMgr (const multirotor_t eMoltirotor_IN):
   _eMotorsNum(eMoltirotor_IN),
   _ptrBoardCtrl(NULL),
   _ptrMotorsCtrl(NULL),
   _ptrInstrumnentsCtrl(NULL),
   _ptrFlyAssistant(NULL)
{
//  spwIMLOG( "Initialize Sparrow: %d rotors\n", eMoltirotor_IN);
}
 * */

SparrowVehicleMgr::~SparrowVehicleMgr ()
{
  shutDownSubsystems();
}

void SparrowVehicleMgr::_initBoardCtrl()
{
  _ptrBoardCtrl = hal::getBoardCtrl ();
}

void SparrowVehicleMgr::_initMotorsCtrl()
{
  spwIMLOG(SPARROW_SUBMODULE_MOTORCTRL, "Initializing %d Motors Controller\n", _eMotorsNum);

  hal::PWM* pwm = NULL;
  
  _ptrMotorsCtrl = new MotorCtrl*[_eMotorsNum];
  
  for(unsigned char indx = 0; indx < _eMotorsNum; indx++)
    {      
      pwm = _ptrBoardCtrl->getPWMCtrl (indx);
      _ptrMotorsCtrl[indx] = new BLDCCtrl(pwm);
    }
}

void SparrowVehicleMgr::_initInstAccelerometer(void)
{
  _ptrInstrumnentsCtrl[accelerometer] = 
          new AccelerometerCtrl( 
             _ptrBoardCtrl->getI2CMasterChannelCtrl (accelerometer) );
}

void SparrowVehicleMgr::_initInstGyroscope(void)
{
  _ptrInstrumnentsCtrl[gyroscope] = 
          new GyroscopeCtrl( 
             _ptrBoardCtrl->getI2CMasterChannelCtrl (gyroscope) );
}

void SparrowVehicleMgr::_initInstrumentsCtrl()
{
  
  if(!instrumentsNum)
    return;
  
  spwIMLOG(SPARROW_SUBMODULE_INSTRUMENTCTRL, "Initializing Instruments Controller\n");
  
  _ptrInstrumnentsCtrl = new InstrumentCtrl*[instrumentsNum];
  for(unsigned char indx = 0; indx<instrumentsNum; indx++)
    {
      switch(indx)
        {
        case accelerometer:
          _initInstAccelerometer ();
          break;
          
        case gyroscope:
          _initInstGyroscope ();
          break;
        }
    }
  
  
}

void SparrowVehicleMgr::_initFlyAssistant()
{
  _ptrFlyAssistant = new SparrowFlyAssistant();
}

void SparrowVehicleMgr::shutDownSubsystems (void)
{
  spwILOG("Shut down subsystems\n");
  
  if(_ptrFlyAssistant)
    {
      delete _ptrFlyAssistant;
      _ptrFlyAssistant = NULL;
    }
  
  if(_ptrInstrumnentsCtrl)
    {
      spwIMLOG(SPARROW_SUBMODULE_INSTRUMENTCTRL, "Shut down Instruments Controller\n");
      for(unsigned char indx=0; indx < instrumentsNum; indx++)
        {
          if(_ptrInstrumnentsCtrl[indx])
            {
              delete _ptrInstrumnentsCtrl[indx];
              _ptrInstrumnentsCtrl[indx] = NULL;
            }
        }
      delete _ptrInstrumnentsCtrl;
      _ptrInstrumnentsCtrl = NULL;
    }
  
  if(_ptrMotorsCtrl)
    {
      spwIMLOG(SPARROW_SUBMODULE_MOTORCTRL, "Shut down Motors Controller\n");
      for(unsigned char indx=0; indx < _eMotorsNum; indx++)
        {
          if(_ptrMotorsCtrl[indx])
            {
              spwIMLOG(SPARROW_SUBMODULE_MOTORCTRL, "Shut down Motor %d\n", indx);
              delete _ptrMotorsCtrl[indx];
              _ptrMotorsCtrl[indx] = NULL;
            }
        }
      
      delete _ptrMotorsCtrl;
    }
  
  if(_ptrBoardCtrl)
    {
      spwIMLOG( SPARROW_SUBMODULE_BOARDCTRL, "Shut down Board Controller\n");
      hal::destroyBoardCtrl (&_ptrBoardCtrl);
    }
}

void SparrowVehicleMgr::_initializeSubsystems(unsigned char eSubSystem_IN)
{
    switch(eSubSystem_IN)
    {
        case boardctrl:
            _initBoardCtrl();
            break;
            
        case motorsctrl:
            _initMotorsCtrl();
            break;
            
        case instumentsctrl:
            _initInstrumentsCtrl();
            break;
            
        case flyassistant:
            _initFlyAssistant();
            break;
            
        default:
            spwWLOG( "Not valid subsystem: %d\n", eSubSystem_IN);
            break;
    }
}

void SparrowVehicleMgr::initializeSubsystems(multirotor_t eMultirotors_IN)
{
    spwILOG( "Initializing Sparrow subsystems\n");
    try
    {
        sparrowMgr._eMotorsNum = eMultirotors_IN;
        for(unsigned char indx = 0 ; indx < numSubsystems; indx++)
        {
            sparrowMgr._initializeSubsystems(indx);
        }
    }
    catch(composite::excps::GenericException* ge)
    {
      WRAP_EXCEPTION(InitializeException,ge);
    }
    catch(...)
    {
      THROW_EXCEPTION(InitializeException);
    }
    spwILOG( "Subsystems initialized!\n");
}
