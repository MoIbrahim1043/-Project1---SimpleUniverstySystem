# 🏫 Simple University System (C++ & OOP)

A comprehensive, console-based University Management System built from scratch using C++ and Object-Oriented Programming (OOP) principles. This project simulates a real-world administrative system managing multiple roles (Students, Doctors, Managers) with secured access and persistent file-based storage.

---

## 🚀 Features

- **Multi-Role Authentication:** Separate dynamic login screens and dashboards for **Students**, **Doctors**, and **Managers**.
- **Role-Based Access Control (RBAC):** Distinct permissions tailored for each user role.
- **Full CRUD Operations:** Capability to Add, Find, Update, and Delete records securely.
- **Robust Input Validation:** Custom validation engine to handle formatting, data types, and logical boundaries (e.g., date calculations).
- **Data Persistence:** File-based data storage (`.txt` database) handling custom delimited formatting (`#//#`).
- **Custom Utility Utilities:** Self-built standalone libraries for robust **String Manipulation** and complex **Date/Period Calculations**.

---

## 🛠️ Architectural Highlights & OOP Concepts

- **Encapsulation:** Properties are securely encapsulated using `private` members, accessed dynamically via Getters/Setters and enhanced with MSVC `__declspec(property)` metadata wrappers.
- **Inheritance:** Clean hierarchical design where `clsStudent`, `clsDoctor`, and `clsManager` inherit core profile attributes from a base `clsPerson` class to enforce the **DRY (Don't Repeat Yourself)** principle.
- **Memory Management:** Zero memory leaks! Utilizes modern C++ Standard Template Library (STL) containers like `std::vector` and `std::string` ensuring robust automatic resource management (RAII).

---

## 📦 Project Structure

```text
├── clsPerson.h             # Base Class for all users
├── clsStudent.h            # Student entity & management logic
├── clsDoctor.h             # Doctor/Professor entity & logic
├── clsManager.h            # Manager/Admin entity & system control
├── clsLoginScreen.h        # Consolidated login flow handling
├── clsString.h             # Custom standalone string processing library
├── clsDate.h               # Custom standalone date processing library
├── clsInputValidate.h      # Advanced input checking and formatting 
├── Global.h                # System state keeping (Active user contexts)


🎯 Key Takeaways & Code Review Reflections
This project was a major milestone in my software engineering journey. After conducting a deep-dive Code Review, I identified critical architectural areas that I am actively refactoring for future iterations:

Decoupling UI and Logic: Moving console text print/read statements out of business logic classes into dedicated View components.

Eliminating Namespace Pollution: Avoiding global using namespace std; inside header files to enforce true industrial-grade naming scopes.

Transitioning from Globals: Refactoring state persistence away from raw Global variables (Global.h) to more secure design patterns like Dependency Injection or Singletons.

Header/Source Separation: Migrating implementations from .h into separate .cpp files to significantly boost modular compilation speed.

🖥️ How to Run
Clone this repository:

Bash
git clone [https://github.com/MoIbrahim1043/-Project1---SimpleUniverstySystem.git](https://github.com/MoIbrahim1043/-Project1---SimpleUniverstySystem.git)
Open the solution folder in Visual Studio (or any modern C++ IDE).

Ensure your compiler supports C++17 or higher.

Build and Run main.cpp.└── main.cpp                # Application entry point

