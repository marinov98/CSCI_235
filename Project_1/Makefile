CXXFLAGS=-std=c++14
main: main.o Customer.o GeniusBar.o 
	g++ -o main main.o Customer.o GeniusBar.o 

main.o: main.cpp Customer.hpp GeniusBar.hpp
	g++ $(CXXFLAGS) -c main.cpp

Customer.o: Customer.cpp Customer.hpp
	g++ $(CXXFLAGS) -c Customer.cpp

GeniusBar.o:GeniusBar.cpp GeniusBar.hpp
	g++ $(CXXFLAGS) -c GeniusBar.cpp

debug: CXXFLAGS:=$(CXXFLAGS) -g

debug: main

clean:
	rm -f main.o GeniusBar.o Customer.o main

run:
	./main