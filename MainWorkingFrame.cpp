﻿#include "MainWorkingFrame.h"
#include "./pugixml.hpp"

MainWorkingFrame::MainWorkingFrame( wxWindow* parent )
:
MainFrameBase( parent )
{

}

void MainWorkingFrame::FrameOnPaint( wxPaintEvent& event )
{
// TODO: Implement FrameOnPaint
}

void MainWorkingFrame::FrameOnSize( wxSizeEvent& event )
{
// TODO: Implement FrameOnSize
}

void MainWorkingFrame::FrameOnUpdateUI( wxUpdateUIEvent& event )
{
// TODO: Implement FrameOnUpdateUI
}

void MainWorkingFrame::BtnImportImageClick( wxCommandEvent& event )
{
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("JPG and PNG files (*.jpg;*.png)|*.jpg;*.png"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK){
		wxImage::AddHandler(new wxJPEGHandler);
		wxImage::AddHandler(new wxPNGHandler);

		// oryginalne zdjecie, nie podlega zadnej edycji, Img_Org podlega zmianie tylko gdy zaladujemy nowe zdjecie
		Img_Org = wxImage(WxOpenFileDialog.GetPath(), wxBITMAP_TYPE_ANY);

		if (Img_Org.IsOk()) {
			// wszystkie operacje zwiazane z graficznymi przeksztalceniami robione na Img_Cpy
			Img_Cpy = Img_Org.Copy();

			// odblokowanie sliderow i przyciskow
			m_slider_red->Enable(true);
			m_slider_green->Enable(true);
			m_slider_blue->Enable(true);
			m_button_bichromy->Enable(true);
			m_button_load_parameters->Enable(true);
			m_button_save_image->Enable(true);
			m_button_save_parameters->Enable(true);
			m_button_restore->Enable(true);
			m_toggleBtn_keep_hue->Enable(true);
			m_colourPickerDark->Enable(true);
			m_colourPickerLight->Enable(true);
			m_colourPicker->Enable(true);
			m_slider_mixing_level->SetValue(0);
			m_slider_mixing_level->Enable(false);
			m_toggleBtn_keep_hue->SetValue(false);

			setDefaultMixer();
			Repaint();
		}
	}
}

void MainWorkingFrame::setDefaultMixer()
{
	// zresetowanie ustawien suwakow
	m_slider_red->SetValue(30);
	m_slider_green->SetValue(59);
	m_slider_blue->SetValue(11);
	m_staticText2->SetLabel("Red: 30%");
	m_staticText3->SetLabel("Green: 59%");
	m_staticText4->SetLabel("Blue: 11%");

	// zmieszanie kanalow i wyswietlenie podgladu
	MixChannels(30, 59, 11);
}

void MainWorkingFrame::OnScrollRed( wxScrollEvent& event )
{
	int red = m_slider_red->GetValue();
	int green = m_slider_green->GetValue();
	int blue = m_slider_blue->GetValue();

	// tylko do podgladu
	m_staticText2->SetLabel("Red: " + std::to_string(red) + "%");
	//

	// mieszanie kanalow
	MixChannels(red, green, blue);
	Repaint();
}

void MainWorkingFrame::OnScrollGreen( wxScrollEvent& event )
{
	int red = m_slider_red->GetValue();
	int green = m_slider_green->GetValue();
	int blue = m_slider_blue->GetValue();
	
	// tylko do podgladu
	m_staticText3->SetLabel("Green: " + std::to_string(green) + "%");
	//

	// mieszanie kanalow
	MixChannels(red, green, blue);
	Repaint();
}

void MainWorkingFrame::OnScrollBlue( wxScrollEvent& event )
{
	int red = m_slider_red->GetValue();
	int green = m_slider_green->GetValue();
	int blue = m_slider_blue->GetValue();
	
	// tylko do podgladu
	m_staticText4->SetLabel("Blue: " + std::to_string(blue) + "%");
	//

	// mieszanie kanalow
	MixChannels(red, green, blue);
	Repaint();
}


