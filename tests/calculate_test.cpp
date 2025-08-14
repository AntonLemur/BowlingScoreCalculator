#include <gtest/gtest.h>

#include "calculate.h"


// TEST(TEST_SUITE, TEST_CASE)

TEST(BowlingScoreCalculator, CalcScoreTest)
{
    ASSERT_EQ(calculate_score(), "Hello from calculate_score");
}
