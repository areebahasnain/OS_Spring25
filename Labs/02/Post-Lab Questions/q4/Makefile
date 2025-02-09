all: main

LetterCount.o: LetterCount.cpp LetterCount.h
	g++ -c LetterCount.cpp

WordCount.o: WordCount.cpp WordCount.h
	g++ -c WordCount.cpp

LineCount.o: LineCount.cpp LineCount.h
	g++ -c LineCount.cpp

main.o: main.cpp LetterCount.h WordCount.h LineCount.h
	g++ -c main.cpp

main: main.o LetterCount.o WordCount.o LineCount.o
	g++ -o main main.o LetterCount.o WordCount.o LineCount.o

clean:
	rm -f *.o main
