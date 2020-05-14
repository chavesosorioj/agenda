/*
 ============================================================================
 Name        : ejer8.c
 Author      : 
 Version     :1) Realizar una agenda para guardar los datos de hasta
200 personas de las cuales se toman los siguientes datos
(utilizar una estructura para representar a la persona.):
Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas, bajas
y modificaciones (ABM) de una agenda.
b- Mostrar un listado ordenado por apellido
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define  QTY_PERSONAS 5

typedef struct{
	char nombre[50];
	char apellido[50];
	int legajo;
}Persona;

int buscarPrimerOcurrencia(Persona arrayPersonas[], int cantidad_de_elementos, int valor);
void inicializarArrayInt(Persona arrayPersonas[], int cantidad_de_elementos, int valor);

int main(void) {

	Persona arrayPersonas[QTY_PERSONAS];
	Persona auxiliarCliente;

	//array paralelos donde se guardará la información
	char auxArrayNombresSrt[50];
	char auxArrayApellidosStr[50];
	char auxArrayLegajosStr[50];
	int	auxLegajo;


	int indiceLugarLibre;
	int indiceResultadoBusqueda;
	int opcion=0;
	int i,j;

	inicializarArrayInt(arrayPersonas, QTY_PERSONAS, -1);// indica con -1 que la posición está vacía

	while(opcion != 6)
	{	opcion =getInt("\n1- ALTA \n 2- BAJA\n 3- MODIFICACION\n 4- LISTAR \n 5- ORDENAR \n 6- SALIR");
		switch(opcion)
		{
			case 1:
				indiceLugarLibre = buscarPrimerOcurrencia(arrayPersonas, QTY_PERSONAS, -1);
				if(indiceLugarLibre == -1)
				{
					printf("No hay lugares libres\n");
					break;
				}
				printf("\n ALTA\n");
				if(!getStringLetras("Ingrese un nombre: ", auxArrayNombresSrt))
				{
					printf("El nombre debe estar compuesto por letras");
					break;
				}
				if(!getStringLetras("Ingrese el apellido: ", auxArrayApellidosStr))
				{
					printf("El apellido debe estar compuesto por letras");
					break;
				}
				if(!getStringNumeros("Ingrese el número de legajo", auxArrayLegajosStr))
				{
					printf("El legajo debe estar compuesto por numeros");
					break;
				}

				auxLegajo = atoi(auxArrayLegajosStr);
				if((buscarPrimerOcurrencia(arrayPersonas, QTY_PERSONAS, auxLegajo)) != -1)
				{
					printf("Ese número de legajo ya existe");
					break;
				}

				strcpy(arrayPersonas[indiceLugarLibre].nombre, auxArrayNombresSrt);
				strcpy(arrayPersonas[indiceLugarLibre].apellido,auxArrayApellidosStr);
				arrayPersonas[indiceLugarLibre].legajo = auxLegajo;

					break;

				case 2:
				if(!getStringNumeros("Ingrese el número de legajo a dar de baja", auxArrayLegajosStr))
				{
					printf("El legajo debe estar compuesto por numeros");
					break;
				}

				indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas, QTY_PERSONAS, atoi(auxArrayLegajosStr));
				if(indiceResultadoBusqueda == -1)
				{
					printf("Ese numero de legajo no existe");
					break;
				}
				arrayPersonas[indiceResultadoBusqueda].legajo = -1;
				break;

			case 3:
				if(!getStringNumeros("Ingrese el número de legajo a modificar", auxArrayLegajosStr))
				{
					printf("El legajo debe estar compuesto por numeros");
					break;
				}

				indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas, QTY_PERSONAS, atoi(auxArrayLegajosStr));
				if(indiceResultadoBusqueda == -1)
				{
					printf("Ese numero de legajo no existe");
					break;
				}
				if(!getStringLetras("Ingrese un nombre: ", auxArrayNombresSrt))
				{
					printf("El nombre debe estar compuesto por letras");
					break;
				}
				if(!getStringLetras("Ingrese el apellido: ", auxArrayApellidosStr))
				{
					printf("El apellido debe estar compuesto por letras");
					break;
				}
				strcpy(arrayPersonas[indiceResultadoBusqueda].nombre, auxArrayNombresSrt);
				strcpy(arrayPersonas[indiceResultadoBusqueda].apellido,auxArrayApellidosStr);
				break;

			case 4:
				printf("\n Listar\n");

				for(i=0 ; i < QTY_PERSONAS; i++)
				{
					if(arrayPersonas[i].legajo != -1)
					{
						printf("\n %s - %s - %d", arrayPersonas[i].nombre, arrayPersonas[i].apellido, arrayPersonas[i].legajo);
					}
				}

				break;
			case 5:
				printf("\n ORDENADO \n");

				for(i=0;i<QTY_PERSONAS;i++)
				{
					if(arrayPersonas[i].legajo == -1)
					{
						continue;
					}
					for(j=i+1;j<QTY_PERSONAS;j++)
					{
						if(arrayPersonas[j].legajo == -1)
						{
							continue;
						}
						if(strcmp(arrayPersonas[i].apellido,arrayPersonas[j].apellido)>0)
						{
							auxiliarCliente = arrayPersonas[j];
							arrayPersonas[j]= arrayPersonas[i];
							arrayPersonas[i] = auxiliarCliente;
						}
					}

				}

				break;
		}// se supone que este es el switch
	}//while
	return EXIT_SUCCESS;
}

/*
 * brief Inicializa un array de enteros	con el valor recibido
 * param array Es el Array a ser inicializado
 * param cantidad_de_elementos indica longitud de array
 * param valor Es el valor que será cargado en cada posiciones
 * return -
 */
void inicializarArrayInt(Persona arrayPersonas[], int cantidad_de_elementos, int valor)
{
	int i;
	for(i=0; i<cantidad_de_elementos;i++)
	{
		arrayPersonas[i].legajo=valor;
	}
}
/*
 * brief Busca la primer ocurrencia de un valor en un array de enteros
 * param array Es el Array a ser inicializado
 * param cantidad_de_elementos indica longitud de array
 * param valor Es el valor que será cargado en cada posiciones
 * return -
 */
int buscarPrimerOcurrencia(Persona arrayPersonas[], int cantidad_de_elementos, int valor)
{	int i;
	for(i=0; i<cantidad_de_elementos;i++)
	{
		if(arrayPersonas[i].legajo == valor)
		{
			return i;
		}
	}
	return -1;
}

