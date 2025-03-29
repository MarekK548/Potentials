#include "GaussianElement.h"
#include <cmath>

GaussianElement::GaussianElement(const double A_0, const std::vector<double> spatial_0, const double sigma, const double t_0)
	: A_0{ A_0 }, spatial_0{ spatial_0 }, sigma{sigma}, t_0{t_0}
{
}

