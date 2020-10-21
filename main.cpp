/*
Name: Christohe Rurangwa
Date: 10/15/2020
CIS 1202-501
Program Name: ATM program.
Description of what the program does:
This program allows the user to make deposit, withdraw,
 display total balance, and display tips of saving cash.
*/

#include <iostream>
#include<string>
#include "cstdlib"
#include "cstring"


using namespace std;



/**
 * data structures
 */
struct Bank{


    double totalBalance;

};

struct Client {

    double deposit;
    double withdrawn;
};

//Prototype functions

void searchLocationInCity();
void menu(char greeting[],string &yourName);
string name(string &yourName);
double withDraw(Bank bank,Client cash[],string switcher);
void stats(string days[],int depovalue);
int receiptNumber(char alphabets [],int SIZE);
int atmIdNumber(char alphabets[]);
double totalSavings(Bank bank,Client cash[]);
int depositCash(Client cash[],int depoValue,double weeklyDepos[]);
void displayDepositReceipt(Client cash [], int depoValue,char alphabets [],int SIZE,string &yourName);




int main() {


    const int SIZE=27;
    const int GREETINGS=21;
    const double MAXI=2999999.999;
    string yourName;
    char greetMsg[GREETINGS]="WELCOME TO PNC";

    double  weeklyDepos[]={};
    Client cash[]={};
    string days []={"Monday","Tuesday","Wednesday","Thursday",
                    "Friday","Saturday","Sunday"};


    Bank bank;Client client;



    char alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                        'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        int depovalue;


        name(yourName);


    cout<<"\t\t\t---"<<greetMsg<<"--- \n\n";
    int pin;
    cout<<"Please Enter a 4 digits PIN, it MUST be a number GREATER "
          "than 1000, and not GREATER than 9999.\n";
    string switcher;

   do {

       cin>>pin;
       int count;
       count+=count;
       cout<<"Please Enter your LastName.\n";
       cin>>yourName;
       name(yourName);
    if(pin>1000 && pin<9999) {


        menu(greetMsg,yourName);

        cout<<"\t\t\t ATM No."<< atmIdNumber(alphabets)<<"\n";


    }
    else if(count<3){

        cout<<"You have TWO trial left "<<name(yourName)<<".\n";
    }

    else if(count<5){ //<-- checks to see if pin is valid.
        cout<<"Your pin is Invalid, please re-enter correct pin to continue.\n";

       } else {cout<<"This terminal has been deactivated, due to multiple trials to gain access, "
                     "please contact your BANK for help.\n Phone 937-xxxx-xxx, or restart the program.";
       break;}
   }while (pin<1000||pin>9999);
    int choix;

    do {
        cin>> choix;

        switch (choix) {

            case 1:if(true){cout<<" --Please Enter How many Deposit you are making Today--\n";

                    cin>>depovalue;}//<--Always going to be true
                depositCash(cash,MAXI,weeklyDepos);
                displayDepositReceipt( cash , depovalue, alphabets ,SIZE, yourName);
                break;

            case 2:withDraw( bank, cash, "on");
                break;
            case 3:searchLocationInCity();
                break;
            case 4:cout<<"$" <<totalSavings( bank, cash)<<" available.\n";
                break;
            case 5:stats( days, depovalue );
                break;

            case 6:exit(0);
            default:
                cout<<"Wrong choice, try again.\n";
                cin>>choix;

        }

    }while (choix<7);



    return 0;
}
/**
 * Will return a randomly generated number within the bounds specified.
 * @return id
 */
int receiptNumber(char alphabets [],int SIZE){

    int min=1111111;
    int max=RAND_MAX;
    srand(time(0));//<-- needed everytime a program run to produce random numbers
    int id= min+(rand()%max);//<-- picks a number from min to max


    for (int i =0;i<SIZE;i++){

        if(i%2==0){//checks to see if the number is even
            if(!isalpha(alphabets[i+((rand()%7)+1)])){// checks if the character is alphabet, skip if not
                continue;
            }
           else cout<< alphabets[i+((rand()%7)+1)];
        }
    }
    cout<<"-";

    return id;
}
/**
 * Prints out the id number for the ATM
 * @param alphabets
 * @return
 */
int atmIdNumber(char alphabets[]){

    cout<<"-PNC-";

    return (rand()%9999)+3090+strlen(alphabets);
}
/**
 * this function prints out the menu
 * @param greeting
 * @param yourName
 */
 void menu(char greeting[],string &yourName){

    cout<<"..."<<greeting<<"...\n\n";
     cout<<name(yourName)<<"\n\n";
    cout<<"1. Deposit Ca$h."<<endl;
    cout<<"2. Withdraw from your Account."<<endl;
    cout<<"3. Search a Branch in your Area."<<endl;
    cout<<"4. Check Balance."<<endl;
    cout<<"5. Display saving Tips."<<endl;
    cout<<"6. Exit."<<endl;

}


