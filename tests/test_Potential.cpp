#include <gtest/gtest.h>
#include "../src/Potential.h"
#include "../src/ElementPot.h"
#include "../tests/test_DummyPotentialElement.h"


class PotentialTest : public testing::Test {
protected:
    Potential potential{};
    std::shared_ptr<DummyPotentialElement> dummyElement = std::make_shared<DummyPotentialElement>();
    std::shared_ptr<DummyPotentialElement> dummyElement2 = std::make_shared<DummyPotentialElement>();
};

TEST_F(PotentialTest, Potential_getValueReturnsValueOfAnElement) {
    potential.addElement(dummyElement);
    ASSERT_DOUBLE_EQ(potential.getValue({ 0, 0 }, 0), 1);
    ASSERT_DOUBLE_EQ(potential.getValue({ 100, 100 }, 100), 1);
}

TEST_F(PotentialTest, Potential_getValueReturnsSumOfValuesOfElements) {
    potential.addElement(dummyElement);
    potential.addElement(dummyElement2);
    ASSERT_DOUBLE_EQ(potential.getValue({0, 0}, 0), 2);
}

TEST_F(PotentialTest, Potential_getDerivativeReturnsCorrectValueForSingleElement) {
    potential.addElement(dummyElement);
    auto derivative = potential.getDerivative({0, 0}, 0);
    ASSERT_DOUBLE_EQ(derivative[0], 2);
    ASSERT_DOUBLE_EQ(derivative[1], 3);
}

TEST_F(PotentialTest, Potential_getDerivativeReturnsCorrectSumForMultipleElements) {
    potential.addElement(dummyElement);
    potential.addElement(dummyElement2);
    auto derivative = potential.getDerivative({0, 0}, 0);
    ASSERT_DOUBLE_EQ(derivative[0], 4);
    ASSERT_DOUBLE_EQ(derivative[1], 6);
}
