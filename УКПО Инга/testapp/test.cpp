#include "../Libapp/IStar.h"
#include "iostream"
#include <cmath>
#include <gtest\gtest.h>

//////////////////////  Black

TEST(libapp, justAdd)
{
	EXPECT_EQ(start(2, 13, 15, 7, true), "0077070070077");
}


TEST(libapp, addOneMax)
{
	EXPECT_EQ(start(2147483648, 13, 15, 7, true), "An empty route generated!");
}


TEST(libapp, addMax)
{
	EXPECT_EQ(start(2147483648, -13, 2147483699, -2147483688, true), "An empty route generated!");
}

