// bank-management-system
// Basic structure with Account class and CLI menu

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Account {
private:
    int accNumber;
    string name;
    double balance;
    string pin;

public:
    void createAccount();
    void showAccount() const;
    void deposit(double amount);
    void withdraw(double amount);
    bool authenticate(const string& inputPin) const;
    int getAccNumber() const { return accNumber; }
    string getName() const { return name; }
    double getBalance() const { return balance; }
    void setBalance(double b) { balance = b; }
    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);
};

void Account::createAccount() {
    cout << "\nEnter Account Number: ";
    cin >> accNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Starting Balance: ";
    cin >> balance;
    cout << "Set 4-digit PIN: ";
    cin >> pin;
    cout << "\nAccount Created Successfully!\n";
}

void Account::showAccount() const {
    cout << "\nAccount Number: " << accNumber;
    cout << "\nName: " << name;
    cout << fixed << setprecision(2);
    cout << "\nBalance: $" << balance << "\n";
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance >= amount)
        balance -= amount;
    else
        cout << "\nInsufficient balance!\n";
}

bool Account::authenticate(const string& inputPin) const {
    return inputPin == pin;
}

void Account::saveToFile(ofstream& out) const {
    out << accNumber << '\n' << name << '\n' << balance << '\n' << pin << '\n';
}

void Account::loadFromFile(ifstream& in) {
    getline(in, name);
    in >> accNumber >> balance >> pin;
    in.ignore();
}

vector<Account> accounts;

void saveAllAccounts() {
    ofstream file("data/accounts.dat");
    file << accounts.size() << '\n';
    for (const auto& acc : accounts)
        acc.saveToFile(file);
    file.close();
}

void loadAllAccounts() {
    ifstream file("data/accounts.dat");
    if (!file) return;
    int size;
    file >> size;
    file.ignore();
    for (int i = 0; i < size; ++i) {
        Account acc;
        acc.loadFromFile(file);
        accounts.push_back(acc);
    }
    file.close();
}

void displayMenu() {
    cout << "\n-----------------------------------\n";
    cout << " Welcome to the Bank Management CLI\n";
    cout << "-----------------------------------\n";
    cout << "1. Create New Account\n";
    cout << "2. Deposit Funds\n";
    cout << "3. Withdraw Funds\n";
    cout << "4. Balance Inquiry\n";
    cout << "5. Display Account Details\n";
    cout << "6. Save & Exit\n";
    cout << "Enter your choice: ";
}

Account* findAccount(int accNumber) {
    for (auto& acc : accounts)
        if (acc.getAccNumber() == accNumber)
            return &acc;
    return nullptr;
}

int main() {
    loadAllAccounts();
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == 6) {
            saveAllAccounts();
            cout << "\nAll data saved. Exiting...\n";
            break;
        }
        int accNum;
        Account* acc;
        double amount;
        string pin;

        switch (choice) {
            case 1:
                {
                    Account newAcc;
                    newAcc.createAccount();
                    accounts.push_back(newAcc);
                    break;
                }
            case 2:
                cout << "Enter Account Number: "; cin >> accNum;
                acc = findAccount(accNum);
                if (acc) {
                    cout << "Enter PIN: "; cin >> pin;
                    if (acc->authenticate(pin)) {
                        cout << "Enter amount to deposit: "; cin >> amount;
                        acc->deposit(amount);
                        cout << "Deposit Successful.\n";
                    } else cout << "Invalid PIN.\n";
                } else cout << "Account not found.\n";
                break;
            case 3:
                cout << "Enter Account Number: "; cin >> accNum;
                acc = findAccount(accNum);
                if (acc) {
                    cout << "Enter PIN: "; cin >> pin;
                    if (acc->authenticate(pin)) {
                        cout << "Enter amount to withdraw: "; cin >> amount;
                        acc->withdraw(amount);
                    } else cout << "Invalid PIN.\n";
                } else cout << "Account not found.\n";
                break;
            case 4:
                cout << "Enter Account Number: "; cin >> accNum;
                acc = findAccount(accNum);
                if (acc) {
                    cout << "Enter PIN: "; cin >> pin;
                    if (acc->authenticate(pin)) {
                        cout << "Balance: $" << acc->getBalance() << "\n";
                    } else cout << "Invalid PIN.\n";
                } else cout << "Account not found.\n";
                break;
            case 5:
                cout << "Enter Account Number: "; cin >> accNum;
                acc = findAccount(accNum);
                if (acc) acc->showAccount();
                else cout << "Account not found.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
