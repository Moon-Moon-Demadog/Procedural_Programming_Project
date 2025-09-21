// Part two of Procedural Programming Project: Gradebook
// Part one is under Gradebook
// This program will read a file containing student names and their grades and calculate their average grade.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function prototypes
void readDataFromFile(const string& filename, int& studentCount);



int main()
{
	// arrays to hold student data
	const int MAX_STUDENTS = 50;
	const int MAX_GRADES = 5;
	string studentNames[MAX_STUDENTS][MAX_GRADES];
	float studentAverages[MAX_STUDENTS];
	char studentLetterGrades[MAX_STUDENTS];
	int studentCount = 0;
	string filename = "StudentGrades.txt";

}

// function to read data from file and get student count
void readDataFromFile(const string& filename, int& studentCount)
{
	ifstream inputFile(filename);
	if (!inputFile)
	{
		cerr << "Error opening file: " << filename << endl;
		return;
	}
	string name;
	float grade;
	while (inputFile >> name)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (inputFile >> grade)
			{
				// Store the name and grades in the arrays
				studentNames[studentCount][0] = name;
				studentNames[studentCount][i + 1] = to_string(grade);
			}
			else
			{
				break; // No more grades for this student
			}
		}
		studentCount++;
	}
	inputFile.close();
}