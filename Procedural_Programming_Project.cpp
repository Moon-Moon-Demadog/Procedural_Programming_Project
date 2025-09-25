// Part two of Procedural Programming Project: Gradebook
// Part one is under Gradebook
// This program will read a file containing student names and their grades and calculate their average grade.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const int MAX_STUDENTS = 50;
const int TEST_SCORE = 5;

/* 
getStudentData:
Preconditions- a file has already been opened and validated The number
               of records on file is unknown.
Input- file object
Postconditions- Student names are in an arrya of strings. Grades are in a
                2D array of integers with 5 grades per student and the
				students names are in the same order as their grades.
				another parralel array contains the average grade for each student.
				The number of students on file will be returned.
Output- array of strinsg, 2D array of integers, char and the record count.
*/
int getStudentData(string students[], double grades[][TEST_SCORE], int maxRows, ifstream& sData);
char getLetterGrade(double average);
/* report:
* Preconditions- all the data is available (student names, grades, average grades, letter grades)
* Input- name array, grades array(2D), average grades array, letter grades array, and the number of students
* Postconditions- a formated report is output to the screen
*/

void report(const string students[], const double grades[][TEST_SCORE], int numStudents, double avgGrades[], const char letterGrades[]);

/* calculateAVGrade
* Preconditions- test scores for a student are in an array of integers
* Input- 2D array of integers, and the number of test scores
* Postconditions- the average of the test scores is calculated and returned
* Output- the average of the test scores
*			as well as an array of letter grades for each student.
*			and a double array of average grades for each student.
*/
void calculateAVGGrade(const double grades[][TEST_SCORE], int numStudents, double avgGrades[]);

int main()
{
	string studentNames[MAX_STUDENTS];
	double studentGrades[MAX_STUDENTS][TEST_SCORE];
	double avgGrades[MAX_STUDENTS];
	char letterGrades[MAX_STUDENTS] = { MAX_STUDENTS };
	int numStudents;
	ifstream inFile("TextFile1.tx");
	if (inFile.fail())
	{
		cout << "Input file did not open correctly. Program ending." << endl;
		return 1;
	}
	numStudents = getStudentData(studentNames, studentGrades, MAX_STUDENTS, inFile);
	calculateAVGGrade(studentGrades, numStudents, avgGrades);
	for (int i = 0; i < numStudents; i++)
	{
		letterGrades[i] = getLetterGrade(avgGrades[i]);
	}
	report(studentNames, studentGrades, numStudents, avgGrades, letterGrades );
}

int getStudentData(string students[], double grades[][TEST_SCORE], int maxRows, ifstream& sData)
{
		int count = 0;
		while (count < maxRows && sData >> students[count])
		{
			for (int j = 0; j < TEST_SCORE; j++)
			{
				sData >> grades[count][j];
			}
			count++;
		}
		sData.close();
	return count;
}

void report(const string students[], const double grades[][TEST_SCORE], int numStudents, double avgGrades[], const char letterGrades[])
{
	cout << "Student Grade Report" << endl;
	cout << "====================" << endl;
	cout << fixed << setprecision(2);
	cout << "Student Name     " << "  Grade               " << "Average Grade " << "Letter Grade" << endl;
	cout << "========================================================================================" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << left << setw(10) << students[i] << right;
		for (int j = 0; j < TEST_SCORE; j++)
		{
			cout << setw(14) << grades[i][j];
		}
		cout << setw(14) << avgGrades[i] << setw(14) << letterGrades[i] << endl;
	}
}

void calculateAVGGrade(const double grades[][TEST_SCORE], int numStudents, double avgGrades[])
{
	for (int i = 0; i < numStudents; i++)
	{
		double total = 0.0;
		for (int j = 0; j < TEST_SCORE; j++)
		{
			total += grades[i][j];
		}
		avgGrades[i] = total / TEST_SCORE;
	}
}

char getLetterGrade(double average)
{
	if (average >= 90.0)
		return 'A';
	else if (average >= 80.0)
		return 'B';
	else if (average >= 70.0)
		return 'C';
	else if (average >= 60.0)
		return 'D';
	else
		return 'F';
}
// End of program