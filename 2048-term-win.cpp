#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct point {
    int i;
    int j;
    int val;
};
int full(int v[6][6], int i) //ferify if a row is full
{
    for(int j = 1; j < 5; ++j)
        if(v[i][j] == 0)
            return 0;
    return 1;
}

int table_full(int v[6][6]) //verify if the table is full
{
    for(int i = 1; i < 5; ++i)
        if(full(v, i)==0) return 0;
            return 1;
}
void show(int v[6][6])
{
    for(int i = 1; i < 5; ++i)
    {
        for(int j = 0; j < 6; ++j)
            cout<<v[i][j]<<" ";
        cout<<'\n';
    }
}
void box_gen(int v[6][6])
{
    int i, j, val;

    //generate random i coord for empty row
    do{
        i = rand()%4+1;
    }while (full(v, i) == 1);

    //generate random j coordinate on empty position
    do{
        j = rand()%4+1;
    }while (v[i][j] != 0);

    v[i][j]=2;
}
int main()
{
    int v[6][6]={0};
    {
        for(int i=0; i<6; ++i)
        {
            v[5][i]=-1;
            v[i][5]=-1;
            v[i][0]=-1;
            v[0][i]=-1;
        }
    }
    int index=0;
    srand (time(NULL));
    //start_screen();
    while(!table_full(v))
    {
        index++;
        box_gen(v);
        show(v);
        cout<<endl;
    }
}
