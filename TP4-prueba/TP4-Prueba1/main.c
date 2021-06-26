#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn1.h"
#include "parser.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int carga = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	if(utn_getNumero(&option,
    			 " \n---Menu---\n"
    			 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    			 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
				 "3. Alta de empleado\n"
				 "4. Modificar datos de empleado\n"
				 "5. Baja de empleado\n"
				 "6. Listar empleados\n"
				 "7. Ordenar empleados\n"
				 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
				 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
				"10. Salir\n",
    		"Error, Ingrese una de las opciones validas\n",1,10,10)==0)
    	{

    		switch(option) {
            case 1:
            	if(carga==0)
                {
            		controller_loadFromText("data.csv",listaEmpleados);
                    carga = 1;
                }
            	else
            	{
            		printf("Error. Solo se puede cargar la lista una vez");
            	}
                break;
            case 2:
            	if(carga == 1)
            	{
            		controller_loadFromBinary("data.bin",listaEmpleados);
            	}
            	else
            	{
            		printf("Error.El archivo no existe");
            	}
            	break;
            case 3:
            	if(carga == 1)
            	{
            		controller_addEmployee(listaEmpleados);

            	}
            	else
            	{
            		printf("ERROR, primero debe cargar la lista");
            	}
            	break;
            case 4:
            	if(carga ==1)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("ERROR, primero debe cargar la lista");

            	}
            	break;
            case 5:
            	if(carga ==1)
            	{
            		controller_removeEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("ERROR, primero debe cargar la lista");

            	}
            	break;
            case 6:
            	if(carga ==1)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("ERROR, primero debe cargar la lista");
            	}
            	break;
            case 7:
            	if(carga ==1)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("ERROR, primero debe cargar la lista");
            	}
            	break;
            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("data.bin", listaEmpleados);
            	break;
            case 10:
            	printf("Cerrando el programa.\n");
            	break;
    		}
    	}

    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

