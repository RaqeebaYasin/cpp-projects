#include <iostream>
using namespace std;

int main() {
    float marks[5], total = 0, average;
    char grade;

    // Input marks
    cout << "Enter marks for 5 subjects (out of 100):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];
        total += marks[i];
    }

    // Calculate average
    average = total / 5;

    // Determine grade
    if (average >= 90)
        grade = 'A';
    else if (average >= 80)
        grade = 'B';
    else if (average >= 70)
        grade = 'C';
    else if (average >= 60)
        grade = 'D';
    else
        grade = 'F';

    // Output results
    cout << "\nTotal Marks: " << total << "/500" << endl;
    cout << "Average: " << average << "%" << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}
