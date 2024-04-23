#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "src/Utils.hpp"
#include <iomanip>
#include<algorithm>

using namespace std;

int main()
{
    vector<double> Id0;
    vector<double> Marker0;
    vector<double> x;
    vector<double> y;
    string filename0="PolygonalMesh/Cell0Ds.csv";
    Id0 = ImportCell0Ds(filename0,Id0,Marker0,x,y);
    //cout<<"Il vettore x: "<<x<<endl;
    //cout<<"Il vettore y: "<<y<<endl;

    vector<double> Id1;
    vector<double> Marker1;
    vector<double> origin;
    vector<double> end;
    string filename1="PolygonalMesh/Cell1Ds.csv";
    Id1 = ImportCell1Ds(filename1,Id1,Marker1,origin,end);
    //cout<<"Il vettore origin: "<<origin<<endl;
    //cout<<"Il vettore end: "<<end<<endl;

    vector<double> Id2;
    vector<double> Marker2;
    vector<double> NumVertices;
    vector<double> NumEdges;
    vector<vector<double>> Vertices;
    vector<vector<double>> Edges;
    string filename2="PolygonalMesh/Cell2Ds.csv";
    Id2 = ImportCell2Ds(filename2,Id2,Marker2,NumVertices,NumEdges,Vertices,Edges);
    //cout<<"Il vettore Id2: "<<Id2<<endl;
    //cout<<"Il vettore Marker2: "<<Marker2<<endl;
    //cout<<"Il vettore Numvertices: "<<NumVertices<<endl;
    //cout<<"Il vettore NumEdges: "<<NumEdges<<endl;
    //cout<<"Il vettore vertices: "<<Vertices<<endl;
    //cout<<"Il vettore Edges: "<<Edges<<endl;

    for(unsigned int c = 0; c < Id2.size(); c++)
    {
        vector<double> edges = Edges[c];

        for(unsigned int e = 0; e < edges.size(); e++)
        {
            const unsigned int orig = origin[e];
            const unsigned int en = end[e];
            vector<double> sium;
            sium=Vertices[c];
            auto findOrigin = find(sium.begin(), sium.end(), orig);

            if(findOrigin == sium.end())
            {
                cerr << "Wrong mesh" << endl;
                //return 2;
            }
            else{cout << "Right mesh" <<NumVertices[c]<< endl;}

            auto findEnd = find(sium.begin(), sium.end(), en);
            if(findEnd == sium.end())
            {
                cerr << "Wrong mesh" << endl;
                //return 3;
            }
            else{cout << "Right mesh" <<NumVertices[c]<< endl;}

        }
    }

    return 0;
}
