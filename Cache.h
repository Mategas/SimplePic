#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <list>
#include <algorithm>
#include <utility>
#include <wx/animate.h>
#include <wx/image.h>

#include "utils.h"
using namespace std;

enum array_condition { all_ok, mia_last, mia_first, mia_boundaries, mia_all };

class Cache {
	pair<wxImage*, wxAnimation*> pcache[3];
	list<string>::iterator itFoundFile, itFoundFile_next, itFoundFile_prev, itFoundFile_end, itFoundFile_begin;
public:
	Cache();
	Cache( list<string> &file_vector, const string &path);
	array_condition check();
	void Next();
	void Prev();
	pair<wxImage*, wxAnimation*> GetImage() /*const*/;
	pair<wxImage*, wxAnimation*> GetNextImage() /*const*/;
	pair<wxImage*, wxAnimation*> GetPrevImage() /*const*/;
	string GetCurrPath() /*const*/;
	~Cache();
};

#endif

