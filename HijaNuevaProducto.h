#ifndef HIJANUEVAPRODUCTO_H
#define HIJANUEVAPRODUCTO_H
#include "wxfb_project.h"
#include "Clientes.h"
#include "Activos.h"

class HijaNuevaProducto : public BaseNuevoProducto {
	
private:
	Clientes *m_data;
	Activos *m_data_activos;
	std::string m_archi_act;
protected:
	void ClickSeleccionProducto( wxCommandEvent& event )  override;
	void ClickAgregar( wxCommandEvent& event )  override;
	void ClickCancelar( wxCommandEvent& event )  override;
	
public:
	HijaNuevaProducto(wxWindow *parent,Clientes *c,Activos *a, std::string nom_archi);
	~HijaNuevaProducto();
};

#endif

