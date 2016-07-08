#include<iostream>
#include<InvalidIndexException.h>
#include "string.h"

using namespace std;
using namespace string;


String::String(const char* str)
:
    capasity_(capasity),
    size_(0),
    buffer_(0)
    {
        size_=strlen(str);
        capasity_=size_+1;
        buffer_=new char[capasity_];
        strcpy(buffer_,str);
    }
{}

String::String(const String& other)
    :
      capasity_(capasity),
      size_(0),
      buffer_(0)
      {
          size_=strlen(str);
          capasity_=size_+1;
          buffer_=new char[capasity_];
          strcpy(buffer_,other);
      }

{}

int String::size(){
    int count=0;
    do{
        count++;
    }
    while(this->buffer_[count]!= '\0');
    return count+1;
}


int String::lenght(){
    int count=0;
    do{
        count++;
    }
    while(this->buffer_[count]!= '\0');
    return count+1;
}

int String::capasity(){
    return this->capasity_;
}

bool String::empty(){
    if(this->buffer_[0]=='\0')
        return true;
    else
        return false;
}

void String::clear(){
    int index=0;
    do{
        this->buffer_[index]=0;
        index++;
    }
    while(this->buffer_[index]!= '\0');
}

char& String::operator[](int index){
    return this->buffer_[index];
}

char& String::at(int index){
    if(index<0 || index > this.capasity_)
       throw InvalidIndexException;
    else return this->buffer_[index];
}

ostream String::operator<<(ostream& out, const String& str){
    for(int i=0;i<this->size_;i++)
    out<<this->buffer_;
    return out;
}

bool String::operator==(const String& other){
    int comparison;
    comparison=strcmp(this->String, other);
    if(comparison==0)
            return true;
    else
        return false;
}

bool String::operator!=(const String& other){
    int comparison;
    comparison=strcmp(this->String, other);
    if(comparison!=0)
            return true;
    else
        return false;
}

bool String::operator>(const String& other){
    int comparison;
    comparison=strcmp(this->String, other);
    if(comparison>0)
            return true;
    else
        return false;
}

bool String::operator<(const String& other){
    int comparison;
    comparison=strcmp(this->String, other);
    if(comparison<0)
            return true;
    else
        return false;
}

bool String::operator>=(const String& other){
    int comparison;
    comparison=strcmp(this->String, other);
    if(comparison>=0)
            return true;
    else
        return false;
}

bool String::operator<=(const String& other){
    int comparison;
    comparison=strcmp(this->String, other);
    if(comparison<=0)
            return true;
    else
        return false;
}


String& String::operator=(const String& other){
int index=0;
do
{
    if(this->size_>strlen(other))
    {
        this->buffer_[index]
    }
    this->buffer_[index]=other[index];
    index++;
}while(other[index]!='\0'|| this->buffer_[index]!='\0');
}

String$ String::append(const String& other){
    int index, secondIndex;
    index=this->capasity_+1;
    secondIndex=0;
    do{
        this->buffer_[index]=other[secondIndex];
        index++;
        secondIndex++;
    }while(other[index]!='\0');
    return this->buffer_;
}

String$ String::operator+=(const String& other){
    int index, secondIndex;
    index=this->capasity_+1;
    secondIndex=0;
    do{
        this->buffer_[index]=other[secondIndex];
        index++;
        secondIndex++;
    }while(other[index]!='\0');
    return this->buffer_;
}

void String::push_back(char ch){
    int index=this->size_;
    this->buffer_[index]=ch;
}

String String::operator+(const String& other){
    int firstIndex=this->size_;
    int secondIndex=0;

    do
    {
        this->buffer_[firstIndex]=other[secondIndex];
        firstIndex++;
        secondIndex++;
    }while(other[secondIndex]!='\0');
    return this->buffer_;
}

String String::operator+(const String& s1,const String& s2){
    int firstIndex=strlen(s1), secondIndex=0;

    do
    {
        s1[firstIndex]=s2[secondIndex];
        firstIndex++;
        secondIndex++;
    }while(s2[secondIndex]!='\0');
    return s1;
}

unsigned String::find(const String& str, unsigned pos){
    for(int i=pos;i<capasity_-pos;i++)
        for(int j=0;j<strlen(str);j++)
        {
            if(this->buffer_[i]!= str[j])
                return -1;
        }
return i-strlen(str);
}

usigned String::find_firs_of(const String& str, pos){
    for(int i=pos;i<capasity_-pos;i++)
        for(int j=0;j<strlen(str);j++)
        {
            if(this->buffer_[i]!= str[j] && str[j]=='\0')
                return -1;
        }
return i;
}

String String::substr(unsigned pos, unsigned n){
    String sub;
    for(int i=0;i<n;i++,pos++){
        sub[i] = this->buffer_[pos];
    }
    return sub;
}

public:
class Iterator{
    String str;
    int index;
    public:
    Iterator(String s){
        str=s;
        index=0;
    }
   Iterator operator++(){
       this->index++;
   }

   Iterator operator++(int){
      Iterator clone(*this);
      ++index;
      return clone;
   }
  bool operator==(const Iterator& other) const{
      Iterator clone(*this);
     do{
          if(clone.str[index]!=other.str[index])
             return false;
          else
              return true;
              index++;
      }while(clone.str[index]!= '\0');
  }

      bool operator!=(const Iterator& other) const{
          Iterator clone(*this);
         do{
              if(clone.str[index]==other.str[index])
                 return false;
              else
                  return true;
                  index++;
          }while(clone.str[index]!= '\0');
      }
};

Iterator Iterator::begin(){
    Iterator clone(*this);
    int index=clone.index;
    do{
        index++;
        return clone;
    }while(clone.str[index]!='\0');
}

Iterator Iterator::begin(){
    Iterator clone(*this);
      do{
        index++;
    }while(clone.str[index]!='\0');
return clone;
}
