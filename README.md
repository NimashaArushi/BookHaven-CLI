# The Little Book Haven (Genius Bookshop) - CLI

A Console-Based Bookstore Management System built using modern C++.

## 📈 Evolution Story
> "This is one of my earliest projects built during Semester 1 to understand the fundamentals of C++ programming, arrays, and structural design."

To showcase my growth as a Software Engineering undergraduate, I have refactored and upgraded this project using the advanced concepts I mastered by **Semester 4**.

## 🛠️ Key Technical Enhancements (Semester 4 Upgrade):
1. **Object-Oriented Architecture (OOP):** Shifted from a purely procedural approach to an OOP paradigm by encapsulating structural entities inside solid modern C++ classes (`Book` and `BookShopManager`).
2. **Dynamic Memory Allocation:** Removed hardcoded, fixed-size arrays (`books arrshop[100]`) and implemented `std::vector` to allow dynamic scaling of the book inventory.
3. **Data Persistence (File Handling):** Integrated `fstream` to automatically save and load bookstore data locally via a flat-file database (`books_db.txt`), preventing data loss upon application exit.
4. **Robust Input Validation:** Secured standard input streams utilizing `cin.clear()` and `numeric_limits` boundaries to completely eliminate terminal infinite loops and runtime crashes caused by invalid data types.

## 🚀 Features
* Role-based simulated login (Admin and User modes).
* Full CRUD operations for Admin (Add, View, Update, Delete books).
* Real-time stock calculation and sales management.
* Persistent storage.

## 💻 How to Run
1. Clone the repository.
2. Compile the `main.cpp` using any standard C++ compiler (G++, Clang, or MSVC).
3. Run the executable.
