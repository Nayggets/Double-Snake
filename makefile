CFLAGS = -std=c++2a -O2
LDFLAGS = $(sdl2-config --cflags --libs)

DoubleSnake: *.cpp *.hpp
	g++	$(CFLAGS)	-o	DoubleSnake	*.cpp	$(LDFLAGS)
