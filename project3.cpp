#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

struct Account //struct variables 
{
    int account_Number; //account numbers with associated accounts
    string Name; //account name
    double balance; //balance display
    int num; //matching account numbers
    string month; //display month for file
    int acc; // account variable
};

void openfile1(ifstream& in) //file for account files
{
    in.open("/Users/ashwaqaljanahi/Project 3/accounts.txt"); //opening of account file
    if(in.is_open()) //checking for success of opening file
    {
        cout<<"File is open!"<<endl;
    }
   else //error check for file opening 
   {
    cout<< "Error! File is not open"<<endl;
   }
   
}
void openfile2(ifstream& input) //opening of transactions file 
  { input.open("/Users/ashwaqaljanahi/Project 3/transactions.txt");
        
        if(input.is_open()) //checking for success of opening file 
         {
        cout<<"File is open!"<<endl;
          }
   else //error check for file opening 
   {
    cout<< "Error! File is not open"<<endl;
   }
   
  }

void filemonth_gen(ofstream& out, Account PA) // file name month generator 
{
const int SIZE = 12;// size for array;
string filename="account_report_";
string array[SIZE]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"}; //array for months

for(int i =  0; i<SIZE;i++) //loop to store months in array 
       {
            if(PA.month==array[i])
            {
               filename += array[i];
               break;
            }
            
       }
    out.open(filename.c_str(),ios::app); //file open to write in

 
       
       
}
void display()//display transactions and account files 
{
 Account PA; //struct 
int account; //input from user
ifstream in; //input file for account txt
ifstream input2,inpu; //input file for transaction txt
ofstream out; //output file
int numberofd=0,numberofd1=0,numberofd2=0,numberofd3=0,numberofd4=0; //number of deposits 
int numberofw=0,numberofw2=0, numberofw3=0,numberofw4=0,numberofw1=0; //number of withdrawals
double deposits=0; // calculation of total depsoit 
double withdrawalz=0; //calculation of total withdrawals
double sum=0; //total for withdrawals
double total=0; //total for deposits 
const int SIZE=5; 
//arrays to extract data from file
int ch[SIZE],bw[SIZE]; 
char wa[SIZE],pa[SIZE],za[SIZE],ea[SIZE],ga[SIZE];
double d[SIZE],da[SIZE],ba[SIZE],pe[SIZE],wq[SIZE];
char aw[SIZE],paw[SIZE],zaw[SIZE],eaw[SIZE],gaw[SIZE];
double dw[SIZE],daw[SIZE],baw[SIZE],pew[SIZE],wqw[SIZE];
openfile1(in);//function call for accounts file
cout<<"Please enter account number"<<endl; 
cin>>PA.account_Number; //user input of account number
while(in>>PA.num>>PA.Name>>PA.balance) //reading information
{
if(PA.num==PA.account_Number) //comparison between user input and file accounts
    {
        cout<<"Your account "<<PA.num<<" has been found!"<<endl;
        cout<<"What month would you like to access? Please type Jan, Feb, Mar, May, Apr, Jun, Jul, Aug, Sep, Oct, Nov, Dec"<<endl;
        cin>>PA.month; //user input for month
        cout<<" You have entered month "<<PA.month<<endl;
        filemonth_gen(out,PA); //output file 


openfile2(input2); //transaction file
int index; //index variable to place different variables in
for( index=0;index<6;index++) //loop to extract data from file into arrays
{
    input2>>ch[index]>>wa[index]>>d[index]>>pa[index]>>da[index]>>za[index]>>ba[index]>>ea[index]>>pe[index]>>ga[index]>>wq[index];
    input2.ignore(' ','\n');
    if(ch[index]==PA.account_Number) //comparing account numbers
    {
    for(index = 0; index<5; index++)
    {
if(ch[index]==PA.account_Number)//comparing account numbers
    {  //if else statments for comparing data to make sure right calculations are made along with counters
        if(wa[index]=='d')
          {
            d[index]=d[index];
            numberofd++;
        }
        else 
            {d[index]=false;
            numberofd=false;
            }
        if(pa[index]=='d')
        {
            da[index]=da[index];
            numberofd1++;
        
        }
        else 
           { da[index]=false;
           numberofd1=false;
           }
       if(za[index]=='d')
       {
        ba[index]=ba[index];
        numberofd2++;
  
        }
        else 
            {za[index]=false;
            numberofd2=false;
            }
       if(ea[index]=='d')
       {
        pe[index]=pe[index];
        numberofd3++;
        
       }
         else 
        {pe[index]=false;
         numberofd3=false;
        }
       if(ga[index]=='d')
       {
        wq[index]=wq[index];
        numberofd4++;
       
       }
        else 
        {wq[index]=false;
        numberofd4=false;
        }
    //while loop to calculate deposits
    while(d[index]==d[index] || da[index]==da[index]||ba[index]==ba[index]||pe[index]==pe[index]||wq[index]==wq[index])
    {
       deposits =d[index]+da[index]+ba[index]+pe[index]+wq[index]; //equation 
        break;
    }
//while loop to calculate number of deposits 
while(numberofd !=false || numberofd1!=false || numberofd2!=false ||numberofd3!=false ||numberofd4 !=false)
{
    sum =numberofd+numberofd1+numberofd2+numberofd3+numberofd4;//equation
    break;
}
    }
    }
    break;
}//end of if statements
}//end of for loop



openfile2(inpu); //opening transaction file again for withdrawals data
int arc;//arc variable to place different variables in
for( arc=0;arc<6;arc++) //loop to extract data from file into arrays
{
    inpu>>bw[arc]>>aw[arc]>>dw[arc]>>paw[arc]>>daw[arc]>>zaw[arc]>>baw[arc]>>eaw[arc]>>pew[arc]>>gaw[arc]>>wqw[arc];
    inpu.ignore(' ','\n');
if(bw[arc]==PA.account_Number)//comparing account numbers
{
for(arc = 0; arc<5; arc++)//extracting data from trans file
{//if else statments for comparing data to make sure right calculations are made along with counters
    if(bw[arc]==PA.account_Number)//comparing account numbers
    {
        {
        if(aw[arc] =='w')
        {
            dw[arc]=dw[arc];
            numberofw++;
         }
        else 
            {dw[arc]=false;
           numberofw=false;
            }
        if(paw[arc]=='w')
        {
            daw[arc]=daw[arc];
           numberofw1++;
        }
        else 
        {daw[arc]=false;
             numberofw1=false;
        }
       if(zaw[arc]=='w')
       {
        baw[arc]=baw[arc];
      numberofw2++;
    }
        else 
          { baw[arc]=false;
            numberofw2=false;
          }
       if(eaw[arc]=='w')
       {
        pew[arc]=pew[arc];
     numberofw3++;
     }
         else 
        { pew[arc]=false;
         numberofw3=false;
        }
       if(gaw[arc]=='w')
       {
        wqw[arc]=wqw[arc];
      numberofw4++;
        }
        else 
       {wqw[arc]=false;
       numberofw4=false;
       }
    //while loop to calculate withdrawals
    while(dw[arc]==dw[arc]||daw[arc]==daw[arc]||baw[arc]==baw[arc]||pew[arc]==pew[arc]||wqw[arc]==wqw[arc])
    {
        withdrawalz=dw[arc]+daw[arc]+baw[arc]+pew[arc]+wqw[arc];//equation

      break;
    }
    //while loop to calculate number of withdrawals
while(numberofw !=false || numberofw1!=false || numberofw2!=false ||numberofw3!=false ||numberofw4 !=false)
{
    total=numberofw+numberofw1+numberofw2+numberofw3+numberofw4;//equations
    break;
}
    }//end of if statment
break;
}//end of for loop
}
}//end of if statment
}//end of for loop
//output data to account report
out<<"Account Number: "<<PA.account_Number<<endl; 
out<<"Name: "<<PA.Name<<endl;
out<< "Beginning Balance: "<<PA.balance<<endl;
out<<"Ending Balance: " <<deposits-withdrawalz+PA.balance<<endl;
out<<"Amount Deposited: "<<deposits<<endl;
out<<"Number of Deposits: "<<sum<<endl;
out<<"Amount Withdrawn: "<<withdrawalz<<endl;
out<<"Number of Withdraws: "<<total<<endl;
       }
        
    }
//closing files
in.close(); 
input2.close();
inpu.close();
out.close();
}


int main()//main func
{
char ch;
do{ //loop to check another account 
display(); //func call to display account report 
cout<<"Would you like to check another account?"<<endl;
cin>>ch;
}while(ch=='Y'||ch=='y');
}