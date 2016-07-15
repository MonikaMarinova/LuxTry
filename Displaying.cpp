int main() //Algorithm for displaying
{
    int sequence  [32] = {480, 272, 224, 16252928, 50593792, 33685504, 67239936, 67174400, 33587200, 16809984, 16973824, 8650752, 7864320, 0};
    int sequence1 [32] = {0, 224, 0, 0, 16252928, 33292288, 66846720, 66977792, 33488896, 16711680, 16515072, 7864320, 0, 0};
    {
        std::cout<<"Input\t\tInput as Grid\n";

        for(int i=0;i<32;i++)
        {
            std::cout<<sequence[i];
            if(sequence[i]<10000000)
            {
                std::cout<<"\t\t";
            }
            else if(sequence[i]<100000000)
                std::cout<<"\t";
            for(long check=2147483648;check>0;check/=2) //
            {

                if((sequence[i]&check)==check)
                    std::cout<<1;
                else
                    std::cout<<".";
            }
            std::cout<<"\n";
        }
    }
}
