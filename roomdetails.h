#include <iostream>
using namespace std;
const int MAX_ROOMS = 100;

struct Room {
    int roomNo;
    int roomFloor;
    int roomCapacity;
    int roomRent;
};

void addRoom(Room rooms[], int &roomCount) {
    if (roomCount < MAX_ROOMS) {
        cout << "Enter Room Number: ";
        cin >> rooms[roomCount].roomNo;
        cout << "Enter Room Floor: ";
        cin >> rooms[roomCount].roomFloor;
        cout << "Enter Room Capacity: ";
        cin >> rooms[roomCount].roomCapacity;
        cout << "Enter Room Rent: ";
        cin >> rooms[roomCount].roomRent;
        roomCount++;
        cout << "Room added successfully.\n";
    } else {
        cout << "Maximum room capacity reached.\n";
    }
}

void viewRooms(const Room rooms[], int roomCount) {
    cout << "Room Details:\n";
    cout << setw(10) << "Room No" << setw(15) << "Floor" << setw(20) << "Capacity" << setw(15) << "Rent" << endl;
    for (int i = 0; i < roomCount; ++i) {
        cout << setw(10) << rooms[i].roomNo << setw(15) << rooms[i].roomFloor << setw(20) << rooms[i].roomCapacity << setw(15) << rooms[i].roomRent << endl;
    }
}

void searchRoom(const Room rooms[], int roomCount) {
    int targetRoomNo;
    cout << "Enter the Room Number to search: ";
    cin >> targetRoomNo;

    bool roomFound = false;
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i].roomNo == targetRoomNo) {
            cout << "Room found:\n";
            cout << setw(10) << "Room No" << setw(15) << "Floor" << setw(20) << "Capacity" << setw(15) << "Rent" << endl;
            cout << setw(10) << rooms[i].roomNo << setw(15) << rooms[i].roomFloor << setw(20) << rooms[i].roomCapacity << setw(15) << rooms[i].roomRent << endl;
            roomFound = true;
            break;
        }
    }

    if (!roomFound) {
        cout << "Room not found.\n";
    }
}

void editRoom(Room rooms[], int roomCount) {
    int targetRoomNo;
    cout << "Enter the Room Number to edit details: ";
    cin >> targetRoomNo;

    bool roomFound = false;
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i].roomNo == targetRoomNo) {
            cout << "Enter new floor: ";
            cin >> rooms[i].roomFloor;
            cout << "Enter new capacity: ";
            cin >> rooms[i].roomCapacity;
            cout << "Enter new rent: ";
            cin >> rooms[i].roomRent;
            cout << "Room details edited successfully.\n";
            roomFound = true;
            break;
        }
    }

    if (!roomFound) {
        cout << "Room not found.\n";
    }
}

void deleteRoom(Room rooms[], int &roomCount) {
    int targetRoomNo;
    cout << "Enter the Room Number to delete: ";
    cin >> targetRoomNo;

    bool roomFound = false;
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i].roomNo == targetRoomNo) {
            for (int j = i; j < roomCount - 1; ++j) {
                rooms[j] = rooms[j + 1];
            }
            --roomCount;
            cout << "Room deleted successfully.\n";
            roomFound = true;
            break;
        }
    }

    if (!roomFound) {
        cout << "Room not found.\n";
    }
}