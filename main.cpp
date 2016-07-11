#include <iostream>
#include "string.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    String str1, str2;
    int i;
    int z;
    for(i=0;!(str1.buffer_[i]=='\0');i++)
    {
        str1->buffer_[i]=argv[i];
        if(str1.buffer_==' ')
        {
            str1.buffer_[i]='\0';
            break;
        }
    }

    z =  calc();

    for(int j=0;!(str2.buffer_[j]=='\0');j++, i++)
    {
        str2->buffer_[j]=argv[i];
    }
    iostream<<"String 1: "<<str1;
    iostream<<"String 2: "<<str2;

    iostream<<"String 1 Length 1: "<<length(str1);
    iostream<<"String 2 Length 2: "<<lenghth(str2);

    return 0;
}
