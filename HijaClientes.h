#ifndef HIJACLIENTES_H
#define HIJACLIENTES_H
#include "wxfb_project.h"
#include "Clientes.h"
#include "Activos.h"

class HijaClientes : public BaseClientes {
	
private:
	Clientes *m_data;
	Activos *m_data_activos;
	std::string m_archi_act;
	int m_cliente_pos=0;
	bool m_modificado=false;
protected:
	void ClickModCant( wxCommandEvent& event )  override;
	void DobleClickClientes( wxGridEvent& event )  override;
	void ClickAgregarCompra( wxCommandEvent& event )  override;
	void ClickEliminarCompra( wxCommandEvent& event )  override;
	void ClickAgregarProducto( wxCommandEvent& event )  override;
	void ClickEliminarProducto( wxCommandEvent& event )  override;
	void ClickGuardarClientes( wxCommandEvent& event )  override;
	void ClickCargarClientes( wxCommandEvent& event )  override;
	void ClickAceptarClientes( wxCommandEvent& event )  override;
	void ClickCancelarClientes( wxCommandEvent& event )  override;
	void ActGrillas_Clientes();
	void GuardarDatos_Clientes();
public:
	HijaClientes(wxWindow *parent=NULL);
	~HijaClientes();
};

#endif

