//
//  main.cpp
//  EmployeeRecord
//
//  Created by imran Chamieh on 06.07.20.
//  Copyright © 2020 imran Chamieh. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>
#include "Employee.hpp"
#include "RwdeService.hpp"
//#include <boost/asio.hpp>
//#include <boost/date_time.hpp>
//#include <boost/regex.hpp>

using namespace std;



int main(int argc, const char * argv[]) {


    RwdeService service;
    cout<< "Number of employees: "<<service.getNrEmployee()<<endl;
    
    int id =1;
    id  = service.getNrEmployee() + 1;
    string name = "Mann";
    string birth = "02.02.2020";
    double salary = 99999;
    
    int input =1;
    while (input ) {
        cout<<"Choose an operation: \n 1: Add employee \n 2: remove an employee \n 3: Update employee information \n 4: Get an employee \n 5: Get the number of employees \n 0: to leave"<<endl;
        cin>>input;
        switch (input) {
            case 1:{
                cout<<"Enter Employee's Name: ";
                cin>>name;
                cout<<"\n Enter Employee's date of birth :";
                cin>>birth;
                cout<<"\n Enter Employee's salary: ";
                cin>>salary;
                Employee new_emp(id,name,birth,salary);
                service.AddEmployee(new_emp);
                cout<<"'n Employee was successfuly added"<<endl;
                break;
            }
                
            case 2:{
                cout<<"Enter Employee's ID number: ";
                cin>>id;
                service.DeleteEmployee(id);
                cout<<"\n Employee was successfuly Deleted"<<endl;
                break;
            }
            
            case 3:
            {
                cout<<"Enter employee's ID and new data: name, salary and date of birth \n";
                cout<<"Enter employee's id:";
                cin>>id;
                cout<<"enter employee's name: ";
                cin>>name;
                cout<<"enter employee's slary: ";
                cin>>salary;
                cout<<"enter employee's date of birth: ";
                cin>>birth;
                
                Employee update_emp(id,name,birth,salary);
                service.UpdateEmployee(update_emp);
                break;
            }
            
                
            case 4:
            {
                cout<<"Enter employee's id: ";
                cin>>id;
                service.GetEmployee(id);
                break;
            }
            case 5:
            {
                
                cout<<"There are "<<service.getNrEmployee() <<" employee. ";

                break;
            }
            
                
            case 0:
                input =0;
            break;
                
            default:
                cout<<"Choose a valid  action 1, 2, 3, 4 or 0";
                break;
        }
    }
    
//    // Employee object
//    Employee emp(id, name, birth, salary);
//    // add ana employee to the record
//    service.AddEmployee(emp);
//    // save all emplyee to a vector.
//    auto employees_vec = service.GetAllEmployees();
//
//    // delet emplyee nr:
//    int nr = 1;
//    service.DeleteEmployee(nr);
//    cout<< "Number of employees: "<<service.getNrEmployee()<<endl;
//
//    nr = 10;
//    cout<<"Emp nr "<<nr<< ": "<<employees_vec[nr].GetID()<<endl;
//    cout<<"Emp name " << nr <<": "<<employees_vec[nr].GetName()<<endl;
//
//    nr = 2;
//    emp = service.GetEmployee(nr);
//    cout<<"Name: "<<emp.GetName()<< ",  Salary: "<<emp.GetSalary()<<",  birth: "<<emp.GetBirth()<<endl;
//    cout<< "Number of employees: "<<service.getNrEmployee()<<endl;

    return 0;
}


