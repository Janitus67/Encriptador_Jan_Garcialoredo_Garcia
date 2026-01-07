// --- DECLARACIÓNES ---

#include <iostream>
#include <string>
#include <vector>

#include "Encriptador.h"
#include "Archivo.h"
#include "Bienvenida.h"

//Valores en el escope necesario para los archivos

#define VALOR_PREDETERMINADO 0
#define PREFIJO "---"

//Funcion principal

int main()
{
	std::vector<std::string> historial;
	short seleccion = VALOR_PREDETERMINADO;
	Bienvenida(seleccion, historial);
	return 0;
}