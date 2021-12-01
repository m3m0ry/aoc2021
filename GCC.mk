CXX = g++
LINKER = $(CXX)

CXXFLAGS := -O2 -Wno-format -Wall -pedantic -Wextra
#CXXFLAGS   += -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align  -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return
#CXXFLAGS   += -Wcast-qual -Wswitch-default -Wconversion -Wunreachable-code
# Specific C flags
CPPFLAGS = -std=c++20
LFLAGS   =
DEFINES  = -D_GNU_SOURCE -DNDEBUG
INCLUDES =
LIBS     =
