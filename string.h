#ifndef STRING_H
#define STRING_H
#include <iostream>
//#include </usr/include/stdio.h>
//#include <string.h>
#include </usr/include/string.h>

//using namespace std;

class Iterator
{
public:
    char* index;
public:
    Iterator operator++();
    Iterator operator++(int);

    bool operator==(const Iterator& other);
    bool operator!=(const Iterator& other);
    char& operator*(int index);
};

class String
{
    public:
        unsigned int capacity_;
        unsigned int size_;
        char* buffer_;

        String(unsigned int capacity);
        String(const char* str);
        String(const String& other);
        String(){}
        ~String();

    unsigned size();
    unsigned length();
    unsigned capacity();
    bool empty();
    void clear();
    char& operator[](unsigned index);
    char& at(unsigned index);

    String& operator=(String& other);
    //1.5
    String& append(const String& other);
    String& operator+=(const String& other);
    void push_back(char ch);
    String operator+(const String& other);

    bool operator==(String& other);
    bool operator!=(String& other);

    bool operator<(String& other);
    bool operator>(String& other);

    bool operator<=(String& other);
    bool operator>=(String& other);

    String moreMemory();

    Iterator begin();
    Iterator end();

    //1.6
    unsigned find(const String& str, unsigned pos);
    unsigned find_first_of(const String& str, unsigned pos);
    void substr(unsigned int pos, unsigned int n);
};


#endif // STRING_H
