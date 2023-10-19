lab6: lab6.o
	g++ -std=c++20 -g -Wall lab6.o -o lab6

lab6.o: lab6.cpp
	g++ -std=c++20 -g -Wall -c lab6.cpp

clean:
	rm *.o lab6