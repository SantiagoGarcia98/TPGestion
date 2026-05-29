
#pragma once
#include <string>

///Validaciones
   bool validarDNI( char *dni);
   bool esTelefonoValido( char* tel);
bool emailExisteEnSistema( std::string email);
std::string cargarCadena();
bool confirmarAccion(const char* mensaje  );

bool Volver(const char* texto);
bool existeEnSistema(char* valor, const char* tipoCampo);
void pantallaInicio();
void imprimirCentrado(const std::string& texto, int ancho=80);
