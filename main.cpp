// =======================================================
// File: main.cpp
// Author: Eduardo Hernández Alonso - A01707225
// Date: 14/06/2024
// Description: Este archivo contiene el programa 
// principal que simula un sistema de comunicación
// celular. Lee las operaciones de un archivo de entrada, // ejecuta las acciones correspondientes (crear clientes
// y operadores, realizar llamadas, enviar mensajes,
// conectarse a Internet, pagar facturas, cambiar de
// operador, y cambiar el límite de crédito) y escribe
// los resultados en un archivo de salida.
// To compile: g++ -std=c++11 main.cpp -o app
// To execute: ./app input_file output_file
// =======================================================
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bill.h"
#include "operator.h"
#include "vox.h"
#include "internet.h"
#include "customer.h"

using namespace std;

int main(int argc, char* argv[]) {
  ifstream inputFile;
  ofstream outputFile;

  vector <Operator*> operators;
  vector <Customer*> customers;


  if (argc != 3) {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
  }

  inputFile.open(argv[1]);
  if (!inputFile.is_open()) {
    cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
  }

  outputFile.open(argv[2]);
  if (!outputFile.is_open()){
    cout << "File not found"<< endl;
    return -1;
  }

  int C, O, N, type, customerCount = 0, operatorCount = 0;
  
  inputFile >> C >> O >> N;

  cout << "headers " << C << " " << O << " " << N << endl;

  customers.resize(C);
  operators.resize(O);
  
  for (int i = 0; i < N; i++) {
    inputFile >> type;
    cout << "type " << type << endl;
    switch (type) {
      case 1: {
        string name;
        int age, operatorId;
        double limCredit;
        inputFile >> name >> age >> operatorId >> limCredit;
        customers[customerCount] = new Customer(customerCount, name, age, operators[operatorId], limCredit);
        customerCount++;
      }
        break;

      case 2: {
        int type, discount;
        double talkCharge, messageCost, internetCharge;
        inputFile >> type >> talkCharge >> messageCost >> internetCharge >> discount;
        if (type == 1) {
          operators[operatorCount] = new VoxOperator(operatorCount, talkCharge, messageCost, internetCharge, discount, VOX);
        } 
        else if (type == 2) {
          operators[operatorCount] = new InternetOperator(operatorCount, talkCharge, messageCost, internetCharge, discount, INTERNET);
        }
        operatorCount++;
      }
        break;
      case 3: {
        int id1, id2, timeTalking;
        inputFile >> id1 >> id2 >> timeTalking;
        customers[id1]->talk(timeTalking, *customers[id2]);
      }
        break;
      case 4: {
        int id1, id2, messagesSent;
        inputFile >> id1 >> id2 >> messagesSent;
        customers[id1]->message(messagesSent, *customers[id2]);
      }
        break;
      case 5: {
        int id;
        double internetUsed;
        inputFile >> id >> internetUsed;
        customers[id]->connection(internetUsed);
      }
        break;
      case 6: {
        int id;
        double toPay;
        inputFile >> id >> toPay;
        customers[id]->pay(toPay);
      }
        break;
      case 7: {
        int clientId, newOperator;
        inputFile>>clientId>>newOperator;
        customers[clientId]->setOperator(operators[newOperator]);
      }
        break;
      case 8: {
        int id;
        double newCreditLimit;
        inputFile>>id>>newCreditLimit;
        customers[id]->getBill()->changeTheLimit(newCreditLimit);
      }
        break;
      default: {
        cout << "No action type for number." << endl;
      }
        break;
    }
  }

  cout << operators.size() << endl;
  cout << customers.size() << endl;

  for (Operator* op : operators){
    string info = op->toString();
    outputFile << info << endl;
  }

  for (Customer* cus : customers) {
    string info = cus->toString();
    outputFile << info << endl;
  }

  int maxTalk = -1, idTalk = -1;
  for (Customer* cus : customers) {
    if (cus->getTotalSpentTalkingTime() > maxTalk) {
      maxTalk = cus->getTotalSpentTalkingTime();
      idTalk = cus->getId();
    } 
    else if (cus->getTotalSpentTalkingTime() == maxTalk) {
      if (cus->getId() > idTalk) {
        idTalk = idTalk;
      }
    }
  }

  outputFile << customers[idTalk]->getName() << ": " << maxTalk << fixed << setprecision(2) << endl;

  int maxMessages = -1, idMess = -1;
  for (Customer* cus : customers) {
    if (cus->getTotalMessageSent() > maxMessages) {
      maxMessages = cus->getTotalMessageSent();
      idMess = cus->getId();
    } 
    else if (cus->getTotalMessageSent() == maxMessages) {
      if (cus->getId() > idMess) {
        idMess = idMess;
      }
    }
  }

  outputFile << customers[idMess]->getName() << ": " << maxMessages << fixed << setprecision(2) << endl;

  double maxInternet = -1;
  int idInt = -1;
  for (Customer* cus : customers){
    if (cus->getTotalInternetUsage() > maxInternet) {
      maxInternet = cus->getTotalInternetUsage();
      idInt = cus->getId();
    } 
    else if (cus->getTotalInternetUsage() == maxInternet) {
      if (cus->getId() > idInt) {
        idInt = idInt;
      }
    }
  }

  outputFile << customers[idInt]->getName() << ": " << maxInternet << fixed << setprecision(2) << endl;

  customers.clear();
  operators.clear();

  inputFile.close();
  outputFile.close();

  return 0;
}
