/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   spwlog.hpp
 * Author: ale
 *
 * Created on May 1, 2016, 8:07 PM
 */

#ifndef SPARROWLOG_HPP
#define SPARROWLOG_HPP

#include "../../composite/src/logs/log.h"

#define SPARROW_MODULE_NAME "sparrow"
#define SPARROW_SUBMODULE_MOTORCTRL "motor controller"
#define SPARROW_SUBMODULE_BOARDCTRL "board controller"
#define SPARROW_SUBMODULE_INSTRUMENTCTRL "instrument controller"
#define SPARROW_SUBMODULE_ACCELEROMETERCTRL "accelerometer controller"
#define SPARROW_SUBMODULE_GYROSCOPECTRL "gyroscope controller"
#define SPARROW_SUBMODULE_FLYASSISTAN "fly assistant"


#define spwELOG(...)   EMLOG(SPARROW_MODULE_NAME, "", __VA_ARGS__)
#define spwWLOG(...)   WMLOG(SPARROW_MODULE_NAME, "", __VA_ARGS__)
#define spwILOG(...)   IMLOG(SPARROW_MODULE_NAME, "", __VA_ARGS__)
#define spwIILOG(...)  IIMLOG(SPARROW_MODULE_NAME,"", __VA_ARGS__)
#define spwTLOG(...)   TMLOG(SPARROW_MODULE_NAME,"", __VA_ARGS__)
#define spwDLOG(...)   DMLOG(SPARROW_MODULE_NAME,"", __VA_ARGS__)
#define spwLOG(...)    MLOG(SPARROW_MODULE_NAME,"", __VA_ARGS__)

#define spwEMLOG(SUB_MODULE, ...)   EMLOG(SPARROW_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define spwWMLOG(SUB_MODULE, ...)   WMLOG(SPARROW_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define spwIMLOG(SUB_MODULE, ...)  IMLOG(SPARROW_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define spwIIMLOG(SUB_MODULE, ...)  IIMLOG(SPARROW_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define spwTMLOG(SUB_MODULE, ...)   TMLOG(SPARROW_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define spwDMLOG(SUB_MODULE, ...)   DMLOG(SPARROW_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define spwMLOG(SUB_MODULE, ...)    MLOG(SPARROW_MODULE_NAME, SUB_MODULE, __VA_ARGS__)


#endif /* SPARROWLOG_HPP */

