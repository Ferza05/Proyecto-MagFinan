#ifndef HIJAESTADISTICAS_H
#define HIJAESTADISTICAS_H
#include "wxfb_project.h"
#include <string>

class HijaEstadisticas : public BaseEstadisticas {
	
private:
	
protected:
	void SeleccionDetalleProducto( wxCommandEvent& event )  override;
	void SeleccionProdMasVendidos( wxCommandEvent& event )  override;
	void SeleccionClientesMasCompras( wxCommandEvent& event )  override;
	void ClickBuscarResultados( wxCommandEvent& event )  override;
	void ClickCerrar( wxCommandEvent& event )  override;
	void SeleccionBusquedaPorCodigo( wxCommandEvent& event )  override;
	void SeleccionBusquedaPorDNI( wxCommandEvent& event )  override;
	void SeleccionBusquedaAmbos( wxCommandEvent& event )  override;
	void ActualizarGrillasClientes(std::string nom_archi);
	void ActualizarGrillasProd(std::string nom_archi);
public:
	HijaEstadisticas(wxWindow *parent=NULL);
	~HijaEstadisticas();
};

#endif

