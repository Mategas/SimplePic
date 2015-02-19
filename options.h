#ifndef OPTIONS_H
#define OPTIONS_H
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class options {
private:
	fstream archi;
	vector<string> vect;
	string aux;
	time_t timer;
	bool use_last_path;
protected:
public:
	options( string &path, bool ulp );
	void VectorInit();
	~options();
};

#endif

