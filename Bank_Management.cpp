#include<iostream>


using namespace std;

//bank mangement system
/*
 saving account
 current account
 
 account creation
 deposit
 withdraw
 balance
 */

class account
{
 private:
    string name;
    int accno;
    string atype;
public:
    void getaccountdetails()
    {
        cout<<"\n enter customer name :";
        cin>>name;
        cout<<"enter account number :";
        cin>>accno;
        cout<<"enter account type :";
        cin>>atype;
    }
    void displaydetails()
    {
        cout<<"\n\n customer name : "<<name;
        cout<<"\n account number :"<<accno;
        cout<<"\n account type :"<<atype;
    }
};
class current_account : public account
{
private:
    float balance;
public:
   void c_display()
    {
        cout<<"\n balance :"<<balance;
    }
    void c_deposit()
    {
        float deposit;
        cout<<"\n enter amount to deposite :";
        cin>>deposit;
        balance=balance+deposit;

    }
    void c_withdraw()
    {
        float withdraw;
        cout<<"\n\nbalance:"<<balance;
        cout<<"\n enter amount to withdraw :";
        cin>>withdraw;
        if(balance>1000)
        {
            balance=balance-withdraw;
            cout<<"\n amount after withdraw :"<<balance;
        }
        else
        {
            cout<<"\n insufficient balance";
        }
    }
};


class saving_account : public account
{
private:
    float sav_balance;
public:
    void s_display()
     {
    cout<<"\n balance :"<<sav_balance;

}
    void s_deposit()
   {
    float deposit,interest;
    cout<<"\n enter amount to deposit:";
    cin>>deposit;
    sav_balance=sav_balance+deposit;
    interest=(sav_balance*2)/100;
    sav_balance=sav_balance+interest;
   }
   void s_withdraw()
{
    float withdraw;
    cout<<"\n balance:"<<sav_balance;
    cout<<"\n enter amount to withdraw:";
    cin>>withdraw;
    if(sav_balance>500)
    {
        sav_balance=sav_balance-withdraw;
        cout<<"\n balance amount after withdrae:"<<sav_balance;
    }
    else{
        cout<<"\n insufficient balance";
    }
}
};
int main()
{
    saving_account s1;
    current_account c1;
    char type;
    cout<<"\n enter s for saving account and c for current account:";
    cin>>type;
    int choice;
    if(type=='s'||type =='S')
    {
        s1.getaccountdetails();
        while(1)
        {
            cout<<"\n choose your choice"<<endl;
            cout<<"\n 1.deposit"<<endl;
            cout<<"\n 2.withdraw"<<endl;
            cout<<"\n 3.display"<<endl;
            cout<<"\n 4.display with full details"<<endl;
            cout<<"\n 5. exit"<<endl;
            cout<<"\n enter your choice:";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    s1.s_deposit();
                    break;
                case 2:
                    s1.s_withdraw();
                    break;
                case 3:
                    s1.s_display();
                    break;
                case 4:
                    s1.displaydetails();
                    s1.s_display();
                     break;
                default:
                    cout<<"\n invalid choice";
            }
        }
    }
    else if(type=='c'||type=='C')
    {
        c1.getaccountdetails();
        while(1)
        {
            cout<<"\n choose your choice"<<endl;
            cout<<"\n 1.deposit"<<endl;
            cout<<"\n 2.withdraw"<<endl;
            cout<<"\n 3.display"<<endl;
            cout<<"\n 4.display with full details"<<endl;
            cout<<"\n 5. exit"<<endl;
            cout<<"\n enter your choice:";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    c1.c_deposit();
                    break;
                case 2:
                    c1.c_withdraw();
                    break;
                case 3:
                    c1.c_display();
                    break;
                case 4:
                    c1.displaydetails();
                    c1.c_display();
                    break;
                default:
                    cout<<"\n invalid choice";
            }
        }
    }
    else
    {
        cout<<"\n invalid choice";
    }
    end:
     cout<<"\n thank you for banking...";
     return 0;
}