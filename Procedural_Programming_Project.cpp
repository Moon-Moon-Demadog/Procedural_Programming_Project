// Part two of Procedural Programming Project: Gradebook
// Part one is under Gradebook
// This program will read a file containing student names and their grades and calculate their average grade.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function prototypes
void readDataFromFile(const string& filename, int& studentCount);
string studentNames[MAX_STUDENTS][MAX_GRADES];
float studentAverages[MAX_STUDENTS] = {0};
const int MAX_STUDENTS = 50;
const int MAX_GRADES = 5;

int main()
{
	// arrays to hold student data;
	char studentLetterGrades[MAX_STUDENTS] = { 0 };
	int studentCount = 0;
	string filename = "StudentGrades.txt";

}

// function to read data from file and get student count
void readDataFromFile(const string& filename, int& studentCount)
{
	ifstream inputFile(filename);
	if (!inputFile)
	{
		cout << "Error opening file: " << filename << endl;
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

// function to calculate average grades
static void calculateAverages(int studentCount, float studentAverages[])
{
	for (int i = 0; i < studentCount; ++i)
	{
		float sum = 0;
		int gradeCount = 0;
		for (int j = 1; j <= MAX_GRADES; ++j)
		{
			if (!studentNames[i][j].empty())
			{
				sum += stof(studentNames[i][j]);
				gradeCount++;
			}
		}
		if (gradeCount > 0)
		{
			studentAverages[i] = sum / gradeCount;
		}
		else
		{
			studentAverages[i] = 0;
		}
	}
}