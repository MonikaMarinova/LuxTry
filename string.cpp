#include "string.h"

#define EOS '/0'



/* String lenght()
 * returns the size_ of the buffer_
 * return unsigned int
 */
unsigned String::size()
{
    unsigned int count;
    for(count=0;this->buffer_[count]!='\0'; count++)
    {}
    return count;
}




/* String lenght()
 * returns the size_ of the buffer_
 * return unsigned int
 */
unsigned String::length()
{
    return this->size();
}




/* String capacity()
 * returns the capacity of the buffer_
 * return unsigned int
 */
unsigned String::capacity()
{
    return this->capacity_;
}





/* String empty()
 * finds if size is equal to 0
 * return bool
 */
bool String::empty()
{
    if(this->size_==0)
        return true;
    else
        return false;
}




/* String clear()
 * sets first symbol to be \0
 * sets size_=0
 */
void String::clear()
{
    this->buffer_[0]='\0';
    this->size_=0;
}




/* String operator[](unsigned index)
 * returns pointer to buffer_[index]
 * returns char
 */
char& String::operator[](unsigned index)
{
    return this->buffer_[index];
}




/* String at(unsigned int index)
 * if the index is out oof range prints message
 * returns pointer to buffer_[index]
 * returns char
 */
char& String::at(unsigned int index)
{
        if (index > this->capacity_){
            std::cout<<"The index is out of range";
        }
    return this->buffer_[index];

}




/* String operator>=(String& other)
 * overloaded operator >=
 * finds if object is equal of other String
 * returns bool
 */
bool String::operator==(String& other)
{
    int isEqual;
    isEqual=strcmp(this->buffer_, other.buffer_);
    if(isEqual==0)
        return true;
    else
        return false;
}




/* String operator>=(String& other)
 * overloaded operator >=
 * finds if object is not equal of other String
 * returns bool
 */
bool String::operator!=(String& other)
{
    int isEqual;
    isEqual=strcmp(this->buffer_, other.buffer_);
    if(isEqual!=0)
        return true;
    else
        return false;
}




/* String operator>=(String& other)
 * overloaded operator >=
 * finds if object is greater than other String
 * returns bool
 */
bool String::operator>(String& other)
{
    int isEqual;
    isEqual=strcmp(this->buffer_, other.buffer_);
    if(isEqual>0)
        return true;
    else
        return false;
}




/* String operator>=(String& other)
 * overloaded operator >=
 * finds if object is less than other String
 * returns bool
 */
bool String::operator<(String& other)
{
    int isEqual;
    isEqual=strcmp(this->buffer_, other.buffer_);
    if(isEqual<0)
        return true;
    else
        return false;
}




/* String operator>=(String& other)
 * overloaded operator >=
 * finds if object is greater or equal of other String
 * returns bool
 */
bool String::operator>=(String& other)
{
    int isEqual;
    isEqual=strcmp(this->buffer_, other.buffer_);
    if(isEqual>=0)
        return true;
    else
        return false;
}




/* String operator<=(String& other)
 * overloaded operator <=
 * finds if less or equal of other string
 * returns bool
 */
bool String::operator<=(String& other)
{
    //int32_t u32Pesho;
    int isEqual;
    isEqual=strcmp(this->buffer_, other.buffer_);
    if(isEqual<=0)
        return true;
    else
        return false;
}
/*
0x7F = 127
0x01 = 1
0 0 0 0 0 0 0 0 = 0
0xFF = -1
0xFE = -2
0x80 = -128
*/

/* String operator=(String& other)
 * overloaded operator =
 * copy value of other string in object
 * returns String
 */
String& String::operator=(String& other)
{
    if(this->capacity_<other.capacity())
    {
        //Need more memory
    }
    for(int i=0; ;i++)
    {
        this->buffer_[i]=other.buffer_[i];
        if(other.buffer_[i]== EOS)
            break;
    }
    return *this;
}




/* String begin()
 * sets Iterator's index in the begining of the object's buffer_
 * returns Iterator
 */
Iterator String::begin()
{
    Iterator it;
    it.index=&this->buffer_[0];
    return it;
}




/* String end()
 * sets Iterator's index in the end of the object's buffer_
 * returns Iterator
 */
Iterator String::end()
{
    Iterator it;
    it.index=&this->buffer_[this->size_];
    return it;
}




/*String append(const String& other)
 * adds String other in the end of the object
 * returns String
 */
String& String::append(const String& other)
{
    this->operator +(other);
    /*
     * int i;
    std::cout<<"Before";
    std::cout<<this->capacity_;
    for(i=0; ;i++)
    {
        if(this->buffer_[i]=='\0')
            break;
    }
    if(this->capacity_<this->size_ + other.size_ + 1){

    }
    std::cout<<"After";
    std::cout<<this->capacity_;
    for(int c=0; ;c++)
    {
        this->buffer_[i]=other.buffer_[c];
        if(other.buffer_[c]=='\0')
            break;
        i++;
    }
    return *this;
    */
}


/* function: String operator+=(const String& other)
 * details: overloaded operator +=
 * adds String other in the end of the object
 * returns String
 */
