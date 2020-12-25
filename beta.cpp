/*
 * Name:		Mohammed Kamal-Aldeen Othman
 * Class:		2nd Class
 * Department:	Computer Engineering
*/

#include <iostream>
#include <string>

using namespace std;
class contact{
	private:
		string name, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, family, phone, gender, email, address, website;
	public:
		contact *next;
		contact(){
		};
		contact(string name, string givenname, string additionalname, string yominame, string givennameyomi, string additionalnameyomi, string familynameyomi, string shortname, string nickname, string namesuffix, string nameprefix, string maidenname, string birthday, string initials, string sensitivity, string priority, string mileage, string dirserver, string occup, string hobby, string subject, string notes, string language, string billing, string family, string phone, string gender, string email, string address, string website){
			this -> name = name; this -> givenname = givenname; this -> additionalname = additionalname; this -> yominame = yominame; this -> givennameyomi = givennameyomi; this -> additionalnameyomi = additionalnameyomi; this -> familynameyomi = familynameyomi; this -> shortname = shortname; this -> nickname = nickname; this -> namesuffix = namesuffix; this -> nameprefix = nameprefix; this -> maidenname = maidenname; this -> birthday = birthday; this -> initials = initials; this -> sensitivity = sensitivity; this -> priority = priority; this -> mileage = mileage; this -> dirserver = dirserver; this -> occup = occup; this -> hobby = hobby; this -> subject = subject; this -> notes = notes; this -> language = language; this -> billing = billing; this -> family = family; this -> phone = phone; this -> gender = gender; this -> email = email; this -> address = address; this -> website = website;
		}
		string getName(){
			return name;
		}
		string getGivenName(){
			return givenname;
		}
		string getAdditionalName(){
			return additionalname;
		}
		string getYomiName(){
			return yominame;
		}
		string getGivenNameYomi(){
			return givennameyomi;
		}
		string getAdditionalNameYomi(){
			return additionalnameyomi;
		}
		string getFamilyNameYomi(){
			return familynameyomi;
		}
		string getShortName(){
			return shortname;
		}
		string getNickName(){
			return nickname;
		}
		string getNameSuffix(){
			return namesuffix;
		}
		string getNamePrefix(){
			return nameprefix;
		}
		string getMaidenName(){
			return maidenname;
		}
		string getBirthday(){
			return birthday;
		}
		string getInitials(){
			return initials;
		}
		string getSensitivity(){
			return sensitivity;
		}
		string getPriority(){
			return priority;
		}
		string getMileage(){
			return mileage;
		}
		string getDirServer(){
			return dirserver;
		}
		string getOccupation(){
			return occup;
		}
		string getHobby(){
			return hobby;
		}
		string getSubject(){
			return subject;
		}
		string getNotes(){
			return notes;
		}
		string getLanguage(){
			return language;
		}
		string getBilling(){
			return billing;
		}
		string getFamily(){
			return family;
		}
		string getPhone(){
			return phone;
		}
		string getGender(){
			return gender;
		}
		string getEmail(){
			return email;
		}
		string getAddress(){
			return address;
		}
		string getWebsite(){
			return website;
		}
		void setContact(string name, string givenname, string additionalname, string yominame, string givennameyomi, string additionalnameyomi, string familynameyomi, string shortname, string nickname, string namesuffix, string nameprefix, string maidenname, string birthday, string initials, string sensitivity, string priority, string mileage, string dirserver, string occup, string hobby, string subject, string notes, string language, string billing, string family, string phone, string gender, string email, string address, string website){
			this -> name = name; this -> givenname = givenname; this -> additionalname = additionalname; this -> yominame = yominame; this -> givennameyomi = givennameyomi; this -> additionalnameyomi = additionalnameyomi; this -> familynameyomi = familynameyomi; this -> shortname = shortname; this -> nickname = nickname; this -> namesuffix = namesuffix; this -> nameprefix = nameprefix; this -> maidenname = maidenname; this -> birthday = birthday; this -> initials = initials; this -> sensitivity = sensitivity; this -> priority = priority; this -> mileage = mileage; this -> dirserver = dirserver; this -> occup = occup; this -> hobby = hobby; this -> subject = subject; this -> notes = notes; this -> language = language; this -> billing = billing; this -> family = family; this -> phone = phone; this -> gender = gender; this -> email = email; this -> address = address; this -> website = website;
		}
		void getContact(){
			cout << name << "   " << givenname << "   " << additionalname << "   " << yominame << "   " << additionalnameyomi << "   " << givennameyomi << "   " << familynameyomi << "   " << nameprefix << "   " << namesuffix << "   " << maidenname << "   " << shortname << "   " << nickname << "   " << birthday << "   " << language << "   " << initials << "   " << dirserver << "   " << billing << "   " << sensitivity << "   " << priority << "   " << subject << "   " << notes << "   " << hobby << "   " << occup << "   " << mileage << "   " << family << "   " << phone << "   " << address << "   " << gender << "   " << email << endl;
		}
};
class contactsList{
	private:
		contact *head;
		contact *last;
		int size;
	public:
		contactsList();
		contact* find(string);
		void add(string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string);
		void deleteContact(string);
		contact* findContact(string);
		void showContacts();
};
contactsList::contactsList(){
	head = NULL ; last = NULL; size = 0;
}
void contactsList::add(string name, string givenname, string additionalname, string yominame, string givennameyomi, string additionalnameyomi, string familynameyomi, string shortname, string nickname, string namesuffix, string nameprefix, string maidenname, string birthday, string initials, string sensitivity, string priority, string mileage, string dirserver, string occup, string hobby, string subject, string notes, string language, string billing, string family, string phone, string gender, string email, string address, string website){
	contact* new_contact = new contact(name, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, family, phone, gender, email, address, website);
	if (last == NULL || head == NULL){
		head = new_contact;
		last = new_contact;
	}
	else {
		new_contact -> next = head;
		head = new_contact;
	}
	size++;
}
contact* contactsList::find(string serachQuery ){
	contact* n = NULL;
	for( n = head ; n != NULL ; n = n->next)
		if (n -> getName() == serachQuery || n -> getAdditionalName() == serachQuery || n -> getMaidenName() == serachQuery || n -> getShortName() == serachQuery || n -> getNickName() == serachQuery || n -> getYomiName() == serachQuery || n -> getFamilyNameYomi() == serachQuery || n -> getAdditionalNameYomi() == serachQuery || n -> getGivenName() == serachQuery || n -> getGivenNameYomi() == serachQuery || n -> getInitials() == serachQuery || n -> getBirthday() == serachQuery || n -> getOccupation() == serachQuery || n -> getNameSuffix() == serachQuery || n -> getNamePrefix() == serachQuery || n -> getDirServer() == serachQuery || n -> getMileage() == serachQuery || n -> getHobby() == serachQuery || n -> getLanguage() == serachQuery || n -> getNotes() == serachQuery || n -> getSubject() == serachQuery || n -> getPriority() == serachQuery || n -> getSensitivity() == serachQuery || n -> getFamily() == serachQuery || ( n -> getName() + " " + n -> getFamily() ) == serachQuery || n -> getEmail() == serachQuery || n -> getAddress() == serachQuery || n -> getGender() == serachQuery) {
			return n;
		}
	return n;
}
contact* contactsList::findContact(string serachQuery){
	contact* f = find(serachQuery);
	if (f == NULL){
		cout << "\n\nNot found!" << endl;
	}
	else {
		cout << "\n\n------------------------------------" << endl;
		f -> getContact();
		cout << "-----------------------------------" << endl;
	}
	return f;
}
void contactsList::deleteContact(string serachQuery){
	if( head->getName() == serachQuery || head->getFamily() == serachQuery || ( head->getName() + " " + head->getFamily() ) == serachQuery )  {
		contact* temp = head->next;
		delete head;
		head = temp;
		size--;
		return;
	}
	contact* temp = head;
	if( temp->next == NULL ){
		 cout << "\n\nNot found!" << endl;
		 return;
	}
	while(temp -> next -> getName() != serachQuery && temp -> next -> getFamily() != serachQuery && ( head -> getName() + " " + head -> getFamily() ) != serachQuery && temp != NULL ){ 
		temp = temp -> next;
		if ( temp -> next == NULL ) {
			 cout << "\n\nNot found!" << endl;
			 return;
		};
	}
    if(temp != NULL){
	contact* temp2 = temp -> next;
	temp -> next = temp2 -> next;
	delete temp2;
	if( last -> getName() == serachQuery || last -> getFamily() == serachQuery || ( last->getName() + " " + last->getFamily() ) == serachQuery ) {
		last = temp;
	}
	size--;
	}
}
void contactsList::showContacts(){
	cout << "\n\n" << endl;
	if (last == NULL || head == NULL){
		throw "No contacts!";
	}
	int l = 1;
	for (contact* n = head; n != NULL ; n = n -> next) {
		cout << l << ") "; l++;
		n -> getContact();
		cout << "-------------------------------------------\n\n" << endl;
	}
};
contact* f;
bool menu();
int main(){
	int n;
	string name, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, family, phone, gender, email, address, website, search;
	contactsList a;
	while(menu()){
		cout << "\nYor choice: ";
		cin >> n;
		switch(n){
			case 1:
				cout << "\nName: ";
				cin >> name;
				cout << "Given Name: ";
				cin >> givenname;
				cout << "Additional Name: ";
				cin >> additionalname;
				cout << "Yomi Name: ";
				cin >> yominame;
				cout << "Given Name Yomi: ";
				cin >> givennameyomi;
				cout << "Family Name Yomi: ";
				cin >> familynameyomi;
				cout << "Additional Name Yomi: ";
				cin >> additionalnameyomi;
				cout << "Short Name: ";
				cin >> shortname;
				cout << "Nick Name: ";
				cin >> nickname;
				cout << "Name Suffix: ";
				cin >> namesuffix;
				cout << "Name Prefix: ";
				cin >> nameprefix;
				cout << "Maiden Name: ";
				cin >> maidenname;
				cout << "Birthday: ";
				cin >> birthday;
				cout << "Initials: ";
				cin >> initials;
				cout << "Sensitivity: ";
				cin >> sensitivity;
				cout << "Priority: ";
				cin >> priority;
				cout << "Mileage: ";
				cin >> mileage;
				cout << "Directory Server: ";
				cin >> dirserver;
				cout << "Occupation: ";
				cin >> occup;
				cout << "Hobby: ";
				cin >> hobby;
				cout << "Subject: ";
				cin >> subject;
				cout << "Notes: ";
				cin >> notes;
				cout << "Language: ";
				cin >> language;
				cout << "Billing: ";
				cin >> billing;
				cout << "Family: ";
				cin >> family;
				cout << "Phone: ";
				cin >> phone;
				cout << "Gender: ";
				cin >> gender;
				cout << "E-Mail: ";
				cin >> email;
				cout << "Address: ";
				cin >> address;
				cout << "Website: ";
				cin >> website;
				a.add(name, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, family, phone, gender, email, address, website);
				break;
			case 2:
				a.showContacts();
				break;
			case 3:
				cout << "\nSearch a Contact Using any Term: ";
				cin >> search;
				f = a.findContact(search);
				break;
			case 4:
				cout << "\nName (And / Or Family Name) of the Contact to Delete: ";
				cin >> search;
				a.deleteContact(search);
				break;
//			case 5:
//				
			case 6:
				exit(1);
			default:
				break;
		}
	}
	return 0;
}
bool menu(){
	cout << "\n\nMain Menu:" << endl;
	cout << "==========" << endl;
	cout << "\n\n1- Add a Contact" << endl;
	cout << "2- Show Contacts" << endl;
	cout << "3- Search a Contact" << endl;
	cout << "4- Delete a Contact" << endl;
	cout << "{coming soon ...} 5- Merge Two Contacts" << endl;
	cout << "6- Exit" << endl;
	cout << "==============================\n" << endl;
	return true;
}
