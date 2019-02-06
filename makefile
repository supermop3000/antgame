#Project: Group Project - makefile
#Name: Group 4
#Date: 2/1/19

CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
RM = /bin/rm -f

OBJS = main.o Critter.o Doodlebug.o

SRCS = main.cpp Critter.cpp Doodlebug.cpp

HEADERS = Critter.hpp Doodlebug.hpp

critter: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o critter

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	${RM} *.o main critter
