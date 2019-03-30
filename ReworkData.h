//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef REWORK_DATA_H
#define REWORK_DATA_H

struct DataA
{
	double r;
	char a;
	char b;
	char pad0;
	char pad1;
	char pad2;
	char pad3;
	char pad4;
	char pad5;

};

struct DataB
{
	DataA da;
	int i;
	char a;
	char b;
	char pad0;
	char pad1;
};

struct DataC
{
	double r;
	int i;
	char a;
	bool f;
	char pad0;
	char pad1;
};

struct DataD
{
	double r;
	int i;
	char a;
	char b;
	char pad0;
	char pad1;
};

struct DataE
{
	char name[12];
	int *p;
	double r;
	int x;
	char a;
	char c;
	char pad0;
	char pad1;
};

struct Vect
{
	float vx;
	float vy;
	float vz;
	float vw;
	char a;
	char b;
	char pad0;
	char pad1;
};

struct DataF
{
	Vect v;
	int i;
	int j;
	char b;
	char pad0;
	char pad1;

};


#endif

// ---  End of File ---------------
