EXE_LINUX := Trees-algorithm-course
SRC := $(wildcard ../../src/*.cpp)
OBJ := $(SRC:.cpp=.o)
DEP := $(OBJ:.o=.d)

CPPFLAGS := -Ilib/sfml/include -MMD -MP
CXXFLAGS := -std=c++11 -g -Wall -W -pedantic
LDFLAGS  := -Llib/sfml/lib -Wl,--rpath=lib/sfml/lib
LDLIBS   := -lsfml-graphics -lsfml-window -lsfml-system
#LDLIBS   += -lopengl32 -lwinmm -lgdi32

.PHONY: all clean

all: $(EXE_LINUX)

$(EXE_LINUX): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	$(RM) $(EXE_LINUX) $(OBJ) $(DEP)

ifeq "$(MAKECMDGOALS)" ""
-include $(DEP)
endif
