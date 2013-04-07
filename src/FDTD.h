#ifndef _FDTD_H_
#define _FDTD_H_

#include <string>
#include <cstdio>
#include "constant.h"
#include "mesh.h"
#include "source.h"

class FDTD {
public:
	FDTD (){};
	~FDTD();
	void setStruct(string setting_file);
	void setSource(source* s);
	void solve();
	void solveone();
private:
	void openfile(FILE* &fd, string filename);
	void genCircle(FILE* &fd);
	void genRect(FILE* &fd);
	void initialmesh(int Nx, int Ny);
private:
	//one time data
	float max_frequency;
	//structure
	int Nx;
	int Ny;
	float xsize;
	float ysize;
	float Ds;
	float Dt;
	source* input;
	
	int max_iteration;
	float time;
	
	mesh** m;
};

#endif
