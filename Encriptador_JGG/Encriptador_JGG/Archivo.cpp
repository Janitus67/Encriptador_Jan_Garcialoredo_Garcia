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

			while (entradaValida != true)
			{
				std::cout << "\nExisten mensajes previos. Quieres mantenerlos?";
				std::cout << "\n[M] Mantener | [B] Borrar | [V] Volver: ";
				std::cin >> decision;

				if (decision == 'M' || decision == 'm')
				{
					std::cout << "\nManteniendo mensajes...";
					entradaValida = true;
					leerLinea(historial);
					escribirLinea(historial);
				}
				else if (decision == 'B' || decision == 'b')
				{
					std::cout << "\nBorrando historial...";
					entradaValida = true;
					borrarArchivo();
					historial.clear();
					leerLinea(historial);
					escribirLinea(historial);
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
			std::cout << "\nNo se han encontrado mensajes previos. Preparando archivo...";
			//borrarArchivo();
			escribirLinea(historial);
		}
	}
	else if (seleccion == 2)
	{
		std::cout << "\nBorrando mensajes...";
		std::cout << "\nSe esta cargando el archivo...";
		borrarArchivo();
		historial.clear();
		escribirLinea(historial);
	}
}

void recuperarDatos(std::vector<std::string> & historial)
{
	std::ifstream archivo("encriptado.txt");
	std::string linea;
	historial.clear();
	char seleccionado = VALOR_PREDETERMINADO;
	int numLinea = VALOR_PREDETERMINADO;
	while (std::getline(archivo, linea))
	{
		numLinea++;
		if (numLinea == 1) {
			generarCheckSum(historial);
		}
		else if (numLinea >= 3)
		{
			if (linea.length() >= 3 && linea.substr(VALOR_PREDETERMINADO, 3) != "---")
			{
				historial.push_back(desencriptadoCesar(linea));
			}
		}
	}
	archivo.close();
}

void leerLinea(std::vector<std::string> & historial)
{
	std::cout << "\n\n--- Mensajes anteriores ---\n" << std::endl;
	for (const std::string & mensaje : historial)
	{
		std::cout << "=> " << mensaje << std::endl;
	}
	std::cout << "\n\n--- Nuevos mensajes ---" << std::endl;
}

void escribirLinea(std::vector<std::string> & historial)
{
	std::string mensaje;
	bool chatActivo = true;
	std::cin.ignore();
	std::cout << "\nEscribe tu mensaje o [/] para salir al menu o [exit] para guardar y encriptar el documento:\n";
	while (chatActivo == true)
	{
		std::cout << "Mensaje => ";
		std::getline(std::cin, mensaje);

		if (mensaje == "/")
		{
			chatActivo = false;
			system("cls");
			short seleccion = VALOR_PREDETERMINADO;
			guardarDatos(historial);
			Bienvenida(seleccion, historial);
		}
		else if (mensaje == "exit" || mensaje == "EXIT")
		{
			guardarDatos(historial);
			std::cout << "\nCerrando programa...\n\n";
			return;
		}
		else if (!mensaje.empty())
		{
			historial.push_back(mensaje);
		}
	}
}

void guardarDatos(std::vector<std::string> & historial)
{
	std::ofstream archivo("encriptado.txt", std::ios::out | std::ios::trunc);
	if (archivo.is_open())
	{
		std::cout << "Este es el numero de checksum generado para este guardado: ";

		std::cout << generarCheckSum(historial);
		archivo << generarCheckSum(historial) << "\n";

		// Línea 3
		archivo << "--- Historial Mensajes Encriptados ---\n";

		// Línea 4 en adelante: Mensajes CIFRADOS
		for (const std::string& mensaje : historial)
		{
			// Aquí es donde ocurre la magia del encriptador
			archivo << encriptadoCesar(mensaje) << "\n";
		}

		archivo.close();
		std::cout << "\nArchivo actualizado y encriptado." << std::endl;
	}
}