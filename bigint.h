/*
========================================================================

INITIALIZATION :

    string s = "12345";
    bigint b(s);

=========================================================================

METHODS:

    string print()    =>    Returns the value stored in bigint object
    void reverse()    =>    Reverses the bigint object    

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
    }
    
    std::string print()
    {
        if(sign == 0)
            return "-" + value;
        return value;
    }

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

    bool operator == (bigint b)
    {
        if( value == b.value)
            return true;
        return false;    
    }

    bool operator > (bigint b)
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

    bool operator < (bigint b)
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

    bool operator >= (bigint b)
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

    bool operator <= (bigint b)
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

    bigint operator + (bigint b)
    {
        int carry = 0;
        bigint sum("");
        long long l1 = value.length();
        long long l2 = b.value.length();
        long long p1 = 0;
        long long p2 = 0;
        long long i=0;

        this->reverse();
        b.reverse();

        for(long long i=0; i<((l1<l2)?l1:l2); i++)
        {
            int nval = value[i]-48 + b.value[i]-48 + carry;
            carry = nval/10;
            sum.value = sum.value + char((nval % 10)+48);
            p1++ , p2++;
        }

        while(p1 < l1)
        {
            int nval = value[p1++]-48 + carry;
            carry = nval/10;
            sum.value = sum.value + char((nval % 10) + 48);
        }

        while(p2 < l2)
        {
            int nval = b.value[p2++]-48 + carry;
            carry = nval/10;
            sum.value = sum.value + char((nval % 10) + 48);
        }

        if(carry>0)
            sum.value = sum.value + char((carry) + 48);

        sum.reverse();

        return sum;
    }

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
        larger.reverse();
        smaller.reverse();

        for(long long i=0; i<l2; i++)
        {
            int v1 = larger.value[i]-48 - borrow;
            int v2 = smaller.value[i]-48;
            if(v1 < v2)
            {
                v1 = v1+10;
                borrow = 1;
            }
            else
                borrow = 0;
            result.value = result.value + char((v1-v2) + 48); 
        }

        for(long long i=l2; i<l1; i++)
        {
            if(borrow == 1)
            {
                borrow = 0;
                result.value = result.value + char(larger.value[i]-1);
            }
            else
                result.value = result.value + larger.value[i];
        }

        result.reverse();

        return result;   
    }
};