#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string extraer_filename( const string &filep ) /*const*/ ;
const char* convertir_path( string filep );
bool verificar_extension( const string &aux ) /*const*/ ;
string extraer_extension( const string &aux ) /*const*/ ;
string extraer_path( const string &filep) /*const*/ ;

#endif
//se puede usar un .hpp?
