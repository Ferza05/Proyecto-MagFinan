///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

BasePrincipal::BasePrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVECAPTION ) );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_bitmap5 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("data/source img/user-manage_114453.ico"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_bitmap5, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("¡Bienvenido a MagFinan!\n"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer14->Add( m_staticText6, 1, wxALL, 5 );


	bSizer9->Add( bSizer14, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Gestor Financiero"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer25->Add( m_staticText12, 0, wxALL, 5 );


	bSizer9->Add( bSizer25, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_button27 = new wxButton( this, wxID_ANY, wxT("Administrar Activos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button27, 1, wxALL, 5 );

	m_button28 = new wxButton( this, wxID_ANY, wxT("Administrar Pasivos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button28, 1, wxALL, 5 );


	bSizer9->Add( bSizer15, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer251;
	bSizer251 = new wxBoxSizer( wxVERTICAL );

	m_staticText121 = new wxStaticText( this, wxID_ANY, wxT("Gestor de Ventas y Empleados"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText121->Wrap( -1 );
	bSizer251->Add( m_staticText121, 0, wxALL, 5 );


	bSizer9->Add( bSizer251, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_toggleBtn2 = new wxToggleButton( this, wxID_ANY, wxT("Administrar Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_toggleBtn2, 1, wxALL, 5 );

	m_button40 = new wxButton( this, wxID_ANY, wxT("Administrar Empleados"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button40, 1, wxALL, 5 );


	bSizer9->Add( bSizer16, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );

	m_toggleBtn21 = new wxToggleButton( this, wxID_ANY, wxT("Manual de Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_toggleBtn21, 0, wxALL, 5 );

	m_button45 = new wxButton( this, wxID_ANY, wxT("Estadísticas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button45, 0, wxALL, 5 );


	bSizer9->Add( bSizer17, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );

	m_button34 = new wxButton( this, wxID_ANY, wxT("Cerrar Sesión"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer60->Add( m_button34, 0, wxALL, 5 );


	bSizer9->Add( bSizer60, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickActivos ), NULL, this );
	m_button28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickPasivos ), NULL, this );
	m_toggleBtn2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickClientes ), NULL, this );
	m_button40->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickEmpleados ), NULL, this );
	m_toggleBtn21->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickRecoPrincipal ), NULL, this );
	m_button45->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickEstadisticas ), NULL, this );
	m_button34->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickCerrarSesion ), NULL, this );
}

BasePrincipal::~BasePrincipal()
{
	// Disconnect Events
	m_button27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickActivos ), NULL, this );
	m_button28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickPasivos ), NULL, this );
	m_toggleBtn2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickClientes ), NULL, this );
	m_button40->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickEmpleados ), NULL, this );
	m_toggleBtn21->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickRecoPrincipal ), NULL, this );
	m_button45->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickEstadisticas ), NULL, this );
	m_button34->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickCerrarSesion ), NULL, this );

}

