#include "payment.h"
#include "unity.h"
#include "unity_fixture.h"
#include <string.h>

TEST_GROUP(Payment);
float value;
char status[15];

TEST_SETUP(Payment)
{

}

TEST_TEAR_DOWN(Payment)
{
  memset(status, 0, 15);
}

TEST(Payment, TestPayment1)
{
  value = 1.0f;
  strcpy(status, "VIP");
  TEST_ASSERT_EQUAL(0, payment(value, status));
}

TEST(Payment, TestPayment2)
{
  value = 2.0f;
  strcpy(status, "Regular");
  TEST_ASSERT_EQUAL(0, payment(value, status));
}

TEST(Payment, TestPayment3)
{
  value = 3.0f;
  strcpy(status, "Estudante");
  TEST_ASSERT_EQUAL(0, payment(value, status));
}

TEST(Payment, TestPayment4)
{
  value = 4.0f;
  strcpy(status, "Aposentado");
  TEST_ASSERT_EQUAL(0, payment(value, status));
}

TEST(Payment, TestPayment5)
{
  value = 5.0f;
  strcpy(status, "Dummy!#&*");
  TEST_ASSERT_EQUAL(1, payment(value, status));
}

TEST(Payment, TestPayment6)
{
  value = 0.00f;
  strcpy(status, "VIP");
  TEST_ASSERT_EQUAL(2, payment(value, status));
}

//Value limit tests
TEST(Payment, TestPayment7)
{
  value = 0.010f;
  strcpy(status, "VIP");
  TEST_ASSERT_EQUAL(0, payment(value, status));
}

TEST(Payment, TestPayment8)
{
  value = 99999.00f;
  strcpy(status, "VIP");
  TEST_ASSERT_EQUAL(0, payment(value, status));
}

TEST(Payment, TestPayment9)
{
  value = 0.009f;
  strcpy(status, "VIP");
  TEST_ASSERT_EQUAL(2, payment(value, status));
}

TEST(Payment, TestPayment10)
{
  value = 99999.1f;
  strcpy(status, "VIP");
  TEST_ASSERT_EQUAL(2, payment(value, status));
}