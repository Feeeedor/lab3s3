#include "prog3.h"
void Number::print()
{
    std::cout << "num : ";
    for (int i = 0; i < m+1; i++)
        std::cout << num[i];
    std::cout << "\n";
    std::cout << "m : " << m << "\n";
}

Number::Number()
{
   num=new char[3];
   num[0]='0';
   num[1]='0';
   num[2]='\0';
    m = 1;
    
}
Number::~Number()
{
   delete []num;
    
}

void Number::set(char *s)
{
   char *str;
    if (s[0] == '-')
    {
        m = strlen(s) - 1;
        str=new char[m+1]();
        str[0] = '1';
        for (int i = 1; i <= m; i++)
        
                str[i] = s[i];
    }
    else
    {
       
m = strlen(s);

str=new char[m+1]();
        str[0] = '0';
    
        for (int i = 1, j=0; j < m; j++,i++)
                str[i] = s[j];
    }
    delete []num;
   
    num=new char[m+2]();
    
    for(int i=0;i<m+1;i++)
    num[i]=str[i];
   
    delete []str;
    num[m+1]='\0';
   
}

void Number::set(long s)
{
    char *str;
    long n=s;
    m=0;
    while(n!=0){
        m++;
        n=n/10;
    }

str = new char[m+1]();

    if (s < 0)
    {
        str[0] = '1';
        s = s * (-1);
    }
    else
    {
        str[0] = '0';
    }
    for (int i = m ; i > 0; i--)
    {
                    int j = s % 10;
            str[i] = (char)j + 48;
            s = s / 10;
    }
delete []num;
 num=new char[m+2]();
    for(int i=0;i<m+1;i++)
    num[i]=str[i];
    delete []str;
    num[m+1]='\0';
}

char *Number::dopcod()
{
    char *num2;

   
    num2 = new char[strlen(num)+1]();
    if (num[0] == '0'){
        for (int i = 0; i < (int)strlen(num); i++){
            num2[i] = num[i];}
            num2[strlen(num)]='\0';}
    else
    {
        num2[0] = '1';
        int transfer = 1;
        for (int i = (int)strlen(num)-1; i > 0; i--)
        {
            int j = num[i] - '0';
            j = 9 - j + transfer;
            transfer = j / 10;
            j = j % 10;
            num2[i] = j + '0';
        }
        num2[strlen(num)] = '\0';
    }
    return num2;
}

void Number::plus(Number *z)
{
    Number x1;
    Number x2;
    delete []x1.num;
    delete []x2.num;
    
    int x = std::max(m, z->m) + 3;
    char *str1;
    char *str2;
    
    str1 = new char[x];
    
    str2 = new char[x];
    
    str1[0] = num[0];
    for (int i = 1; i < x - m -1; i++)
        str1[i] = '0';
     
    for (int i = x - m -1, j=1; i < x;j++, i++)
        str1[i] = num[j];

    str2[0] = z->num[0];
      
    for (int i = 1; i < x - z->m-1 ; i++)
        str2[i] = '0';
         
    for (int i = x - z->m -1, j=1; i < x; j++,i++)
        str2[i] = z->num[j];
        
    x1.num = new char[x];
    x2.num = new char[x];
    
    for (int i = 0; i < x; i++){
        x1.num[i] = str1[i];
        x2.num[i] = str2[i];}
        
    x1.m = m;
    x2.m = z->m;
  delete []str1;
    delete []str2;
    char *number1 = x1.dopcod();
    char *number2 = x2.dopcod();


    int transfer = 0;
    for (int i = x - 2; i >= 0; i--)
    {
        int j1 = number1[i] - '0';
        int j2 = number2[i] - '0';
        j1 = j1 + j2 + transfer;
        transfer = j1 / 10;
        j1 = j1 % 10;
        number1[i] = j1 + '0';
    }
    int c = number1[0] - '0';
    c = c % 2;

    number1[0] = c + '0';
    
    
    if (number1[0] == '1')
    {
        transfer = 1;
        for (int i = x - 2; i > 0; i--)
        {
            int j = number1[i] - '0';
            j = 9 - j + transfer;
            transfer = j / 10;
            j = j % 10;
            number1[i] = j + '0';
        }
    }
    
    delete []num;
      
      
    int ost = 0;
    for (int i = 1; i < x - 1; i++)
    {
        if (number1[i] != '0')
            break;
        ost++;
    }
    
    num = new char[x - ost];
    num[0] = number1[0];

    for (int i = ost+1, j = 1; i < x-1;j++, i++){
   
        num[j] = number1[i];
        }
    num[x-ost -1]='\0';

    m = x - ost-2;

    delete[] number1;
    delete[] number2;
}

