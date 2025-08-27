#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course {
    string name;
    float grade;
    int creditHours;
};

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    float totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << " details:\n";
        cout << "Course name: ";
        cin >> ws; // to consume any leftover newline
        getline(cin, courses[i].name);

        cout << "Grade (on a 10-point scale): ";
        cin >> courses[i].grade;

        cout << "Credit hours: ";
        cin >> courses[i].creditHours;

        totalGradePoints += courses[i].grade * courses[i].creditHours;
        totalCredits += courses[i].creditHours;
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n--- Semester Summary ---\n";
    cout << left << setw(20) << "Course"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours" << endl;

    for (const auto& course : courses) {
        cout << left << setw(20) << course.name
             << setw(10) << course.grade
             << setw(15) << course.creditHours << endl;
    }

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nFinal CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
