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

			// zresetowanie ustawien suwakow
			m_slider_red->SetValue(0);
			m_slider_green->SetValue(0);
			m_slider_blue->SetValue(0);
			m_staticText2->SetLabel("Red:");
			m_staticText3->SetLabel("Green:");
			m_staticText4->SetLabel("Blue:");

			Repaint();
		}
	}
}

void MainWorkingFrame::OnScrollRed( wxScrollEvent& event )
{
// TODO: Implement OnScrollRed
	int red = m_slider_red->GetValue();
	// tylko do podgladu
	m_staticText2->SetLabel("Red: " + std::to_string(red) + "%");
	//
	MixChannels(red, -999, -999);
	Repaint();
}

void MainWorkingFrame::OnScrollGreen( wxScrollEvent& event )
{
// TODO: Implement OnScrollGreen
	int green = m_slider_green->GetValue();
	// tylko do podgladu
	m_staticText3->SetLabel("Green: " + std::to_string(green) + "%");
	//
	MixChannels(-999, green, -999);
	Repaint();
}

void MainWorkingFrame::OnScrollBlue( wxScrollEvent& event )
{
// TODO: Implement OnScrollBlue
	int blue = m_slider_blue->GetValue();
	// tylko do podgladu
	m_staticText4->SetLabel("Blue: " + std::to_string(blue) + "%");
	//
	MixChannels(- 999, -999, blue);
	Repaint();
}

void MainWorkingFrame::BtnBichromyClick( wxCommandEvent& event )
{
// TODO: Implement BtnBichromyClick
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
	unsigned char* colors_org = Img_Org.GetData();
	unsigned char* colors_cpy = Img_Cpy.GetData();
	for (int i = 0; i < Img_Cpy.GetWidth() * Img_Cpy.GetHeight(); i++) {
		
		/////////// DO POPRAWY ///////////
		// R channel
		if (r >= -200 && r != 0) {
			int NewRed = (int)colors_org[i * 3] * (double)r / 100;
			NewRed += (int)colors_org[i * 3];
			colors_cpy[i * 3] = (NewRed < 0 ? 0 : NewRed);
			colors_cpy[i * 3] = (NewRed > 255 ? 255 : NewRed);

		}
		// G channel
		if (g >= -200 && g != 0) {
			int NewGreen = (int)colors_org[i * 3 + 1] * (double)g / 100;
			NewGreen += (int)colors_org[i * 3 + 1];
			colors_cpy[i * 3 + 1] = (NewGreen < 0 ? 0 : NewGreen);
			colors_cpy[i * 3 + 1] = (NewGreen > 255 ? 255 : NewGreen);

		}
		// B channel
		if (b >= -200 && b != 0) {
			int NewBlue = (int)colors_org[i * 3 + 2] * (double)b / 100;
			NewBlue += (int)colors_org[i * 3 + 2];
			colors_cpy[i * 3 + 2] = (NewBlue < 0 ? 0 : NewBlue);
			colors_cpy[i * 3 + 2] = (NewBlue > 255 ? 255 : NewBlue);

		}
	}
}