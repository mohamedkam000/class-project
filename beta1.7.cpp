/*
 * Name:		Mohammed Kamal-Aldeen Othman
 * Class:		2nd Class
 * Department:	Computer Engineering
*/

#include <iostream>
#include <string>

using namespace std;
class conan{
	private:
		string name1, family1, phone1;
	public:
		conan *next1;
		conan(){
		};
		conan(string name1, string family1, string phone1){
			this -> name1 = name1; this -> family1 = family1; this -> phone1 = phone1;
		}
		string gn(){
			return name1;
		}
		string gf(){
			return family1;
		}
		string gp(){
			return phone1;
		}
		void Con(string name1, string family1, string phone1){
			this -> name1 = name1; this -> family1 = family1; this -> phone1 = phone1;
		}
		void Cona(){
			cout << name1 << "   " << family1 << "   " << phone1 << endl;
		}
};
class conly{
	private:
		conan *head1;
		conan *last1;
		int size1;
	public:
		conly();
		conan* fo(string);
		void add1(string,string,string);
		void dCon(string);
		conan* fCon(string);
		void sCon();
};
conly::conly(){
	head1 = NULL ; last1 = NULL; size1 = 0;
}
void conly::add1(string name1, string family1, string phone1){
	conan* new_conan = new conan(name1, family1, phone1);
	if (last1 == NULL || head1 == NULL){
		head1 = new_conan;
		last1 = new_conan;
	}
	else {
		new_conan -> next1 = head1;
		head1 = new_conan;
	}
	size1++;
}
conan* conly::fo(string ser){
	conan* x = NULL;
	for( x = head1 ; x != NULL ; x = x -> next1)
		if (x -> gn() == ser || x -> gp() == ser || x -> gf() == ser || ( x -> gn() + " " + x -> gf() ) == ser) {
			return x;
		}
	return x;
}
conan* conly::fCon(string ser){
	conan* z = fo(ser);
	if (z == NULL){
		cout << "\n\nNot found!" << endl;
	}
	else {
		cout << "\n\n------------------------------------" << endl;
		z -> Cona();
		cout << "-----------------------------------" << endl;
	}
	return z;
}
void conly::dCon(string ser){
	if (head1 -> gn() == ser || head1 -> gf() == ser || (head1 -> gn() + " " + head1 -> gf()) == ser) {
		conan* temp1 = head1 -> next1;
		delete head1;
		head1 = temp1;
		size1--;
		return;
	}
	conan* temp1 = head1;
	if (temp1 -> next1 == NULL) {
		 cout << "\n\nNot found!" << endl;
		 return;
	}
	while(temp1 -> next1 -> gn() != ser && temp1 -> next1 -> gf() != ser && (head1 -> gf() + " " + head1 -> gf()) != ser && temp1 != NULL){ 
		temp1 = temp1 -> next1;
		if ( temp1 -> next1 == NULL ) {
			 cout << "\n\nNot found!" << endl;
			 return;
		};
	}
    if(temp1 != NULL){
	conan* temp3 = temp1 -> next1;
	temp1 -> next1 = temp3 -> next1;
	delete temp3;
	if( last1 -> gn() == ser || last1 -> gf() == ser || ( last1->gn() + " " + last1->gf() ) == ser ) {
		last1 = temp1;
	}
	size1--;
	}
}
void conly::sCon(){
	cout << "\n\n" << endl;
	if (last1 == NULL || head1 == NULL){
		throw "No contacts!";
	}
	int j = 1;
	for (conan* x = head1; x != NULL ; x = x -> next1) {
		cout << j << ") "; j++;
		x -> Cona();
		cout << "-------------------------------------------\n\n" << endl;
	}
};
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
	if (head->getName() == serachQuery || head -> getAdditionalName() == serachQuery || head -> getMaidenName() == serachQuery || head -> getShortName() == serachQuery || head -> getNickName() == serachQuery || head -> getYomiName() == serachQuery || head -> getFamilyNameYomi() == serachQuery || head -> getAdditionalNameYomi() == serachQuery || head -> getGivenName() == serachQuery || head -> getGivenNameYomi() == serachQuery || head -> getInitials() == serachQuery || head -> getBirthday() == serachQuery || head -> getOccupation() == serachQuery || head -> getNameSuffix() == serachQuery || head -> getNamePrefix() == serachQuery || head -> getDirServer() == serachQuery || head -> getMileage() == serachQuery || head -> getHobby() == serachQuery || head -> getLanguage() == serachQuery || head -> getNotes() == serachQuery || head -> getSubject() == serachQuery || head -> getPriority() == serachQuery || head -> getSensitivity() == serachQuery || head -> getEmail() == serachQuery || head -> getAddress() == serachQuery || head -> getGender() == serachQuery || head->getFamily() == serachQuery || (head->getName() + " " + head->getFamily()) == serachQuery) {
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
	while(temp -> next -> getLanguage() != serachQuery && temp -> next -> getShortName() != serachQuery && temp -> next -> getSubject() != serachQuery && temp -> next -> getFamilyNameYomi() != serachQuery && temp -> next -> getGender() != serachQuery && temp -> next -> getGivenName() != serachQuery && temp -> next -> getInitials() != serachQuery && temp -> next -> getPhone() != serachQuery && temp -> next -> getPriority() != serachQuery && temp -> next -> getSensitivity() != serachQuery && temp -> next -> getYomiName() != serachQuery && temp -> next -> getEmail() != serachQuery && temp -> next -> getName() != serachQuery && temp -> next -> getWebsite() != serachQuery && temp -> next -> getNotes() != serachQuery && temp -> next -> getNickName() != serachQuery && temp -> next -> getMileage() != serachQuery && temp -> next -> getMaidenName() != serachQuery && temp -> next -> getAddress() != serachQuery && temp -> next -> getAdditionalNameYomi() != serachQuery && temp -> next -> getAdditionalName() != serachQuery && temp -> next -> getBirthday() != serachQuery && temp -> next -> getBilling() != serachQuery && temp -> next -> getOccupation() != serachQuery && temp -> next -> getNameSuffix() != serachQuery && temp -> next -> getNamePrefix() != serachQuery && temp -> next -> getDirServer() != serachQuery && temp -> next -> getHobby() != serachQuery && temp -> next -> getFamily() != serachQuery && ( head -> getName() + " " + head -> getFamily() ) != serachQuery && temp != NULL ){ 
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
	if (last -> getName() == serachQuery || last -> getAdditionalName() == serachQuery || last -> getMaidenName() == serachQuery || last -> getShortName() == serachQuery || last -> getNickName() == serachQuery || last -> getYomiName() == serachQuery || last -> getFamilyNameYomi() == serachQuery || last -> getAdditionalNameYomi() == serachQuery || last -> getGivenName() == serachQuery || last -> getGivenNameYomi() == serachQuery || last -> getInitials() == serachQuery || last -> getBirthday() == serachQuery || last -> getOccupation() == serachQuery || last -> getNameSuffix() == serachQuery || last -> getNamePrefix() == serachQuery || last -> getDirServer() == serachQuery || last -> getMileage() == serachQuery || last -> getHobby() == serachQuery || last -> getLanguage() == serachQuery || last -> getNotes() == serachQuery || last -> getSubject() == serachQuery || last -> getPriority() == serachQuery || last -> getSensitivity() == serachQuery || last -> getEmail() == serachQuery || last -> getAddress() == serachQuery || last -> getGender() == serachQuery || last->getFamily() == serachQuery || (last->getName() + " " + last->getFamily()) == serachQuery) {
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
conan* z;
contact* f;
bool menu();
int main(){
	int n, con, sery, sho, de;
	string name1, family1, phone1, name, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, family, phone, gender, email, address, website, search, search1;
	contactsList a;
	conly b;
	while(menu()){
		cout << "\nYor choice: ";
		cin >> n;
		switch(n){
			case 1:
				loop:
				cout << "\n1- Simple" << endl;
				cout << "2- Advanced" << endl;
				cout << "============\n" << endl;
				cout << "Your choice: ";
				cin >> con;
				if (con == 1) {
					cout << "\nName: ";
					cin >> name1;
					cout << "Family: ";
					cin >> family1;
					cout << "Phone: ";
					cin >> phone1;
					b.add1(name1,family1,phone1);
				}
				else if (con == 2) {
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
				}
				else {
					cout << "\nAh please, this trick won't work anymore :|" << endl;
					goto loop;
				}
				break;
			case 2:
				loop1:
				cout << "\n1- Simple" << endl;
				cout << "2- Advanced" << endl;
				cout << "============\n" << endl;
				cout << "Your choice: ";
				cin >> sho;
				if (sho == 1) {
					b.sCon();
				}
				else if (sho == 2) {
					a.showContacts();
				}
				else {
					cout << "\nAh please, this trick won't work anymore :|" << endl;
					goto loop1;
				}
				break;
			case 3:
				loop2:
				cout << "\n1- Simple" << endl;
				cout << "2- Advanced" << endl;
				cout << "============\n" << endl;
				cout << "Your choice: ";
				cin >> sery;
				if (sery == 1) {
					cout << "\nSearch a Contact Using Name Or (And) Family: ";
					cin >> search1;
					z = b.fCon(search1);
				}
				else if (sery == 2) {
					cout << "\nSearch a Contact Using any Term: ";
					cin >> search;
					f = a.findContact(search);
				}
				else {
					cout << "\nAh please, this trick won't work anymore :|" << endl;
					goto loop2;
				}
				break;
			case 4:
				loop3:
				cout << "\n1- Simple" << endl;
				cout << "2- Advanced" << endl;
				cout << "============\n" << endl;
				cout << "Your choice: ";
				cin >> de;
				if (de == 1) {
					cout << "\nName (And / Or Family Name) of the Contact to Delete: ";
					cin >> search1;
					b.dCon(search1);
				}
				else if (de == 2) {
					cout << "\nSearch a Contact Using any Term: ";
					cin >> search;
					f = a.findContact(search);
				}
				else {
					cout << "\nAh please, this trick won't work anymore :|" << endl;
					goto loop3;
				}
				break;
//			case 5:
//				
//				break;
//			case 6:
//				
//				break;
			case 7:
				exit(1);
			default:
				cout << "\nWrong choice ...\n" << endl;
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
	cout << "{coming soon ...} 5- Edit a Contact" << endl;
	cout << "{coming soon ...} 6- Merge Two Contacts" << endl;
	cout << "7- Exit" << endl;
	cout << "==============================\n" << endl;
	return true;
}
