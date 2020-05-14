/*
 * ejerUtn.h
 *
 *  Created on: Apr 14, 2020
 *      Author: juliana
 */

#ifndef UTN_H_
#define UTN_H_

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
char getNumeroAleatorio(int desde, int hasta, int iniciar);
int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfanumerico(char str[]);
int esSoloLetras(char str[]);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);
void getString(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);
int getStringNumeros(char mensaje[], char input[]);
//void inicializarArrayInt(int array[], int cantidad_de_elementos, int valor);

#endif /* UTN_H_ */
