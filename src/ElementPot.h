#pragma once
#include <vector>

class ElementPot {
public:
    virtual ~ElementPot() = default;

    ElementPot() = default;

    [[nodiscard]] virtual double getValue(const std::vector<double> &spatial, double t) const = 0;

    [[nodiscard]] virtual std::vector<double> getDerivative(const std::vector<double> &spatial, double t) const = 0;
};
