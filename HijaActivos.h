#ifndef HIJAACTIVOS_H
#define HIJAACTIVOS_H
#include "wxfb_project.h"
#include "Activos.h"
#include "Clientes.h"

class HijaActivos : public BaseActivos {
	
private:
	Activos *m_data;
	std::string m_archi_act;
	bool m_modificado=false;
protected:
	void ClickDescontarDinero( wxCommandEvent& event )  override;
	void DobleClickActivos( wxGridEvent& event )  override;
	void ClickEliminarProducto( wxCommandEvent& event )  override;
	void ClickDepositar( wxCommandEvent& event )  override;
	void ClickRetiro( wxCommandEvent& event )  override;
	void ClickAgregarProducto( wxCommandEvent& event )  override;
	void ClickGuardarActivos( wxCommandEvent& event )  override;
	void ClickCargarArchivoActivos( wxCommandEvent& event )  override;
	void ClickAceptarActivos( wxCommandEvent& event )  override;
	void ClickCancelarActivos( wxCommandEvent& event )  override;
	void ActGrillas_Activos();
	void GuardarDatos_Activos();
	
public:
	HijaActivos(wxWindow *parent=NULL);
	~HijaActivos();
};

#endif

