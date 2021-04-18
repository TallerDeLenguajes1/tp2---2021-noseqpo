#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

struct compu {
    int velocidad;//entre 1 y 3 Gherz
    int anio;//entre 2000 y 2017
    int cantidad;//entre 1 y 4
    char *tipo_cpu;//valores del arreglo tipos
};

compu crearCompu() {
    compu unidad;
    unidad.velocidad = 1 + rand() % 3;
	unidad.anio = 2000 + rand() % 18;
	unidad.cantidad = 1 + rand() % 4;
	unidad.tipo_cpu = tipos[rand() % 6];
	return (unidad);
}

void listaCompus(int cant, compu * espacio){
    for (int i;i<cant;i++){
        espacio[i]=crearCompu();
    }
}

void imprimir(compu temp){
    printf("La velocidad de la maquina es: %d GHz\n",temp.velocidad);
    printf("El año de la maquina es: %d\n",temp.anio);
    printf("La cantidad de procesadores de la maquina es: %d\n",temp.cantidad);
    printf("El tipo de procesador de la maquina es: %s\n",temp.tipo_cpu);
    printf("\n");
}

void impCompus(int cant, compu * lista){
    for (int i;i<cant;i++){
        imprimir(lista[i]);
    }
}

void antigua(int cant, compu * lista){
    compu temp=lista[0];
    for (int i=0;i<cant;i++){
        if (temp.anio>lista[i].anio){
            temp=lista[i];
        }
    }
    printf("\nLa computadora mas antigua es: \n \n");
    imprimir(temp);
}

void rapida(int cant, compu * lista){
    compu temp=lista[0];
    for (int i=0;i<cant;i++){
        if (temp.velocidad*temp.cantidad<lista[i].velocidad*lista[i].cantidad){
            temp=lista[i];
        } // hago que elija la con mayor velocidad x cantidad de procesadores
    }
    printf("\nLa computadora mas rapida es: \n \n");
    imprimir(temp);
}

int main(){
    srand (time(NULL)); // el time(NULL) va siempre en el main xd
    int numero = 4; // por poner un numero
    compu * computadoras = (compu *) malloc(sizeof(compu) * numero);
    
    listaCompus(numero, computadoras);
    impCompus(numero,computadoras);
    antigua(numero, computadoras);
    rapida(numero, computadoras);
    
    free(computadoras);
    getchar();
    return 0;
}