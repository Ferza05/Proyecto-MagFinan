#include "Logs.h"
#include "Funciones.h"

Logs::Logs() {
	
}
Logs::Logs(Clientes c,Productos p){
	m_log=std::to_string(c.verFecha_Compra())+"_"+std::to_string(p.cod_prod)+"_"+std::to_string(p.cant_comp)+"_"+c.verMetodoPago()+"_"+std::to_string(c.verCodCompra())+"_"+std::to_string(c.verDNI());
	m_log_clientes=std::to_string(c.verDNI())+"_"+c.verNombreYApellido()+"_"+std::to_string(p.cant_comp);
	m_log_prod=std::to_string(p.cod_prod)+"_"+std::to_string(p.cant_comp);
}
std::string Logs::verLog(){return m_log;}
std::string Logs::verLogClientes(){return m_log_clientes;}
std::string Logs::verLogProd(){return m_log_prod;}
int Logs::verFecha(){
	std::string s=verSeccion(m_log,1);
	return std::atoi(s.c_str());
}
int Logs::verCodProd(){
	std::string s=verSeccion(m_log,2);
	return std::atoi(s.c_str());
}
int Logs::verCantProd(){
	std::string s=verSeccion(m_log,3);
	return std::atoi(s.c_str());
}
std::string Logs::verMetodo(){
	std::string s=verSeccion(m_log,4);
	return s;
}
int Logs::verCodCompra(){
	std::string s=verSeccion(m_log,5);
	return std::atoi(s.c_str());
}
int Logs::verDni(){
	std::string s=verSeccion(m_log,6);
	return std::atoi(s.c_str());
}
std::string Logs::verNYA(){
	std::string s=verSeccion(m_log_clientes,2);
	return s;
}
void Logs::modLog(std::string n_log){m_log=n_log;}
void Logs::modLogClientes(std::string n_log_clientes){m_log_clientes=n_log_clientes;}
void Logs::modLogProd(std::string n_log_prod){m_log_prod=n_log_prod;}
void Logs::modFecha(int n_Fecha){
	modSeccion(m_log,1,std::to_string(n_Fecha));
}
void Logs::modCodProd(int n_CodProd){
	modSeccion(m_log,2,std::to_string(n_CodProd));
	modSeccion(m_log_prod,1,std::to_string(n_CodProd));
}
void Logs::modCantProd(int n_CantProd){
	modSeccion(m_log,3,std::to_string(n_CantProd));
	modSeccion(m_log_prod,2,std::to_string(n_CantProd));
	modSeccion(m_log_clientes,3,std::to_string(n_CantProd));
}
void Logs::modMetodo(std::string n_Metodo){
	modSeccion(m_log,4,n_Metodo);
}
void Logs::modCodCompra(int n_CodCompra){
	modSeccion(m_log,5,std::to_string(n_CodCompra));
}
void Logs::modDni(int n_Dni){
	modSeccion(m_log,6,std::to_string(n_Dni));
	modSeccion(m_log_clientes,1,std::to_string(n_Dni));
}
void Logs::modNYA(std::string n_NYA){
	modSeccion(m_log_clientes,2,n_NYA);
}
