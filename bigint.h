/*
========================================================================

INITIALIZATION :

    string s = "12345";
    bigint b(s);

=========================================================================

METHODS:

    string print()    =>    Returns the value stored in bigint object
    void reverse()    =>    Reverses the bigint object 
    string absolute() =>    Returns the absolute value of bigint object   

=========================================================================

OVERLOADED OPERATORS:

    ==        =>    Compares equality of two bigint objects
    <         =>    Checks if the given bigint value is less than another bigint value
    >         =>    Checks if the given bigint value is greater than or equal to another bigint value
    <=        =>    Checks if the given bigint value is less than or equal to another bigint value
    >=        =>    Checks if the given bigint value is greater than another bigint value
    +         =>    Addition of two bigint objects
    -         =>    Subtraction of two bigint objects

=========================================================================
*/

#include<iostream>
#include "pythoniser.h"

class bigint
{

public:
    std::string value;
    int sign;

    bigint()
    {
        value = "";
        sign = 1;
    }

    bigint(std::string s)
    {
        value = s;
        sign = 1;
        if(s[0]=='-')
        {
            value = value.substr(1);
            sign = 0;
        }
    }
    
    std::string absolute()
    {
        return value;
    }

    // Returns string representing value of bigint
    std::string print()
    {
        if(value == "")
            return "0";
        if(sign == 0)
            return "-" + value;
        return value;
    }

    // Reverses the bigint
    void reverse()
    {
        long long l = value.length();
        for(long long i=0; i<(l/2); i++)
        {
            char temp = value[i];
            value[i] = value[l-1-i];
            value[l-1-i] = temp;
        }
    }

    // Checks equality between two bigint 
    bool operator == (bigint b)
    {
        if((sign == b.sign)&&( value == b.value))
            return true;
        return false;    
    }

    // Checks if given bigint is larger then another bigint
    bool operator > (bigint b)
    {
        if(sign == b.sign)
        {
            if(sign == 1)
            {
                if(value.length() > b.value.length())
                {
                    return true;
                }
                else if(value.length() < b.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < value.length())
                    {
                        if(value[i] > b.value[i])
                            return true;
                        else if(value[i] < b.value[i])
                            return false;
                        else
                            i++;
                    }
                    return false;
                }
            }
            else 
            {
                if(value.length() < b.value.length())
                {
                    return true;
                }
                else if(value.length() > b.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < value.length())
                    {
                        if(value[i] < b.value[i])
                            return true;
                        else if(value[i] > b.value[i])
                            return false;
                        else
                            i++;
                    }
                    return false;
                }
            }
        }
        else
        {
            if(sign == 0)
                return false;
            return true;    
        }
        
    }

    // Checks is given bigint is smaller than given bigint
    bool operator < (bigint b)
    {
        if(sign == b.sign)
        {
            if(sign == 1)
            {
                if(value.length() < b.value.length())
                {
                    return true;
                }
                else if(value.length() > b.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < value.length())
                    {
                        if(value[i] < b.value[i])
                            return true;
                        else if(value[i] > b.value[i])
                            return false;
                        else
                            i++;
                    }
                    return false;
                }
            }
            else 
            {
                if(value.length() > b.value.length())
                {
                    return true;
                }
                else if(value.length() < b.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < value.length())
                    {
                        if(value[i] > b.value[i])
                            return true;
                        else if(value[i] < b.value[i])
                            return false;
                        else
                            i++;
                    }
                    return false;
                }
            }
        }
        else
        {
            if(sign == 1)
                return false;
            return true;    
        }
    }

    // Checks if bigint if greater than or equal to given bigint
    bool operator >= (bigint b)
    {
        if(sign == b.sign)
        {
            if(sign == 1)
            {
                if(value.length() > b.value.length())
                {
                    return true;
                }
                else if(value.length() < b.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < value.length())
                    {
                        if(value[i] > b.value[i])
                            return true;
                        else if(value[i] < b.value[i])
                            return false;
                        else
                            i++;
                    }
                    return true;
                }
            }
            else 
            {
                if(value.length() < b.value.length())
                {
                    return true;
                }
                else if(value.length() > b.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < value.length())
                    {
                        if(value[i] < b.value[i])
                            return true;
                        else if(value[i] > b.value[i])
                            return false;
                        else
                            i++;
                    }
                    return true;
                }
            }
        }
        else
        {
            if(sign == 0)
                return false;
            return true;    
        }
        
    }

    // Checks if bigint is less than or equal to given bigint
    bool operator <= (bigint b)
    {
        if(sign == b.sign)
        {
            if(sign == 1)
            {
                if(value.length() < b.value.length())
                {
                    return true;
                }
                else if(value.length() > b.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < value.length())
                    {
                        if(value[i] < b.value[i])
                            return true;
                        else if(value[i] > b.value[i])
                            return false;
                        else
                            i++;
                    }
                    return true;
                }
            }
            else 
            {
                if(value.length() > b.value.length())
                {
                    return true;
                }
                else if(value.length() < b.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < value.length())
                    {
                        if(value[i] > b.value[i])
                            return true;
                        else if(value[i] < b.value[i])
                            return false;
                        else
                            i++;
                    }
                    return true;
                }
            }
        }
        else
        {
            if(sign == 1)
                return false;
            return true;    
        }
    }

    // Returns the sum of two bigint
    bigint operator + (bigint b)
    {
        if(sign != b.sign)
        {
            if(sign == 0)
                return b - *this;
            return *this - b;   
        }
        int carry = 0;
        bigint sum("");
        long long l1 = value.length();
        long long l2 = b.value.length();
        long long p1 = l1-1;
        long long p2 = l2-1;
        long long i = 0;

        for(long long i=0; i<((l1<l2)?l1:l2); i++)
        {
            int nval = value[p1--]-48 + b.value[p2--]-48 + carry;
            carry = nval/10;
            sum.value = char((nval % 10)+48) + sum.value;
        }

        while(p1 >= 0)
        {
            int nval = value[p1--]-48 + carry;
            carry = nval/10;
            sum.value = char((nval % 10) + 48) + sum.value;
        }

        while(p2 >= 0)
        {
            int nval = b.value[p2--]-48 + carry;
            carry = nval/10;
            sum.value = char((nval % 10) + 48) + sum.value;
        }

        if(carry>0)
            sum.value = char((carry) + 48) + sum.value;

        sum.sign = sign;
        sum.value = ltrim(sum.value, '0');

        return sum;
    }

    // Returns the diference of two bigint
    bigint operator - (bigint b)
    {
        bigint larger, smaller, result;
        int borrow = 0;
        larger = *this;
        smaller = b;
        if (*this < b)
        {
            result.sign = 0;
            larger = b;
            smaller = *this;
        }

        long long l1 = larger.value.length();
        long long l2 = smaller.value.length();

        long long pi = l1-1;

        for(long long i=0; i<l2; i++)
        {
            int v1 = larger.value[pi--]-48 - borrow;
            int v2 = smaller.value[l2-i-1]-48;
            if(v1 < v2)
            {
                v1 = v1+10;
                borrow = 1;
            }
            else
                borrow = 0;
            result.value = char((v1-v2) + 48) + result.value; 
        }

        for(long long i=l2; i<l1; i++)
        {
            if(borrow == 1)
            {
                borrow = 0;
                result.value = char(larger.value[pi--]-1) + result.value;
            }
            else
                result.value = larger.value[pi--] + result.value;
        }

        result.value = ltrim(result.value, '0');

        return result;   
    }
};