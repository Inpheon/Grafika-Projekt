///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-282-g1fa54006)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 780,580 ), wxSize( 780,580 ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	bSizer2->SetMinSize( wxSize( 250,-1 ) );
	btn_import_image = new wxButton( this, wxID_ANY, wxT("Wczytaj obrazek"), wxDefaultPosition, wxSize( 200,35 ), 0 );
	bSizer2->Add( btn_import_image, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Manipulacje kanalami:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Red:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALL, 5 );

	m_slider_red = new wxSlider( this, wxID_ANY, 0, -200, 200, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	m_slider_red->Enable( false );

	bSizer2->Add( m_slider_red, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Green:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer2->Add( m_staticText3, 0, wxALL, 5 );

	m_slider_green = new wxSlider( this, wxID_ANY, 0, -200, 200, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	m_slider_green->Enable( false );

	bSizer2->Add( m_slider_green, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Blue:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer2->Add( m_staticText4, 0, wxALL, 5 );

	m_slider_blue = new wxSlider( this, wxID_ANY, 0, -200, 200, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	m_slider_blue->Enable( false );

	bSizer2->Add( m_slider_blue, 0, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_button_bichromy = new wxButton( this, wxID_ANY, wxT("Bichromia"), wxDefaultPosition, wxSize( 115,20 ), 0 );
	m_button_bichromy->Enable( false );

	bSizer8->Add( m_button_bichromy, 0, wxALIGN_CENTER|wxALL, 5 );

	m_button_restore = new wxButton( this, wxID_ANY, wxT("Resetuj obrazek"), wxDefaultPosition, wxSize( 115,-1 ), 0 );
	m_button_restore->Enable( false );

	bSizer8->Add( m_button_restore, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer2->Add( bSizer8, 1, wxEXPAND, 5 );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Gradient bichromii:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer2->Add( m_staticText11, 0, wxALL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_colourPickerDark = new wxColourPickerCtrl( this, wxID_ANY, wxColour( 0, 0, 0 ), wxDefaultPosition, wxSize( 115,-1 ), wxCLRP_DEFAULT_STYLE );
	bSizer7->Add( m_colourPickerDark, 0, wxALIGN_CENTER|wxALL, 5 );

	m_colourPickerLight = new wxColourPickerCtrl( this, wxID_ANY, wxColour( 255, 255, 255 ), wxDefaultPosition, wxSize( 115,-1 ), wxCLRP_DEFAULT_STYLE );
	bSizer7->Add( m_colourPickerLight, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer2->Add( bSizer7, 1, wxEXPAND, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Zagadnienia dodatkowe:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer2->Add( m_staticText5, 0, wxALL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_button_load_parameters = new wxButton( this, wxID_ANY, wxT("Wczytaj parametry"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_button_load_parameters->Enable( false );

	bSizer5->Add( m_button_load_parameters, 0, wxALL, 5 );

	m_button_save_parameters = new wxButton( this, wxID_ANY, wxT("Zapisz parametry"), wxDefaultPosition, wxSize( 110,-1 ), 0 );
	m_button_save_parameters->Enable( false );

	bSizer5->Add( m_button_save_parameters, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 1, wxALL|wxEXPAND, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Poziom mieszania:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer2->Add( m_staticText6, 0, wxALL, 5 );

	m_slider_mixing_level = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	m_slider_mixing_level->Enable( false );

	bSizer2->Add( m_slider_mixing_level, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Wybrana barwa:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer2->Add( m_staticText7, 0, wxALL, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_toggleBtn_keep_hue = new wxToggleButton( this, wxID_ANY, wxT("Pozostaw barwe"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_toggleBtn_keep_hue, 0, wxALL, 5 );

	m_colourPicker = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxSize( 120,-1 ), wxCLRP_DEFAULT_STYLE );
	bSizer4->Add( m_colourPicker, 0, wxALL, 5 );


	bSizer2->Add( bSizer4, 1, wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	panel_main = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panel_main->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	panel_main->SetMaxSize( wxSize( 500,500 ) );

	bSizer3->Add( panel_main, 1, wxALIGN_LEFT|wxALL|wxEXPAND, 5 );

	m_button_save_image = new wxButton( this, wxID_ANY, wxT("Zapisz obrazek"), wxDefaultPosition, wxSize( 500,-1 ), 0 );
	m_button_save_image->Enable( false );

	bSizer3->Add( m_button_save_image, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrameBase::FrameOnPaint ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::FrameOnSize ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrameBase::FrameOnUpdateUI ) );
	btn_import_image->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnImportImageClick ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_button_bichromy->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnBichromyClick ), NULL, this );
	m_button_restore->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::btnRestoreImageClick ), NULL, this );
	m_colourPickerDark->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MainFrameBase::bichromyGradientChanged ), NULL, this );
	m_colourPickerLight->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MainFrameBase::bichromyGradientChanged ), NULL, this );
	m_button_load_parameters->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnLoadParametersClick ), NULL, this );
	m_button_save_parameters->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnSaveParametersClick ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_toggleBtn_keep_hue->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::ToggleKeepingHueClick ), NULL, this );
	m_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MainFrameBase::ColorChanged ), NULL, this );
	m_button_save_image->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnSaveImageClick ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrameBase::FrameOnPaint ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::FrameOnSize ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrameBase::FrameOnUpdateUI ) );
	btn_import_image->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnImportImageClick ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_red->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::OnScrollRed ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_green->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::OnScrollGreen ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_slider_blue->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::OnScrollBlue ), NULL, this );
	m_button_bichromy->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnBichromyClick ), NULL, this );
	m_button_restore->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::btnRestoreImageClick ), NULL, this );
	m_colourPickerDark->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MainFrameBase::bichromyGradientChanged ), NULL, this );
	m_colourPickerLight->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MainFrameBase::bichromyGradientChanged ), NULL, this );
	m_button_load_parameters->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnLoadParametersClick ), NULL, this );
	m_button_save_parameters->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnSaveParametersClick ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_slider_mixing_level->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::OnScrollMixer ), NULL, this );
	m_toggleBtn_keep_hue->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::ToggleKeepingHueClick ), NULL, this );
	m_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MainFrameBase::ColorChanged ), NULL, this );
	m_button_save_image->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::BtnSaveImageClick ), NULL, this );

}
