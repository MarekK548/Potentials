#pragma once
#include <vector>
#include <memory>
#include "ElementPot.h"

class Potential {
public:
    Potential();
    void addElement(std::shared_ptr<ElementPot> el);
    double getValue(const std::vector<double>& spatial, const double t) const;
    std::vector<double> getDerivative(const std::vector<double>& spatial, const double t) const;

private:
    std::vector<std::shared_ptr<ElementPot>> elementsOfPotential;
};
