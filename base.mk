SPARROW_HOME_PATH=$(PROJECT_HOME)

TARGET_BIN=debug

SPARROW_BIN_PATH=$(SPARROW_HOME_PATH)/$(TARGET_BIN)
SPARROW_SRC_PATH=$(SPARROW_HOME_PATH)/src

LIB_PATH=$(SPARROW_HOME_PATH)/../../lib/$(TARGET_BIN)

# Compiler setting
SPARROW_CC=g++
SPARROW_CFLAG=-Wall -g $(LOG_SETTING)

# Link setting
SPARROW_LPP=g++
SPARROW_LFLAG=

# Log setting
SPARROW_LOG_TYPE=-D_STLOG_
SPARROW_LOG_LEVEL=-DVERBOSE_LOG
#SPARROW_LOG_LEVEL=-DL3_LOG
SPARROW_LOG_SETTING=$(SPARROW_LOG_TYPE) $(SPARROW_LOG_LEVEL)

