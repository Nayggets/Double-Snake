CXX = g++
LANG_STD = -std=c++20
COMPILE_FLAGS = -g -O2 -Os
LDFLAGS = -lSDL2 -lSDL2_image
APP_NAME = Double_Snake
SRC_FILES = src/Screen_Manager/*.cpp \
			src/Snake/*.cpp 

build:
	$(CXX)	$(LANG_STD) $(COMPILE_FLAGS) $(SRC_FILES) $(LDFLAGS) -o $(APP_NAME)


clean:
	rm Double_Snake

run:
	make
	./Double_Snake

o_run:
	./Double_Snake