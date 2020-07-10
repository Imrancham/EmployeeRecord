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
#include <stdio.h>

//#include <boost/regex.hpp>
using namespace std;
const string emp_name = "/Users/imranchamieh/Documents/DevProject /EmployeeRecord/EmployeeRecord/EmployeeName.txt";

// get the number of employee
int getNrEmployee(){
    
    ifstream NameEmployee(emp_name);
    int Nr_emp=0;
          
    string line;
           while (getline(NameEmployee,line ) ){
               Nr_emp++;
           }
    
           NameEmployee.close();
    return Nr_emp;
    }


int num_emp = getNrEmployee(); // initial number of employees


// Add an employee
void AddEmployee(string name, string date, int salary){
    
    num_emp++;
    ofstream NameEmployee(emp_name,ios::app);
    NameEmployee<<num_emp<<"\t"<< name <<"\t"<<date<<"\t"<<salary <<endl;
    NameEmployee.close();
}

// Show all employees

void getAllEmployee(){

    ifstream NameEmployee(emp_name);
      std::string line;
       while (getline(NameEmployee,  line)) {
           cout<<line<<endl;
       }
       NameEmployee.close();
};



// Get employee info
void getEmployee(int id_nr)
{

    ifstream NameEmployee(emp_name);
      int id, salary;
      string name, birth;
    
       while (NameEmployee >> id >>name >> birth>> salary) {
           if (id == id_nr) {
               
               cout<< id <<"\t"<<name<<"\t"<< birth<<"\t"<< salary <<endl;
           }
           
       }
       NameEmployee.close();
};



// Edit an employee
void EditEmployee(int nr, string name); // edite name by given nr
void EditEmployee(int nr, int salary);  // edite salary by given number
void EditEmployee(int nr, string date); // edit date by given number
void EditEmployee(string name, int salary); // edite salary by given name
void EditEmployee(string name, string date); // edite date by given number




// void removeLine(string emp_name,int id_nr){

//   ifstream infile;

//   auto tempPath="/Users/imranchamieh/Documents/DevProject /EmployeeRecord/EmployeeRecord/tempfile.txt";

//   infile.open(emp_name,ios::in);

//   if(infile){

//     ofstream outfile;

//     outfile.open(tempPath,ios::out);

//     int id, salary;
//     string name, birth;

//     while(infile>>id >> name >>birth >>salary){

//        if(id==id_nr) continue;

//        outfile<<id<<"\t"<< name <<"\t"<<birth<<"\t"<<salary <<endl;

//     }

//     outfile.close();

//   }

//   infile.close();

//  remove(emp_name);

//  rename(tempPath,emp_name);

// }

// int countLine(char* sourcefile){

//   ifstream infile;

//   infile.open(sourcefile,ios::in);

//   char data[100];

//   int line=0;

//   while(infile.getline(data,100)) line++;

//   return line;

// }




int main(int argc, const char * argv[]) {
    
//        AddEmployee("imran", "21.03.2020", 2000);
//        AddEmployee("ahmad", "00.00.2020", 4567);
//         AddEmployee("samer", "00.00.2020", 6543);
//         AddEmployee("johan", "00.00.2030", 98776);
//    getEmployee(1);
    getAllEmployee();
 
    cout<<"number of employee is: "<<getNrEmployee()<<endl;

    return 0;
}


    
//    ofstream BirthEmployee(emp_birth,ios::app);
//    BirthEmployee<<num_emp<<"\t"<< date <<endl;
//    BirthEmployee.close();
//
//    ofstream SalaryEmployee(emp_salary);
//    SalaryEmployee<<num_emp<<"\t"<< salary <<endl;
//    SalaryEmployee.close();
    


//    int num_emp = getNrEmployee();
    // Creat data files
//    ifstream NameEmployee(emp_name, ios_base::openmode mode);
//    NameEmployee.close();
//
//    ofstream BirthEmployee(emp_birth);
//    BirthEmployee.close();
//
//    ofstream SalaryEmployee(emp_salary);
//    SalaryEmployee.close();
    
    
//    AddEmployee("imran", "21.03.2020", 2000);
//    AddEmployee("ahmad", "00.00.2020", 4567);
//     AddEmployee("samer", "00.00.2020", 6543);
//     AddEmployee("johan", "00.00.2030", 98776);
//
//    getAllEmployee();
//        ifstream NameEmployee(emp_name);
//        string  name, birth;
//        int id, salary;
//        while (NameEmployee >> id >>name >> birth >> salary) {
//            cout<< salary <<endl;
//        }
//        NameEmployee.close();

//

