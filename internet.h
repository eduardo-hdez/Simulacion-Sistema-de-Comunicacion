// =======================================================
// File: internet.h
// Author: Eduardo Hernández Alonso - A01707225
// Date: 14/06/2024
// Description: Este archivo contiene la definición e
// implementación de la clase Internet, que es una clase
// derivada de Operator. Esta clase se especializa en
// calcular los costos de uso de Internet para clientes que
// utilizan más intensamente los servicios de datos.
// Incluye métodos para calcular costos de llamadas,
// mensajes y uso de red, aplicando descuentos según las
// reglas definidas.
// =======================================================
#ifndef INTERNETOPERATOR_H
#define INTERNETOPERATOR_H

#include "operator.h"

class InternetOperator : public Operator {
private:
    const double LIMITGB = 1.0;

public:
    InternetOperator(int, double, double, double, int, OperatorType);
    InternetOperator(const InternetOperator&);

    double calculateTalkingCost(int, int);
    double calculateMessageCost(int, int, int);
    double calculateNetworkCost(double);
};

InternetOperator::InternetOperator(int id, double talkingCharge, double messageCost, double networkCharge, int discountRate, OperatorType type)
    : Operator(id, talkingCharge, messageCost, networkCharge, discountRate, type) {}

InternetOperator::InternetOperator(const InternetOperator& other) : Operator(other) {}

double InternetOperator::calculateTalkingCost(int minutes, int age) {
    if (minutes <= 0 || age <= 0) return 0.0;
    double cost = minutes * talkingCharge;
    if (minutes < 2) {
        cost *= (1 - discountRate / 100.0);
    }
    return cost;
}

double InternetOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId) {
    if (quantity <= 0) return 0.0;
    double cost = quantity * messageCost;
    if (quantity < 3) {
        cost *= (1 - discountRate / 100.0);
    }
    return cost;
}

double InternetOperator::calculateNetworkCost(double amount) {
    if (amount <= 0) return 0.0;
    if (amount <= LIMITGB) {
        return 0.0;
    }
    return (amount - LIMITGB) * networkCharge;
}

#endif