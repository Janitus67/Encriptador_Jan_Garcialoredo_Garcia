// --- DECLARACIÓNES ---

#include <fstream>
#include <iostream>

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
		archivo << "--- Codigo Cifrado -------\n" << std::endl;
		archivo << "--- Historial Mensajes ---\n" << std::endl;
		archivo << "--- Nuevos Mensajes ------\n" << std::endl;
		archivo.close();
	}
	else
	{
		std::cerr << "No se pudo abrir el archivo." << std::endl;
	}
}

void abrirFichero(char seleccion)
{
	if (seleccion == 1)
	{
		if (existeArchivo() == true)
		{
			for (char decision = VALOR_PREDETERMINADO; (decision != 'M') || (decision != 'm') || (decision != 'B') || (decision != 'b') || (decision != 'V') || (decision != 'v');)
			{
				std::cout << "\nExisten mensajes, quieres mantenerlos?";
				std::cout << "\n[M] Mantener mensajes | [B] Borrar mensajes | [V] Volver al menu: ";
				std::cin >> decision;

				if (decision == 'M' || decision == 'm')
				{
					std::cout << "\nCargando mensajes...";
					leerLinea();
					escribirLinea();
					return;
				}
				else if (decision == 'B' || decision == 'b')
				{
					std::cout << "\nBorrando mensajes...";
					std::cout << "\nSe ha cargado el archivo limpio...";
					escribirLinea();
					return;
				}
				else
				{
					std::cout << "\n\nEl caracter que ha introducido no es valido.";
					system("cls");
				}
			}
		}
	}
	else if (seleccion == 2)
	{
		std::cout << "\nBorrando mensajes...";
		std::cout << "\nSe ha cargado el archivo limpio...";
		borrarArchivo();
		escribirLinea();
	}
}

void recuperarDatos()
{
	char seleccionado = VALOR_PREDETERMINADO;
}

void leerLinea()
{
	std::cout << "\n\nDentro de leerLinea\n";
}

void escribirLinea()
{
	std::cout << "\n\nDentro de escribirLinea\n";
}

void guardarDatos()
{
	std::cout << "\n\nDentro de guardarDatos\n";
}