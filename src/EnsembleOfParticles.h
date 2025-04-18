//
// Created by marek on 4/17/25.
//

#pragma once
#include "Particle.h"


class EnsembleOfParticles {
public:
    void addParticle(const Particle& particle);
    void updateAll();



private:
    std::vector<Particle> particles;
};

