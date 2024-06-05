#ifndef ACTIVOS_H
#define ACTIVOS_H
#include <vector>
#include <string>
struct Inventario{
	bool activo=true;
	int cod_prod;
	int stock_disponible=0;
	int precio=0;
	char detalle[30]={'N','N'};
	char rubro[30]={'N','N'};;
};
class Activos {
private:
	double m_dinero_caja=0;
	double m_dinero_banco=0;
	double m_dinero_credito=0;
public:
	Activos();
	Activos(double dinero_caja,double dinero_banco,double dinero_credito);
	double verDineroCaja();
	double verDineroBanco();
	double verDineroCredito();
	void modDineroCaja(double n_dinero_caja);
	void modDineroBanco(double n_dinero_banco);
	void modDineroCredito(double n_dinero_credito);
	void Depositar(double cant);
	void Retiro(double cant);
	friend bool operator==(const Inventario& inv1, const Inventario& inv2);
};

#endif

