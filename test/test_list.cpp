#include <gtest.h>
#include "forward_list.h"

TEST(ForwardList, can_create_list)
{
    ForwardList list(10, 2);
    EXPECT_EQ(list[0], 2);
}
TEST(ForwardList, can_assign_to_list)
{
    ForwardList destination(10, 3);
    ForwardList donor(5, 1);

    destination = donor;

    EXPECT_EQ(destination.size(), 5);
    EXPECT_EQ(destination[0], 1);
}

