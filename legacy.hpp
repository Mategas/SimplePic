
class Cache0 {
	wxImage* pcache[3];
public:
	Cache0();
	array_condition check() const;
	//si no quiero cambiar lo devuelto lleva CONST adelante
	void Load( vector<string>::iterator itFoundFile const );
	//CONST atras no modifica el THIS
	~Cache0();
};

//---------------------------------------------------------//

Cache0::Cache0(){
	for(int i=0;i<3;i++) { pcache[i]=NULL; }
}

Cache0::Load( vector<string>::iterator itFoundFile const, int cant, bool load_forward ){
	vector<string>::iterator itFoundFile_prev, itFoundFile_next;
	itFoundFile_prev = itFoundFile_next = itFoundFile;
	++itFoundFile_next; --itFoundFile_prev;
	
	if( cant <= 3 && cant > 0 ){
		
		if( cant != 3 ){
			switch( cant ){
			case 1:
				if( pcache[1] != NULL ){
					
				}
			}
		}
		else {
			for(int i=0;i<3;i++) { delete pcache[i]; }
			pcache[1] = new wxImage( *itFoundFile );
			pcache[0] = new wxImage( *itFoundFile_prev );
			pcache[2] = new wxImage( *itFoundFile_next );
		}
		
	}
	
	//preguntar por un entero que determine la posicion
}

Cache0::Load( vector<string>::iterator itFoundFile const ){
	vector<string>::iterator itFoundFile_prev, itFoundFile_next;
	itFoundFile_prev = itFoundFile_next = itFoundFile;
	--itFoundFile_prev;
	++itFoundFile_next;
	
	switch( check() ){
	case all_ok:
		for(int i=0;i<3;i++) { delete pcache[i]; }
		pcache[0] = new wxImage( *itFoundFile_prev );
		pcache[1] = new wxImage( *itFoundFile );
		pcache[2] = new wxImage( *itFoundFile_next );
		//PELIGRO! No tiene verificacion
		break;
	case mia_first:
		break;
	case mia_last:
		break;
	case mia_boundaries:
		break;
	case mia_all:
		break;
	}
	
	//Intentar hacer que la clase Load sea sin chequeos y que estos los realice
	//Loader.next y Loader.prev
	//Ademas, fusionar Cache0 con Cache si esto se lleva a cabo.
}

array_condition Cache0::check(){
	
	if( pcache[0] == NULL ){
		if( pcache[1] != NULL ){
			if( pcache[2] == NULL )
				return mia_boundaries;
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

Cache0::~Cache0(){
	
}

//----------------------------------------------------//

bool Loader::IsGIF() const {
	size_t cant = (wximg->GetHandlers())->GetCount(); //es (wxList&)->GetCount() o (wxList&).GetCount()?
	for(size_t i=0;i<cant;i++) { 
		string ext = ((wximg->GetHandlers())->Item(i))->GetExtension();
		if( ext == "gif" )
			return true;
	}
	return false;
}

//----------------------------------------------------//

void Cache::prev() {
	
	switch( check() ){
	case all_ok:
	case mia_last:
		delete pcache[2];
		pcache[2] = pcache[1];
		
		/*delete pcache[1];*/
//		no hace falta borrarlos- recuperan los de las otras posiciones
		pcache[1] = pcache[0];
		
		/*delete pcache[0];*/
		
		--itFoundFile_prev;
		if( itFoundFile_prev != itFoundFile_rend ){
			pcache[0] = new wxImage( *itFoundFile_prev );
		}
		else{
			pcache[0] = NULL;
		}
		--itFoundFile_next; --itFoundFile;
		break;
		/*default:*/
		//casos donde no puede seguir
		//no hacer nada? - en gral, si; pero agregar aca el refresco de la lista.
	}
	
}

pair<wxImage*, string> Cache::get_image() const {
	if( check() == mia_all )
		return pair<wxImage*, string>( NULL, string() );
	return pair<wxImage*, string>( pcache[1], *itFoundFile );
}

pair<wxImage*, string> Cache::get_next() const {
	int cond = check();
	if( cond == mia_all || cond == mia_boundaries || cond == mia_last )
		return pair<wxImage*, string>( NULL, string() );
	return pair<wxImage*, string>( pcache[2], *itFoundFile_next );
}

pair<wxImage*, string> Cache::get_prev() const {
	int cond = check();
	if( cond == mia_all || cond == mia_boundaries || cond == mia_first )
		return pair<wxImage*, string>( NULL, string() );
	return pair<wxImage*, string>( pcache[0], *itFoundFile_prev );
}
