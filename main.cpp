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
#include <boost/asio.hpp>
//#include <boost/date_time.hpp>

//#include <boost/regex.hpp>

using namespace std;
const string emp_name = "/Users/imranchamieh/Documents/DevProject /EmployeeRecord/EmployeeRecord/EmployeeName.txt";
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// get number of employees
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

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Add an employee
void AddEmployee(string name, string date, int salary){
    
    num_emp++;
    ofstream NameEmployee(emp_name,ios::app);
    NameEmployee<<num_emp<<"\t"<< name <<"\t"<<date<<"\t"<<salary <<endl;
    NameEmployee.close();
}
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Show all employees

void getAllEmployee(){

    ifstream NameEmployee(emp_name);
      std::string line;
       while (getline(NameEmployee,  line)) {
           cout<<line<<endl;
       }
       NameEmployee.close();
};


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Edit an employee
void EditName(int id_nr, string NewName)// edite name by given nr
{

  ifstream infile;
  infile.open(emp_name,ios::in);

  if(infile){

    ofstream outfile;

    outfile.open("tempfile.txt");

    int id, salary;
    string name, birth;

    while(infile>>id >> name >>birth >>salary){

       if(id==id_nr) {
           outfile<<id<<"\t"<< NewName <<"\t"<<birth<<"\t"<<salary <<endl;
       }
        else
            outfile<<id<<"\t"<< name <<"\t"<<birth<<"\t"<<salary <<endl;

    }

    outfile.close();

  }

  infile.close();
    
    const char * p = emp_name.c_str();

    remove(p);
    rename("tempfile.txt",p);

}

int countLine(char* sourcefile){

  ifstream infile;

  infile.open(sourcefile,ios::in);

  char data[100];

  int line=0;

  while(infile.getline(data,100)) line++;

  return line;

}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void EditSalary(int id_nr, int NewSalary)  // edite salary by given number
{

  ifstream infile;
  infile.open(emp_name,ios::in);

  if(infile){

    ofstream outfile;

    outfile.open("tempfile.txt");

    int id, salary;
    string name, birth;

    while(infile>>id >> name >>birth >>salary){

       if(id==id_nr) {
           outfile<<id<<"\t"<< name <<"\t"<<birth<<"\t"<<NewSalary <<endl;
       }
        else
            outfile<<id<<"\t"<< name <<"\t"<<birth<<"\t"<<salary <<endl;

    }

    outfile.close();

  }

  infile.close();
    
    const char * p = emp_name.c_str();

    remove(p);
    rename("tempfile.txt",p);

}


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void EditEmployee(int nr, string NewBirth); // edit date by given number




// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void removeEmployee(int id_nr){

   ifstream infile;
   infile.open(emp_name,ios::in);

   if(infile){

     ofstream outfile;

     outfile.open("tempfile.txt");

     int id, salary;
     string name, birth;

     while(infile>>id >> name >>birth >>salary){

        if(id==id_nr) continue;

        outfile<<id<<"\t"<< name <<"\t"<<birth<<"\t"<<salary <<endl;

     }

     outfile.close();

   }

   infile.close();
     
     const char * p = emp_name.c_str();

     remove(p);
     rename("tempfile.txt",p);

 }



// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]) {
    
   
    string name = "Muster";
    string birth = "02.02.2020";
    int salary = 99999;
    
    
//    add an employee
    AddEmployee(name, birth, salary);
    
//    Print all empoloyees data
    getAllEmployee();
    
// Print number of employees
    cout<<"number of employee is: "<<getNrEmployee()<<endl;
    
//    remove employss number 2
    
    removeEmployee(2);
//    Edit employee name
    
    EditName(1, "mohammad");
//    Edit employee salary
    
    EditSalary(3, 000);
//    Print all employees data
    
    getAllEmployee();
//    Print number of employees
       cout<<"number of employee is: "<<getNrEmployee()<<endl;
    

    return 0;
}


    

    
    
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

