//
// Created by marek on 4/17/25.
//

#include "EnsembleOfParticles.h"

void EnsembleOfParticles::addParticle(const Particle &particle) {
    particles.push_back(particle);
}

void EnsembleOfParticles::updateAll() {
    for (auto & particle : particles) {

    }
}

