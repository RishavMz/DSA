/*

string ltrim(std::string s , char c=' ')
    
    Removes selected character occurances from the left of the string

std::string rtrim(std::string s, char c=' ')

    Removes selected character occurances from the right of the string

std::string trim(std::string s, char c=' ')

    Removes selected character occurances from the left and right of the string

std::vector<std::string> split(std::string s, char c=' ')

    Implemented the missing split function for C++ to split a string based on a specified character into array of strings 

std::vector<T> distinct(std::vector<T> v)

    Removing duplicates from a given vector

std::string str(T data)                 

    Returns a numeric data as a string datatype 

*/

#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cmath>

// Removes selected character occurances from the left of the string
std::string ltrim(std::string s , char c=' ')
{
    long long i=0;
    while(i<s.length())
    {
        if(s[i]==c)
            i++;
        else
            break;    
    }
    return s.substr(i);
}

// Removes selected character occurances from the right of the string
std::string rtrim(std::string s, char c=' ')
{
    std::string s1;
    long long i=s.length()-1;
    while(i>=0)
    {
        if(s[i]==c)
            i--;
        else
            break;    
    }
    return s.substr(0,i+1);
}

// Removes selected character occurances from the left and right of the string
std::string trim(std::string s, char c=' ')
{
    return ltrim(rtrim(s,c),c);
}

// Implemented the missing split function for C++ to split a string based on a specified character into array of strings 
std::vector<std::string> split(std::string s, char c=' ')
{
    std::vector<std::string>parts;
    std::string temp = "";
    for(long long i=0; i<s.length(); i++)
    {
        if(i == s.length()-1)
        {
            temp = temp + s[i];
            parts.push_back(temp);
            temp = "";
        }
        else if(i == s.length()-1 || s[i]==c)
        {
            parts.push_back(temp);
            temp = "";
        }
        else
        {
            temp = temp + s[i];
        }
    }
    return parts;
}

// Removing duplicates from a given vector
template < typename T >
std::vector<T> distinct(std::vector<T> v)
{
    std::set<T> s;
    for(auto i : v)
        s.insert(i);
    std::vector<T> d;
    for(auto i : s)
        d.push_back(i);
    return d;        
}

std::string str(int data)
{
    std::string s = "";
    while(data>0)
    {
        s = char((data%10)+48) + s;
        data /= 10;
    }
    return s;
}

std::string str(long long int data)
{
    std::string s = "";
    while(data>0)
    {
        s = char((data%10)+48) + s;
        data /= 10;
    }
    return s;
}

std::string str(float data)
{
    std::string s = ".";
    double integer, fraction;
    fraction = modf(data, &integer);
    s = str(int(integer)) + ".";
    while(fraction>0)
    {
        fraction *= 10;
        s = s + str(int(floor(fraction))%10);
        if(ceil(fraction) == floor(fraction))
            break;
    }
    return s;
}

std::string str(double data)
{
    std::string s = ".";
    double integer, fraction;
    fraction = modf(data, &integer);
    s = str(int(integer)) + ".";
    while(fraction>0)
    {
        fraction *= 10;
        s = s + str(int(floor(fraction))%10);
        if(ceil(fraction) == floor(fraction))
            break;
    }
    return s;
}