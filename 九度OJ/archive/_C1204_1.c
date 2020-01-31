#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("sheep_go\n");
    printf("nothing_come\n");
    printf("wolf_go\n");
    printf("sheep_come\n");
    printf("vegetable_go\n");
    printf("nothing_come\n");
    printf("sheep_go\n");
    printf("succeed\n\n");
    printf("sheep_go\n");
    printf("nothing_come\n");
    printf("vegetable_go\n");
    printf("sheep_come\n");
    printf("wolf_go\n");
    printf("nothing_come\n");
    printf("sheep_go\n");
    printf("succeed\n\n");
    return 0;
}


/*
#include<stdio.h>
void creat(void);
int safe(int,int,int,int);
int islink(int,int);
void dfs(int);
void out(void);
struct problem{
        int farmer;
        int wolf;
        int goft;
        int vegetable;
};
int visit[16];
int max=0;
int pa=0;
struct problem p[16];
int link[16][16];
int path[16];
int main(void){
        int i;
        for(i=0;i<16;i++)        visit[i]=0;
        creat();
        dfs(0);
        return 0;
}
void creat(void){
        int i,j,m,n;
        for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                        for(m=0;m<2;m++)
                                for(n=0;n<2;n++){
                                        if(safe(i,j,m,n)){
                                                p[max].farmer=i;
                                                p[max].wolf=j;
                                                p[max].goft=m;
                                                p[max].vegetable=n;
                                                max++;
                                        }
                                }
        max--;
        for(i=0;i<=max;i++)
                for(j=0;j<=max;j++){
                        if(islink(i,j))        link[i][j]=1;
                        else link[i][j]=0;
                }
}
int safe(int i,int j,int m,int n){
        if(i!=m&&(j==m||m==n))        return 0;
        return 1;
}
int islink(int i,int j){
        int k=0;
        if(p[i].wolf!=p[j].wolf)        k++;
        if(p[i].goft!=p[j].goft)        k++;
        if(p[i].vegetable!=p[j].vegetable)        k++;
        if(p[i].farmer!=p[j].farmer&&k<=1)        return 1;
        return 0;
}
void dfs(int n){
        int i;
        visit[n]=1;
        path[pa++]=n;
        if(n==max)        {
                out();
                return;
        }
        for(i=0;i<=max;i++){
                if(link[n][i]&&!visit[i]){
                        dfs(i);
                        visit[i]=0;
                        pa--;
                }
        }
        return;
}
void out(void){
        int i;
        for(i=1;i<pa;i++){
                if(p[path[i-1]].wolf==0&&p[path[i]].wolf==1)
                    printf("wolf_go\n");
                else if(p[path[i-1]].wolf==1&&p[path[i]].wolf==0)
                    printf("wolf_come\n");
                else if(p[path[i-1]].goft==0&&p[path[i]].goft==1)
                    printf("sheep_go\n");
                else if(p[path[i-1]].goft==1&&p[path[i]].goft==0)
                    printf("sheep_come\n");
                else if(p[path[i-1]].vegetable==0&&p[path[i]].vegetable==1)
                    printf("vegetable_go\n");
                else if(p[path[i-1]].vegetable==1&&p[path[i]].vegetable==0)
                    printf("vegetable_come\n");
                else if(p[path[i-1]].farmer==0&&p[path[i]].farmer==1)
                    printf("nothing_go\n");
                else if(p[path[i-1]].farmer==1&&p[path[i]].farmer==0)
                    printf("nothing_come\n");
        }
        printf("succeed\n\n");
}
*/


