///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __VENTANAS_H__
#define __VENTANAS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/animate.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/toolbar.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define tool1 1000
#define tool2 1001
#define tool3 1002
#define tool4 1003
#define tool5 1004
#define tool6 1005
#define tool7 1006
#define tool8 1007
#define tool9 1008
#define tool10 1009
#define tool11 1010
#define tool12 1011
#define tool13 1012
#define tool14 1013
#define tool15 1014

///////////////////////////////////////////////////////////////////////////////
/// Class Frame0
///////////////////////////////////////////////////////////////////////////////
class Frame0 : public wxFrame 
{
	private:
	
	protected:
		wxAnimationCtrl* m_animCtrl1;
		wxToolBar* m_toolBar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Open( wxCommandEvent& event ) { event.Skip(); }
		virtual void ZoomOut( wxCommandEvent& event ) { event.Skip(); }
		virtual void ZoomIn( wxCommandEvent& event ) { event.Skip(); }
		virtual void Share( wxCommandEvent& event ) { event.Skip(); }
		virtual void Save( wxCommandEvent& event ) { event.Skip(); }
		virtual void RotateLeft( wxCommandEvent& event ) { event.Skip(); }
		virtual void Previous( wxCommandEvent& event ) { event.Skip(); }
		virtual void Presentation( wxCommandEvent& event ) { event.Skip(); }
		virtual void Next( wxCommandEvent& event ) { event.Skip(); }
		virtual void RotateRight( wxCommandEvent& event ) { event.Skip(); }
		virtual void Delete( wxCommandEvent& event ) { event.Skip(); }
		virtual void Edit( wxCommandEvent& event ) { event.Skip(); }
		virtual void Settings( wxCommandEvent& event ) { event.Skip(); }
		virtual void AddBookmarks( wxCommandEvent& event ) { event.Skip(); }
		virtual void Bookmarks( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Frame0( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SimplePic"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 854,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Frame0();
	
};

#endif //__VENTANAS_H__
