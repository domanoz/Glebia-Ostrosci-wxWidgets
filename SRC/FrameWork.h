
#ifndef __FRAMEWORK_H__
#define __FRAMEWORK_H__

#include <wx/scrolwin.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <vector>
#include <cmath>

using namespace std;


///////////////////////////////////////////////////////////////////////////
typedef vector<double> Array; //wektor wskaznikow
typedef vector<Array> Matrix; //macierz, czyli wektor wektorow

//klasa MyFrame odpowiadajaca za okno na ktorym pracujemy
class MyFrame1 : public wxFrame
{
private:

protected:
	wxScrolledWindow* m_scrolledWindow; //scroll ktory umozliwia zmiane rozmiarow okna
	wxButton* m_wczytaj_obraz; //przycisk wczytania obrazu
	wxButton* m_wczytaj_mape; //przycisk wczytania mapy glebokosci
	wxStaticText* m_text_odleglosc; //odleglosc ostra ktora wpisujemy
	wxTextCtrl* m_pole_wpisz_odleglosc; //pole w ktorym wpisujemy odleglosc
	wxStaticText* m_text_rozmycie; //wartosc skali rozmycia
	wxSlider* m_scroll_rozmycie; //suwak pozwalajacy na zmiane skali rozmycia
	wxButton* m_zapisz_obraz; //przycisk zapisu obrazu
	wxPanel* m_panel1; //panel glowny
	wxButton* m_powrot; //przycisk powrotu do oryginalu


	//funkcja, ktora wczytuje obraz, na ktorym rozpoczynamy pracowac
	//uzytkownik ma dostep do katalogow i z nich moze wybrac obraz
	//funkcja obsluguje tylko pliki bmp
	virtual void m_wczytaj_obrazOnButtonClick(wxCommandEvent& event);

	/*funkcja, ktora wczytuje mape szarosci, ktora wykorzystujemy do symulacji glebi ostrosci
	uzytkownik ma dostep do katalogow i z nich moze wybrac obraz
	wybieranie dotyczy tylko plikow bmp*/
	virtual void m_wczytaj_mapeOnButtonClick(wxCommandEvent& event); 

	//funckja, ktora pozwala nam wrocic do obrazu, ktory wczytalismy na poczatku
	virtual void m_powrotOnButtonClick(wxCommandEvent& event);

	//funkcja, ktora pozwala uzytkownikowi na wpisanie odleglosci ostrej
	//odleglosc ta wykorzystana jest pozniej do rozmycia innych elementow obrazu tym bardziej im roznica jest wieksza
	virtual void m_pole_wpisz_odlegloscOnTextEnter(wxCommandEvent& event);

	//funkcja, ktora pozwala uzytkownikowi zmieniac skale rozmycia
	//niestety zmiana skali rozmywania dziala bardzo dlugo
	virtual void m_scroll_rozmycieOnScroll(wxScrollEvent& event);


	//funkcja, ktora pozwala nam na zapisanie edytowanego obrazu w formacie .jpg
	virtual void m_zapisz_obrazOnButtonClick(wxCommandEvent& event);

	//funkcja umozliwiajaca zmiane rozmiarow okna 
	virtual void m_scrolledWindow_update(wxUpdateUIEvent& event);

public:

	//konstruktor, tworzy nam okno o tytule Glebia Ostrosci i wymiarach 900x600 ale z mozliwoscia zmiany rozmiarow okna
	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("G\u0142\u0119bia ostrosci"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(900, 600), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	
	
	wxImage Img_Org; //oryginalny obraz ktora wczytujemy na poczatku
	wxImage Img_Cpy; //kopia oryginalnego obrazu, ktora jest ciagle wyswietlana i na ktorej pracujemy
	wxImage Img_Map; //mapa szarosci, ktora uzywa sie do symulowania glebi ostrosci


	void Repaint(); 

	//metoda zwracajaca nam macierz(kernel), ktara zawiera w sobie gaussian piksela, na ktarym pracujemy oraz jego otoczenie
	//sigma to skala odleglosci na mapie szarosci[1,10], kernelRadius odnosi sie do skali rozmycia {3,5,7,9,11}
	Matrix getGaussian( double sigma, int kernelRadius);
	
	//glowna funkcja w programie, korzystajac z odpowiedniej macierzy rozmywa punkty w zaleznosci od ich ostrosci
	void applyFilter(int value, int kernelRadius);

	//tablica macierzy kernelowskich, w zaleznosci od sigmy
	Matrix tablica_sigm[10];
	~MyFrame1(); //destruktor
};

#endif //__FRAMEWORK_H__
