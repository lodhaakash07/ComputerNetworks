/*
 * Akash Lodha
 * 08/08/2014 (dd/mm/yyyy)
 * Computer Networks - Vit University
 * Program - Cpp simulation of Go Back N ARQ
 */

 // No object oriented comcept is used, its a simple cpp simulation for understanding the concept

 /*
  * Input - Data as string , frame size from user , error position from user
  * It is not checked if valid error position is entered by the user
  * IF invalid program behaves aribitarily
  * most assumptions mentioned in the codes
  * We assume user can enter the error at only one place in frame
  */



#include<iostream>
#include<string>
using namespace std;

string sender(void);
int receiver(string ,int);

int main(void)
    {
    sender();
    }

string sender()
    {
    cout<<"Enter the data :- ";
    string data;
    cin>>data;
    int len = data.length();

    // Get the frame size
    int frame;
    cout<<"ENter the frame size:-";
    cin>>frame;

    // We will ask the user for ech frame if error has to be introduced

    for(int i=0;i<data.length();) {
        // WE have to send frame size data to the receiver
        // Data is send frame my fame
        // However here we send the data at one for simulation convinience

        // Check out of bounce condition
        string to_send;
        if(i+frame >= data.length())    to_send = data.substr(i,data.length()-i);
        else to_send = data.substr(i,frame);

        cout<<" DAta to be sent is :- "<<to_send<<endl;
        // Ask the user if error is to be introduced
        cout<<"For introducing error enter 1, else any character"<<endl;
        int e;
        cin>>e;
        // If the user introduces an error
        if( e == 1 ) {
            // Simply reusing variable a here
            cout<<"Enter the position "<<endl;
            cin>>e;
            e = receiver(to_send,e);
            // If a eror occurs the frames after the error position has to be sent again
            i = i + e-1;
            }
        // If the user doesnot include any error
        else {
            e = receiver(to_send,-1);
            i = i + frame ;
            }
        }

    }

int receiver(string data, int a)
    {
    cout<<"------------------------Receiver()"<<endl;
    //Error represented as E

    // If there are some errors in the data
    if(a!=-1){
        cout<<"-ve acknowledment sent for frame after "<<(a-1)<<endl;
        cout<<"Data Received - "<<data.substr(0,a-1)<<"E"<<data.substr(a,data.length()-a)<<endl;
        cout<<"Valid Data:- "<<data.substr(0,a-1)<<endl;
        }
    // else if the data is received correctly
    else {
        cout<<"Data Received: "<<data<<endl;
        cout<<"All frames send +ve acknowledment"<<endl;
        }
    cout<<"----------------------------------"<<endl;
    return a;
    }
