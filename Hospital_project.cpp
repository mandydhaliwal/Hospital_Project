#include<iostream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
using namespace std;
void search();
void add();
void edit();
void doctor(char);
void nurse(char);
void receptionist(char);
class A
{
	public:
		int code;
		char name[30];
		char department[30];char grade[30];

};
class Doctor:public A{
public:
void show(){

	cout<<"Doctor info-"<<endl;
	cout<<"Name: "<<name<<" , Grade: "<<grade<<" , Department: "<<department;
	cout<<" and Code: "<<code<<endl;}
	Doctor(){code=0;

	}
	void get(int c){cout<<endl<<"Name:";cin>>name;
	cout<<"Grade:";cin>>grade;
	cout<<"Department:";cin>>department;code=c;
	}
};
class Nurse:public A{
	public:
	void show(){
cout<<"Nurse info-"<<endl;
	cout<<"Name: "<<name<<" , Grade: "<<grade<<" , Department: "<<department;
	cout<<" and Code: "<<code<<endl;}
	Nurse()
	{code=0;
	}void get(int c){cout<<endl<<"Name";cin>>name;
	cout<<"Grade";cin>>grade;
	cout<<"Department";cin>>department;code=c;
	}
};
class Receptionist:public A{
	public:
		void show(){
cout<<"Receptionist info-"<<endl;
	cout<<"Name: "<<name<<" , Grade: "<<grade<<" , Department: "<<department;
	cout<<" and Code: "<<code<<endl;}
	Receptionist(){code=0;
	}void get(int c){cout<<endl<<"Name";cin>>name;
	cout<<"Grade";cin>>grade;
	cout<<"Department";cin>>department;code=c;
	}
};
int main()
{cout<<"------------------HOSPITAL STAFF DATA MAINTAINENCE PROGRAM-----------------"<<endl;
	int choice;start:
	cout<<"Enter  choice:"<<endl<<"1. Search record"<<endl<<"2. ADD record"<<endl<<"3. Edit record"<<endl;

	    cin>>choice;
	switch(choice)
	{
		case 1: search();
		break;
		case 2: add();
		break;
		case 3: edit();
		break;
		default:cout<<"Wrong choice entered. Enter again:"<<endl;goto start;
	}
	cout<<endl<<"Do you want to start again (y/n) ?";
	char c;
	cin>>c;
	if(c=='y'||c=='Y')goto start;
	return 0;
}

void search()
{cout<<"Search records in:"<<endl<<"1.Doctors"<<endl<<"2.Nurses"<<endl<<"3.Receptionists"<<endl;
int ch;start:
cin>>ch;
switch(ch)
{
case 1:doctor('s');
break;
case 2:nurse('s');
break;
case 3:receptionist('s');
break;
default:cout<<"wrong choice entered.Enter again:"<<endl;goto start;

}
}

void add()
{cout<<"Add records in:"<<endl<<"1.Doctors"<<endl<<"2.Nurses"<<endl<<"3.Receptionists"<<endl;
int ch;start:
cin>>ch;
switch(ch)
{
case 1:doctor('a');
break;
case 2:nurse('a');
break;
case 3:receptionist('a');
break;
default:cout<<"wrong choice entered.Enter again:"<<endl;goto start;}}

void edit()
{cout<<"Edit records in:"<<endl<<"1.Doctors"<<endl<<"2.Nurses"<<endl<<"3.Receptionists"<<endl;
int ch;start:
cin>>ch;
switch(ch)
{
case 1:doctor('e');
break;
case 2:nurse('e');
break;
case 3:receptionist('e');
break;
default:cout<<"wrong choice entered.Enter again:"<<endl;goto start;}}

void doctor(char a)
{
Doctor d;
fstream doc;
doc.open("doc.info", ios::in|ios::out|ios::binary|ios::ate);
if(doc)
    cout<<"File opened"<<endl;
else
    {cout<<"File not opened!"<<endl;return;}
if(a=='s')
{doc.seekg(0,ios::beg);

int code;
cout<<endl<<"Enter code to be searched:";
		cin>>code;

	while(doc.eof()==0)
	{
		doc.read((char*)&d,sizeof(d));
		if(d.code==code)
		{
			cout<<"Result found:"<<endl;
			d.show();
			break;
		}
	}
	if(doc.eof())
        cout<<endl<<"Result not found!"<<endl;
}
if(a=='a')
{
Doctor p;


if(doc.tellg()==0)
	{p.get(1);}
	else
    {
        doc.seekg(doc.tellg()-sizeof(d));

        doc.read((char*)&d,sizeof(d));
        cout<<endl<<"Your code is "<<d.code+1<<endl;
        p.get(d.code+1);
    }
	doc.write((char*)&p,sizeof(p));
	if(doc.fail())
        cout<<"Write fail";
        else
        {
            cout<<endl<<"Successfully added with following record"<<endl;
            p.show();
        }
}
if(a=='e')
{
	doc.seekg(0,ios::beg);

int code;cout<<endl<<"Enter code to be searched:";
		cin>>code;
	while(doc.eof()==0)
	{
		doc.read((char*)&d,sizeof(d));

		if(d.code==code)
		{
			cout<<"Result found:"<<endl;
			d.show();
			cout<<endl<<"Edit details:"<<endl;
			cout<<"Enter name:";
			cin>>d.name;
			cout<<endl<<"Enter department:";
			cin>>d.department;
			cout<<endl<<"Enter grade";
			cin>>d.grade;

			break;

}
}
int n=-1*sizeof(d);
doc.seekg(n,ios::end);
Doctor p;
cout<<endl<<doc.tellg();
doc.read((char*)&p,sizeof(p));
d.code=p.code+1;
doc.write((char*)&d,sizeof(d));
cout<<endl<<"Record successfully edited with new code "<<d.code<<endl;
}
doc.close();
}

