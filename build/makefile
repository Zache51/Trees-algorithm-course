EXE_LINUX := Trees-algorithm-course
SRC := $(wildcard ../src/*.cpp)
OBJ := $(SRC:.cpp=.o)
DEP := $(OBJ:.o=.d)

CPPFLAGS := -Ilib/linux64/sfml/include -MMD -MP
CXXFLAGS := -std=c++11 -Wall -W -pedantic
LDFLAGS  := -Llib/linux64/sfml/lib
LDLIBS   := -lsfml-graphics -lsfml-window -lsfml-system
#LDLIBS   += -lopengl32 -lwinmm -lgdi32

.PHONY: all clean

all: $(EXE_LINUX)

$(EXE_LINUX): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o target/$@

clean:
	$(RM) $(EXE_LINUX) $(OBJ) $(DEP)

ifeq "$(MAKECMDGOALS)" ""
-include $(DEP)
endif
