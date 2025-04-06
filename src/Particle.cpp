#include "../src/Particle.h"
#include <vector>

using std::vector;

Particle::Particle(const double mass, const vector<double>& spatial, const vector<double>& velocity) :
	mass{ mass }, spatial_0{ spatial }, velocity_0{ velocity }, spatial_old{ spatial },
	spatial_current{ spatial }, velocity_current{ velocity }, first_iteration{ false }
{
}

void Particle::update(const vector<double> force, const double dt)
{
	vector<double> acceleration( force.size(), 0 );
	for (size_t i = 0; i < force.size(); i++)
	{
		acceleration[i] = force[i] / mass;
	}

}

vector<double> Particle::getPosition() const
{
	return spatial_current;
}



void Particle::VerletIntegration(vector<double> acceleration)
{
	if (first_iteration) [[unlikely]]
	{
	}
}