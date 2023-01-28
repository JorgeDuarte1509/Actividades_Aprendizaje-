
//Programa para sumar en paralelo deos arreglos
//Jorge Alberto Duarte Salinas
//Matricula: A01793015

//#include "pch.h"
#include <iostream>
#include <omp.h>

#define N 1000//cantidad de elementos a manejar en los arreglos
#define chunk 100// tamaño que tendran los pedazos de los arreglos para que cada hilo se encargie de la cantidad de elementos que indica
#define mostrar 5//Permite manejar esta cantidad de datos a imprimir

void imprimeArreglo(float *d);

int main()
{
	std::cout << "Sumando Arreglos en Paralelo!\n";
	float a[N], b[N], c[N];//Se declaran los arreglos a, b y c con el tamaño que definimos para N= 1000
	int i;//Se decalara la i que va a estar sumando +1 en cada ciclo for

	for (i = 0; i < N; i++)//Ciclo for, emieza con i siendo cero y menor a N, se va sumando +1 en cada iteracion
	{
		a[i] = i * 20;
		b[i] = (i + 10) * 5.7;
	}
	int pedazos = chunk;
    #pragma omp parallel for \
	shared(a, b, c, pedazos) private(i) \
	schedule(static, pedazos)
	
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);
}

void imprimeArreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}