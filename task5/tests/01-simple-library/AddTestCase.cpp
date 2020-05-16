#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTestCase, Negative_Positive) {
    ASSERT_EQ(Add(-1, 3), 2);
}

TEST(AddTestCase, Positive_Negative) {
    ASSERT_EQ(Add(4, -2), 2);
}

TEST(AddTestCase, Zero_Positive) {
    ASSERT_EQ(Add(0, 7), 7);
}

TEST(AddTestCase, Negative_Zero) {
    ASSERT_EQ(Add(-7, 0), -7);
}

TEST(AddTestCase, Zero_Zero) {
    ASSERT_EQ(Add(0, 0), 0);
}

TEST(AddTestCase, Positive_Positive) {
    ASSERT_EQ(Add(1, 4), 5);
}

TEST(AddTestCase, Negative_Negative) {
    ASSERT_EQ(Add(-3, -2), -5);
}
