#include "prog3.h"
#include "prog3.cpp"

#include <gtest/gtest.h>


TEST (constructor, empty){
    Number s;
    ASSERT_EQ(s.getM(),0);
    ASSERT_STREQ(s.getNum(), "00000000000000000000");
    ASSERT_EQ(s.getSize(),21);
}

TEST(set,long_positive){
    Number s;
    s.set(12345678911);
ASSERT_EQ(s.getM(),11);
ASSERT_STREQ(s.getNum(), "00000000012345678911");
}
TEST(set,long_negative){
    Number s;
    s.set(-12345678911);
ASSERT_EQ(s.getM(),11);
ASSERT_STREQ(s.getNum(), "10000000012345678911");
}
TEST(set,maschar_positive){
    Number s;
    char str[]={"123456"};
    s.set(str);
ASSERT_EQ(s.getM(),6);
ASSERT_STREQ(s.getNum(), "00000000000000123456");
}
TEST(set,maschar_negative){
    Number s;
    char str[]={"-123456"};
    s.set(str);
ASSERT_EQ(s.getM(),6);
ASSERT_STREQ(s.getNum(), "10000000000000123456");
}


TEST(dopcod, number_123456){
    Number s;
    s.set(123456);
    char *check=s.dopcod();
ASSERT_STREQ(check, "00000000000000123456");
delete [] check;
}
TEST(dopcod, number_minus123456){
    Number s;
    s.set(-123456);
    char *check=s.dopcod();
ASSERT_STREQ(check, "19999999999999876544");
delete[] check;
}

TEST(plus, 123456_plus_111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(111111);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "00000000000000234567");
}
TEST(plus, 123456_plus_minus111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(-111111);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "00000000000000012345");
}
TEST(plus, minus123456_plus_minus111111){
    Number s;
    s.set(-123456);
    Number s2;
    s2.set(-111111);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "10000000000000234567");
}

TEST(minus, 123456_minus_111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "00000000000000012345");
}
TEST(minus, 123456_minus_minus111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(-111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "00000000000000234567");
}
TEST(minus, minus123456_minus_minus111111){
    Number s;
    s.set(-123456);
    Number s2;
    s2.set(-111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "10000000000000012345");
}

TEST(decrease, 123456){
Number s;
    s.set(123456);
s.decrease();
ASSERT_STREQ(s.getNum(), "00000000000000012345");
}

TEST(increase, 123456){
Number s;
    s.set(123456);
s.increase();
ASSERT_STREQ(s.getNum(), "00000000000001234560");
}

