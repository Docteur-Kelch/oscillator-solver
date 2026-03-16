/*==========================================================
Implémentation du Runge-Kutta 4
============================================================*/
#include "solver.hpp"

State Solver::rk4_step(
    const Oscillator& osc,
    const State& s,
    double dt
)
{

    State k1 = osc.derivative(s);

    State s2;
    s2.x = s.x + 0.5 * dt * k1.x;
    s2.v = s.v + 0.5 * dt * k1.v;

    State k2 = osc.derivative(s2);

    State s3;
    s3.x = s.x + 0.5 * dt * k2.x;
    s3.v = s.v + 0.5 * dt * k2.v;

    State k3 = osc.derivative(s3);

    State s4;
    s4.x = s.x + dt * k3.x;
    s4.v = s.v + dt * k3.v;

    State k4 = osc.derivative(s4);

    State result;

    result.x =
        s.x + dt / 6.0 * (k1.x + 2 * k2.x + 2 * k3.x + k4.x);

    result.v =
        s.v + dt / 6.0 * (k1.v + 2 * k2.v + 2 * k3.v + k4.v);

    return result;
}