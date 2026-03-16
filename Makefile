CXX = g++
CXXFLAGS = -O2 -Wall

OBJ = main.o oscillator.o solver.o

oscillator_solver: $(OBJ)
	$(CXX) $(CXXFLAGS) -o oscillator_solver $(OBJ)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

oscillator.o: oscillator.cpp
	$(CXX) $(CXXFLAGS) -c oscillator.cpp

solver.o: solver.cpp
	$(CXX) $(CXXFLAGS) -c solver.cpp

clean:
	rm -f *.o oscillator_solver