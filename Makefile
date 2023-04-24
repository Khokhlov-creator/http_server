run: compile
	./main

clean:
	rm main.o http_tcpServer.o

compile: main.o http_tcpServer.o
	g++ main.o http_tcpServer.o -o main

main.o: main.cpp http_tcpServer.hpp
	g++ -Wall -pedantic -std=c++17 -c main.cpp -o main.o

http_tcpServer.o: http_tcpServer.hpp http_tcpServer.cpp
	g++ -Wall -pedantic -std=c++17 -c http_tcpServer.cpp -o http_tcpServer.o
