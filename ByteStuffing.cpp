/*
 * Akash Lodha
 * 01/08/2014 (dd/mm/yyyy)
 * Computer Networks - Vit University
 * Program - Cpp simulation of ByteStuffing
 */

 // No object oriented comcept is used, its a simple cpp simulation for understanding the concept

 /*
  * Input - Data as string
  * Output - a) Message after byte stuffing sent to the receiver
  * 		 b) The decoded message
  * More importance given to readability, not running time
  */

// Note flag variable taken as f
// 		esc variable taken as e
// Header and trailer are ignored

#include<iostream>
#include<string>
using namespace std;

string sender();
void receiver(string);

const char flag = 'f';
const char esc = 'e';
int main()
	{
	string data = sender();
	receiver(data);
	}

string sender()
	{
	string data;
	cout<<"Enter the data:";
	cin>>data;

	// Add flag variables to the start and end of the data
	data = flag + data + flag;
	int len = data.length();
	// Wherever flag or escape character is encountered in the message add escape character one position before that
	// Except for the initial and final position
	for(int i=1;i<len;i++)
		{
		if((data[i] == 'f' || data[i] == 'e') && i!=len-1){
			data = data.substr(0,i-1) + "e" + data.substr(i++,len-i);
			// Uncomment below statement to see how the bute is stuffed - step by step
			//cout<<data<<endl;
			len = data.length();
			}
		}
	cout<<"Sent data:"<<data<<endl;
	return data;
	}

void receiver(string data)
	{

	//lets remove the flag bits
	data = data.substr(1,data.length()-2);
	int len = data.length();
	for(int i=0;i<len-1;i++)
		{
		if(data[i]=='e' && (data[i+1] == 'f' || data[i+1] == 'e')){
			string t = data.substr(0,i) ;
			data = t +  data.substr(i+1,len-t.length()+2);
			// Uncomment below statement to see how the stuffted byte is decoded - step by step
			//cout<<data<<endl;
			len = data.length();
			}
		}
	cout<<"Decoded message : "<<data;
	}
