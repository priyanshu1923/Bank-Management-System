// // //* wapas se jab dusra info le raha hoon, toh pehle k balance m add ho jaa raha
// // //isliye iuska dekhna hai 
// // //*check karna hbai ki jab savings and current alg alg le rahe hai toh ek dsaath add ho raha hai ya alg alg
// // //dikha raha hai
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
#include<conio.h>
#include<string>
using namespace std;
ofstream myfile;

class bankaccount{
    private:
    string accno="";
    //string atype;
    string name1,name2;
    string name3=" ";
    string res;
    string branch;
    //string type="savings";
    //string type1="current";
    float money;
    public:
    void accdetails()
    {
        // cout<<setw (82);
        cout<<"Enter the first name"<<endl;
        cin>>name1;
        // cout<<setw (81);
        cout<<"Enter the last name"<<endl;
        cin>>name2;
        // cout<<setw (86);
        label1:
        cout<<"Enter the account number"<<endl;
        
        fflush(stdin);//to clear if any input is there from early
        accno="";
        while (true) {
        char ch = cin.get();
        if (isdigit(ch)) {
            accno+=ch;
        }
        if (ch=='\n'){
             break;
        }
    }
    if (accno==""){
        goto label1;
    }
    cout << "Your valid account number is: " << accno << endl;

        // cout<<setw (87);
//again: 
    // cout<<"Enter the type of account"<<endl;
    // cin>>atype;
//         if(atype!=type)
//         {
//             //cout<<"Invalid selection of the account type"<<endl;
//             goto next;
//         }
// next:   if(atype!=type1)
//         {
//             cout<<"Invalid selection of the account type"<<endl;
//             goto again;
//         }
        cout<<"Enter the branch"<<endl;
        cin>>branch; 
        myfile.open("Accounts/"+accno+".txt",ios::out | ios::app);
        myfile<<name1<<","<<name2<<","<<accno<<","<<branch;
        myfile.close();
    }
    void disp_accdetails()
    {
        res=name1+name3+name2;
        cout<<setw(71);
        cout<<"Name:"<<res<<"\n";
        cout<<setw(81);
        cout<<"Account number:"<<accno<<"\n";
        // cout<<setw(82);
        // cout<<"Type of account:"<<atype<<"\n";
        cout<<setw(73);
        cout<<"Branch:"<<branch<<"\n";
    }
    // void transfermny()
    // {
    //     cout<<"Since you want to transfer money"<<endl;
    //     cout<<"Enter the ampount to be transferred"<<endl;
    //     cin>>money;
    // }
};
class modify: public bankaccount{
    private:
    string accno="";
    string atype;
    string name1,name2;
    string name3=" ";
    string res;
    string branch;
    public:
    void modifydetails()
    {
        cout<<"You can now update your profile"<<endl;
        cout<<"Enter the first name"<<endl;
        cin>>name1;
        cout<<"Enter the second name"<<endl;
        cin>>name2; 
        cout<<"Enter account type:"<<endl;
        cin>>atype;
        cout<<"Enter branch:"<<endl;
        cin>>branch;    
    }
    void disp_modifieddetails()
    {
        res=name1+name3+name2;
        cout<<setw(79);
        cout<<"Updated Name:"<<res<<"\n";
        cout<<setw(87);
        cout<<"Updated account type:"<<atype<<"\n";
        cout<<setw(81);
        cout<<"Updated Branch:"<<branch<<"\n";
    }
    void status()
    {
        cout<<"Your profile has been updated"<<endl;
    }
};
class closeaccount: public bankaccount{
    public:
    void closeacc()
    {
        cout<<"Your account has been successfully closed"<<endl;
    }
     void disp_accdetails()
    {
        cout<<"Sorry but your account no longer exist"<<endl;
    }
};
class currentaccount: public bankaccount{
     float balance=0,balancetrnfr1,money1;
    string name6,name7,name8=" ",ress1,aatype1;//aatype for transferred person's acc type
    public:
    currentaccount()
    {
        money1=0;
    }
    void c_display()
    {
        cout<<setw(74);
        cout<<"Balance:"<<balance<<endl;
        //balance=0;
    }
    void c_display1()
    {
        balance=0;
    }
    void c_deposit()
    {
        float deposit;
        cout<<"Enter the amount to deposit"<<endl;
        cin>>deposit;
        balance=balance+deposit;
    }
    void c_withdraw()
    {
        float withdraw;
        cout<<"Enter the amount to withdraw"<<endl;
        cin>>withdraw;
        if(balance>withdraw)
        {
            balance=balance-withdraw;
            cout<<setw(78);
            cout<<"Balance after withdrawl:"<<balance<<endl;
        }
        else
        {
            cout<<setw(80);
            cout<<"Insufficient balance"<<endl;
        }
    }
    float trnsfr()
    {
        //float money;
        cout<<"Since you want to transfer money"<<endl;
        cout<<"Enter the amount to be transferred"<<endl;
        cin>>money1;
        balance=balance-money1;
        return money1;
    }
    void gettrnsfrmoney()
    {
        cout<<"Enter the details of the person you want to transfer money too"<<endl;
        cout<<"enter the first name"<<endl;
        cin>>name6;
        cout<<"Enter the last name"<<endl;
        cin>>name7;
        cout<<"Enter account type:"<<endl;
        cin>>aatype1;
        // balancetrnfr=balancetrnfr+money;
        //return balancetrnfr;
    }
    void disp_trnsfrmny()
    {
        ress1=name6+name8+name7;
        cout<<"Name:"<<ress1<<endl;
        cout<<"Account type:"<<aatype1<<endl;
        balancetrnfr1=balancetrnfr1+money1;
        cout<<"Transferred Balance:"<<balancetrnfr1<<endl;
    }
};
class savingsaccount: public bankaccount{
    float sav_balance=0,balancetrnfr,money;
    string name3,name4,name5=" ",ress,aatype;//aatype1 for transferred person's acc type
    public:
    savingsaccount()
    {
        money=0;
    }
    void s_display()
    {
        cout<<setw(74);
        cout<<"Balance:"<<sav_balance<<endl;
        //sav_balance=0;
    }
    void s_display1()//making balance as zero when taking new info
    {
        sav_balance=0;
        // cout<<setw(74);
        // cout<<"Balance:"<<sav_balance<<endl;
    }
    void s_deposit()
    {
            float deposit,interest;
            cout<<"Enter the amount to deposit"<<endl;
            cin>>deposit;
            sav_balance=sav_balance+deposit;
            interest=(sav_balance*2)/100;
            sav_balance=sav_balance+interest;
            cout<<"Interest on your deposited account will be :"<<interest<<endl;
    }
    // void s_interest()
    // {
    //     cout<<"Interest is:"<<interest<<endl;
    // }
    void s_withdraw()
    {
        float withdraw;
        cout<<"Balance:"<<sav_balance<<endl;
        cout<<"Enter the amount to withdraw"<<endl;
        cin>>withdraw;
        if(sav_balance>withdraw)
        {
            sav_balance=sav_balance-withdraw;
            cout<<setw(78);
            cout<<"Balance after withdrawl:"<<sav_balance<<endl;
        }
        else
        {
            cout<<setw(80);
            cout<<"Insufficient balance"<<endl;
        }
    }
    float trnsfr()
    {
        //float money;
        cout<<"Since you want to transfer money"<<endl;
        cout<<"Enter the amount to be transferred"<<endl;
        cin>>money;
        sav_balance=sav_balance-money;
        return money;
    }
    void gettrnsfrmoney()
    {
        cout<<"Enter the details of the person you want to transfer money too"<<endl;
        cout<<"enter the first name"<<endl;
        cin>>name3;
        cout<<"Enter the last name"<<endl;
        cin>>name4;
        cout<<"Enter account type:"<<endl;
        cin>>aatype;
        // balancetrnfr=balancetrnfr+money;
        //return balancetrnfr;
    }
    void disp_trnsfrmny()
    {
    //     string ress,name3,name4,name5=" ";
        ress=name3+name5+name4;
        cout<<"Name:"<<ress<<endl;
        cout<<"Account type:"<<aatype<<endl;
        balancetrnfr=balancetrnfr+money;
        cout<<"Transferred Balance:"<<balancetrnfr<<endl;
    }
};
int main(){
    currentaccount c1;
    savingsaccount s1;
    closeaccount d1;
    modify m1;
    char typ;
    cout<<setw (100);
   cont:cout<<"Enter S for saving account or C for current account:"<<endl;
    cin>>typ;
    string atype;
    string type="savings";
    string type1="current";
    int c=0;
    int d=0;
    int e=0;//counter for tranferred money
    int choice;
    if(typ== 's'|| typ=='S')
    {
 again: cout<<"Enter the type of account"<<endl;
        cin>>atype;
        if(atype!=type)
        {
            cout<<"Inv alid selection of the branch"<<endl;
            goto again;
        }
        s1.accdetails();
        while (1)
        {
            cout<<"Select your choice"<<endl;
            cout<<"1) Deposit"<<endl;
            cout<<"2) Withdraw"<<endl;
            cout<<"3) Display Balance"<<endl;
            cout<<"4) Display Full Details"<<endl;
            cout<<"5) Modify Details"<<endl;
            cout<<"6) Close account"<<endl;
            cout<<"7) Transfer Money"<<endl;
            cout<<"8) Exit"<<endl;
    start:  cout<<"Enter the choice"<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1:
                s1.s_deposit();
                break;
            case 2:
                s1.s_withdraw();
                break;
            case 3:
                s1.s_display();
                cout<<setw(82);
                cout<<"Type of account:"<<atype<<"\n";
                break;
            case 4:
                if(c==1)
                {
                    d1.disp_accdetails();
                    cout<<setw(82);
                    cout<<"Type of account:"<<atype<<"\n";
                    //s1.s_interest();
                    s1.s_deposit();
                    c=0;
                    goto cont;
                }
                else
                if(d==1)
                {
                    m1.disp_modifieddetails();
                    s1.s_display();
                    m1.status();
                    d=0;
                    s1.s_display1();
                    goto cont;
                }
                else
                if(e==1)
                {
                    s1.disp_trnsfrmny();
                    e=0;
                    goto start;
                }
                else
                s1.disp_accdetails();
                cout<<setw(82);
                cout<<"Type of account:"<<atype<<"\n";
                s1.s_display();
                break;
            case 5:
                m1.modifydetails();
                m1.disp_modifieddetails();
                m1.status();
                d++;
                goto start;
            case 6:
                d1.closeacc();
                c++;
                goto start;
            case 7:
                s1.trnsfr();
                s1.gettrnsfrmoney();
                e++;
                goto start;
            case 8:
                goto end;
            default:
            cout<<"Entered choice is ivalid"<<endl;
                break;
            
            }
        }
        
    }
    else if(typ=='c'||typ=='C')
    {
        again1: cout<<"Enter the type of account"<<endl;
        cin>>atype;
        if(atype!=type1)
        {
            cout<<"Invalid selection of the branch"<<endl;
            goto again1;
        }
        c1.accdetails();
        while (1)
        {
            cout<<"Select your choice"<<endl;
            cout<<"1) Deposit"<<endl;
            cout<<"2) Withdraw"<<endl;
            cout<<"3) Display Balance"<<endl;
            cout<<"4) Display Full Details"<<endl;
            cout<<"5) Modify Details"<<endl;
            cout<<"6) Close account"<<endl;
            cout<<"7) Transfer Money"<<endl;
            cout<<"8) Exit"<<endl;
    start1: cout<<"Enter the choice"<<endl;
            cin>>choice;
            switch (choice)
            {
            case 1:
                c1.c_deposit();
                break;
            case 2:
                c1.c_withdraw();
                break;
            case 3:
                c1.c_display();
                cout<<setw(82);
                cout<<"Type of account:"<<atype<<"\n";
                break;
            case 4:
                if(c==1)
                {
                    d1.disp_accdetails();
                    cout<<setw(82);
                    cout<<"Type of account:"<<atype<<"\n";
                    c=0;
                    goto cont;
                }
                else
                   if(d==1)
                {
                    m1.disp_modifieddetails();
                    c1.c_display();
                    m1.status();
                    d=0;
                    c1.c_display1();
                    goto cont;
                }
                if(e==1)
                {
                    c1.disp_trnsfrmny();
                    e=0;
                    goto start1;
                }
                else
                c1.disp_accdetails();
                cout<<setw(82);
                cout<<"Type of account:"<<atype<<"\n";
                c1.c_display();
                break;
            case 5:
                m1.modifydetails();
                m1.disp_modifieddetails();
                m1.status();
                d++;
                goto start1 ;
            case 6:
                d1.closeacc();
                c++;
                goto start1;
            case 7:
                c1.trnsfr();
                c1.gettrnsfrmoney();
                e++;
                goto start1;
            case 8:
                goto end;
            default:
            cout<<"Entered choice is ivalid"<<endl;
                break;
            
            }
        }  
    }
   else
    {
        cout<<"Invalid Account selection"<<endl;
    }
    end:
    cout<<"Thankyou for banking with us"<<endl;
getch();
return 0;
}
