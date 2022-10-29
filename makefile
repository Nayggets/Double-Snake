CFLAGS = -std=c++2a -O2
LDFLAGS = $(-lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

DoubleSnake: *.cpp *.hpp
	g++	$(CFLAGS)	-o	DoubleSnake	*.cpp	$(LDFLAGS)
