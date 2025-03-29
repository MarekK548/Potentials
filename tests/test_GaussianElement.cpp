#include <gtest/gtest.h>
#include "../src/GaussianElement.h"


class TestGaussianElement : public testing::Test
{
protected:
	GaussianElement gaussianAtZero{ 0, 0, 0, 0 };
};


TEST_F(TestGaussianElement, CreateAGaussian)
{
	gaussianAtZero;
}

