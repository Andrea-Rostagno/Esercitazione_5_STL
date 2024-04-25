#include "Utils.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ostream& operator<<(ostream& os, const vector<double> a)
{
    for (size_t i = 0; i < a.size(); i++) {
        os<< a[i]<< " ";
    }

    return os;
}

ostream& operator<<(ostream& os,const vector<vector<double>> a)
{
    for (size_t i = 0; i < a.size(); i++) {
        os<< a[i]<< " ";
    }

    return os;

}

vector<double> ImportCell0Ds(const string &filename0,vector<double> &Id0,vector<double> &Marker0,vector<double> &x,vector<double> &y){

    ifstream fin(filename0);

    string line;
    vector<double> c;

    while (getline(fin, line)) {

        if (line.empty() || line[0] == 'I') {
            continue;
        }
        else {

            for (unsigned i = 0; i < line.size(); i++) {
                if(line[i] == ';'){
                    c.push_back(i);

                }
            }
            Id0.push_back(stod(line.substr(0,c[0])));
            Marker0.push_back(stod(line.substr(c[0]+1,c[1])));
            x.push_back(stod(line.substr(c[1]+1,c[2])));
            y.push_back(stod(line.substr(c[2]+1)));

            c.clear();
        }
    }
    cout<<"Cell0D marker:"<<endl;
    for (int j = 0; j < 8; ++j) {
        cout<<"key:\t"<<j+1<<"\t values:";
        for (unsigned z = 0; z < Id0.size(); ++z) {
            if(Marker0[z] == j+1){
                cout<<"\t"<<Id0[z]<<"\t";
            }
        }
        cout<<endl;
    }


    fin.close();

    return Id0;

}


vector<double> ImportCell1Ds(const string &filename1,vector<double> &Id1,vector<double> &Marker1,vector<double> &origin,vector<double> &end)
{
    ifstream fin(filename1);

    string line;
    vector<double> c;

    while (getline(fin, line)) {

        if (line.empty() || line[0] == 'I') {
            continue;
        }
        else {

            for (unsigned i = 0; i < line.size(); i++) {
                if(line[i] == ';'){
                    c.push_back(i);

                }
            }
            Id1.push_back(stod(line.substr(0,c[0])));
            Marker1.push_back(stod(line.substr(c[0]+1,c[1])));
            origin.push_back(stod(line.substr(c[1]+1,c[2])));
            end.push_back(stod(line.substr(c[2]+1)));

            c.clear();
        }
    }

    cout<<"Cell1D marker:"<<endl;
    for (int j = 5; j < 9; ++j) {
        cout<<"key:\t"<<j<<"\t values:";
        for (unsigned z = 0; z < Id1.size(); ++z) {
            if(Marker1[z] == j){
                cout<<"\t"<<Id1[z]<<"\t";
            }
        }
        cout<<endl;
    }


    fin.close();

    return Id1;

}

vector<double> ImportCell2Ds(const string &filename2,vector<double> &Id2,vector<double> &Marker2,vector<double> &NumVertices,vector<double> &NumEdges,vector<vector<double>> &Vertices,vector<vector<double>> &Edges)
{
    ifstream fin(filename2);

    string line;
    vector<double> c;
    vector<double> vet;

    while (getline(fin, line)) {

        if (line.empty() || line[0] == 'I') {
            continue;
        }
        else {

            for (unsigned i = 0; i < line.size(); i++) {
                if(line[i] == ';'){
                    c.push_back(i);

                }
            }
            Id2.push_back(stod(line.substr(0,c[0])));
            Marker2.push_back(stod(line.substr(c[0]+1,c[1])));
            NumVertices.push_back(stod(line.substr(c[1]+1,c[2])));
            for (unsigned j = 0; j < NumVertices[NumVertices.size()-1]; j++) {
                vet.push_back(stod(line.substr(c[j+2]+1,c[j+3])));
            }
            Vertices.push_back(vet);
            vet.clear();
            NumEdges.push_back(stod(line.substr(c[2+NumVertices[NumVertices.size()-1]]+1,c[3+NumVertices[NumVertices.size()-1]])));
            for (unsigned z = 0; z < NumEdges[NumEdges.size()-1]-1; z++) {
                vet.push_back(stod(line.substr(c[z+3+NumVertices[NumVertices.size()-1]]+1,c[z+4+NumVertices[NumVertices.size()-1]])));
            }
            vet.push_back(stod(line.substr(c[2+NumVertices[NumVertices.size()-1]+NumEdges[NumEdges.size()-1]]+1)));
            Edges.push_back(vet);
            vet.clear();

            c.clear();
        }
    }


    fin.close();

    return Id2;

}

string NonZeroLenght(vector<double> &NumEdges,vector<vector<double>> &Edges){
    int count=0;
    vector<double> vet;
    for (unsigned i = 0; i < NumEdges.size(); ++i) {
        if(NumEdges[i]== 3){
            vet=Edges[i];
            for (unsigned j = 0; j < 3 ; ++j) {
                if(vet[j]==0){
                    count=count+1;
                }
            }
            vet.clear();
        }
    }
    if(count ==0){
        return "Non sono presenti lati di triangoli uguali a zero";
    }
    else{
        return "Sono presenti lati di triangoli uguali a zero";
    }
}
