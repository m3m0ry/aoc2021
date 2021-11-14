CXX = g++
LINKER = $(CXX)

#CPPFLAGS := -Wall -Wextra -pedantic #-fopenmp
# More warning pls
#CPPFLAGS   += -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align  -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wno-format 
# Maybe too much warnings
#CPPFLAGS   += -Wcast-qual -Wswitch-default -Wconversion -Wunreachable-code
# Specific C flags
CPPFLAGS += -std=c++20
LFLAGS   = #-fopenmp
DEFINES  = #-D_GNU_SOURCE -DNDEBUG
INCLUDES =
LIBS     =
STD_LIBS = iostream string vector string_view


#CONFIGURE BUILD SYSTEM
TARGET	   = aoc2021
BUILD_DIR  = ./build
SRC_DIR    = ./src
MAKE_DIR   = ./
Q         ?= 

VPATH     = $(SRC_DIR)
MODULES  = ./src/boiler.cpp ./src/day1.cpp ./src/day.cpp
OBJ      += $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(MODULES))
CPPFLAGS := $(CPPFLAGS) $(DEFINES) $(INCLUDES) 


${TARGET}: $(BUILD_DIR) $(OBJ)
	@echo "===>  LINKING  $(TARGET)"
	$(Q)${LINKER} $(CPPFLAGS) ${LFLAGS} -fmodules-ts -o $(TARGET) apps/main.cpp $(OBJ) $(LIBS)

$(BUILD_DIR)/%.o:  %.cpp
	@echo "===>  COMPILE  $@"
	$(Q)$(CXX) -c -fmodules-ts $(CPPFLAGS) $< -o $@
	
standard_libs:
	@echo "===> COMPILE $@"
	$(Q)$(CXX) -c -fmodules-ts -x c++-system-header $(CPPFLAGS) $(STD_LIBS)

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)


ifeq ($(findstring $(MAKECMDGOALS),clean),)
-include $(OBJ:.o=.d)
endif

.PHONY: clean distclean standard_libs

clean:
	@echo "===>  CLEAN"
	@rm gcm.cache/*.gcm
	@rm -rf build

distclean: clean
	@echo "===> DIST CLEAN"
	@rm -rf gcm.cache/
	@rm -f $(TARGET)


