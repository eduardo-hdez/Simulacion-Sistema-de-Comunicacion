// =======================================================
// File: customer.h
// Author: Eduardo Hernández Alonso - A01707225
// Date: 14/06/2024
// Description: Este archivo contiene la definición e
// implementación de la clase Customer, que representa a
// un cliente en el sistema de comunicación celular.
// Incluye métodos para gestionar las interacciones del
// cliente como hablar, enviar mensajes, conectarse a
// Internet y pagar su factura.
// =======================================================
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <sstream>
#include <iomanip>
#include "bill.h"
#include "operator.h"

class Customer {
private:
    int id, age, totalSpentTalkingTime, totalMessageSent;
    double totalInternetUsage;
    std::string name;
    Operator* op;
    Bill* bill;

public:
    Customer(int, std::string, int, Operator*, double);
    Customer(const Customer&);
    ~Customer();

    int getId() const;
    int getAge() const;
    int getTotalSpentTalkingTime() const;
    int getTotalMessageSent() const;
    double getTotalInternetUsage() const;
    std::string getName() const;
    Operator* getOperator() const;
    Bill* getBill() const;

    void setOperator(Operator*);

    std::string toString() const;

    void talk(int, Customer&);
    void message(int, const Customer&);
    void connection(double);
    void pay(double);
};

Customer::Customer(int id, std::string name, int age, Operator* op, double limit)
    : id(id), name(name), age(age), op(op), totalSpentTalkingTime(0), totalMessageSent(0), totalInternetUsage(0.0) {
    bill = new Bill(limit);
}

Customer::Customer(const Customer& other)
    : id(other.id), name(other.name), age(other.age), totalSpentTalkingTime(other.totalSpentTalkingTime),
      totalMessageSent(other.totalMessageSent), totalInternetUsage(other.totalInternetUsage), op(other.op), bill(new Bill(*other.bill)) {}

Customer::~Customer() {
    delete bill;
}

int Customer::getId() const {
    return id;
}

int Customer::getAge() const {
    return age;
}

int Customer::getTotalSpentTalkingTime() const {
    return totalSpentTalkingTime;
}

int Customer::getTotalMessageSent() const {
    return totalMessageSent;
}

double Customer::getTotalInternetUsage() const {
    return totalInternetUsage;
}

std::string Customer::getName() const {
    return name;
}

Operator* Customer::getOperator() const {
    return op;
}

Bill* Customer::getBill() const {
    return bill;
}

void Customer::setOperator(Operator* newOp) {
    op = newOp;
}

std::string Customer::toString() const {
    std::ostringstream oss;
    oss << "Customer " << id << ": " << std::fixed << std::setprecision(2) << bill->getTotalMoneySpent() << " " << bill->getCurrentDebt();
    return oss.str();
}

void Customer::talk(int minutes, Customer& other) {
    if (minutes > 0 && this != &other) {
        double cost = op->calculateTalkingCost(minutes, age);
        if (bill->check(cost)) {
            bill->add(cost);
            totalSpentTalkingTime += minutes;
            op->addTalkingTime(minutes);
            if (op != other.getOperator()) {
                other.getOperator()->addTalkingTime(minutes);
            }
        }
    }
}

void Customer::message(int quantity, const Customer& other) {
    if (quantity > 0 && this != &other) {
        double cost = op->calculateMessageCost(quantity, op->getId(), other.getOperator()->getId());
        if (bill->check(cost)) {
            bill->add(cost);
            totalMessageSent += quantity;
            op->addTotalMessageSent(quantity);
            if (op != other.getOperator()) {
                other.getOperator()->addTotalMessageSent(quantity);
            }
        }
    }
}

void Customer::connection(double amount) {
    if (amount > 0) {
        double cost = op->calculateNetworkCost(amount);
        if (bill->check(cost)) {
            bill->add(cost);
            totalInternetUsage += amount;
            op->addTotalInternetUsage(amount);
        }
    }
}

void Customer::pay(double amount) {
    if (amount > 0) {
        bill->pay(amount);
    }
}

#endif