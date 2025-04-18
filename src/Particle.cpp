#include "../src/Particle.h"
#include <vector>
#include <cmath>

using std::vector;

Particle::Particle(const double mass, const vector<double> &spatial, const vector<double> &velocity) : mass{mass},
	spatial_0{spatial}, velocity_0{velocity}, spatial_old{spatial},
	spatial_current{spatial}, velocity_current{velocity}, first_iteration{true} {
}

void Particle::update(const vector<double> &force, const double dt) {
	vector<double> acceleration(force.size(), 0);
	for (size_t i = 0; i < force.size(); i++) {
		acceleration[i] = force[i] / mass;
	}
	VerletIntegration(acceleration, dt);
}

void Particle::VerletIntegration(const vector<double> &acceleration, double dt) {
	if (first_iteration) [[unlikely]] {
		spatial_old = spatial_current;
		for (size_t i = 0; i < spatial_current.size(); i++) {
			spatial_current[i] = spatial_current[i] + 1.0 / 2 * acceleration[i] * std::pow(dt, 2);
		}
		first_iteration = false;
		return;
	}
	vector<double> newSpatial(spatial_current.size(), 0);
	for (size_t i = 0; i < spatial_current.size(); i++) {
		newSpatial[i] = 2 * spatial_current[i] - spatial_old[i] + acceleration[i] * std::pow(dt, 2);
	}
	spatial_old = spatial_current;
	spatial_current = newSpatial;
}
