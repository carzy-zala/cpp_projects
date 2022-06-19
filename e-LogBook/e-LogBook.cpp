//This code is made by ZALA
 
#include <bits/stdc++.h>


using namespace std;

void mainu();

// class Log-Book
class LogBook{

    private:
    
    string date,work,time;
    int noOFTask;
    

    public:

    string getdate()  //getter of date
    {
       return date;
    }

    void creatLog()  //function creating log entry
    {
     
        system("cls");
        string st;
        cout<<"Enter a date[dd-mm-yyyy] of log ....: ";
        cin>>this->date;
        cin.sync();
        cout<<"Enter a time[hh:mm-AM/PM] of work...:";
        cin>>this->time;
        cout<<"Enter work you done ...:";
        cin>>this->work;
    }

    void display()    //display function
    {
        cout<<endl<<"Date:"<<this->date<<endl<<endl;
        cout<<"Time\t\t\t"<<"Work Done\n";               
        cout<<this->time<<"\t\t"<<this->work;
        cout<<"\n";
    }
}lb;

//creating new log
void addNewLog()
{
   fstream op("e-LogBook.txt",ios::app|ios::in|ios::out);
   lb.creatLog();
   op.write((char*)&lb,sizeof(lb));
   op.close();
}

//displaying logbook
void displayLogbook()
{
    fstream op("e-LogBook.txt");
    op.read((char*)&lb,sizeof(lb));
    while(!op.eof())
    {
    lb.display();
    op.read((char*)&lb,sizeof(lb));
    cout<<endl;
    }
    op.close();

}

//searching log of particular date
void SearchLogOfDate()
{
  int flag=0;
  string date;
  cout<<"Enter a date of which you want to delete a log ...:";
  cin>>date;
  fstream op("e-LogBook.txt");
  while(!op.eof())
    {
    op.read((char*)&lb,sizeof(lb));

    if(date==lb.getdate())
      {
        flag=1;
        cout<<endl<<endl<<"Your Log of date found"<<endl<<endl;
        lb.display();
        break;
      }
    }
     if(flag==0)
        cout<<"Log on this particular date doesn't exist...."<<endl;
     op.close();
}

//choice function
void choice(int k)
{
  switch(k)
  {
      case 1:addNewLog();
             break;
      case 2:displayLogbook();
             break;
      case 3:SearchLogOfDate();
             break;
      case 4: 
               exit(0);
      default:cout<<"Enter a wrong choice...:\n";
    
  }
  cin.sync();
  cout<<"You want more action [Y/N]..: ";
  char c;
  cin.sync();
  cin>>c;
  if(c=='y' || c=='Y')
  {
      mainu();
  }
  else
     exit(0);
}

//mainu
void mainu()
{
    int j;
    system("cls");
    cout<<setw(90)<<"These are the services we providing to you.........\n\n\n";
    cout<<setw(69)<<"1.Add New Log Of Day\n";
    cout<<setw(68)<<"2.View Exciting Log\n";
    cout<<setw(72)<<"3.Search Particular Log\n";
    cout<<setw(63)<<"4.Exit\n\n\n\n\n\n\n\n\n";
    cout<<"Enter your choice..........:";
    cin>>j;
    choice(j);

}

// greating function
void greeting()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t*****************************************\n";
    cout<<"\t\t\t\tWelcome\n";
    cout<<"\t\t*****************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    system("pause");
}

int main()
{
    greeting();
    mainu();
    return 0;
}