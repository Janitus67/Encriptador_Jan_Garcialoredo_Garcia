// --- DECLARACIÓNES ---

#include "Encriptador.h"
#include <fstream>
#include <string>
#include <iostream>

// --- FUNCIÓNES ---

std::string encriptadoCesar(std::string mensaje)
{
	std::string resultado = mensaje;
	for (int i = 0; i < resultado.length(); i++)
	{
		if (resultado[i] == 90)
		{
			resultado[i] = 65;
		}
		else if (resultado[i] == 122)
		{
			resultado[i] = 97;
		}
		else
		{
			resultado[i] = resultado[i] + 1;
		}
	}
	return resultado;
}
std::string desencriptadoCesar(std::string mensaje)
{
	std::string resultado = mensaje;
	for (int i = 0; i < resultado.length(); i++)
	{
		if (resultado[i] == 65)
		{
			resultado[i] = 90;
		}
		else if (resultado[i] == 97)
		{
			resultado[i] = 122;
		}
		else
		{
			resultado[i] = resultado[i] - 1;
		}
	}
	return resultado;
}

void calcularCheckSum(std::vector<std::string>& historial)
{
	
}

int generarCheckSum(std::vector<std::string>& historial)
{
	int suma = 0;
	return suma;
}