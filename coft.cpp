#include <iostream>
#include <exception>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

class Employee {
private:
    string Name;
    int Age;
    int Salary;
    string Position;
    bool isWorking;

public:
    // Constructor with parameters
    Employee(string name, int age, int salary, string position) {
        Name = name;
        Age = age;
        Salary = salary;
        Position = position;
        isWorking = true;
    }

    // Default constructor with initialization
    Employee() {
        Name = "";
        Age = 0;
        Salary = 0;
        Position = "";
        isWorking = true;
    }

    // Setters
    void setFIO(string name) { Name = name; }
    void setAge(int age) { Age = age; }
    void setSalary(int salary) { Salary = salary; }
    void setPosition(string position) { Position = position; }
    void setIsWorking(bool is_working) { isWorking = is_working; }

    // Getters
    string getFIO() { return Name; }
    int getAge() { return Age; }
    int getSalary() { return Salary; }
    string getPosition() { return Position; }
    bool getIsWorking() { return isWorking; }

    // Return employee information as a formatted string
    string toString() {
        return "Имя: " + Name + "\nВозраст: " + to_string(Age) +
            "\nЗарплата: " + to_string(Salary) +
            "\nДолжность: " + Position + '\n';
    }
};

class HRSystem {
private:
    Employee* staff;
    int N;

    // Increase array size and copy data
    void copyArray(int newSize) {
        Employee* newArray = new Employee[newSize];
        for (int i = 0; i < N; i++) {
            newArray[i] = staff[i];
        }
        delete[] staff; // Free old memory
        staff = newArray;
        N = newSize;
    }

public:
    // Constructor: input initial employees
    HRSystem() {
        cout << "How many employees work in the company? ";
        int n;
        cin >> n;
        N = n;
        staff = new Employee[N];

        cout << "Enter information about your employees:\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < N; ++i) {
            string Name, Position;
            int Age, Salary;

            cout << "Enter name: ";
            getline(cin, Name);
            staff[i].setFIO(Name);

            cout << "Enter age: ";
            cin >> Age;
            staff[i].setAge(Age);

            cout << "Enter salary: ";
            cin >> Salary;
            staff[i].setSalary(Salary);

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter position: ";
            getline(cin, Position);
            staff[i].setPosition(Position);

            cout << endl;
        }

        system("cls"); // Clear screen
    }

    // Mark employee as not working (soft delete)
    void deleteEmployee() {
        string name;
        cout << "Enter the name of the employee to remove: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        system("cls");

        for (int i = 0; i < N; i++) {
            if (name == staff[i].getFIO()) {
                staff[i].setIsWorking(false);
                cout << "Employee deleted\n";
                return;
            }
        }
        cout << "Employee not found\n";
    }

    // Add a new employee
    void addEmployee() {
        cout << "Enter new employee data:\n";
        string Name, Position;
        int Age, Salary;

        cout << "Enter name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, Name);

        cout << "Enter age: ";
        cin >> Age;

        cout << "Enter salary: ";
        cin >> Salary;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter position: ";
        getline(cin, Position);

        system("cls");

        Employee newEmployee(Name, Age, Salary, Position);

        // Reuse a slot if an employee was deleted
        for (int i = 0; i < N; i++) {
            if (!staff[i].getIsWorking()) {
                staff[i] = newEmployee;
                cout << "Employee added (replaced)\n";
                return;
            }
        }

        // Otherwise expand array and add
        copyArray(N + 1);
        staff[N - 1] = newEmployee;
        cout << "Employee added\n";
    }

    // Show all active employees
    void showAllStaff() {
        for (int i = 0; i < N; i++) {
            if (staff[i].getIsWorking()) {
                cout << staff[i].toString() << endl;
            }
        }
        cout << endl;
    }

    // Main menu
    bool mainMenu() {
        int choice;
        cout << "Choose an option:\n"
            << "1 - Show all employees\n"
            << "2 - Delete employee\n"
            << "3 - Add new employee\n"
            << "4 - Exit\n";
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            showAllStaff();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            addEmployee();
            break;
        case 4:
            return true; // Exit program
        default:
            cout << "Unknown command\n";
        }

        return false;
    }

    // Destructor: free memory
    ~HRSystem() {
        delete[] staff;
    }
};

// Main function
int main() {
    setlocale(LC_ALL, "Russian");
    HRSystem system;
    while (!system.mainMenu());
    return 0;
}
