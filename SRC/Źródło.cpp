#include <wx/wx.h>
#include <memory>
#include "FrameWork.h"

//glowna aplikacja
class MyApp : public wxApp {

public:

	virtual bool OnInit(); //wlaczanie aplikacji
	virtual int OnExit() { return 0; } //wylaczanie aplkacji

};


wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{
	wxFrame *mainFrame = new MyFrame1(NULL); //tworzenie nowego okna

	wxImage::AddHandler(new wxJPEGHandler); //handler, pozwala na uzywanie formatow JPEG 
	wxImage::AddHandler(new wxBMPHandler);	//handler, pozwala na uzywanie formatow BMP

	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}
