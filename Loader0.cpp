#include "Loader.h"

Loader::Loader( string file_path, wxImage* const puntero_a_mostrar = NULL ) {
	path = file_path;
	wximg = puntero_a_mostrar;
	
	CargarDirectorioActual();
	
//	if( wximg->HasAlpha() ) hasAlpha = true; else hasAlpha = false;
}

bool Loader::CargarImagen() {
	wximg->LoadFile( path );
	return img->IsOk();
}

void Loader::CargarDirectorioActual(){
	string aux;
	DIR *imgdir = NULL;
	imgdir = opendir( convertir_path(path) ) ;
	struct dirent *pent = NULL;
	
	if( imgdir == NULL )
	{ /*error*/	}
	
	int c = 0;
	while( (pent = readdir(imgdir)) )
	{
		if( pent == NULL )
		{ /*error*/ }
		
		if(c<2){c++;} //evito guardar los "." y ".." en el vector
		else {
			aux(pent->d_name);
			
			if( verificar_extension(aux) ){
				file_paths.push_back( aux );
			}
		}
		
	}
	
	closedir (imgdir);
}


Loader::~Loader() {
	
}

//------------------------------------------------------------------//

Cache::Cache( vector<string> &file_vector const, string &path const ) {
	
	for(int i=0;i<3;i++) { pcache[i]=NULL; }
	
	itFoundFile = find( file_vector.begin(), file_vector.end(), extraer_filename(path) );
	itFoundFile_next = itFoundFile_prev = itFoundFile;
	itFoundFile_rend = file_vector.rend();
	itFoundFile_end = file_vector.end();
	
	if( itFoundFile != file_paths.end() ){
		pcache[1] = new wxImage( *itFoundFile );
		
		if( itFoundFile != file_paths.begin() )
			--itFoundFile_prev;
		pcache[0] = new wxImage( *(itFoundFile_prev) );
		
		if( itFoundFile != file_paths.rbegin() )
			++itFoundFile_next;
		pcache[2] = new wxImage( *(itFoundFile_next) );
	}
	
}

array_condition Cache::check(){
	
	if( pcache[0] == NULL ){
		if( pcache[1] != NULL ){
			if( pcache[2] == NULL )
				return mia_limits;
			else
				return mia_first;
		} else
			return mia_all;
	}
	else {
		if( pcache[2] == NULL )
			return mia_last;
		else
			return all_ok;
	}
	
}

void Cache::next() {
	
	switch( check() ){
	case all_ok:
	case mia_first:
		pcache[0] = pcache[1];
		pcache[1] = pcache[2];
		
		delete pcache[2];
		
		++itFoundFile_next;
		if( itFoundFile_next != itFoundFile_end ){
			pcache[2] = new wxImage( *itFoundFile_next );
		}
		//sera que hay que hacer el NEXT y PREV en Loader?
		//insertar nuevo "2"
		break;
	default:
		//casos donde no puede seguir
	}
	
}

void Cache::prev() {
	
	switch( check() ){
	case all_ok:
	case mia_last:
		pcache[2] = pcache[1];
		pcache[1] = pcache[0];
		//insertar nuevo "0"
		break;
	default:
		//casos donde no puede seguir
	}
	
}

Cache::~Cache(){
	
}

//------------------------------------------------------------------//

string extraer_filename( const string &str ){
	size_t pos = str.find_last_of("\\/");
	if( pos != str.npos ){
		return str.substr(pos+1);
	}
}

const char* convertir_path( string filep ){
	size_t p = 0;
	p = filep.find('/');
	while ( p != filep.npos ){
		filep.replace( p, 1, "\\" );
		p = filep.find('/');
	}
//	filep.erase( filep.find("\\"), 2 );
	filep.erase( filep.rbegin(), filep.end() );

	return filep.c_str();
}

bool verificar_extension( const string &aux ){
	
	size_t dotpos = aux.find_last_of(".");
	if( dotpos == aux.npos ){ return false; }
	
	string ext = aux.substr( dotpos+1 );
	for(int i=0;i<ext.size();i++) { ext[i]=toupper(ext[i]); }
	
	return ( (ext == "GIF") || (ext == "JPG") || (ext == "PNG") || (ext == "ICO") || (ext == "BMP") || (ext == "BMP") || (ext == "TIFF") || (ext == "JPEG") || (ext == "PCX") || (ext == "PNM") || (ext == "TGA") || (ext == "IFF") || (ext == "XPM") || (ext == "CUR") || (ext == "ANI") )
	
}
