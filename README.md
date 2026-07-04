# The Little Book Haven (Genius Bookshop) - CLI

A console-based Bookstore Management System developed in C++. This project simulates a real-world digital bookstore dashboard with role-based access control, inventory management, and live sales processing.

---

## 📈 Evolution & Context
> "This is one of my earliest projects built during Semester 1 to understand the fundamentals of C++ programming, arrays, and structural design."

This repository serves as a foundation showcase for core programming concepts, demonstrating data structure layouts, structural schemas, and procedural logic flows built during the initial stages of my Software Engineering journey.

---

## 🛠️ Technical Stack & Concepts Used
* **Language:** C++
* **Paradigm:** Procedural Programming
* **Data Structures:** Fixed-size Arrays and Custom `struct` layouts
* **Control Flows:** Conditional Statements (`if-else`), Loops (`while`, `do-while`), and Menu Selection (`switch-case`)

---

## 🚀 Key Features

### 🔐 1. Role-Based Authentication System
* Multi-user simulation with separate permissions for **Admin** and **Standard User**.
* Secure access control shielding management actions from non-admin accounts.
* Built-in security block tracking failed credential entries (Maximum 3 login attempts).

### 📦 2. Comprehensive Inventory Management
* Dynamic lookup framework utilizing explicit unique identifiers (Book IDs).
* **View:** Tabular data layout displaying Book ID, Title, Author, Price (LKR), and Quantities.
* **Add:** Seamless element entry directly appending new objects into the structural array.
* **Update:** In-place fields modification for targeted text strings and numerical values.
* **Delete:** Data array restructuring using element-shifting loops to maintain sequence continuity upon extraction.

### 💰 3. Live Sales Dashboard
* Transaction processor with integrated logical checks.
* Auto-calculates billing values based on entry quantifiers.
* Prevents inventory anomalies through proactive stock-threshold validation.

---

## 📊 Structural Overview

The core data blueprint relies on a highly organized composite structure blueprint:

```cpp
struct books {
    int id;
    string bookname;
    string author;
    float price;
    int qty;
};
