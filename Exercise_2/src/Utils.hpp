#ifndef mesh_
#define mesh_

#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os,const vector<double> a);

ostream& operator<<(ostream& os,const vector<vector<double>> a);

vector<double> ImportCell0Ds(const string &filename0,vector<double> &Id0,vector<double> &Marker0,vector<double> &x,vector<double> &y);

vector<double> ImportCell1Ds(const string &filename1,vector<double> &Id1,vector<double> &Marker1,vector<double> &origin,vector<double> &end);

vector<double> ImportCell2Ds(const string &filename2,vector<double> &Id2,vector<double> &Marker2,vector<double> &NumVertices,vector<double> &NumEdges,vector<vector<double>> &Vertices,vector<vector<double>> &Edges);

string NonZeroLenght(vector<double> &NumEdges,vector<vector<double>> &Edges);

#endif
