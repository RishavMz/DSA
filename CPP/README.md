
<h3 align="center"><b><u>bigint.h</u></b><h3>

INITIALIZATION :

    string s = "12345";
    bigint b(s);


METHODS:

    string print()        =>    Returns the value stored in bigint object
    void reverse()        =>    Reverses the bigint object 
    string absolute()     =>    Returns the absolute value of bigint object   
    bigint pow(bigint b)  =>    Returns base bigint raised to power of given bigint


OVERLOADED OPERATORS:

    ==        =>    Compares equality of two bigint objects
    <         =>    Checks if the given bigint value is less than another bigint value
    >         =>    Checks if the given bigint value is greater than or equal to another bigint value
    <=        =>    Checks if the given bigint value is less than or equal to another bigint value
    >=        =>    Checks if the given bigint value is greater than another bigint value
    +         =>    Addition of two bigint objects
    -         =>    Subtraction of two bigint objects
    *         =>    Multiplication of two bigint objects
    ++        =>    Increment the value of bigint object
    --        =>    Decrement the value of bigint object



#

<h3 align="center"><b><u>pythonizer.h</u></b><h3>

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
