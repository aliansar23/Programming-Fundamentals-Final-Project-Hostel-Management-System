#include<iostream>
#include <iomanip>
using namespace std;
const int MAX_STUDENTS = 100;

struct Student {
    string name;
    string lastName;
    int roomNumber;
};

void addStudent(Student students[], int &studentCount) {
    if (studentCount < MAX_STUDENTS) {
        cout << "Enter Student Name: ";
        cin >> students[studentCount].name;
        cout << "Enter Student Last Name: ";
        cin >> students[studentCount].lastName;
        cout << "Enter Student Room Number: ";
        cin >> students[studentCount].roomNumber;
        studentCount++;
        cout << "Student added successfully.\n";
    } else {
        cout << "Maximum student capacity reached.\n";
    }
}

void viewStudents(const Student students[], int studentCount) {
    cout << "Student Details:\n";
    cout << setw(15) << "Name" << setw(15) << "Last Name" << setw(15) << "Room Number" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << setw(15) << students[i].name << setw(15) << students[i].lastName << setw(15) << students[i].roomNumber << endl;
    }
}

void searchStudent(const Student students[], int studentCount) {
    int targetStudentRoom;
    cout << "Enter the Student Room Number to search: ";
    cin >> targetStudentRoom;

    bool studentFound = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].roomNumber == targetStudentRoom) {
            cout << "Student found:\n";
            cout << setw(15) << "Name" << setw(15) << "Last Name" << setw(15) << "Room Number" << endl;
            cout << setw(15) << students[i].name << setw(15) << students[i].lastName << setw(15) << students[i].roomNumber << endl;
            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        cout << "Student not found.\n";
    }
}

void editStudent(Student students[], int studentCount) {
    int targetStudentRoom;
    cout << "Enter the student's room number to edit details: ";
    cin >> targetStudentRoom;

    bool studentFound = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].roomNumber == targetStudentRoom) {
            cout << "Enter new name: ";
            cin >> students[i].name;
            cout << "Enter new last name: ";
            cin >> students[i].lastName;
            cout << "Student details edited successfully.\n";
            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        cout << "Student not found.\n";
    }
}

void deleteStudent(Student students[], int &studentCount) {
    int targetStudentRoom;
    cout << "Enter the student's room number to delete: ";
    cin >> targetStudentRoom;

    bool studentFound = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].roomNumber == targetStudentRoom) {
            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }
            --studentCount;
            cout << "Student deleted successfully.\n";
            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        cout << "Student not found.\n";
    }
}