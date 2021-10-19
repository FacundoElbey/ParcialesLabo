#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parcial1.h"
#define TRUE 1
#define FALSE 0
#define TAMCLIENTES 1000
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

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int iniciarClientes(Clientes* listaDeClientes, int tam)
{
	int retorno =  -1;
	int i;
	if(listaDeClientes != NULL)
	{
		retorno = 0;
		for(i=0; i<tam; i++)
		{
			listaDeClientes[i].isEmpty = TRUE;
		}
	}
	return retorno;
}

/***
 * \fn int getEmptyIndex(Employee*, int)
 * \brief Busca un ID automicaticamente y lo devuelve
 *
 * \param listaClientes el array de clientes
 * \param tam la cantidad de clientes
 * \return retorna -1 como error y sino retorna el ID
 */
int buscarIndiceDisponible(Clientes* listaDeClientes,int tam)
{
	int retorno = -1;
	int i;
	if(listaDeClientes != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaDeClientes[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int altaCliente(Clientes* listaDeClientes, int tam, int* id, int indice)
{
	int retorno = -1;
	Clientes bufferCliente;

	if(listaDeClientes != NULL && indice < tam && id != NULL)
	{
		if(PedirString("\nIngrese el nombre de la empresa: ",bufferCliente.nombreEmpresa) == 0 &&
			PedirString("\nIngrese la dirección del cliente: ", bufferCliente.direccion) == 0 &&
			PedirString("\nIngrese la localidad del cliente: ", bufferCliente.localidad) == 0 &&
			utn_getNumero(&bufferCliente.cuit, "\nIngrese el cuit del cliente: ", "\nError.", 0, 9999999, 5) == 0)
		{
			retorno = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = FALSE;
			listaDeClientes[indice] = bufferCliente;
			printf("\nEl Cliente fue dado de alto con el ID: %d", listaDeClientes[indice].id);
			*id = *id + 1;
		}
		else
		{
			printf("\nEl Cliente no fue dado de alta por un error inesperado.");
		}
	}
    return retorno;
}

int imprimirCliente (Clientes* pCliente)
{
	int retorno = -1;

	if(pCliente != NULL && pCliente->isEmpty == FALSE)
	{
		retorno = 0;
		printf("\nID: %d - NOMBRE EMPRESA: %s - DIRECCION: %s - LOCALIDAD: %s - CUIT: %d", pCliente->id, pCliente->nombreEmpresa, pCliente->direccion, pCliente->localidad, pCliente->cuit);
	}
	return retorno;
}

void mostrarListaClientes (Clientes* listaClientes, int tamanio)
{

    for(int i = 0 ; i < tamanio ; i++){
        if(listaClientes[i].isEmpty == FALSE){
        	imprimirCliente(&listaClientes[i]);
        }


    }
}
int modificarCliente (Clientes* listaDeClientes, int tam)
{
    int IdCliente;
    int opcion;
    int retorno = -1;


    mostrarListaClientes(listaDeClientes, tam);

    IdCliente = PedirEntero("\nIngrese el ID del cliente a modificar: ");


      for(int i = 0 ; i < tam ; i++)
      {

        if(listaDeClientes[i].isEmpty != TRUE && listaDeClientes[i].id == IdCliente)
        {
        	retorno = 0;
        	do
        	{
        		if(utn_getNumero(&opcion, "\nIngrese lo que desea cambiar.\n1)Dirección.\n2)Localidad.\n3)Salir.\nIngrese una opción: ", "\nNo es una opción válida\n", 1,3,4) == 0)
        		{
        			switch(opcion)
        			{
        			case 1:
        				utn_getNombre(listaDeClientes[i].direccion, 51, "\nIngrese la direccion del cliente: ", "\nDirección inválida.",2);
        				break;
        			case 2:
        				utn_getNombre(listaDeClientes[i].localidad, 51, "\nIngrese la localidad del cliente: ", "\nLocalidad inválida.",2);
        				break;
        			case 3:
        				break;
        			}
        		}
        	} while (opcion != 3);
        }
      }
   return retorno;
}

int bajaCliente(Clientes* listaDeClientes, int tam, int id)
{
	int retorno = -1;
	int opcion;
		if(utn_getNumero(&opcion, "\n¿Seguro que desea dar de baja este cliente?\n1)Sí.\n2)No.", "\nError.", 1,2,4) == 0)
			{
			switch(opcion)
				{
				case 1:
					for(int i = 0 ; i < tam ; i++)
						{

							if(listaDeClientes[i].isEmpty != TRUE && listaDeClientes[i].id == id)
							{
								listaDeClientes[i].isEmpty = TRUE;
								retorno = 0;
								break;
							}
						}
					break;
			case 2:
				retorno = -1;
				break;
				}
			}

    return retorno;
}
