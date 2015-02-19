#ifndef VentanaPrincipal_H
#define VentanaPrincipal_H
#include "Ventanas.h"
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/image.h>
#include <wx/animate.h>
#include <stdio.h>

#include "Loader.h"
#include "utils.h"
#include "Cache.h"

class VentanaPrincipal:public Frame0 {
protected:
	//Events
	void ZoomOut( wxCommandEvent& event ) ;
	void ZoomIn( wxCommandEvent& event ) ;
	
	void Share( wxCommandEvent& event ) ;
	void Save( wxCommandEvent& event ) ;
	void Delete( wxCommandEvent& event ) ;
	void Edit( wxCommandEvent& event ) ;
	void Presentation( wxCommandEvent& event ) ;
	
	void RotateLeft( wxCommandEvent& event ) ;
	void RotateRight( wxCommandEvent& event ) ;
	
	void Previous( wxCommandEvent& event ) ;
	void Next( wxCommandEvent& event ) ;
	
	void Open( wxCommandEvent& event ) ;
	
	void Settings( wxCommandEvent& event ) ;
	
	void AddBookmarks( wxCommandEvent& event ) ;
	void Bookmarks( wxCommandEvent& event ) ;
	
	// OpenFile
	wxFileDialog* m_fileCtrl1;
	Loader* loadcall;

public:
	VentanaPrincipal(wxWindow *parent=NULL);
	void OnBotonCerrar(wxCommandEvent &evt);
};

#endif
