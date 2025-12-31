// --- DECLARACIÓNES ---

#pragma once
#include <vector>
#include <string>

std::string encriptadoCesar(std::string mensaje);
std::string desencriptadoCesar(std::string mensaje);
void calcularCheckSum(std::vector<std::string> & historial);
int generarCheckSum(std::vector<std::string> & historial);