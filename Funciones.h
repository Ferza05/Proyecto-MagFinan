#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <wx/string.h>

int calcularDiferenciaAnios(int fecha);

int obtenerFechaDeHoy();

/// para convertir un c-string, o una constante, a wxString
inline wxString c_to_wx(const char *c_str) {
	return wxString::From8BitData(c_str);
}
/// para convertir un std::string a wxString
inline wxString std_to_wx(const std::string &std_str) {
	return wxString::From8BitData(std_str.c_str());
}
/// para convertir wxString a std::string
inline std::string wx_to_std(const wxString &wx_str) {
	return static_cast<const char*>(wx_str.To8BitData());
}
wxString ConvertirFormato_aaaammdd(int aaaammdd);

int ConvertirFormato_ddmmaaaa(wxString fecha);

double FiltrarYConvertir(wxString texto);

std::string verSeccion(const std::string &s,int sec);
void modSeccion(std::string &s,int sec,const std::string &nuevoContenido);

#endif
