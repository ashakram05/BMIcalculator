#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Function for input validation
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) { // Check for valid input and positive value
            cout << "Invalid input! Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return value;
        }
    }
}

// Function to calculate BMI
double calculateBMI(double height, double weight, int choice) {
    if (choice == 1) { // Height in inches and weight in pounds
        return (weight * 703) / (height * height);
    } else if (choice == 2) { // Height in meters and weight in kilograms
        return weight / (height * height);
    } else if (choice == 3) { // Height in feet and inches and weight in pounds
        return (weight * 703) / (height * height);
    }
    return 0;
}

// Function to display BMI classification
void displayResult(double bmi) {
    cout << fixed << setprecision(2);
    cout << "The BMI is: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        cout << "Normal" << endl;
    } else if (bmi >= 25 && bmi <= 29.9) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obese" << endl;
    }
}

int main() {
    char continueChoice; // Variable to allow re-runs

    cout << "********************************************" << endl;
    cout << "***                                      ***" << endl;
    cout << "***            BMI CALCULATOR            ***" << endl;
    cout << "***                                      ***" << endl;
    cout << "***                                      ***" << endl;
    cout << "********************************************" << endl;

    do {
        // Display choices
        cout << "\nChoose an option:\n";
        cout << "1. Height in Inches and Weight in Pounds\n";
        cout << "2. Height in Meters and Weight in Kilograms\n";
        cout << "3. Height in Feet & Inches, and Weight in Pounds\n";
        cout << "Enter your choice (1-3): ";

        int choice;
        while (!(cin >> choice) || choice < 1 || choice > 3) { // Validate choice input
            cout << "Invalid choice! Please enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Variable declarations
        double height, weight, feet, inches, bmi;

        if (choice == 1) {
            height = getValidInput("Enter height in inches: ");
            weight = getValidInput("Enter weight in pounds: ");
            bmi = calculateBMI(height, weight, choice);
        } else if (choice == 2) {
            height = getValidInput("Enter height in meters: ");
            weight = getValidInput("Enter weight in kilograms: ");
            bmi = calculateBMI(height, weight, choice);
        } else if (choice == 3) {
            feet = getValidInput("Enter height in feet: ");
            inches = getValidInput("Enter remaining height in inches: ");
            height = (feet * 12) + inches; // Convert to inches
            weight = getValidInput("Enter weight in pounds: ");
            bmi = calculateBMI(height, weight, choice);
        }

        // Display BMI result
        displayResult(bmi);

        // Ask if the user wants to continue
        cout << "Do you want to calculate BMI again? (Y/N): ";
        cin >> continueChoice;

    } while (continueChoice == 'Y' || continueChoice == 'y');

    cout << "Thank you for using the BMI calculator! Goodbye.\n";

    return 0;
}
