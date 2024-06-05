#ifndef HIJANUEVOEMPLEADO_H
#define HIJANUEVOEMPLEADO_H
#include "wxfb_project.h"
#include "Empleado.h"

class HijaNuevoEmpleado : public BaseNuevoEmpleado {
	
private:
	Empleado *m_data;
protected:
	void ClickAceptarNuevoEmpleado( wxCommandEvent& event )  override;
	void ClickCancelarNuevoEmpleado( wxCommandEvent& event )  override;
	
public:
	HijaNuevoEmpleado(wxWindow *parent,Empleado *a);
	~HijaNuevoEmpleado();
};

#endif

