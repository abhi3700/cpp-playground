#include <iostream>
#include <fstream>
// using namespace std;
using std::endl;
int main()
{
	std::ofstream outfile("players.txt");
	outfile << "Alessandro Del Piero" << endl
		    << "Juvemtus, Italy"	  << endl
		    << "Zein Eldin Zeidan"	  << endl
		    << "Real Madrid CF, Spain"<< endl;
	outfile.close();
	return 0;
}