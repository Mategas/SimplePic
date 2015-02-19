#include "VentanaPrincipal.h"
using namespace std;

VentanaPrincipal::VentanaPrincipal(wxWindow *parent):Frame0(parent){
	loadcall = NULL;
	Show();
}

void VentanaPrincipal::OnBotonCerrar( wxCommandEvent& event ) { 
	Close();
}

void VentanaPrincipal::Open( wxCommandEvent& event )  {
	
	m_fileCtrl1 = new wxFileDialog( this, wxT("Choose a file"), wxEmptyString, wxEmptyString, wxT("*.*"), wxFD_DEFAULT_STYLE | wxFD_CHANGE_DIR );
	
	m_fileCtrl1->SetWildcard( 
		wxT("Image files (*.bmp; *.png; *.jpeg; *.jpg; *.pcx; *.pnm; *.tiff; *.tga; *.iff; *.xpm; *.ico; *.cur; *.ani; *.gif)|*.bmp;*.png;*.jpeg;*.jpg;*.pcx;*.pnm;*.tiff;*.tga;*.iff;*.xpm;*.ico;*.cur;*.ani;*.gif|All files (*.*)|*.*") 
		);
	
	if ( m_fileCtrl1->ShowModal() == wxID_OK ){
		
		m_animCtrl1->SetInactiveBitmap( wxNullBitmap );
		m_animCtrl1->SetAnimation( wxNullAnimation );
		
		string sp = (m_fileCtrl1->GetPath()).fn_str();
		
		delete loadcall;
		loadcall = new Loader( sp );
		
		if ( loadcall->IsGIF() ){
			m_animCtrl1->SetAnimation( *(loadcall->MostrarAnimacion()) );
			m_animCtrl1->Play();
		}
		else {
			m_animCtrl1->SetInactiveBitmap( wxBitmap( *(loadcall->MostrarImagen()) ) );
			m_animCtrl1->Stop();
		}
		Layout();
		
		
	}
}

void VentanaPrincipal::ZoomOut( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::ZoomIn( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::Share( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::Save( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::RotateLeft( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::Previous( wxCommandEvent& event )  {
	if( loadcall != NULL && !loadcall->BackEndReached() ){
		loadcall->CargarAnt();
		if ( loadcall->IsGIF() ){
			m_animCtrl1->SetAnimation( *(loadcall->MostrarAnimacion()) );
			m_animCtrl1->Play();
		}
		else {
			m_animCtrl1->Stop();
			m_animCtrl1->SetInactiveBitmap( wxBitmap( *(loadcall->MostrarImagen()) ) );
		}
		Layout();
	}
	else
		event.Skip();
}

void VentanaPrincipal::Presentation( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::Next( wxCommandEvent& event )  {
	if( loadcall != NULL && !loadcall->FrontEndReached() ){
		loadcall->CargarSig();
		if ( loadcall->IsGIF() ){
			m_animCtrl1->SetAnimation( *(loadcall->MostrarAnimacion()) );
			m_animCtrl1->Play();
		}
		else {
			m_animCtrl1->Stop();
			m_animCtrl1->SetInactiveBitmap( wxBitmap( *(loadcall->MostrarImagen()) ) );
		}
		Layout();
	}
	else
		event.Skip();
}

void VentanaPrincipal::RotateRight( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::Delete( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::Edit( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::Settings( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::AddBookmarks( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaPrincipal::Bookmarks( wxCommandEvent& event )  {
	event.Skip();
}


