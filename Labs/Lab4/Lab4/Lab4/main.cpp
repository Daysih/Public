#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "readFile.h"
#include "Decoder.h"
#include "StringSplitter.h"
using namespace std;

int main()
{
	//auto data = readFile("tinypix.ppm");
	//auto dimensions = StringSplitter::split(data[1], " ");
	//int width = stoi(dimensions[0]);
	//int height = stoi(dimensions[1]);
	//vector<vector<vector<int>>> pixels{};
	////recommended
	//// vector<vector<pixel>> Pixels{}

	////initialize our vector
	//pixels.resize(height);

	////finally process data
	//vector<int> current_pixel{};
	//vector<vector<int>> current_row{};

	//int row_counter = 0;
	//for (int i = 3; i < data.size(); i++)
	//{
	//	string line = data[i];
	//	vector<string> pieces = StringSplitter::split(line, " ");
	//	for (string piece : pieces)
	//	{
	//		try
	//		{
	//			int color_value = stoi(piece);
	//			current_pixel.push_back(color_value);
	//			if (current_pixel.size() == 3)
	//			{
	//				//pixel complete
	//				// create pixel 2/ pixel p{current[0], r,g,b}
	//				current_row.push_back(current_pixel);
	//				current_pixel = vector<int>{};
	//			}
	//			if (current_row.size() == width)
	//			{
	//				pixels[row_counter] = current_row;
	//				current_row = vector<vector<int>>{};
	//				row_counter++;
	//			}
	//		}
	//		catch (...)
	//		{

	//		}
	//	}
	//}


	//pixels[x][y]= <r,g,b>;
	string file_input;
	cout << "Enter the file you wish to decode: ";
	cin >> file_input;
	Decoder file_decode(file_input);

	return 0;

}






void print(vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++)
	{
		cout << input.at(i) << endl;
	}
}