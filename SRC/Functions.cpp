#include "FrameWork.h"
#include <wx/wx.h>

#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <memory>
#include <wx/msgdlg.h>


void MyFrame1::m_scrolledWindow_update(wxUpdateUIEvent& event)
{
	Repaint();
}


void MyFrame1::m_wczytaj_obrazOnButtonClick(wxCommandEvent& event)
{
	wxFileDialog WxOpenFileDialog(this, _("Wybierz obraz"), _(""), _(""), _("BMP files  (*.bmp)|*.bmp|JPG files (*.jpg)|*.jpg"), wxFD_OPEN);
	m_scrolledWindow->ClearBackground();
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxBMPHandler);
	wxImage image;

	if (WxOpenFileDialog.ShowModal() == wxID_OK)
	{
		if (!image.LoadFile(WxOpenFileDialog.GetPath().ToAscii()))
		{
			wxMessageBox(_("Nie uda\u0142o si\u0119 za\u0142adowa\u0107 obrazu"));
			Destroy();
		}
		else
		{
			Img_Org = image.Copy();
			Img_Cpy = Img_Org.Copy();
			wxMessageBox(_("Uda\u0142o si\u0119 za\u0142adowa\u0107 obraz"));
		}
	}
};

void MyFrame1::m_wczytaj_mapeOnButtonClick(wxCommandEvent& event)
{
	wxFileDialog WxOpenFileDialog(this, _("Wybierz mape"), _(""), _(""), _("BMP files  (*.bmp)|*.bmp|JPG files (*.jpg)|*.jpg"), wxFD_OPEN);
	wxImage image;

	if (WxOpenFileDialog.ShowModal() == wxID_OK)
	{
		if (!image.LoadFile(WxOpenFileDialog.GetPath().ToAscii()))
		{
			wxMessageBox(_("Nie uda\u0142o si\u0119 za\u0142adowa\u0107 mapy"));
			Destroy();
		}
		else
		{
			Img_Map = image.Copy();
			wxMessageBox(_("Uda\u0142o si\u0119 za\u0142adowa\u0107 mape"));
		}
	}
};


void MyFrame1::Repaint()
{
	wxBitmap bitmap(Img_Cpy);
	wxClientDC dc(m_scrolledWindow);
	m_scrolledWindow->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, false);
}

void MyFrame1::m_zapisz_obrazOnButtonClick(wxCommandEvent& event)
{
	if (!Img_Cpy.SaveFile("zapis.jpg"))
		wxMessageBox(_("Nie uda\u0142o si\u0119 zapisa\u0107 obraz"));
	else
		wxMessageBox(_("Uda\u0142o si\u0119 zapisa\u0107 obraz"));
}

void MyFrame1::m_powrotOnButtonClick(wxCommandEvent& event)
{
	m_scrolledWindow->ClearBackground();
	Img_Cpy = Img_Org.Copy();
	Repaint();
}

void MyFrame1::m_pole_wpisz_odlegloscOnTextEnter(wxCommandEvent& event)
{
	applyFilter(wxAtoi(m_pole_wpisz_odleglosc->GetValue()), m_scroll_rozmycie->GetValue());
	Repaint();
}


void MyFrame1::m_scroll_rozmycieOnScroll(wxScrollEvent& event)
{
	applyFilter(wxAtoi(m_pole_wpisz_odleglosc->GetValue()), m_scroll_rozmycie->GetValue());
}




Matrix MyFrame1::getGaussian(double sigma,int kernelRadius)
{

	Matrix kernel((kernelRadius), Array((kernelRadius))); //macierz wartosci gaussowskich dla danej sigmy
	double suma = 0.0;
	double mean = kernelRadius / 2;

	for (int x = 0; x <  kernelRadius; ++x){
		for (int y = 0; y <  kernelRadius; ++y) {

			kernel[x][y] = 1 / (2 * M_PI * sigma * sigma) *  exp(-((x - mean)*(x - mean) +(y-mean)*(y - mean))/(2*sigma*sigma));
			suma += kernel[x][y];
		}
	}

	for (int x = 0; x <  kernelRadius; ++x){
		for (int y = 0; y <  kernelRadius; ++y){
			kernel[x][y] /= suma;
		}
	}
	return kernel;
}


void MyFrame1::applyFilter(int value, int radius)
{

	int kernelRadius; //Rozmiar macierzy kernelowskiej, im wieksza tym wieksze rozmycie

	//ustawianie stopnia rozmycia
	if (radius == 1)
		kernelRadius = 3;
	if (radius == 2)
		kernelRadius = 5;
	if (radius == 3)
		kernelRadius = 7;
	if (radius == 4)
		kernelRadius = 9;
	if (radius == 5)
		kernelRadius = 11;

	Matrix kernel2;
	int sigma_temp; //tymczasowa sigma, obliczana dla ka¿dego piksela
	int wysokosc = Img_Org.GetHeight();
	int szerokosc = Img_Org.GetWidth();
	int sigma; //stopien odleg³osci pomiedzy wartoscia zadana, a wartoscia piksela
	double double_sigma = 1.0;
	

	//petla ktora uzupelnia tablice sigm
	for (int k = 0; k < 10; k++)
	{
		tablica_sigm[k] = getGaussian(double_sigma,kernelRadius); 
		double_sigma++;
	}

		for (int y = 0; y < wysokosc; y++)
		{
			for (int x = 0; x < szerokosc; x++)
			{	
					sigma_temp = fabs(value - (Img_Map.GetRed(x, y))); //obliczanie sigmy dla kazdego piksela

					if (sigma_temp < 256 && sigma_temp >= 230)
						sigma = 10;
					if (sigma_temp > 205 && sigma_temp < 230)
						sigma = 9;
					if (sigma_temp > 180 && sigma_temp <= 205)
						sigma = 8;
					if (sigma_temp > 155 && sigma_temp <= 180)
						sigma = 7;
					if (sigma_temp > 130 && sigma_temp <= 155)
						sigma = 6;
					if (sigma_temp > 105 && sigma_temp <= 130)
						sigma = 5;
					if (sigma_temp > 80 && sigma_temp <= 105)
						sigma = 4;
					if (sigma_temp > 55 && sigma_temp <= 80)
						sigma = 3;
					if (sigma_temp > 30 && sigma_temp <= 55)
						sigma = 2;
					if (sigma_temp >= 0 && sigma_temp <= 30)
						sigma = 1;

					double sumRed = 0.0;
					double sumGreen = 0.0;
					double sumBlue = 0.0;
					kernel2 = tablica_sigm[sigma - 1];		

					int kx, ky;

					//chodzenie po ca³ej macierzy otoczenia piksela i sumowanie wszystkich sk³adowych koloru piksela pomno¿one przez kernel
					for ( ky = -(kernelRadius/2); ky <= (kernelRadius / 2); ky++) {
						for ( kx = -(kernelRadius / 2); kx <= (kernelRadius / 2); kx++) {

								sumRed += kernel2[(kernelRadius / 2) + ky][(kernelRadius / 2) + kx] * Img_Org.GetRed(x+kx, y+ky);
								sumGreen += kernel2[(kernelRadius / 2) + ky][(kernelRadius / 2) + kx] * Img_Org.GetGreen(x+kx, y+ky);
								sumBlue += kernel2[(kernelRadius / 2) + ky][(kernelRadius / 2) + kx] * Img_Org.GetBlue(x + kx, y + ky);
						}
					}
					Img_Cpy.SetRGB(x, y, sumRed, sumGreen, sumBlue); //ustawianie kolorów piksela na takie jakie zosta³y wczeœniej obliczone
				}
		}
	}

