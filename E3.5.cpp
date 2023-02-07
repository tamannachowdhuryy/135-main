/*                                                                                                                                                                           
Author: Tamanna Chowdhury                                                                                                                                                    
Course: CSCI-135                                                                                                                                                             
Instructor: Genady Maryash                                                                                                                                                   
Assignment: Homework E3.5                                                                                                                                                    
                                                                                                                                                                             
Write a program that reads three numbers and prints “increasing” if they are increasing order, “decreasing” if they are in decreasing order, and “neither”                   
otherwise. Here, “increasing” means “strictly increasing”, with each value                                                                                                   
larger than its predecessor. The sequence 3 4 4 would not be considered                                                                                                      
increasing.                                                                                                                                                                  
*/



#include <iostream>
using namespace std;
int main() {
  // these will show the three numbers                                                                                                                                       
  int num1, num2, num3;
  // user will input first number                                                                                                                                            
  cout << "Enter first number: ";
  cin >> num1;
  // user will input second number                                                                                                                                           
  cout << "Enter second number: ";
  cin >> num2;
  // user will input third number                                                                                                                                            
  cout << "Enter third number: ";
  cin >> num3;
  // used a if... else if and else statement to help figure out if the three                                                                                                 
  // numbers are increasing, decreasing or neither                                                                                                                           
  if (num1 < num2 && num2 < num3) {
    cout << "increasing" << endl;
  } else if (num1 > num2 && num2 > num3) {
    cout << "decreasing" << endl;
  } else {
    cout << "neither" << endl;
  }

  return 0;

