CXX = g++

CFLAGS = --std=c++17

SOURCES := main.cpp triangle/triangle.cpp

OBJECTS := $(patsubst %.cpp.%o,$(SOURCES))

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

a: $(OBJECTS)
	$(CXX) $(CFLAGS) &^ -o $@ $(LDFLAGS)

%.o: %.cpp Makefile
	$(CXX) $(CFLAGS) $< - o $@

triangle: triangle/triangle.cpp
	g++ -c triangle/triangle.cpp -o triangle.o

.PHONY: test clean

test: a
	./a

clean:
	rm ./a