BaseActivos::BaseActivos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );

	m_GrillaListaActivos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaListaActivos->CreateGrid( 12, 1 );
	m_GrillaListaActivos->EnableEditing( false );
	m_GrillaListaActivos->EnableGridLines( true );
	m_GrillaListaActivos->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_GrillaListaActivos->EnableDragGridSize( false );
	m_GrillaListaActivos->SetMargins( 0, 0 );

	// Columns
	m_GrillaListaActivos->SetColSize( 0, 150 );
	m_GrillaListaActivos->EnableDragColMove( false );
	m_GrillaListaActivos->EnableDragColSize( false );
	m_GrillaListaActivos->SetColLabelValue( 0, wxT("Archivos") );
	m_GrillaListaActivos->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaListaActivos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaListaActivos->EnableDragRowSize( true );
	m_GrillaListaActivos->SetRowLabelSize( 0 );
	m_GrillaListaActivos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaListaActivos->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer42->Add( m_GrillaListaActivos, 0, wxALL, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );

	m_GrillaActivosDinero = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaActivosDinero->CreateGrid( 1, 3 );
	m_GrillaActivosDinero->EnableEditing( false );
	m_GrillaActivosDinero->EnableGridLines( true );
	m_GrillaActivosDinero->EnableDragGridSize( false );
	m_GrillaActivosDinero->SetMargins( 0, 0 );

	// Columns
	m_GrillaActivosDinero->SetColSize( 0, 250 );
	m_GrillaActivosDinero->SetColSize( 1, 250 );
	m_GrillaActivosDinero->SetColSize( 2, 250 );
	m_GrillaActivosDinero->EnableDragColMove( false );
	m_GrillaActivosDinero->EnableDragColSize( false );
	m_GrillaActivosDinero->SetColLabelValue( 0, wxT("Dinero en Caja") );
	m_GrillaActivosDinero->SetColLabelValue( 1, wxT("Dinero en Banco") );
	m_GrillaActivosDinero->SetColLabelValue( 2, wxT("Dinero en Creditos") );
	m_GrillaActivosDinero->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaActivosDinero->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaActivosDinero->AutoSizeRows();
	m_GrillaActivosDinero->EnableDragRowSize( false );
	m_GrillaActivosDinero->SetRowLabelSize( 0 );
	m_GrillaActivosDinero->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance
	m_GrillaActivosDinero->SetLabelBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	// Cell Defaults
	m_GrillaActivosDinero->SetDefaultCellBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_GrillaActivosDinero->SetDefaultCellTextColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_GrillaActivosDinero->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	m_GrillaActivosDinero->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_GrillaActivosDinero->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

	bSizer43->Add( m_GrillaActivosDinero, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxHORIZONTAL );

	m_GrillaActivos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaActivos->CreateGrid( 0, 5 );
	m_GrillaActivos->EnableEditing( true );
	m_GrillaActivos->EnableGridLines( true );
	m_GrillaActivos->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_GrillaActivos->EnableDragGridSize( false );
	m_GrillaActivos->SetMargins( 0, 0 );

	// Columns
	m_GrillaActivos->SetColSize( 0, 100 );
	m_GrillaActivos->SetColSize( 1, 50 );
	m_GrillaActivos->SetColSize( 2, 120 );
	m_GrillaActivos->SetColSize( 3, 120 );
	m_GrillaActivos->SetColSize( 4, 75 );
	m_GrillaActivos->EnableDragColMove( false );
	m_GrillaActivos->EnableDragColSize( false );
	m_GrillaActivos->SetColLabelValue( 0, wxT("Cod. de Producto") );
	m_GrillaActivos->SetColLabelValue( 1, wxT("Stock") );
	m_GrillaActivos->SetColLabelValue( 2, wxT("Detalle") );
	m_GrillaActivos->SetColLabelValue( 3, wxT("Rubro") );
	m_GrillaActivos->SetColLabelValue( 4, wxT("Precio") );
	m_GrillaActivos->SetColLabelValue( 5, wxEmptyString );
	m_GrillaActivos->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaActivos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaActivos->EnableDragRowSize( true );
	m_GrillaActivos->SetRowLabelSize( 0 );
	m_GrillaActivos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaActivos->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer44->Add( m_GrillaActivos, 0, wxALL|wxEXPAND, 5 );

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 2, 0, 0 );

	m_button221 = new wxButton( this, wxID_ANY, wxT("Eliminar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_button221, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Agregar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_button23, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_textDeposito = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textDeposito->SetToolTip( wxT("Importe del Deposito") );

	m_textDeposito->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico7 ) );

	gSizer2->Add( m_textDeposito, 0, wxALL|wxALIGN_RIGHT, 5 );

	m_button27 = new wxButton( this, wxID_ANY, wxT("Deposito"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_button27, 0, wxALL, 5 );

	m_textRetiro = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textRetiro->SetToolTip( wxT("Importe del Retiro") );

	m_textRetiro->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico8 ) );

	gSizer2->Add( m_textRetiro, 0, wxALL|wxALIGN_RIGHT, 5 );

	m_button28 = new wxButton( this, wxID_ANY, wxT("Retiro"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_button28, 0, wxALL, 5 );

	m_textDescontarCasilla = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textDescontarCasilla->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico9 ) );

	gSizer2->Add( m_textDescontarCasilla, 0, wxALL|wxALIGN_RIGHT, 5 );

	m_button45 = new wxButton( this, wxID_ANY, wxT("Descontar Dinero Seleccionado"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_button45, 0, wxALL, 5 );


	bSizer44->Add( gSizer2, 0, wxALL, 5 );


	bSizer43->Add( bSizer44, 1, wxEXPAND, 5 );


	bSizer42->Add( bSizer43, 1, wxEXPAND, 5 );


	bSizer17->Add( bSizer42, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_button35 = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button35, 0, wxALL, 5 );

	m_button34 = new wxButton( this, wxID_ANY, wxT("Cargar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button34, 0, wxALL, 5 );

	m_button22 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button22, 0, wxALL, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Cancelar "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button21, 0, wxALL, 5 );


	bSizer17->Add( bSizer20, 0, wxALIGN_RIGHT|wxALL, 5 );


	this->SetSizer( bSizer17 );
	this->Layout();
	bSizer17->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_GrillaListaActivos->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( BaseActivos::DobleClickActivos ), NULL, this );
	m_button221->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickEliminarProducto ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickAgregarProducto ), NULL, this );
	m_button27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickDepositar ), NULL, this );
	m_button28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickRetiro ), NULL, this );
	m_button45->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickDescontarDinero ), NULL, this );
	m_button35->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickGuardarActivos ), NULL, this );
	m_button34->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickCargarArchivoActivos ), NULL, this );
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickAceptarActivos ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickCancelarActivos ), NULL, this );
}

BaseActivos::~BaseActivos()
{
	// Disconnect Events
	m_GrillaListaActivos->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( BaseActivos::DobleClickActivos ), NULL, this );
	m_button221->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickEliminarProducto ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickAgregarProducto ), NULL, this );
	m_button27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickDepositar ), NULL, this );
	m_button28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickRetiro ), NULL, this );
	m_button45->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickDescontarDinero ), NULL, this );
	m_button35->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickGuardarActivos ), NULL, this );
	m_button34->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickCargarArchivoActivos ), NULL, this );
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickAceptarActivos ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseActivos::ClickCancelarActivos ), NULL, this );

}

