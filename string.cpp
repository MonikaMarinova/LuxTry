#include "string.h"
#include "InvalidIndexException.h"
#include <string.h>

int String::size()
{
    int count;
    char symbol= this->buffer_[0];
    for(count=0; symbol!='\n'; count++)
    {}
    return count;
}

int String::length()
{
    return size();
}

int String::capacity()
{
    return this->capacity_;
}

bool String::empty()
{
    if(this->size_==0)
        return true;
    else
        return false;
}

void String::clear()
{
    this->buffer_[0]='\0';
    this->size_=0;
}

char& String::operator[](int index)
{
    return this->buffer_[index];
}

char& String::at(int index)
{
    if (index < 0 || index > this->capacity_){
        throw InvalidIndexException;
    }
    return this->buffer_[index];
}


ostream& String::operator<<(ostream& out)
{
    for(int i; i<this->size_; i++)
        out << this->buffer_[i];
    return out;
}

bool String::operator==(String& other)
{
    int isEquel;
    isEquel=strcmp(this->buffer_, other.buffer_);
    if(isEquel==0)
        return true;
    else
        return false;
}

bool String::operator!=(String& other)
{
    int isEquel;
    isEquel=strcmp(this->buffer_, other.buffer_);
    if(isEquel!=0)
        return true;
    else
        return false;
}

bool String::operator>(String& other)
{
    int isEquel;
    isEquel=strcmp(this->buffer_, other.buffer_);
    if(isEquel>0)
        return true;
    else
        return false;
}

bool String::operator<(String& other)
{
    int isEquel;
    isEquel=strcmp(this->buffer_, other.buffer_);
    if(isEquel<0)
        return true;
    else
        return false;
}

bool String::operator>=(String& other)
{
    int isEquel;
    isEquel=strcmp(this->buffer_, other.buffer_);
    if(isEquel>=0)
        return true;
    else
        return false;
}

bool String::operator<=(String& other)
{
    int isEquel;
    isEquel=strcmp(this->buffer_, other.buffer_);
    if(isEquel<=0)
        return true;
    else
        return false;
}

String& String::operator=(const String& other)
{
    if(this->capacity_<other->capacity_)
    {
        //Need more memory
    }
    for(int i; ;i++)
    {
        this->buffer_[i]=other.buffer_[i];
        if(other.buffer_[i]=='\0')
            break;
    }
}

Iterator Iterator::operator++ ()
{
    this->index++;
}

Iterator Iterator::operator++(int)
{
    Iterator clone (*this);
    ++index;
    return clone;
}
//
bool Iterator::operator==(const Iterator& other)
{
    if(this->index!=other.index)
        return false;
    else
        return true;
}

bool Iterator::operator!=(const Iterator& other)
{
    if(this->index==other.index)
        return false;
    else
        return true;
}

Iterator Iterator::begin()
{
    Iterator clone(*this);
    /*
    int index=clone.index;
    do{
        index++;
    }while(clone.str[index]!='\0');
    */
    return clone;
}

Iterator Iterator::end()
{
    Iterator clone(*this);
    do{
        index++;
    }while(clone.str[index]!='\0');
index++;
return clone;
}

String& append(const String& other)
{
    int i;
    for(i=0; ;i++)
    {
        if(this->buffer_[i]=='\0')
            break;
        i++;
    }
    for(int c=0; ;c++)
    {
        this->buffer_[i]=other.buffer_[c];
        if(other.buffer_[c]=='\0')
            break;
        i++;
    }
}

String& operator+=(const String& other)
{
    int i;
    for(i=0; ;i++)
    {
        if(this->buffer_[i]=='\0')
            break;
        i++;
    }
    for(int c=0; ;c++)
    {
        this->buffer_[i]=other.buffer_[c];
        if(other.buffer_[c]=='\0')
            break;
        i++;
    }
}

void push_back(char ch)
{
        int i;
    for(i=0; ;i++)
    {
        if(this->buffer_[i]=='\0')
            break;
        i++;
    }
    this->buffer_[i]=ch;
    this->buffer_[i+1]='\0';
}

String operator+(const String& other)
{
    int i;
    for(i=0; ;i++)
    {
        if(this->buffer_[i]=='\0')
            break;
        i++;
    }
    for(int c=0; ;c++)
    {
        this->buffer_[i]=other.buffer_[c];
        if(other.buffer_[c]=='\0')
            break;
        i++;
    }
}

String operator+(const String& s1, const String& s2)
{
    int i;
    for (i=0; ;i++)
    {
        if(s1.buffer_[i]=='\0')
            break;
    }
    for(int c=0; ;c++)
    {
        s1->buffer_[i]=s2->buffer_[c];
        if(s2.buffer_[c]=='\0')
            break;
        i++;
    }
}

unsigned find(const String& str, unsigned pos)
{
    unsigned index, indexOfFirstString;
    index=pos;
    indexOfFirstString=pos;
    for(;index<this.size_;)
    {
        indexOfFirstString=index;
        for(int i=0;i<str.size_; i++) //!
        {
            if(str.buffer_[i]=='\0')
                return index;
            if(this.buffer_[indexOfFirstString]=='\0')
                return -1;
            if(this.buffer_[indexOfFirstString]!=str.buffer_[i])
            {
                index++;
                break;
            }
            indexOfFirstString++;
        }
    }
    return -1;
}

unsigned find_first_of(const String& str, unsigned pos)
{
    unsigned index;
    index=pos;
    for(int i=0;;index++)
    {
        if(str.buffer_[i]==this.buffer_[index]&& str.buffer_[i]!='\0')
            return index;
        if(this.buffer_[index]=='\0')
        {
            index=pos;
            i++;
        }
        if(str.buffer_[i]=='\0')
            return -1;
    }
}

String substr(unsigned pos, unsigned n)
{
    String result;
    int i;
    for(i=0;i<n;i++, pos++)
    {
        result->buffer_[i]=this.buffer_[pos];
        if(this.buffer_[i]=='\0')
            return -1;
    }
    result->buffer_[i]='\0';
    return result;
}

String::String(unsigned capacity)
    :
      capacity_(capacity),
      size_(0),
      buffer_(new char[capacity])
{}

String::String(const char* str)
    :
      capacity_(0),
      size_(0),
      buffer_(0)
{
    size_=strlen(str);
    capacity_=size_+1;
    buffer_= new char[capacity_];
    strcpy(buffer_,str);
}
/*
String::String(const char *other)
    :
      capacity_(0),
      size_(0),
      buffer_(0)
      {
          size_=strlen(other);
          capacity_=size_+1;
          buffer_=new char[capasity_];
          strcpy(buffer_,other);
      }*/

String::String(const String& other)
    :
      capacity_(other.capacity_),
      size_(other.size_),
      buffer_(other.buffer_)
{}



String::~String()
{
    delete [] buffer_;
}



char& String::lastIndex(){
    return this->size_;
}
