#include "string.h"

unsigned String::size()
{
    unsigned int count;
    for(count=0;this->buffer_[count]!='\0'; count++)
    {}
    return count;
}

unsigned String::length()
{
    return this->size();
}

unsigned String::capacity()
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

char& String::operator[](unsigned index)
{
    return this->buffer_[index];
}

char& String::at(unsigned int index)
{
        if (index > this->capacity_){
            std::cout<<"The index is out of range";
        }
    return this->buffer_[index];

}

/*
std::ostream& operator<<(std::ostream& out, const String& str)
{
    for(unsigned i=0; i < str.size_; i++)
        out << str.buffer_;
    return out;
}*/

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

String& String::operator=(String& other)
{
    if(this->capacity_<other.capacity())
    {
        //Need more memory
    }
    for(int i=0; ;i++)
    {
        this->buffer_[i]=other.buffer_[i];
        if(other.buffer_[i]=='\0')
            break;
    }
    return *this;
}

Iterator Iterator::operator++ ()
{
    this->index++;
    return *this;
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
/*Iterator::Iterator(char* str)
    :
      index(0),
      begin_(0),
      end_(0)
{
          index=0;
          begin_=0;
          do{
          index++;
          }while(str[index]!='\0');
          end_=index;
}
*/

Iterator String::begin()
{
    Iterator it;
    it.index=&this->buffer_[0];
    return it;
}

Iterator String::end()
{
    Iterator it;
    it.index=&this->buffer_[this->size_];
    return it;
}

String& String::append(const String& other)
{
    int i;
    for(i=0; ;i++)
    {
        if(this->buffer_[i]=='\0')
            break;
        //i++;
    }
    if(this->capacity_<this->size_+other.size_+1){
        //Need more memory!
    }
    for(int c=0; ;c++)
    {
        this->buffer_[i]=other.buffer_[c];
        if(other.buffer_[c]=='\0')
            break;
        i++;
    }
    return *this;
}

String& String::operator+=(const String& other)
{
    int i;
    for(i=0; ;i++)
    {
        if(this->buffer_[i]=='\0')
            break;
        i++;
    }
    if(this->capacity_<this->size_+other.size_+1){
        //Need more memory!
    }
    for(int c=0; ;c++)
    {
        this->buffer_[i]=other.buffer_[c];
        if(other.buffer_[c]=='\0')
            break;
        i++;
    }
    return *this;
}

/*void String::push_back(char ch) //Opt
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
    for(int c=0; buffer_[c]!='\0'; c++)
        std::cout<<this->buffer_[c];
}
*/
void String::push_back(char ch){
    this->buffer_[size_]=ch;
    std::cout<<this->buffer_;
}

String String::operator+(const String& other)
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
    return *this;
}

String operator+(const String& s1, const String& s2)
{
    int i;
    String str(s1.size_+s2.size_+1) ;
    for (i=0; ;i++)
    {
        if(s1.buffer_[i]=='\0')
            break;
        str.buffer_[i]=s1.buffer_[i];
    }

    for(int c=0; ;c++, i++)
    {
        str.buffer_[i]=s2.buffer_[c];
        if(s2.buffer_[c]=='\0')
            break;
    }
    return str;
}

unsigned String::find(const String& str, unsigned pos)
{
    unsigned index, indexOfFirstString;
    index=pos;
    indexOfFirstString=pos;
    for(index=pos;index<this->size_;)
    {
        indexOfFirstString=index;
        for(unsigned i=0;i<str.size_; i++) //!
        {
            if(str.buffer_[i]=='\0')
                return index;
            if(this->buffer_[indexOfFirstString]=='\0')
                return -1;
            if(this->buffer_[indexOfFirstString]!=str.buffer_[i])
            {
                index++;
                break;
            }
            indexOfFirstString++;
        }
    }
    return -1;
}

unsigned String::find_first_of(const String& str, unsigned pos)
{
    unsigned index;
    index=pos;
    for(int i=0;;index++)
    {
        if(str.buffer_[i]==this->buffer_[index]&& str.buffer_[i]!='\0')
            return index;
        if(this->buffer_[index]=='\0')
        {
            index=pos;
            i++;
        }
        if(str.buffer_[i]=='\0')
            return -1;
    }
}

/*String String::substr(unsigned pos, unsigned n)
{
    String result(n+1);
    unsigned i;
    for(i=0;i<n;i++, pos++)
    {
        result.buffer_[i]=this->buffer_[pos];
        if(this->buffer_[i]=='\0')
            return -1;
    }
    result.buffer_[i]='\0';
    return result;
}
*/
void String::substr(unsigned pos, unsigned n)
{
    String str(n+1);
    for(unsigned i=pos, j=0; i<pos+n, j<n ;i++, j++)
        str.buffer_[j]=this->buffer_[i];
    std::cout<<str.buffer_;
}

String::String(unsigned int capacity)
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


/*
char& String::lastIndex(){
    return this->size_;
}
*/
