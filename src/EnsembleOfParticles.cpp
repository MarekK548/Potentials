//
// Created by marek on 4/17/25.
//

#include "EnsembleOfParticles.h"

void EnsembleOfParticles::addParticle(const Particle &particle) {
    particles.push_back(particle);
}

void EnsembleOfParticles::updateAll(const Potential &pot, const double t, const double dt) {
    for (auto &particle: particles) {
        particle.update(pot, dt, t);
    }
}

std::vector<std::vector<double> > EnsembleOfParticles::getCurrentPositions() const {
    std::vector<std::vector<double> > positions;
    for (auto &particle: particles) {
        positions.push_back(particle.getPosition());
    }
    return positions;
}
