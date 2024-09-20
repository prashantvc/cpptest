#include <gtest/gtest.h>
#include <limits>

int add(int a, int b)
{
  return a + b;
}

TEST(AdditionTest, PositiveNumbers)
{
  EXPECT_EQ(add(2, 3), 5) << "Expected add(2, 3) to be 5";
}

TEST(AdditionTest, NegativeNumbers)
{
  EXPECT_EQ(add(-2, -3), -5) << "Expected add(-2, -3) to be -5";
  EXPECT_EQ(add(-2, 3), 1) << "Expected add(-2, 3) to be 1";
  EXPECT_EQ(add(2, -3), -1) << "Expected add(2, -3) to be -1";
}

TEST(AdditionTest, Zero)
{
  EXPECT_EQ(add(0, 0), 0) << "Expected add(0, 0) to be 0";
  EXPECT_EQ(add(0, 5), 5) << "Expected add(0, 5) to be 5";
  EXPECT_EQ(add(5, 0), 5) << "Expected add(5, 0) to be 5";
}

TEST(AdditionTest, LargeNumbers)
{
  EXPECT_EQ(add(1000000, 2000000), 3000000) << "Expected add(1000000, 2000000) to be 3000000";
  EXPECT_EQ(add(-1000000, -2000000), -3000000) << "Expected add(-1000000, -2000000) to be -3000000";
}

TEST(AdditionTest, EdgeCases)
{
  EXPECT_EQ(add(std::numeric_limits<int>::max(), 0), std::numeric_limits<int>::max()) << "Expected add(INT_MAX, 0) to be INT_MAX";
  EXPECT_EQ(add(std::numeric_limits<int>::min(), 0), std::numeric_limits<int>::min()) << "Expected add(INT_MIN, 0) to be INT_MIN";
  EXPECT_EQ(add(std::numeric_limits<int>::max(), -1), std::numeric_limits<int>::max() - 1) << "Expected add(INT_MAX, -1) to be INT_MAX - 1";
  EXPECT_EQ(add(std::numeric_limits<int>::min(), 1), std::numeric_limits<int>::min() + 1) << "Expected add(INT_MIN, 1) to be INT_MIN + 1";
}