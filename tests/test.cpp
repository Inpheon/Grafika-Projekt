#include"pch.h"
#include <gtest/gtest.h>
#include <wx/stdpaths.h>

#include "../MainWorkingFrame.h"
#include "../MainWorkingFrame.cpp"
#include "../GUI.h"
#include "../GUI.cpp"
#include "../pugiconfig.hpp"
#include "../pugixml.hpp"
#include "../pugixml.cpp"

//
//przed wykonaniem testów należy zmienić wszystkie elementy w klasie MainWorkingFrame na public (nie może być protected oraz private)
//dodatkowo należy do ciała klasy dodać metodę symulującą kliknięcie:
    /*void SimulateButtonClick(wxButton* button) {
        wxCommandEvent event(wxEVT_COMMAND_BUTTON_CLICKED, button->GetId());
        button->GetEventHandler()->ProcessEvent(event);
    }*/
//

TEST(MainWorkingFrameTest, SetDefaultMixer) {
    wxWindow* test = nullptr;
    MainWorkingFrame frame(test);
    frame.setDefaultMixer();

    //sprawdzanie wartosci ustawionych przez SetDefaultMixer
    EXPECT_EQ(frame.m_slider_red->GetValue(), 30);
    EXPECT_EQ(frame.m_slider_green->GetValue(), 59);
    EXPECT_EQ(frame.m_slider_blue->GetValue(), 11);
    EXPECT_EQ(frame.m_staticText2->GetLabel(), "Red: 30%");
    EXPECT_EQ(frame.m_staticText3->GetLabel(), "Green: 59%");
    EXPECT_EQ(frame.m_staticText4->GetLabel(), "Blue: 11%");
}

TEST(MainWorkingFrameTest, OnScrollRedTest) {
    MainWorkingFrame frame(nullptr);
    frame.m_slider_red->SetValue(50);
    frame.m_slider_green->SetValue(60);
    frame.m_slider_blue->SetValue(70);

    frame.OnScrollRed(wxScrollEvent());

    EXPECT_EQ(frame.m_slider_red->GetValue(), 50);
    EXPECT_EQ(frame.m_staticText2->GetLabel(), "Red: 50%");

}

TEST(MainWorkingFrameTest, OnScrollGreenTest) {
    MainWorkingFrame frame(nullptr);
    frame.m_slider_red->SetValue(50);
    frame.m_slider_green->SetValue(60);
    frame.m_slider_blue->SetValue(70);

    wxScrollEvent event;
    frame.OnScrollGreen(event);

    EXPECT_EQ(frame.m_slider_green->GetValue(), 60);
    std::string expectedLabel = "Green: 60%";
    EXPECT_EQ(frame.m_staticText3->GetLabel(), expectedLabel);
}

TEST(MainWorkingFrameTest, OnScrollBlueTest) {
    MainWorkingFrame frame(nullptr);
    frame.m_slider_red->SetValue(50);
    frame.m_slider_green->SetValue(60);
    frame.m_slider_blue->SetValue(70);

    wxScrollEvent event;
    frame.OnScrollBlue(event);

    EXPECT_EQ(frame.m_slider_blue->GetValue(), 70);
    std::string expectedLabel = "Blue: 70%";
    EXPECT_EQ(frame.m_staticText4->GetLabel(), expectedLabel);
}

TEST(MainWorkingFrameTest, BtnSaveParametersClickTest_Success)
{
    MainWorkingFrame frame(nullptr);

    //ustawienie wartosci poczatkowych
    frame.m_slider_red->SetValue(100);
    frame.m_slider_green->SetValue(150);
    frame.m_slider_blue->SetValue(200);
    frame.m_colourPickerLight->SetColour(wxColour(255, 255, 255));
    frame.m_colourPickerDark->SetColour(wxColour(0, 0, 0));
    frame.m_toggleBtn_keep_hue->SetValue(true);
    frame.m_colourPicker->SetColour(wxColour(128, 128, 128));
    frame.m_slider_mixing_level->SetValue(50);

    wxCommandEvent event;
    frame.BtnSaveParametersClick(event);

    //EXPECT_TRUE(wxMessageBoxCalledWith("Parametry zapisano poprawnie!", "Zapisz parametry", wxOK | wxICON_INFORMATION));
}

