//#include <iostream>
#include "prog3.h"
void Number::print()
{
    std::cout << "number "<<number<<"\n";
    std::cout<<"num ";
    for (int i = 0; i < this->getSize(); i++)
        std::cout << num[i];
    std::cout << "\n";
    std::cout <<"m "<< m << "\n";
};

int Number::getSize(){
return Number::size;
}
/*
 Number::Number(){
number=0;
for(int i=0;i<size;i++)
num[i]=NULL;
}*/

int Number::set(char*s)
{
    //std::cout<<strlen(s)<<"\n";
    if (strlen(s) < 10 || (strlen(s)==10 && s[0]=='-'))
    {
        std::cout<<"KKK\n";
        number = atol(s);
        m = -1;
        for (int i = 0; i < this->getSize(); i++)
            num[i] = '0';
    }
    else
    {
        number = -1;
        std::cout << "JJJ\n";
        if (s[0] == '-')
        {
            num[0] = '1';

            for (int i = 0, j = 1; i < this->getSize(); i++){
                std::cout<<"i = "<<i<<" j = "<<j<<"\n";
                           if (i < this->getSize() - strlen(s))
                    num[i] = '0';

                else
                {
                    num[i] = s[j];
                    j++;
                }}
            m = strlen(s) - 1;
        }
        else
        {
            num[0] = '0';
             
            for (int i = 0, j = 0; i < this->getSize(); i++){
                std::cout<<"i = "<<i<<" j = "<<j<<"\n";
                if (i < this->getSize() - 1 - strlen(s))
                    num[i] = '0';
                else
                {
                    num[i] = s[j];
                    j++;
                }}
        }
        m = strlen(s);
    }

    return 0;
    }

/*int Number::set(char *s, int mnew)
{
    if (mnew >= 10 || mnew < 0)
    {
        std::cout << "m не по размерам\n";
        return 1;
    }

    if (sizeof(s) / sizeof(char) != 2 * (mnew + 1))
    {
        std::cout << "m и num не совпали\n";
        return 1;
    }
    num[0] = s[0];
    for (int i = 1; i < 10 - mnew; i++)
        num[i] = '0';

    for (int i = 10 - 1 - mnew, j = 1; i < 10; j++, i++)
        num[i] = s[j];
    m = mnew;
    return 0;
}*/
