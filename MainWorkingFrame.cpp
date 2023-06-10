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
}

void MainWorkingFrame::OnScrollRed( wxScrollEvent& event )
{
// TODO: Implement OnScrollRed
}

void MainWorkingFrame::OnScrollGreen( wxScrollEvent& event )
{
// TODO: Implement OnScrollGreen
}

void MainWorkingFrame::OnScrollBlue( wxScrollEvent& event )
{
// TODO: Implement OnScrollBlue
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