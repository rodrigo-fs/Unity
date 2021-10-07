#include "sorting.h"
#include "unity.h"
#include "unity_fixture.h"
#define VECTOR_SIZE 10
TEST_GROUP(Sorting);

int actual[VECTOR_SIZE];
//int * expected;

void populate_array(int* v, int size){
  for(int i = 0 ; i < size; i++){
    //0 for desc and 1 for asc
    int value = (size-1) - i;
    v[i] = value;
  }
}

TEST_SETUP(Sorting)
{
  populate_array(actual, VECTOR_SIZE);
}

TEST_TEAR_DOWN(Sorting)
{
}
//Sort All Array
TEST(Sorting, TestSorting1)
{
  int expected[VECTOR_SIZE] = {0,1,2,3,4,5,6,7,8,9};
  sort(actual, VECTOR_SIZE);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, VECTOR_SIZE);
}
//Sort only half of the array
TEST(Sorting, TestSorting2)
{
  int expected[VECTOR_SIZE] = {5,6,7,8,9,4,3,2,1};
  sort(actual, VECTOR_SIZE / 2);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, VECTOR_SIZE);
}

/*
TEST(Sorting, TestSorting2)
{
  // This test will fail
  TEST_ASSERT_EQUAL(2, foo(1,2));
}
*/