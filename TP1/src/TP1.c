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
#include "bibliotecaTP1.h"
/*
int calcularSuma(int a, int b);
int calcularResta(int a, int b);
int calcularMultiplicacion(int a, int b);
float calcularDivision(int a, int b);
int calcularFactorial(int a);
int calcularFactorial2(int b);*/


int main(void) {

	setbuf(stdout, NULL);

	int x;
	int y;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	int factorial;
	int factorial2;
	int opcion;

	do
	{

		printf("Ingresar primer operando: ");
		scanf("%d", &x);
		printf("Ingresar segundo operando: ");
		scanf("%d", &y);

		printf("Elija una opcion: \n");
		printf("1. Suma\n");
		printf("2. Resta\n");
		printf("3. Multiplicacion\n");
		printf("4. Division\n");
		printf("5. Factorial\n");
		printf("6. Salir\n");

		scanf("%d", &opcion);

		switch(opcion)//int - char
		{
			case 1:
				printf("Ingreso a la opcion Suma\n");
				suma = calcularSuma(x, y);
				printf("El resultado de %d + %d es: %d\n",x, y,  suma);
			break;
			case 2:
				printf("Ingreso a la opcion Resta\n");
				resta = calcularResta(x, y);
				printf("El resultado de %d - %d es: %d\n",x, y, resta);
			break;
			case 3:
				printf("Ingreso a la opcion Multiplicacion\n");
				multiplicacion = calcularMultiplicacion(x,y);
				printf("El resultado de %d * %d es : %d\n",x, y, multiplicacion);
			break;
			case 4:
				printf("Ingreso a la opcion Division\n");
				division = calcularDivision(x,y);
				printf("El resultado de %d / %d es: %.2f\n",x, y, division);
			break;
			case 5:
				printf("Ingreso a la opcion Factorial\n");
				printf("Calculo con el primer operando: &d \n", x);
				factorial = calcularFactorial(x);
				printf("El factorial %d es: %d\n",x, factorial);
				printf("Calculo con el segundo operando: %d\n", y);
				factorial2 = calcularFactorial2(y);
				printf("El factorial del %d es: %d\n",y, factorial2);
			break;
			case 6:
				printf("GRACIAS POR USAR LA CALCULADORA!\n");
			break;
		}

	}while(opcion!=6);

	return EXIT_SUCCESS;
}

