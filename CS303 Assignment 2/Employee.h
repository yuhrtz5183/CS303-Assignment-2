#pragma once
#include <iostream>
using namespace std;

class Employee {
protected:
	double hourlyRate;
	int hoursWorked;

public:
	Employee(double rate, int hours);
	virtual double WeeklySalary() const = 0;
	virtual double HealthContribution() const = 0;
	virtual int VacationDays() const = 0;
};

class Professional : public Employee {
private:
	int vacationDays;

public:
	Professional(double rate, int hours, int days);
	double WeeklySalary() const override;
	double HealthContribution() const override;
	int VacationDays() const override;
};

class Nonprofessional : public Employee {
private:
	double vacationHours;

public:
	Nonprofessional(double rate, int hours, double vacHours);
	double WeeklySalary() const override;
	double HealthContribution() const override;
	int VacationDays() const override;
};


