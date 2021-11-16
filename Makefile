TAG = GCC

#CONFIGURE BUILD SYSTEM
TARGET	   = aoc2021-$(TAG)
BUILD_DIR  = ./build_$(TAG)
SRC_DIR    = ./src
MAKE_DIR   = ./
Q         ?= @

#DO NOT EDIT BELOW
include $(MAKE_DIR)/$(TAG).mk
INCLUDES  += -I./include

VPATH     = $(SRC_DIR)
OBJ      += $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.cpp))
CPPFLAGS := $(CPPFLAGS) $(DEFINES) $(INCLUDES) 


${TARGET}: $(BUILD_DIR) $(OBJ)
	@echo "===>  LINKING  $(TARGET)"
	$(Q)${LINKER} ${LFLAGS} -o $(TARGET) $(OBJ) $(LIBS)

asm:  $(BUILD_DIR) $(ASM)

$(BUILD_DIR)/%.o:  %.cpp
	@echo "===>  COMPILE  $@"
	$(Q)$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
	$(Q)$(CXX) $(CPPFLAGS) -MT $(@:.d=.o) -MM  $< > $(BUILD_DIR)/$*.d

tags:
	@echo "===>  GENERATE  TAGS"
	$(Q)ctags -R


$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

ifeq ($(findstring $(MAKECMDGOALS),clean),)
-include $(OBJ:.o=.d)
endif

.PHONY: clean distclean debug debug-clean debug-distclean

debug:
	@make TAG=GCCdebug

debug-clean:
	@make clean TAG=GCCdebug

debug-distclean:
	@make distclean TAG=GCCdebug

clean:
	@echo "===>  CLEAN"
	@rm -rf $(BUILD_DIR)
	@rm -f tags

distclean: clean
	@echo "===> DIST CLEAN"
	@rm -f $(TARGET)
	@rm -f tags

