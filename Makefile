all: clean compile run

compile:
	g++ -std=c++11 main.cpp functions.cpp

run: 
	./a.exe

clean:
	rm -f *.exe

