#include <gtest/gtest.h>
#include "../src/GaussianElement.h"


constexpr double startingAmp = 1;
constexpr double sigma = 1;
constexpr double t_0 = 0, x_0 = 0, y_0 = 0;

class TestGaussianElement : public testing::Test
{
protected:
	GaussianElement gaussian2DAt000{ startingAmp, {x_0, y_0}, sigma, t_0 };
	GaussianElement gaussian2DAt100{ startingAmp, {1, y_0}, sigma, t_0 };
	GaussianElement gaussian2DAt010{ startingAmp, {x_0, 1}, sigma, t_0 };
	GaussianElement gaussian2DAt001{ startingAmp, {x_0, y_0}, sigma, 1 };
	GaussianElement gaussian2DAt111{ startingAmp, {1, 1}, sigma, 1 };
};


TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsFullAmpAtCenter)
{
	ASSERT_DOUBLE_EQ(gaussian2DAt000.getValue({0,0}, 0), 1);
	ASSERT_DOUBLE_EQ(gaussian2DAt100.getValue({ 1,0 }, 0), 1);
	ASSERT_DOUBLE_EQ(gaussian2DAt010.getValue({ 0, 1 }, 0), 1);
	ASSERT_DOUBLE_EQ(gaussian2DAt001.getValue({ 0,0 }, 1), 1);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsNearZeroFarInX)
{
	ASSERT_NEAR(gaussian2DAt000.getValue({ 100, 0 }, 0), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt100.getValue({ 100, 0 }, 0), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt010.getValue({ 100, 0 }, 0), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt001.getValue({ 100, 0 }, 0), 0, 0.0000000001);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsNearZeroFarInY)
{
	ASSERT_NEAR(gaussian2DAt000.getValue({ 0, 100 }, 0), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt100.getValue({ 0, 100 }, 0), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt010.getValue({ 0, 100 }, 0), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt001.getValue({ 0, 100 }, 0), 0, 0.0000000001);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsNearZeroFarInT)
{
	ASSERT_NEAR(gaussian2DAt000.getValue({ 0, 0 }, 100), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt100.getValue({ 0, 0 }, 100), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt010.getValue({ 0, 0 }, 100), 0, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt001.getValue({ 0, 0 }, 100), 0, 0.0000000001);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsSensibleValues)
{
	ASSERT_NEAR(gaussian2DAt000.getValue({ 1, 0 }, 0), 0.6065306597, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt000.getValue({ 0, 1 }, 0), 0.6065306597, 0.0000000001);
	ASSERT_NEAR(gaussian2DAt111.getValue({ 1, 1 }, 0), 0.6065306597, 0.0000000001);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsZeroDerivativeInCenterRegardlessOfTime)
{
	const std::vector<double> derivativeAtCenter000 = gaussian2DAt000.getDerivative({ 0,0 }, 0);
	ASSERT_EQ(derivativeAtCenter000.size(), 2);
	ASSERT_DOUBLE_EQ(derivativeAtCenter000[0], 0);
	ASSERT_DOUBLE_EQ(derivativeAtCenter000[1], 0);

	const std::vector<double> derivativeAtCenter111 = gaussian2DAt111.getDerivative({ 1,1 }, 3);
	ASSERT_EQ(derivativeAtCenter111.size(), 2);
	ASSERT_DOUBLE_EQ(derivativeAtCenter111[0], 0);
	ASSERT_DOUBLE_EQ(derivativeAtCenter111[1], 0);
}

TEST_F(TestGaussianElement, twoDimensionalGaussianReturnsSensibleValuesForDerivativeOutsideOfCenter)
{
	const std::vector<double> derivativeOffsetAtXOf000 = gaussian2DAt000.getDerivative({ 1, 0 }, 0);
	ASSERT_NEAR(derivativeOffsetAtXOf000[0], -0.6065306597, 0.0000000001);
	ASSERT_DOUBLE_EQ(derivativeOffsetAtXOf000[1], 0);

	const std::vector<double> derivativeOffsetAtYOf111 = gaussian2DAt111.getDerivative({ 1, 0 }, 1);
	ASSERT_DOUBLE_EQ(derivativeOffsetAtYOf111[0], 0);
	ASSERT_NEAR(derivativeOffsetAtYOf111[1], 0.6065306597, 0.0000000001);

}