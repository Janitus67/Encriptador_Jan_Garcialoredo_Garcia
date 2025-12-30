// --- DECLARACIÓNES ---

#include <fstream>
#include <iostream>

// --- DECLARACIÓNES ---

#include <string>
#include "Archivo.h"
#include "Encriptador.h"

// --- FUNCIÓNES ---

bool existeArchivo() {
	std::ifstream archivo("encriptado.txt");
	return archivo.is_open();
}

void borrarArchivo()
{
	std::ofstream archivo("encriptado.txt", std::ios::out | std::ios::trunc);

	if (archivo.is_open())
	{
		archivo << "--- Codigo Cifrado -------" << std::endl;
		archivo << "--- Historial Mensajes ---" << std::endl;
		archivo << "--- Nuevos Mensajes ------" << std::endl;
		archivo.close();
	}
	else
	{
		std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
	}
}

int abrirFichero(char seleccion)
{
	if (seleccion == 1)
	{

	}
	else if (seleccion == 2)
	{
		borrarArchivo();
	}
	return 0;
}

void recuperarDatos()
{
	
}

int leerLinea()
{
	return 0;
}

int escribirLinea()
{
	return 0;
}

int guardarDatos()
{
	return 0;
}