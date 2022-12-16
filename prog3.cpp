#include "prog3.h"
void Number::print()
{
    std::cout << "num : ";
    for (int i = 0; i < size - 1; i++)
        std::cout << num[i];
    std::cout << "\n";
    std::cout << "m : " << m << "\n";
}

int Number::getSize()
{
    return size;
}

Number::Number()
{
    for (int i = 0; i < size - 1; i++)
        num[i] = '0';
    m = 0;
    num[size - 1] = '\0';
}

void Number::set(char *s)
{
    if (s[0] == '-')
    {
        num[0] = '1';
        for (int i = 1, j = 1; i < size - 1; i++)
        {
            if (i < size - (int)strlen(s))
                num[i] = '0';
            else
            {
                num[i] = s[j];
                j++;
            }
        }
        m = strlen(s) - 1;
    }
    else
    {

        num[0] = '0';
        for (int i = 0, j = 0; i < size - 1; i++)
        {
            if (i < size - 1 - (int)strlen(s))
                num[i] = '0';
            else
            {
                num[i] = s[j];
                j++;
            }
        }
        m = strlen(s);
    }
}

void Number::set(long s)
{
    if (s < 0)
    {
        num[0] = '1';
        s = s * (-1);
    }
    else
    {
        num[0] = '0';
    }
    for (int i = this->getSize() - 2; i > 0; i--)
    {
        if (s)
        {
            int j = s % 10;
            num[i] = (char)j + 48;
            m++;
            s = s / 10;
        }
        else
        {
            num[i] = '0';
        }
    }
}

char *Number::dopcod()
{
    char *num2;
    num2 = new char[size]();
    if (num[0] == '0')
        for (int i = 0; i < size; i++)
            num2[i] = num[i];
    else
    {
        num2[0] = '1';
        int transfer = 1;
        for (int i = size - 2; i > 0; i--)
        {
            int j = num[i] - '0';
            j = 9 - j + transfer;
            transfer = j / 10;
            j = j % 10;
            num2[i] = j + '0';
        }
        num2[size - 1] = '\0';
    }
    return num2;
}

void Number::plus(Number *z)
{
    char *number1 = this->dopcod();
    char *number2 = z->dopcod();
    int transfer = 0;
    for (int i = size - 2; i >= 0; i--)
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
        for (int i = size - 2; i > 0; i--)
        {
            int j = number1[i] - '0';
            j = 9 - j + transfer;
            transfer = j / 10;
            j = j % 10;
            number1[i] = j + '0';
        }
    }

    for (int i = 0; i < size - 1; i++)
        num[i] = number1[i];
    c = 0;
    for (int i = 1; i < size - 1; i++)
        if (num[i] != '0')
        {
            c = i;
            break;
        }
    if (c)
        m = size - 1 - c;
    else
    {
        m = 0;
    }
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
    for (int i = size - 2; i > 1; i--)
    {
        num[i] = num[i - 1];
    }
    num[1] = '0';
}

void Number::increase()
{
    for (int i = 1; i < size - 2; i++)
    {
        num[i] = num[i + 1];
    }
    num[size - 2] = '0';
}

int Number::input()
{
    char *newnum;
    newnum = new char[this->getSize()]();
    std::cin.ignore();
    std::cin.getline(newnum, this->getSize(), '\n');

    this->set(newnum);

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
            for (int i = 0; i < z.getSize() - 1; i++)
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

for(int i=0;i<size;i++)
num[i]=second.num[i];
m=second.m;
    return *this;
}
const Number Number::operator+(Number &second){
Number newNumber;
char *number1 = this->dopcod();
    char *number2 =second.dopcod();
    int transfer = 0;
    for (int i = size - 2; i >= 0; i--)
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
        for (int i = size - 2; i > 0; i--)
        {
            int j = number1[i] - '0';
            j = 9 - j + transfer;
            transfer = j / 10;
            j = j % 10;
            number1[i] = j + '0';
        }
    }

    for (int i = 0; i < size - 1; i++)
        newNumber.num[i] = number1[i];
    c = 0;
    for (int i = 1; i < size - 1; i++)
        if (newNumber.num[i] != '0')
        {
            c = i;
            break;
        }
    if (c)
        newNumber.m = size - 1 - c;
    else
    {
        newNumber.m = 0;
    }
    delete[] number1;
    delete[] number2;
    return newNumber;
}
Number::Number(const Number &q)
{
    for (int i = 0; i < size ; i++)
        num[i] = q.num[i];
    m = q.m;
    
}
const Number Number::operator-(Number &second){
Number newNumber;
int j = num[0] - '0';
    j = 1 - j;
    num[0] = j + '0';
    newNumber=*this+second;
    if (newNumber.m)
    {
        j = newNumber.num[0] - '0';
        j = 1 - j;
        newNumber.num[0] = j + '0';
    }
    j = num[0] - '0';
    j = 1 - j;
    num[0] = j + '0';
    return newNumber;
}