String& String::operator+=(const String& other)
{
    /*if(null!=other)*/
    int i;
    for(i=0; ;i++)
    {
        if('\0' == this->buffer_[i])
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




/*String push_back(char ch)
 * adds character ch in the end of the object
 * prints object's buffer
 */
void String::push_back(char ch){
    this->buffer_[size_]=ch;
    std::cout<<this->buffer_;
}




/*String operator+(const String& other)
 * overloaded operator +
 * creates  String with content of both object and other
 * returns String
 */
String String::operator+(const String& other)
{
    int i, size;

    size = this->size_ + other.size_ + 1;
    char* tmp = new char(size);
    std::cout<<"test";
    std::cout<<size;

    for(i = 0; i < this->size_; i++)
    {
        tmp[i] = this->buffer_[i];
    }

    for(i = 0; i <= other.capacity_; i++)
    {
        tmp[this->size_ + i] = other.buffer_[i];

    }

    std::cout<<tmp[this->size_];

    delete[] this->buffer_;

    this->buffer_ = new char(size);

    strcpy(this->buffer_,tmp);

    this->capacity();
    this->size();

    std::cout<<"After";
    std::cout<<this->capacity_;

    delete[] tmp;

    return *this;
}




/* String operator +(const String& s1, const String& s2)
 * overloaded operator +
 * creates new string with the contend of str1 and str2
 * returns String
 */
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




/*String find(const String& str, unsigned pos)
 * finds first sub string str
 * searching starts from index pos
 * searching ends in the end of the object
 * returns unsigned int : index of the first found string
 * return -1: sub string was not found
 */
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




/*String find_first_of(const String& str, unsigned pos)
 * finds first symbol of str
 * searching starts from index pos
 * searching ends in the end of the object
 * returns unsigned int: index of the first found symbol
 * return -1: there is no symbol that is in both strings
 */
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




/* operator<<
 * ovgerloaded operator <<
 * adds all characters from object in the out stream
 * return ostream
*/
std::ostream& operator<<(std::ostream& out, const String& str) //!
{
    for(unsigned i=0; i < str.size_; i++)
        out << str.buffer_;
    return out;
}




/*String substr(unsigned pos, unsigned n)
 * starts from index pos
 * length of the sub string n characters
 * prints sub string from index=pos
 */
void String::substr(unsigned int pos, unsigned int n)
{
    String str(n+1);
    for(unsigned i=pos, j=0; i<pos+n/*, j<n*/ ;i++, j++)
    {
        str.buffer_[j]=this->buffer_[i];
        std::cout<<str.buffer_[j];
    }
}




/*String constructor(unsigned int capacity)
 *uses capacity
 */
String::String(unsigned int capacity)
    :
      capacity_(capacity),
      size_(0),
      buffer_(new char[capacity])
{}




/* String constructor(const char* str)
 *  uses char*
*/
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




/*String constructor(const String& other)
 * copy contructor
 */
String::String(const String& other)
    :
      capacity_(other.capacity_),
      size_(other.size_),
      buffer_(other.buffer_)
{}




/*String ~String()
 * destructor
*/
String::~String()
{
    delete [] buffer_;
}




/*Iterator operator++
 * overloaded operator ++
 * increments Iterator's index with 1
 * retuns Iterator
 */
Iterator Iterator::operator++ ()
{
    this->index+=1;
    return *this;
}




/*Iterator operator++
 * overloaded operator ++
 * increments Iterator's index with n
 * retuns Iterator
 */
Iterator Iterator::operator++(int n)
{
    this->index+=n;
    return *this;
}





/*bool operator==
 * overloaded operator ==
 * finds if symbols from object and other string are equal
 * retuns bool
 */
bool Iterator::operator==(const Iterator& other)
{
    if(this->index[0]!=other.index[0])
        return false;
    else
        return true;
}




/*bool operator!=
 * overloaded operator !=
 * finds if symbols from object and other string are not equal
 * retuns bool
 */
bool Iterator::operator!=(const Iterator& other)
{
    if(this->index==other.index)
        return false;
    else
        return true;
}





/*Iterator constructor with String.buffer_
 *
 * Iterator::Iterator(char* str)
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




/*
 * Other implementation of substr
String String::substr(unsigned pos, unsigned n)
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





/* Other implementation of String push_back
 *
 * void String::push_back(char ch) //Opt
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
/*String::String(unsigned int capacity)
    :
      capacity_(capacity),
      size_(0),
      buffer_(new char[capacity])
{}
*/

/*
String String::moreMemory()
{
    String temp;
    temp.capacity_=this->capacity_*2;
    std::cout<<'moreMemory test \n';
    std::cout<<temp.capacity_;
    temp.size_=0;
    temp.buffer_= new char(temp.capacity_);
    temp=*this;
    delete this;
    return temp;
}

String String::moreMemory()
{
    String temp;
    temp.capacity_=this->capacity_*2;
    temp.size_=0;
    temp.buffer_(new char[temp.capacity_]);
    temp=*this;
    delete *this;
    return temp;
}
*/
