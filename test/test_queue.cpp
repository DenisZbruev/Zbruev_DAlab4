#include "Queue.h"

#include <gtest.h>

TEST(Queue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(Queue q(5));
}

TEST(Queue, cant_create_too_large_quque)
{
    ASSERT_ANY_THROW(Queue q(101));
}

TEST(Queue, throws_when_create_quque_with_negative_size)
{
  ASSERT_ANY_THROW(Queue q(-5));
}

TEST(Queue, can_create_copied_vector)
{
    Queue q(5);

  ASSERT_NO_THROW(Queue q2(q));
}

TEST(Queue, can_get_size)
{
  Queue v(4);
  EXPECT_EQ(4, v.GetSize());
}

TEST(Queue, can_put_element)
{
    Queue v(2);
    Typeelem a("name", 4);
    v.Put(a);
  EXPECT_EQ(1, v.GetCount());
}
TEST(Queue, queue_is_empty)
{
    Queue v(4);
    EXPECT_EQ(1, v.IsEmpty());
}
TEST(Queue, queue_is_not_empty)
{
    Queue v(4);
    Typeelem a("name", 4);
    v.Put(a);
    EXPECT_EQ(0, v.IsEmpty());
}
TEST(Queue, queue_is_full)
{
    Queue v(4);
    Typeelem a("name", 4);
    v.Put(a);
    v.Put(a);
    v.Put(a);
    v.Put(a);
  EXPECT_EQ(1, v.IsFull());
}
TEST(Queue, queue_is_not_full)
{
    Queue v(4);
    Typeelem a("name", 4);
    v.Put(a);
    v.Put(a);
    v.Put(a);
    EXPECT_EQ(0, v.IsFull());
}
TEST(Queue, can_not_get_element_from_empty_queue)
{
    Queue v(4);
    ASSERT_ANY_THROW(v.Get());
}
TEST(Queue, can_get_element)
{
  Queue v1(4);
  Typeelem a("name", 4);
  v1.Put(a);
  Typeelem b;
  b = v1.Get();
  EXPECT_EQ(0,v1.GetCount());
}
TEST(Queue, can_get_element_when_count_equal_one)
{
    Queue A(4);
    Typeelem a("", 1, 1);
        A.Put(a);
        ASSERT_NO_THROW(A.Get());
}
TEST(Queue, can_put_element_when_last_equal_size)
{
    Queue A(4);
    Typeelem a("", 1, 1);
    A.Put(a);
    A.Put(a);
    A.Put(a);
    ASSERT_NO_THROW(A.Put(a));
}
TEST(Queue, can_get_element_when_first_equal_size_minus_one)
{
    Queue A(4);
    Typeelem a("", 1, 1);
    A.Put(a);
    A.Put(a);
    A.Put(a);
    A.Put(a);
    A.Get();
    A.Get();
    A.Get();
    ASSERT_NO_THROW(A.Get());
}

/*
TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v1;
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i;
    }
    EXPECT_EQ(true, v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v1(8);
    TVector<int> v2(21);
    EXPECT_NE(v2.GetSize(), v1.GetSize());
    EXPECT_EQ(true, v1 != v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> v1(8);
    TVector<int> v2(8);
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i + 17;
        v2[i] = i;
    }
    EXPECT_EQ(v1, v2 + 17);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> v1(8);
    TVector<int> v2(8);
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i - 17;
        v2[i] = i;
    }
    EXPECT_EQ(v1, v2 - 17);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> v1(8);
    TVector<int> v2(8);
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i * 17;
        v2[i] = i;
    }
    EXPECT_EQ(v1, v2 * 17);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> v1(56);
    TVector<int> v2(56);
    TVector<int> v3(56);
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i * 19;
        v2[i] = i + 19;
        v3[i]= (i * 19)+(i + 19);
    }
    EXPECT_EQ(v3, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> v1(56);
    TVector<int> v2(34);
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i * 19;
    }
    for (int i = 0; i < v2.GetSize(); i++)
    {
        v2[i] = i + 19;
    }
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> v1(56);
    TVector<int> v2(56);
    TVector<int> v3(56);
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i * 19;
        v2[i] = i + 19;
        v3[i] = (i * 19) - (i + 19);
    }
    EXPECT_EQ(v3, v1 - v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> v1(56);
    TVector<int> v2(34);
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i * 19;
    }
    for (int i = 0; i < v2.GetSize(); i++)
    {
        v2[i] = i + 19;
    }
    ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> v1(56);
    TVector<int> v2(56);
    int s=0;
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i + 4;
        v2[i] = i - 4;
        s+= (i + 4) * (i - 4);
    }
    EXPECT_EQ(s, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> v1(56);
    TVector<int> v2(34);
    for (int i = 0; i < v1.GetSize(); i++)
    {
        v1[i] = i * 19;
    }
    for (int i = 0; i < v2.GetSize(); i++)
    {
        v2[i] = i + 19;
    }
    ASSERT_ANY_THROW(v1 * v2);
}

*/