void Number::minus(Number *z)
{
    int j = num[0] - '0';
    j = 1 - j;
    num[0] = j + '0';
    this->plus(z);
    if (m)
    {
        j = num[0] - '0';
        j = 1 - j;
        num[0] = j + '0';
    }
}

void Number::decrease()
{
    char *str;
    str = new char[m+1];
    for (int i = 0; i <m; i++){
        str[i] = num[i];
    }
    str[m]='\0';
    delete []num;
    num=new char[m+1];
    for(int i=0;i<m;i++)
    num[i]=str[i];
    num[m]='\0';
    m--;
delete []str;
}

void Number::increase()
{
char *str;
    str = new char[m+3];
for (int i = 0; i <m+1; i++){
        str[i] = num[i];
    }
    
    str[m+1]='0';
    str[m+2]='\0';
    
    delete []num;
    num = new char[m+3];
    for(int i=0;i<m+2;i++)
    num[i]=str[i];
    num[m+2]='\0';
    m++;
    delete []str;
}

int Number::input()
{
    char *newnumx;
    newnumx = new char[20]();
    std::cin.ignore();
    std::cin.getline(newnumx,20,'\n');
    m=0;
    for(int i=0;i<20;i++){
if(newnumx[i]=='\0')
break;
m++;}
char *newnum;

newnum=new char[m+1];
for(int i=0;i<m;i++){
newnum[i]=newnumx[i];}
newnum[m]='\0';
    this->set(newnum);

   delete[] newnumx;
   delete[] newnum;
    return 0;
}



int Number::getM()
{
    return m;
}
char *Number::getNum()
{
    return num;
}

int dialog(Number &z)
{
    std::cout << std::endl;
    std::string words[] = {"0.Выход", "1.input", "2.dopcod", "3.plus",
                           "4.minus", "5.decrease",
                           "6.increase", "7.вывод"};
    int m;
    int N = 8;
    do
    {
        for (int i = 0; i < N; i++)
            std::cout << words[i] << std::endl;
        printf("выбор: --> ");
        std::cin >> m;
        switch (m)
        {
        case 1:

            z.input();

            break;
        case 2:
        {
            char *dop = z.dopcod();
            for (int i = 0; i < (int)strlen(dop); i++)
                std::cout << dop[i];
            std::cout << "\n";
            delete[] dop;
            break;
        }
        case 3:
        {
            Number z2;
            z2.input();
            z.plus(&z2);
            break;
        }
        case 4:
        {
            Number z2;
            z2.input();
            z.minus(&z2);
            break;
        }
        case 5:
            z.decrease();
            break;
        case 6:
            z.increase();
            break;
        case 7:
            z.print();
            break;

        case 0:
            return 1;
        default:
            std::cout << "Должно быть введено значение от 0 до 7" << std::endl;
            break;
        }
    } while (1);
    return 1;
}
const Number &Number::operator=(const Number &second){
delete []num;
num = new char[second.m+2];
for(int i=0;i<second.m+2;i++)
num[i]=second.num[i];
m=second.m;
    return *this;
}
const Number Number::operator+(Number &second){
Number newNumber;
newNumber.plus(this);
newNumber.plus(&second);
    
    return newNumber;
}
Number::Number(const Number &q)
{
    num=new char[q.m+2];
    for (int i = 0; i < q.m+2 ; i++)
        num[i] = q.num[i];
    m = q.m;
    
}
const Number Number::operator-(Number &second){
Number newNumber;
newNumber.plus(this);
newNumber.minus(&second);
    return newNumber;
}