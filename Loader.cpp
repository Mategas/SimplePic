#include "Loader.h"

Loader::Loader( const string &file_path ) {
	wximg = NULL; wxanim = NULL;
	file_list.clear();
	path = file_path;
	
	if( !CargarDirectorioActual() ) {
		cachito = NULL; cache_ok = false;
	}
	else {
		cachito = new Cache( file_list, path ); cache_ok = true;
		path.clear(); path = cachito->GetCurrPath();
//		options ini( path, false );
	}
	
	CargarImagen();
	
}

void Loader::CargarImagen() {
	if( cache_ok ){ 
		if( !IsGIF() )
			wximg = (cachito->GetImage()).first;
		else
			wxanim = (cachito->GetImage()).second;
		path = cachito->GetCurrPath();
	}
	else{
		if( !IsGIF() )
			wximg->LoadFile( path );
		else
			wxanim->LoadFile( path );
	}
}

void Loader::CargarSig() {
	if( cache_ok ){
		cachito->Next();
		path = cachito->GetCurrPath();
		if( !IsGIF() )
			wximg = (cachito->GetImage()).first;
		else
			wxanim = (cachito->GetImage()).second;
	}
}

void Loader::CargarAnt() {
	if( cache_ok ){
		cachito->Prev();
		path = cachito->GetCurrPath();
		if( !IsGIF() )
			wximg = (cachito->GetImage()).first;
		else
			wxanim = (cachito->GetImage()).second;
	}
}

bool Loader::IsGIF() /*const*/ {
	if( extraer_extension( path ) == "GIF" )
		return true;
	return false;
}

bool Loader::HasAlpha() /*const*/ {
	return ( wximg->HasAlpha() );
}

string Loader::GetFilename() /*const*/ {
	return extraer_filename( path );
}

string Loader::GetExtension() /*const*/ {
	return extraer_extension( path );
}

string Loader::GetPath() /*const*/ {
	return path;
}

wxImage* Loader::MostrarImagen(){
	return wximg;
}

wxAnimation* Loader::MostrarAnimacion(){
	return wxanim;
}

bool Loader::FrontEndReached(){
	int cond = cachito->check();
	if( cond != 0 && cond != 2 )
		return true;
	return false;
}

bool Loader::BackEndReached(){
	int cond = cachito->check();
	if( cond != 0 && cond != 1 && file_list.front() == cachito->GetCurrPath() )
		return true;
	return false;
}

bool Loader::CargarDirectorioActual(){
	string aux;
	DIR *imgdir = NULL;
	imgdir = opendir( extraer_path(path).c_str() ) ;
	struct dirent *pent = NULL;
	
	if( imgdir == NULL ) { return false; }
	
	int c = 0;
	while( (pent = readdir(imgdir)) )
	{
		if( pent == NULL ) { return false; }
		
		if(c<2){++c;}
		
		aux = pent->d_name;
		
		if( verificar_extension(aux) ){
			string sp = extraer_path(path); sp = sp+aux;
			file_list.push_back( sp );
		}
		
	}
	
	closedir (imgdir);
	return true;
}

Loader::~Loader() {
	delete wximg;
	delete wxanim;
	delete cachito;
	file_list.clear();
	path.clear();
}

