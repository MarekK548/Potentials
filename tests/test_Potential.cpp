#include <gtest/gtest.h>
#include "../src/Potential.h"
#include "../src/ElementPot.h"

class DummyElement : public ElementPot
{
public: 
    double getValue(const std::vector<double>& spatial, const double t) const override;
    std::vector<double> getDerivative(const std::vector<double>& spatial, const double t) const override;
};


double DummyElement::getValue(const std::vector<double>& spatial, const double t) const
{
    return 1;
}

std::vector<double> DummyElement::getDerivative(const std::vector<double>& spatial, const double t) const
{
    return {2, 3};
}

class PotentialTest : public testing::Test
{
protected:
    Potential potential{};
    std::shared_ptr<DummyElement> dummyElement = std::make_shared<DummyElement>();
    std::shared_ptr<DummyElement> dummyElement2 = std::make_shared<DummyElement>();
};

TEST_F(PotentialTest, Potential_getValueReturnsValueOfAnElement)
{
    potential.addElement(dummyElement);
    ASSERT_DOUBLE_EQ(potential.getValue({ 0, 0 }, 0), 1);
    ASSERT_DOUBLE_EQ(potential.getValue({ 100, 100 }, 100), 1);
}

TEST_F(PotentialTest, Potential_getValueReturnsSumOfValuesOfElements)
{
    potential.addElement(dummyElement);
    potential.addElement(dummyElement2);
    ASSERT_DOUBLE_EQ(potential.getValue({0, 0}, 0), 2);
}

TEST_F(PotentialTest, Potential_getDerivativeReturnsCorrectValueForSingleElement)
{
    potential.addElement(dummyElement);
    auto derivative = potential.getDerivative({0, 0}, 0);
    ASSERT_DOUBLE_EQ(derivative[0], 2);
    ASSERT_DOUBLE_EQ(derivative[1], 3);
}
TEST_F(PotentialTest, Potential_getDerivativeReturnsCorrectSumForMultipleElements)
{
    potential.addElement(dummyElement);
    potential.addElement(dummyElement2);
    auto derivative = potential.getDerivative({ 0, 0 }, 0);
    ASSERT_DOUBLE_EQ(derivative[0], 4);
    ASSERT_DOUBLE_EQ(derivative[1], 6);
}