#include "utils.h"

string extraer_filename( const string &filep ) /*const*/ {
	size_t p = 0;
	p = filep.find_last_of("\\/");
	if( filep[p-4] == '.' || filep[filep.size()-4] == '.' ){
		if( filep[p] == '/' && filep.begin()+(p+1) == filep.end() ){
			size_t h = filep.find_last_of("\\/", p-1);
			return filep.substr( h+1, (p-h-1) );
		}
		else if( filep[p] == '\\' ){
			return filep.substr( p+1 );
		}
	}
	return string();
}

const char* convertir_path( string filep ){
	size_t p = 0;
	size_t len = filep.size();
	p = filep.find_last_of("/\\");
	if( filep[p] == '/' ){
		if( filep.begin()+(p+1) == filep.end() ){
			if( filep[p-4] == '.' ){
				p = filep.find_last_of('/', p-1);
			}
			filep.erase( filep.begin()+p, filep.end() );
		}
		else {
			size_t dot = filep.rfind('.');
			if( dot != filep.npos && filep.size() - dot == 4 ){
				filep.erase( filep.begin()+p, filep.end() );
			}
		}
		
		p = filep.find('/');
		while ( p != filep.npos ){
			filep.replace( p, 1, "\\" );
			p = filep.find('/');
		}
	}
	else {
		if( (p+1) == len ){
			if( filep[p-4] == '.' ){
				p = filep.find_last_of('/', p-1);
			}
		}
		else {
			size_t dot = filep.rfind('.');
			if( dot != filep.npos && filep.size() - dot == 4 ){
				filep.erase( filep.begin()+p, filep.end() );
			}
			filep.push_back( '/' );
		}
		
		p = filep.find("\\");
		while ( p != filep.npos ){
			filep.replace( p, 1, "/" );
			p = filep.find("\\");
		}
		
	}
	
	return filep.c_str();
}

bool verificar_extension( const string &aux ) /*const*/ {
	
	size_t badchar_pos = aux.find_first_of('?');
	if( badchar_pos != aux.npos ){ return false; }
	
	size_t dot_pos = aux.find_last_of('.');
	if( dot_pos == aux.npos ){ return false; }
	
	string ext = aux.substr( dot_pos+1, 3 );
	for(size_t i=0;i<ext.size();i++) { ext[i]=toupper(ext[i]); }
	
	return ( (ext == "GIF") || (ext == "JPG") || (ext == "PNG") || (ext == "ICO") || (ext == "BMP") || (ext == "BMP") || (ext == "TIFF") || (ext == "JPEG") || (ext == "PCX") || (ext == "PNM") || (ext == "TGA") || (ext == "IFF") || (ext == "XPM") || (ext == "CUR") || (ext == "ANI") );
	
}

string extraer_extension( const string &aux ) /*const*/ {
	
	size_t dot_pos = aux.find_last_of('.');
	if( dot_pos == aux.npos ){ return string(); }
	
	string ext = aux.substr( dot_pos+1, 3 );
	for(size_t i=0;i<ext.size();i++) { ext[i]=toupper(ext[i]); }
	
	return ext;
	
}

string extraer_path( const string &filep) /*const*/ {
	size_t p = 0;
	p = filep.find_last_of("\\/");
	if( filep.begin()+(p+1) == filep.end() && filep[p-4] == '.' ){
		p = filep.find_last_of("\\/", p-1);
	}
	else if( filep[p] == '\\' && filep[filep.size()-4] != '.' ){
		return filep;
	}
	
	return filep.substr(0, p+1);
}
