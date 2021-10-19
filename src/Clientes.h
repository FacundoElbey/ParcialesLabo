/*
 * Clientes.h
 *
 *  Created on: 17 oct. 2021
 *      Author: river
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

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
	char nombreEmpresa[NOMBRE_LEN];
	char direccion[51];
	char localidad[51];
	int cuit;
	int isEmpty;
}Clientes;

int iniciarClientes(Clientes*, int);
int buscarIndiceDisponible(Clientes*,int);
int altaCliente(Clientes*, int, int*, int);
int imprimirCliente (Clientes*);
void mostrarListaClientes (Clientes*, int);
int modificarCliente (Clientes*, int);
int bajaCliente(Clientes*, int, int);
#endif /* CLIENTES_H_ */
