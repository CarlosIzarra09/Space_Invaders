#ifndef _SaveScore_H_
#define _SaveScore_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Registro.hpp"



using namespace std;
class SaveScore
{
private:
	ofstream wfile;
	ifstream rfile;
public:
	SaveScore()
	{
		wfile = ofstream("information.dim", ofstream::app);
		rfile = ifstream("information.dim",ios::in);
	}
	~SaveScore(){}
	void Write(string name, int score)
	{
		if (wfile.is_open())
		{
			wfile << name << '\t';
			wfile << score << endl;
		}
	}

	void Limpiar_Archivo() 
	{
		wfile = ofstream("information.dim", std::ios::out | std::ios::trunc);
	}

	void Read(std::vector<Registro*>&arreglo)
	{
		if (rfile.is_open())
		{
			string name;
			int score;
			string line;

			rfile = ifstream("information.dim", ios::in);

			while (getline(rfile, line))
			{
				istringstream iss(line);
				getline(iss, name, '\t');
				iss >> score;

				arreglo.push_back(new Registro(name, score));
			}

		
		}
	}

};



#endif // !_SaveScore_H_

