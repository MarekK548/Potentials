//
// Created by marek on 4/17/25.
//

#pragma once
#include "Particle.h"


class EnsembleOfParticles {
public:
    void addParticle(const Particle &particle);

    void updateAll(const Potential &pot, double t, double dt);

    [[nodiscard]] std::vector<std::vector<double> > getCurrentPositions() const;

private:
    std::vector<Particle> particles;
};
