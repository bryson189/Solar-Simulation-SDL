#OBJS = files to compile
OBJS = SDLLearningForHenry/solarSimulationWindow.cpp

#CC = compiler used
CC = g++

#COMPLIE_FLAGS = additional flags
COMPILE_FLAGS = -w -g -std=c++0x

LINK_FLAGS = `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_ttf -ltiff


#OUTPUT_NAME = final name
OUTPUT_NAME = hello

#INCLUDE FLAGS
INCLUDE_FLAGS = -Ilib -Iinclude

all :
	 $(CC) $(OBJS) $(INCLUDE_FLAGS) $(LINK_FLAGS) $(COMPILE_FLAGS) -o $(OUTPUT_NAME) -pthread

clean :
	rm hello
