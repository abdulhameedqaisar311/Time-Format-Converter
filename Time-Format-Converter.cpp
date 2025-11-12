#include <iostream>
#include <string>
#include <cctype>

using namespace std;
void convert_to_12_hour(int hour,int minute)
{
    string period;
    if(hour==0)
    {
        hour=12;
        period="AM";
    }
    else if(hour==12)
    {
        period="PM";
    }
    else if(hour>12)
    {
        hour=hour-12;
        period="PM";
    }
    else
    {
        period="AM";
    }
    cout<<"Time in 12 hours notation is : ";
    cout<<hour<<" : ";
    if(minute<10)
        cout<<"0";
    cout<<minute<<" "<<period;

}
void convert_to_24_hour(int hour,int minute)
{
    string period;
    cout<<"Enter AM/PM: ";
    cin>>period;
    if(period=="AM")
    {
        if(hour==12)
            hour=0;
    }
    else if(period=="PM")
    {
        if(hour!=12)
            hour=hour+12;
    }
    cout<<"Time in 24 hours notation is : ";
    if(hour<10)
        cout<<"0";
    cout<<hour<<" : ";
    if(minute<10)
        cout<<"0";
    cout<<minute;
}
void get_time(int &hour,int &minute)
{
    cout<<"Enter Hours: ";
    cin>>hour;
    cout<<"Enter Minutes: ";
    cin>>minute;
}
void menu()
{
   cout<<"Enter 'A' for conversion from 24 hours to 12 hours notation"<<endl;
   cout<<"Enter 'B' for conversion from 12 hours to 24 hours notation\n";
}

int main()
{
    int hours,minutes;
    char choice,again;

    do
    {
     menu();
     cout<<"Enter Your Choice: ";
     cin>>choice;
     choice=toupper(choice);
        if(choice=='A')
        {
            cout<<"You have chosen the conversion from 24 hours to 12 hours notation"<<endl;
            get_time(hours,minutes);
            convert_to_12_hour(hours,minutes);
        }
        else if(choice=='B')
        {
            cout<<"You have chosen the conversion from 12 hours to 24 hours notation"<<endl;
            get_time(hours,minutes);
            convert_to_24_hour(hours,minutes);
        }
        else
        {
            cout<<"Invalid Choice! Enter A or B "<<endl;
        }
        cout<<"\nDo you want to perform another conversion, Enter 'Y',(Enter 'N' for Quit): ";
        cin>>again;
        again=toupper(again);
    }while(again=='Y');

}
