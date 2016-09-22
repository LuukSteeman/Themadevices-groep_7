//Template class seperate declaration/implementation??

#ifndef __arm__
    #include <string>
    #include <iostream>
#else
    #include "hwlib.hpp"
#endif // !__arm__

template <int T>
class String
{
  private:
    char string[T + 1];

  public:
    //constructors
    String()
    {
        string[0] = '\0';
    };
    String( const char *literalString)
    {
        int currentChar = 0;
        while (*literalString != '\0' && currentChar < T)
        {
            string[currentChar] = *literalString;
            literalString++;
            currentChar++;
        }
        string[currentChar] = '\0';
    };
#ifndef __arm__
    String(const std::string & copyString):
    String(copyString.c_str())
    {};
#endif // !__arm__

    //functions
    void clear()
    {
        string[0] = '\0';
    };

    int length()
    {
        int length = 0;
        while (string[length] != '\0')
        {
            length++;
        }
        return length;
    };

    //returns mutable c_str
    char *c_str()
    {
        return &string[0];
    };

    // //operators
    String<T> operator=(char in)
    {
        string[0] = in;
        string[1] = '\0';
        return this;
    };
    String<T> operator=(char *in)
    {
        strcpy(string, in);
        string[T + 1] = '\0';
        return this;
    };

    String<T> operator+=(char in)
    {
        int length = this.length();
        string[length + 1] = in;
        string[length + 2] = '\0';
        return this;
    };
    String<T> operator+=(char *in)
    {
        int length = this.length() + 1;
        while (*in != '\0' && length <= T)
        {
            string[length] = *in;
            in++;
            length++;
        }
        string[length] = '\0';
    };

    char operator[](int index) const
    {
        return string[index];
    };
    char &operator[](int index)
    {
        return &string[index];
    };

    //operators with string as rhs
    #ifndef __arm__
    String<T> operator=(std::string in){
        return this=in.c_str();   
    };
    String<T> operator+=(std::string in){
        return this+=in.c_str();
    };
    #endif // !__arm__
};

#ifdef __arm__
typedef hwlib::ostream std_ostream;
#else
typedef std::ostream std_ostream;
#endif
    template <int T2>
    std_ostream &operator<<(std_ostream &out, String<T2> in)
{
    out << in.c_str();
    return out;
};