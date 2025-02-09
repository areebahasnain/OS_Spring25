CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main

main: main.o Student.o Teacher.o Course.o
	$(CXX) $(CXXFLAGS) -o main main.o Student.o Teacher.o Course.o

main.o: main.cpp Student.h Teacher.h Course.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Student.o: Student.cpp Student.h Course.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

Teacher.o: Teacher.cpp Teacher.h Course.h
	$(CXX) $(CXXFLAGS) -c Teacher.cpp

Course.o: Course.cpp Course.h
	$(CXX) $(CXXFLAGS) -c Course.cpp

clean:
	rm -f *.o main
