//
//  RwdeService.cpp
//  EmployeeRecord
//
//  Created by imran Chamieh on 11.07.20.
//  Copyright © 2020 imran Chamieh. All rights reserved.
//

#include "RwdeService.hpp"
#include <fstream>

void RwdeService::UpdateEmployee(const Employee &emp) const
{
    std::ifstream infile;
    infile.open(emp_name,std::ios::in);

    if(infile){

        std::ofstream outfile;

      outfile.open("tempfile.txt");

      int id, salary;
      std::string name, birth;

      while(infile>> id >> name >>birth >>salary){

         if(id== emp.GetID()) {
             outfile<<id<<"\t"<< emp.GetName() <<"\t"<<emp.GetBirth()<<"\t"<<emp.GetSalary() <<std::endl;
         }
          else
              outfile<<id<<"\t"<< name <<"\t"<<birth<<"\t"<<salary <<std::endl;

      }

      outfile.close();

    }

    infile.close();
      
      const char * p = emp_name.c_str();

      remove(p);
      rename("tempfile.txt",p);

}
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int RwdeService::getNrEmployee()
{
    
    
    std::ifstream NameEmployee(emp_name);
    int Nr_emp=0;
          
    std::string line;
           while (getline(NameEmployee,line ) ){
               Nr_emp++;
           }
    
           NameEmployee.close();
    return Nr_emp ;
    
}
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RwdeService::AddEmployee(const Employee &emp){
    // give the employee new number at the record
    auto employees = GetAllEmployees();
    int const  num_emp = employees.end()->GetID() + 1;
    
    // register the employee at the record.
    std::ofstream NameEmployee(emp_name,std::ios::app);
    NameEmployee<<num_emp<<"\t"<< emp.GetName() <<"\t"<<emp.GetName()<<"\t"<<emp.GetSalary() <<std::endl;
    NameEmployee.close();
}

void RwdeService::DeleteEmployee(int emp_id){
    std::ifstream infile;
    infile.open(emp_name,std::ios::in);

      if(infile){

          std::ofstream outfile;

        outfile.open("tempfile.txt");

        int id, salary;
          std::string name, birth;

        while(infile>>id >> name >>birth >>salary){

           if(id == emp_id) continue;

            outfile<<id<<"\t"<< name <<"\t"<<birth<<"\t"<<salary <<std::endl;

        }

        outfile.close();

      }

      infile.close();
        
        const char * p = emp_name.c_str();

        remove(p);
        rename("tempfile.txt",p);
}
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<Employee> RwdeService::GetAllEmployees()
{
    std::vector<Employee> emp;
    
    std::ifstream femp(emp_name);
    
    while (femp) {
        int id, salary;
        std::string name, birth;
        femp>>id >>name >> birth >>salary;
        Employee mustr(id, name, birth, salary);
        emp.push_back(mustr);
        
    }
    femp.close();
    emp.erase(emp.end() - 1);

    return emp;
}
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Employee RwdeService::GetEmployee(int id){
    
    std::ifstream femp(emp_name);
    
    while (femp) {
        int em_id, salary;
        std::string name, birth;
        femp>>em_id >>name >> birth >>salary;
        if (em_id == id) {
            Employee mustr(id, name, birth, salary) ;
            return mustr;
        }
        
    }
    femp.close();
    Employee mustr(0 , "NN", "birth", 0) ;
    return mustr;
}
