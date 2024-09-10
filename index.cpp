#include <iostream>
using namespace std;

struct Date
{
    unsigned int d;
    unsigned int m;
    unsigned int y;
};

ostream &operator<<(ostream &out, const Date &a)
{
    out << a.d << "/" << a.m << "/" << a.y << endl;// da nang hoa cout d/m/y
    return out;
}

istream &operator>>(istream &in, Date &a)// da nang hoa cin d/m/y
{
    in >> a.d >> a.m >> a.y;
    return in;
}

int is_LeapYear(Date &a){
    return (((a.y % 4)==0 && (a.y%100)) || (a.y%400)==0);
}

int checkDate(Date &a)
{

    if (a.m < 1 || a.m > 12)
        return 0;

    switch (a.m)
    {
    case 2:
        if (!is_LeapYear(a))
        {
            if (a.d < 1 || a.d > 28)
                return 0;
        }
        else
        {
            if (a.d < 1 || a.d > 29)
                return 0;
            break;
        }
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (a.d < 1 || a.d > 31)
            return 0;
        break;
    default:
        if (a.d < 1 || a.d > 30)
            return 0;
        break;
    }
    return 1;
}
//++a
Date operator++(Date &a)
{
    if (!checkDate(a))
        exit(-1);
    switch (a.m)
    {
    case 2:
        if (a.d == 28 && !is_LeapYear(a)|| a.d == 29 )
        {
            a.d = 1;
            a.m++;
        }
        else
            a.d++;
        break;
    case 12:
        if (a.d == 31)
        {
            a.d = 1;
            a.m = 1;
            a.y++;
        }
        else
            a.d++;
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (a.d == 31)
        {
            a.d = 1;
            a.m++;
        }
        else
            a.d++;
        break;
    default:
        if (a.d == 30)
        {
            a.d = 1;
            a.m++;
        }
        else
            a.d++;
        break;
    }
    return a;
}
// a++
Date operator++(Date &a, int)
{
    if (!checkDate(a))
        exit(-1);
    Date b = a;
    ++a;
    return b;
}
//--a
Date operator--(Date &a)
{
    if (!checkDate(a))
        exit(-1);
    switch (a.m)
    {
    case 3:
        if (a.d == 1)
        {
            if (!is_LeapYear(a))
                a.d = 28;
            else
                a.d = 29;
            a.m--;
        }
        else
            a.d--;
        break;
    case 1:
        if (a.d == 1)
        {
            a.d = 31;
            a.m = 12;
            a.y--;
        }
        else
            a.d--;
        break;
    case 5:
    case 7:
    case 10:
    case 12:
        if (a.d == 1)
        {
            a.d = 30;
            a.m--;
        }
        else
            a.d--;
        break;
    default:
        if (a.d == 1)
        {
            a.d = 31;
            a.m--;
        }
        else
            a.d--;
        break;
    }
    return a;
}
// a--
Date operator--(Date &a, int)
{
    if (!checkDate(a))
        exit(-1);
    Date b = a;
    --a;
    return b;
}

int main()
{
    Date a;
    cin >> a;

    do
    {
        Date b;
        b = ++a;
        cout << "++a\n"
             << b << a;
        b = a++;
        cout << "a++\n"
             << b << a;
        Date c;
        c = --a;
        cout << "--a\n"
             << c << a;
        c = a--;
        cout << "a--\n"
             << c << a;
        getchar();
        getchar();
        system("cls");
        cin >> a;
    } while (a.d);

    return 0;
}