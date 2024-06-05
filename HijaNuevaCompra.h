#ifndef HIJANUEVACOMPRA_H
#define HIJANUEVACOMPRA_H
#include "wxfb_project.h"
#include "Clientes.h"

class HijaNuevaCompra : public BaseNuevaCompra {
	
private:
	Clientes *m_data;
protected:
	void ClickAceptarNuevaCompra( wxCommandEvent& event )  override;
	void ClickCancelarNuevaCompra( wxCommandEvent& event )  override;
	
public:
	HijaNuevaCompra(wxWindow *parent,Clientes *a);
	~HijaNuevaCompra();
};

#endif

