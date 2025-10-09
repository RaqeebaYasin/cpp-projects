#include <iostream>
#include <string>
using namespace std;

const int MAX_PATIENTS = 100;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string disease;
    bool isAdmitted;
};

Patient patients[MAX_PATIENTS];
int count = 0;

// Function to add a new patient
void addPatient() {
    if (count >= MAX_PATIENTS) {
        cout << "Hospital record is full!\n";
        return;
    }

    cout << "Enter Patient ID: ";
    cin >> patients[count].id;
    cin.ignore(); // Clear newline
    cout << "Enter Name: ";
    getline(cin, patients[count].name);
    cout << "Enter Age: ";
    cin >> patients[count].age;
    cin.ignore();
    cout << "Enter Gender (M/F): ";
    getline(cin, patients[count].gender);
    cout << "Enter Disease: ";
    getline(cin, patients[count].disease);
    cout << "Is Admitted (1 for Yes, 0 for No): ";
    cin >> patients[count].isAdmitted;

    count++;
    cout << "Patient added successfully!\n";
}

// Function to display all patients
void displayPatients() {
    if (count == 0) {
        cout << "No patients to display.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nPatient ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Disease: " << patients[i].disease << endl;
        cout << "Admitted: " << (patients[i].isAdmitted ? "Yes" : "No") << endl;
        cout << "----------------------------";
    }
}

// Function to search patient by ID
void searchPatient() {
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            found = true;
            cout << "\nPatient ID: " << patients[i].id << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Gender: " << patients[i].gender << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Admitted: " << (patients[i].isAdmitted ? "Yes" : "No") << endl;
            break;
        }
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}

// Function to update patient record
void updatePatient() {
    int id;
    cout << "Enter Patient ID to update: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            found = true;
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, patients[i].name);
            cout << "Enter New Age: ";
            cin >> patients[i].age;
            cin.ignore();
            cout << "Enter New Gender: ";
            getline(cin, patients[i].gender);
            cout << "Enter New Disease: ";
            getline(cin, patients[i].disease);
            cout << "Is Admitted (1 for Yes, 0 for No): ";
            cin >> patients[i].isAdmitted;
            cout << "Patient updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}

// Function to delete a patient
void deletePatient() {
    int id;
    cout << "Enter Patient ID to delete: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            found = true;
            // Shift remaining patients left
            for (int j = i; j < count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            count--;
            cout << "Patient deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n=== Hospital Management System ===" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display All Patients" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Update Patient" << endl;
        cout << "5. Delete Patient" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: cout << "Exiting system. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
