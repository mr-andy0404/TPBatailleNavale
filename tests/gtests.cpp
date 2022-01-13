#include <gtest/gtest.h>

#include "src/lib.h"

void test_add(int const p_a, int const p_b)
{
    ASSERT_EQ(add(p_a, p_b), p_a + p_b)
        << "Error: " << p_a << " + " << p_b << " == " << p_a + p_b << " and not " << add(p_a, p_b) << "\n";
}

TEST(test_Lib_add, Test1)
{
    test_add(5, 3);
    test_add(15, 23);
}

TEST(test_Lib_add, Test2)
{
    test_add(0, 1);
    test_add(1, 0);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
