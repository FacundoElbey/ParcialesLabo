#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parcial1.h"
#define TRUE 1
#define FALSE 0
#define PENDIENTE 2
#define COMPLETO 3
#define TAMPEDIDOS 1000

typedef struct
{
	int id;
	int tipoDePlastico;
	int estado;
	int isEmpty;
}Pedidos;

int altaPedido(Pedidos* listaDePedidos, int tam, int* id, int indice)
{
	int retorno = -1;

	if(listaDePedidos != NULL && indice < tam && id != NULL)
	{
		retorno = 0;
		listaDePedidos[indice].id = *id;
		*id = *id +1;
		listaDePedidos[indice].estado = PENDIENTE;

	}
	return retorno;
}


int buscarIndiceDisponiblePedidos(Pedidos* listaDePedidos,int tam)
{
	int retorno = -1;
	int i;
	if(listaDePedidos != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaDePedidos[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
