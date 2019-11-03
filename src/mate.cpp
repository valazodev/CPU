#include "../include/cpu/mate.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>

/*************************/
/* FUNCIONES MATEMÁTICAS */
/*************************/

bool esPotencia(int num, int base)
{// Verifica si 'num' es potencia de 'base'

	// Casos de error
	if (num<0 or base<0) {
		std::cerr << "Error: 'esPotencia()' no admite parametros negativos.\n";
		std::system("pause");
        std::exit(EXIT_FAILURE);
	}
	// Casos especiales
    if (num==base)
		return true;
	else if (num==1) // Cualquier número elevado a 0 es 1
		return true;
	else if (num!=1 and base==1) // Una potencia de 1 siempre es igual a 1
		return false;
	else if (num==0 and base!=0) // Solo una potencia de 0 puede ser igual a 0
		return false;
	else if (num>1 and base==0) // Una potencia de 0 sólo puede ser 0 o 1 (0^0)
		return false;
	else if (num < base) // Un entero sólo tiene una potencia menor que él: 1
		return false;
	
    // Caso más probable (num > base)
    else {
		int pot = base;
		while (num > pot) {
			pot *= base;
			if (num == pot)
				return true;
		}
		return false;
	}
}

bool* dtob(int dec, int tam)
{// Decimal a binario
	
	bool *bin = new bool[tam];
    for (int i=tam-1; i>=0; i--) {
		bin[i] = dec % 2;
		dec /= 2;
	}
	return bin;
}

int btod(bool *bin, int tam)
{// Binario a decimal
	
	int dec = 0;
	for (int i=0; i<tam; i++) {
		int exp = (tam-1) - i;
        int pot = int(std::pow(2,exp));
        dec += (bin[i] * pot);
	}
	return dec;
}
