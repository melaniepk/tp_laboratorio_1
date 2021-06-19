#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn1.h"
#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo a abrir
 * \param pArrayListEmployee LinkedList* lista que cargar en el archivo
 * \return devuelve 0 si cargó, -1 si no
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int retorno = -1;

	if(path != NULL && pArrayListEmployee!= NULL)
	{
		pArchivo = fopen(path,"r");
		if(pArchivo == NULL)
		{
			printf("Error al abrir el archivo\n");
			system("pause");
		}
		else
		{
			retorno = 0;
			printf("Se ingresó al archivo exitosamente");
			parser_EmployeeFromText(pArchivo, pArrayListEmployee);
			fclose(pArchivo);

		}

	}

	controller_saveAsBinary("data.bin",pArrayListEmployee);

    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* archivo a abrir
 * \param pArrayListEmployee LinkedList* lista a leer del archivo
 * \return int devuelve 0 si cargó, -1 si no
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int retorno = -1;


	if(path!= NULL && pArrayListEmployee!= NULL)
	{
		pArchivo = fopen(path,"rb");
		if(pArchivo != NULL)
		{

			retorno = 0;
			printf("Se ingresó al archivo exitosamente");
			parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
			fclose(pArchivo);

		}
		else
		{
			printf("Error al abrir el archivo\n");
			system("pause");
		}
	}

	return retorno;
}

