/*
 ============================================================================
 Name        : Parcial_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parcial1.h"
#include "Clientes.h"
#include "Pedidos.h"
#define TAMCLIENTES 100
#define TAMPEDIDOS 1000

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int indiceLibre;
	int indiceLibreParaPedidos;
	int idCliente = 0;
	int idBajaCliente;
	int idPedidoCliente;
	int cantidadKilos;
	int idPedido = 0;
	Clientes listadeClientes[TAMCLIENTES];
	Pedidos listadePedidos[TAMPEDIDOS];

	if(iniciarClientes(listadeClientes,TAMCLIENTES) == -1)
	{
		printf("\nError en la inicialización de la lista de Clientes!");
	}

	do
		{
		if(utn_getNumero(&opcion, "\nSeleccione una opción\n1) Alta de Cliente.\n2) Modificar Cliente.\n3) Dar de Baja un Cliente.\n4) Crear pedido de recolección.\n5) Salir.\n\nIngrese la opción: ", "\nNo es una opción válida\n", 1,5,4) == 0)
			        {
			            switch(opcion)
			            {
			                case 1:
			                	indiceLibre = buscarIndiceDisponible(listadeClientes,TAMCLIENTES);
			                	if(indiceLibre >= 0 && listadeClientes != NULL && indiceLibre < TAMCLIENTES)
			                	{
			                		if(altaCliente(listadeClientes, TAMCLIENTES, &idCliente,indiceLibre) == 0)
			                		{
			                			continue;
			                		}
			                	}
			                    break;
			                case 2:
			                	if(modificarCliente (listadeClientes, TAMCLIENTES) == 0)
								{
			                		continue;
								}
			                	break;
			                case 3:
			                	 mostrarListaClientes(listadeClientes, TAMCLIENTES);
			                	 if (utn_getNumero(&idBajaCliente, "\nIngrese el id del cliente: ", "\nEl id es inválido.", 0, 100,2) == 0 &&
			                			 bajaCliente(listadeClientes, TAMCLIENTES, idBajaCliente) == 0	)
			                	 		{
			                	 		 printf("\nSe realizó la baja del empleado.\n");
			                	 		}
			                	 		 else
			                	 		{
			                	 		 printf("\nNo se pudo realizar la baja del empleado.\n");
			                	 		}
			                	break;
			                case 4:
			                	 mostrarListaClientes(listadeClientes, TAMCLIENTES);
			                	 indiceLibreParaPedidos = buscarIndiceDisponiblePedidos(listadePedidos,TAMPEDIDOS);
			                	 if(indiceLibreParaPedidos >= 0 && listadePedidos != NULL && indiceLibreParaPedidos < TAMPEDIDOS)
			                	 {
			                		 utn_getNumero(&idPedidoCliente, "\nIngrese el id del cliente: ", "\nEl id es inválido.", 0, 1000,2);
			                		 utn_getNumero(&cantidadKilos, "\nIngrese la cantidad de kilos que se recolectarán del cliente: ", "\nLa cantidad es inválida.", 0, 1000,2);;
			                		 if(altaPedido(listadePedidos, TAMPEDIDOS, &idPedido,indiceLibre) == 0)
			                		 {
			                			 printf("\nSe realizó el pedido de recolleccion.\n");
			                		 }
			                		 else
			                		{
			                			 printf("\nNo se pudo realizar el pedido de recolleccion por un error inesperado.\n");
			                		}
			                	 }
			                	 break;
			                case 5:
			                    break;
			            }
		             }
				    } while (opcion != 5);
	return EXIT_SUCCESS;
}
