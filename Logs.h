#ifndef LOGS_H
#define LOGS_H
#include <string>
#include "Clientes.h"
struct LogsBin{
	char log_bin[45];
	char log_clientes_bin[45];
	char log_prod_bin[15];
};
class Logs {
private:
	std::string m_log;///aaaammdd_codprod_cant_metodo_codcompra_dni
	std::string m_log_clientes;///dni_nya_cant
	std::string m_log_prod;///codprod_cant
public:
	Logs();
	Logs(Clientes c,Productos p);
	std::string verLog();
	std::string verLogClientes();
	std::string verLogProd();
	int verFecha();
	int verCodProd();
	int verCantProd();
	std::string verMetodo();
	int verCodCompra();
	int verDni();
	std::string verNYA();
	void modLog(std::string n_log);///se recomienda usar las tres juntas
	void modLogClientes(std::string n_log_clientes);///se recomienda usar las tres juntas
	void modLogProd(std::string n_log_prod);///se recomienda usar las tres juntas
	void modFecha(int n_Fecha);
	void modCodProd(int n_CodProd);
	void modCantProd(int n_CantProd);
	void modMetodo(std::string n_Metodo);
	void modCodCompra(int n_CodCompra);
	void modDni(int n_Dni);
	void modNYA(std::string n_NYA);
};

#endif

