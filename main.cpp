#include <iostream>

int main()
{

    int step, n;
    std::cout<<"Please input number of numbers: ";
    std::cin>>n;
    std::cout<<"Please input step ";
    std::cin>>step;
    int numbers[n];
    unsigned char convertedNumbers[8*n];
    for(int i=0; i<n ;i++)
    {
        std::cout<<"Please input number "<<i+1<< " ";
        std::cin>>numbers[i];
    }
    for(int j=0, i=0;j<n;j++)
    {
        for(int c=128;c>0;c/=2, i++)
        {
            convertedNumbers[i]=((numbers[j]&c)==c);
        }
    }
    for(int i=0; i<n*8; i+=step)
    {
        if(convertedNumbers[i]==0)
            convertedNumbers[i]=1;
        else
            convertedNumbers[i]=0;
    }
    /*
    for(int i=0; i<n*8; i++)
        std::cout<<(int)convertedNumbers[i];
    std::cout<< std::endl;
    */
    /*
    int allConvertedNumbers[n][8];
    for (int i=0, j=0, c=0; j<n; i++, c++)
    {
        allConvertedNumbers[j][i]=convertedNumbers[c];
        if(i==7)
        {
            i=0;
            j++;
        }
    }
    */
    unsigned char answear[n];
    unsigned char b;
    for(int j=0; j<n; j++)
    {
        answear[j]=0;
        b= 0x80;
        for(int i=0; i < 8; i++)
        {
            answear[j] += convertedNumbers[j*8+i]*b;
            //std::cout<< (int)convertedNumbers[i] <<" : "<< (int)b <<std::endl;
            b = b >> 1;
        }

    }
    for(int i=0; i<n; i++)
    {
        std::cout<<(int)answear[i]<<std::endl;
    }
    return 0;
}
