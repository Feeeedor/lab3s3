#pragma once
//#include "prog3.cpp"
#include <iostream>
#include <string.h>
class Number{
    private:
    static const int size = 30;//разобраться
        char num[size];
        int m;
    public:
    int set(char*);
    int set(long );
Number();
char* dopcod();
int getSize();
void getnum();

int plus(Number *);
int increase();
int decrease();

    void print();
};

int Number_set();