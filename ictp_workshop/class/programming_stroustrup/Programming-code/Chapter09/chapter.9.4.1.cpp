#include<iostream>
using std::cout;
using std::endl;

//
// This is example code from Chapter 9.4.1 "Struct and functions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// simple Date (too simple?):
struct Date {
    int y; // year
    int m; // month in year
    int d; // day of month
};

//------------------------------------------------------------------------------

// helper functions:

void init_day(Date& dd, int y, int m, int d)
{
    if (m <13 && m > 0)
      dd.m = m;
    else{
      std::cout << "Invalid mounth\n";
      std::cout<< m<<endl;
      exit(0) ;
    }
    if (d<31 && d >-1)
      dd.d = d;
    else{
      std::cout << "Invalid day\n";
      std::cout<< d<<endl;
      exit(0) ;
    }
    if (y%1000 )
      dd.y = y;
    else{
      std::cout << "Invalid year\n";
      std::cout<< y<<endl;
      exit(0) ;
    }
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
}

//------------------------------------------------------------------------------

void add_day(Date& dd, int n)
{
    // increase dd by n days
}

//------------------------------------------------------------------------------

void f()
{
    Date today;
    init_day(today, 12, 24, 2005); // oops! (no day 2005 in year 12)
    add_day(today,1);
}

//------------------------------------------------------------------------------

int main()
{
    Date today; // a Date variable (a named object)

    // set today to December 24, 2005
    today.y = 2005;
    today.m = 24;
    today.d = 12;

    Date x;
    x.y = -3;
    x.m = 13;
    x.d = 32;

    // Was year 2000 a leap year? Are you sure?
    Date y;
    y.y = 2000;
    y.m = 2;
    y.d = 29;

    init_day(y, 2000, 1, 1);
    add_day(y, 28);
    return 0;
}

//------------------------------------------------------------------------------
