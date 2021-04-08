#include <stdio.h>
#define N 4
#define M 5
int main()
{
    double matriz[N][M];
    int f,c;
    for (f=0;f<N;f++){
        for (c=0;c<M;c++){
            printf("%1f ",matriz[f][c]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}