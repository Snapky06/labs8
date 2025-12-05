#include "Employee.h"
#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string path = "employees.csv";
    std::vector<Employee> employees = loadEmployees(path);
    int option = 0;

    do {
        std::cout << "\n--- Employee Management ---\n";
        std::cout << "[1] Add Employee";
        std::cout << "[2] Edit Employee";
        std::cout << "[3] Fire Employee (Soft Delete)";
        std::cout << "[4] Show Active Employees";
        std::cout << "[5] Exit";
        std::cout << "Select an option: ";
        std::cin >> option;

        if (option == 1) {
            std::string name;
            float salary;

            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            do {
                std::cout << "Enter salary: ";
                std::cin >> salary;
                if (salary <= 0) std::cout << "Salary must be positive.\n";
            } while (salary <= 0);

            Employee newEmp;
            newEmp.id = getNextId(employees);
            newEmp.name = name;
            newEmp.salary = salary;
            newEmp.fired = false;

            employees.push_back(newEmp);
            saveEmployees(path, employees);
            std::cout << "Employee added successfully.\n";

        } else if (option == 2) {
            int id;
            std::cout << "Enter ID to edit: ";
            std::cin >> id;

            int index = findEmployeeById(employees, id);

            if (index != -1) {
                if (employees[index].fired) {
                    std::cout << "Cannot edit a fired employee.\n";
                } else {
                    std::string name;
                    float salary;

                    std::cout << "Enter new name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);

                    do {
                        std::cout << "Enter new salary: ";
                        std::cin >> salary;
                    } while (salary <= 0);

                    employees[index].name = name;
                    employees[index].salary = salary;
                    saveEmployees(path, employees);
                    std::cout << "Employee updated successfully.\n";
                }
            } else {
                std::cout << "Employee not found.\n";
            }

        } else if (option == 3) {
            int id;
            std::cout << "Enter ID to fire: ";
            std::cin >> id;

            int index = findEmployeeById(employees, id);

            if (index != -1) {
                employees[index].fired = true;
                saveEmployees(path, employees);
                std::cout << "Employee fired successfully.\n";
            } else {
                std::cout << "Employee not found.\n";
            }

        } else if (option == 4) {
            showEmployees(employees);
        }

    } while (option != 5);

    return a.exec();
}
