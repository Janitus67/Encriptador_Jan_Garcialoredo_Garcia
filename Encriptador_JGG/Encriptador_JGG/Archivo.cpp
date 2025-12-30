// --- DECLARACIÓNES ---

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Archivo.h"
#include "Encriptador.h"

// --- FUNCIÓNES ---

bool existeArchivo()
{
	std::ifstream archivo("encriptado.txt");
	return archivo.is_open();
}

void borrarArchivo()
{
	std::ofstream archivo("encriptado.txt", std::ios::out | std::ios::trunc);

	if (archivo.is_open())
	{
		archivo << "--- Numero Cifrado -------------------\n" << std::endl;
		archivo << "--- Historial Mensajes Encriptados ---\n" << std::endl;
		archivo << "--- Nuevos Mensajes ------------------\n" << std::endl;
		archivo.close();
	}
	else
	{
		std::cerr << "No se pudo abrir el archivo." << std::endl;
	}
}

void abrirArchivo(char seleccion, std::vector<std::string> & historial)
{
	if (seleccion == 1)
	{
		if (existeArchivo())
		{
			recuperarDatos(historial);
		}

		if (!historial.empty())
		{
			char decision = VALOR_PREDETERMINADO;
			bool entradaValida = false;

			while (!entradaValida)
			{
				std::cout << "\nExisten mensajes previos. Quieres mantenerlos?";
				std::cout << "\n[M] Mantener | [B] Borrar | [V] Volver: ";
				std::cin >> decision;

				if (decision == 'M' || decision == 'm')
				{
					std::cout << "\nManteniendo mensajes...";
					entradaValida = true;
				}
				else if (decision == 'B' || decision == 'b')
				{
					std::cout << "\nBorrando historial...";
					borrarArchivo();
					historial.clear();
					entradaValida = true;
				}
				else if (decision == 'V' || decision == 'v')
				{
					return;
				}
				else
				{
					std::cout << "\nOpcion no valida.";
				}
			}
		}
		else
		{
			std::cout << "\nNo se han encontrado mensajes previos. Preparando entorno...";
			borrarArchivo();
		}

		escribirLinea();
	}
	else if (seleccion == 2)
	{
		std::cout << "\nBorrando mensajes...";
		std::cout << "\nSe ha cargado el archivo limpio...";
		borrarArchivo();
		historial.clear();
		escribirLinea();
	}
}

void recuperarDatos(std::vector<std::string> & historial)
{
	std::ifstream archivo("encriptado.txt");
	std::string linea;
	historial.clear();
	char seleccionado = VALOR_PREDETERMINADO;
	while (std::getline(archivo, linea))
	{
		if (linea.length() >= 3 && linea.substr(0, 3) != "---")
		{
			historial.push_back(linea);
		}
	}
	archivo.close();
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