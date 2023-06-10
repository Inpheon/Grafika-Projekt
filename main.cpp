#include <wx/wx.h>
#include "MainWorkingFrame.h"

class MyApp : public wxApp {

public:
	virtual bool OnInit();
	virtual int OnExit() { return 0; }
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	wxInitAllImageHandlers();

	MainWorkingFrame* mainFrame = new MainWorkingFrame(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}