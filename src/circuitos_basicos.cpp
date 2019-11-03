// Header con las declaraciones
#include "../include/cpu/circuitos_basicos.hpp"

// Headers propios
#include "../include/cpu/mate.hpp"

// Headers del sistema
#include <cmath>
#include <iostream>

/*******************************/
/* CIRCUITOS DIGITALES BÁSICOS */
/*******************************/

bool mux(int tam, bool *input, bool *select)
{
/*	Multiplexor n:1 (n input, 1 output)
	Se usa el select para elegir qué input es transmitido hacia el output
*/
	// Caso de error
	if (!esPotencia(tam,2)) {
		std::cerr << "Error: el parametro 'tam' en la funcion 'mux()' "
					 "debe ser igual a una potencia de 2.\n";
		std::system("pause");
        std::exit(EXIT_FAILURE);
	}
	
    int tamSel = int(log2(tam));
	int nroOp = btod(select,tamSel);
	bool output = input[(tam-1)-nroOp];
	
	return output;
}

bool* demux(int tam, bool input, bool *select)
{
/*	Demultiplexor 1:n (1 input, n output)
	Se usa el select para elegir qué input es transmitido hacia el output
*/	
	// Caso de error
	if (!esPotencia(tam,2)) {
		std::cerr << "Error: el parametro 'tam' en la funcion 'demux()' "
					 "debe ser igual a una potencia de 2.\n";
		std::system("pause");
        std::exit(EXIT_FAILURE);
	}
	
	bool *output = new bool[tam];
	for (int i=0; i<8; i++) {
		output[i] = 0;
	}
	
    int tamSel = int(log2(tam));
	int nroOp = btod(select,tamSel);
	output[(tam-1)-nroOp] = input;
	
	return output;
}

bool transistor(bool colector, bool base)
{
/*	Componentes básicos de un transistor
	
	Colector : Recibe una señal externa y se la entrega a la base
	Base     : Permite (o no) el paso de la señal hacia el receptor
	Emisor   : Recibe la señal de la base y la hace salir del transistor
	
    En este tipo de transistor, si la base es un 1, permite el paso de corriente
*/
    bool emisor;
	
	if (base == 1) emisor = colector;
	if (base == 0) emisor = 0;
	
	return emisor;
}

void semiSuma(bool inputA, bool inputB, bool &output, bool &carry)
{
/*	Circuito semisumador básico */
	carry  = inputA and inputB;
	output = inputA xor inputB;
}
