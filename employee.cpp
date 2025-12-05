#include "Employee.h"
#include <fstream>
#include <sstream>

std::vector<Employee> loadEmployees(std::string path) {
    std::vector<Employee> data;
    std::ifstream file(path);

    if (!file.is_open()) return data;

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string segment;
        Employee emp;

        std::getline(ss, segment, ',');
        emp.id = std::stoi(segment);

        std::getline(ss, emp.name, ',');

        std::getline(ss, segment, ',');
        emp.salary = std::stof(segment);

        std::getline(ss, segment, ',');
        emp.fired = (std::stoi(segment) == 1);

        data.push_back(emp);
    }

    file.close();
    return data;
}

void saveEmployees(std::string path, const std::vector<Employee>& employees) {
    std::ofstream file(path);

    file << "id,name,salary,fired" << std::endl;

    for (const auto& emp : employees) {
        file << emp.id << ","
             << emp.name << ","
             << emp.salary << ","
             << (emp.fired ? 1 : 0) << std::endl;
    }

    file.close();
}

void showEmployees(const std::vector<Employee>& employees) {
    std::cout << "ID | Name | Salary" << std::endl;
    std::cout << "--------------------" << std::endl;
    for (const auto& emp : employees) {
        if (!emp.fired) {
            std::cout << emp.id << " | " << emp.name << " | " << emp.salary << std::endl;
        }
    }
}

int getNextId(const std::vector<Employee>& employees) {
    int maxId = 0;
    for (const auto& emp : employees) {
        if (emp.id > maxId) {
            maxId = emp.id;
        }
    }
    return maxId + 1;
}

int findEmployeeById(const std::vector<Employee>& employees, int id) {
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}