BasePasivos::BasePasivos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );

	m_GrillaListaPasivos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaListaPasivos->CreateGrid( 12, 1 );
	m_GrillaListaPasivos->EnableEditing( false );
	m_GrillaListaPasivos->EnableGridLines( true );
	m_GrillaListaPasivos->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_GrillaListaPasivos->EnableDragGridSize( false );
	m_GrillaListaPasivos->SetMargins( 0, 0 );

	// Columns
	m_GrillaListaPasivos->SetColSize( 0, 150 );
	m_GrillaListaPasivos->EnableDragColMove( false );
	m_GrillaListaPasivos->EnableDragColSize( true );
	m_GrillaListaPasivos->SetColLabelValue( 0, wxT("Archivos") );
	m_GrillaListaPasivos->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaListaPasivos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaListaPasivos->EnableDragRowSize( true );
	m_GrillaListaPasivos->SetRowLabelSize( 0 );
	m_GrillaListaPasivos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaListaPasivos->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer24->Add( m_GrillaListaPasivos, 0, wxALL, 5 );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	m_GrillaPasivos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaPasivos->CreateGrid( 1, 4 );
	m_GrillaPasivos->EnableEditing( false );
	m_GrillaPasivos->EnableGridLines( true );
	m_GrillaPasivos->EnableDragGridSize( false );
	m_GrillaPasivos->SetMargins( 0, 0 );

	// Columns
	m_GrillaPasivos->SetColSize( 0, 100 );
	m_GrillaPasivos->SetColSize( 1, 120 );
	m_GrillaPasivos->SetColSize( 2, 120 );
	m_GrillaPasivos->SetColSize( 3, 100 );
	m_GrillaPasivos->EnableDragColMove( false );
	m_GrillaPasivos->EnableDragColSize( true );
	m_GrillaPasivos->SetColLabelValue( 0, wxT("Deudas Varias") );
	m_GrillaPasivos->SetColLabelValue( 1, wxT("Impuestos Varios") );
	m_GrillaPasivos->SetColLabelValue( 2, wxT("Salarios Mensuales") );
	m_GrillaPasivos->SetColLabelValue( 3, wxT("Servicios Varios") );
	m_GrillaPasivos->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaPasivos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaPasivos->EnableDragRowSize( true );
	m_GrillaPasivos->SetRowLabelSize( 0 );
	m_GrillaPasivos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaPasivos->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer25->Add( m_GrillaPasivos, 0, wxALL, 5 );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	m_button201 = new wxButton( this, wxID_ANY, wxT("Liquidación Final"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_button201, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button211 = new wxButton( this, wxID_ANY, wxT("Liquidar Selección"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_button211, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_textAgregar = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_textAgregar, 0, wxALL|wxALIGN_RIGHT, 5 );

	m_button42 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_button42, 0, wxALL, 5 );


	bSizer25->Add( gSizer1, 0, wxEXPAND, 5 );

	m_button18 = new wxButton( this, wxID_ANY, wxT("Mostrar Balance del Mes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_button18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer24->Add( bSizer25, 0, wxALL, 5 );


	bSizer23->Add( bSizer24, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_button30 = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button30, 0, wxALL, 5 );

	m_button31 = new wxButton( this, wxID_ANY, wxT("Cargar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button31, 0, wxALL, 5 );

	m_button26 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button26, 0, wxALL, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Cancelar "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_button21, 0, wxALL, 5 );


	bSizer23->Add( bSizer20, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer23 );
	this->Layout();
	bSizer23->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_GrillaListaPasivos->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( BasePasivos::DobleClickPasivos ), NULL, this );
	m_button201->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickLiquidarTodo ), NULL, this );
	m_button211->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickLiquidarCasilla ), NULL, this );
	m_button42->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickAgregarACasilla ), NULL, this );
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickMostrarBalance ), NULL, this );
	m_button30->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickGuardarPasivos ), NULL, this );
	m_button31->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickCargarPasivos ), NULL, this );
	m_button26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickAceptarPasivos ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickCancelarPasivos ), NULL, this );
}

BasePasivos::~BasePasivos()
{
	// Disconnect Events
	m_GrillaListaPasivos->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( BasePasivos::DobleClickPasivos ), NULL, this );
	m_button201->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickLiquidarTodo ), NULL, this );
	m_button211->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickLiquidarCasilla ), NULL, this );
	m_button42->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickAgregarACasilla ), NULL, this );
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickMostrarBalance ), NULL, this );
	m_button30->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickGuardarPasivos ), NULL, this );
	m_button31->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickCargarPasivos ), NULL, this );
	m_button26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickAceptarPasivos ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasivos::ClickCancelarPasivos ), NULL, this );

}

