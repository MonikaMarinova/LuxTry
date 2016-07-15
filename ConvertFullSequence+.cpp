#include <iostream>

void sequenceFunc();
void displaying(int sequence[]);

int inputSequence  [32] = {480, 272, 224, 16252928, 50593792, 33685504, 67239936, 67174400, 33587200, 16809984, 16973824, 8650752, 7864320, 0};
int outputSequence [32];

int main() //*************** FULL TASK ***************
{
    sequenceFunc();
    displaying(inputSequence);
    std::cout<<"\n";
    displaying(outputSequence);
}

void sequenceFunc()
{
    for(int i=0; i<32; i++)
    {
        outputSequence[i] = inputSequence[i];
    }
    for(int i=0; i<32; i++)
    {
        int flag=0;
        int temp;
        int marker=0;
        bool a;
        for(int check=268435456; check>0; check/=2) //
        {
            a=(((outputSequence[i])&check)==check);
            if(flag==1 && a==true) //Checks last bit
            {
                for(; a==true;) //Checks for repeats
                {
                    (outputSequence[i])=(outputSequence[i])^check;
                    check/=2;
                    a=(((outputSequence[i])&check)==check);
                }
                flag=2;
            }
            else if(flag==1 && marker==0 && a==false) //Convert zeroes, between 1, to 1
            {
                (outputSequence[i])=(outputSequence[i])|check;
                if(check==1)//secure!
                    (outputSequence[i])=(outputSequence[i])&0;
            }
            if(a==true && flag!=2) //Finds first bit
            {
                for(; a==true; check/=2) //Checks for repeats
                {
                    a=(((outputSequence[i])&check)==check);
                    (outputSequence[i])=(outputSequence[i])^check;
                }
                check*=2;
                for(temp=check; a==false; check/=2) //Checks for "..1111.." cases
                {
                    a=(((outputSequence[i])&check)==check);
                    if(check<=0) // Solutions for "..1111.." cases
                    {
                        (outputSequence[i])=(outputSequence[i])&0;
                        marker=1;
                        break;
                    }
                }
                if(marker==1) //Breaks when case is like"..1111.."
                {
                    break;
                }
                check*=2;
                flag=1;
            }
        }
    }
}

void displaying(int sequence[])
{
    for(int i=0; i<32 ; i++)
    {
        std::cout<<sequence[i];
        if(sequence[i]<10000000)
        {
            std::cout<<"\t\t";
        }
        else if(sequence[i]<100000000)
            std::cout<<"\t";
        for(int c=268435456; c>0; c/=2) //
        {
            if((sequence[i]&c)==c)
                std::cout<<1;
            else
                std::cout<<".";
        }
        std::cout<<"\n";
    }
}
