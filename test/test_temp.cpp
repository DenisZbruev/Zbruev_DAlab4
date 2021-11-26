#include "Typeelem.h"

#include <gtest.h>

TEST(TypeElem, can_create_typeelem_with_with_positive_count_and_time)
{
    ASSERT_NO_THROW(Typeelem a("",4,5));
}
TEST(Typeelem, cant_create_default_typelem)
{
    ASSERT_NO_THROW(Typeelem a);
}
TEST(Typeelem, throws_when_create_typeelem_with_negative_time)
{
    ASSERT_ANY_THROW(Typeelem m("", -4,4));
}
TEST(Typeelem, throws_when_create_typeelem_with_negative_count)
{
  ASSERT_ANY_THROW(Typeelem m("",4,-4));
}
TEST(Typeelem, can_create_copied_typeelem)
{
    Typeelem m;
    ASSERT_NO_THROW(Typeelem m2(m));
}
TEST(Typeelem, can_get_name_of_typeelem)
{
    Typeelem a("a", 4, 4);
    EXPECT_EQ(a.Getname(), "a");
}
TEST(Typeelem, can_get_time_of_typeelem)
{
    Typeelem a("a", 4, 4);
    EXPECT_EQ(a.Gettime(), 4);
}
TEST(Typeelem, can_get_count_of_typeelem)
{
    Typeelem a("a", 4, 4);
    EXPECT_EQ(a.Getcount(), 4);
}



