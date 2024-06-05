#include "Personas.h"
#include <string>

Personas::Personas(){}
Personas::Personas(std::string nya,std::string nacion,int dni,int fecha_nac) {
	m_nya=nya;
	m_nacionalidad=nacion;
	m_dni=dni;
	m_fecha_nac=fecha_nac;

}
std::string Personas::verNombreYApellido(){return m_nya;}
std::string Personas::verNacionalidad(){return m_nacionalidad;}
int Personas::verDNI(){return m_dni;}
int Personas::verFecha_Nac(){return m_fecha_nac;}

void Personas::modNombreYApellido(std::string n_nomb){m_nya=n_nomb;}
void Personas::modNacionalidad(std::string n_nacion){m_nacionalidad=n_nacion;}
void Personas::modDNI(int n_dni){m_dni=n_dni;}
void Personas::modFecha_Nac(int n_fecha_nac){m_fecha_nac=n_fecha_nac;}



