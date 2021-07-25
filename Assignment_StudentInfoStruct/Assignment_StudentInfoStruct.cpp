#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct SchoolInfo
{
    string schoolName;
    string schoolAddress;
    string city;
    string province;
    string postalCode;
};

struct CourseInfo
{
    string Course1A;
    string Course1B;
    string Course2A;
    string Course2B;
    string Course3A;
    string Course3B;
    string Course4A;
    string Course4B;
};

struct PersonalInfo
{
    string firstName;
    string lastName;
    string gender;
    int age;
};

struct StudentInfo
{
    PersonalInfo personalInfo;
    int grade;
    SchoolInfo school;
    CourseInfo courses;
};

StudentInfo fillStudentInfo()
{
    StudentInfo student;
    cout << "Please enter the first name of the student" << endl;
    cin >> student.personalInfo.firstName;
    cout << "Please enter the last name of the student" << endl;
    cin >> student.personalInfo.lastName;
    cout << "Please enter the gender of the student" << endl;
    cin >> student.personalInfo.gender;
    cout << "Please enter the age of the student" << endl;
    cin >> student.personalInfo.age;
    cout << "Please enter the grade of the student" << endl;
    cin >> student.grade;
    cout << "Please enter the name of the student's school" << endl;
    cin >> student.school.schoolName;
    cout << "Please enter the address of the student's school" << endl;
    cin.ignore(1, '\n');
    getline(cin, student.school.schoolAddress);
    cout << "Please enter the city of the student's school" << endl;
    cin >> student.school.city;
    cout << "Please enter the province of the student's school" << endl;
    cin >> student.school.province;
    cout << "Please enter the postal code of the student's school" << endl;
    cin >> student.school.postalCode;
    cout << "Please enter the student's first course in quadmester 1" << endl;
    cin >> student.courses.Course1A;
    cout << "Please enter the student's second course in quadmester 1" << endl;
    cin >> student.courses.Course1B;
    cout << "Please enter the student's first course in quadmester 2" << endl;
    cin >> student.courses.Course2A;
    cout << "Please enter the student's second course in quadmester 2" << endl;
    cin >> student.courses.Course2B;
    cout << "Please enter the student's first course in quadmester 3" << endl;
    cin >> student.courses.Course3A;
    cout << "Please enter the student's second course in quadmester 3" << endl;
    cin >> student.courses.Course3B;
    cout << "Please enter the student's first course in quadmester 4" << endl;
    cin >> student.courses.Course4A;
    cout << "Please enter the student's second course in quadmester 4" << endl;
    cin >> student.courses.Course4B;
    return student;
}

void printTimeTable(StudentInfo student)
{
    cout << student.personalInfo.lastName << ", " << student.personalInfo.firstName << endl;
    cout << "Age: " << student.personalInfo.age << " Gender: " << student.personalInfo.gender << endl;
    cout << "Gr. " << student.grade << endl;

    cout << student.school.schoolName << " " << student.school.schoolAddress << " " << student.school.city << " " << student.school.province << ", " << student.school.postalCode << endl;
    cout << endl << left << setw(8) << " " << setw(15) << "Course A" << setw(15) << "Course B" << endl;
    cout << left << setw(8) << "Quad 1 " << setw(15) << student.courses.Course1A << setw(15) << student.courses.Course1B << endl;
    cout << left << setw(8) << "Quad 2 " << setw(15) << student.courses.Course2A << setw(15) << student.courses.Course2B << endl;
    cout << left << setw(8) << "Quad 3 " << setw(15) << student.courses.Course3A << setw(15) << student.courses.Course3B << endl;
    cout << left << setw(8) << "Quad 4 " << setw(15) << student.courses.Course4A << setw(15) << student.courses.Course4B << endl;
}

int main()
{
    StudentInfo student = fillStudentInfo();
    printTimeTable(student);
}