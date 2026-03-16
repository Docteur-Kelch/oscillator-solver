#include <iostream>
#include <fstream>
#include "oscillator.hpp"
#include "solver.hpp"


int main() {

	Oscillator osc(1.0, 10.0, 0.5);
    
	double dt = 0.01;
	double T = 100.0;

	int N = T / dt;
	State s ;
	s.x = 1.0;
	s.v = 0.0;

	std::ofstream file("result.dat");
	for (int i = 0; i < N; i++)
	{
		double t = i * dt;
		file << t << " "
			<< s.x << " "
			<< s.v << std::endl;
		s = Solver::rk4_step(osc, s, dt);

	}
	file.close();
	std::cout << "Simulation finished" << std::endl;

}