///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-282-g1fa54006)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/tglbtn.h>
#include <wx/clrpicker.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	private:

	protected:
		wxButton* btn_import_image;
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxSlider* m_slider_red;
		wxStaticText* m_staticText3;
		wxSlider* m_slider_green;
		wxStaticText* m_staticText4;
		wxSlider* m_slider_blue;
		wxButton* m_button_bichromy;
		wxStaticText* m_staticText5;
		wxButton* m_button_load_parameters;
		wxButton* m_button_save_parameters;
		wxStaticText* m_staticText6;
		wxSlider* m_slider_mixing_level;
		wxStaticText* m_staticText7;
		wxToggleButton* m_toggleBtn_keep_hue;
		wxColourPickerCtrl* m_colourPicker;
		wxPanel* panel_main;
		wxButton* m_button_save_image;

		// Virtual event handlers, override them in your derived class
		virtual void FrameOnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void FrameOnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void FrameOnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void BtnImportImageClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnScrollRed( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnScrollGreen( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnScrollBlue( wxScrollEvent& event ) { event.Skip(); }
		virtual void BtnBichromyClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void BtnLoadParametersClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void BtnSaveParametersClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnScrollMixer( wxScrollEvent& event ) { event.Skip(); }
		virtual void ToggleKeepingHueClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void ColorChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void BtnSaveImageClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Projekt 26 "), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 780,580 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

};

