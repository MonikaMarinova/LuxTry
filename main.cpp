#include"string.h"

//using namespace std;

int main()
    {

     //2
     String str1 = "Hello world";
     String str2 = "Good bye";

    //3
    std::cout<<"String 1: <";
    std::cout<<str1.buffer_;
    std::cout<<">\n";
    std::cout<<"String 2: <";
    std::cout<<str2.buffer_;
    std::cout<<">";
    std::cout<<"\n";

    //4
    std::cout<<"String 1 lenght: ";
    std::cout<<str1.size();
    std::cout<<'\n';
    std::cout<<"String 2 lenght: ";
    std::cout<<str2.length();
    std::cout<<"\n";


    //5
    int countSpaces=0;
    String space = " ";
    Iterator spaceIt = space.begin();
    for(Iterator it=str1.begin();it!=str1.end();it.operator ++())
    {
       if(it.index[0]==spaceIt.index[0])
           countSpaces++;
    }
    std::cout<<"String 1 Spaces: ";
    std::cout<<countSpaces;
    std::cout<<"\n";

    countSpaces = 0;

    for(Iterator it = str2.begin(); it!=str2.end(); it.operator ++())
    {
        if(it.index[0] == spaceIt.index[0])
            countSpaces++;
    }

    std::cout<<"String 2 Spaces: ";
    std::cout<<countSpaces;
    std::cout<<"\n";

    //6
    if(str1==str2){
        std::cout<<"/<";
        std::cout<<str1.buffer_;
        std::cout<<">";
        std::cout<<"is equal to <";
        std::cout<<str2.buffer_;
        std::cout<<">";
        std::cout<<"\n";
    }
    if(str1!=str2){
        std::cout<<"<";
        std::cout<<str1.buffer_;
        std::cout<<">";
        std::cout<<"is not equal to <";
        std::cout<<str2.buffer_;
        std::cout<<">";
        std::cout<<"\n";
    }
    if(str1>str2){
        std::cout<<"<";
        std::cout<<str1.buffer_;
        std::cout<<">";
        std::cout<<"is greater than <";
        std::cout<<str2.buffer_;
        std::cout<<">";
        std::cout<<"\n";
    }
    if(str1<str2){
        std::cout<<"<";
        std::cout<<str1.buffer_;
        std::cout<<">";
        std::cout<<"is less than <";
        std::cout<<str2.buffer_;
        std::cout<<">";
        std::cout<<"\n";
    }
    //7
    std::cout<<"String 1: <";
    str1.push_back('!');
    std::cout<<">\n";\
    std::cout<<"String 2: <";
    str2.push_back('!');
    std::cout<<">";
    std::cout<<"\n";

    //8

    String str=str1.operator +(str2);

    std::cout<<"concatenation: <";
    std::cout<<str.buffer_;
    std::cout<<">";
    std::cout<<"\n";

    //9
    std::cout<<"concatenation lenght: ";
    std::cout<<str.length();
    std::cout<<"\n";

    //11
    for(unsigned int i=0;i<str.length();i++){
        if(str[i]=='!'){
            std::cout<<"Index of !: ";
            std::cout<<i;
            std::cout<<"\n";
             break;
        }
    }

    //12
    std::cout<<"Substring: <";
    str.substr(12,4);
    std::cout<<">";
    std::cout<<"\n";

        return 0;
}
//#endif

