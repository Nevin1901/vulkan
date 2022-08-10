CFLAGS = --std=c++17

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

a: main.cpp triangle
	g++ $(CFLAGS) -o a main.cpp triangle.o $(LDFLAGS)

triangle: triangle/triangle.cpp
	g++ -c triangle/triangle.cpp -o triangle.o

.PHONY: test clean

test: a
	./a

clean:
	rm ./a