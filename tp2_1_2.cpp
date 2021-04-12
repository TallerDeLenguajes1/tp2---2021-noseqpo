#include <stdio.h>
#define N 4
#define M 5
int main()
{
    double matriz[N][M]; 
    int f,c;
    double* p;
    p=&matriz[0][0];
    for (f=0;f<N;f++){
        for (c=0;c<M;c++){
            printf("%1f ",p+f);
        }
        // Qué esta pasando aqui? Creeria que con la delcaracion de "p" nos ubicamos al inicio de nuestra matriz, luego recorremos la matriz usando solamente "f" ya que nos movera c*f veces nestro puntero, que es justamente la cantidad de elementos que tiene nuestra matriz
        printf("\n");
    }
    getchar();
    return 0;
}