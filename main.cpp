#include "prog3.cpp"
#include "prog3.h"
//#include <iostream>
int main()
{
Number z;
Number z2;
//char s[5];
//std::cin>>s;
//z.set(s);
long s=-1005;
z.set(s);
long s2=-10000;
z2.set(s2);
//char *q=z2.dopcod();
//for(int i=0;i<z.getSize();i++)
//std::cout<<q[i];
//std::cout<<std::endl;

z.increase();
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