/*
 * Akash Lodha
 * 08/08/2014 (dd/mm/yyyy)
 * Computer Networks - Vit University
 * Program - Cpp simulation of Encoding Algorithms NRZ, NRZI , Manchester
 */

 // No object oriented comcept is used, its a simple cpp simulation for understanding the concept

 /*
  * Input - Data as string
  * Output - Timing diagram of the various encoding algorithms
  * More importance given to readability, not running time
  */



#include<iostream>
#include<string>
using namespace std;

int main(void)
    {
    string data;
    cout<<"Enter the data:-  ";
    cin>>data;
    int len = data.length();

    // Lets first print the clock signal
    for(int i=0;i<len;i++)  cout<<"_-";

    // NRZ Algorithm
    // In NRZ algorithm we represent each 0 by __ and each 1 by --
    cout<<endl<<endl<<"NRZ Encoding"<<endl<<endl;
    for(int i=0;i<len;i++){
        if( data[i] == '0' ) cout<<"__";
        else    cout <<"--";
        }
    cout<<endl<<endl<<"NRZI"<<endl<<endl;

    // NRZI Algorithm
    // In NRZi algorithm whenever 1 occurs output changes (if low, then to high, else if high, then to low)
    string nrzi="";
    for(int i=0; i<len ; i++)
        {
        // When i=0 there is no previous position to check from
        // Out of Bounce error
        // So we have seperate condition for then
        // Better to put this condtition outside of loop, so that its not checked with every i
        if( i==0 ){
            if( data[i] == '0') nrzi+= "__";
            else nrzi+="_-";
            }
        else if( data[i] == '0' ) {
            if( nrzi[i*2-1] == '_') nrzi += "__";
            else nrzi += "--";
            }

        else if ( data[i] == '1' ) {
            if( nrzi[i*2-1] == '_') nrzi += "_-";
            else nrzi += "-_";
            }
        cout<<nrzi.substr(i*2,2);
        }

    cout<<endl<<endl<<"Manchester"<<endl<<endl;

    // MAnchester
    // For manchester if 1 - -_
    //                if 0 - _-

    for(int i=0; i<len; i++) {
        if( data[i] == '0' ) cout<<"_-";
        else cout<<"-_";
        }
    }
