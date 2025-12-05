#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>

struct Employee {
    int id;
    std::string name;
    float salary;
    bool fired;
};

std::vector<Employee> loadEmployees(std::string path);
void saveEmployees(std::string path, const std::vector<Employee>& employees);
void showEmployees(const std::vector<Employee>& employees);
int getNextId(const std::vector<Employee>& employees);
int findEmployeeById(const std::vector<Employee>& employees, int id);

#endif// EMPLOYEE_H
