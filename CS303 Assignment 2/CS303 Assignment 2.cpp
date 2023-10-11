#include "LinkedList.h"
#include "Employee.h"
#include <string>

int main() {
	LinkedList<int> list;

	// Push elements
	list.push_back(10);
	list.push_front(5);
	list.push_back(20);
	list.push_front(2);

	// Print the first list
	cout << "List: ";
	list.displayList();

	// Print front and back elements
	cout << "Front: " << list.front() << endl;
	cout << "Back: " << list.back() << endl;

	// Insert at index 2
	list.insert(2, 15);

	// Print the list after insertion
	cout << "Aftering insering 15 at index 2: ";
	list.displayList();

	// Remove at index 3
	list.remove(3);

	// Print the list after removal
	cout << "After removing element at index 3: ";
	list.displayList();

	// Pop front and back
	list.pop_back();
	list.pop_front();

	// Print the list after popping
	cout << "After popping back and front: ";
	list.displayList();

	// Check if the list is empty
	cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << endl;

	Professional profEmployee(30.0, 40, 10);  // Professional employee with 30 hour rate, 40 hours worked, and 10 vacation days
	Nonprofessional nonProfEmployee(20.0, 35, 20.0);  // Nonprofessional employee with 20 hour rate, 35 hours worked, and 20 vacation hours

	cout << "\n\nProfessional Employee" << endl;
	cout << "Weekly Salary: $" << profEmployee.WeeklySalary() << endl;
	cout << "Healthcare Contributions: $" << profEmployee.HealthContribution() << endl;
	cout << "Vacation Days: " << profEmployee.VacationDays() << endl;
	cout << "\nNonprofessional Employee" << endl;
	cout << "Weekly Salary: $" << nonProfEmployee.WeeklySalary() << endl;
	cout << "Healthcare Contributions: $" << nonProfEmployee.HealthContribution() << endl;
	cout << "Vacation Days: " << nonProfEmployee.VacationDays() << endl;

	return 0;
}
