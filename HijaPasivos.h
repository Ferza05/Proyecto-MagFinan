#ifndef HIJAPASIVOS_H
#define HIJAPASIVOS_H
#include "wxfb_project.h"
#include "Pasivos.h"
#include "Empleado.h"
#include "Activos.h"

class HijaPasivos : public BasePasivos {
	
private:
	Activos *m_data_activos;
	Pasivos *m_data;
	std::string m_archi_act;
	bool m_modificaciones_temp_pasivos=false;
protected:
	void ClickAgregarACasilla( wxCommandEvent& event )  override;
	void ClickMostrarBalance( wxCommandEvent& event )  override;
	void ClickLiquidarTodo( wxCommandEvent& event )  override;
	void ClickLiquidarCasilla( wxCommandEvent& event )  override;
	void ClickGuardarPasivos( wxCommandEvent& event )  override;
	void ClickCargarPasivos( wxCommandEvent& event )  override;
	void DobleClickPasivos( wxGridEvent& event )  override;
	void ClickAceptarPasivos( wxCommandEvent& event )  override;
	void ClickCancelarPasivos( wxCommandEvent& event )  override;
	void ActGrilla_Pasivos();
	void GuardarDatos_Pasivos();
public:
	HijaPasivos(wxWindow *parent=NULL);
	~HijaPasivos();
};

#endif

