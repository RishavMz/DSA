
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
        bigint aa,ab;
        aa.value = ltrim(value,'0');
        ab.value = ltrim(b.value,'0');
        if((aa.sign == ab.sign)&&( aa.value == ab.value))
            return true;
        return false;    
    }

    // Checks if given bigint is larger then another bigint
    bool operator > (bigint b)
    {
        bigint aa,ab;
        aa.value = ltrim(value,'0');
        ab.value = ltrim(b.value,'0');
        if(aa.sign == ab.sign)
        {
            if(aa.sign == 1)
            {
                if(aa.value.length() > ab.value.length())
                {
                    return true;
                }
                else if(aa.value.length() < ab.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < aa.value.length())
                    {
                        if(aa.value[i] > ab.value[i])
                            return true;
                        else if(aa.value[i] < ab.value[i])
                            return false;
                        else
                            i++;
                    }
                    return false;
                }
            }
            else 
            {
                if(aa.value.length() < ab.value.length())
                {
                    return true;
                }
                else if(aa.value.length() > ab.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < aa.value.length())
                    {
                        if(aa.value[i] < ab.value[i])
                            return true;
                        else if(aa.value[i] > ab.value[i])
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
            if(aa.sign == 0)
                return false;
            return true;    
        }
        
    }

    // Checks is given bigint is smaller than given bigint
    bool operator < (bigint b)
    {
        bigint aa,ab;
        aa.value = ltrim(value,'0');
        ab.value = ltrim(b.value,'0');
        if(aa.sign == ab.sign)
        {
            if(aa.sign == 1)
            {
                if(aa.value.length() < ab.value.length())
                {
                    return true;
                }
                else if(aa.value.length() > ab.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < aa.value.length())
                    {
                        if(aa.value[i] < ab.value[i])
                            return true;
                        else if(aa.value[i] > ab.value[i])
                            return false;
                        else
                            i++;
                    }
                    return false;
                }
            }
            else 
            {
                if(aa.value.length() > ab.value.length())
                {
                    return true;
                }
                else if(aa.value.length() < ab.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < aa.value.length())
                    {
                        if(aa.value[i] > ab.value[i])
                            return true;
                        else if(aa.value[i] < ab.value[i])
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
            if(aa.sign == 1)
                return false;
            return true;    
        }
    }

    // Checks if bigint if greater than or equal to given bigint
        bool operator >= (bigint b)
    {
        bigint aa,ab;
        aa.value = ltrim(value,'0');
        ab.value = ltrim(b.value,'0');
        if(aa.sign == ab.sign)
        {
            if(aa.sign == 1)
            {
                if(aa.value.length() > ab.value.length())
                {
                    return true;
                }
                else if(aa.value.length() < ab.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < aa.value.length())
                    {
                        if(aa.value[i] > ab.value[i])
                            return true;
                        else if(aa.value[i] < ab.value[i])
                            return false;
                        else
                            i++;
                    }
                    return true;
                }
            }
            else 
            {
                if(aa.value.length() < ab.value.length())
                {
                    return true;
                }
                else if(aa.value.length() > ab.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < aa.value.length())
                    {
                        if(aa.value[i] < ab.value[i])
                            return true;
                        else if(aa.value[i] > ab.value[i])
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
            if(aa.sign == 0)
                return false;
            return true;    
        }
        
    }

    // Checks is given bigint is smaller than or equal to given bigint
    bool operator <= (bigint b)
    {
        bigint aa,ab;
        aa.value = ltrim(value,'0');
        ab.value = ltrim(b.value,'0');
        if(aa.sign == ab.sign)
        {
            if(aa.sign == 1)
            {
                if(aa.value.length() < ab.value.length())
                {
                    return true;
                }
                else if(aa.value.length() > ab.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < aa.value.length())
                    {
                        if(aa.value[i] < ab.value[i])
                            return true;
                        else if(aa.value[i] > ab.value[i])
                            return false;
                        else
                            i++;
                    }
                    return true;
                }
            }
            else 
            {
                if(aa.value.length() > ab.value.length())
                {
                    return true;
                }
                else if(aa.value.length() < ab.value.length())
                {
                    return false;
                }
                else
                {
                    long long i = 0;
                    while(i < aa.value.length())
                    {
                        if(aa.value[i] > ab.value[i])
                            return true;
                        else if(aa.value[i] < ab.value[i])
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
            if(aa.sign == 1)
                return false;
            return true;    
        }
    }

    bigint operator++()
    {
        bigint temp;
        temp.value = "1";
        *this = *this + temp;
        return temp;
    }
    bigint operator++(int)
    {
        bigint temp;
        temp.value = "1";
        *this = *this + temp;
        return temp;
    }
    bigint operator--()
    {
        bigint temp;
        temp.value = "1";
        *this = *this - temp;
        return temp;
    }
    bigint operator--(int)
    {
        bigint temp;
        temp.value = "1";
        *this = *this - temp;
        return temp;
    }

    // Returns the sum of two bigint
    bigint operator + (bigint b)
    {
        value = ltrim(value,'0');
        b.value = ltrim(b.value,'0');
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
        value = ltrim(value,'0');
        b.value = ltrim(b.value,'0');
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

    // Returns the product of two bigint
    bigint operator * (bigint b)
    {
        value = ltrim(value,'0');
        b.value = ltrim(b.value,'0');
        long long l1 = value.length();
        long long l2 = b.value.length();
        bigint result("0");
        int carry = 0;

        for(long long i= 0; i<l1 ; i++)
        {
            bigint temp;
            for(long long j= l2-1 ; j>=0 ; j--)
            {
                int v1 = value[l1 - i-1] -48;
                int v2 = b.value[j] -48;
                int product = (v1 * v2) + carry;
                carry = product / 10;
                temp.value = char((product % 10) + 48) + temp.value ;
            }
            if(carry > 0)
                temp.value = char(carry + 48) + temp.value ;
            for(long long ik=0; ik<i; ik++)
                temp.value = temp.value + '0';  
            result = result + temp;
            carry = 0;
        }

        if(sign == b.sign)
            result.sign = 1;

        else
            result.sign = 0;
            
        return result;

    }

    // Returns the result of division of two bigint
    bigint operator / (bigint b)
    {
        value = ltrim(value,'0');
        b.value = ltrim(b.value,'0');
        bigint quotient;
        bigint temp;
        long long ptr = 0;
        long long l1 = value.length();
        long long l2 = b.value.length();
        std::vector<bigint> products;
        for(int i=0; i<9; i++)
        {
            bigint t;
            t.value = (i+48);
            products.push_back(b * t);
        }
        bool zeroadd = false;
        while(ptr < l1)
        {
            if(temp < b)
            {
                if(zeroadd || (temp.value == ""))
                    quotient.value = quotient.value + "0";
                temp.value = temp.value + value[ptr];
                zeroadd = true;        
            }
            if(temp>=b)
            {
                int ptr1 = 0;
                for(int i=8; i>=1; i--)
                {
                if(products[i] <= temp)
                    {
                        ptr1 = i;
                        break;
                    }
                }
                temp = temp - products[ptr1] ;
                quotient.value = quotient.value + char(ptr1+48);
                zeroadd = false;
            }
            ptr++;
        } 
        quotient.value = ltrim(quotient.value, '0');
        return quotient;
    }

    // Returns the result of modulo operation on two bigint
    bigint operator % (bigint b)
    {
        value = ltrim(value,'0');
        b.value = ltrim(b.value,'0');
        bigint quotient;
        bigint temp;
        long long ptr = 0;
        long long l1 = value.length();
        long long l2 = b.value.length();
        std::vector<bigint> products;
        for(int i=0; i<9; i++)
        {
            bigint t;
            t.value = (i+48);
            products.push_back(b * t);
        }
        bool zeroadd = false;
        while(ptr < l1)
        {
            if(temp < b)
            {
                if(zeroadd || (temp.value == ""))
                    quotient.value = quotient.value + "0";
                temp.value = temp.value + value[ptr];
                zeroadd = true;        
            }
            if(temp>=b)
            {
                int ptr1 = 0;
                for(int i=8; i>=1; i--)
                {
                if(products[i] <= temp)
                    {
                        ptr1 = i;
                        break;
                    }
                }
                temp = temp - products[ptr1] ;
                quotient.value = quotient.value + char(ptr1+48);
                zeroadd = false;
            }
            ptr++;
        } 
        temp.value = ltrim(temp.value, '0');
        if(temp.value=="")
            temp.value="0";
        return temp;
    }

    // Returns the result of one bigint reised to power of another 
    bigint pow(bigint b)
    {
        bigint power;
        power.value = this->value;
        if(b.value=="0")
            power.value="0";
        else
        {
            bigint temp;
            temp.value="1";
            while(temp < b)
            {
                power = power * (*this);
                temp++;
            }
        }    
        return power;
    }

};