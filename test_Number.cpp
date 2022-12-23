#include "prog3.h"
#include "prog3.cpp"

#include <gtest/gtest.h>


TEST (constructor, empty){
    Number s;
    ASSERT_EQ(s.getM(),1);
    ASSERT_STREQ(s.getNum(), "00");
}

TEST(set,long_positive){
    Number s;
    s.set(11);
ASSERT_EQ(s.getM(),2);
ASSERT_STREQ(s.getNum(), "011");
}
TEST(set,long_negative){
    Number s;
    s.set(-11);
ASSERT_EQ(s.getM(),2);
ASSERT_STREQ(s.getNum(), "111");
}
TEST(set,maschar_positive){
    Number s;
    char str[]={"12"};
    s.set(str);
ASSERT_EQ(s.getM(),2);
ASSERT_STREQ(s.getNum(), "012");
}
TEST(set,maschar_negative){
    Number s;
    char str[]={"-12"};
    s.set(str);
ASSERT_EQ(s.getM(),2);
ASSERT_STREQ(s.getNum(), "112");
}

TEST(dopcod, number_12){
    Number s;
    s.set(12);
    char *check=s.dopcod();
ASSERT_STREQ(check, "012");
delete [] check;
}
TEST(dopcod, number_minus11){
    Number s;
    s.set(-11);
    char *check=s.dopcod();
ASSERT_STREQ(check, "189");
delete[] check;
}

TEST(plus, 12_plus_11){
    Number s;
    s.set(12);
    Number s2;
    s2.set(11);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "023");
ASSERT_EQ(s.getM(),2);
}
TEST(plus, 99_plus_9){
    Number s;
    char str[]={"9"};
    s.set(str);
    Number s2;
    char str2[]={"9"};
    s2.set(str2);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "018");
}
TEST(plus, 12_plus_minus11){
    Number s;
    s.set(12);
    Number s2;
    s2.set(-11);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "01");
}
TEST(plus, minus12_plus_minus11){
    Number s;
    s.set(-12);
    Number s2;
    s2.set(-11);
    s.plus(&s2);
ASSERT_STREQ(s.getNum(), "123");
}

TEST(minus, 123456_minus_111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "012345");
}
TEST(minus, 123456_minus_minus111111){
    Number s;
    s.set(123456);
    Number s2;
    s2.set(-111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "0234567");
}
TEST(minus, minus123456_minus_minus111111){
    Number s;
    s.set(-123456);
    Number s2;
    s2.set(-111111);
    s.minus(&s2);
ASSERT_STREQ(s.getNum(), "112345");

}

TEST(decrease, 123456){
Number s;
    s.set(123456);
s.decrease();
ASSERT_STREQ(s.getNum(), "012345");
}

TEST(increase, 123456){
Number s;
    s.set(123456);
s.increase();
ASSERT_STREQ(s.getNum(), "01234560");
}

TEST (_rovno_, 123){
    Number s1;
    Number s2;
    s2.set(123456);
    s1=s2;
    ASSERT_STREQ(s1.getNum(), "0123456");
    ASSERT_STREQ(s2.getNum(), "0123456");
}
TEST (_plus_, 123){
    Number s1;
    Number s2;
    s1.set(111);
    s2.set(123456);
    Number s3=s1+s2;
    ASSERT_STREQ(s1.getNum(), "0111");
    ASSERT_STREQ(s2.getNum(), "0123456");
    ASSERT_STREQ(s3.getNum(), "0123567");
}
TEST (_minus_, 123){
    Number s1;
    Number s2;
    s1.set(111);
    s2.set(123456);
    Number s3=s1-s2;
    ASSERT_STREQ(s1.getNum(), "0111");
    ASSERT_STREQ(s2.getNum(), "0123456");
    ASSERT_STREQ(s3.getNum(), "1123345");
}