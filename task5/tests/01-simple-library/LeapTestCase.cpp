#include "LeapTestCase.h"
#include "Functions.h"

TEST(LeapTestCase, DividedByHundred) {
    ASSERT_FALSE(IsLeap(1700));
}

TEST(LeapTestCase, OddNumbered) {
    ASSERT_FALSE(IsLeap(2013));
}

TEST(LeapTestCase, EvenNumbered) {
    ASSERT_FALSE(IsLeap(2014));
}

TEST(LeapTestCase, DividedByFour) {
    ASSERT_TRUE(IsLeap(2016));
}

TEST(LeapTestCase, DividedByFourHundred) {
    ASSERT_TRUE(IsLeap(2000));
}

TEST(LeapTestCase, Negative) {
    ASSERT_THROW(IsLeap(-1), std::invalid_argument);
}

TEST(LeapTestCase, Zero) {
    ASSERT_THROW(IsLeap(0), std::invalid_argument);
}
