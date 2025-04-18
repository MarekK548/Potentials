//
// Created by marek on 4/17/25.
//

#include <gtest/gtest.h>
#include "../src/EnsembleOfParticles.h"
#include "../src/Particle.h"

class EnsembleTest : public testing::Test {
public:
    EnsembleTest() : testParticle(1, {0, 0}, {0, 0}),
                     testParticle2(1, {2, 2}, {0, 0}) {
    }

protected:
    EnsembleOfParticles testEnsemble;
    Particle testParticle;
    Particle testParticle2;
};


TEST_F(EnsembleTest, EnsembleTest_addAParticle) {
    testEnsemble.addParticle(testParticle);
}

TEST_F(EnsembleTest, EnsembleTest_addMultipleParticles) {
    testEnsemble.addParticle(testParticle);
    testEnsemble.addParticle(testParticle2);
}

TEST_F(EnsembleTest, EnsembleTest_updateParticles) {
    testEnsemble.updateAll();
}
