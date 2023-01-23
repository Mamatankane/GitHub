// Scenario
// For this practical you will be assisting a building manager with checking the offices they are currently
// renting out. The building manager has a list of floors and the people renting on those floors called
// building.data. The manager needs to check specific floors and would like you to provide them with
// a program that will read this list and give them the name of all the peoples’ offices that they need
// to check in on.
// Unfortunately when the building was built the elevator was placed on the opposite side of the building
// thus you will also need to print the names for the manager in reverse order since they are coming
// from the other side of the floor now.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*
	stringToInt is a helper function that will 
	take a string called line and return the integer value
*/
int stringToInt(string line){
	stringstream s1(line);
	int temp = 0;
	s1 >> temp;
	return temp;
}


int main() {

	fstream fBuilding;
	fBuilding.open("building.data",ios::in);
	if (fBuilding.is_open()){
		string sfloors;
		getline(fBuilding,sfloors);
		sfloors+=',';
		string sline;
		int ifloors {0};
		while (!fBuilding.eof()){
			getline(fBuilding,sline);
			getline(fBuilding,sline);
			++ifloors;
		}
		fBuilding.close();
		fBuilding.open("building.data",ios::in);
		getline(fBuilding,sline);
		string ** ptrBuilding=new string *[ifloors];
		int * ptroffices= new int [ifloors];
		for (int a =0; a<ifloors; a++){
			getline(fBuilding,sline);
			sline.erase(0,9);
			int ifloor= stringToInt(sline);
			getline(fBuilding,sline);
			sline+=',';
			string snames= sline;
			int ioffices {0};
			while (sline.find(',')!=-1){
				sline.erase(0,sline.find(',')+1);
				++ioffices;
			}
			ptrBuilding[ifloor]= new string [ioffices];
			ptroffices[ifloor]=ioffices;
			for (int b=0; b<ioffices; b++){
				ptrBuilding[ifloor][b]=snames.substr(0,snames.find(','));
				snames.erase(0,snames.find(',')+1);

			}
		}
		while (sfloors.find(',')!=-1){
				int ifloor= stringToInt(sfloors.substr(0,sfloors.find(',')));
				sfloors.erase(0,sfloors.find(',')+1);
				for (int i=ptroffices[ifloor]-1; i>0; i--){
					cout<<ptrBuilding[ifloor][i]<<',';
				}
				cout<<ptrBuilding[ifloor][0]<<endl;
			}
		fBuilding.close();
		for (int i=0; i<ifloors; i++){
			delete [] ptrBuilding[i];	
		}
		delete [] ptrBuilding;
		delete [] ptroffices;
	}
	return 0;

}

/*
Expected output with the given building.txt:

Sunil,Alok,Kamilah,Pratik
Tamera,Zanetta,Keyundra,Alexzander,Nickalaus,Nathania,Annamaria,Ransen,Thuy,Yousef       
Jeffry,Shira,Sereena
Janna,Shaleen,Josi,Ndidi,Indalecio,Charlotta
Kejuan,Matricia,Takiya,Karalyn,Charls
Rebbecca
Kailyn,Kenda
Katheryne,Coury,Timithy,Melisssa,Clara,Lucus,Brittony,Makoto,Latona,Rudolph
*/