BaseClientes::BaseClientes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_GrillaListaClientes = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaListaClientes->CreateGrid( 0, 1 );
	m_GrillaListaClientes->EnableEditing( false );
	m_GrillaListaClientes->EnableGridLines( true );
	m_GrillaListaClientes->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_GrillaListaClientes->EnableDragGridSize( false );
	m_GrillaListaClientes->SetMargins( 0, 0 );

	// Columns
	m_GrillaListaClientes->SetColSize( 0, 150 );
	m_GrillaListaClientes->EnableDragColMove( false );
	m_GrillaListaClientes->EnableDragColSize( false );
	m_GrillaListaClientes->SetColLabelValue( 0, wxT("Ventas") );
	m_GrillaListaClientes->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaListaClientes->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaListaClientes->EnableDragRowSize( true );
	m_GrillaListaClientes->SetRowLabelSize( 0 );
	m_GrillaListaClientes->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaListaClientes->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer28->Add( m_GrillaListaClientes, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_GrillaClientes1 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaClientes1->CreateGrid( 1, 5 );
	m_GrillaClientes1->EnableEditing( false );
	m_GrillaClientes1->EnableGridLines( true );
	m_GrillaClientes1->EnableDragGridSize( false );
	m_GrillaClientes1->SetMargins( 0, 0 );

	// Columns
	m_GrillaClientes1->SetColSize( 0, 150 );
	m_GrillaClientes1->SetColSize( 1, 100 );
	m_GrillaClientes1->SetColSize( 2, 150 );
	m_GrillaClientes1->SetColSize( 3, 120 );
	m_GrillaClientes1->SetColSize( 4, 120 );
	m_GrillaClientes1->EnableDragColMove( false );
	m_GrillaClientes1->EnableDragColSize( false );
	m_GrillaClientes1->SetColLabelValue( 0, wxT("Codigo de Compra") );
	m_GrillaClientes1->SetColLabelValue( 1, wxT("Pago") );
	m_GrillaClientes1->SetColLabelValue( 2, wxT("Cant. de Articulos") );
	m_GrillaClientes1->SetColLabelValue( 3, wxT("Metodo de Pago") );
	m_GrillaClientes1->SetColLabelValue( 4, wxT("Fecha de Compra") );
	m_GrillaClientes1->SetColLabelValue( 5, wxT("Cuotas") );
	m_GrillaClientes1->SetColLabelValue( 6, wxT("Intereses") );
	m_GrillaClientes1->SetColLabelValue( 7, wxEmptyString );
	m_GrillaClientes1->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaClientes1->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaClientes1->EnableDragRowSize( true );
	m_GrillaClientes1->SetRowLabelSize( 0 );
	m_GrillaClientes1->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaClientes1->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer29->Add( m_GrillaClientes1, 0, wxALL, 5 );

	m_GrillaClientes2 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaClientes2->CreateGrid( 1, 2 );
	m_GrillaClientes2->EnableEditing( true );
	m_GrillaClientes2->EnableGridLines( true );
	m_GrillaClientes2->EnableDragGridSize( false );
	m_GrillaClientes2->SetMargins( 0, 0 );

	// Columns
	m_GrillaClientes2->SetColSize( 0, 150 );
	m_GrillaClientes2->SetColSize( 1, 100 );
	m_GrillaClientes2->EnableDragColMove( false );
	m_GrillaClientes2->EnableDragColSize( true );
	m_GrillaClientes2->SetColLabelValue( 0, wxT("Nombre y Apellido") );
	m_GrillaClientes2->SetColLabelValue( 1, wxT("DNI") );
	m_GrillaClientes2->SetColLabelValue( 2, wxEmptyString );
	m_GrillaClientes2->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaClientes2->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaClientes2->EnableDragRowSize( true );
	m_GrillaClientes2->SetRowLabelSize( 0 );
	m_GrillaClientes2->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaClientes2->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer29->Add( m_GrillaClientes2, 0, wxALL, 5 );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	m_GrillaClientes3 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaClientes3->CreateGrid( 0, 5 );
	m_GrillaClientes3->EnableEditing( false );
	m_GrillaClientes3->EnableGridLines( true );
	m_GrillaClientes3->EnableDragGridSize( false );
	m_GrillaClientes3->SetMargins( 0, 0 );

	// Columns
	m_GrillaClientes3->SetColSize( 0, 100 );
	m_GrillaClientes3->SetColSize( 1, 60 );
	m_GrillaClientes3->SetColSize( 2, 120 );
	m_GrillaClientes3->SetColSize( 3, 120 );
	m_GrillaClientes3->SetColSize( 4, 60 );
	m_GrillaClientes3->EnableDragColMove( false );
	m_GrillaClientes3->EnableDragColSize( false );
	m_GrillaClientes3->SetColLabelValue( 0, wxT("Cod. de Producto") );
	m_GrillaClientes3->SetColLabelValue( 1, wxT("Cantidad") );
	m_GrillaClientes3->SetColLabelValue( 2, wxT("Detalle") );
	m_GrillaClientes3->SetColLabelValue( 3, wxT("Rubro") );
	m_GrillaClientes3->SetColLabelValue( 4, wxT("Precio") );
	m_GrillaClientes3->SetColLabelValue( 5, wxEmptyString );
	m_GrillaClientes3->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaClientes3->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaClientes3->EnableDragRowSize( true );
	m_GrillaClientes3->SetRowLabelSize( 0 );
	m_GrillaClientes3->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaClientes3->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer31->Add( m_GrillaClientes3, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 0 );

	m_button33 = new wxButton( this, wxID_ANY, wxT("Agregar Venta"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_button33, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button32 = new wxButton( this, wxID_ANY, wxT("Eliminar Venta"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_button32, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button31 = new wxButton( this, wxID_ANY, wxT("Agregar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_button31, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button30 = new wxButton( this, wxID_ANY, wxT("Eliminar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_button30, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer42->Add( gSizer3, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button42 = new wxButton( this, wxID_ANY, wxT("Modificar Cantidad Comprada"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button42->SetToolTip( wxT("Esta opcion modifica la cantidad comprada del articulo seleccionado.") );

	bSizer42->Add( m_button42, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer31->Add( bSizer42, 1, wxEXPAND, 5 );


	bSizer29->Add( bSizer31, 1, wxEXPAND, 5 );


	bSizer28->Add( bSizer29, 0, wxEXPAND, 5 );


	bSizer27->Add( bSizer28, 1, 0, 5 );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_button311 = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button311, 0, wxALL, 5 );

	m_button26 = new wxButton( this, wxID_ANY, wxT("Cargar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button26, 0, wxALL, 5 );

	m_button28 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button28, 0, wxALL, 5 );

	m_button29 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button29, 0, wxALL, 5 );


	bSizer27->Add( bSizer30, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer27 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_GrillaListaClientes->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( BaseClientes::DobleClickClientes ), NULL, this );
	m_button33->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickAgregarCompra ), NULL, this );
	m_button32->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickEliminarCompra ), NULL, this );
	m_button31->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickAgregarProducto ), NULL, this );
	m_button30->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickEliminarProducto ), NULL, this );
	m_button42->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickModCant ), NULL, this );
	m_button311->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickGuardarClientes ), NULL, this );
	m_button26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickCargarClientes ), NULL, this );
	m_button28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickAceptarClientes ), NULL, this );
	m_button29->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickCancelarClientes ), NULL, this );
}

