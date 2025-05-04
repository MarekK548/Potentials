//
// Created by marek on 5/4/25.
//
#pragma once

#include "../src/ElementPot.h"

class DummyPotentialElement final : public ElementPot {
public:
    [[nodiscard]] double getValue(const std::vector<double> &spatial, double t) const override;

    [[nodiscard]] std::vector<double> getDerivative(const std::vector<double> &spatial, double t) const override;
};


inline double DummyPotentialElement::getValue(const std::vector<double> &spatial, const double t) const {
    return 1;
}

inline std::vector<double> DummyPotentialElement::getDerivative(const std::vector<double> &spatial,
                                                                const double t) const {
    return {2, 3};
}
