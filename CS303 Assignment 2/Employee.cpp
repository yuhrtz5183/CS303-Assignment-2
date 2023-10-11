#include "Employee.h"

// Employee implementation
Employee::Employee(double rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}

// Professional implementation
Professional::Professional(double rate, int hours, int days) :Employee(rate, hours), vacationDays(days) {}

double Professional::WeeklySalary() const {
	return hourlyRate * hoursWorked;
}

double Professional::HealthContribution() const {
	return 100.0;  // Contribution amount for professionals
}

int Professional::VacationDays() const {
	return vacationDays;
}

// Nonprofessional implementation
Nonprofessional::Nonprofessional(double rate, int hours, double vacHours) :Employee(rate, hours), vacationHours(vacHours) {}

double Nonprofessional::WeeklySalary() const {
	return hourlyRate * hoursWorked;
}

double Nonprofessional::HealthContribution() const {
	return 50.0;  // Contribution amount for nonprofessionals
}

int Nonprofessional::VacationDays() const {
	return static_cast<int>(vacationHours / 8);  // 8 hours for a vacation day
}
