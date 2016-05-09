/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hallog.hpp
 * Author: ale
 *
 * Created on May 1, 2016, 8:07 PM
 */

#ifndef HALLOG_HPP
#define HALLOG_HPP

#define HAL_MODULE_NAME "hal"

#include "../../../composite/src/logs/log.h"

#define halELOG(...)   EMLOG(HAL_MODULE_NAME, "", __VA_ARGS__)
#define halWLOG(...)   WMLOG(HAL_MODULE_NAME, "", __VA_ARGS__)
#define halILOG(...)   IMLOG(HAL_MODULE_NAME, "", __VA_ARGS__)
#define halIILOG(...)  IIMLOG(HAL_MODULE_NAME,"", __VA_ARGS__)
#define halTLOG(...)   TMLOG(HAL_MODULE_NAME,"", __VA_ARGS__)
#define halDLOG(...)   DMLOG(HAL_MODULE_NAME,"", __VA_ARGS__)
#define halLOG(...)    MLOG(HAL_MODULE_NAME,"", __VA_ARGS__)

#define halEMLOG(SUB_MODULE, ...)   EMLOG(HAL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define halWMLOG(SUB_MODULE, ...)   WMLOG(HAL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define halIMLOG(SUB_MODULE, ...)  IMLOG(HAL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define halIIMLOG(SUB_MODULE, ...)  IIMLOG(HAL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define halTMLOG(SUB_MODULE, ...)   TMLOG(HAL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define halDMLOG(SUB_MODULE, ...)   DMLOG(HAL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define halMLOG(SUB_MODULE, ...)    MLOG(HAL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)


#endif /* HALLOG_HPP */

