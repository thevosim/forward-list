#include <gtest.h>
#include "forward_list.h"

TEST(ForwardList, can_create_list)
{
    ForwardList<int> list(10, 2);
    EXPECT_EQ(list[0], 2);
}

TEST(ForwardList, can_assign_to_list)
{
    ForwardList<int> destination(10, 3);
    ForwardList<int> donor(5, 1);

    destination = donor;

    EXPECT_EQ(destination.size(), 5);
    EXPECT_EQ(destination[0], 1);
}

TEST(ForwardList, can_copy_list)
{
    ForwardList<int> donor(5, 1);
    ForwardList<int> destination(donor);
    
    EXPECT_EQ(destination[2], 1);
}

TEST(ForwardList, can_push_front)
{
    ForwardList<int> list;

    list.push_front(10);

    EXPECT_EQ(list[0], 10);
}

TEST(ForwardList, push_front_updates_existing_list)
{
    ForwardList<int> list;
    
    list.push_front(10);
    list.push_front(20);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], 20);
}

TEST(ForwardList, can_erase_front)
{
    ForwardList<int> list;

    list.push_front(10);
    list.push_front(20);
    list.erase_front();

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list[0], 10);
}

TEST(ForwardList, at_returns_correct_value)
{
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);

    EXPECT_EQ(list.at(0), 20);
}

TEST(ForwardList, at_throws_exception)
{
    ForwardList<int> list;
    list.push_front(10);

    EXPECT_ANY_THROW(list.at(1));
}

TEST(ForwardList, can_insert_after_head)
{
    ForwardList<int> list;
    list.push_front(10);
    auto it = list.begin();

    list.insert_after(it, 20);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[1], 20);
}

TEST(ForwardList, can_insert_after_middle)
{
    ForwardList<int> list;
    list.push_front(30);
    list.push_front(10);
    auto it = list.begin(); 

    list.insert_after(it, 20); 

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list[1], 20);
}

TEST(ForwardList, can_erase_after_head)
{
    ForwardList<int> list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    auto it = list.begin();

    list.erase_after(it);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[1], 30);
}

TEST(ForwardList, iterators_begin_end)
{
    ForwardList<int> list;
    list.push_front(20);
    list.push_front(10);

    auto it = list.begin();
    
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(ForwardList, iterators_loop_check)
{
    ForwardList<int> list(3, 5);
    int count = 0;

    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, 5);
        count++;
    }

    EXPECT_EQ(count, 3);
}