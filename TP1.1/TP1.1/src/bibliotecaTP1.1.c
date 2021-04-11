/*
 * bibliotecaTP1.1.c
 *
 *  Created on: 29 mar. 2021
 *      Author: mkale
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @fn int calcularSuma(int, int)
 * @brief
 * calcula la suma entre a y b
 * @param a
 * @param b
 * @return suma
 */
float calcularSuma(float a, float b)
{

	float suma;
	suma = a + b;
	return suma;
}

/**
 * @fn int calcularResta(int, int)
 * @brief
 * calcula la resta entre a y b
 * @param a
 * @param b
 * @return resta
 */
float calcularResta(float a, float b)
{
	float resta;
	resta = a - b;
	return resta;

}

/**
 * @fn int calcularMultiplicacion(int, int)
 * @brief
 * calcula el producto entre a y b
 * @param a
 * @param b
 * @return multiplicacion
 */
float calcularMultiplicacion(float a, float b)
{
	float multiplicacion;
	multiplicacion = a * b;
	return multiplicacion;
}

/**
 * @fn float calcularDivision(int, int)
 * @brief
 * calcula el cociente entre a y b
 * @param a
 * @param b
 * @return division
 */
float calcularDivision(float a, float b)
{
	float resultado;


	if(b != 0)
	{
		float division;
		division = (float)a / b;
		resultado = division;
	}
	else
	{
		resultado = printf("Error. No se puede dividir por 0 ");
	}

	return resultado;
}

/**
 * @fn int calcularFactorial(int)
 * @brief
 * calcula el factorial de a
 * @param a
 * @return faltorial
 */
float calcularFactorial(float a)
{
	//int numero;
	int contador;
	float factorial;
	int multiplicador;


	multiplicador=1;
	factorial=1;

	for(contador=0;contador<a;contador++)
	{
		factorial=factorial*multiplicador;

		multiplicador++;
	}

	return factorial;
}

/**
 * @fn int calcularFactorial2(int)
 * @brief
 * calcula el factorial de b
 * @param b
 * @return factorial2
 */
float calcularFactorial2(float b)
{
	//int numero;
	int contador;
	float factorial;
	int multiplicador;


	multiplicador=1;
	factorial=1;

	for(contador=0;contador<b;contador++)
	{
		factorial=factorial*multiplicador;

		multiplicador++;
	}

	return factorial;
}

void pedirNumero(char mensaje, int numero)
{

	printf(mensaje);
	scanf("%f", &numero);

        /*PedirUnNumero(char[], char[], int, int);
        miVector[i] = PedirUnNumero("Ingrese un numero: ", "Error, fuera de rango: ",
        min, max);*/

}
