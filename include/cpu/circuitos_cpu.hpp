#ifndef CIRCUITOS_CPU
#define CIRCUITOS_CPU

/**********************/
/* CLASE CIRCUITO CPU */
/**********************/

class Circuito {
	
protected:
	bool A[8], B[8], S[8];
	bool Clo[8], Chi[8], Carry;
	
public:
    Circuito();
	void actualizarInput(bool*, bool*, bool*);
	bool leerClo(int indice) { return Clo[indice]; };
	bool leerChi(int indice) { return Chi[indice]; };
	bool leerCarry() { return Carry; };
};

class cSumaResta: public Circuito {
	public: void actualizar();
};

class cLShift: public Circuito {
	public: void actualizar();
};

class cRShift: public Circuito {
	public: void actualizar();
};

class cIgual: public Circuito {
	public: void actualizar();
};

class cAnd: public Circuito {
	public: void actualizar();
};

class cOr: public Circuito {
	public: void actualizar();
};

#endif
