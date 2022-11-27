#pragma once
//#include "prog3.cpp"
#include <iostream>
#include <string.h>
class Number{
    private:
    static const int size = 30;//разобраться
        char num[size];
        int m;
        long int number; 
    public:
    int set(char*);
//Number();

int getSize();
void getnum();
int dopcod();
int plus();
int increase();
int decrease();

    void print();
};

int Number_set();