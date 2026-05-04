#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

// Class to hold User Personal Details
class User {
private:
  string name;
  int age;
  string id;
  bool registered;

public:
  User() : age(0), registered(false) {}

  // Phase 1: Asking and saving personal details
  void registerUser() {
    cout << "\n=== User Registration ===\n";
    cout << "Enter your Name: ";
    getline(
        cin >> ws,
        name); // read full line including spaces, consuming leading whitespace

    cout << "Enter your Age: ";
    while (!(cin >> age) || age <= 0) {
      cout << "Invalid input. Please enter a valid positive integer for age: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter your User ID: ";
    cin >> ws;
    getline(cin, id);

    registered = true;
    cout << "\nRegistration Successful! Welcome, " << name << ".\n";
  }

  // Displaying user profile
  void displayProfile() const {
    if (!registered) {
      cout << "No user registered.\n";
      return;
    }
    cout << "\n--- Personal Profile ---\n";
    cout << "Name: " << name << "\n";
    cout << "Age:  " << age << "\n";
    cout << "ID:   " << id << "\n";
    cout << "------------------------\n";
  }

  bool isRegistered() const { return registered; }
};

// Class to manage the Main Application and Records workflow
class Application {
private:
  User currentUser;

  // Using unordered_map for O(1) average time complexity for lookups,
  // insertions, and deletions Key: integer Record ID, Value: string Record Data
  unordered_map<int, string> records;

  void displayMenu() const {
    cout << "\n=== Main Menu ===\n";
    cout << "1. View Profile\n";
    cout << "2. Add a Record\n";
    cout << "3. Search for a Record\n";
    cout << "4. Delete a Record\n";
    cout << "5. Display All Records\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
  }

  void addRecord() {
    int recordId;
    string recordData;

    cout << "\nEnter Record ID (integer): ";
    while (!(cin >> recordId)) {
      cout << "Invalid input. Record ID must be an integer: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // O(1) lookup to check existence
    if (records.find(recordId) != records.end()) {
      cout << "Record with ID " << recordId << " already exists!\n";
      return;
    }

    cout << "Enter Record Details: ";
    getline(cin >> ws, recordData);

    // O(1) insertion
    records[recordId] = recordData;
    cout << "Record added successfully.\n";
  }

  void searchRecord() {
    int recordId;
    cout << "\nEnter Record ID to search: ";
    while (!(cin >> recordId)) {
      cout << "Invalid input. Record ID must be an integer: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // O(1) lookup
    auto it = records.find(recordId);
    if (it != records.end()) {
      cout << "Record Found -> ID: " << it->first
           << " | Details: " << it->second << "\n";
    } else {
      cout << "Record with ID " << recordId << " not found.\n";
    }
  }

  void deleteRecord() {
    int recordId;
    cout << "\nEnter Record ID to delete: ";
    while (!(cin >> recordId)) {
      cout << "Invalid input. Record ID must be an integer: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // O(1) deletion
    if (records.erase(recordId)) {
      cout << "Record deleted successfully.\n";
    } else {
      cout << "Record with ID " << recordId << " not found.\n";
    }
  }

  void displayAllRecords() const {
    if (records.empty()) {
      cout << "\nNo records available.\n";
      return;
    }

    // O(N) iteration, required for printing all elements
    cout << "\n--- All Records ---\n";
    for (const auto &pair : records) {
      cout << "ID: " << pair.first << " | Details: " << pair.second << "\n";
    }
    cout << "-------------------\n";
  }

public:
  void run() {
    // Registration enforcement
    // Check if the user is registered or not before sending them to main menu.
    if (!currentUser.isRegistered()) {
      currentUser.registerUser();
    }

    // Main Menu logic
    int choice;
    do {
      displayMenu();

      // Validation of integer input for menu choice
      if (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }

      switch (choice) {
      case 1:
        currentUser.displayProfile();
        break;
      case 2:
        addRecord();
        break;
      case 3:
        searchRecord();
        break;
      case 4:
        deleteRecord();
        break;
      case 5:
        displayAllRecords();
        break;
      case 6:
        cout << "Exiting program. Goodbye!\n";
        break;
      default:
        cout << "Invalid choice. Please select an option from 1 to 6.\n";
      }
    } while (choice != 6);
  }
};

int main() {
  // Instantiate and run the application
  Application app;
  app.run();
  return 0;
}