/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fclog.hpp
 * Author: ale
 *
 * Created on May 1, 2016, 8:07 PM
 */

#ifndef FCTLLOG_HPP
#define FCTLLOG_HPP

#define FCTL_MODULE_NAME "fly controller"
#define MOTR_SUBMODULE_NAME "motor controller"

#include "../../../composite/src/logs/log.h"

#define fcELOG(...)   EMLOG(FCTL_MODULE_NAME, "", __VA_ARGS__)
#define fcWLOG(...)   WMLOG(FCTL_MODULE_NAME, "", __VA_ARGS__)
#define fcILOG(...)   IMLOG(FCTL_MODULE_NAME, "", __VA_ARGS__)
#define fcIILOG(...)  IIMLOG(FCTL_MODULE_NAME,"", __VA_ARGS__)
#define fcTLOG(...)   TMLOG(FCTL_MODULE_NAME,"", __VA_ARGS__)
#define fcDLOG(...)   DMLOG(FCTL_MODULE_NAME,"", __VA_ARGS__)
#define fcLOG(...)    MLOG(FCTL_MODULE_NAME,"", __VA_ARGS__)

#define fcEMLOG(SUB_MODULE, ...)   EMLOG(FCTL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define fcWMLOG(SUB_MODULE, ...)   WMLOG(FCTL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define fcIMLOG(SUB_MODULE, ...)  IMLOG(FCTL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define fcIIMLOG(SUB_MODULE, ...)  IIMLOG(FCTL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define fcTMLOG(SUB_MODULE, ...)   TMLOG(FCTL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define fcDMLOG(SUB_MODULE, ...)   DMLOG(FCTL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)
#define fcMLOG(SUB_MODULE, ...)    MLOG(FCTL_MODULE_NAME, SUB_MODULE, __VA_ARGS__)


#endif /* FCTLLOG_HPP */

