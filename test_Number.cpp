#include "prog3.h"
#include "prog3.cpp"

#include <gtest/gtest.h>


TEST (constructor, empty){
    Number s;
    ASSERT_EQ(s.getM(),0);
    ASSERT_STREQ(s.getNum(), "0000000000");
    ASSERT_EQ(s.getSize(),11);
}

TEST(set,long_positive){
    Number s;
    s.set(345678911);
ASSERT_EQ(s.getM(),9);
ASSERT_STREQ(s.getNum(), "0345678911");
}
TEST(set,long_negative){
    Number s;
    s.set(-345678911);
ASSERT_EQ(s.getM(),9);
ASSERT_STREQ(s.getNum(), "1345678911");
}
TEST(set,maschar_positive){
    Number s;
    char str[]={"123456"};
    s.set(str);
ASSERT_EQ(s.getM(),6);
ASSERT_STREQ(s.getNum(), "0000123456");
}
TEST(set,maschar_negative){
    Number s;
    char str[]={"-123456"};
    s.set(str);
ASSERT_EQ(s.getM(),6);
ASSERT_STREQ(s.getNum(), "1000123456");
}


TEST(dopcod, number_123456){
    Number s;
    s.set(123456);
    char *check=s.dopcod();
ASSERT_STREQ(check, "0000123456");
delete [] check;
}
TEST(dopcod, number_minus123456){
    Number s;
    s.set(-123456);
    char *check=s.dopcod();
ASSERT_STREQ(check, "1999876544");
delete[] check;
}

TEST(plus, 123456_plus_111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(111111);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "0000234567");
}
TEST(plus, 999999999_plus_999999999){
    Number s;
    char str[]={"999999999"};
    s.set(str);
    Number s2;
    char str2[]={"999999999"};
    s2.set(str2);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "1000000002");
}
TEST(plus, 123456_plus_minus111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(-111111);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "0000012345");
}
TEST(plus, minus123456_plus_minus111111){
    Number s;
    s.set(-123456);
    Number s2;
    s2.set(-111111);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "1000234567");
}

TEST(minus, 123456_minus_111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "0000012345");
}
TEST(minus, 123456_minus_minus111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(-111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "0000234567");
}
TEST(minus, minus123456_minus_minus111111){
    Number s;
    s.set(-123456);
    Number s2;
    s2.set(-111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "1000012345");
}

TEST(decrease, 123456){
Number s;
    s.set(123456);
s.decrease();
ASSERT_STREQ(s.getNum(), "0000012345");
}

TEST(increase, 123456){
Number s;
    s.set(123456);
s.increase();
ASSERT_STREQ(s.getNum(), "0001234560");
}

TEST (_rovno_, 123){
    Number s1;
    Number s2;
    s2.set(123456);
    s1=s2;
    ASSERT_STREQ(s1.getNum(), "0000123456");
    ASSERT_STREQ(s2.getNum(), "0000123456");
}
TEST (_plus_, 123){
    Number s1;
    Number s2;
    s1.set(111);
    s2.set(123456);
    Number s3=s1+s2;
    ASSERT_STREQ(s1.getNum(), "0000000111");
    ASSERT_STREQ(s2.getNum(), "0000123456");
    ASSERT_STREQ(s3.getNum(), "0000123567");
}
TEST (_minus_, 123){
    Number s1;
    Number s2;
    s1.set(111);
    s2.set(123456);
    Number s3=s1-s2;
    ASSERT_STREQ(s1.getNum(), "0000000111");
    ASSERT_STREQ(s2.getNum(), "0000123456");
    ASSERT_STREQ(s3.getNum(), "1000123345");
}