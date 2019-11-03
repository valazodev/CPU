#ifndef CIRCUITOS_BASICOS_HPP
#define CIRCUITOS_BASICOS_HPP

/*******************************/
/* CIRCUITOS DIGITALES BÁSICOS */
/*******************************/

bool mux(int tam, bool *input, bool *select);   // Multiplexor n:1
bool* demux(int tam, bool input, bool *select); // Demultiplexor 1:n
bool transistor(bool colector, bool base); // Transistor, retorna el emisor
void semiSuma(bool inputA, bool inputB, bool &output, bool &carry); // Semisumador

#endif
