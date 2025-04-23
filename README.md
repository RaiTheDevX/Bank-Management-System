# Bank Management System – C++

## 📜 Project Overview
This project is an **interactive bank management system** developed in C++ that allows users to create and manage accounts, deposit and withdraw funds, and view account balances securely via a PIN. It uses file handling for persistent storage and showcases object-oriented programming principles.

---

## ⚙️ Features
- **Account Creation:** Allows users to create new bank accounts with personal details and PIN.
- **Deposit Funds:** Users can deposit money into their accounts.
- **Withdraw Funds:** Enables users to withdraw money from their accounts (with balance checks).
- **Balance Inquiry:** View the current balance of any account.
- **PIN-based Authentication:** Ensures account security with a user-defined PIN.
- **Persistent Data Storage:** Saves account details to a file for data persistence.
- **Interactive CLI:** A simple, easy-to-use command-line interface for interacting with the system.

---

## 🛠️ How It Works
1. **Account Management:**  
   Users can create, update, and manage bank accounts through the command-line interface.

2. **PIN-based Authentication:**  
   The system requires the correct PIN to allow users to access and manage their accounts.

3. **Data Storage:**  
   Account details (such as account number, balance, and PIN) are stored in a file (`accounts.dat`) and can be retrieved when the program is restarted.

4. **Transaction Management:**  
   Users can deposit and withdraw funds, with checks for sufficient balance during withdrawals.

---

## 🖥️ Requirements
- C++ compiler (e.g., g++, clang++)
- No additional libraries required (Standard C++ libraries used)

---

## 🚀 Usage
1. Clone the repository:
   ```bash
   gh repo clone RaiTheDevX/Bank-Management-System

    Compile the C++ code:

g++ main.cpp -o bank

Run the program:

    ./bank

    Follow the on-screen menu to:

        Create a new account

        Deposit funds

        Withdraw funds

        Check balance

        Display account details

---

📊 Example Output

-----------------------------------
 Welcome to the Bank Management CLI
-----------------------------------
1. Create New Account
2. Deposit Funds
3. Withdraw Funds
4. Balance Inquiry
5. Display Account Details
6. Save & Exit
Enter your choice:

Balance Inquiry:

    Enter Account Number: 12345
    Enter PIN: ****
    Balance: $1000.00

🤔 Why This Project?

This project demonstrates:

    - Object-oriented programming with classes and file handling in C++.

    - A simple, secure, and interactive CLI for managing banking operations.

    - Data persistence through file-based storage.

🙌 Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request.
