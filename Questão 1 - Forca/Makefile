.DEFAULT_GOAL := all

OBJECTS=build/JogoDaForca.o

build/JogoDaForca.o: src/JogoDaForca.cpp include/JogoDaForca.h
	g++ -Iinclude src/JogoDaForca.cpp -c -o build/JogoDaForca.o

objects: $(OBJECTS)

jogo: objects src/main.cpp
	g++ -fsanitize=address  -Wall  -Iinclude $(OBJECTS) src/main.cpp -o build/jogo

all: jogo