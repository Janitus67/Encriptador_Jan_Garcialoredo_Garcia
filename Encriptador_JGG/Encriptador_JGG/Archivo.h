// --- DECLARACIÓNES ---

#pragma once
#include <vector>
#include <string>
#include "Bienvenida.h"
#include "Encriptador.h"

#define PREFIJO

void abrirArchivo(char seleccion, std::vector<std::string> & historial);
void recuperarDatos(std::vector<std::string> & historial);
void leerLinea(std::vector<std::string> & historial);
void escribirLinea(std::vector<std::string> & historial);
void guardarDatos(std::vector<std::string> & historial);
#define VALOR_PREDETERMINADO 0