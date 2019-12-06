CC = gcc
CXX = g++
TARGET = osrunner
OBJECTS = main.o data.o gui.o ogl.o
DEPENDS = $(OBJECTS:.o=.d)
CXXFLAGS = -ansi -pedantic -Wall
LDLIBS = -l GLU -l GL -l fltk -l fltk_gl

all: CXXFLAGS += -O2 -DNDEBUG
all: $(TARGET)

debug: CXXFLAGS += -Og -g
debug: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS)

-include $(DEPENDS)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $*.cpp -o $*.o
	$(CXX) -MM $(CXXFLAGS) $*.cpp > $*.d

%.o: %.c
	$(CC) -c $(CXXFLAGS) $*.c -o $*.o
	$(CC) -MM $(CXXFLAGS) $*.c > $*.d

clean:
	$(RM) $(TARGET) $(OBJECTS) $(DEPENDS)
