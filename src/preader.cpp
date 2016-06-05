/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "preader.hpp"
#include "../../composite/src/logs/log.h"
#include <stdio.h>
#include <string.h>


PropertiesFilesReader::PropertiesFilesReader()
{
  if(!(_sBuffer = (char*)malloc(PREADER_BUFFER_SIZE * sizeof(char))))
    {
      _sBuffer = NULL;
      ELOG("Not enough memory!\n");
    }
  _sBuffer[0] = '\0';
  
  if(!(_sCurrentToken = (char*)malloc(PREADER_TOKEN_SIZE * sizeof(char))))
    {
      _sCurrentToken = NULL;
      ELOG("Not enough memory!\n");
    }
  _sCurrentToken[0] = '\0';
  
  if(!(_sValueToken = (char*)malloc(PREADER_TOKEN_SIZE * sizeof(char))))
    {
      _sValueToken = NULL;
      ELOG("Not enough memory!\n");
    }
  _sValueToken[0] = '\0';
  
  _uiCurrentPosition = 0;
  _uiBufferLen       = 0;
  _ptrStore          = NULL;
}

PropertiesFilesReader::~PropertiesFilesReader()
{
  if(_sBuffer)
    free (_sBuffer);
  
  if(_sCurrentToken)
    free (_sCurrentToken);
  
  if(_sValueToken)
    free (_sValueToken);
  
  _uiCurrentPosition = 0;
  _uiBufferLen       = 0;
  _ptrStore          = NULL;
}

/**! 
 * Read token from buffer
 */
unsigned char PropertiesFilesReader::readNextToken(buffer_t sToken_OUT)
{
  
  sToken_OUT[0] = '\0';
  
  //Skip blank
  SKIP_BLANK;
  
  if(END_BUFFER)
    return 0;
  
  buffer_index_t uiTokenIndx = 0;
  
  while (!(END_BUFFER) && 
         strchr(PREADER_TOKEN_SEPARATOR, _sBuffer[_uiCurrentPosition]) == NULL)
    {
      sToken_OUT[uiTokenIndx++] = _sBuffer[_uiCurrentPosition++];
    }
  
  // if token is a separator
  if(!uiTokenIndx)
    sToken_OUT[uiTokenIndx++] = _sBuffer[_uiCurrentPosition++];

    sToken_OUT[uiTokenIndx] = '\0';
  
  return 1;

}

void PropertiesFilesReader::parseIncludeDirective(void)
{
  // Read file name
  if(!readNextToken (_sCurrentToken)) return;
  
  PropertiesFilesReader nestedReader;
  nestedReader.load (_sCurrentToken, _ptrStore);
  
}
  
void PropertiesFilesReader::parseDirective(void)
{

  // Reading directive name
  if(!readNextToken (_sCurrentToken)) return;
  
  if(IS_INCLUDE_DIRECTIVE(_sCurrentToken))
    {
      parseIncludeDirective ();
    }
}

void PropertiesFilesReader::parseBuffer(void)
{

  // Error reading the token
  if(!readNextToken (_sCurrentToken)) 
    return;
  
  // Comment line
  if(IS_COMMENT(_sCurrentToken)) 
    return;
  
  // Directive line
  if(IS_DIRECTIVE(_sCurrentToken)) 
    {
      parseDirective ();
      return;
    }
  
  //It is a property
  if(!readNextToken (_sValueToken)) 
    return;
  
  if(IS_ASSOCIATION(_sValueToken))
    {
      if(!readNextToken (_sValueToken)) 
        return;
      
      _ptrStore->setProperty (_sCurrentToken, _sValueToken);
    }
  else
    {
      // ERROR
    }
  
}
  

void PropertiesFilesReader::load(const char* sSourceFile_IN, 
                                 PpropertiesStore* ptrStore_IN)
{
  if(!_sBuffer || !_sCurrentToken || !_sValueToken || !sSourceFile_IN || !ptrStore_IN)
    return;
  
  _ptrStore = ptrStore_IN;
  
  FILE *fp = fopen( sSourceFile_IN, "r" );
  
  if(!fp)
    {
      ELOG("File %s not found!\n", sSourceFile_IN);
    }
  
  while(fgets(_sBuffer, PREADER_BUFFER_SIZE, fp) != NULL)
    {
      _uiCurrentPosition=0;
      _uiBufferLen = strlen(_sBuffer);
      parseBuffer ();
    }
      
    
  
  fclose(fp);
}