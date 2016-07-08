#ifndef INVALIDINDEXEXCEPTION_H
#define INVALIDINDEXEXCEPTION_H

class InvalidIndexException: public exception
{
  virtual const char* what() const throw()
  {
    return "The index is negative or out of range";
  }
}
#endif // INVALIDINDEXEXCEPTION_H
