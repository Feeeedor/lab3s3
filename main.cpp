#include "prog3.cpp"
#include "prog3.h"
//#include <iostream>
int main()
{
Number z;
char s[5];
std::cin>>s;
z.set(s);
z.print();
    //std::cout<<sizeof(int)<<" "<<sizeof(long);
    /*
    Number z;
    int n;
    std::cin >> n;
    char *s = new char[n + 1];
    s[0]=getchar();
    for (int i = 0; i < n + 1; i++)
        s[i] = getchar();
        /*    std::cout << "n - " << n << "\n";
    for (int i = 0; i < n + 1; i++)
        std::cout <<"i = "<<i<<" s[i] = "<<s[i]<<"\n";
    std::cout << "\n";
    z.set(s, n);
    z.print();*/
}