BaseClientes::~BaseClientes()
{
	// Disconnect Events
	m_GrillaListaClientes->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( BaseClientes::DobleClickClientes ), NULL, this );
	m_button33->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickAgregarCompra ), NULL, this );
	m_button32->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickEliminarCompra ), NULL, this );
	m_button31->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickAgregarProducto ), NULL, this );
	m_button30->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickEliminarProducto ), NULL, this );
	m_button42->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickModCant ), NULL, this );
	m_button311->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickGuardarClientes ), NULL, this );
	m_button26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickCargarClientes ), NULL, this );
	m_button28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickAceptarClientes ), NULL, this );
	m_button29->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClientes::ClickCancelarClientes ), NULL, this );

}

BaseEmpleado::BaseEmpleado( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	m_GrillaListaEmpleados = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaListaEmpleados->CreateGrid( 0, 1 );
	m_GrillaListaEmpleados->EnableEditing( false );
	m_GrillaListaEmpleados->EnableGridLines( true );
	m_GrillaListaEmpleados->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_GrillaListaEmpleados->EnableDragGridSize( false );
	m_GrillaListaEmpleados->SetMargins( 0, 0 );

	// Columns
	m_GrillaListaEmpleados->SetColSize( 0, 150 );
	m_GrillaListaEmpleados->EnableDragColMove( false );
	m_GrillaListaEmpleados->EnableDragColSize( true );
	m_GrillaListaEmpleados->SetColLabelValue( 0, wxT("Empleados") );
	m_GrillaListaEmpleados->SetColLabelSize( wxGRID_AUTOSIZE );
	m_GrillaListaEmpleados->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaListaEmpleados->EnableDragRowSize( true );
	m_GrillaListaEmpleados->SetRowLabelSize( 0 );
	m_GrillaListaEmpleados->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaListaEmpleados->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	m_GrillaListaEmpleados->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );
	m_GrillaListaEmpleados->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	bSizer23->Add( m_GrillaListaEmpleados, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	m_GrillaEmpleados2 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaEmpleados2->CreateGrid( 1, 5 );
	m_GrillaEmpleados2->EnableEditing( true );
	m_GrillaEmpleados2->EnableGridLines( true );
	m_GrillaEmpleados2->EnableDragGridSize( false );
	m_GrillaEmpleados2->SetMargins( 0, 0 );

	// Columns
	m_GrillaEmpleados2->SetColSize( 0, 100 );
	m_GrillaEmpleados2->SetColSize( 1, 100 );
	m_GrillaEmpleados2->SetColSize( 2, 120 );
	m_GrillaEmpleados2->SetColSize( 3, 100 );
	m_GrillaEmpleados2->SetColSize( 4, 150 );
	m_GrillaEmpleados2->EnableDragColMove( false );
	m_GrillaEmpleados2->EnableDragColSize( true );
	m_GrillaEmpleados2->SetColLabelValue( 0, wxT("Ocupación") );
	m_GrillaEmpleados2->SetColLabelValue( 1, wxT("Salario") );
	m_GrillaEmpleados2->SetColLabelValue( 2, wxT("Fecha de Ingreso") );
	m_GrillaEmpleados2->SetColLabelValue( 3, wxT("Telefono") );
	m_GrillaEmpleados2->SetColLabelValue( 4, wxT("Correo") );
	m_GrillaEmpleados2->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaEmpleados2->EnableDragRowSize( true );
	m_GrillaEmpleados2->SetRowLabelSize( 0 );
	m_GrillaEmpleados2->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaEmpleados2->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer25->Add( m_GrillaEmpleados2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_GrillaEmpleados1 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaEmpleados1->CreateGrid( 1, 2 );
	m_GrillaEmpleados1->EnableEditing( true );
	m_GrillaEmpleados1->EnableGridLines( true );
	m_GrillaEmpleados1->EnableDragGridSize( false );
	m_GrillaEmpleados1->SetMargins( 0, 0 );

	// Columns
	m_GrillaEmpleados1->SetColSize( 0, 150 );
	m_GrillaEmpleados1->SetColSize( 1, 100 );
	m_GrillaEmpleados1->EnableDragColMove( false );
	m_GrillaEmpleados1->EnableDragColSize( true );
	m_GrillaEmpleados1->SetColLabelValue( 0, wxT("Nombre y Apellido") );
	m_GrillaEmpleados1->SetColLabelValue( 1, wxT("DNI") );
	m_GrillaEmpleados1->SetColLabelValue( 2, wxEmptyString );
	m_GrillaEmpleados1->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaEmpleados1->EnableDragRowSize( true );
	m_GrillaEmpleados1->SetRowLabelSize( 0 );
	m_GrillaEmpleados1->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaEmpleados1->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer25->Add( m_GrillaEmpleados1, 0, wxALL, 5 );

	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 0, 2, 0, 0 );

	m_button35 = new wxButton( this, wxID_ANY, wxT("Agregar Empleado"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( m_button35, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button36 = new wxButton( this, wxID_ANY, wxT("Eliminar Empleado"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( m_button36, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer25->Add( gSizer4, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer23->Add( bSizer25, 1, 0, 5 );


	bSizer22->Add( bSizer23, 1, 0, 5 );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_button311 = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button311, 0, wxALL, 5 );

	m_button26 = new wxButton( this, wxID_ANY, wxT("Cargar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button26, 0, wxALL, 5 );

	m_button28 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button28, 0, wxALL, 5 );

	m_button29 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button29, 0, wxALL, 5 );


	bSizer22->Add( bSizer30, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer22 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_GrillaListaEmpleados->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( BaseEmpleado::DobleClickEmpleado ), NULL, this );
	m_button35->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickAgregarEmpleado ), NULL, this );
	m_button36->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::EliminarEmpleado ), NULL, this );
	m_button311->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickGuardarEmpleados ), NULL, this );
	m_button26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickCargarEmpleados ), NULL, this );
	m_button28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickAceptarEmpleado ), NULL, this );
	m_button29->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickCancelarEmpleado ), NULL, this );
}

