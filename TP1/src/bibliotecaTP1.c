/*
 * bibliotecaTP1.c
 *
 *  Created on: 26 mar. 2021
 *      Author: mkale
 */

/**
 * @fn int calcularSuma(int, int)
 * @brief
 * calcula la suma entre a y b
 * @param a
 * @param b
 * @return suma
 */
int calcularSuma(int a, int b)
{

	int suma;
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
int calcularResta(int a, int b)
{
	int resta;
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
int calcularMultiplicacion(int a, int b)
{
	int multiplicacion;
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
float calcularDivision(int a, int b)
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
int calcularFactorial(int a)
{
	//int numero;
	int contador;
	int factorial;
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
int calcularFactorial2(int b)
{
	//int numero;
	int contador;
	int factorial;
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

