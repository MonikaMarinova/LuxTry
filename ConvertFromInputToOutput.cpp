#include <iostream>

int main() //Algorithm for converting! (case .11...1., .1....1., .1...11. and .1111...)
{
    int sequence=50593792;
    int flag=0;
    int temp;
    int marker=0;
    bool a;
    for(long long check=4294967296; check>0; check/=2) //
    {
        a=((sequence&check)==check);
        if(flag==1 && a==true) //Checks last bit
        {
            for(;a==true;/*check/=2*/) //Checks for repeats
            {
                //std::cout<<"here0";
                sequence=sequence^check;
                check/=2;
                a=((sequence&check)==check);
            }
            flag=2;
        }
        else if(flag==1 && marker==0 && a==false) //Convert zeroes, between 1, to 1
        {
            sequence=sequence|check;
            if(check==1)//secure!
                sequence=sequence&0;
            //std::cout<<"here1";

        }
        if(a==true && flag!=2) //Finds first bit
        {
           // std::cout<<"hire21 ";
            for(; a==true; check/=2) //Checks for repeats
            {
                //std::cout<<"here2";
                a=((sequence&check)==check);
                sequence=sequence^check;
            }
            check*=2;
            for(temp=check;a==false; check/=2) //Checks for "..1111.." cases
            {
                //std::cout<<"here3";
                a=((sequence&check)==check);
                if(check<=0) // Solutions for "..1111.." cases
                {
                    sequence=sequence&0;
                    marker=1;
                    break;
                }
            }
            if(marker==1) //Breaks when case is like"..1111.."
            {
                break;
            }
            check*=2;
            //sequence=sequence^check;
            flag=1;
        }
    }
    std::cout<<sequence;
}
