#include <gtest/gtest.h>

#include "Array.h"
#include "Array.cpp"

TEST(push, ElementsAddition)
{
  ds::Array<int> arr;

  arr.push(0);
  arr.push(1);
  arr.push(2);
  arr.push(3);

  EXPECT_EQ(arr.at(2), 2);
  EXPECT_EQ(arr.at(0), 0);
  EXPECT_NE(arr.at(1), 0);

  arr.push(4);
  arr.push(5);
  arr.push(6);

  EXPECT_EQ(arr.at(5), 5);
  EXPECT_EQ(arr.at(3), 3);
}
