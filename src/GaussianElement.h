#pragma once

#include "../src/ElementPot.h"
#include <vector>
#include <cmath>

class GaussianElement : public ElementPot {
public:
    inline GaussianElement(const double A_0, const std::vector<double> spatial_0, const double sigma, const double t_0);

    double getValue(const std::vector<double> &spatial, const double t) const override;

    std::vector<double> getDerivative(const std::vector<double> &spatial, const double t) const override;

private:
    inline double gaussian_exp_func(double x, double y, double sigma) const;

private:
    double A_0;
    const std::vector<double> spatial_0;
    const double sigma;
    const double t_0;
};


inline GaussianElement::GaussianElement(const double A_0, const std::vector<double> spatial_0, const double sigma,
                                        const double t_0)
    : A_0{A_0}, spatial_0{spatial_0}, sigma{sigma}, t_0{t_0} {
}

double GaussianElement::getValue(const std::vector<double> &spatial, const double t) const {
    double value = A_0;
    for (size_t i = 0; i < spatial.size(); i++) {
        value *= gaussian_exp_func(spatial[i], spatial_0[i], sigma);
    }
    value *= gaussian_exp_func(t, t_0, sigma);
    return value;
}

std::vector<double> GaussianElement::getDerivative(const std::vector<double> &spatial, const double t) const {
    std::vector<double> derivative(spatial.size(), 0);
    for (size_t i = 0; i < spatial.size(); i++) {
        derivative[i] = -(spatial[i] - spatial_0[i]) / (std::pow(sigma, 2)) * getValue(spatial, t);
    }
    return derivative;
}

inline double GaussianElement::gaussian_exp_func(double x, double x_0, double sigma) const {
    return std::exp(-std::pow((x - x_0), 2) / (2 * std::pow(sigma, 2)));
}
