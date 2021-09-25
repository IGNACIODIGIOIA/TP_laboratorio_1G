/*
 * calculadora.h
 *
 *  Created on: 8 sep. 2020
 *      Author: ignacio
 */
#ifndef CALCULADORA_H_
#define CALCULADORA_H_

int suma(int a, int b);
int resta(int a, int b);
float division(float a, float b);
int multiplicacion(int a, int b);
int factorial(int x);

float getFloat(char mensaje[]);
int getInt(char mensaje[]);

void printSuma(int a, int b);
void printResta(int a, int b);
void printMultiplicacion(int a, int b);
void printDivision(float a, float b);

#endif /* CALCULADORA_H_ */
