//main.cpp
#include "Queue.h"
#include "Customer.h"
#include <fstream>
#include <istream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  //find number of customers
  ifstream custData(argv[1], ifstream::in);
  char m;
  int numCustomers = 0;
  while (custData >> m) { 
    string s;
    getline(custData, s);
    numCustomers++;
  }
  Queue que(numCustomers);
  custData.close();

  //extracting data from given file
  ifstream data(argv[1], ifstream::in);
  char n;
  while (data >> n) { //fill customers array
    data.unget();
    string arrival;
    string service;
    getline(data, arrival, ' ');
    getline(data, arrival, ' ');
    getline(data, arrival, ' ');
    getline(data, service, ' ');
    getline(data, service, '\n');
    int arr = stoi(arrival);
    int ser = stoi(service);
    Customer customer;
    customer.arrival = arr;
    customer.service = ser;
    que.enqueue(customer);
  }

  //calculating and printing wait/leave time
  int leave = 0;
  int wait = 0;
  int totalWait = 0;
  int i = 1;
  while (!que.isEmpty()) { 
    Customer customer;
    que.dequeue(customer);
    cout << "Customer" << i << " wait: ";
    wait = leave - customer.arrival;
    if (wait < 0) {
      wait = 0;
    }
    totalWait += wait;
    cout << wait << ", leave time: ";
    leave = wait + customer.arrival + customer.service;
    cout << leave << endl;
    i++;
  }
  
  //calculating average wait time
  double avg = totalWait / (double) numCustomers;
  cout << "Average waiting time = " << avg << endl;
  

} //main
