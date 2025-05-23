#pragma once

#include <vector>

class Potential;

class Particle {
public:
    Particle(double mass, const std::vector<double> &spatial, const std::vector<double> &velocity);

    void update(const std::vector<double> &force, double dt);

    void update(const Potential &pot, double dt, double t);

    [[nodiscard]] inline std::vector<double> getPosition() const;

private:
    void VerletIntegration(const std::vector<double> &acceleration, double dt);

private:
    const double mass;
    const std::vector<double> spatial_0;
    const std::vector<double> velocity_0;
    std::vector<double> spatial_old;
    std::vector<double> spatial_current;
    std::vector<double> velocity_current;
    bool first_iteration;
};


inline std::vector<double> Particle::getPosition() const {
    return spatial_current;
}