BaseEmpleado::~BaseEmpleado()
{
	// Disconnect Events
	m_GrillaListaEmpleados->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( BaseEmpleado::DobleClickEmpleado ), NULL, this );
	m_button35->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickAgregarEmpleado ), NULL, this );
	m_button36->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::EliminarEmpleado ), NULL, this );
	m_button311->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickGuardarEmpleados ), NULL, this );
	m_button26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickCargarEmpleados ), NULL, this );
	m_button28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickAceptarEmpleado ), NULL, this );
	m_button29->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEmpleado::ClickCancelarEmpleado ), NULL, this );

}

BaseNuevaCompra::BaseNuevaCompra( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Por favor, ingrese el DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer36->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer32->Add( bSizer36, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer33->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textDNI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textDNI->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico1 ) );

	bSizer33->Add( m_textDNI, 1, wxALL, 5 );


	bSizer32->Add( bSizer33, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Metodo de Pago:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer34->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceMetodoPagoChoices[] = { wxT("Efectivo"), wxT("Banco"), wxT("Credito") };
	int m_choiceMetodoPagoNChoices = sizeof( m_choiceMetodoPagoChoices ) / sizeof( wxString );
	m_choiceMetodoPago = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceMetodoPagoNChoices, m_choiceMetodoPagoChoices, 0 );
	m_choiceMetodoPago->SetSelection( 0 );
	bSizer34->Add( m_choiceMetodoPago, 0, wxALL, 5 );


	bSizer32->Add( bSizer34, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );


	bSizer32->Add( bSizer35, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_button46 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( m_button46, 0, wxALL, 5 );

	m_button47 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( m_button47, 1, wxALL, 5 );


	bSizer32->Add( bSizer37, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer32 );
	this->Layout();
	bSizer32->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button46->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevaCompra::ClickAceptarNuevaCompra ), NULL, this );
	m_button47->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevaCompra::ClickCancelarNuevaCompra ), NULL, this );
}

BaseNuevaCompra::~BaseNuevaCompra()
{
	// Disconnect Events
	m_button46->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevaCompra::ClickAceptarNuevaCompra ), NULL, this );
	m_button47->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevaCompra::ClickCancelarNuevaCompra ), NULL, this );

}

BaseNuevoEmpleado::BaseNuevoEmpleado( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Por favor, ingrese los datos obligatorios \npara registrar un nuevo empleado:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer48->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer44->Add( bSizer48, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer45->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textDNI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textDNI->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico2 ) );

	bSizer45->Add( m_textDNI, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer44->Add( bSizer45, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Salario:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer46->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textSalario = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( m_textSalario, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer44->Add( bSizer46, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxHORIZONTAL );

	m_button49 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( m_button49, 0, wxALL, 5 );

	m_button50 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( m_button50, 0, wxALL, 5 );


	bSizer44->Add( bSizer47, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer44 );
	this->Layout();
	bSizer44->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button49->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevoEmpleado::ClickAceptarNuevoEmpleado ), NULL, this );
	m_button50->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevoEmpleado::ClickCancelarNuevoEmpleado ), NULL, this );
}

BaseNuevoEmpleado::~BaseNuevoEmpleado()
{
	// Disconnect Events
	m_button49->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevoEmpleado::ClickAceptarNuevoEmpleado ), NULL, this );
	m_button50->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevoEmpleado::ClickCancelarNuevoEmpleado ), NULL, this );

}

