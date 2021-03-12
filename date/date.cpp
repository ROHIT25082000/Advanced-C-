#include <iostream>
#include "date.h"

Date::Date(int dd, int mm ,int yy)
:dd_(dd),mm_(mm),yy_(yy){
}

std::ostream & operator<<(std::ostream & os , const Date & obj)
{
    os << obj.dd_ << "-" << obj.mm_ << "-" << obj.yy_; 
    return os; 
}

bool operator<(const Date & lhs, const Date & rhs)
{
    if(lhs.yy_ < rhs.yy_)
        return true; 
    else if ((lhs.yy_ == rhs.yy_) && (lhs.mm_ < rhs.mm_))
        return true; 
    else if((lhs.yy_ == rhs.yy_) && (lhs.mm_ == rhs.mm_) && (lhs.dd_ < lhs.dd_))
        return true;
    else 
        return false;
}

bool operator==(const Date & lhs, const Date & rhs)
{
    return lhs.dd_ == rhs.dd_ && lhs.mm_ == rhs.mm_ && lhs.yy_ == rhs.yy_;  
}

Date & Date::operator++()
{
    ++this->dd_; 
    return *this;
}

Date Date::operator++(int)
{
    Date temp{*this};
    ++(*this); 
    return temp;
}

Date::operator int()const {
    return this->dd_;
}


