#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//create a class
class sections {
public:
	string courseName;
	double courseCode;
	string courseSection;
};
// Load file function
void LoadFile(sections data[], int&count)
{
	
	ifstream f("C:\\Users\\christopherzaman\\Desktop\\updatedSections.txt");
	if (f.good())
	{
		while (!f.eof())
		{
			f >> data[count].courseName;
			f >> data[count].courseCode;
			f >> data[count].courseSection;
			count++;
		}
	}
	f.close();
}
//Add course to list function
void AddCourse(sections data[], int &count)
{
	string yourCoursename;
	cout << "Enter your course Name (example BPL):" << endl;
	cin >> yourCoursename;

	double yourCourseCode;
	cout << "Enter your course Code (example 5100):" << endl;
	cin >> yourCourseCode;

	string yourCourseSection;
	cout << "Enter your course Section (example LMSB):" << endl;
	cin >> yourCourseSection;

	data[count].courseName = yourCoursename;
	data[count].courseCode = yourCourseCode;
	data[count].courseSection = yourCourseSection;

	count++;
}
//Search for course in the list
void SearchCourse(sections data[], int &count)
{
	string courseName;
	cout << "Enter course name:" << endl;
	cin >> courseName;

	double courseCode;
	cout << "Enter course code:" << endl;
	cin >> courseCode;

	string courseSection;
	cout << "Enter course section:" << endl;
	cin >> courseSection;

	bool found = false;
	for (int i = 0; i < count; i++)
	{
		if (data[i].courseName == courseName && data[i].courseCode == courseCode && data[i].courseSection == courseSection)
		{
			cout << "Great News!" << endl;
			cout << "That section is available" << endl;
			cout << "A swap will be made, you will be enrolled in " << data[i].courseName << " " << data[i].courseCode << " " << data[i].courseSection << endl;
			found = true;
		}
	}
	if (found == false)
	{
		cout << "Course not on the list" << endl;
	}
}
void DisplayList(sections data[], int &count)
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i].courseName << " " << data[i].courseCode << " " << data[i].courseSection << endl;

	}
}
void FileOut(sections data[], int &count)
{
	ofstream fileOut("C:\\Users\\christopherzaman\\Desktop\\updatedSections.txt");
	for (int i = 0; i < count; i++)
	{
		fileOut << data[i].courseName << " ";
		fileOut << data[i].courseCode << " ";
		fileOut << data[i].courseSection;
		if (i != count - 1)
		{
			fileOut << endl;
		}
	}
	fileOut.close();
}
int main()
{
	//Create an array of type class
	sections data[500];
	int count = 0;

	//read the file
	LoadFile(data, count);

	while (true)
	{
		cout << "Welcome to section swapper" << endl;
		cout << "==========================" << endl;
		cout << "1 - Add your section to the list of available sections to swap" << endl;
		cout << "2 - Search to see if the section you want is available" << endl;
		cout << "3 - Subscribe for alert if it becomes available " << endl;
		cout << "4 - Display list of sections to choose from " << endl;
		cout << "0 - Exit this wonderful life saver app" << endl;

		int choice;
		cin >> choice;

		//Add your section to the list
		if (choice == 1)
		{
			AddCourse(data, count);
		}
		//Search the list for section you want
		else if (choice == 2)
		{
			SearchCourse(data, count);
		}
		else if (choice == 3)
		{

		}
		//Display List
		else if (choice == 4)
		{
			DisplayList(data, count);
		}
		else if (choice == 5)
		{
			FileOut(data, count);
		}
		//Exit Program
		else if (choice == 0)
		{
			break;
		}
	}
	system("pause");
	return 0;
}