/*
 * Parcial1.h
 *
 *  Created on: 17 oct. 2021
 *      Author: river
 */

#ifndef PARCIAL1_H_
#define PARCIAL1_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int myGets(char* cadena, int longitud);
int PedirEntero (char mensaje[]);
float PedirFloat (char mensaje[]);
int PedirString (char mensaje[], char stringIngresado[]);

#endif /* PARCIAL1_H_ */
