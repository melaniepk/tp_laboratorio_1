/*
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTP1.1.h"
/*
int calcularSuma(int a, int b);
int calcularResta(int a, int b);
int calcularMultiplicacion(int a, int b);
float calcularDivision(int a, int b);
int calcularFactorial(int a);
int calcularFactorial2(int b);*/


int main(void) {

	setbuf(stdout, NULL);

	float x = 0;
	float y = 0;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	float factorial;
	float factorial2;
	int opcion;

	do
	{
		printf("MENÚ DE OPCIONES\n");

		printf("1. Ingresar primer operando: \n");
		printf("2. Ingresar segundo operando: \n");
		printf("3. Calcular todas las operaciones: \n");
		printf("a) Suma\n");
		printf("b) Resta\n");
		printf("c) Multiplicacion\n");
		printf("d) Division\n");
		printf("e) Factorial\n");
		printf("4. Mostrar resultados\n");
		printf("5. Salir\n");

		scanf("%d", &opcion);
		while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5)
		{
			printf("Error, debe ingresar alguna de las opciones enumeradas");
			printf("Presione cualquier tecla para continuar");
			scanf("%d", &opcion);
		}

		switch(opcion)//int - char
		{
			case 1:
				printf("Ingrese el primer operando\n");
				scanf("%f", &x);
			break;
			case 2:
				if(x != 0 )
				{
					printf("Ingrese el segundo operando\n");
					scanf("%f", &y);
				}
				else
				{
					printf("Error, primero debe ingresar el primer operando, ingrese opcion 1\n");
					printf("Presione cualquier tecla para continuar");
					scanf("%d", &opcion);
				}
			break;
			case 3:
				if(x != 0 && y != 0)
				{
					printf("Presione 4 para ver los resultados\n");
					//printf("Ingreso a la opcion Suma\n");
					suma = calcularSuma(x, y);

					//printf("Ingreso a la opcion Resta\n");
					resta = calcularResta(x, y);

					//printf("Ingreso a la opcion Multiplicacion\n");
					multiplicacion = calcularMultiplicacion(x,y);


					//printf("Ingreso a la opcion Division\n");
					division = calcularDivision(x,y);


					//printf("Ingreso a la opcion Factorial\n");
					//printf("Calculo con el primer operando: %d \n", x);
					factorial = calcularFactorial(x);

					//printf("Calculo con el segundo operando: %d\n", y);
					factorial2 = calcularFactorial2(y);
				}
				else
				{
					printf("Error, Primero debe ingresar los operandos. Opcion 1 y 2.\n");
					printf("Presione cualquier tecla para continuar");
					scanf("%d", &opcion);
				}
			break;
			case 4:

				printf("El resultado de %f + %f es: %f\n",x, y,  suma);
				printf("El resultado de %f - %f es: %f\n",x, y, resta);
				printf("El resultado de %f * %f es : %f\n",x, y, multiplicacion);
				printf("El resultado de %f / %f es: %.2f\n",x, y, division);
				printf("El factorial %f es: %f\n",x, factorial);
				printf("El factorial del %f es: %f\n",y, factorial2);
			break;

			case 5:
				printf("GRACIAS POR USAR LA CALCULADORA!\n");
			break;


		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}

