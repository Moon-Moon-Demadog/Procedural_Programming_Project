// Part two of Procedural Programming Project: Gradebook
// Part one is under Gradebook
// This program will read a file containing student names and their grades and calculate their average grade.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function prototypes
void readDataFromFile(const string& filename, int& studentCount);
static void displayStudentInfo(int studentCount);


int main() {
	// arrays to hold student data
	const int MAX_STUDENTS = 50;
	const int MAX_GRADES = 5;
	string studentNames[MAX_STUDENTS][MAX_GRADES];
	float studentAverages[MAX_STUDENTS];
	char studentLetterGrades[MAX_STUDENTS];

	int studentCount = 0;
	string filename = "grades.txt"; // Input file name
	// Read data from file
	readDataFromFile(filename, studentCount);

}

// Function to read data from file and populate arrays
void readDataFromFile(const string& a, int& studentCount)
{
}

// function to calculate average using grades array
void calculateAverage(int grades[], int gradeCount, float& average) {
	int sum = 0;
	for (int i = 0; i < gradeCount; i++) {
		sum += grades[i];
	}
	average = static_cast<float>(sum) / gradeCount;
}


// function to display student information