TEST(MainWorkingFrameTest, BtnSaveParametersClick_Failure) {
    MainWorkingFrame frame(nullptr);

    //ustawienie wartosci poczatkowych
    frame.m_slider_red->SetValue(100);
    frame.m_slider_green->SetValue(150);
    frame.m_slider_blue->SetValue(200);
    frame.m_colourPickerLight->SetColour(wxColour(255, 255, 255));
    frame.m_colourPickerDark->SetColour(wxColour(0, 0, 0));
    frame.m_toggleBtn_keep_hue->SetValue(true);
    frame.m_colourPicker->SetColour(wxColour(128, 128, 128));
    frame.m_slider_mixing_level->SetValue(50);

    // symulacja bledu zapisu
    //SetSaveFileResult(false);

    wxCommandEvent event;
    frame.BtnSaveParametersClick(event);

    // Sprawd�, czy wiadomo�� o b��dzie zosta�a wy�wietlona
    //EXPECT_TRUE(wxMessageBoxCalledWith("Nie uda�o si� zapisa� parametr�w!", "Zapisz parametry", wxOK | wxICON_ERROR));
}

TEST(MainWorkingFrameTest, BtnImportImageClick) {
    // Tworzenie obiektu testowego
    MainWorkingFrame frame(nullptr);

    // Tworzenie obiektu zdarzenia
    wxCommandEvent event(wxEVT_COMMAND_BUTTON_CLICKED, wxID_ANY);

    // Symulacja klikni�cia przycisku importu obrazu
    frame.BtnImportImageClick(event);

    // Sprawdzenie, czy sk�adowe zosta�y ustawione poprawnie
    EXPECT_TRUE(frame.Img_Org.IsOk()); // Sprawdzenie, czy Img_Org jest poprawnym obrazem
    //EXPECT_EQ(frame.Img_Org, frame.Img_Cpy); // Sprawdzenie, czy Img_Cpy jest kopi� Img_Org
    EXPECT_TRUE(frame.m_slider_red->IsEnabled()); // Sprawdzenie, czy przyciski sa wlaczone
    EXPECT_TRUE(frame.m_slider_green->IsEnabled());
    EXPECT_TRUE(frame.m_slider_blue->IsEnabled());
    EXPECT_TRUE(frame.m_button_bichromy->IsEnabled());
    EXPECT_TRUE(frame.m_button_load_parameters->IsEnabled());
    EXPECT_TRUE(frame.m_button_save_image->IsEnabled());
    EXPECT_TRUE(frame.m_button_save_parameters->IsEnabled());
    EXPECT_TRUE(frame.m_button_restore->IsEnabled());
    EXPECT_TRUE(frame.m_toggleBtn_keep_hue->IsEnabled());
    EXPECT_TRUE(frame.m_colourPickerDark->IsEnabled());
    EXPECT_TRUE(frame.m_colourPickerLight->IsEnabled());
    EXPECT_TRUE(frame.m_colourPicker->IsEnabled());
}

