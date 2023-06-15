#include "MainWorkingFrame.h"

MainWorkingFrame::MainWorkingFrame( wxWindow* parent )
:
MainFrameBase( parent )
{

}

cimg_library::CImg<unsigned char> MainWorkingFrame::wxImageToCImg(const wxImage& image)
{
	cimg_library::CImg<unsigned char> img(image.GetWidth(), image.GetHeight(), 1, 3);

	for (size_t x = 0; x < image.GetWidth(); x++) {
		for (size_t y = 0; y < image.GetHeight(); y++) {
			img(x, y, 0, 0) = image.GetRed(x, y);
			img(x, y, 0, 1) = image.GetGreen(x, y);
			img(x, y, 0, 2) = image.GetBlue(x, y);
		}
	}

	return img;
}

wxImage MainWorkingFrame::CImgTowxImage(const cimg_library::CImg<unsigned char>& image)
{
	// Create a new wxImage with the same dimensions as the CImg image
	wxImage img(image.width(), image.height());

	// Get pointers to the image data
	unsigned char* imgData = img.GetData();

	// Copy the pixel data from the CImg image to the wxImage
	size_t index = 0;
	for (size_t y = 0; y < image.height(); ++y) {
		for (size_t x = 0; x < image.width(); ++x) {
			imgData[index++] = image(x, y, 0, 0); // Red
			imgData[index++] = image(x, y, 0, 1); // Green
			imgData[index++] = image(x, y, 0, 2); // Blue
		}
	}

	return img;
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
// TODO: Implement BtnImportImageClick
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("JPG and PNG files (*.jpg;*.png)|*.jpg;*.png"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK){
		wxImage::AddHandler(new wxJPEGHandler);
		wxImage::AddHandler(new wxPNGHandler);

		// oryginalne zdjecie, nie podlega zadnej edycji, Img_Org podlega zmianie tylko gdy zaladujemy nowe zdjecie
		Img_Org = wxImage(WxOpenFileDialog.GetPath(), wxBITMAP_TYPE_JPEG);

		if (Img_Org.IsOk()) {
			// wszystkie operacje zwiazane z graficznymi przeksztalceniami robione na Img_Cpy
			Img_Cpy = Img_Org.Copy();

			// odblokowanie sliderow i przyciskow
			m_slider_red->Enable(true);
			m_slider_green->Enable(true);
			m_slider_blue->Enable(true);
			m_slider_mixing_level->Enable(true);
			m_button_bichromy->Enable(true);
			m_button_load_parameters->Enable(true);
			m_button_save_image->Enable(true);
			m_button_save_parameters->Enable(true);
			m_button_restore->Enable(true);

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
// TODO: Implement OnScrollRed
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
// TODO: Implement OnScrollGreen
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
// TODO: Implement OnScrollBlue
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



void MainWorkingFrame::BtnLoadParametersClick( wxCommandEvent& event )
{
// TODO: Implement BtnLoadParametersClick
}

void MainWorkingFrame::BtnSaveParametersClick( wxCommandEvent& event )
{
// TODO: Implement BtnSaveParametersClick
}

void MainWorkingFrame::OnScrollMixer( wxScrollEvent& event )
{
// TODO: Implement OnScrollMixer
}

void MainWorkingFrame::ToggleKeepingHueClick( wxCommandEvent& event )
{
// TODO: Implement ToggleKeepingHueClick
}

void MainWorkingFrame::ColorChanged( wxColourPickerEvent& event )
{
// TODO: Implement ColorChanged
}

void MainWorkingFrame::BtnSaveImageClick( wxCommandEvent& event )
{
// TODO: Implement BtnSaveImageClick
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