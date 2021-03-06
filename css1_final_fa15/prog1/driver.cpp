// Bianca Hernandez
// Date: December 17 2015
// CSS-1 Fa15 Final Exam Prog 1
//
//***************************************************
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void fillVector(vector<string>& v, ifstream& in);
void outGoodPasswords(string ara[], int length, ofstream& out, vector<string>& v);
bool isGood(vector<string>& v, string word);

int main()
{
	ifstream fin;
	ofstream fout;
	vector <string> hackedPasswords;
	
	fin.open("passwords.txt");
	fout.open("good_words.txt");

	if(fin.fail() || fout.fail())
	{
		cout << "Error Opening Files" << endl;
	}
	
	fout << "Bianca Hernandez" << endl;
	fout << "\nGood Passwords: "<< endl;
	
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};

	fillVector(hackedPasswords, fin);
	outGoodPasswords(possible, SIZE, fout, hackedPasswords);

	fin.close();
	fout.close();

	return 0;
} // end of main()


//*************************************
void fillVector(vector<string>& v, ifstream& in)
{
	string password;
	while(in >> password)
	{
		v.push_back(password);
	}	
}// end fill Vector(_)
void outGoodPasswords(string ara[], int length, ofstream& out, vector<string>& v)
{
	string word;

	for(int i = 0; i < length; i++)
	{	
		word = ara[i];
		if(isGood(v,word))
		{
			out << word << endl;
		}
	}
	return;
}
bool isGood(vector<string>& v, string word)
{
		for(int i = 0; i < v.size(); i++)
		{
			if(word == v[i])
			{
				return false;
			}
		}
		
	return true;
} // end isGood()

 