TEST(MainWorkingFrameTest, BtnBichromyClick) {
    // Tworzenie obiektu testowego
    MainWorkingFrame frame(nullptr);

    // Tworzenie przyk�adowych warto�ci odcieni
    wxColour darkColour(100, 50, 0);
    wxColour lightColour(200, 150, 100);

    // Ustawienie warto�ci sk�adowych wymaganych przez test
    frame.m_colourPickerDark->SetColour(darkColour);
    frame.m_colourPickerLight->SetColour(lightColour);

    // Tworzenie obiektu zdarzenia
    wxCommandEvent event(wxEVT_COMMAND_BUTTON_CLICKED, wxID_ANY);

    // Wywo�anie metody BtnBichromyClick
    frame.BtnBichromyClick(event);

    // Pobranie obrazu Img_Cpy
    wxImage* imgCpy = &frame.Img_Cpy;

    // Przej�cie przez ka�dy piksel obrazu Img_Cpy i sprawdzenie przypisanych odcieni
    for (size_t x = 0; x < imgCpy->GetWidth(); x++) {
        for (size_t y = 0; y < imgCpy->GetHeight(); y++) {
            unsigned char r = imgCpy->GetRed(x, y);
            unsigned char g = imgCpy->GetGreen(x, y);
            unsigned char b = imgCpy->GetBlue(x, y);

            unsigned char brightness = 0.3 * r + 0.59 * g + 0.11 * b;

            unsigned char interpolatedHue[3];
            for (int i = 0; i < 3; i++) {
                interpolatedHue[i] = (brightness / 255.0) * lightColour.Red() + (1 - brightness / 255.0) * darkColour.Red();
            }

            // Sprawdzenie, czy przypisane odcienie s� poprawne
            EXPECT_EQ(interpolatedHue[0], r);
            EXPECT_EQ(interpolatedHue[1], g);
            EXPECT_EQ(interpolatedHue[2], b);
        }
    }
}

// Test sprawdzaj�cy, czy metoda BtnLoadParametersClick wczytuje poprawnie parametry
TEST(MainWorkingFrameTest, BtnLoadParametersClick) {
    // Tworzenie obiektu testowego
    MainWorkingFrame frame(nullptr);

    // Ustalenie �cie�ki do przyk�adowego pliku XML z parametrami
    wxString testFilePath = wxFileName(wxStandardPaths::Get().GetExecutablePath()).GetPath() + "/test_params.xml";

    // Tworzenie przyk�adowego pliku XML z parametrami
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("Settings");
    root.append_child("Parameter").append_attribute("name") = "RedSlider";
    root.child("Parameter").append_attribute("value") = "50";
    root.append_child("Parameter").append_attribute("name") = "GreenSlider";
    root.child("Parameter[2]").append_attribute("value") = "75";
    root.append_child("Parameter").append_attribute("name") = "BlueSlider";
    root.child("Parameter[3]").append_attribute("value") = "100";
    root.append_child("Parameter").append_attribute("name") = "BichromyLightColor";
    root.child("Parameter[4]").append_attribute("value") = "#AABBCC";
    root.append_child("Parameter").append_attribute("name") = "BichromyDarkColor";
    root.child("Parameter[5]").append_attribute("value") = "#102030";
    // Dodaj inne przyk�adowe parametry, je�li jest to konieczne

    // Zapisanie pliku XML
    if (!doc.save_file(testFilePath.ToStdString().c_str())) {
        wxMessageBox("Nie mo�na zapisa� pliku XML!", "Wczytywanie Parametr�w", wxOK | wxICON_ERROR);
        return;
    }

    // Symulowanie klikni�cia przycisku wczytuj�cego parametry
    frame.SimulateButtonClick(frame.m_button_load_parameters);

    // Sprawdzenie, czy parametry zosta�y poprawnie wczytane
    EXPECT_EQ(frame.m_slider_red->GetValue(), 50);
    EXPECT_EQ(frame.m_slider_green->GetValue(), 75);
    EXPECT_EQ(frame.m_slider_blue->GetValue(), 100);
    EXPECT_EQ(frame.m_colourPickerLight->GetColour(), wxColour("#AABBCC"));
    EXPECT_EQ(frame.m_colourPickerDark->GetColour(), wxColour("#102030"));
    // Dodaj asercje dla innych wczytanych parametr�w, je�li jest to konieczne

    // Usuni�cie pliku testowego
    wxRemoveFile(testFilePath);
}

TEST(MainWorkingFrameTest, testtest) {
    MainWorkingFrame test(nullptr);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
