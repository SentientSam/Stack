CC = g++ -std=c++11 -Wall -Wextra -I.

all: fstack.x

fstack.x: tstack.h fstack.cpp
	$(CC) -o fstack.x fstack.cpp
