#ifndef HIJAEMPLEADO_H
#define HIJAEMPLEADO_H
#include "wxfb_project.h"
#include "Empleado.h"
#include "Pasivos.h"

class HijaEmpleado : public BaseEmpleado {
	
private:
	Empleado *m_data;
	Pasivos *m_data_pasivos;
	std::string m_archi_act;
	int m_empleado_pos;
	bool m_modificado=false;
protected:
	void DobleClickEmpleado( wxGridEvent& event )  override;
	void ClickAgregarEmpleado( wxCommandEvent& event )  override;
	void EliminarEmpleado( wxCommandEvent& event )  override;
	void ClickGuardarEmpleados( wxCommandEvent& event )  override;
	void ClickCargarEmpleados( wxCommandEvent& event )  override;
	void ClickAceptarEmpleado( wxCommandEvent& event )  override;
	void ClickCancelarEmpleado( wxCommandEvent& event )  override;
	void ActGrillas_Empleado();
	void GuardarDatos_Empleado();
public:
	HijaEmpleado(wxWindow *parent=NULL);
	~HijaEmpleado();
};

#endif

