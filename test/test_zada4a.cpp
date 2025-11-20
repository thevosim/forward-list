#include <gtest.h>
#include <vector>
#include "forward_list.h"

class ForwardListTest : public ::testing::Test
{
public:
    void verify(const ForwardList<int>& list, const std::vector<int>& expected)
    {
        auto curr = list.first;
        size_t expected_index = 0;
        while (curr && expected_index < expected.size())
        {
            EXPECT_EQ(curr->m_data, expected[expected_index]);
            curr = curr->m_next;
            ++expected_index;
        }
        EXPECT_EQ(curr, nullptr);
        EXPECT_EQ(expected_index, expected.size());
    }
};

TEST_F(ForwardListTest, multiply_simple_number_no_carry)
{
    ForwardList<int> list;
    list.push_front(3); 
    list.push_front(2);
    list.push_front(1); 
    int factor = 2;
    std::vector<int> expected = {2, 4, 6};

    ForwardList result = list.multiply(factor);

    verify(result, expected);
}

TEST_F(ForwardListTest, multiply_number_with_carry_extends_size)
{
    ForwardList<int> list;
    list.push_front(9);
    list.push_front(9); 
    int factor = 2;
    std::vector<int> expected = {1, 9, 8};

    ForwardList result = list.multiply(factor);

    verify(result, expected);
}

TEST_F(ForwardListTest, multiply_by_zero)
{
    ForwardList<int> list;
    list.push_front(5);
    list.push_front(1); 
    int factor = 0;
    std::vector<int> expected = {0};

    ForwardList result = list.multiply(factor);

    verify(result, expected);
}

TEST_F(ForwardListTest, multiply_large_factor)
{
    ForwardList<int> list;
    list.push_front(5); 
    int factor = 300;
    std::vector<int> expected = {1, 5, 0, 0};

    ForwardList result = list.multiply(factor);

    verify(result, expected);
}
