#include <gtest/gtest.h>
#include <vector>
#include "../src/Particle.h"


class ParticleTest : public testing::Test
{
protected:
	Particle particle{1 , {0,0}, {0,0} };
};

TEST_F(ParticleTest, Particle_DoesntMoveWhenNoForce)
{
	const std::vector<double> force{ 0, 0 };
	const double dt = 0.1;
	particle.update(force, dt);
	const auto newPos = particle.getPosition();
	ASSERT_EQ(newPos.size(), 2);
	ASSERT_DOUBLE_EQ(newPos[0], 0);
	ASSERT_DOUBLE_EQ(newPos[1], 0);
}

TEST_F(ParticleTest, Particle_ForceMovesParticleInCorrectWay)
{
	const std::vector<double> force{ 100, -100 };
	const double dt = 0.1;
	particle.update(force, dt);
	const auto newPos = particle.getPosition();
	ASSERT_NEAR(newPos[0],  0.5, 0.001);
	ASSERT_NEAR(newPos[1], -0.5, 0.001);

}