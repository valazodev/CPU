#ifndef CPU_HPP
#define CPU_HPP

// Headers propios
#include "circuitos_cpu.hpp"

typedef enum {
	NO_OP,
	L_SHIFT,
	R_SHIFT,
	SUMA,
	RESTA,
	OR,
	AND,
	IGUAL
} OP;

/***************/
/* CLASE "CPU" */
/***************/

class Cpu {
	
	private:
        bool *A, *B, *S;        // Input
        bool *Clo, *Chi, Carry; // Output
		int Adec, Bdec, Cdec;
		OP Sdec;
		
		cSumaResta SumaResta;
		cLShift LShift;
		cRShift RShift;
		cIgual Igual;
		cAnd And;
		cOr Or;
		
		void actualizarInput();
		void actualizarOutputLo();
		void actualizarOutputHi();
		void actualizarCarry();
		void actualizarCdec();
	
	public:
		Cpu();
		void actualizar();
        void actualizarAdec(int valor) {Adec = valor;}
        void actualizarBdec(int valor) {Bdec = valor;}
        void actualizarSdec(int valor) {Sdec = OP(valor);}
        int leerCdec() {return Cdec;}
        int Ai(int i) {return int(A[i]);}
        int Bi(int i) {return int(B[i]);}
        int Si(int i) {return int(S[i]);}
        int Li(int i) {return int(Clo[i]);}
        int Hi(int i) {return int(Chi[i]);}
        int C() {return Carry;}
};

#endif
