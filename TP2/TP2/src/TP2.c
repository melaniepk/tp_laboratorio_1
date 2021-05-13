/*
 1 Enunciado
Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
Datos:

El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n empleado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn1.h"
#include "ArrayEmployees.h"

#define TAM 3

int main(void) {

	setbuf(stdout, NULL);
	int banderaDeCompletado = 0;
	int opcion;
	int retorno;
	Employee listaEmpleados[TAM];
	int idEncontrado;

	int numeroId;
	int mostrarLista;
	int id=0;
	int criterio;
	initEmployees(listaEmpleados, TAM);
	int IdIncremental;

	do{
		utn_getNumero(&opcion, "\nMenu de opciones: \n1. Alta Empleado.\n2. Baja Empleado.\n3. Modificar empleado."
				" \n4. Listado de empleados ordenados alfabeticamente y por sector.\n"
				"5. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n"
				"6.Salir del menu.\nSeleccione alguna de las opciones desplegadas anteriormente:\n", "ERROR! opcion invalida", 1,6,2);

		switch(opcion)
		{
		case 1:
			IdIncremental = IncrementarId(&id);
			retorno = altaEmpleado(listaEmpleados, TAM, IdIncremental);
			if(retorno != -1)
			{
				printf("Empleado cargado exitosamente! Si desea a�adir otro empleado pulse 1\n");
				banderaDeCompletado = 1;
			}
			else
			{
				printf("No hay mas lugar!\n");
			}

			break;
		case 2:
			if(banderaDeCompletado != 1)
			{
				printf("ERROR. Primero debe ingresar empleado/s\n");
			}
			else
			{
				mostrarLista = printEmployees(listaEmpleados,TAM);
				if(mostrarLista == 0)
				{
					utn_getNumero(&numeroId,"Ingrese el ID del empleado que desea eliminar\n","Error, ID no existente\n",0,1000,10);
					idEncontrado = findEmployeeById(listaEmpleados,TAM,&numeroId);
					if(idEncontrado == -1)
					{
						printf("No se pudo encontrar a un empleado con ese ID\n");
					}
					else
					{
						retorno = removeEmployee(listaEmpleados, TAM, idEncontrado);
						if(retorno == -1 || retorno == 1)
						{
							printf("NO se elimin� correctamente al empleado\n");
						}
						else
						{
							printf("Empleado eliminado con exito!\n");
						}
					}
				}
				else
				{
					printf("NO existen empleados a eliminar\n");
				}

			}
			break;
		case 3:
			if(banderaDeCompletado != 1)
			{
				printf("ERROR. Primero debe ingresar empleado/s\n");
			}
			else
			{
				retorno = ModificarEmpleado(listaEmpleados, TAM);
				if(retorno == -1)
				{
					printf("No se pudo modificar al empleado o el ID no existe\n");
				}
				else
				{
					printf("Empleado modificado\n");
				}
			}
			break;
		case 4:
			if(banderaDeCompletado != 1)
			{
				printf("ERROR. Primero debe ingresar empleado/s\n");
			}
			else
			{
				utn_getNumero(&criterio, "Ingrese un criterio de ordenamiento descendente (0) o ascendente (1)", "ERROR. Fuera de rango", 0, 1,2);

				retorno = sortEmployees(listaEmpleados, TAM, &criterio);
				if(retorno != -1)
				{
					printEmployees(listaEmpleados,TAM);
				}

			}
			break;
		case 5:
			if(banderaDeCompletado != 1)
			{
				printf("ERROR. Primero debe ingresar empleado/s\n");
			}
			else
			{
				MostrarTotalYPromedioDeSalarios(listaEmpleados, TAM);
			}
			break;
		case 6:
			printf("Cerrando men�.\n");
			break;

		}

	}while(opcion != 6);


	return EXIT_SUCCESS;
}
