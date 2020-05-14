/*
 * ejerUtn.c
 *
 *  Created on: Apr 14, 2020
 *      Author: juliana
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utn.h"
#include <string.h>
/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
 int retorno =-1;
 int bufferInt;
 while(reintentos>=0)
 {
	 printf("%s",mensaje);
	 scanf("%d",&bufferInt);
	 __fpurge();
	 if(bufferInt >= minimo && bufferInt <= maximo)
	 {
		 *pResultado = bufferInt;
		 retorno=0;
		 break; // lo de abajo no se seguiría
	 }
	 else
	 {
		 printf("%s", mensajeError);
		 reintentos--;
	 }

   }

return retorno;
}
/*
* \brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param minimo Es el numero minimo a ser aceptado
* \param maximo Es el numero maximo a ser aceptado
* \return Retorna 0 si se obtuvo el numero y -1 si no
*
*/
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}

/*
 * brief solicita un número al usuario y devuelve el resultado
 * param mensaje Es el mensaje a ser mostrado
 * return el número ingresado por el usuario
 */
int getInt(char mensaje[])
{
	int aux;
	printf("%s",mensaje);
	scanf("%d",&aux);
	return aux;
}
/*
 * brief solicita un número al usuario y devuelve el resultado
 * param mensaje Es el mensaje a ser mostrado
 * return el número ingresado por el usuario
 */
float getFloat(char mensaje[])
{
	float aux;
	printf("%s",mensaje);
	scanf("%f",&aux);
	return aux;
}
/*
 * brief solicita un caracter al usuario y devuelve el resultado
 * param mensaje Es el mensaje a ser mostrado
 * return el caracter ingresado por el usuario
 */

char getChar(char mensaje[])
{
	char aux;
	printf("%s",mensaje);
	__fpurge(stdin); // para limpiar lo que pueda venir
	scanf("%c",&aux);
	return aux;
}
/*
 * brief genera un numero aleatorio
 * param desde y hasta los parametros dentro del que se genera el numero
 * return el número aleatorio
 */

char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}
/*
 * brief Verifica si el valor es numerico
 * str Array con la cadena a analizar
 * return 1 si es numerico y 0 si no lo es
 */
/* esta es la que estaba-----
int esNumerico(char str[])
{	int i=0;
	while(str[i] != '\0')
	{
		if(str[i] <'9' || str[i] >'0')
			return 0;
		i++;
	}
	return 1;
}
*/

int esNumerico(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*
 * brief Verifica si el valor recibido es un numero telefónico
 * param str Array con la cadena a analizar
 * return 1 si es un telefon y 0 si no lo es
 */
int esTelefono(char str[])
{	int i=0;
	int contadorGuion=0;
	while(str[i] != '\0')
	{
		 if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
		       return 0;
		if(str[i]== '-')
		{
			contadorGuion++;
		}
		i++;
	}
	if(contadorGuion ==1)//debe tener un guion
		return 1;

	return 0;
}
/*
 * brief Verifica si el valor recibido contiene letras y numeros
 * param str Array con la cadena a analizar
 * return 1 si son letras y numeros o 0 si no lo son
 */
int esAlfanumerico(char str[])
{	int i=0;
	while(str[i] != '\0')
	{
		  if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
		       return 0;
		i++;
	}
	return 1;
}

/*
 * brief Verifica si el valor recibido contiene solo letras
 * param str Array con la cadena a analizar
 * return 1 si son solo letras o 0 si no lo son
 */
int esSoloLetras(char str[])
{	int i=0;
	while(str[i] != '\0')
	{
		if((str[i] !=' ') && (str[i] < 'a' || str[i]> 'z') && (str[i] < 'A' || str[i]> 'Z'))
			return 0;
		i++;
	}
	return 1;
}
/*
 * brief soslicita un texto al usuario y lo devuelve
 * param Mensaje es el mensaje a ser mostrado
 * param input es Array donde se cargara lo ingresado
 * return void
 */
void getString(char mensaje[], char input[])
{
	printf("%s",mensaje);
	scanf("%s",input);
}
/*
 * brief Solicita un texto al usuario y lo devuelve
 * param Mensaje es el mensaje a ser mostrado
 * param input Array donde se guardará lo ingresado
 * return 1 si el texto contiene solo letras y 0 si no
 */
int getStringLetras(char mensaje[], char input[])
{
	char aux[256];
	getString(mensaje, aux);
	if(esSoloLetras(aux))
	{
		strcpy(input,aux);
		return 1;
	}
	return 0;
}
/*
 * brief Solicita un texto al usuario y lo devuelve
 * param Mensaje es el mensaje a ser mostrado
 * param imput Array donde se guarda lo ingresado
 * return 1 si el texto contiene numeros y 0 si no
 */
int getStringNumeros(char mensaje[], char input[])
{
		char aux[256];
		getString(mensaje, aux);
		if(esNumerico(aux))
		{
			strcpy(input, aux);
			return 1;
		}
		return 0;
}
/*
 * brief Inicializa un array de enteros	con el valor recibido
 * param array Es el Array a ser inicializado
 * param cantidad_de_elementos indica longitud de array
 * param valor Es el valor que será cargado en cada posiciones
 * return -

void inicializarArrayInt(int array[], int cantidad_de_elementos, int valor)
{
	int i;
	for(i=0; i<cantidad_de_elementos;i++)
	{
		array[i]=valor;
	}
}
*/

