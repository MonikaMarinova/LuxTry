#ifndef STRING_H
#define STRING_H

class String
{
int capasity_;
int size_;
char buffer_;
public:
 String (int capacity);
 String (const char*str);

 String:: String(int capasity)
:
     capasity_(capasity),
     size_(0),
     buffer_(new char [capasity])
 {}

String::~String()
{
   delete [] buffer_;
}

 };

#endif // STRING_H
