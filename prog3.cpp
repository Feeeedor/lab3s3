//#include <iostream>
#include "prog3.h"
void Number::print()
{
    std::cout<<"num ";
    for (int i = 0; i < this->getSize(); i++)
    std::cout<<num[i];
       // std::cout <<"i = "<<i<< "num[i] = "<< num[i]<<"\n";
    std::cout << "\n";
    std::cout <<"m "<< m << "\n";
};

int Number::getSize(){
return Number::size;
}

 Number::Number()
 {
for(int i=0;i<size;i++)
num[i]='0';
m=0;
}

int Number::set(char*s)
{
    //std::cout<<strlen(s)<<"\n";   
        if (s[0] == '-')
        {
            num[0] = '1';
            for (int i = 0, j = 1; i < this->getSize(); i++){
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
                if (i < this->getSize() - 1 - strlen(s))
                    num[i] = '0';
                else
                {
                    num[i] = s[j];
                    j++;
                }}
        }
        m = strlen(s);
        return 0;
    }

    
int Number::set(long s)
{
    //std::cout<<strlen(s)<<"\n";
    
        if (s<0)
        {
            num[0] = '1';
s=s*(-1);
        }
        else
        {
            num[0] = '0';                       
            }
        
        for (int i = this->getSize()-1; i >0;i-- ){
            
                if(s!=0){
                int j=s%10;
                
                      num[i]=j+'0' ;
                     
                      m++;    
                      s=s/10;  
                       }  
                         else
                         num[i]='0'  ;
                         
                           
            }

    return 0;
    }

char *Number::dopcod(){
 char *num2;
 num2=new char[this->getSize()]();
if(num[0]=='0')
for(int i=0;i<this->getSize();i++)
num2[i]=num[i];
else{
    num2[0]='1';
    int transfer =1;
for(int i=this->getSize()-1;i>0;i--){//
int j=num[i]-'0';
j=9-j+transfer;
transfer=j/10;
j=j%10;
num2[i]=j+'0';}
}/*
int c=this->getSize()-1;
while(c!=0){
int j=num2[c]-'0';
j++;
if(j!=10){
num2[c]=j+'0';
break;}
else{
num2[c]='0';
c--;}
}*/
return num2;
}

int Number::plus(Number *z){
    if(this->getSize()<z->getSize()){
    std::cout<<"Error\n";
    return 1;}
char *number1=this->dopcod();
char *number2=z->dopcod();
int transfer=0;
//std::cout<<"QQQ\n";
for(int i=this->getSize()-1;i>=0;i--){
int j1=number1[i]-'0';
int j2=number2[i]-'0';
j1=j1+j2+transfer;
transfer=j1/10;
j1=j1%10;
number1[i]=j1+'0';
}



int c=number1[0]-'0';
c=c%2;
number1[0]=c+'0';
if(number1[0]=='1'){
transfer=1;
for(int i=this->getSize()-1;i>0;i--){
int j=number1[i]-'0';
j=9-j+transfer;
transfer=j/10;
j=j%10;
number1[i]=j+'0';}
}

for(int i=0;i<this->getSize();i++)
num[i]=number1[i];
c=0;
for(int i=1;i<this->getSize();i++)
if(num[i]!='0'){
    c=i;
break;}
if(c)
m=this->getSize()-c;
else
m=0;
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
