#pragma once
//#include "prog3.cpp"
#include <iostream>
#include <string.h>

class Number
{
private:
    static const int size = 11;
    char num[size];
    int m;

public:
const Number &operator=(const Number &second);
const Number operator+(Number &second);
Number (const Number &q);
const Number operator-(Number &second);
    int getM();
    char *getNum();
    void set(char *);
    void set(long);
    Number();
    char *dopcod();
    int getSize();
    void minus(Number *);
    void plus(Number *);
    void increase();
    void decrease();
    int input();
    void print();
};
int dialog(Number &z);
