// Header con las declaraciones
#include "../include/cpu/circuitos_cpu.hpp"

// Headers propios
#include "../include/cpu/circuitos_basicos.hpp"

/**********************/
/* CLASE CIRCUITO CPU */
/**********************/

Circuito::Circuito()
{// Inicialización de los arreglos en 0

	for (int i=0; i<8; i++) {
		A[i] = B[i] = Clo[i] = Chi[i] = 0;
	}
	for (int i=0; i<3; i++) {
		S[i] = 0;
	}
	Carry = 0;
}

void Circuito::actualizarInput(bool input1[8], bool input2[8], bool select[3])
{// Actualiza los valores de A, B y S
	
	for (int i=0; i<8; i++) {
		A[i] = input1[i];
		B[i] = input2[i];
	}
	for (int i=0; i<3; i++) {
		S[i] = select[i];
	}
}

void cSumaResta::actualizar()
{// Suma y resta, para diferenciarlas se usa S[0] (0:suma, 1:resta)
 // Cuando es igual a 1, calcula el complemento para calcular la resta
	
	bool c0[8],c1[8]; // Carrys intermedios
	bool outAux[8];   // Output intermedio
	
	// Primera corrida de semi-sumadores
	for (int i=7; i>=0; i--)
	{
		bool inA = A[i];
		bool inB = B[i] xor S[0];
		semiSuma( inA, inB, outAux[i], c0[i] );
	}
	// Segunda corrida de semi-sumadores
	for (int i=7; i>=0; i--)
	{
		bool inA = outAux[i];
		bool inB;
		
		if (i==7) inB = S[0];
		else inB = c0[i+1] xor c1[i+1];
		
		semiSuma( inA, inB, Clo[i], c1[i] );
    }
    Carry = (c0[0] xor c1[0]) xor S[0];
}

void cLShift::actualizar()
{// Desplaza los bits hacia la izquierda (L)

	Carry = A[0];
	
	for (int i=0; i<7; i++) {
		Chi[i] = A[i+1];
	}
	Chi[7] = B[0];
	
	for (int i=0; i<7; i++) {
		Clo[i] = B[i+1];
	}
	Clo[7] = 0;
}

void cRShift::actualizar()
{// Desplaza los bits hacia la derecha (R)

	Carry = Chi[0] = 0;
	
	for (int i=0; i<7; i++) {
		Chi[i+1] = A[i];
	}
	Clo[0] = A[7];
	
	for (int i=0; i<7; i++) {
		Clo[i+1] = B[i];
	}
}

void cIgual::actualizar()
{// Si 2 inputs son iguales, la salida es 1

	for (int i=0; i<8; i++) {
		Clo[i] = not(A[i] xor B[i]);
	}
}

void cAnd::actualizar()
{// Operación lógica AND

	for (int i=0; i<8; i++) {
		Clo[i] = A[i] and B[i];
	}
}

void cOr::actualizar()
{// Operación lógica OR

	for (int i=0; i<8; i++) {
		Clo[i] = A[i] or B[i];
	}
}
