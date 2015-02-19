#include "options.h"

options::options( string &path, bool ulp ) {
	timer = time(NULL); use_last_path = ulp;
	archi.open( "opt.ini", ios::in | ios::out );
	
	if( archi.is_open() ){
		
		archi.seekg(0, archi.end);
		if( archi.tellg() != 0 ){
			archi.seekg(0, archi.beg);
			
			int cont = 0;
			while( getline(archi, aux) ){
				if( ++cont == 3 ){
					size_t pos = aux.find_last_of("=");
					if( aux[pos+2] == '1' )
						use_last_path = true;
					else if( aux[pos+2] == '0' )
						use_last_path = false;
				}
			}
			
		}
		
		archi.close();
	}
	
	archi.open( "opt.ini", ios::out | ios::trunc );
	VectorInit();
	archi<<vect[0]<< path <<endl;
	archi<<vect[1]<< ctime(&timer);
	if( use_last_path )
		archi<<vect[2]<< "1" <<endl;
	else
		archi<<vect[2]<< "0" <<endl;
	
	archi.close();
}

void options::VectorInit(){
	vect.push_back( "last_accessed_path= " );
	vect.push_back( "last_accessed_time= " );
	vect.push_back( "use_last_path= " );
}

options::~options() {
	
}

