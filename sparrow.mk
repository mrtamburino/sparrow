PROJECT_HOME=$(HOME)/workspace/Projects/sparrow

#Target: bebug, release
BIN_TARGET=debug

include $(PROJECT_HOME)/base.mk

FC_OBJ=$(SPARROW_BIN_PATH)/flyctl/flyctl.o
SPARROW_OBJ=$(SPARROW_BIN_PATH)/sparrow.o $(SPARROW_BIN_PATH)/sparrowmgr.o
TEST_OBJ=$(SPARROW_BIN_PATH)/main.o
BEAGLEBOARD_OBJ=$(SPARROW_BIN_PATH)/hal/beagle/beagleboard.o

$(SPARROW_BIN_PATH)/hal/beagle/beagleboard.o: $(SPARROW_SRC_PATH)/hal/beagle/beagleboard.cpp
	@echo
	@echo "[MAKE INFO] Compiling $?"
	@echo "   File to compie: $?"
	@echo "   Obj file      : $@"
	$(SPARROW_CC) $(SPARROW_CFLAG) $(SPARROW_LOG_SETTING) -c $? -o $@
	@echo "[MAKE INFO] Compile $? succesfull!"
	@echo

$(SPARROW_BIN_PATH)/sparrowmgr.o: $(SPARROW_SRC_PATH)/sparrowmgr.cpp
	@echo
	@echo "[MAKE INFO] Compiling $?"
	@echo "   File to compie: $?"
	@echo "   Obj file      : $@"
	$(SPARROW_CC) $(SPARROW_CFLAG) $(SPARROW_LOG_SETTING) -c $? -o $@
	@echo "[MAKE INFO] Compile $? succesfull!"
	@echo

$(SPARROW_BIN_PATH)/sparrow.o: $(SPARROW_SRC_PATH)/sparrow.cpp
	@echo
	@echo "[MAKE INFO] Compiling $?"
	@echo "   File to compie: $?"
	@echo "   Obj file      : $@"
	$(SPARROW_CC) $(SPARROW_CFLAG) $(SPARROW_LOG_SETTING) -c $? -o $@
	@echo "[MAKE INFO] Compile $? succesfull!"
	@echo

$(SPARROW_BIN_PATH)/flyctl/flyctl.o: $(SPARROW_SRC_PATH)/flyctl/flyctl.cpp
	@echo
	@echo "[MAKE INFO] Compiling $?"
	@echo "   File to compie: $?"
	@echo "   Obj file      : $@"
	$(SPARROW_CC) $(SPARROW_CFLAG) $(SPARROW_LOG_SETTING) -c $? -o $@
	@echo "[MAKE INFO] Compile $? succesfull!"
	@echo

$(SPARROW_BIN_PATH)/main.o: $(SPARROW_SRC_PATH)/main.cpp
	@echo
	@echo "[MAKE INFO] Compiling $?"
	@echo "   File to compile: $?"
	@echo "   Obj file      : $@"
	$(SPARROW_CC) $(SPARROW_CFLAG) $(SPARROW_LOG_SETTING) -c $? -o $@
	@echo "[MAKE INFO] Compile $? succesfull!"
	@echo
	
test: $(FC_OBJ) $(BEAGLEBOARD_OBJ) $(SPARROW_OBJ) $(TEST_OBJ)
	@echo
	@echo "---------------------------------------------------------------------------------"
	@echo "[MAKE INFO] Linking $@"	
	$(SPARROW_LPP) $(SPARROW_LFLAG) -o $(SPARROW_BIN_PATH)/$@ $(SPARROW_OBJ) $(FC_OBJ) $(TEST_OBJ) $(BEAGLEBOARD_OBJ)
	@echo "[MAKE INFO] Succesfull!"
	@echo "---------------------------------------------------------------------------------"
	@echo

	
.PHONY : clean_test
  
 clean_test:
	@echo
	@echo "---------------------------------------------------------------------------------"
	@echo "Clean object files: $(FC_OBJ) $(SPARROW_OBJ) $(TEST_OBJ) $(SPARROW_BIN_PATH)/$@"
	-rm $(FC_OBJ) $(SPARROW_OBJ) $(TEST_OBJ) $(BEAGLEBOARD_OBJ) $(SPARROW_BIN_PATH)/test
	@echo "Object file deleted"
	@echo "---------------------------------------------------------------------------------"
	@echo
	