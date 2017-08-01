#include<stdio.h>
#include <stdlib.h>
char r[3][3]={'_','_','_','_','_','_','_','_','_',};

void input1()
{
    int x,y;
    scanf("%d %d",&x,&y);
    if((r[x][y]=='O' || r[x][y]=='X') || x>2 || y>2)
        {
            printf("Invalid Move...Enter again!!\n");
            input1();
        }
    else
    {
        r[x][y]='X';
    }
}
void input2(int c)
{
        int i,j;
        scanf("%d%d",&i,&j);
        if((r[i][j]=='O' || r[i][j]=='X') || i>2 || j>2)
        {
            printf("Invalid Move...Enter again!!\n");
            input2(c);
        }
        else
        {
            if(c%2==0)
                r[i][j]='O';
            else
                r[i][j]='X';
        }
}
void print()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%c ",r[i][j]);
        printf("\n");
    }
}
void computer(int i)
{
    int x,y;
    if(i==0)
    {
        x=rand() % 3;
        y=rand() % 3;
        if(r[x][y]!='X')
            r[x][y]='O';
        else
            computer(i);
    }
    else
    {
        int j=0;

        for(i=0;i<3;i++)
        {
            if(r[i][j]==r[i][j+1] && r[i][j]=='O' && r[i][j+2]!='X' && r[i][j+2]!='O')
                {
                    r[i][j+2]='O';
                    return;
                }
            else
                if(r[i][j]==r[i][j+2] && r[i][j]=='O' && r[i][j+1]!='X' && r[i][j+1]!='O')
                    {
                        r[i][j+1]='O';
                        return;
                    }
                else
                    if(r[i][j+2]==r[i][j+1] && r[i][j+2]=='O' && r[i][j]!='X' && r[i][j]!='O')
                        {
                            r[i][j]='O';
                            return;
                        }
        }
        i=0;
        for(j=0;j<3;j++)
        {
            if(r[i][j]==r[i+1][j] && r[i][j]=='O' && r[i+2][j]!='X' && r[i+2][j]!='O')
                {
                    r[i+2][j]='O';
                    return;
                }
            else
                if(r[i][j]==r[i+2][j] && r[i][j]=='O' && r[i+1][j]!='X' && r[i+1][j]!='O')
                    {
                        r[i+1][j]='O';
                        return;
                    }
                else
                    if(r[i+2][j]==r[i+1][j] && r[i+1][j]=='O' && r[i][j]!='X' && r[i][j]!='O')
                        {
                            r[i][j]='O';
                            return;
                        }
        }
        if(r[i][i]==r[i+1][i+1] && r[i][i]!='O' && r[i+2][i+2]!='X' && r[i+2][i+2]!='O')
            {
                r[i+2][i+2]='O';
                return;
            }
        else
            if(r[i][i]==r[i+2][i+2] && r[i][i]!='O' && r[i+1][i+1]!='X' && r[i+1][i+1]!='O')
                {
                    r[i+1][i+1]='O';
                    return;
                }
            else
                if(r[i+1][i+1]==r[i+2][i+2] && r[i+1][i+1]!='O' && r[i][i]!='X' && r[i][i]!='O')
                    {
                        r[i][j]='O';
                        return;
                    }
        if(r[2][0]==r[1][1] && r[1][1]!='O' && r[0][2]!='X' && r[0][2]!='O')
            {
                r[0][2]='O';
                return;
            }
        else
            if(r[1][1]==r[0][2] && r[1][1]!='O' && r[2][0]!='X' && r[2][0]!='O')
                {
                    r[2][0]='O';
                    return;
                }
            else
                if(r[2][0]==r[0][2] && r[2][0]!='O' && r[1][1]!='X' && r[1][1]!='O')
                    {
                        r[1][1]='O';
                        return;
                    }
        j=0;
        for(i=0;i<3;i++)
        {


                if(r[i][j]==r[i][j+1] && r[i][j]!='_')
                    {
                        if(r[i][j+2]!='X' && r[i][j+2]!='O')
                        {
                            r[i][j+2]='O';
                            return;
                        }
                    }
                else
                    if(r[i][j]==r[i][j+2] && r[i][j]!='_')
                        {
                            if(r[i][j+1]!='X' && r[i][j+1]!='O')
                            {
                                r[i][j+1]='O';
                                return;
                            }
                        }
                    else
                        if(r[i][j+2]==r[i][j+1] && r[i][j+1]!='_')
                            {
                                if(r[i][j]!='X' && r[i][j]!='O')
                                {
                                    r[i][j]='O';
                                    return;
                                }
                            }

        }
        i=0;
        for(j=0;j<3;j++)
            {
                if(r[i][j]==r[i+1][j] && r[i][j]!='_')
                {   if(r[i+2][j]!='X' && r[i+2][j]!='O')
                        {
                            r[i+2][j]='O';
                            return;
                        }
                }
                else
                    if(r[i][j]==r[i+2][j] && r[i][j]!='_')
                        {
                            if(r[i+1][j]!='X' && r[i+1][j]!='O')
                            {
                                r[i+1][j]='O';
                                return;
                            }
                        }
                    else
                        if(r[i+1][j]==r[i+2][j] && r[i+2][j]!='_')
                            {
                                if(r[i][j]!='X' && r[i][j]!='O')
                                {
                                    r[i][j]='O';
                                    return;
                                }
                            }
            }

        if(r[i][i]==r[i+1][i+1] && r[i][i]!='_' && r[i+2][i+2]!='X' && r[i+2][i+2]!='O')
            {
                r[i+2][i+2]='O';
                return;
            }
        else
            if(r[i][i]==r[i+2][i+2] && r[i][i]!='_' && r[i+1][i+1]!='X' && r[i+1][i+1]!='O')
                {
                    r[i+1][i+1]='O';
                    return;
                }
            else
                if(r[i+1][i+1]==r[i+2][i+2] && r[i+1][i+1]!='_' && r[i][i]!='X' && r[i][i]!='O')
                    {
                        r[i][j]='O';
                        return;
                    }
        if(r[2][0]==r[1][1] && r[1][1]!='_' && r[0][2]!='X' && r[0][2]!='O')
            {
                r[0][2]='O';
                return;
            }
        else
            if(r[1][1]==r[0][2] && r[1][1]!='_' && r[2][0]!='X' && r[2][0]!='O')
                {
                    r[2][0]='O';
                    return;
                }
            else
                if(r[2][0]==r[0][2] && r[2][0]!='_' && r[1][1]!='X' && r[1][1]!='O')
                    {
                        r[1][1]='O';
                        return;
                    }
        x=rand() % 3;
        y=rand() % 3;
        if(r[x][y]!='X')
            r[x][y]='O';
        else
            computer(i);
    }
}
int check()
{
    int d=0,k,i,j;
    for(i=0;i<3;i++)
    {
        k=r[i][0];
        for(j=1;j<3;j++)
            if(k==r[i][j])
                if(r[i][j]!='_')
                    d++;
        if(d==2)
            return 1;
        else d=0;
    }
    for(j=0;j<3;j++)
    {
        k=r[0][j];
        for(i=1;i<3;i++)
            if(k==r[i][j])
                if(r[i][j]!='_')
                    d++;
        if(d==2)
            return 1;
        else
            d=0;
    }
    k=r[0][0];
    for(i=1;i<3;i++)
        if(k==r[i][i])
            if(r[i][i]!='_')
                d++;
    if(d==2)
        return 1;
    else
        d=0;
    k=r[2][0];
    for(i=1,j=1;j<3;i--,j++)
        if(k==r[i][j])
            if(r[i][j]!='_')
                d++;
    if(d==2)
        return 1;
    else
        d=0;
}
void main()
{

    char s[20];
    int i,d,j,f,n,k=0,c,p=0,q=0;
    char x[10],y[10];
    printf("Enter 1 to play Vs Computer....\nEnter 2 to play Vs Human......\nEnter Choice:");
    scanf("%d",&n);
    if(n==1)
    {

        printf("Enter name of Player:");
        scanf("%s",s);
        print();
        for(i=0;i<10;i++)
        {
            k=0;
            printf("Enter your move:");
            input1();
            print();
            if(check()==1)
            {
                printf("..........%s win..........!!!!",s);
                return;
            }
            printf("Computer's Turn:-\n");
            computer(i);
            print();
            if(check()==1)
            {
                printf("..........Computer wins..........!!!!");
                return;
            }

                    for(f=0;f<3;f++)
                        for(j=0;j<3;j++)
                            if(r[f][j]!='_')
                                k++;
            if(k==9)
            {
                printf("........Match is a DRAW.....!!!!");
                return;
            }
        }
    }
    else
    {
        printf("Enter name of Player 1:");
        scanf("%s",x);
        printf("Enter name of Player 2:");
        scanf("%s",y);
        print();
        for(c=1;c<=9;c++)
    {
        if(c%2==0)
        {
            printf("%s's turn",y);
            input2(c);
            p=check();
            print();
            if(p==1)
            {
                printf(".............%s Wins...............!!\n",y);
                exit(0);
            }
        }
        else
        {
            printf("%s's turn",x);
            input2(c);
            q=check();
            print();
            if(q==1)
            {
                printf("...............%s Wins............!!\n",x);
                exit(0);
            }
        }
    }
    printf("Match is a DRAW!!!");
    }
}
