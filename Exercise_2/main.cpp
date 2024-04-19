#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "src/Utils.hpp"
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("PolygonalMesh/Cell0Ds.csv");

    if(fin.fail())
    {
        cerr << "file not found" << endl;
        return 1;
    }

    string line;
    vector<double> Id;
    vector<double> Marker;
    vector<double> x;
    vector<double> y;
    vector<double> c;

    while (getline(fin, line)) {

        if (line.empty() || line[0] == 'I') {
            continue;
        }
        else {

            for (unsigned i = 0; i < line.size(); i++) {
                if(line[i] == ';'){
                    c.push_back(i);
                    //cout<<i<<" ";
                }
            }
            Id.push_back(stod(line.substr(0,c[0])));
            Marker.push_back(stod(line.substr(c[0]+1,c[1])));
            x.push_back(stod(line.substr(c[1]+1,c[2])));
            y.push_back(stod(line.substr(c[2]+1)));

            c.clear();
        }
    }

    cout<<"Il vettore Id: "<<Id<<endl;
    cout<<"Il vettore Marker: "<<Marker<<endl;
    cout<<"Il vettore x: "<<x<<endl;
    cout<<"Il vettore y: "<<y<<endl;




    fin.close();


    return 0;
}
