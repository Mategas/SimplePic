#ifndef LOADER_H
#define LOADER_H
#include <string>
#include <dirent.h>
#include <wx/image.h>
#include <vector>
using namespace std;

class Loader {
	string path;
	wxImage* wximg;
	bool hasAlpha;
	bool isGif;
	vector <string> file_paths;
	int error;
public:
	Loader( string file_path, wxImage* const wxpointer );
	bool CargarImagen();
	void CargarDirectorioActual();
	bool IsGif();
	void LoadCache();
	~Loader();
};

class Cache {
	string path;
	wxImage* pcache[3];
	vector<string>::iterator itFoundFile, itFoundFile_next, itFoundFile_prev, itFoundFile_end, itFoundFile_rend;
public:
	Cache( const vector<string> &file_vector, const string &path);
	int check() const;
	void next();
	void prev();
	~Cache();
};

enum array_condition { all_ok, mia_last, mia_first, mia_limits, mia_all };
#endif

