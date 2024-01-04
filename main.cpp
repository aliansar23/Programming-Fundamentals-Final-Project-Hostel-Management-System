#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "roomdetails.h"
#include"studentDetails.h"
using namespace std;

const int MAX_RESERVATIONS = 100;

struct Reservation {
    int roomNo;
    int studentRoom;
};

// Function declarations
void roomManagement(Room rooms[], int &roomCount);
void studentManagement(Student students[], int &studentCount);
void reservationManagement(Reservation reservations[], int &reservationCount, const Room rooms[], int roomCount, const Student students[], int studentCount);
void addReservation(Reservation reservations[], int &reservationCount, const Room rooms[], int roomCount, const Student students[], int studentCount);
void viewReservations(const Reservation reservations[], int reservationCount, const Room rooms[], int roomCount, const Student students[], int studentCount);
void searchReservation(const Reservation reservations[], int reservationCount, const Room rooms[], int roomCount, const Student students[], int studentCount);
void saveReservationsToFile(const Reservation reservations[], int reservationCount);
void loadReservationsFromFile(Reservation reservations[], int &reservationCount);

int main() {
    Room rooms[MAX_ROOMS];
    int roomCount = 0;

    Student students[MAX_STUDENTS];
    int studentCount = 0;

    Reservation reservations[MAX_RESERVATIONS];
    int reservationCount = 0;

    loadReservationsFromFile(reservations, reservationCount);

    while (true) {
        cout << "Menu:\n";
        cout << "1. Room Management\n";
        cout << "2. Student Management\n";
        cout << "3. Reservation Management\n";
        cout << "4. Save and Quit\n";
        cout << "Enter an option: ";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                roomManagement(rooms, roomCount);
                break;
            case 2:
                studentManagement(students, studentCount);
                break;
            case 3:
                reservationManagement(reservations, reservationCount, rooms, roomCount, students, studentCount);
                break;
            
                
            case 4:
                saveReservationsToFile(reservations, reservationCount);
                cout << "Program ends\n";
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    }

    return 0;
}

void roomManagement(Room rooms[], int &roomCount) {
    while (true) {
        int option;
        cout << setw(120) <<"*-----------------------Room Management------------------------*\n";
        cout << "1. Add Room\n";
        cout << "2. View Rooms\n";
        cout << "3. Search Room\n";
        cout << "4. Edit Room\n";
        cout << "5. Delete Room\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                addRoom(rooms, roomCount);
                break;
            case 2:
                viewRooms(rooms, roomCount);
                break;
            case 3:
                searchRoom(rooms, roomCount);
                break;
            case 4:
                editRoom(rooms, roomCount);
                break;
            case 5:
                deleteRoom(rooms, roomCount);
                break;
            case 6:
                return; // Exit the room management section and go back to the main menu
            default:
                cout << "Invalid option!\n";
        }
    }
}



void studentManagement(Student students[], int &studentCount) {
    while (true) {
        int option;
        cout << setw(120) <<"*-----------------------Student Management------------------------*\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Edit Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                editStudent(students, studentCount);
                break;
            case 5:
                deleteStudent(students, studentCount);
                break;
            case 6:
                return; // Exit the student management section and go back to the main menu
            default:
                cout << "Invalid option!\n";
        }
    }
}






void reservationManagement(Reservation reservations[], int &reservationCount, const Room rooms[], int roomCount, const Student students[], int studentCount) {
    while (true) {
        int option;
        cout << setw(120) <<"*-----------------------Reservation Management------------------------*\n";
        cout << "1. Add Reservation\n";
        cout << "2. View Reservations\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                addReservation(reservations, reservationCount, rooms, roomCount, students, studentCount);
                break;
            case 2:
                viewReservations(reservations, reservationCount, rooms, roomCount, students, studentCount);
                break;
            case 3:
                return; // Exit the reservation management section and go back to the main menu
            default:
                cout << "Invalid option!\n";
        }
    }
}


void addReservation(Reservation reservations[], int &reservationCount, const Room rooms[], int roomCount, const Student students[], int studentCount) {
    if (reservationCount < MAX_RESERVATIONS) {
        int roomNo, studentRoom;
        cout << "Enter Room Number: ";
        cin >> roomNo;

        bool roomFound = false;
        for (int i = 0; i < roomCount; ++i) {
            if (rooms[i].roomNo == roomNo) {
                roomFound = true;
                break;
            }
        }

        if (!roomFound) {
            cout << "Room not found.\n";
            return;
        }

        cout << "Enter Student Room Number: ";
        cin >> studentRoom;

        bool studentFound = false;
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].roomNumber == studentRoom) {
                studentFound = true;
                break;
            }
        }

        if (!studentFound) {
            cout << "Student not found.\n";
            return;
        }

        reservations[reservationCount].roomNo = roomNo;
        reservations[reservationCount].studentRoom = studentRoom;
        reservationCount++;

        cout << "Reservation added successfully.\n";
    } else {
        cout << "Maximum reservation capacity reached.\n";
    }
}

void viewReservations(const Reservation reservations[], int reservationCount, const Room rooms[], int roomCount, const Student students[], int studentCount) {
    cout << "Reservation Details:\n";
    cout << setw(10) << "Room No" << setw(15) << "Student Name" << setw(15) << "Last Name" << setw(15) << "Student Room" << endl;
    
    for (int i = 0; i < reservationCount; ++i) {
        int roomNo = reservations[i].roomNo;
        int studentRoom = reservations[i].studentRoom;
        int roomIndex = -1;
        for (int j = 0; j < roomCount; ++j) {
            if (rooms[j].roomNo == roomNo) {
                roomIndex = j;
                break;
            }
        }

   
        int studentIndex = -1;
        for (int k = 0; k < studentCount; ++k) {
            if (students[k].roomNumber == studentRoom) {
                studentIndex = k;
                break;
            }
        }

        
        cout << setw(10) << roomNo;
        if (studentIndex != -1) {
            cout << setw(15) << students[studentIndex].name << setw(15) << students[studentIndex].lastName;
        } else {
            cout << setw(30) << "Student details not found";
        }
        cout << setw(15) << studentRoom << endl;
    }
}




// Other Utility Functions
void saveReservationsToFile(const Reservation reservations[], int reservationCount) {
    ofstream outFile("reservations.txt");

    if (outFile.is_open()) {
        for (int i = 0; i < reservationCount; ++i) {
            outFile << reservations[i].roomNo << " " << reservations[i].studentRoom << "\n";
        }

        outFile.close();
        cout << "Reservations saved to file successfully.\n";
    } else {
        cout << "Unable to open file for saving reservations.\n";
    }
}

void loadReservationsFromFile(Reservation reservations[], int &reservationCount) {
    ifstream inFile("reservations.txt");

    if (inFile.is_open()) {
        while (inFile >> reservations[reservationCount].roomNo >> reservations[reservationCount].studentRoom) {
            reservationCount++;
            if (reservationCount >= MAX_RESERVATIONS) {
                break;
            }
        }

        inFile.close();
        cout << "Reservations loaded from file successfully.\n";
    } else {
        cout << "Unable to open file for loading reservations. Starting with an empty reservation list.\n";
    }
}
