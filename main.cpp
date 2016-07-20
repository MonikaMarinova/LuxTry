#include <iostream>

int blackboard[8][8]={0};
int availableMoves[8][2];
int count=0;
int checkPos(int y, int x);


int main()
{
    int x, y;
    availableMoves[0][0]=2;
    availableMoves[0][1]=1;
    availableMoves[1][0]=2;
    availableMoves[1][1]=-1;
    availableMoves[2][0]=1;
    availableMoves[2][1]=-2;
    availableMoves[3][0]=-1;
    availableMoves[3][1]=-2;
    availableMoves[4][0]=-2;
    availableMoves[4][1]=-1;
    availableMoves[5][0]=-2;
    availableMoves[5][1]=1;
    availableMoves[6][0]=-1;
    availableMoves[6][1]=2;
    availableMoves[7][0]=1;
    availableMoves[7][1]=2;
    y=0;
    x=4;
    blackboard[0][4]=1;
    checkPos(y, x);
    std::cout<<"Moves: "<<count<<std::endl;
    return 0;
}

int checkPos(int y, int x)
{
    int res = 0;

    for(int i=0; i<8; i++)
        //for(int j=0; j<2; j++)
        {
            if((y+availableMoves[i][1] < 8) && (y+availableMoves[i][1] >= 0) &&
               (x+availableMoves[i][0] < 8) && (x+availableMoves[i][0] >= 0))
            if(blackboard[y+availableMoves[i][1]][x+availableMoves[i][0]]!=1)
            {
                res = 1;
                count++;
                blackboard[y+availableMoves[i][1]][x+availableMoves[i][0]]=1;
                if(checkPos(y+availableMoves[i][1], x+availableMoves[i][0]) == 0)
                    blackboard[y+availableMoves[i][1]][x+availableMoves[i][0]]= 0;

            }
        }
    if(count==64)
    {
        std::cout<<"WIN!";
        return res;
    }

    return res;
}