BaseNuevoProducto::BaseNuevoProducto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Ingrese el codigo del producto y la cantidad del mismo."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer44->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer43->Add( bSizer44, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Codigo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer45->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCodigo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCodigo->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico4 ) );

	bSizer45->Add( m_textCodigo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText131 = new wxStaticText( this, wxID_ANY, wxT("Detalle:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	bSizer45->Add( m_staticText131, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxArrayString m_choiceProdChoices;
	m_choiceProd = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceProdChoices, 0 );
	m_choiceProd->SetSelection( 0 );
	bSizer45->Add( m_choiceProd, 0, wxALL, 5 );


	bSizer43->Add( bSizer45, 1, 0, 5 );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Cantidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer46->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCantidad->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico5 ) );

	bSizer46->Add( m_textCantidad, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer43->Add( bSizer46, 1, 0, 5 );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxHORIZONTAL );

	m_button46 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( m_button46, 0, wxALL, 5 );

	m_button48 = new wxButton( this, wxID_ANY, wxT("Cancelar "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( m_button48, 0, wxALL, 5 );


	bSizer43->Add( bSizer47, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer43 );
	this->Layout();
	bSizer43->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_choiceProd->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseNuevoProducto::ClickSeleccionProducto ), NULL, this );
	m_button46->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevoProducto::ClickAgregar ), NULL, this );
	m_button48->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevoProducto::ClickCancelar ), NULL, this );
}

BaseNuevoProducto::~BaseNuevoProducto()
{
	// Disconnect Events
	m_choiceProd->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseNuevoProducto::ClickSeleccionProducto ), NULL, this );
	m_button46->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevoProducto::ClickAgregar ), NULL, this );
	m_button48->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseNuevoProducto::ClickCancelar ), NULL, this );

}

