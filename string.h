#ifndef STRING_H
#define STRING_H
#include <iostream>
#include </usr/include/stdio.h>
#include <string.h>
#include </usr/include/string.h>


extern int calc();

//using namespace std;

class Iterator
{
public:
    char* index;
//    unsigned int begin_;
//    unsigned int end_;
public:
/*
    Iterator()
    {
        index=0;
        do{
            str[index]=this.buffer_[index];
            index++;
        }while(this.buffer_[index]!='\0');
        size=index;
    }
*/
//    void Eval(unsigned int size){this->end_ = size;};
    Iterator operator++();
    Iterator operator++(int);

//    Iterator(char* str);


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
  /*      friend ostream& operator<<( ostream &output,
                                         const String &D )
        {
           //output << "F : " << D.feet << " I : " << D.inches;
           output << D.buffer_;
           return output;
        }*/
        Iterator I;
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

//    char& lastIndex();

    Iterator begin();// const;
    Iterator end();// const;

    //1.6
    unsigned find(const String& str, unsigned pos);
    unsigned find_first_of(const String& str, unsigned pos);
    void substr(unsigned pos, unsigned n);

};


#endif // STRING_H
