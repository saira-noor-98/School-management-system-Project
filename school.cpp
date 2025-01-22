#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

struct Teacher {
    int id;
    string name;
    string subject;
};

struct ClassSchedule {
    string className;
    string time;
};

struct FeeRecord {
    int studentId;
    double amountPaid;
};


Student students[50];  
Teacher teachers[50];  
ClassSchedule schedules[50]; 
FeeRecord fees[50]; 

int studentCount = 0;
int teacherCount = 0;
int scheduleCount = 0;
int feeCount = 0;


void studentMenu();
void teacherMenu();
void classScheduleMenu();
void feeMenu();


int main() {
    int choice;
    do {
        cout << "\n--- School Management System ---\n";
        cout << "1. Student Management\n";
        cout << "2. Teacher Management\n";
        cout << "3. Class Schedule Management\n";
        cout << "4. Fee Management\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                studentMenu();
                break;
            case 2:
                teacherMenu();
                break;
            case 3:
                classScheduleMenu();
                break;
            case 4:
                feeMenu();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}


void addStudent() {
    if (studentCount >= 50) {
        cout << "Student limit reached!\n";
        return;
    }

    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Student Age: ";
    cin >> s.age;
    students[studentCount] = s;
    studentCount++;
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No students available.\n";
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name << ", Age: " << students[i].age << "\n";
    }
}

void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = true;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student deleted successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }
}

void studentMenu() {
    int choice;
    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}


void addTeacher() {
    if (teacherCount >= 50) {
        cout << "Teacher limit reached!\n";
        return;
    }

    Teacher t;
    cout << "Enter Teacher ID: ";
    cin >> t.id;
    cout << "Enter Teacher Name: ";
    cin.ignore();
    getline(cin, t.name);
    cout << "Enter Subject: ";
    getline(cin, t.subject);
    teachers[teacherCount] = t;
    teacherCount++;
    cout << "Teacher added successfully!\n";
}

void viewTeachers() {
    if (teacherCount == 0) {
        cout << "No teachers available.\n";
        return;
    }
    for (int i = 0; i < teacherCount; i++) {
        cout << "ID: " << teachers[i].id << ", Name: " << teachers[i].name << ", Subject: " << teachers[i].subject << "\n";
    }
}

void deleteTeacher() {
    int id;
    cout << "Enter Teacher ID to delete: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < teacherCount; i++) {
        if (teachers[i].id == id) {
            found = true;
            for (int j = i; j < teacherCount - 1; j++) {
                teachers[j] = teachers[j + 1];
            }
            teacherCount--;
            cout << "Teacher deleted successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "Teacher not found.\n";
    }
}

void teacherMenu() {
    int choice;
    do {
        cout << "\n--- Teacher Management ---\n";
        cout << "1. Add Teacher\n";
        cout << "2. View Teachers\n";
        cout << "3. Delete Teacher\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTeacher();
                break;
            case 2:
                viewTeachers();
                break;
            case 3:
                deleteTeacher();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}


void addClassSchedule() {
    if (scheduleCount >= 50) {
        cout << "Class schedule limit reached!\n";
        return;
    }

    ClassSchedule cs;
    cout << "Enter Class Name: ";
    cin.ignore();
    getline(cin, cs.className);
    cout << "Enter Time: ";
    getline(cin, cs.time);
    schedules[scheduleCount] = cs;
    scheduleCount++;
    cout << "Class schedule added successfully!\n";
}

void viewClassSchedules() {
    if (scheduleCount == 0) {
        cout << "No class schedules available.\n";
        return;
    }
    for (int i = 0; i < scheduleCount; i++) {
        cout << "Class: " << schedules[i].className << ", Time: " << schedules[i].time << "\n";
    }
}

void classScheduleMenu() {
    int choice;
    do {
        cout << "\n--- Class Schedule Management ---\n";
        cout << "1. Add Class Schedule\n";
        cout << "2. View Class Schedules\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addClassSchedule();
                break;
            case 2:
                viewClassSchedules();
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

// Fee Management
void addFeeRecord() {
    if (feeCount >= 50) {
        cout << "Fee record limit reached!\n";
        return;
    }

    FeeRecord fr;
    cout << "Enter Student ID: ";
    cin >> fr.studentId;
    cout << "Enter Amount Paid: ";
    cin >> fr.amountPaid;
    fees[feeCount] = fr;
    feeCount++;
    cout << "Fee record added successfully!\n";
}

void viewFeeRecords() {
    if (feeCount == 0) {
        cout << "No fee records available.\n";
        return;
    }
    for (int i = 0; i < feeCount; i++) {
        cout << "Student ID: " << fees[i].studentId << ", Amount Paid: " << fees[i].amountPaid << "\n";
    }
}

void feeMenu() {
    int choice;
    do {
        cout << "\n--- Fee Management ---\n";
        cout << "1. Add Fee Record\n";
        cout << "2. View Fee Records\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFeeRecord();
                break;
            case 2:
                viewFeeRecords();
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}