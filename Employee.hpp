//
//  Employee.hpp
//  EmployeeRecord
//
//  Created by imran Chamieh on 11.07.20.
//  Copyright © 2020 imran Chamieh. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp
#pragma once

#include <stdio.h>
#include <string>


#endif /* Employee_hpp */

class Employee
{
    int m_id;
    std::string m_name;
    double m_salary;
    std::string m_birth;
    
public:
    Employee(int id, std::string name, std::string birth, double salary): m_id(id), m_name(name), m_birth(birth), m_salary(salary) {}
    int GetID() const {return m_id;}
    std::string GetName() const {return m_name;}
    double GetSalary() const {return m_salary;}
    std::string GetBirth() const {return m_birth;}
};