/** \brief Alta de empleados
 *añade un empleado a la lista
 * \param pArrayListEmployee LinkedList* lista a la que se añadira el empleado
 * \return int devuelve 0 si cargó, -1 si no
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* nuevoEmpleado;

	char id[50];
	char nombre[128];
	char horasTrabajadas[50];
	char sueldo[50];
	int seguir;
	int cantidad;


	if(pArrayListEmployee!= NULL)
	{
		do
		{
			cantidad = ll_len(pArrayListEmployee);
			sprintf(id,"%d",cantidad);
			utn_getString(nombre,sizeof(nombre),"Ingrese el nombre del empleado\n", "Error\n",5);
			utn_getString(horasTrabajadas,sizeof(horasTrabajadas),"Ingrese las horas trabajadas del empleado\n", "Error\n",5);
			utn_getString(sueldo,sizeof(sueldo),"Ingrese el sueldo del empleado\n", "Error\n",5);

			nuevoEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			ll_add(pArrayListEmployee,nuevoEmpleado);
			printf("Si desea seguir ingresando datos, ingrese 1\n");

			scanf("%d",&seguir);

		}while(seguir == 1);
		retorno = 0;
	}


    return retorno;
}

/** \brief Modificar datos de empleado
 *modifica el dato elegido en determinado empleado a partir de su id
 * \param pArrayListEmployee LinkedList* lista de empleados modificables
 * \return int 0 si se modifica, -1 si no
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int id;
	int retorno = -1;
	int respuesta;
	char nombre[128];
	float sueldo;
	int horas;
	Employee* empleado;

	printf("Si desea imprimir la lista ingrese 1\n");
	scanf("%d",&respuesta);
	if(respuesta ==1)
	{
		controller_ListEmployee(pArrayListEmployee);
	}

	utn_getNumero(&id, "Ingrese el ID del empleado a modificar","ERROR, ID no encontrado\n",1,1001,5);

	if(pArrayListEmployee!= NULL)
	{
		empleado = ll_get(pArrayListEmployee,id-1);
		do
		{
			utn_getNumero(&respuesta,"Ingrese el numero correspondiente a la opcion a modificar: \n1.Nombre\n2.Sueldo\n"
					"3.Horas trabajadas\n4.Salir\n","ERROR, la opcion ingresada no existe\n",1,3,5);

			switch(respuesta)
			{
				case 1:
					utn_getPalabra(nombre,sizeof((*(empleado)).nombre),"Ingrese el nuevo nombre:\n","ERROR, nombre invalido\n",3);
					employee_setNombre(empleado,nombre);
					break;
				case 2:
					utn_getNumeroFlotante(&sueldo,"Ingrese nuevo sueldo\n","ERROR, sueldo invalido\n",1000,100000,3);
					employee_setSueldo(empleado,sueldo);
					break;
				case 3:
					utn_getNumero(&horas, "Ingrese nueva cantidad de horas trabajadas\n", "ERROR, cantidad invalida\n",10,500,6);
					employee_setHorasTrabajadas(empleado, horas);
					break;
			}
			retorno = 0;

			printf("Modificacion realizada con exito!.\nSi no desea realizar mas modificaciones, ingrese 4\n");
			scanf("%d", &respuesta);

		}while(respuesta!=4);
	}
    return retorno;
}

/** \brief Baja de empleado
 * elimina un empleado segun su id
 * \param pArrayListEmployee LinkedList* lista de la que se elimina el empleado
 * \return int devuelve -1 si falló, 0 si eliminó
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int cantidad;
	int id;
	int respuesta;
	int retorno =-1;
	Employee* empleado;

	printf("Si desea imprimir la lista ingrese 1\n");
	scanf("%d",&respuesta);
	if(respuesta == 1)
	{
		controller_ListEmployee(pArrayListEmployee);
	}

	cantidad = ll_len(pArrayListEmployee);
	utn_getNumero(&id,"Ingrese el ID del empleado a eliminar\n","ERROR, ID no encontrado\n",1,cantidad,5);
	if(pArrayListEmployee != NULL)
	{
		cantidad = ll_len(pArrayListEmployee);
		if(id> 0 && id <= cantidad)
		{
			empleado = ll_get(pArrayListEmployee,id-1);
			ll_remove(pArrayListEmployee,id-1);
			printf("Empleado removido exitosamente de la lista\n");
			retorno = 0;
		}
		else
		{
			printf("No es posible eliminar al empleado\n");
		}
	}

    return retorno;
}

/** \brief Listar empleados
 * muestra una lista de todos los empleados
 * \param pArrayListEmployee LinkedList* lista que muestra
 * \return int devuelve -1 si no lista, 0 si si
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int retorno = -1;
	int cantidad;
	cantidad = ll_len(pArrayListEmployee);
	Employee* lista;
	printf("ID  ---NOMBRE  ---HORAS  ---SUELDO\n");

	for(i=0;i<cantidad;i++)
	{
		lista = (Employee*) ll_get(pArrayListEmployee,i);
		printf("%d\t--- %s\t--- %d\t--- %d\n", lista->id,lista->nombre,lista->horasTrabajadas,lista->sueldo);
		retorno = 0;
	}
    return retorno;
}

/** \brief Ordenar empleados
 *ordena a los empleados segun el criterio seleccionado
 * \param pArrayListEmployee LinkedList* lista de empleados a ordenar
 * \return int -1 si no ordenó, 0 si ordenó
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int menu;
	int cantidad;
	int respuesta = 0;

	if(pArrayListEmployee != NULL)
	{
		cantidad = ll_len(pArrayListEmployee);
		if(cantidad > 0)
		{
			do
			{

				do
				{
					printf(	"Menu:\n"
							"1.Ordenar por ID\n"
							"2.Ordenar por nombre\n"
							"3.Ordenar por horas trabajadas\n"
							"4.Ordenar por salario\n"
							"5.Salir.\n");
				}while(utn_getNumero(&menu,"Ingrese la opcion de ordenamiento que prefiera\n",
						"ERROR,opcion de orenamiento invalida\n",1,5,5));

				switch(menu)
				{
				case 1:
					do
					{
						utn_getNumero(&menu, "Ingrese la opcion que desee:\n"
								"1.Ordenar por ID de manera ascendente\n"
								"2.Ordenar por ID de manera descendente\n"
								"3.Salir\n","ERROR, opcion invalida\n",1,3,3);
						switch(menu)
						{
						case 1:
							ll_sort(pArrayListEmployee,employee_CompareById,0);
							controller_ListEmployee(pArrayListEmployee);
							retorno =0;
							printf("Ordenamiento realizado\n");
							break;
						case 2:
							ll_sort(pArrayListEmployee,employee_CompareById,1);
							controller_ListEmployee(pArrayListEmployee);
							retorno =0;
							printf("Ordenamiento realizado\n");
							break;
						case 3:
							break;
						}
					}while(menu != 3);

					break;
				case 2:
					do
					{
						utn_getNumero(&menu, "Ingrese la opcion que desee:\n"
								"1.Ordenar por NOMBRE de manera ascendente\n"
								"2.Ordenar por NOMBRE de manera descendente\n"
								"3.Salir\n","ERROR, opcion invalida\n",1,3,3);
						switch(menu)
						{
						case 1:
							ll_sort(pArrayListEmployee,employee_CompareByNombre,0);
							controller_ListEmployee(pArrayListEmployee);
							retorno =0;
							printf("Ordenamiento realizado\n");
							break;
						case 2:
							ll_sort(pArrayListEmployee,employee_CompareByNombre,1);
							controller_ListEmployee(pArrayListEmployee);
							retorno =0;
							printf("Ordenamiento realizado\n");
							break;
						case 3:
							break;
						}

					}while(menu != 3);

					break;
				case 3:
					do
					{
						utn_getNumero(&menu, "Ingrese la opcion que desee:\n"
								"1.Ordenar por HORAS TRABAJADAS de manera ascendente\n"
								"2.Ordenar por HORAS TRABAJADAS de manera descendente\n"
								"3.Salir\n","ERROR, opcion invalida\n",1,3,3);
						switch(menu)
						{
						case 1:
							ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,0);
							controller_ListEmployee(pArrayListEmployee);
							retorno =0;
							printf("Ordenamiento realizado\n");
							break;
						case 2:
							ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,1);
							controller_ListEmployee(pArrayListEmployee);
							retorno =0;
							printf("Ordenamiento realizado\n");
							break;
						case 3:
							break;
						}

					}while(menu != 3);
					break;
				case 4:
					do
					{
						utn_getNumero(&menu, "Ingrese la opcion que desee:\n"
								"1.Ordenar por SUELDO de manera ascendente\n"
								"2.Ordenar por SUELDO de manera descendente\n"
								"3.Salir\n","ERROR, opcion invalida\n",1,3,3);
						switch(menu)
						{
						case 1:
							ll_sort(pArrayListEmployee,employee_CompareBySueldo,0);
							controller_ListEmployee(pArrayListEmployee);
							retorno =0;
							printf("Ordenamiento realizado\n");
							break;
						case 2:
							ll_sort(pArrayListEmployee,employee_CompareBySueldo,1);
							controller_ListEmployee(pArrayListEmployee);
							retorno =0;
							printf("Ordenamiento realizado\n");
							break;
						case 3:
							break;
						}

					}while(menu != 3);
					break;
				case 5:
					utn_getNumero(&respuesta,"Si desea volver al menú, ingrese 1, de lo cotrario ingrese 2 para salir\n", "ERROR, opcion invalida\n",1,2,3);
					break;
				}



			}while(respuesta == 1);
		}
		else
		{
			printf("ERROR. Primero necesita cargar los empleados\n");
			system("pause");
		}


	}
    return retorno;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* archivo a guardar
 * \param pArrayListEmployee LinkedList* lista a guardar en el archivo
 * \return int devuelve -1 si no guardó, 0 si guardó
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int cantidad;
	int i;
	Employee* empleado;
	int retorno = -1;

	cantidad = ll_len(pArrayListEmployee);
	pArchivo = fopen(path, "r+");
	if(pArchivo!= NULL)
	{
		pArchivo = fopen(path,"w+");
	}

	if(cantidad >0)
	{
		fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");

		for(i=0;i<cantidad;i++)
		{
			empleado = ll_get(pArrayListEmployee,i);
			fprintf(pArchivo, "%d,%s,%d,%d\n", empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
			retorno = 0;;
		}
	}

	fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* archivo a guardar
 * \param pArrayListEmployee LinkedList* lista a aguardar en el archivo
 * \return int devuelve -1 si no guardó, 0 si guardó
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo = fopen(path, "wb");
	int cantidad;
	int i;
	Employee* empleado;
	int retorno = -1;


	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		ll_sort(pArrayListEmployee,employee_CompareById,0);
		cantidad = ll_len(pArrayListEmployee);

		if(cantidad >0)
		{
			for(i=0;i<cantidad;i++)
			{
				empleado = ll_get(pArrayListEmployee,i);
				fwrite(empleado,sizeof(Employee),1,pArchivo);
				retorno = 0;
			}
		}

		fclose(pArchivo);

	}
	return retorno;
}


























