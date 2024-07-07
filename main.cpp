#include <iostream>
#include <cstring>
using namespace std;

const int Max_acc = 100;

int n;

class Account {
private:
    char name[30];
    char pass[15];
    int ty;
    
public:
float balance;

    static long account_number;
    static int account_count;

    void type();
    void Acc();
    
    
    bool validate(const char* inputName, const char* inputPass) {
        return strcmp(name, inputName) == 0 && strcmp(pass, inputPass) == 0;
    }

    const char* getName() const {
        return name;
    }
    
};

class fns:public Account{
    private:
       int  min_balance = 1000;
       int charge = 100;
    public:
        void deposit(float a){
            balance+=a;
            cout<<"Deposited amount: "<<a<<"\nNew Balance: "<<balance<<endl;
        }

        float getBalance() const {
            return balance;
        }

        void withdraw(float b){
            if (b<=balance){
                balance -= b;
                cout<<"Amount withdrawed: "<<b<<"\nNew Balance: "<<balance<<endl;
            }
            else{
                cout<<"\nInsufficient Balance\n";
            }
        }

        void depositS(float b){
            int si,r=3,t=10;
            si=(b*r*t)/100;
            balance += b;
            cout<<"Amount withdrawed: "<<b<<"\nNew Balance: "<<balance<<endl;
            cout<<"Simple interest is added "<<si<<endl;
            balance+=si;
            cout<<"After adding simple interest new balance: "<<balance<<endl;
            
        }

        void Cheque_Book(float b){
            if(b<balance){
                    balance -= b;
                    cout<<"Amount withdrawed: "<<b<<"\nNew Balance: "<<balance<<endl;
                    if (min_balance<b){
                       balance-=100;
                    cout<<"Your balance is less than min balance . So service charge is imposed!!!\n";
                
                    }
            }
            
            else if(b>balance){
                cout<<"\nInsufficient Balance\n";
            }

        }
};

class Array{
    public :
        fns create_ac[Max_acc];
};

class CurrentType : public Array , public fns{
    public:
        void current();
};

class SavingsType : public Array , public fns{
    public:
        void savings();
};

long Account::account_number = 1000000001;
int Account::account_count = 0;

class Bank : public Account, public Array {
    
public:
    void create_acc();
    

    bool SignIn(const char* inputName, const char* inputPass) {
        for (int i = 0; i < account_count; ++i) {
            if (create_ac[i].validate(inputName, inputPass)) {
                cout << "Welcome, " << inputName << " You are now signed in." << endl;
                n = i;
                create_ac[i].type();
                return true;
            }
        }
        cout << "Invalid credentials. Please try again." << endl;
        return false;
    }
};

int main() {
    Bank b;
    int ch;
    cout << "________Welcome________";
    while (true) {
        cout << "\n1. Create\n2. Sign in\n3. Exit\n";
        cout << "Enter the Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                b.create_acc();
                break;
            case 2: {
                char inputName[30];
                char inputPass[15];
                cout << "\nEnter your name: ";
                cin >> inputName;
                cout << "\nEnter your password: ";
                cin >> inputPass;
                b.SignIn(inputName, inputPass);
                break;
            }
            case 3:
                return 0;
            default:
                cout<<"\nInvalid Choice\n";
                break;
        }
    }
}

//Functions Used

void Bank :: create_acc() {
        if (account_count < Max_acc) {
            create_ac[account_count].Acc();
            account_count++;
        } else {
            cout << "Maximum account limit reached." << endl;
        }
}

void Account :: type(){
    CurrentType c;
    SavingsType s;
    switch (ty){
            case 1:
                c.current();
                break;   
            case 2:
                s.savings();
                break;
            default:
                cout<<"\nInvalid Choice\n";
                break;
    }
}

void Account :: Acc() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Password under 15 characters: ";
        cin >> pass;

        char conf[15];
        while (true) {
            cout << "Confirm Password: ";
            cin >> conf;
            if (strcmp(pass, conf) != 0) {
                cout << "Password incorrect\n";
                cout << "Re-enter password\n";
            } else {
                break;
            }
        }

        cout <<"Select the acc type\n";
        cout<<"\n1.Current\n2.Savings\n";
        cout<<"Enter the choice: ";
        cin >> ty;
        cout << "Your ACC number: " << account_number << endl;
        account_number++;
}

void CurrentType  :: current(){
    while(1){
        int ch;
        float amount;
        cout<<"\n1.Deposit\n2.Show Balance\n3.Cheque_Book\n4.Exit\n";
        cout<<"Enter Choice: ";
        cin >> ch;
        if (ch==4){
            break;
        }
        else{
            switch (ch){
                case 1:
                    cout<<"\nEnter the amount to Deposit:";
                    cin>>amount;
                    create_ac[n].deposit(amount);
                    break;
                case 2:
                    cout << "Balance is: " <<create_ac[n].getBalance() << endl;
                    break;
                case 3:
                    cout<<"Enter amount to withdraw: ";
                    cin>>amount;
                    create_ac[n].Cheque_Book(amount);
                    break;
                default:
                    cout<<"\nInvalid Choice";
                    break;
            }
        }
    }
}

void SavingsType :: savings(){
    int ch;
    float amount;
    while(1){
        cout<<"\n1.Deposit\n2.Show Balance\n3.Withdraw\n4.Exit\n\n";
        cout<<"Enter Choice: ";
        cin>>ch;
        if (ch==4){
            break;
        }
        else{
            switch (ch){
                case 1:
                    cout<<"\nEnter the amount to Deposit:";
                    cin>> amount;
                    create_ac[n].depositS(amount);
                    break;
                case 2:
                    cout << "Balance is: " <<create_ac[n].getBalance() << endl;
                    break;
                case 3:
                    cout<<"\nEnter amount to withdraw: ";
                    cin>>amount;
                    create_ac[n].withdraw(amount);
                    break;
                default:
                    cout<<"\nInvalid Choice";
                    break;
                }
            }
        }
}

