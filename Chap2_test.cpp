#include <gtest/gtest.h>
#include "Chap2.cpp"

using namespace std;

TEST(Any, Returns_False_On_Empty_Collection) {
    vector<int> collection;
    ASSERT_FALSE(any(collection, [](int n) { return n == 0; }));
}

TEST(Any, Returns_True_When_Match_Exists) {
    vector<int> collection{2, 1, 0, 3};
    ASSERT_TRUE(any(collection, [](int n) { return n == 0; }));
}

TEST(Any, Returns_False_When_Match_Does_Not_Exist) {
    vector<int> collection{2, 1, 4, 3};
    ASSERT_FALSE(any(collection, [](int n) { return n == 0; }));
}

TEST(All, Returns_True_On_Empty_Collection) {
    vector<int> collection;
    ASSERT_TRUE(all(collection, [](int n) { return n == 0; }));
}

TEST(All, Returns_True_When_All_Match) {
    vector<int> collection{0, 0, 0, 0};
    ASSERT_TRUE(all(collection, [](int n) { return n == 0; }));
}

TEST(All, Returns_False_When_One_Does_Not_Match) {
    vector<int> collection{1, 2, 3, 4};
    ASSERT_FALSE(all(collection, [](int n) { return n == 0; }));
}
