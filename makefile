#Project: Group Project - makefile
#Name: Group 4
#Date: 2/1/19

CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
RM = /bin/rm -f

OBJS = main.o Critter.o Doodlebug.o Group4Utils.o Ant.o
SRCS = main.cpp Critter.cpp Doodlebug.cpp Group4Utils.cpp Ant.cpp
HEADERS = Critter.hpp Doodlebug.hpp Group4Utils.hpp Ant.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main

clean:
		-rm *.o ${OBJS} main
