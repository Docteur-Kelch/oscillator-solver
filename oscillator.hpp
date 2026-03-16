#ifndef OSCILLATOR_HPP
#define OSCILLATOR_HPP

struct	State{
	double x;// position
    double v; //vitesse

};

class Oscillator {

 private :
	double m;
	double k;
	double c;
 public :
	 Oscillator(double mass, double stiffness, double damping);
	 State derivative(const State& s) const;
};

#endif
