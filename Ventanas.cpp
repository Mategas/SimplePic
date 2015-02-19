///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Ventanas.h"

///////////////////////////////////////////////////////////////////////////

Frame0::Frame0( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 854,480 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWFRAME ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_animCtrl1 = new wxAnimationCtrl( this, wxID_ANY, wxNullAnimation, wxDefaultPosition, wxDefaultSize, wxAC_DEFAULT_STYLE|wxAC_NO_AUTORESIZE ); 
	bSizer1->Add( m_animCtrl1, 1, wxALL|wxEXPAND, 5 );
	
	m_toolBar1 = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL ); 
	m_toolBar1->AddTool( tool1, wxT("Open"), wxBitmap( wxT("GUI/media-eject.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Abrir..."), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool2, wxT("ZoomOut"), wxBitmap( wxT("GUI/zoom-out.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Alejar"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool3, wxT("ZoomIn"), wxBitmap( wxT("GUI/zoom-in.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Acercar"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool4, wxT("Share"), wxBitmap( wxT("GUI/document-send.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Compartir..."), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool5, wxT("Save"), wxBitmap( wxT("GUI/extract-archive.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Guardar..."), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool6, wxT("RotateLeft"), wxBitmap( wxT("GUI/object-rotate-left.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Rotar 270º"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddSeparator(); 
	
	m_toolBar1->AddTool( tool7, wxT("Previous"), wxBitmap( wxT("GUI/media-skip-backward.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Anterior"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool8, wxT("Presentation"), wxBitmap( wxT("GUI/media-playback-start.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Iniciar Presentación"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool9, wxT("Next"), wxBitmap( wxT("GUI/media-skip-forward.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Siguiente"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddSeparator(); 
	
	m_toolBar1->AddTool( tool10, wxT("RotateRight"), wxBitmap( wxT("GUI/object-rotate-right.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Rotar 90º"), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool11, wxT("Delete"), wxBitmap( wxT("GUI/application-exit.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Eliminar..."), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool12, wxT("Edit"), wxBitmap( wxT("GUI/gtk-edit.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Editar..."), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool13, wxT("Settings"), wxBitmap( wxT("GUI/system-run.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Opciones..."), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool14, wxT("AddBookmarks"), wxBitmap( wxT("GUI/folder-new.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Agregar a Marcadores..."), wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( tool15, wxT("Bookmarks"), wxBitmap( wxT("GUI/bookmark-new.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Marcadores..."), wxEmptyString, NULL ); 
	
	m_toolBar1->Realize(); 
	
	bSizer1->Add( m_toolBar1, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( tool1, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Open ) );
	this->Connect( tool2, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::ZoomOut ) );
	this->Connect( tool3, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::ZoomIn ) );
	this->Connect( tool4, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Share ) );
	this->Connect( tool5, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Save ) );
	this->Connect( tool6, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::RotateLeft ) );
	this->Connect( tool7, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Previous ) );
	this->Connect( tool8, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Presentation ) );
	this->Connect( tool9, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Next ) );
	this->Connect( tool10, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::RotateRight ) );
	this->Connect( tool11, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Delete ) );
	this->Connect( tool12, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Edit ) );
	this->Connect( tool13, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Settings ) );
	this->Connect( tool14, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::AddBookmarks ) );
	this->Connect( tool15, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Bookmarks ) );
}

Frame0::~Frame0()
{
	// Disconnect Events
	this->Disconnect( tool1, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Open ) );
	this->Disconnect( tool2, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::ZoomOut ) );
	this->Disconnect( tool3, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::ZoomIn ) );
	this->Disconnect( tool4, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Share ) );
	this->Disconnect( tool5, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Save ) );
	this->Disconnect( tool6, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::RotateLeft ) );
	this->Disconnect( tool7, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Previous ) );
	this->Disconnect( tool8, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Presentation ) );
	this->Disconnect( tool9, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Next ) );
	this->Disconnect( tool10, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::RotateRight ) );
	this->Disconnect( tool11, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Delete ) );
	this->Disconnect( tool12, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Edit ) );
	this->Disconnect( tool13, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Settings ) );
	this->Disconnect( tool14, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::AddBookmarks ) );
	this->Disconnect( tool15, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Frame0::Bookmarks ) );
	
}