void nurse(char a)
{Nurse d;
fstream doc;
doc.open("nurse.info", ios::in|ios::out|ios::binary|ios::ate);
if(doc)
    cout<<"File opened"<<endl;
else
    {cout<<"File not opened!"<<endl;return;}
if(a=='s')
{doc.seekg(0,ios::beg);

int code;
cout<<endl<<"Enter code to be searched:";
		cin>>code;

	while(doc.eof()==0)
	{
		doc.read((char*)&d,sizeof(d));
		if(d.code==code)
		{
			cout<<"Result found:"<<endl;
			d.show();
			break;
		}
	}
	if(doc.eof())
        cout<<endl<<"Result not found!"<<endl;
}
if(a=='a')
{
Nurse p;


if(doc.tellg()==0)
	{p.get(1);}
	else
    {
        doc.seekg(doc.tellg()-sizeof(d));

        doc.read((char*)&d,sizeof(d));
        cout<<endl<<"Your code is "<<d.code+1<<endl;
        p.get(d.code+1);
    }
	doc.write((char*)&p,sizeof(p));
	if(doc.fail())
        cout<<"Write fail";
        else
        {
            cout<<endl<<"Successfully added with following record"<<endl;
            p.show();
        }
}
if(a=='e')
{
	doc.seekg(0,ios::beg);

int code;cout<<endl<<"Enter code to be searched:";
		cin>>code;
	while(doc.eof()==0)
	{
		doc.read((char*)&d,sizeof(d));

		if(d.code==code)
		{
			cout<<"Result found:"<<endl;
			d.show();
			cout<<endl<<"Edit details:"<<endl;
			cout<<"Enter name:";
			cin>>d.name;
			cout<<endl<<"Enter department:";
			cin>>d.department;
			cout<<endl<<"Enter grade";
			cin>>d.grade;

			break;

}
}
int n=-1*sizeof(d);
doc.seekg(n,ios::end);
Nurse p;
cout<<endl<<doc.tellg();
doc.read((char*)&p,sizeof(p));
d.code=p.code+1;
doc.write((char*)&d,sizeof(d));
cout<<endl<<"Record successfully edited with new code "<<d.code<<endl;
}
doc.close();
}

void receptionist(char a)
{Receptionist d;
fstream doc;
doc.open("receptionist.info", ios::in|ios::out|ios::binary|ios::ate);
if(doc)
    cout<<"File opened"<<endl;
else
    {cout<<"File not opened!"<<endl;return;}
if(a=='s')
{doc.seekg(0,ios::beg);

int code;
cout<<endl<<"Enter code to be searched:";
		cin>>code;

	while(doc.eof()==0)
	{
		doc.read((char*)&d,sizeof(d));
		if(d.code==code)
		{
			cout<<"Result found:"<<endl;
			d.show();
			break;
		}
	}
	if(doc.eof())
        cout<<endl<<"Result not found!"<<endl;
}
if(a=='a')
{
Receptionist p;


if(doc.tellg()==0)
	{p.get(1);}
	else
    {
        doc.seekg(doc.tellg()-sizeof(d));

        doc.read((char*)&d,sizeof(d));
        cout<<endl<<"Your code is "<<d.code+1<<endl;
        p.get(d.code+1);
    }
	doc.write((char*)&p,sizeof(p));
	if(doc.fail())
        cout<<"Write fail";
        else
        {
            cout<<endl<<"Successfully added with following record"<<endl;
            p.show();
        }
}
if(a=='e')
{
	doc.seekg(0,ios::beg);

int code;cout<<endl<<"Enter code to be searched:";
		cin>>code;
	while(doc.eof()==0)
	{
		doc.read((char*)&d,sizeof(d));

		if(d.code==code)
		{
			cout<<"Result found:"<<endl;
			d.show();
			cout<<endl<<"Edit details:"<<endl;
			cout<<"Enter name:";
			cin>>d.name;
			cout<<endl<<"Enter department:";
			cin>>d.department;
			cout<<endl<<"Enter grade";
			cin>>d.grade;

			break;

}
}
int n=-1*sizeof(d);
doc.seekg(n,ios::end);
Receptionist p;
cout<<endl<<doc.tellg();
doc.read((char*)&p,sizeof(p));
d.code=p.code+1;
doc.write((char*)&d,sizeof(d));
cout<<endl<<"Record successfully edited with new code "<<d.code<<endl;
}
doc.close();
}
