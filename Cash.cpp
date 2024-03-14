#include <iostream>
#include<string.h>
using namespace std;
class ATM
{
private:
    int balance;
    int pincode;
    int success;

public:
    ATM(int bal, int pin)
    {
        balance = bal;
        pincode = pin;
    }
    int getBalance()
    {
        return balance;
    }
    int withdraw(int amount, int pin)
    {
        if(pin != pincode)
        {
            return false;
        }
        if (amount > balance)
        {
            return false;
        }
        balance = balance - amount;
        return true;
    }
    void deposit(int amount)
    {
        balance = balance + amount;
    }
    int tranfer(int amount, ATM receiver, int pin)
    {
        if(pin != pincode)
        {
            return false;
        }
        success = withdraw(amount, pin);
        if(success)
        {
            receiver.deposit(amount);
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    ATM atm(1000, 9090);
    int choice = 0, amount = 0, success = 0, pin = 0;
    string op = " ";
    do
    { 
        system("cls"); // new transaction --> screen should be clear
        cout << "1. View Balance \n2. Cash Withdraw \n3. Cash Deposit \n4. Cash Transfer \n5. Exit\n";
        cout << "Enter yout choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Your Balance is : " << atm.getBalance();
            break;
        case 2:
            cout << "Your available balance is : " << atm.getBalance()<<endl;
            cout << "Enter the amount to withdraw : ";
            cin >> amount;
            success = atm.withdraw(amount,9090);
            if (success)
            {
                cout << "Withdraw Successful!!!\n";
            }
            else
            {
                cout << "Insufficient balance...";
            }
            break;
        case 3:
            cout << "Enter rhe amount to deposit : ";
            cin >> amount;
            atm.deposit(amount);
            cout << "Deposit Sucessfull!!!\n";
            break;
        case 4:
            cout << "Your available balance is : " << atm.getBalance()<<endl;
            cout<<"Enter the amount to transfer : ";
            cin>>amount;
            cout<<"Enter Pin Code : ";
            cin>>pin;
            success = atm.tranfer(amount,atm,pin);
            if(success)
            {
                cout<<"Transfer is Successful!!!\n";
            }
            else
            {
                cout<<"Transfer is Unsuccessful!!!\n";
            }
            break;
        case 5:
            cout << "Thanks for using ATM\n";
            exit(1);
            break;
        default:
            cout << "Invalid Choice\n";
        }
        cout << "\nDo you want to try another transaction [Yes / No] :";
        cin >> op;
    } while (op == "Yes" || op == "yes" || op == "YES");
    return 0;
}