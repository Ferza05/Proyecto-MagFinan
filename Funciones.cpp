#include "Funciones.h"
#include <ctime>
#include <chrono>
#include <wx/string.h>
#include <string>
#include <sstream>
#include <wx/tokenzr.h>

int calcularDiferenciaAnios(int fecha) {
	time_t t = time(0);
	struct tm *now = localtime(&t);
	int anioActual = (now->tm_year + 1900) * 10000 + (now->tm_mon + 1) * 100 + now->tm_mday;
	int diferencia = (anioActual - fecha) / 10000;
	return diferencia;
}

int obtenerFechaDeHoy() {
	auto tiempoActual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm* tmActual = std::localtime(&tiempoActual);
	return (tmActual->tm_year + 1900) * 10000 + (tmActual->tm_mon + 1) * 100 + tmActual->tm_mday;
}

wxString ConvertirFormato_aaaammdd(int aaaammdd) {
	if (aaaammdd!=0) {
		wxString fechaStr = std::to_string(aaaammdd);
		wxString anioStr = fechaStr.SubString(0, 3);
		wxString mesStr = fechaStr.SubString(4, 5);
		wxString diaStr = fechaStr.SubString(6, 7);
		wxString nuevaFecha = diaStr + "/" + mesStr + "/" + anioStr;
		return nuevaFecha;
	}else{return "0";}
}

int ConvertirFormato_ddmmaaaa(wxString fecha) {
	wxStringTokenizer tokenizer(fecha, "/");
	wxString diaStr = tokenizer.GetNextToken();
	wxString mesStr = tokenizer.GetNextToken();
	wxString anioStr = tokenizer.GetNextToken();
	
	if (diaStr.empty() || mesStr.empty() || anioStr.empty()) {return 0;}
	
	int dia = FiltrarYConvertir(diaStr);
	int mes = FiltrarYConvertir(mesStr);
	int anio = FiltrarYConvertir(anioStr);
	
	if (dia == 0 || mes == 0 || anio == 0) {return 0;}
	
	int fechaConvertida = anio * 10000 + mes * 100 + dia;
	return fechaConvertida;
}
double FiltrarYConvertir(wxString texto) {
	wxString resultadoFiltrado;
	for (wxString::const_iterator it = texto.begin(); it != texto.end(); ++it) {
		if (std::isdigit(*it) || *it == '.') {
			resultadoFiltrado += *it;
		}
	}
	double resultado = 0.0;
	if (!resultadoFiltrado.IsEmpty()) {
		resultado=std::atof(resultadoFiltrado.c_str());
	}
	
	return resultado;
}

std::string verSeccion(const std::string &s, int sec) {
	size_t posGuion=0;
	size_t inicio=0;
	
	for(int i=1;i<=sec;++i) {
		if(inicio==std::string::npos) {
			return "X";
		}
		posGuion=s.find("_",inicio);
		if(i==sec) {
			if(posGuion!=std::string::npos) {
				return s.substr(inicio,posGuion-inicio);
			}else{
				return s.substr(inicio);
			}
		}else{
			if(posGuion==std::string::npos) {
				inicio=std::string::npos;
			}else{
				inicio=posGuion+1;
			}
		}
	}
	return "X";
}
void modSeccion(std::string &s, int sec, const std::string &nuevoContenido) {
	size_t inicio=0;
	size_t fin=0;
	
	for(int i=1;i<=sec;++i) {
		inicio=fin;
		while(inicio<s.size() && s[inicio]=='_') {
			++inicio;
		}
		fin=s.find('_',inicio);
		if(fin==std::string::npos) {
			fin=s.size();
		}
		if(i==sec) {
			s.replace(inicio,fin-inicio,nuevoContenido);
			break;
		}
	}
}