BaseEstadisticas::BaseEstadisticas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Estadísticas Mensuales y Anuales"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	m_staticText24->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer43->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer471;
	bSizer471 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText141 = new wxStaticText( this, wxID_ANY, wxT("Productos mas vendidos de: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	m_staticText141->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer471->Add( m_staticText141, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceMesProdChoices[] = { wxT("Enero"), wxT("Febrero"), wxT("Marzo"), wxT("Abril"), wxT("Mayo"), wxT("Junio"), wxT("Julio"), wxT("Agosto"), wxT("Septiembre"), wxT("Octubre"), wxT("Noviembre"), wxT("Diciembre"), wxT("Todo el Año") };
	int m_choiceMesProdNChoices = sizeof( m_choiceMesProdChoices ) / sizeof( wxString );
	m_choiceMesProd = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceMesProdNChoices, m_choiceMesProdChoices, 0 );
	m_choiceMesProd->SetSelection( 0 );
	bSizer471->Add( m_choiceMesProd, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer46->Add( bSizer471, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_gridProdMes = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridProdMes->CreateGrid( 5, 4 );
	m_gridProdMes->EnableEditing( true );
	m_gridProdMes->EnableGridLines( true );
	m_gridProdMes->EnableDragGridSize( false );
	m_gridProdMes->SetMargins( 0, 0 );

	// Columns
	m_gridProdMes->SetColSize( 0, 130 );
	m_gridProdMes->SetColSize( 1, 120 );
	m_gridProdMes->SetColSize( 2, 150 );
	m_gridProdMes->SetColSize( 3, 150 );
	m_gridProdMes->EnableDragColMove( false );
	m_gridProdMes->EnableDragColSize( true );
	m_gridProdMes->SetColLabelValue( 0, wxT("Codigo del Producto") );
	m_gridProdMes->SetColLabelValue( 1, wxT("Cantidad Vendida") );
	m_gridProdMes->SetColLabelValue( 2, wxT("Detalle") );
	m_gridProdMes->SetColLabelValue( 3, wxT("Rubro") );
	m_gridProdMes->SetColLabelSize( wxGRID_AUTOSIZE );
	m_gridProdMes->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridProdMes->EnableDragRowSize( true );
	m_gridProdMes->SetRowLabelSize( 0 );
	m_gridProdMes->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridProdMes->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer46->Add( m_gridProdMes, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer44->Add( bSizer46, 1, 0, 5 );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Clientes que mas compraron de:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer47->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceMesClientChoices[] = { wxT("Enero"), wxT("Febrero"), wxT("Marzo"), wxT("Abril"), wxT("Mayo"), wxT("Junio"), wxT("Julio"), wxT("Agosto"), wxT("Septiembre"), wxT("Octubre"), wxT("Noviembre"), wxT("Diciembre"), wxT("Todo el Año") };
	int m_choiceMesClientNChoices = sizeof( m_choiceMesClientChoices ) / sizeof( wxString );
	m_choiceMesClient = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceMesClientNChoices, m_choiceMesClientChoices, 0 );
	m_choiceMesClient->SetSelection( 0 );
	bSizer47->Add( m_choiceMesClient, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer45->Add( bSizer47, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_gridClientesMes = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridClientesMes->CreateGrid( 5, 3 );
	m_gridClientesMes->EnableEditing( false );
	m_gridClientesMes->EnableGridLines( true );
	m_gridClientesMes->EnableDragGridSize( false );
	m_gridClientesMes->SetMargins( 0, 0 );

	// Columns
	m_gridClientesMes->SetColSize( 0, 100 );
	m_gridClientesMes->SetColSize( 1, 150 );
	m_gridClientesMes->SetColSize( 2, 120 );
	m_gridClientesMes->EnableDragColMove( false );
	m_gridClientesMes->EnableDragColSize( false );
	m_gridClientesMes->SetColLabelValue( 0, wxT("DNI") );
	m_gridClientesMes->SetColLabelValue( 1, wxT("Nombre y Apellido") );
	m_gridClientesMes->SetColLabelValue( 2, wxT("Cantidad Comprada") );
	m_gridClientesMes->SetColLabelSize( wxGRID_AUTOSIZE );
	m_gridClientesMes->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridClientesMes->EnableDragRowSize( true );
	m_gridClientesMes->SetRowLabelSize( 0 );
	m_gridClientesMes->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridClientesMes->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer45->Add( m_gridClientesMes, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer44->Add( bSizer45, 0, wxEXPAND, 5 );


	bSizer43->Add( bSizer44, 0, wxEXPAND, 5 );

	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Conteo de Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	m_staticText23->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer43->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxVERTICAL );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Busqueda por:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	m_staticText18->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Calibri") ) );

	bSizer54->Add( m_staticText18, 0, wxALL, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBox2 = new wxCheckBox( this, wxID_ANY, wxT("Código del Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_checkBox2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCodProd = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 45,23 ), 0 );
	m_textCodProd->Enable( false );

	m_textCodProd->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico6 ) );

	bSizer56->Add( m_textCodProd, 0, wxALL, 5 );

	wxArrayString m_choiceDetalleProdChoices;
	m_choiceDetalleProd = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDetalleProdChoices, 0 );
	m_choiceDetalleProd->SetSelection( 0 );
	m_choiceDetalleProd->Enable( false );

	bSizer56->Add( m_choiceDetalleProd, 0, wxALL, 5 );


	bSizer54->Add( bSizer56, 1, 0, 5 );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBox3 = new wxCheckBox( this, wxID_ANY, wxT("DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_checkBox3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlDNI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlDNI->Enable( false );

	m_textCtrlDNI->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico7 ) );

	bSizer58->Add( m_textCtrlDNI, 0, wxALL, 5 );


	bSizer54->Add( bSizer58, 1, 0, 5 );

	m_checkBox4 = new wxCheckBox( this, wxID_ANY, wxT("Código del Producto y DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_checkBox4, 0, wxALL, 5 );


	bSizer52->Add( bSizer54, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bSizer51->Add( bSizer52, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );

	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Periodo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	m_staticText20->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer60->Add( m_staticText20, 0, wxALL, 5 );

	wxBoxSizer* bSizer511;
	bSizer511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Fecha Inicial:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer511->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlFechaIni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer511->Add( m_textCtrlFechaIni, 0, wxALL, 5 );


	bSizer60->Add( bSizer511, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Fecha Final:  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer53->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlFechaFin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrlFechaFin->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &Filtro_numerico9 ) );

	bSizer53->Add( m_textCtrlFechaFin, 0, wxALL, 5 );


	bSizer60->Add( bSizer53, 0, wxEXPAND, 5 );

	m_button43 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer60->Add( m_button43, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer51->Add( bSizer60, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Resultados de la Búsqueda:\n"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	m_staticText21->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer61->Add( m_staticText21, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_gridResultado = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridResultado->CreateGrid( 1, 2 );
	m_gridResultado->EnableEditing( true );
	m_gridResultado->EnableGridLines( true );
	m_gridResultado->EnableDragGridSize( false );
	m_gridResultado->SetMargins( 0, 0 );

	// Columns
	m_gridResultado->SetColSize( 0, 100 );
	m_gridResultado->SetColSize( 1, 150 );
	m_gridResultado->EnableDragColMove( false );
	m_gridResultado->EnableDragColSize( true );
	m_gridResultado->SetColLabelValue( 0, wxT("X") );
	m_gridResultado->SetColLabelValue( 1, wxT("Cantidad Vendida") );
	m_gridResultado->SetColLabelSize( wxGRID_AUTOSIZE );
	m_gridResultado->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridResultado->EnableDragRowSize( true );
	m_gridResultado->SetRowLabelSize( 0 );
	m_gridResultado->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridResultado->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer61->Add( m_gridResultado, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer51->Add( bSizer61, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer43->Add( bSizer51, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );

	m_button44 = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( m_button44, 0, wxALL, 5 );


	bSizer43->Add( bSizer68, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer43 );
	this->Layout();
	bSizer43->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_choiceMesProd->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseEstadisticas::SeleccionProdMasVendidos ), NULL, this );
	m_choiceMesClient->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseEstadisticas::SeleccionClientesMasCompras ), NULL, this );
	m_checkBox2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseEstadisticas::SeleccionBusquedaPorCodigo ), NULL, this );
	m_choiceDetalleProd->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseEstadisticas::SeleccionDetalleProducto ), NULL, this );
	m_checkBox3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseEstadisticas::SeleccionBusquedaPorDNI ), NULL, this );
	m_checkBox4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseEstadisticas::SeleccionBusquedaAmbos ), NULL, this );
	m_button43->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEstadisticas::ClickBuscarResultados ), NULL, this );
	m_button44->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEstadisticas::ClickCerrar ), NULL, this );
}

BaseEstadisticas::~BaseEstadisticas()
{
	// Disconnect Events
	m_choiceMesProd->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseEstadisticas::SeleccionProdMasVendidos ), NULL, this );
	m_choiceMesClient->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseEstadisticas::SeleccionClientesMasCompras ), NULL, this );
	m_checkBox2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseEstadisticas::SeleccionBusquedaPorCodigo ), NULL, this );
	m_choiceDetalleProd->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseEstadisticas::SeleccionDetalleProducto ), NULL, this );
	m_checkBox3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseEstadisticas::SeleccionBusquedaPorDNI ), NULL, this );
	m_checkBox4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseEstadisticas::SeleccionBusquedaAmbos ), NULL, this );
	m_button43->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEstadisticas::ClickBuscarResultados ), NULL, this );
	m_button44->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEstadisticas::ClickCerrar ), NULL, this );

}
