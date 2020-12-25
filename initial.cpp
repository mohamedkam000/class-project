/*
 * Name:	Mohammed Kamal-Aldeen Othman
 * Class:	2nd Class
 * Department:	Computer Engineering
*/

#include <iostream>
#include <string>
using namespace std;
class contact {
	private:
		string name, phone;
	public:
		contact *next;
		contact() {
		};
		contact(string name, string phone) {
			this -> name = name ; this -> phone = phone; next = NULL;
		}
		string getName() {
			return name;
		}
		string getPhone() {
			return phone;
		}
		void setContact(string name, string phone) {
			this -> name = name; this -> phone = phone ;
		}
		void getContact() {
			cout << name << "   " << phone << endl;
		}
};
class contactsList {
	private:
		contact *head;
		contact *last;
		int size;
	public:
		contactsList();
		void addBegin(string, string);
		void showContacts();
	};
contactsList::contactsList() {
	head = NULL ; last = NULL; size = 0;
}
void contactsList::addBegin(string name, string phone) {
	contact* new_contact = new contact(name , phone);
	if (last == NULL || head == NULL) {
		head = new_contact;
		last = new_contact;
	}
	else {
		new_contact -> next = head;
		head = new_contact;
	}
	size++;
}
void contactsList::showContacts() {
	cout << "\n\n" << endl;
	if (last == NULL || head == NULL) {
		throw "No contacts!";
	}
	int l = 1;
	for (contact* n = head ; n != NULL ; n = n -> next) {
		cout << l << ") "; l++;
		n -> getContact();
		cout << "-------------------------------------------\n\n" << endl;
	}
};
bool menu();
int main() {
	int n;
	string name, phone;
	contactsList a;
	while(menu()) {
		cout << "Yor choice: ";
		cin >> n;
		switch(n) {
			case 1:
				cout << "\nName: ";
				cin >> name;
				cout << "Phone: ";
				cin >> phone;
				a.addBegin(name,phone);
				break;
			case 2:
				a.showContacts();
				break;
			default:
				break;
		}
	}
	return 0;
}
bool menu() {
	cout << "\n\nMain Menu:" << endl;
	cout << "=========" << endl;
	cout << "\n\n1- Add" << endl;
	cout << "2- Show\n" << endl;
	cout << "==============================" << endl;
	return true;
}
