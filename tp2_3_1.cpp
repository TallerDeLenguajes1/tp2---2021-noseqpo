#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int suma15(int * lista){
    int total;
    for (int i=0;i<15;i++){
        total=total+lista[i];
    }
    return total;
}

void llenarAl15(int * lista){
    for(int i=0;i<15;i++){
        lista[i]=(rand () % (15-5+1) + 5);
    }
}

void llenarAleatorios(int tamanio, int * lista){
    for(int i=0;i<tamanio;i++){
        lista[i]=(rand () % (100-99+1) + 99);
    }
}

void organizador(int * listaC, int * espacio, int total){
    int pos=0;
    for (int i=0;i<15;i++){
        espacio[pos]=listaC[i];
        pos=pos+listaC[i];
        llenarAleatorios(listaC[i],espacio[pos]);
    }
}

int main(){
    srand (time(NULL));
    int tmnCs[15];
    llenarAl15(tmnCs);
    int totalNum=suma15(tmnCs);
    int * matrizIrregular = (int *) malloc(sizeof(int)*(totalNum+15));
    
    organizador(tmnCs,matrizIrregular,totalNum);

    free(matrizIrregular);
    getchar();
    return 0;
}
