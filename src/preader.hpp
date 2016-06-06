/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   preader.hpp
 * Author: ale
 *
 * Created on June 4, 2016, 8:24 PM
 */

#ifndef PREADER_HPP
#define PREADER_HPP

#include "stdlib.h"
#include "stdio.h"

#define PREADER_SUB_MODULE          "PropertiesFilesReader"

#define PREADER_BUFFER_SIZE         4096
#define PREADER_TOKEN_SIZE          1024

#define PREADER_BLANK               " \t\n"
#define PREADER_TOKEN_SEPARATOR     " \t\n!="

#define SKIP_BLANK                  while( strchr(PREADER_BLANK, _sBuffer[_uiCurrentPosition]) && ++_uiCurrentPosition < _uiBufferLen) 
#define END_BUFFER                  _uiCurrentPosition == _uiBufferLen

#define IS_COMMENT(TOKEN)           TOKEN[0]=='#'              
#define IS_DIRECTIVE(TOKEN)         TOKEN[0]=='!' 
#define IS_ASSOCIATION(TOKEN)       TOKEN[0]=='='

#define DIRECTIVE_INCLUDE           "include"

#define IS_INCLUDE_DIRECTIVE(TOKEN)   !strcmp(DIRECTIVE_INCLUDE,TOKEN)

class PpropertiesStore
{
public:
    virtual void setProperty(char* sName_IN, char* sValue_IN) = 0;
    virtual char* getProperty(const char* s_Name_IN) = 0;
};

class PStoreTest: public PpropertiesStore
{
    void setProperty(char* sName_IN, char* sValue_IN)
    {
        printf("set property %s to %s\n", sName_IN, sValue_IN);
    }
    char* getProperty(const char* s_Name_IN){return NULL;}
    
};

class PropertiesFilesReader
{
public:
    PropertiesFilesReader();
    ~PropertiesFilesReader();
    
    void load(const char* sSourceFile_IN, PpropertiesStore* ptrStore_IN);
    
private:
    
    typedef char*        buffer_t;
    typedef unsigned int buffer_index_t;
    
    buffer_t             _sBuffer;
    buffer_t             _sCurrentToken;
    buffer_t             _sValueToken;
    buffer_index_t       _uiCurrentPosition;
    unsigned int         _uiBufferLen;
    PpropertiesStore*    _ptrStore;
    
    inline unsigned char readNextToken(buffer_t sToken_OUT);
    void parseBuffer(void);
    void parseDirective(void);
    void parseIncludeDirective(void);
    
};

#endif /* PREADER_HPP */