void MainWorkingFrame::BtnBichromyClick(wxCommandEvent& event)
{
	/////////////////////////////////////
	wxImage* Img_MixResult = &Img_GrayScale; 
	/////////////////////////////////////


	// Pobierz wybrane kolory z Color Pickerow
	wxColour dark_colour = m_colourPickerDark->GetColour();
	wxColour light_colour = m_colourPickerLight->GetColour();

	// Przypisz wartosci do tablicy odcieni
	unsigned char dark_hue[3] = { dark_colour.Red(), dark_colour.Green(), dark_colour.Blue() };
	unsigned char light_hue[3] = { light_colour.Red(), light_colour.Green(), light_colour.Blue() };

	// Przejscie przez kazdy piksel obrazu
	for (size_t x = 0; x < Img_MixResult->GetWidth(); x++) {
		for (size_t y = 0; y < Img_MixResult->GetHeight(); y++) {
			// Uzyskanie wartosci jasnosci dla piksela
			unsigned char r = Img_MixResult->GetRed(x, y);
			unsigned char g = Img_MixResult->GetGreen(x, y);
			unsigned char b = Img_MixResult->GetBlue(x, y);

			// Konwersja do skali szarosci
			unsigned char brightness = 0.3 * r + 0.59 * g + 0.11 * b;

			// Interpolacja liniowa miedzy ciemnym a jasnym odcieniem
			unsigned char interpolated_hue[3];
			for (int i = 0; i < 3; i++) {
				interpolated_hue[i] = (brightness / 255.0) * light_hue[i] + (1 - brightness / 255.0) * dark_hue[i];
			}

			// Przypisanie odcienia do obrazu
			Img_Cpy.SetRGB(x, y, interpolated_hue[0], interpolated_hue[1], interpolated_hue[2]);
		}
	}

	// Odswiezenie obrazu na panelu
	Repaint();
}

