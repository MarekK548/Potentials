#include <gtest/gtest.h>
#include "../src/GaussianElement.h"


constexpr double startingAmp = 1;

class TestGaussianElement : public testing::Test
{
protected:
	GaussianElement gaussian2DAtZero{ startingAmp, {0, 0}, 1, 0 };
};


TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsFullAmpAtAll0)
{
	ASSERT_FLOAT_EQ(gaussian2DAtZero.getValue({0,0}, 0), 1);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsNearZeroFarInX)
{
	ASSERT_NEAR(gaussian2DAtZero.getValue({ 100, 0 }, 0), 0, 0.0000000001);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsNearZeroFarInY)
{
	ASSERT_NEAR(gaussian2DAtZero.getValue({ 0, 100 }, 0), 0, 0.0000000001);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsNearZeroFarInT)
{
	ASSERT_NEAR(gaussian2DAtZero.getValue({ 0, 0 }, 100), 0, 0.0000000001);
}