/**
 * gives user the option of deposit the value they wish to deposit
 * @param cash
 * @param depoValue
 * @param weeklyDepos
 * @param bank
 * @return
 */

int depositCash(Client cash[],int depoValue,double weeklyDepos[]){
    char ques;int count=0;
    cout<<"Insert the amount you wish to deposit: $ ";

    do{

        count++;

        cin>>cash[count-1].deposit; //<-- will deposit from position zero to the maximum amount the user wish
        weeklyDepos[count-1]=cash[count-1].deposit;

        cout<<"Enter 'y' to deposit more,or press 'n' to exit.  \n";
       cin>>ques; cout<<"$ ";
        if(depoValue==count)break;
   }while(ques=='y'||ques=='Y');


    return depoValue;
}

/**
 * This method will store the amount dollar in an array of type client
 * @param cash
 * @param days
 * @param depoValue
 */

void displayDepositReceipt(Client cash [], int depoValue,char alphabets [],int SIZE, string &yourName){

    cout<<"\t\t------PNC BANK------\n\n";
    cout<<"Oct/2020\n";

    for (int i=0;i<depoValue;i++){

        if(cash[i].deposit>=100000||cash[i].deposit==0||cash[i].deposit<=6.26953e-310){//<- Can't deposit more than 10000, the value 6.26953e-310 is the lowest limit to be entered.

            break;
        }

        cout<<"|--------------------------------|\n";
        cout<<"You deposited at instance ("<<i+1<<") :$ ";
        cout<<cash[i].deposit<<"\n";
        cout<<"|--------------------------------|\n";


    }
        cout<<"\n"<<" Receipt No. "<<receiptNumber(alphabets , SIZE)<<"\n";
        cout<<"||========================================||\n";
}
/**
 * will print stats showing the client how much the would benefited if they saved $50 everyday
 * @param weeklyDepos
 * @param days
 * @param depovalue
 */
void stats(string days[],int depovalue ){

    int amount=0;


    cout<<"Did you know, If you deposited $"<<50<<" everyday, your weekly saving would be: \n ";
    for (int i=0;i<7;i++){

        for (int j=0;j<depovalue;j++){

            cout<<"$"<<(amount+=50)<<"    ";
            cout<<days[i]<<" \n";

            break;
        }
    }
}
/**
 * will return the name after it has been entered as a reference
 * @param yourName
 * @return
 */
string name(string &yourName){

   string *p= nullptr;
   p=&yourName;

    return *p;
}
/**
 * will withdraw cash from saving account
 * @param bank
 * @param cash
 * @return
 */
double totalSavings(Bank bank,Client cash[]){
  bank.totalBalance  =41934.9544;
  if(withDraw(bank,cash,"off")!=0){
      bank.totalBalance=41934.9544-withDraw(bank,cash,"off");

  }
    return bank.totalBalance;
}
/**
 * will subtract the value type double, the user enters
 * @param bank
 * @param cash
 * @return
 */
double withDraw(Bank bank,Client cash[],string switcher){
  bank.totalBalance  =41934.9544;
if(switcher=="on"){
  cout<<"Enter how much to withdraw from your account: \n$";
  cin>>cash[0].withdrawn;
    double removingSaving=bank.totalBalance-cash[0].withdrawn;
    cout<<" You have $"<<removingSaving<<" available. \n";}
else if(switcher=="off"){
    return cash[0].withdrawn;

}

    return cash[0].withdrawn;
}
/**
 * sort and search the key string the user enters
 * @param key
 */
void searchLocationInCity(){
    cout<<"Type your city, e.g: \"Fairborn\",\"Kettering\",\"Lakewood\" or,\"Centerville.\"\n";

    string key;
    cin>>key;
    string temp1,temp2;
    string cityBranches[4][4]={{"Fairborn","Kettering","Lakewood","Centerville"},
                               {"Springfield","Oakwood","Dayton","Labanon"},
                               {"Trotwood","Cleveland","Moraine","Riverside"},
                               {"Clayton","Smithville","Beavercleek","DR"},

};
    //sort section

    for (int row1=0;row1<4;row1++){

        for (int col1=0;col1<4;col1++) {
            for (int row2=0;row2<4;row2++){
                temp1=row2+1;
                for (int col2=0;col2<4;col2++){
            if (cityBranches[row1][col1] >cityBranches[row2][col2]){
               // switching values
                    temp1=cityBranches[row1][col1];
                cityBranches[row1][col1]=temp2;
                temp2=temp1;
            }}}
        }
    }

//search section

    for (int row=0;row<4;row++){

        for (int col=0;col<4;col++){


            if(cityBranches[row][col]==key){

                cout<<"The city you entered "<<cityBranches[row][col]<<" was found, we do have a branch in this area.\n";
                break;
            }
        }
    }
}