#include <vector>
#include <cmath>

class GaussianElement
{
public:
	GaussianElement(const double A_0, const std::vector<double> spatial_0, const double sigma, const double t_0);
	inline double getValue(const std::vector<double> spatial, const double t);

private:
	inline double exponential_func(double x, double y, double sigma);


private:
	double A_0;
	const std::vector<double> spatial_0;
	const double sigma;
	const double t_0;
};

inline double GaussianElement::getValue(const std::vector<double> spatial, const double t)
{
	double value = A_0;
	for (size_t i = 0; i < spatial.size(); i++)
	{
		value *= exponential_func(spatial[i], spatial_0[i], sigma);
	}
	value *= exponential_func(t, t_0, sigma);
	return value;
}

inline double GaussianElement::exponential_func(double x, double x_0, double sigma)
{
	return std::exp(-std::pow((x - x_0), 2) / (2 * std::pow(sigma, 2)));
}
