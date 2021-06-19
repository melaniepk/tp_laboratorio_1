#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;

	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	int i=0;

	pFile = fopen("data.csv","r");
	if(pFile == NULL)
	{
		printf("Error, no es posible leer el archivo");
	}
	else
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]", id,nombre, horasTrabajadas, sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]", id, nombre,
					horasTrabajadas, sueldo);

			unEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			i++;
			ll_add(pArrayListEmployee,unEmpleado);
		}
	}

	fclose(pFile);
    return i;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* unEmpleadoBinario;


		ll_clear(pArrayListEmployee);
		while(!feof(pFile))
		{

			unEmpleadoBinario = employee_new();

			fread(unEmpleadoBinario,sizeof(Employee),1,pFile);
			ll_add(pArrayListEmployee,unEmpleadoBinario);
			retorno = 0;
		}

    return  retorno;
}
