/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sparrowmgr.hpp"
#include "spwlog.hpp"
#include "hdctrl.hpp"
#include "flyasnt.hpp"
#include "flyctl/flyctl.hpp"

using namespace sparrow;

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

SparrowMgr::~SparrowMgr ()
{
  _shutDownSubsystems();
}

void SparrowMgr::_initBoardCtrl()
{
  _ptrBoardCtrl = hal::getBoardCtrl ();
  
  // Check: pwm signals available has to be equal or greater that number of motors
  if ( _ptrBoardCtrl->countPWMSignalsUnclamed () < _eMotorsNum)
    {
      // ERROR
      THROW_EXCEPTION(FewPWMSignalsException);
    }
}

void SparrowMgr::_initMotorsCtrl()
{
  spwIMLOG(SPARROW_SUBMODULE_MOTORCTRL, "Initializing %d Motors Controller\n", _eMotorsNum);

  hal::PWM* pwm = NULL;
  
  _ptrMotorsCtrl = new sfa::MotorCtrl*[_eMotorsNum];
  
  for(unsigned char indx = 0; indx < _eMotorsNum; indx++)
    {      
      pwm = _ptrBoardCtrl->getPWMCtrl (indx);
      _ptrMotorsCtrl[indx] = new BLDCCtrl(pwm);
    }
}

void SparrowMgr::_initInstAccelerometer(void)
{
  _ptrInstrumnentsCtrl[accelerometer] = 
          new AccelerometerCtrl( 
             _ptrBoardCtrl->getI2CMasterChannelCtrl (accelerometer) );
}

void SparrowMgr::_initInstGyroscope(void)
{
  _ptrInstrumnentsCtrl[gyroscope] = 
          new GyroscopeCtrl( 
             _ptrBoardCtrl->getI2CMasterChannelCtrl (gyroscope) );
}

void SparrowMgr::_initInstrumentsCtrl()
{
  
  if(!instrumentsNum)
    return;
  
  spwIMLOG(SPARROW_SUBMODULE_INSTRUMENTCTRL, "Initializing Instruments Controller\n");
  
  _ptrInstrumnentsCtrl = new sfa::InstrumentCtrl*[instrumentsNum];
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

void SparrowMgr::_initFlyAssistant()
{
  _ptrFlyAssistant = new SparrowFlyAssistant();
}

void SparrowMgr::_shutDownSubsystems (void)
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

void SparrowMgr::initSystem(unsigned char ucMotors_IN)
{
    _eMotorsNum = ucMotors_IN;
    
    spwILOG( "Initializing Sparrow subsystems\n");
    
    for(unsigned char indx = 0 ; indx < sfa::e_numSubsystems; indx++)
        {
            _initSubsystem(indx);
        }
    
    spwILOG( "Subsystems initialized\n");
    
}

void SparrowMgr::_initSubsystem(unsigned char eSubSystem_IN)
{
    switch(eSubSystem_IN)
    {
        case sfa::e_boardctrl:
            _initBoardCtrl();
            break;
            
        case sfa::e_motorsctrl:
            _initMotorsCtrl();
            break;
            
        case sfa::e_instumentsctrl:
            _initInstrumentsCtrl();
            break;
            
        case sfa::e_flyassistant:
            _initFlyAssistant();
            break;
            
        default:
            spwWLOG( "Not valid subsystem: %d\n", eSubSystem_IN);
            break;
    }
}