#include "oscillator.hpp"

Oscillator::Oscillator(double mass, double stiffness, double damping) {
	m = mass;
	k = stiffness;
	c = damping;
}
State Oscillator::derivative(const State& s) const {
	State ds;
	ds.x = s.v; 
	ds.v = -(k/m) * s.x - (c / m) * s.v;
	return ds;
}
