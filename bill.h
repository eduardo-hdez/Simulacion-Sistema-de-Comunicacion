// =======================================================
// File: bill.h
// Author: Eduardo Hernández Alonso - A01707225
// Date: 14/06/2024
// Description: Este archivo contiene la definición e
// implementación de la clase Bill, que maneja la
// información de facturación de los clientes. Incluye
// métodos para agregar cargos, realizar pagos, cambiar los
// límites de crédito y verificar si los cargos se pueden
// agregar sin exceder el límite.
// =======================================================
#ifndef BILL_H
#define BILL_H

class Bill {
private:
    double limitAmount, currentDebt, totalMoneySpent;

public:
    Bill();
    Bill(double);
    Bill(const Bill&);

    double getLimitAmount() const;
    double getCurrentDebt() const;
    double getTotalMoneySpent() const;

    void add(double);
    void pay(double);
    void changeTheLimit(double);
    bool check(double) const;
};

Bill::Bill() : limitAmount(0), currentDebt(0), totalMoneySpent(0) {}

Bill::Bill(double limit) : limitAmount(limit), currentDebt(0), totalMoneySpent(0) {}

Bill::Bill(const Bill& other)
    : limitAmount(other.limitAmount), currentDebt(other.currentDebt), totalMoneySpent(other.totalMoneySpent) {}

double Bill::getLimitAmount() const {
    return limitAmount;
}

double Bill::getCurrentDebt() const {
    return currentDebt;
}

double Bill::getTotalMoneySpent() const {
    return totalMoneySpent;
}

void Bill::add(double amount) {
    if (amount > 0) {
        currentDebt += amount;
    }
}

void Bill::pay(double amount) {
    if (amount > 0 && amount <= currentDebt) {
        currentDebt -= amount;
        totalMoneySpent += amount;
    }
}

void Bill::changeTheLimit(double amount) {
    if (amount > 0 && amount >= currentDebt) {
        limitAmount = amount;
    }
}

bool Bill::check(double amount) const {
    return (currentDebt + amount) <= limitAmount;
}

#endif