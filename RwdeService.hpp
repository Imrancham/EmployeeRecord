//
//  RwdeService.hpp
//  EmployeeRecord
//
//  Created by imran Chamieh on 11.07.20.
//  Copyright © 2020 imran Chamieh. All rights reserved.
//

#ifndef RwdeService_hpp
#define RwdeService_hpp

#include <stdio.h>
#include "Employee.hpp"
#include <string>
#include <vector>

#endif /* RwdeService_hpp */

class RwdeService
{
    const std::string emp_name = "/Users/imranchamieh/Documents/DevProject /EmployeeRecord/EmployeeRecord/EmployeeName.txt";
    
public:
    
    int getNrEmployee();
    void AddEmployee(const Employee& emp);
    Employee GetEmployee(int id);
    void UpdateEmployee(const Employee& emp) const;
    void DeleteEmployee(int id);
    std::vector<Employee> GetAllEmployees();
};
