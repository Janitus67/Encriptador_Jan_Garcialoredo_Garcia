// --- DECLARACIÓNES ---

#include <iostream>
#include "Bienvenida.h"

// --- FUNCIÓNES ---

int Bienvenida(int seleccion)
{
	if ((seleccion >= 1) && (seleccion <= 3))
	{

	}
	else
	{
		std::cout << "|   La opcion que ha seleccionado no es valida, por favor seleccione una que este dentro del rango.  |";
	}
	return 0;
}