#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parcial1.h"
#define TRUE 1
#define FALSE 0
#define NOMBRE_LEN 51

typedef struct
{
	int id;
	int tipoDePlastico;
	int estado;
	int isEmpty;
}Pedidos;

int altaPedido(Pedidos*, int, int*, int);
int buscarIndiceDisponiblePedidos(Pedidos*,int);

#endif /* PEDIDOS_H_ */
