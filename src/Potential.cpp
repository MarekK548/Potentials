#include "../src/Potential.h"


Potential::Potential() {
    elementsOfPotential.reserve(100);
}

void Potential::addElement(const std::shared_ptr<ElementPot> el) {
    elementsOfPotential.push_back(el);
}

double Potential::getValue(const std::vector<double> &spatial, double t) const {
    double result = 0;
    for (auto &pot: elementsOfPotential) {
        result += pot->getValue(spatial, t);
    }
    return result;
}

std::vector<double> addTwoVectors(const std::vector<double> &first, const std::vector<double> &second) {
    std::vector<double> result(first.size(), 0);
    for (size_t i = 0; i < result.size(); i++) {
        result[i] = first[i] + second[i];
    }
    return result;
}


std::vector<double> Potential::getDerivative(const std::vector<double> &spatial, double t) const {
    std::vector<double> result(spatial.size(), 0);
    for (auto &pot: elementsOfPotential) {
        std::vector<double> singleDerivative = pot->getDerivative(spatial, t);
        result = addTwoVectors(result, singleDerivative);
    }
    return result;
}
