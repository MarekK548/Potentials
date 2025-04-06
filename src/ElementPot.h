#pragma once
#include <vector>

class ElementPot
{	
public:
	ElementPot() {};
	virtual double getValue(const std::vector<double>& spatial, const double t) const = 0;
	virtual std::vector<double> getDerivative(const std::vector<double>& spatial, const double t) const = 0;
};

