#pragma once
#include <iostream>
#include <string>
using namespace std;

#define MAX_PERSON 1000

struct Person
{
	string m_Name;
	string m_Gender;
	int m_Age;
	string m_Address;
	string m_Phone;

};
struct Addressbook
{
	Person addressList[MAX_PERSON];
	int m_Size=0;

};


void showMenu();
void addContact(Addressbook *contact);
void showContact(Addressbook *contact);
int isExist(Addressbook* contact, string name);
void deleteContact(Addressbook* contact);
void findContact(Addressbook* contact);
void modifyContact(Addressbook* contact);
void clearContact(Addressbook* contact);