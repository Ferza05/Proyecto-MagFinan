///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/tglbtn.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/textctrl.h>
#include <wx/valtext.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BasePrincipal
///////////////////////////////////////////////////////////////////////////////
class BasePrincipal : public wxFrame
{
	private:

	protected:
		wxStaticBitmap* m_bitmap5;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText12;
		wxButton* m_button27;
		wxButton* m_button28;
		wxStaticText* m_staticText121;
		wxToggleButton* m_toggleBtn2;
		wxButton* m_button40;
		wxToggleButton* m_toggleBtn21;
		wxButton* m_button45;
		wxButton* m_button34;

		// Virtual event handlers, override them in your derived class
		virtual void ClickActivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickPasivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEmpleados( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickRecoPrincipal( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEstadisticas( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCerrarSesion( wxCommandEvent& event ) { event.Skip(); }


	public:

		BasePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Menú"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 517,392 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BasePrincipal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseActivos
///////////////////////////////////////////////////////////////////////////////
class BaseActivos : public wxFrame
{
	private:

	protected:
		wxGrid* m_GrillaListaActivos;
		wxGrid* m_GrillaActivosDinero;
		wxGrid* m_GrillaActivos;
		wxButton* m_button221;
		wxButton* m_button23;
		wxTextCtrl* m_textDeposito;
		wxButton* m_button27;
		wxTextCtrl* m_textRetiro;
		wxButton* m_button28;
		wxTextCtrl* m_textDescontarCasilla;
		wxButton* m_button45;
		wxButton* m_button35;
		wxButton* m_button34;
		wxButton* m_button22;
		wxButton* m_button21;

		// Virtual event handlers, override them in your derived class
		virtual void DobleClickActivos( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickEliminarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickDepositar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickRetiro( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickDescontarDinero( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGuardarActivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCargarArchivoActivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAceptarActivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarActivos( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxString Filtro_numerico7;
		wxString Filtro_numerico8;
		wxString Filtro_numerico9;

		BaseActivos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Administrador de Activos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BaseActivos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BasePasivos
///////////////////////////////////////////////////////////////////////////////
class BasePasivos : public wxFrame
{
	private:

	protected:
		wxGrid* m_GrillaListaPasivos;
		wxGrid* m_GrillaPasivos;
		wxButton* m_button201;
		wxButton* m_button211;
		wxTextCtrl* m_textAgregar;
		wxButton* m_button42;
		wxButton* m_button18;
		wxButton* m_button30;
		wxButton* m_button31;
		wxButton* m_button26;
		wxButton* m_button21;

		// Virtual event handlers, override them in your derived class
		virtual void DobleClickPasivos( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickLiquidarTodo( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickLiquidarCasilla( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarACasilla( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickMostrarBalance( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGuardarPasivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCargarPasivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAceptarPasivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarPasivos( wxCommandEvent& event ) { event.Skip(); }


	public:

		BasePasivos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Administrador de Pasivos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BasePasivos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseClientes
///////////////////////////////////////////////////////////////////////////////
class BaseClientes : public wxFrame
{
	private:

	protected:
		wxGrid* m_GrillaListaClientes;
		wxGrid* m_GrillaClientes1;
		wxGrid* m_GrillaClientes2;
		wxGrid* m_GrillaClientes3;
		wxButton* m_button33;
		wxButton* m_button32;
		wxButton* m_button31;
		wxButton* m_button30;
		wxButton* m_button42;
		wxButton* m_button311;
		wxButton* m_button26;
		wxButton* m_button28;
		wxButton* m_button29;

		// Virtual event handlers, override them in your derived class
		virtual void DobleClickClientes( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAgregarCompra( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminarCompra( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickModCant( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGuardarClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCargarClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAceptarClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarClientes( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseClientes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Administrador de Ventas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 893,334 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BaseClientes();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseEmpleado
///////////////////////////////////////////////////////////////////////////////
class BaseEmpleado : public wxFrame
{
	private:

	protected:
		wxGrid* m_GrillaListaEmpleados;
		wxGrid* m_GrillaEmpleados2;
		wxGrid* m_GrillaEmpleados1;
		wxButton* m_button35;
		wxButton* m_button36;
		wxButton* m_button311;
		wxButton* m_button26;
		wxButton* m_button28;
		wxButton* m_button29;

		// Virtual event handlers, override them in your derived class
		virtual void DobleClickEmpleado( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAgregarEmpleado( wxCommandEvent& event ) { event.Skip(); }
		virtual void EliminarEmpleado( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGuardarEmpleados( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCargarEmpleados( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAceptarEmpleado( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarEmpleado( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseEmpleado( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Administrador de Empleados"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 761,350 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BaseEmpleado();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseNuevaCompra
///////////////////////////////////////////////////////////////////////////////
class BaseNuevaCompra : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textDNI;
		wxStaticText* m_staticText12;
		wxChoice* m_choiceMetodoPago;
		wxButton* m_button46;
		wxButton* m_button47;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAceptarNuevaCompra( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarNuevaCompra( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxString Filtro_numerico1;

		BaseNuevaCompra( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Nueva Compra"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP );

		~BaseNuevaCompra();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseNuevoEmpleado
///////////////////////////////////////////////////////////////////////////////
class BaseNuevoEmpleado : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textDNI;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_textSalario;
		wxButton* m_button49;
		wxButton* m_button50;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAceptarNuevoEmpleado( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarNuevoEmpleado( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxString Filtro_numerico2;
		wxString Filtro_numerico3;

		BaseNuevoEmpleado( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Nuevo Empleado"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~BaseNuevoEmpleado();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseNuevoProducto
///////////////////////////////////////////////////////////////////////////////
class BaseNuevoProducto : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textCodigo;
		wxStaticText* m_staticText131;
		wxChoice* m_choiceProd;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_textCantidad;
		wxButton* m_button46;
		wxButton* m_button48;

		// Virtual event handlers, override them in your derived class
		virtual void ClickSeleccionProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxString Filtro_numerico4;
		wxString Filtro_numerico5;

		BaseNuevoProducto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Nuevo Producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~BaseNuevoProducto();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseEstadisticas
///////////////////////////////////////////////////////////////////////////////
class BaseEstadisticas : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText141;
		wxChoice* m_choiceMesProd;
		wxGrid* m_gridProdMes;
		wxStaticText* m_staticText14;
		wxChoice* m_choiceMesClient;
		wxGrid* m_gridClientesMes;
		wxStaticText* m_staticText23;
		wxStaticText* m_staticText18;
		wxCheckBox* m_checkBox2;
		wxTextCtrl* m_textCodProd;
		wxChoice* m_choiceDetalleProd;
		wxCheckBox* m_checkBox3;
		wxTextCtrl* m_textCtrlDNI;
		wxCheckBox* m_checkBox4;
		wxStaticText* m_staticText20;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textCtrlFechaIni;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_textCtrlFechaFin;
		wxButton* m_button43;
		wxStaticText* m_staticText21;
		wxGrid* m_gridResultado;
		wxButton* m_button44;

		// Virtual event handlers, override them in your derived class
		virtual void SeleccionProdMasVendidos( wxCommandEvent& event ) { event.Skip(); }
		virtual void SeleccionClientesMasCompras( wxCommandEvent& event ) { event.Skip(); }
		virtual void SeleccionBusquedaPorCodigo( wxCommandEvent& event ) { event.Skip(); }
		virtual void SeleccionDetalleProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void SeleccionBusquedaPorDNI( wxCommandEvent& event ) { event.Skip(); }
		virtual void SeleccionBusquedaAmbos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscarResultados( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCerrar( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxString Filtro_numerico6;
		wxString Filtro_numerico7;
		wxString Filtro_numerico9;

		BaseEstadisticas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MagFinan - Estadísticas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BaseEstadisticas();

};

