// Header con las declaraciones
#include "../include/cpu/cpu.hpp"

// Headers propios
#include "../include/cpu/circuitos_basicos.hpp"
#include "../include/cpu/mate.hpp"

// Headers del sistema
#include <string>

/***************/
/* CLASE "CPU" */
/***************/

Cpu::Cpu()
{// Inicializa los inputs y los outputs
	
    A = new bool[8];
    B = new bool[8];
    S = new bool[3];
    Clo = new bool[8];
    Chi = new bool[8];

	for (int i=0; i<8; i++) {
		A[i] = B[i] = Clo[i] = Chi[i] = 0;
	}
	for (int i=0; i<3; i++) {
        S[i] = 0;
	}
	Carry = 0;
    Adec = 0;
    Bdec = 0;
    Cdec = 0;
	Sdec = NO_OP;
}

void Cpu::actualizar()
{// Actualiza los inputs y los outputs

	actualizarInput();
	
	SumaResta.actualizar();
	LShift.actualizar();
	RShift.actualizar();
	Igual.actualizar();
	And.actualizar();
	Or.actualizar();
	
	actualizarOutputLo();
	actualizarOutputHi();
	actualizarCarry();
    actualizarCdec();
}

void Cpu::actualizarCdec()
{
	if (Sdec==NO_OP or Sdec==L_SHIFT or Sdec==R_SHIFT) {
		bool Cbin[17];
		
		Cbin[0] = Carry;
		for (int i=0; i<8; i++) {
			Cbin[i+1] = Chi[i];
			Cbin[i+9] = Clo[i];
		}
        Cdec = btod(Cbin,17);
	}
    else if (Sdec==RESTA) {
        bool Cbin[8];

        for (int i=0; i<8; i++)
            Cbin[i] = Clo[i];

        // Caso A => B
        if (Carry==0) {
            Cdec = btod(Cbin,8);
        }
        // Caso A < B
        else if (Carry==1) {
            // Signo + reversion del complemento 2
            Cdec = (-1) * (256 - btod(Cbin,8));
        }
    }
	else {
		bool Cbin[9];
		
		Cbin[0] = Carry;
		for (int i=0; i<8; i++)
			Cbin[i+1] = Clo[i];
			
		Cdec = btod(Cbin,9);
    }
}

void Cpu::actualizarInput()
{
    delete[] A;
    delete[] B;
    delete[] S;
    A = dtob(Adec,8);
    B = dtob(Bdec,8);
    S = dtob(Sdec,3);

	// Actualiza los inputs de todos los componentes
    SumaResta.actualizarInput( A,B,S );
    LShift.actualizarInput( A,B,S );
    RShift.actualizarInput( A,B,S );
    Igual.actualizarInput( A,B,S );
    And.actualizarInput( A,B,S );
    Or.actualizarInput( A,B,S );
}

void Cpu::actualizarOutputLo()
{
	bool inMux[8];
	for (int i=0; i<8; i++)
	{
		inMux[7] = B[i];
		inMux[6] = LShift.leerClo(i);
		inMux[5] = RShift.leerClo(i);
		inMux[4] = SumaResta.leerClo(i);
		inMux[3] = SumaResta.leerClo(i);
		inMux[2] = Or.leerClo(i);
		inMux[1] = And.leerClo(i);
		inMux[0] = Igual.leerClo(i);
	
        Clo[i] = mux(8,inMux,S);
	}
}

void Cpu::actualizarOutputHi()
{
    bool *outDemux = demux(8,1,S);
	
	// Bases transistores
	bool baseNOP = outDemux[7];
	bool baseLS = outDemux[6];
	bool baseRS = outDemux[5];
	
	for (int i=0; i<8; i++) {
		switch (Sdec)
		{
			// Transistores
			case NO_OP   : Chi[i] = transistor(A[i],baseNOP);             break;
			case L_SHIFT : Chi[i] = transistor(LShift.leerChi(i),baseLS); break;
			case R_SHIFT : Chi[i] = transistor(RShift.leerChi(i),baseRS); break;
			default      : Chi[i] = 0;                                    break;
		}
	}
}

void Cpu::actualizarCarry()
{
	bool inMux[8];
	inMux[7] = 0;
	inMux[6] = LShift.leerCarry();
	inMux[5] = 0;
	inMux[4] = SumaResta.leerCarry();
    inMux[3] = SumaResta.leerCarry();
	inMux[2] = 0;
	inMux[1] = 0;
	inMux[0] = 0;
	
    Carry = mux(8,inMux,S);
}
