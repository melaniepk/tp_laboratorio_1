#include "Employee.h"
#include "utn1.h"

Employee* employee_new()
{
	Employee* empleado;
	empleado = (Employee*) calloc(sizeof(Employee),1);

	return empleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleado;
	empleado = employee_new();

	int id;
	int horasTrabajadas;
	float sueldo;

	id = atoi(idStr);
	horasTrabajadas = atoi(horasTrabajadasStr);
	sueldo = atof(sueldoStr);

	if(empleado!= NULL)
	{
		employee_setId(empleado,id);
		employee_setNombre(empleado,nombreStr);
		employee_setHorasTrabajadas(empleado,horasTrabajadas);
		employee_setSueldo(empleado,sueldo);
	}
	return empleado;
}

int employee_delete(Employee* this)
{
	int retorno =-1;

	if(this!= NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

/*FUNCIONES SET*/

int employee_setId(Employee* this,int id)
{
	int retorno =-1;
	if(this!= NULL && id>=0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!= NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, sizeof(this->nombre));
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno =-1;
	if(this!= NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this!= NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
	}
	return retorno;
}

/* FUNCIONES GET*/

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this!= NULL && id!= NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}


char* employee_getNombre(Employee* this)
{

	return this->nombre;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno =-1;
	if(this!= NULL&& horasTrabajadas!= NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;


}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno =-1;
	if(this!= NULL && sueldo!= NULL)
	{
		*sueldo = this->sueldo;
		retorno =0;
	}
	return retorno;
}


int employee_CompareById(void* empleado1, void* empleado2)
{
	int retorno;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(empleado1 != NULL && empleado2!= NULL)
	{
		unEmpleado = (Employee*) empleado1;
		otroEmpleado = (Employee*) empleado2;

		if(unEmpleado->id > otroEmpleado->id)
		{
			retorno = -1;
		}
		else
		{
			if(unEmpleado->id < otroEmpleado->id)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
int employee_CompareByNombre(void* empleado1, void* empleado2)
{
	int retorno;
	char unNombre[128];
	char otroNombre[128];

	if(empleado1 != NULL && empleado2!= NULL)
	{
		strcpy(unNombre,employee_getNombre(empleado1));
		strcpy(otroNombre,employee_getNombre(empleado2));

		retorno = strcmp(unNombre,otroNombre);
	}

	return retorno;
}
int employee_CompareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	int retorno;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(empleado1 != NULL && empleado2!= NULL)
	{
		unEmpleado = (Employee*) empleado1;
		otroEmpleado = (Employee*) empleado2;

		if(unEmpleado->horasTrabajadas > otroEmpleado->horasTrabajadas)
		{
			retorno = -1;
		}
		else
		{
			if(unEmpleado->horasTrabajadas < otroEmpleado->horasTrabajadas)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
int employee_CompareBySueldo(void* empleado1, void* empleado2)
{
	int retorno =-1;
	Employee* unEmpleado;
	Employee* otroEmpleado;


	if(empleado1 != NULL && empleado2!= NULL)
	{
		unEmpleado = (Employee*) empleado1;
		otroEmpleado = (Employee*) empleado2;

		if(unEmpleado->sueldo > otroEmpleado->sueldo)
		{
			retorno = -1;
		}
		else
		{
			if(unEmpleado->sueldo < otroEmpleado->sueldo)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
