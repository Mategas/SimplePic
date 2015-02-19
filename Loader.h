#ifndef LOADER_H
#define LOADER_H
#include <string>
#include <list>
#include <dirent.h>
#include <wx/image.h>
#include <wx/animate.h>

#include "Cache.h"
#include "utils.h"
#include "options.h"
using namespace std;

class Loader {
private:
	wxImage* wximg;
	wxAnimation* wxanim;
	Cache* cachito;
	list <string> file_list;
	string path;
	bool cache_ok;
	
protected:
	bool CargarDirectorioActual();
	void CargarImagen();
	
public:
	Loader( const string &file_path );
	void CargarSig();
	void CargarAnt();
	wxImage* MostrarImagen();
	wxAnimation* MostrarAnimacion();
	bool IsGIF() /*const*/;
	bool HasAlpha() /*const*/;
	bool FrontEndReached();
	bool BackEndReached();
	string GetFilename() /*const*/;
	string GetExtension() /*const*/;
	string GetPath() /*const*/;
//	void SuprImage();
	~Loader();
};

#endif

