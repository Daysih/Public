#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "stringSplitter.h"


using namespace std;

vector<string> readFile(ifstream& some_file);
vector<string> readFile(ifstream&& some_file);
vector<string> readFile(string file_name);
//void header_remover(vector<string> vec_out, vector<string> vec_in);

int main()
{
	string file_input, file_dest;
	cout << "Enter a PPM file to parse: ";
	cin >> file_input;
	vector<string> ppm_vec = readFile(file_input);
	vector<string> new_vec, vec_o;

	cout << endl << "Enter destination file: ";
	cin >> file_dest;
	ofstream stream(file_dest);
	stream << "P3" << endl;
	stream << "400 273" << endl;
	stream << "255" << endl;

	cout << "parsing..." << endl;

	for (int i = 3; i < ppm_vec.size(); i++)
	{
		new_vec = StringSplitter::split(ppm_vec[i], " ");
		for (int i = 1; i < new_vec.size(); i += 3)
		{
			new_vec[i] = "0";
		}
		
		for (auto row : new_vec)
		{
			stream << row << " ";
			//cout << row << " ";
		}
		//cout << endl;
		stream << endl;
	}
	stream.close();

	cout << "Processing image complete..." << endl;
	return 0;
}

vector<string> readFile(ifstream& some_file)
{
	vector<string> result{};
	//is the file open?
	if (some_file.is_open() == true)
	{
		while (some_file.good() == true)
		{
			//two ways to grab data
			string data;
			//first_names >> data; //CIN style
			getline(some_file, data); //more robust method
			result.push_back(data);
		}
	}
	return result;
}

vector<string> readFile(ifstream&& some_file)
{
	ifstream& local_file = some_file;

	//auto is an automatically inferred variable type
	//in our case, vector<string>
	auto result = readFile(local_file);
	local_file.close();
	return result;
}

vector<string> readFile(string file_name)
{
	return readFile(ifstream{ file_name });
}

/*void header_remover(vector<string> vec_out, vector<string> vec_in)
{
	for (int k = 0; k < 3; k++)
	{
		vec_out = StringSplitter::split(vec_in[k], " ");
	}
}*/