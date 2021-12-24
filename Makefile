OPTIONS = -O2 -Wall -Wextra -std=c++11    # pour optimiser

all: tp3

tp3: tp3.o MatriceAdjacent.o
	g++ ${OPTIONS} -o tp3 tp3.o MatriceAdjacent.o

tp3.o: tp3.cpp
	g++ ${OPTIONS} -c tp3.cpp

MatriceAdjacent.o: MatriceAdjacent.cpp MatriceAdjacent.h
	g++ ${OPTIONS} -c MatriceAdjacent.cpp

run:
	./tp3 univers.txt 0 0 1 6 1

clean:
	rm tp3 tp3.o MatriceAdjacent.o