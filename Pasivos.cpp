#include "Pasivos.h"
#include <fstream>


Pasivos::Pasivos(){}
Pasivos::Pasivos(float salarios,float deuda_proveedor,float servicios_a_pagar,float impuestos_varios){
	m_salarios=salarios;
	m_deuda_proveedor=deuda_proveedor;
	m_servicios_a_pagar=servicios_a_pagar;
	m_impuestos_varios=impuestos_varios;
}
float Pasivos::verSalarios(){return m_salarios;}
float Pasivos::verDeudaProveedor(){return m_deuda_proveedor;}
float Pasivos::verServiciosAPagar(){return m_servicios_a_pagar;}
float Pasivos::verImpuestosVarios(){return m_impuestos_varios;}
void Pasivos::ActualizarRegistro(std::string nomb_archi){
	std::ofstream archi(nomb_archi,std::ios::binary|std::ios::in);
	
}
void Pasivos::CrearRegistro(std::string nomb_archi){}
void Pasivos::modSalarios(float n_salarios){m_salarios=n_salarios;}
void Pasivos::modDeudaProveedor(float n_deuda_proveedor){m_deuda_proveedor=n_deuda_proveedor;}
void Pasivos::modServiciosAPagar(float n_servicios_a_pagar){m_servicios_a_pagar=n_servicios_a_pagar;}
void Pasivos::modImpuestosVarios(float n_impuestos_varios){m_impuestos_varios=n_impuestos_varios;}
