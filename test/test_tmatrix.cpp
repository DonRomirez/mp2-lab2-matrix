#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> s(10), cop(s);
	EXPECT_EQ(1, s == cop);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
 TMatrix<int> s(10), cop(s);
 cop[0][0] = 1;
 EXPECT_EQ(1, cop[0][0] != s[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> s(20);
	EXPECT_EQ(1, s.GetSize() == 20);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> s(20);
	s[0][0] = 1;
    EXPECT_EQ(1, s[0][0]==1);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> s(20);
	ASSERT_ANY_THROW(s[-1][0] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> s(20);
	ASSERT_ANY_THROW(s[500][0] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> s(20);
	
	ASSERT_NO_THROW(s = s);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> s(20), s1(20);
	ASSERT_NO_THROW(s = s);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> s(10), s1(20);
	s = s1;

	EXPECT_EQ(1, s1.GetSize() == s.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> s(10), s1(20);
	ASSERT_NO_THROW(s = s1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> s(10), s1(10);
	s[0][0] = 1;
	s1[0][0] = 1;
	EXPECT_EQ(1, s1 == s);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> s(10);
	EXPECT_EQ(1, s == s);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> s(10),s2(20);
	EXPECT_EQ(0, s == s2);;
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> s(10),s1(10);
	ASSERT_NO_THROW(s = s+s1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> s(10), s1(20);
	ASSERT_ANY_THROW(s = s + s1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> s(10), s1(10);
	ASSERT_NO_THROW(s = s - s1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> s(10), s1(20);
	ASSERT_ANY_THROW(s = s - s1);
}