void MainWorkingFrame::BtnLoadParametersClick(wxCommandEvent& event)
{
	// Utworz okienko dialogowe do wczytania pliku
	wxFileDialog openFileDialog(this, "Wczytaj ustawienia", "", "", "XML Files (*.xml)|*.xml", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	// Wyswietl okienko dialogowe
	if (openFileDialog.ShowModal() == wxID_OK)
	{
		// Pobierz sciezke wybranek pliku
		wxString filePath = openFileDialog.GetPath();
		pugi::xml_document doc;

		// Wczytaj dokument XML z pliku
		if (!doc.load_file(filePath.ToStdString().c_str()))
		{
			wxMessageBox("Nie mozna wczytac parametrow z pliku!", "Wczytywanie Parametrow", wxOK | wxICON_ERROR);
			return;
		}

		// Pobierz wezel glowny
		pugi::xml_node root = doc.child("Settings");
		if (!root)
		{
			wxMessageBox("Nieprawidlowy format pliku XML!", "Wczytywanie Parametrow", wxOK | wxICON_ERROR);
			return;
		}

		// Znajdź i ustaw wartości suwaków i wyboru koloru
		for (pugi::xml_node parameter = root.child("Parameter"); parameter; parameter = parameter.next_sibling("Parameter"))
		{
			wxString name = parameter.attribute("name").as_string();
			wxString value = parameter.attribute("value").as_string();

			if (name == "RedSlider")
			{
				int redValue = wxAtoi(value);
				m_slider_red->SetValue(redValue);
				m_staticText2->SetLabel("Red: " + std::to_string(redValue) + "%");

			}
			else if (name == "GreenSlider")
			{
				int greenValue = wxAtoi(value);
				m_slider_green->SetValue(greenValue);
				m_staticText3->SetLabel("Green: " + std::to_string(greenValue) + "%");

			}
			else if (name == "BlueSlider")
			{
				int blueValue = wxAtoi(value);
				m_slider_blue->SetValue(blueValue);
				m_staticText4->SetLabel("Blue: " + std::to_string(blueValue) + "%");

			}
			else if (name == "BichromyLightColor")
			{
				wxColour color;
				color.Set(value);
				m_colourPickerLight->SetColour(color);
			}
			else if (name == "BichromyDarkColor")
			{
				wxColour color;
				color.Set(value);
				m_colourPickerDark->SetColour(color);
			}
			else if (name == "KeepingHue")
			{
				bool keepHue = (value == "1" || value.Lower() == "true");
				m_toggleBtn_keep_hue->SetValue(keepHue);
			}
			else if (name == "HueToKeep")
			{
				wxColour color;
				color.Set(value);
				m_colourPicker->SetColour(color);
			}
			else if (name == "MixingRate")
			{
				int mixingRate = wxAtoi(value);
				m_slider_mixing_level->SetValue(mixingRate);
			}
			// Dodaj dodatkowe warunki dla innych parametrów, jeśli jest to konieczne
		}
		MixChannels(m_slider_red->GetValue(), m_slider_green->GetValue(), m_slider_blue->GetValue());
		wxMessageBox("Parametry wczytane pomyslnie!", "Wczytywanie Parametrow", wxOK | wxICON_INFORMATION);
		Repaint();
	}
}

void MainWorkingFrame::BtnSaveParametersClick( wxCommandEvent& event )
{

	wxFileDialog saveFileDialog(this, "Zapisz ustawienia", "", "", "XML Files (*.xml)|*.xml", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	saveFileDialog.SetFilename("Parametry.xml");

	// Wyświetl okienko dialogowe
	if (saveFileDialog.ShowModal() == wxID_OK)
	{
		// Pobierz wybrana nazwe i lokalizacje pliku.
		wxString filePath = saveFileDialog.GetPath();
		pugi::xml_document doc;

		// Utworz wezel glowny
		pugi::xml_node root = doc.append_child("Settings");

		// Dodaj elementy podrzedne z danymi
		pugi::xml_node element1 = root.append_child("Parameter");
		element1.append_attribute("name") = "RedSlider";
		element1.append_attribute("value") = m_slider_red->GetValue();

		pugi::xml_node element2 = root.append_child("Parameter");
		element2.append_attribute("name") = "GreenSlider";
		element2.append_attribute("value") = m_slider_green->GetValue();

		pugi::xml_node element3 = root.append_child("Parameter");
		element3.append_attribute("name") = "BlueSlider";
		element3.append_attribute("value") = m_slider_blue->GetValue();

		pugi::xml_node element4 = root.append_child("Parameter");
		element4.append_attribute("name") = "BichromyLightColor";
		element4.append_attribute("value") = m_colourPickerLight->GetColour().GetAsString();

		pugi::xml_node element5 = root.append_child("Parameter");
		element5.append_attribute("name") = "BichromyDarkColor";
		element5.append_attribute("value") = m_colourPickerDark->GetColour().GetAsString();

		pugi::xml_node element6 = root.append_child("Parameter");
		element6.append_attribute("name") = "KeepingHue";
		element6.append_attribute("value") = m_toggleBtn_keep_hue->GetValue();

		pugi::xml_node element7 = root.append_child("Parameter");
		element7.append_attribute("name") = "HueToKeep";
		element7.append_attribute("value") = m_colourPicker->GetColour().GetAsString();

		pugi::xml_node element8 = root.append_child("Parameter");
		element8.append_attribute("name") = "MixingRate";
		element8.append_attribute("value") = m_slider_mixing_level->GetValue();

		// Zapisz dokument XML do wybranego pliku w czytelnym dla czlowieka formacie
		if (doc.save_file(filePath.ToStdString().c_str(), "  ", pugi::format_default | pugi::format_indent))
		{
			wxMessageBox("Parametry zapisano poprawnie!", "Zapisz parametry", wxOK | wxICON_INFORMATION);
		}
		else
		{
			wxMessageBox("Nie udalo sie zapisac parametrow!", "Napisz parametry", wxOK | wxICON_ERROR);
		}
	}
	}

void MainWorkingFrame::OnScrollMixer( wxScrollEvent& event )
{
	if (m_toggleBtn_keep_hue->GetValue())
	{
		wxCommandEvent evt(wxEVT_COMMAND_BUTTON_CLICKED, m_toggleBtn_keep_hue->GetId());    GetEventHandler()->ProcessEvent(evt); ToggleKeepingHueClick(evt);
	}
}

void MainWorkingFrame::ToggleKeepingHueClick(wxCommandEvent& event)
{

	if (m_toggleBtn_keep_hue->GetValue()) m_slider_mixing_level->Enable(); else m_slider_mixing_level->Disable();

	// dodane, żeby na opracje były przeprowadzane na zdjęciu w skali szarości
	Img_Cpy = Img_GrayScale.Copy();


	// parametr kotrolujący siłę zanikania barw
	double val = (double)m_slider_mixing_level->GetValue() / 100.0;

	// wartosc RGB zczytana z colorpickera
	wxImage::RGBValue picker_RGB(
		m_colourPicker->GetColour().Red(),
		m_colourPicker->GetColour().Green(),
		m_colourPicker->GetColour().Blue()
	);

	// konwersja RGB na HSV
	wxImage::HSVValue picker_HSV = Img_Cpy.RGBtoHSV(picker_RGB);

	// tablica kolorow oryginalnego zdjecia
	unsigned char* colors_org = Img_Org.GetData();
	// tablica kolorow kopii roboczej
	unsigned char* colors_cpy = Img_Cpy.GetData();

	unsigned char* gray_cpy = Img_GrayScale.GetData();

	for (int i = 0; i < Img_Cpy.GetWidth() * Img_Cpy.GetHeight(); i++) {

		// skladowe koloru piksela w oryginalnym obrazie
		int red = colors_org[i * 3];
		int green = colors_org[i * 3 + 1];
		int blue = colors_org[i * 3 + 2];

		// wartosc RGB piksela
		wxImage::RGBValue pixel_RGB(
			red,
			green,
			blue
		);

		// konwersja RGB na HSV
		wxImage::HSVValue pixel_HSV = Img_Cpy.RGBtoHSV(pixel_RGB);

		double diff = fabs(pixel_HSV.hue * 360 - picker_HSV.hue * 360);
		if (diff > 180)
			diff = 360 - diff;

		diff = diff / 180.0;

		if (diff <= val) {
			// jezeli parametr HUE piksela oraz barwy z colorpickera sa takie same to pozostawiamy ten kolor na obrazie
			colors_cpy[i * 3] = colors_org[i * 3];
			colors_cpy[i * 3 + 1] = colors_org[i * 3 + 1];
			colors_cpy[i * 3 + 2] = colors_org[i * 3 + 2];
		}
		else {
			// Jeżeli różnica między odcieniami przekracza ustalony próg (tutaj jest to dwukrotność wartości suwaka), kolor piksela zostaje zamieniony na kolor z obrazu w skali szarości
			if (diff > 2 * val) {
				colors_cpy[i * 3] = gray_cpy[i * 3];
				colors_cpy[i * 3 + 1] = gray_cpy[i * 3 + 1];
				colors_cpy[i * 3 + 2] = gray_cpy[i * 3 + 2];
			}
			else {
				// wówczas miszamy barwy proporcjonalnie do oddalnia od siebie nasycenia kolorów
				int r = std::clamp((double)colors_org[i * 3] * (1.0 - diff), 0., 255.) + std::clamp((double)gray_cpy[i * 3] * diff, 0.0, 255.0);
				int g = std::clamp((double)colors_org[i * 3 + 1] * (1.0 - diff), 0., 255.) + std::clamp((double)gray_cpy[i * 3 + 1] * diff, 0.0, 255.0);
				int b = std::clamp((double)colors_org[i * 3 + 2] * (1.0 - diff), 0., 255.) + std::clamp((double)gray_cpy[i * 3 + 2] * diff, 0.0, 255.0);

				colors_cpy[i * 3] = r;
				colors_cpy[i * 3 + 1] = g;
				colors_cpy[i * 3 + 2] = b;
			}
		}
	}
	Repaint();
}

void MainWorkingFrame::ColorChanged( wxColourPickerEvent& event )
{
// TODO: Implement ColorChanged
}

void MainWorkingFrame::BtnSaveImageClick( wxCommandEvent& event )
{
// TODO: Implement BtnSaveImageClick

	// mozliwosc zapisu w dwoch formatach: JPG i PNG
	wxFileDialog saveFileDialog(this, _("Save image to file"), "", "", "JPG files (*.jpg)|*.jpg|PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	// jezeli uzytkownik zdecyduje sie anulowac zapis
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;

	// sciezka do pliku
	wxFileOutputStream output_stream(saveFileDialog.GetPath());
	
	if (!output_stream.IsOk())
	{
		// error jesli sciezka nieprawidlowa
		wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
		return;
	}
	else {
		Img_Cpy.SetOption("quality", 100);	// najlepsza jakosc zapisu dla plikow JPG
		Img_Cpy.SaveFile(saveFileDialog.GetPath()); // zapis do pliku jezeli wszystko w porzadku
		wxMessageDialog(NULL, "Poprawnie zapisano obraz do pliku.", "Uwaga!", wxOK).ShowModal(); // komunikat o powodzeniu akcji
	}
}

void MainWorkingFrame::Repaint() {
	// podglad na zywo rysowany na podstawie Img_Cpy
	wxImage Img_Preview = Img_Cpy.Copy();

	// wysokosc i szerokosc obrazka
	int w = Img_Org.GetWidth();
	int h = Img_Org.GetHeight();
	
	// przesuniecie obrazu wzgledem lewego gornego rogu w przypadku gdy propocje sie nie zgadzaja
	int shiftX = 0, shiftY = 0;

	wxClientDC dc1(panel_main);
	wxBufferedDC dc(&dc1);

	dc.Clear();

	// skalowanie obrazka z zachowaniem proporcji - dluzszy bok rowny 500px
	if (w>h) {
		Img_Preview = Img_Preview.Rescale(500, (double)h / w * 500);
		shiftY = (double)(500 - Img_Preview.GetHeight()) / 2;
	}
	else {
		Img_Preview = Img_Preview.Rescale((double)w/h*500, 500);
		shiftX = (double)(500 - Img_Preview.GetWidth()) / 2;
	}

	wxBitmap bitmapa(Img_Preview);
	dc.DrawBitmap(bitmapa, shiftX, shiftY);
}

void MainWorkingFrame::MixChannels(int r, int g, int b) {
	// tablice kolorow - kolejne trojki rgb
	// 
	// tablica kolorow oryginalnego zdjecia
	unsigned char* colors_org = Img_Org.GetData();
	// tablica kolorow kopii roboczej
	unsigned char* colors_cpy = Img_Cpy.GetData();

	for (int i = 0; i < Img_Cpy.GetWidth() * Img_Cpy.GetHeight(); i++) {
		// procentowa wartosc suwaka
		double red = (double)r / 100;
		double green = (double)g / 100;
		double blue = (double)b / 100;

		// konwersja do skali szarosci - mieszanie wedlug ustawien uzytkownika
		unsigned char brightness = std::clamp(int(red * colors_org[i * 3] + green * colors_org[i * 3 + 1] + blue *colors_org[i * 3 + 2]), 0, 255);

		// modyfikacja pikseli obrazu
		colors_cpy[i * 3] = brightness;		// r
		colors_cpy[i * 3 + 1] = brightness;	// g
		colors_cpy[i * 3 + 2] = brightness;	// b

		Img_GrayScale = Img_Cpy;
	}
}