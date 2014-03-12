# Copyright (c) 2014 Oleksandr Sviridenko
#
# http://www.robionica.org/

SRC_DIR = src
LIB_DIR = lib

LIB_NAME = camera_ir_rc.a
LIB_PATH = $(LIB_DIR)/lib$(LIB_NAME)

PROPELLER_TOOLS_PREFIX = propeller-elf-

propeller:
	$(PROPELLER_TOOLS_PREFIX)gcc -c -o $(SRC_DIR)/camera_ir_rc/camera_ir_rc.o $(SRC_DIR)/camera_ir_rc/camera_ir_rc.c
	$(PROPELLER_TOOLS_PREFIX)ar rcs $(LIB_PATH) $(SRC_DIR)/camera_ir_rc/camera_ir_rc.o

clean:
	rm -f $(SRC)/camera_ir_rc/camera_ir_rc.o $(LIB_PATH)
