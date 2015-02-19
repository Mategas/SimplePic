#include "Cache.h"

Cache::Cache(){
	for(int i=0;i<3;i++) { (pcache[i]).first = NULL; (pcache[i]).second = NULL; }
}

Cache::Cache( list<string> &file_vector, const string &path ) {
	
	for(int i=0;i<3;i++) { (pcache[i]).first = NULL; (pcache[i]).second = NULL; }
	
	itFoundFile = find( file_vector.begin(), file_vector.end(), path );
	itFoundFile_next = itFoundFile_prev = itFoundFile;
	itFoundFile_begin = file_vector.begin();
	itFoundFile_end = file_vector.end();
	
	if( itFoundFile != file_vector.end() ){
		if( extraer_extension(*itFoundFile) != "GIF" )
			pcache[1].first = new wxImage( *itFoundFile );
		else
			pcache[1].second = new wxAnimation( *itFoundFile );
		
		if( itFoundFile_prev != file_vector.begin() ){
			--itFoundFile_prev;
			if( extraer_extension(*itFoundFile_prev) != "GIF" )
				pcache[0].first = new wxImage( *itFoundFile_prev );
			else
				pcache[0].second = new wxAnimation( *itFoundFile_prev );
		}
		
		++itFoundFile_next;
		if( itFoundFile_next != file_vector.end() ){
			if( extraer_extension(*itFoundFile_next) != "GIF" )
				pcache[2].first = new wxImage( *itFoundFile_next );
			else
				pcache[2].second = new wxAnimation( *itFoundFile_next );
		}
		else
			--itFoundFile_next;
	}
	
}

array_condition Cache::check() /*const*/ {
	
	if( pcache[0].first == NULL && pcache[0].second == NULL){
		if( pcache[1].first != NULL || pcache[1].second != NULL ){
			if( pcache[2].first == NULL && pcache[2].second == NULL )
				return mia_boundaries;
			else
				return mia_first;
		} else
			return mia_all;
	}
	else {
		if( pcache[2].first == NULL && pcache[2].second == NULL)
			return mia_last;
		else
			return all_ok;
	}
	
}

void Cache::Next() {
	
	switch( check() ){
	case all_ok:
	case mia_first:
		
		delete pcache[0].second; pcache[0].second = NULL;
		delete pcache[0].first; pcache[0].first = NULL;
		
		if( pcache[1].first == NULL )
			pcache[0].second = pcache[1].second;
		else
			pcache[0].first = pcache[1].first;
		
		if( pcache[2].first == NULL ){
			pcache[1].second = pcache[2].second;
			pcache[1].first = NULL;
		}
		else{
			pcache[1].first = pcache[2].first;
			pcache[1].second = NULL;
		}
		pcache[2].first=NULL; pcache[2].second=NULL;
		
		if( itFoundFile_next != itFoundFile_end ){
			++itFoundFile_next;
			if( itFoundFile_next != itFoundFile_end ){
				if( extraer_extension(*itFoundFile_next) != "GIF" )
					pcache[2].first = new wxImage( *itFoundFile_next );
				else
					pcache[2].second = new wxAnimation( *itFoundFile_next );
			}
			++itFoundFile_prev; ++itFoundFile;
		}
		break;
	default: break;
	}
	
}

void Cache::Prev() {
	
	switch( check() ){
	case all_ok:
	case mia_last:
		
		delete pcache[2].second; pcache[2].second = NULL;
		delete pcache[2].first; pcache[2].first = NULL;
		
		if( pcache[1].first == NULL )
			pcache[2].second = pcache[1].second;
		else
			pcache[2].first = pcache[1].first;
		
		if( pcache[0].first == NULL ){
			pcache[1].second = pcache[0].second;
			pcache[1].first = NULL;
		}
		else{
			pcache[1].first = pcache[0].first;
			pcache[1].second = NULL;
		}
		pcache[0].first=NULL; pcache[0].second=NULL;
		
		if( itFoundFile_prev != itFoundFile_begin ){
			--itFoundFile_prev;
			if( extraer_extension(*itFoundFile_prev) != "GIF" )
				pcache[0].first = new wxImage( *itFoundFile_prev );
			else
				pcache[0].second = new wxAnimation( *itFoundFile_prev );
		}
		--itFoundFile_next; --itFoundFile;
		break;
	default: break;
	}
	
}

pair<wxImage*, wxAnimation*> Cache::GetImage() /*const*/ {
	if( check() == mia_all )
		return pair<wxImage*, wxAnimation*>( NULL, NULL );
	return pcache[1];
}

pair<wxImage*, wxAnimation*> Cache::GetNextImage() /*const*/ {
	int cond = check();
	if( cond == mia_all || cond == mia_boundaries || cond == mia_last )
		return pair<wxImage*, wxAnimation*>( NULL, NULL );
	return pcache[2];
}

pair<wxImage*, wxAnimation*> Cache::GetPrevImage() /*const*/ {
	int cond = check();
	if( cond == mia_all || cond == mia_boundaries || cond == mia_first )
		return pair<wxImage*, wxAnimation*>( NULL, NULL );
	return pcache[0];
}

string Cache::GetCurrPath() /*const*/ {
	return *itFoundFile;
}

Cache::~Cache(){
	for(int i=0;i<3;i++) {
		/*delete pcache[i].first;*/	pcache[i].first = NULL;
		/*delete pcache[i].second;*/ pcache[i].second = NULL;
	}
}

