#pragma once

#include <iostream>
#include <string.h>

class Number
{
private:
    char *num;
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
    ~Number();
    char *dopcod();
  
    void minus(Number *);
    void plus(Number *);
    void increase();
   void decrease();
    int input();
    void print();
};
//int dialog(Number &z);
