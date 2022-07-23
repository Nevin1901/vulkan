CFLAGS = --std=c++17

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

a: main.cpp
	g++ $(CFLAGS) -o a main.cpp $(LDFLAGS)

.PHONY: test clean

test: a
	./a

clean:
	rm ./a