#include <iostream>
using namespace std;
class Person{
public:
    string F_name,L_name,user_name,pass;
    string clients[100];
    string clientspass[100];
    static int checkpass;
    static int checkname;
    long phone_number;
};
class Client:public Person{
private:
    long balance;
public :
    Client()
    {

    }
    Client(string f_name,string l_name,string username,string pass,long phone_number,long balance)
    {
        this->F_name=f_name;
        this->L_name=l_name;
        this->pass=pass;
        this->phone_number=phone_number;
        this->user_name=username;
        this->balance=balance;
    }
    bool log_in(string username,string pass)
    {
        bool checker=0;
        for(int i=0;i<checkname;++i)
        {
            if(username==clients[i]&&pass==clientspass[i])
            {
                checker=1;
                break;
            }
        }
        if(checker)
            return 1;
        else
          return 0;
    }
    void PayToBalance(long balance)
    {
        this->balance+=balance;
    }
    long viewbalance()
    {
        return this->balance;
    }
    void withdrawBalance(long amount)
    {
        this->balance-=amount;
    }


};
class Admin: public Person{
private :
    string hiring_date;
public :
    Admin()
    {
    this->user_name="admin";
    this->pass="admin";
    }
    Admin(string f_name,string l_name,long phone_number,string hiringDate)
    {
        this->F_name=f_name;
        this->L_name=l_name;
        this->phone_number=phone_number;
        this->hiring_date=hiringDate;
        this->user_name="admin";
        this->pass="admin";
    }
    bool log_in(string username,string pass)
    {
        if(username==this->user_name && pass==this->pass)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    long get_BankBalance()
    {
        return 1000;
    }
    bool createClientAccount(string f_name,string l_name,string username,string pass,long phone_number,long balance)
    {
        Client c(f_name,l_name,username,pass,phone_number,balance);
        clients[checkname++]=username;
        clientspass[checkpass++]=pass;
        return 1;
    }
    string* viewBankClients()
    {
         return clients;
    }
    void viewBankBranches()
    {
        cout<<"Bank Branches"<<endl;
    }

};
int Person::checkname=0;
int Person::checkpass=0;

int main()
{
    int choose;
    Admin admin;
    Client client;
    while(true)
    {
        cout<<"Choose :\n1-Admin\n2-Client\n0-Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choose;
        switch(choose)
        {
            case 1:
            {
                string username,pass;
                cout<<"please enter"<<endl;
                cout<<"Username : ";
                cin>>username;
                cout<<"Password : ";
                cin>>pass;
                if(admin.log_in(username,pass))
                {
                    int funchoice;
                do{
                string* clients;
                cout<<"choose : "<<endl;
                cout<<"1. Create Client Account"<<endl;
                cout<<"2. View Bank Balance"<<endl;
                cout<<"3. View Bank Branches"<<endl;
                cout<<"4. View Bank's Clients"<<endl;
                cout<<"0. Back "<<endl;
                cout<<"Enter your choice: ";
                cin>>funchoice;
                switch(funchoice)
                {
                case 1:
                    {
                    string f_name,l_name, username, pass;
                    long phone_number, balance;
                    cout<<"Enter:"<<endl;
                    cout<<"First name :";
                    cin>>f_name;
                    cout<<"Last name :";
                    cin>>l_name;
                    cout<<"Username :";
                    cin>>username;
                    cout<<"Password :";
                    cin>>pass;
                    cout<<"Phone_number :";
                    cin>>phone_number;
                    cout<<"Balance :";
                    cin>>balance;
                    admin.createClientAccount(f_name,l_name,username,pass,phone_number,balance);
                        cout<<"Created Account Successfully"<<endl;
                    break;
                    }
                case 2:
                    cout<<"Bank Balance is "<<admin.get_BankBalance()<<endl;
                    break;
                case 3:
                    admin.viewBankBranches();
                    break;
                case 4:
                    clients=admin.viewBankClients();
                    for(int i=0;i<admin.checkname;++i)
                    {
                        cout<<"Client #"<<i+1<<" : "<<clients[i]<<endl;
                    }
                    break;
                case 0:
                    break;
                }//switch function of admin
                }while(funchoice!=0);
                 }//(if)log in successfully
                else
                {
                    cout<<"Invalid username"<<endl;
                }
                break;

            }//case 1(admin)
            case 2:
                {
                    string username,pass;
                    cout<<"please enter"<<endl;
                    cout<<"Username : ";
                    cin>>username;
                    cout<<"Password : ";
                    cin>>pass;
                    if(client.log_in(username,pass))
                    {
                        int funchoice;
                        do
                        {
                            cout<<"choose : "<<endl;
                            cout<<"1. Pay to Balance"<<endl;
                            cout<<"2. View Balance"<<endl;
                            cout<<"3. Withdraw Balance"<<endl;
                            cout<<"0. Back "<<endl;
                            cout<<"Enter your choice: ";
                            cin>>funchoice;
                            switch(funchoice)
                            {
                            case 1:
                                {
                                  long balance;
                                  cout<<"Enter the balance ";
                                  cin>>balance;
                                  client.PayToBalance(balance);
                                  cout<<"Payed successfully"<<endl;
                                  break;
                                }
                            case 2:
                                cout<<"Balance = "<<client.viewbalance()<<endl;
                                break;
                            case 3:
                                {
                                    long amount;
                                    cout<<"Enter the amount"<<endl;
                                    cin>>amount;
                                    client.withdrawBalance(amount);
                                    cout<<"Successfully"<<endl;
                                    break;
                                }
                            case 0:
                                break;
                            }

                        }while(funchoice!=0);
                   }
                   else
                        {
                            cout<<"Invalid username"<<endl;
                        }
                     break;
                }

            case 0:
                cout<<"Ending the program. Goodbye"<<endl;
                return 0;
        }

}
return 0;
}
