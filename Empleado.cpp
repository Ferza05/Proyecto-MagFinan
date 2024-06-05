#include "Empleado.h"
#include <cstring>

Empleado::Empleado(){}
Empleado::Empleado(std::string nya,std::string nacion,int dni,int fecha_nac,
				   std::string ocupacion,int fecha_ingreso,std::string tel,std::string mail):Personas(nya,nacion,dni,fecha_nac) {
	m_ocupacion=ocupacion;
	m_fecha_ingreso=fecha_ingreso;
	m_telefono=tel;
	m_correo=mail;
}
std::string Empleado::verOcupacion(){return m_ocupacion;}
int Empleado::verSalario(){return m_salario;}
int Empleado::verFechaIngreso(){return m_fecha_ingreso;}
std::string Empleado::verTelefono(){return m_telefono;}
std::string Empleado::verCorreo(){return m_correo;}
bool Empleado::verEstado(){return m_activo;}
void Empleado::modOcupacion(std::string n_ocupacion){m_ocupacion=n_ocupacion;}
void Empleado::modSalario(int n_salario){m_salario=n_salario;}
void Empleado::modFechaIngreso(int n_fecha_ingreso){m_fecha_ingreso=n_fecha_ingreso;}
void Empleado::modTelefono(std::string n_telefono){m_telefono=n_telefono;}
void Empleado::modCorreo(std::string n_correo){m_correo=n_correo;}
void Empleado::modEstado(bool n_estado){m_activo=n_estado;}
