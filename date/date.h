#include <iostream>

#ifndef DATE_H
#define DATE_H

class Date
{
    private:
    int dd_; 
    int mm_; 
    int yy_; 
    public: 
    Date(int dd = 1, int mm = 1, int yy =1971);  

    Date & operator++();
    Date operator++(int);
    operator int() const; 
    friend std::ostream & operator<<(std::ostream & os, const Date & obj);  
    friend bool operator<(const Date &lhs , const Date & rhs);
    friend bool operator==(const Date & lhs, const Date & rhs); 
};

#endif