#include <gtest/gtest.h>

#include <memory>
#include "test_DummyPotentialElement.h"
#include "../src/EnsembleOfParticles.h"
#include "../src/Particle.h"
#include "../src/Potential.h"

class EnsembleTest : public testing::Test {
public:
    EnsembleTest() : testParticle(1, {0, 0}, {0, 0}),
                     testParticle2(1, {2, 2}, {0, 0}) {
        auto const elPot1 = std::make_shared<DummyPotentialElement>();
        testPotential.addElement(elPot1);
    }

protected:
    EnsembleOfParticles testEnsemble;
    Particle testParticle;
    Particle testParticle2;
    Potential testPotential;
};


TEST_F(EnsembleTest, EnsembleTest_addAParticle) {
    testEnsemble.addParticle(testParticle);
}

TEST_F(EnsembleTest, EnsembleTest_addMultipleParticles) {
    testEnsemble.addParticle(testParticle);
    testEnsemble.addParticle(testParticle2);
}

TEST_F(EnsembleTest, EnsembleTest_getPositionsOfMultipleParticles) {
    testEnsemble.addParticle(testParticle);
    testEnsemble.addParticle(testParticle2);
    auto const positions = testEnsemble.getCurrentPositions();
    ASSERT_DOUBLE_EQ(positions[0][0], 0);
    ASSERT_DOUBLE_EQ(positions[0][1], 0);
    ASSERT_DOUBLE_EQ(positions[1][0], 2);
    ASSERT_DOUBLE_EQ(positions[1][1], 2);
}

TEST_F(EnsembleTest, EnsembleTest_updateParticles) {
    testEnsemble.addParticle(testParticle);
    testEnsemble.addParticle(testParticle2);
    testEnsemble.updateAll(testPotential, 0, 0.1);
    auto const positions = testEnsemble.getCurrentPositions();
    ASSERT_DOUBLE_EQ(positions[0][0], 0.0100);
    ASSERT_DOUBLE_EQ(positions[0][1], 0.0150);
    ASSERT_DOUBLE_EQ(positions[1][0], 2.0100);
    ASSERT_DOUBLE_EQ(positions[1][1], 2.0150);
}
