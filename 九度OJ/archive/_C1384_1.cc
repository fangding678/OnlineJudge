#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int **a;
    int num;
    int row,col;
    int i,j;
    int index_row,index_col;
    bool flag;
    while(~scanf("%d%d%d",&row,&col,&num))
    {
        a = new int*[row];
        for(i=0; i<row; ++i)
        {
            *(a+i) = new int[col];
            for(j=0; j<col; ++j)
            {
                scanf("%d",&a[i][j]);
            }
        }
        flag = false;
        index_row = 0;
        index_col = col-1;
        while(index_row<row && index_col>=0)
        {
            if(a[index_row][index_col] < num)
                index_row++;
            else if(a[index_row][index_col] > num)
                index_col--;
            else
            {
                flag = true;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
        for(i=0; i<row; ++i)
            delete[] *(a+i);
        delete[] a;
    }
    return 0;
}
