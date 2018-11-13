//Kod wygenerowany za pomoca wxFormBuilder 
//wszystkie funkcje odpowiadaja za rozmieszczenie kolejnych przyciskow, pol do wpisania tekstu lub suwakow

#include "FrameWork.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(600, 400), wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	m_scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	m_scrolledWindow->SetScrollRate(5, 5);
	bSizer1->Add(m_scrolledWindow, 1, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer(0, 2, 0, 0);

	m_wczytaj_obraz = new wxButton(this, wxID_ANY, _("Wczytaj obraz"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer1->Add(m_wczytaj_obraz, 0, wxALL, 5);

	m_wczytaj_mape = new wxButton(this, wxID_ANY, _("Wczytaj mape"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer1->Add(m_wczytaj_mape, 0, wxALL, 5);

	m_zapisz_obraz = new wxButton(this, wxID_ANY, _("Zapisz"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer1->Add(m_zapisz_obraz, 0, wxALL, 5);

	m_powrot = new wxButton(this, wxID_ANY, _("Powrót do orygina³u"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer1->Add(m_powrot, 0, wxALL, 5);

	bSizer2->Add(gSizer1, 1, wxEXPAND, 5);

	m_text_odleglosc = new wxStaticText(this, wxID_ANY, _("Podaj odleg³oœæ (0-255)"), wxDefaultPosition, wxDefaultSize, 0);
	m_text_odleglosc->Wrap(-1);
	bSizer2->Add(m_text_odleglosc, 0, wxALIGN_CENTER | wxALL, 5);

	m_pole_wpisz_odleglosc = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(m_pole_wpisz_odleglosc, 0, wxALIGN_CENTER | wxALL, 5);

	m_text_rozmycie = new wxStaticText(this, wxID_ANY, _("Rozmycie"), wxDefaultPosition, wxDefaultSize, 0);
	m_text_rozmycie->Wrap(-1);
	bSizer2->Add(m_text_rozmycie, 0, wxALIGN_CENTER | wxALL, 5);

	m_scroll_rozmycie = new wxSlider(this, wxID_ANY, 3, 1, 5, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	bSizer2->Add(m_scroll_rozmycie, 0, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

	bSizer1->Add(bSizer2, 0, wxALIGN_RIGHT, 5);
	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	
	m_scrolledWindow->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::m_scrolledWindow_update), NULL, this);
	m_wczytaj_obraz->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_wczytaj_obrazOnButtonClick ), NULL, this );
	m_wczytaj_mape->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_wczytaj_mapeOnButtonClick ), NULL, this );
	m_zapisz_obraz->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_zapisz_obrazOnButtonClick), NULL, this);
	m_powrot->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_powrotOnButtonClick), NULL, this);
	m_pole_wpisz_odleglosc->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame1::m_pole_wpisz_odlegloscOnTextEnter ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_scrolledWindow->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::m_scrolledWindow_update), NULL, this);
	m_wczytaj_obraz->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_wczytaj_obrazOnButtonClick ), NULL, this );
	m_zapisz_obraz->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_zapisz_obrazOnButtonClick), NULL, this);
	m_powrot->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::m_powrotOnButtonClick), NULL, this);
	m_wczytaj_mape->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_wczytaj_mapeOnButtonClick ), NULL, this );
	m_pole_wpisz_odleglosc->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame1::m_pole_wpisz_odlegloscOnTextEnter ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );
	m_scroll_rozmycie->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_scroll_rozmycieOnScroll ), NULL, this );	
}
