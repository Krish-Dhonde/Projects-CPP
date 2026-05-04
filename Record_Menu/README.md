# User Record Management System

Hey there! Welcome to the User Record Management System. This project was born out of a desire to create a clean, professional, and highly efficient C++ console application. It moves away from scattered, isolated scripts and instead provides a cohesive, state-driven application with a proper workflow.

## The Concept & Hierarchy

The core idea behind this project is to mimic how real-world applications handle user sessions and data management. Instead of just dumping you into a menu where you can click random buttons, the program enforces a strict hierarchy:

1. **The Registration Phase (Initialization):** When you fire up the program, it recognizes that it doesn't know who you are. Before letting you touch any records, it prompts you to register by providing your Name, Age, and a User ID. 
2. **The Main Application Phase:** Once you're successfully registered, the doors unlock. You are brought to the main menu where you can manage your personal records. 

This two-step process ensures that data isn't manipulated by a "guest" and gives the application a structured flow.

## Functionalities & How to Use

The system provides a straight-to-the-point menu interface. Here's what you can do:

*   **View Profile (Option 1):** Instantly recalls and displays the personal details you entered during the registration phase.
*   **Add a Record (Option 2):** Allows you to save a new piece of data. You'll be asked to provide a unique integer ID and the details of the record (like a task, a note, or contact info).
*   **Search for a Record (Option 3):** Looking for something specific? Type in the Record ID, and the system pulls it up immediately.
*   **Delete a Record (Option 4):** Removes a record from the database using its ID.
*   **Display All Records (Option 5):** Prints out every single record currently stored in the system.
*   **Exit (Option 6):** Safely shuts down the application.

**How to run it:** 
Compile the `Menu_System.cpp` file using a standard C++ compiler (like g++):
```bash
g++ Menu_System.cpp -o Menu_System.exe
```
Then simply run `./Menu_System.exe` and follow the on-screen prompts!

## Technical Things (Under the Hood)

I wanted to make sure this wasn't just functional, but also written to professional standards. 

*   **Object-Oriented Design:** The code is modularized. There's a `User` class that strictly handles personal details and an `Application` class that manages the overall state and the records database.
*   **O(1) Time Complexity:** Instead of using basic arrays or vectors that require looping through every item to find what you need (O(N) time), this project uses C++'s `std::unordered_map`. This acts as a hash table, meaning that adding, searching, and deleting records happens in **O(1) average time**. Whether you have 5 records or 5 million, the system fetches them almost instantly.
*   **Bulletproof Input Validation:** Ever typed a letter when a program asked for a number and watched it crash into an infinite loop? Not here. The `cin` inputs are strictly validated. If you feed it bad data, it clears the error state, flushes the input buffer, and politely asks you to try again.

## A Quick Walkthrough

Here is a glimpse of what happens when you run the app:
1. You open the app and are greeted with `=== User Registration ===`.
2. You type in your name, a valid age, and an ID.
3. The system welcomes you and presents the `=== Main Menu ===`.
4. You press `2` to add a record. You give it an ID of `101` and type "Buy groceries".
5. You press `3` to search, type `101`, and the app instantly spits back "Buy groceries".
6. You press `6` when you're done to exit gracefully.

---

## Developer Guide: How to Edit

If you want to fork this, tweak it, or use it as a boilerplate for your own assignments or projects, go right ahead! Here is a guide on how to safely edit the code.

### 1. Adding a New Menu Option
If you want to add a feature (e.g., "Update a Record"):
*   Go to the `Application::displayMenu()` function and add your new option to the `cout` list. Don't forget to increment the "Exit" option number!
*   Scroll down to the `switch(choice)` block inside `Application::run()`. 
*   Add a new `case` for your feature, and call the function you wrote to handle it.
*   Update the `do...while (choice != X)` condition to match your new exit number.

### 2. Modifying User Details
If you want to ask for an email instead of age:
*   Update the private variables inside the `User` class.
*   Update the prompts in `User::registerUser()`.
*   Update the print statements in `User::displayProfile()`.

### Precautions While Editing

*   **Mind the Input Buffer (`cin >> ws`):** You'll notice I use `getline(cin >> ws, string_variable)` instead of just `cin >>`. This is crucial! Standard `cin` leaves newline characters (`\n`) in the input buffer, which causes `getline` to instantly skip. If you add new string inputs, always consume that whitespace first.
*   **Don't Break the Validation:** When asking for an integer, use the `while(!(cin >> variable))` loop provided in the code. This checks if the input failed (e.g., someone typed "hello" instead of "12"). If you skip the `cin.clear()` and `cin.ignore(...)` lines inside that loop, the program will get stuck in an infinite failure loop.
*   **Time Complexity:** If you decide to change `unordered_map` to a `vector` or an array to sort things alphabetically, remember that you will lose the O(1) performance for lookups and deletions! If you must sort, consider using a `std::map` instead (which gives O(log N) time).
