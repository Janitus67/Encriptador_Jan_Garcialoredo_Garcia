// --- DECLARACIÓNES ---

#include <iostream>
#include <string>
#include <vector>

#include "Encriptador.h"
#include "Archivo.h"
#include "Bienvenida.h"

#define VALOR_PREDETERMINADO 0

int main()
{
	char seleccion = VALOR_PREDETERMINADO;
	Bienvenida(seleccion);
}