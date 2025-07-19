// =======================================================
// File: operator.h
// Author: Eduardo Hernández Alonso - A01707225
// Date: 14/06/2024
// Description: Este archivo contiene la definición e
// implementación de la clase Operator, que representa un
// operador en el sistema de comunicación celular.
// Incluye métodos para gestionar
// el tiempo de llamadas, el envío de mensajes y el uso
// de Internet. Además, define métodos virtuales puros
// para calcular los costos asociados a estas
// actividades, que deben ser implementados por
// las clases derivadas.
// =======================================================
#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <sstream>
#include <iomanip>

typedef enum {VOX, INTERNET} OperatorType;

class Operator {
protected:
    int id, discountRate;
    double talkingCharge, messageCost, networkCharge, totalInternetUsage;
    int totalSpentTalkingTime, totalMessageSent;
    OperatorType type;

public:
    Operator(int, double, double, double, int, OperatorType);
    Operator(const Operator&);

    int getId() const;
    int getDiscountRate() const;
    double getTalkingCharge() const;
    double getMessageCost() const;
    double getNetworkCharge() const;
    int getTotalSpentTalkingTime() const;
    int getTotalMessageSent() const;
    double getTotalInternetUsage() const;
    OperatorType getType() const;

    void addTalkingTime(int);
    void addTotalMessageSent(int);
    void addTotalInternetUsage(double);

    std::string toString() const;

    virtual double calculateTalkingCost(int, int) = 0;
    virtual double calculateMessageCost(int, int, int) = 0;
    virtual double calculateNetworkCost(double) = 0;
};

Operator::Operator(int id, double talkingCharge, double messageCost, double networkCharge, int discountRate, OperatorType type)
    : id(id), talkingCharge(talkingCharge), messageCost(messageCost), networkCharge(networkCharge),
      discountRate(discountRate), totalSpentTalkingTime(0), totalMessageSent(0), totalInternetUsage(0.0), type(type) {}

Operator::Operator(const Operator& other)
    : id(other.id), talkingCharge(other.talkingCharge), messageCost(other.messageCost), networkCharge(other.networkCharge),
      discountRate(other.discountRate), totalSpentTalkingTime(other.totalSpentTalkingTime), totalMessageSent(other.totalMessageSent),
      totalInternetUsage(other.totalInternetUsage), type(other.type) {}

int Operator::getId() const {
    return id;
}

int Operator::getDiscountRate() const {
    return discountRate;
}

double Operator::getTalkingCharge() const {
    return talkingCharge;
}

double Operator::getMessageCost() const {
    return messageCost;
}

double Operator::getNetworkCharge() const {
    return networkCharge;
}

int Operator::getTotalSpentTalkingTime() const {
    return totalSpentTalkingTime;
}

int Operator::getTotalMessageSent() const {
    return totalMessageSent;
}

double Operator::getTotalInternetUsage() const {
    return totalInternetUsage;
}

OperatorType Operator::getType() const {
    return type;
}

void Operator::addTalkingTime(int minutes) {
    if (minutes > 0) {
        totalSpentTalkingTime += minutes;
    }
}

void Operator::addTotalMessageSent(int quantity) {
    if (quantity > 0) {
        totalMessageSent += quantity;
    }
}

void Operator::addTotalInternetUsage(double amount) {
    if (amount > 0) {
        totalInternetUsage += amount;
    }
}

std::string Operator::toString() const {
    std::ostringstream oss;
    oss << "Operator " << id << ": " << totalSpentTalkingTime << " " << totalMessageSent << " " << std::fixed << std::setprecision(2) << totalInternetUsage;
    return oss.str();
}

#endif