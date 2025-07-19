// =======================================================
// File: vox.h
// Author: Eduardo Hernández Alonso - A01707225
// Date: 14/06/2024
// Description: Este archivo contiene la definición e
// implementación de la clase Vox, que es una clase
// derivada de Operator. Esta clase se especializa en
// calcular los costos de llamadas y mensajes para clientes
// que utilizan más estos servicios. Incluye métodos para
// calcular costos de llamadas, mensajes y uso de red,
// aplicando descuentos según la edad del cliente y el
// operador receptor de los mensajes.
// =======================================================
#ifndef VOXOPERATOR_H
#define VOXOPERATOR_H

#include "operator.h"

class VoxOperator : public Operator {
public:
    VoxOperator(int, double, double, double, int, OperatorType);
    VoxOperator(const VoxOperator&);

    double calculateTalkingCost(int, int);
    double calculateMessageCost(int, int, int);
    double calculateNetworkCost(double);
};

VoxOperator::VoxOperator(int id, double talkingCharge, double messageCost, double networkCharge, int discountRate, OperatorType type)
    : Operator(id, talkingCharge, messageCost, networkCharge, discountRate, type) {}

VoxOperator::VoxOperator(const VoxOperator& other) : Operator(other) {}

double VoxOperator::calculateTalkingCost(int minutes, int age) {
    if (minutes <= 0 || age <= 0) return 0.0;
    double cost = minutes * talkingCharge;
    if (age < 18 || age > 65) {
        cost *= (1 - discountRate / 100.0);
    }
    return cost;
}

double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId) {
    if (quantity <= 0) return 0.0;
    double cost = quantity * messageCost;
    if (thisOpId == otherOpId) {
        cost *= (1 - discountRate / 100.0);
    }
    return cost;
}

double VoxOperator::calculateNetworkCost(double amount) {
    if (amount <= 0) return 0.0;
    return amount * networkCharge;
}

#endif