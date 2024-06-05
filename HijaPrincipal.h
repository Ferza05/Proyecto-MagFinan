#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H
#include "wxfb_project.h"
#include "Activos.h"
#include "Pasivos.h"
#include "Clientes.h"
#include "Empleado.h"
#include "Personas.h"

class HijaPrincipal : public BasePrincipal {
	
private:
	Activos *m_activos;
	Pasivos *m_pasivos;
	Clientes *m_clientes;
	Empleado *m_empleado;
	Personas *m_persona;
protected:
	void ClickEstadisticas( wxCommandEvent& event )  override;
	void ClickClientes( wxCommandEvent& event )  override;
	void ClickEmpleados( wxCommandEvent& event )  override;
	void ClickRecoPrincipal( wxCommandEvent& event )  override;
	void ClickCerrarSesion( wxCommandEvent& event )  override;
	void ClickActivos( wxCommandEvent& event )  override;
	void ClickPasivos( wxCommandEvent& event )  override;
	
public:
	HijaPrincipal(wxWindow *parent=NULL);
	~HijaPrincipal();
};

#endif

