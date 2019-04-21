#include <gtest/gtest.h>

#include "Dummy.h"

TEST(absolute, NegativeNumbers)
{
  sample::Dummy d = sample::Dummy();
  ASSERT_EQ(d.absolute(-5), 5);
}
