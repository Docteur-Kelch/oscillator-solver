/*==========================================================
Interface solveur
============================================================*/
#ifndef SOLVER_HPP
#define	SOLVER_HPP
#include "oscillator.hpp"


class Solver {
public:
	static State rk4_step(
		const Oscillator& osc, const State& s, double dt
		);
};

#endif