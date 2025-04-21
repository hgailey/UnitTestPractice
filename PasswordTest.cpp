/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Empty string fails
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

// Shoould pass the test with a capital p and multiple lowercase letters
TEST(PasswordTest, mixed_mixed_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("Password");
	ASSERT_EQ(1, actual);
}

// Is not a valid password with all capitals -> return false
TEST(PasswordTest, mixed_upper_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("PASSWORD");
	ASSERT_EQ(0, actual);
}

// Is not a valid password with all lowercase -> return false
TEST(PasswordTest, mixed_lower_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("password");
	ASSERT_EQ(0, actual);
}

// Is not a valid password with empty string -> return false
TEST(PasswordTest, mixed_empty_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(0, actual);
}



