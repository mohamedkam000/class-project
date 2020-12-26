/*
 * Name:		Mohammed Kamal-Aldeen Othman
 * Class:		2nd Class
 * Department:	Computer Engineering
*/

// iincluding standard input-output stream which contains definitions
// to objects like cin, cout, ...
#include <iostream>
// as the name suggests, using the declarative region that provides
// a scope to the identifiers inside it
using namespace std;
// creating a class, a set of properties that have meaning together,
// named conan, used to provide a more simple interface
class conan{
// to be more open, when preceding a list of class members, the private
// keyword specifies that those members are accessible only from member
// functions and friends of the class, which applies to all members
// declared up to the next specifier or the end of class and it is the
// default access of members in a class
	private:
		string name1, family1, phone1;
// in the footsteps of the previous one, when preceding a list of class
// members, the public keyword specifies that those members are
// accessible from any function. This applies to all members declared
// up to the next access specifier or the end of the class
	public:
// the "*" syntax means that the template parameter is a function,
// so it is used to designate a variable as a pointer
		conan *next1;
		conan(){
		};
// somehow, these two lines below controls the order of the list,
// anyway "this" is a keyword that refers to the current instance of
// the class, there can be 3 main usage of this keyword:

/*
 (1) It can be used to pass current object as a parameter to another
	 method.
 
 (2) It can be used to refer current class instance variable.
 
 (3) It can be used to declare indexers.

*/

// well, currently we're using it to refer to the fields of the current
// class
		conan(string name1, string family1, string phone1){
			this -> name1 = name1; this -> family1 = family1; this -> phone1 = phone1;
		}
// for I want others to read and modify the data, I'll use setters and
// getters method to successfully assign parameters from a public
// variable to a private one, so when we call the value with getters it
// will be there
		string gn(){
			return name1;
		}
		string gf(){
			return family1;
		}
		string gp(){
			return phone1;
		}
// this is a setter which is mentioned in the comments starting from
// line 52 and below, the difference is that we use a function return
// type "void", with a pointer that returns a function not a class
// member. So tricky, nah?
		void Con(string name1, string family1, string phone1){
			this -> name1 = name1; this -> family1 = family1; this -> phone1 = phone1;
		}
// a getter, taking it's variables from the setter and viewes them, and
// yes, this might look like the code controlling the order of the list,
// but nah .. it only controls whether it is viewed or not, not how.
		void Cona(){
			cout << name1 << " " << family1 << "   " << phone1 << endl;
		}
};
// great .. now we head to the next class tied to the previous one, this
// class is all about listing contacts and managing various features
// so close to as deleting, adding, searching, ... 
class conly{
// same as line 16 ~ 20
	private:
		conan *head1;
		conan *last1;
		int size1;
// same as line 23 ~ 26
	public:
// dunno how to explain this, but this is the part where define your
// main feature's function, for some, I've gave the a pointer and others
// are just .. functions, it'll be clearer as you go along the lines
		conly();
		conan* fo(string);
		void add1(string,string,string);
		void dCon(string);
		conan* fCon(string);
		void ia(conan*,string,string,string);
		void sCon();
};
// the two colons "::", named the scope operator, specifies the class
// to which the member being defined belongs to
conly::conly(){
// well .. when we start a list from scratch, it'll definitely be empty,
// that's what the case would be like, here
	head1 = NULL ; last1 = NULL; size1 = 0;
}
// as said above, the scoped functions belongs to the class "conly", and
// below is it's brain of what the function actually do (adds).
void conly::add1(string name1, string family1, string phone1){
	conan* new_conan = new conan(name1, family1, phone1);
	if (last1 == NULL || head1 == NULL){
		head1 = new_conan;
		last1 = new_conan;
	}
// the thing is, when the list is empty, it adds a contact, and if it's
// not, it adds pushes the old one back and put the new one first, I've
// been told to add a contact, nothing was told upon how and which way
// to accomplish it
	else {
		new_conan -> next1 = head1;
		head1 = new_conan;
	}
// the list size increases each time we add a contact, it starts from 0
// which is mentioned in line 106
	size1++;
}
// insert after a specific contact .. we're not going to use the feature
// on it's own, it's here to use it as a trick for editing a contact
// without more headaches and tremendous hours of studying something
// that might not even exist anyway, bla bla bla ...
void conly::ia(conan* n_conan, string name1, string family1, string phone1){
	if (n_conan == NULL){
// yeah you're so smart to figure out that this code checks the absense
// of a contact before it starts functioning, congrats
		cout << "\nNot Found!" << endl;
		return;
	}
// the actual functionality, enforcibly insert the contact after another
// specified one, that'll also trigger a size increase
	conan* new_conan = new conan(name1, family1, phone1);
	new_conan -> next1 = n_conan -> next1;
	n_conan -> next1 = new_conan;
	if (n_conan == last1) last1 = n_conan;
	size1++;
}
// yeah the pointer we defined earlier, the search feature, checks the
// inserted term and compares them with the absent variable values
// this is like a brain/kernel to the actual function we're using later 
conan* conly::fo(string ser){
	conan* x = NULL;
	for( x = head1 ; x != NULL ; x = x -> next1)
		if (x -> gn() == ser || x -> gp() == ser || x -> gf() == ser || ( x -> gn() + " " + x -> gf() ) == ser) {
			return x;
		}
	return x;
}
// this is similar to a front-end code (theoritically) as it implements
// the previous code and provides the output the user desires
conan* conly::fCon(string ser){
	conan* z = fo(ser);
// this verification should be default, in order to avoid things that
// are not calculated
	if (z == NULL){
		cout << "\n\nNot found!" << endl;
	}
// in case any contact is absent, it'll be shown using the getter
	else {
		cout << "\n\n------------------------------------" << endl;
		z -> Cona();
		cout << "-----------------------------------" << endl;
	}
	return z;
}
// deleting feature, though it implements a search mechanism, it makes
// sense, as to delete a specific contact, you need to search for it
// first, and make sure it exists
void conly::dCon(string ser){
	if (head1 -> gn() == ser || head1 -> gf() == ser || (head1 -> gn() + " " + head1 -> gf()) == ser) {
		conan* temp1 = head1 -> next1;
// delete is an operator used to destroy array and non-array (pointers)
// objects, deeply, what it does is deallocating memory from heap
		delete head1;
		head1 = temp1;
		size1--;
		return;
	}
// nothing to delete, it shouldn't show this as it's so .. old way of
// expressing tool feature, I mean for God's sake who's gonna try to
// delete something he knows it doesn't exist
	conan* temp1 = head1;
	if (temp1 -> next1 == NULL) {
		 cout << "\n\nNot found!" << endl;
		 return;
	}
// so far as the code above was started, it should be completed at least
	while(temp1 -> next1 -> gn() != ser && temp1 -> next1 -> gf() != ser && (head1 -> gf() + " " + head1 -> gf()) != ser && temp1 != NULL){ 
		temp1 = temp1 -> next1;
		if ( temp1 -> next1 == NULL ) {
			 cout << "\n\nNot found!" << endl;
			 return;
		};
	}
// delete the specified contact, and put it's predecessor on it's ash
	if(temp1 != NULL){
	conan* temp3 = temp1 -> next1;
	temp1 -> next1 = temp3 -> next1;
	delete temp3;

/*

	Just to note, the arrow operator ( -> )is used to reference individual
		members of classes, structures, and unions.

	The arrow operator is used with a pointer to object, now I don't
		think I'm gonna explain all the lines of which it has the arrow
		operator, so this will be the end of it.

*/

	if( last1 -> gn() == ser || last1 -> gf() == ser || ( last1->gn() + " " + last1->gf() ) == ser ) {
		last1 = temp1;
	}
// didn't forget you, the list gets smaller by one each time we delete
	size1--;
	}
}
// what good does it make for a list that we don't manage it's contents
// so now and then? and how would you manage something you don't know?
// following is a code used to show stored contacts
void conly::sCon(){
	cout << "\n" << endl;
// checks the list, in case it's empty, it'll output an error message
// formerly there used to be an exception that throw an error but it
// used to close the entire program, and it makes no sense, that's why
// it has been replaced
	if (last1 == NULL || head1 == NULL){
		cout << "\nNo contacts!";
		return;
	}
// the precedure is, we use a for loop to output each contact using a
// numbering that increases with each new contact
	int j = 1;
	for (conan* x = head1; x != NULL ; x = x -> next1) {
		cout << j << ") "; j++;
		x -> Cona();
		cout << "-------------------------------------------\n\n" << endl;
	}
};
// similar as line 13 ~ 14, the difference is, this is for the advanced
// contacts manager, thus, it has tremendous entries
class contact{
// same as it's corresponding class
	private:
		string org, orgs, orgl, orgj, orgn, orgyn, orgd, orgt, name, emtype, emtype1, ptype, ptype1, ptype2, ptype3, email1, phone2, phone3, phone4, webtype, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, family, phone, gender, email, address, website;
// same as it's corresponding class
	public:
		contact *next;
		contact(){
		};
// somehow, below two lines controls the order of the advanced contacts adding mechanism
// rest is the same as it's corresponding class
		contact(string name, string family, string phone, string orgn, string orgyn, string orgt, string orgj, string orgl, string orgs, string org, string orgd, string emtype, string emtype1, string ptype, string ptype1, string ptype2, string ptype3, string email1, string phone2, string phone3, string phone4, string webtype, string givenname, string additionalname, string yominame, string givennameyomi, string additionalnameyomi, string familynameyomi, string shortname, string nickname, string namesuffix, string nameprefix, string maidenname, string birthday, string initials, string sensitivity, string priority, string mileage, string dirserver, string occup, string hobby, string subject, string notes, string language, string billing, string gender, string email, string address, string website){
			this -> name = name; this -> family = family; this -> phone = phone; this -> org = org; this -> orgs = orgs; this -> orgyn = orgyn; this -> orgn = orgn; this -> orgd = orgd; this -> orgl = orgl; this -> orgj = orgj; this -> orgt = orgt; this -> phone4 = phone4; this -> phone3 = phone3; this -> phone2 = phone2; this -> ptype3 = ptype3; this -> ptype2 = ptype2; this -> ptype1 = ptype1; this -> ptype = ptype; this -> emtype = emtype; this -> givenname = givenname; this -> additionalname = additionalname; this -> yominame = yominame; this -> givennameyomi = givennameyomi; this -> additionalnameyomi = additionalnameyomi; this -> familynameyomi = familynameyomi; this -> shortname = shortname; this -> nickname = nickname; this -> namesuffix = namesuffix; this -> nameprefix = nameprefix; this -> maidenname = maidenname; this -> birthday = birthday; this -> initials = initials; this -> sensitivity = sensitivity; this -> priority = priority; this -> mileage = mileage; this -> dirserver = dirserver; this -> occup = occup; this -> hobby = hobby; this -> subject = subject; this -> notes = notes; this -> language = language; this -> billing = billing; this -> gender = gender; this -> email = email; this -> emtype1 = emtype1; this -> email1 = email1; this -> address = address; this -> webtype = webtype; this -> website = website;
		}
// same as it's corresponding class
		string getName(){
			return name;
		}
		string getFamily(){
			return family;
		}
		string getPhone(){
			return phone;
		}
		string getEmType(){
			return emtype;
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
		string getOrg(){
			return org;
		}
		string getOrgs(){
			return orgs;
		}
		string getOrgd(){
			return orgd;
		}
		string getOrgt(){
			return orgt;
		}
		string getOrgl(){
			return orgl;
		}
		string getOrgn(){
			return orgn;
		}
		string getOrgj(){
			return orgj;
		}
		string getOrgyn(){
			return orgyn;
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
		string getPhone2(){
			return phone2;
		}
		string getPhone3(){
			return phone3;
		}
		string getPhone4(){
			return phone4;
		}
		string getPtype(){
			return ptype;
		}
		string getPtype1(){
			return ptype1;
		}
		string getPtype2(){
			return ptype2;
		}
		string getPtype3(){
			return ptype3;
		}
		string getGender(){
			return gender;
		}
		string getEmail(){
			return email;
		}
		string getEmail1(){
			return email1;
		}
		string getEmType1(){
			return emtype1;
		}
		string getAddress(){
			return address;
		}
		string getWebsite(){
			return website;
		}
		string getWebtype(){
			return webtype;
		}
// a setter bla bla bla ...
		void setContact(string name, string family, string phone, string orgn, string orgyn, string orgt, string orgj, string orgl, string orgs, string org, string orgd, string emtype, string emtype1, string ptype, string ptype1, string ptype2, string ptype3, string email1, string phone2, string phone3, string phone4, string webtype, string givenname, string additionalname, string yominame, string givennameyomi, string additionalnameyomi, string familynameyomi, string shortname, string nickname, string namesuffix, string nameprefix, string maidenname, string birthday, string initials, string sensitivity, string priority, string mileage, string dirserver, string occup, string hobby, string subject, string notes, string language, string billing, string gender, string email, string address, string website){
			this -> name = name; this -> family = family; this -> phone = phone; this -> org = org; this -> orgs = orgs; this -> orgyn = orgyn; this -> orgn = orgn; this -> orgd = orgd; this -> orgl = orgl; this -> orgj = orgj; this -> orgt = orgt; this -> phone4 = phone4; this -> phone3 = phone3; this -> phone2 = phone2; this -> ptype3 = ptype3; this -> ptype2 = ptype2; this -> ptype1 = ptype1; this -> ptype = ptype; this -> emtype = emtype; this -> givenname = givenname; this -> additionalname = additionalname; this -> yominame = yominame; this -> givennameyomi = givennameyomi; this -> additionalnameyomi = additionalnameyomi; this -> familynameyomi = familynameyomi; this -> shortname = shortname; this -> nickname = nickname; this -> namesuffix = namesuffix; this -> nameprefix = nameprefix; this -> maidenname = maidenname; this -> birthday = birthday; this -> initials = initials; this -> sensitivity = sensitivity; this -> priority = priority; this -> mileage = mileage; this -> dirserver = dirserver; this -> occup = occup; this -> hobby = hobby; this -> subject = subject; this -> notes = notes; this -> language = language; this -> billing = billing; this -> gender = gender; this -> email = email; this -> emtype1 = emtype1; this -> email1 = email1; this -> address = address; this -> webtype = webtype; this -> website = website;
		}
// the rest is the same as it's corresponding class
// a getter bla bla bla ...
		void getContact(){
			cout << name << " " << family << "   " << phone << "   " << ptype << "   " << givenname << "   " << additionalname << "   " << yominame << "   " << additionalnameyomi << "   " << givennameyomi << "   " << familynameyomi << "   " << nameprefix << "   " << namesuffix << "   " << maidenname << "   " << shortname << "   " << nickname << "   " << birthday << "   " << language << "   " << initials << "   " << dirserver << "   " << billing << "   " << sensitivity << "   " << priority << "   " << subject << "   " << notes << "   " << hobby << "   " << occup << "   " << mileage << "   " << ptype1 << "   " << phone2 << "   " << ptype2 << "   " << phone3 << "   " << ptype3 << "   " << phone4 << "   " << address << "   " << gender << "   " << orgd << "   " << org << "   " << orgyn << "   " << orgn << "   " << orgs << "   " << orgj << "   " << orgl << "   " << orgt << "   " << emtype << "   " << email << "   " << emtype1 << "   " << email1 << "   " << webtype << "   " << website << endl;
		}
};
// same as it's corresponding class
class contactsList{
	private:
// same as it's corresponding class
		contact *head;
		contact *last;
		int size;
	public:
// same as it's corresponding class
		contactsList();
		contact* find(string);
		void add(string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string);
		void deleteContact(string);
		contact* findContact(string);
		void insertAfter(contact*, string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string);
		void showContacts();
};
// same as it's corresponding class
contactsList::contactsList(){
	head = NULL ; last = NULL; size = 0;
}
// same as it's corresponding class
void contactsList::add(string name, string family, string phone, string orgn, string orgyn, string orgt, string orgj, string orgl, string orgs, string org, string orgd, string emtype, string emtype1, string ptype, string ptype1, string ptype2, string ptype3, string email1, string phone2, string phone3, string phone4, string webtype, string givenname, string additionalname, string yominame, string givennameyomi, string additionalnameyomi, string familynameyomi, string shortname, string nickname, string namesuffix, string nameprefix, string maidenname, string birthday, string initials, string sensitivity, string priority, string mileage, string dirserver, string occup, string hobby, string subject, string notes, string language, string billing, string gender, string email, string address, string website){
	contact* new_contact = new contact(name, family, phone, org, orgs, orgl, orgj, orgn, orgyn, orgd, orgt, emtype, emtype1, ptype, ptype1, ptype2, ptype3, email1, phone2, phone3, phone4, webtype, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, gender, email, address, website);
	if (last == NULL || head == NULL){
		head = new_contact;
		last = new_contact;
	}
// same as it's corresponding class
	else {
		new_contact -> next = head;
		head = new_contact;
	}
	size++;
}
// same as it's corresponding class
contact* contactsList::find(string serachQuery ){
	contact* n = NULL;
	for( n = head ; n != NULL ; n = n->next)
		if (n -> getOrgs() == serachQuery || n -> getOrgyn() == serachQuery || n -> getOrgt() == serachQuery || n -> getOrgn() == serachQuery || n -> getOrgl() == serachQuery || n -> getOrgj() == serachQuery || n -> getOrgd() == serachQuery || n -> getOrg() == serachQuery || n -> getName() == serachQuery || n -> getWebtype() == serachQuery || n -> getPtype3() == serachQuery || n -> getPtype2() == serachQuery || n -> getPtype1() == serachQuery || n -> getPtype() == serachQuery || n -> getPhone4() == serachQuery || n -> getPhone3() == serachQuery || n -> getPhone2() == serachQuery || n -> getEmail1() == serachQuery || n -> getEmType1() == serachQuery || n -> getEmType() == serachQuery || n -> getAdditionalName() == serachQuery || n -> getMaidenName() == serachQuery || n -> getShortName() == serachQuery || n -> getNickName() == serachQuery || n -> getYomiName() == serachQuery || n -> getFamilyNameYomi() == serachQuery || n -> getAdditionalNameYomi() == serachQuery || n -> getGivenName() == serachQuery || n -> getGivenNameYomi() == serachQuery || n -> getInitials() == serachQuery || n -> getBirthday() == serachQuery || n -> getOccupation() == serachQuery || n -> getNameSuffix() == serachQuery || n -> getNamePrefix() == serachQuery || n -> getDirServer() == serachQuery || n -> getMileage() == serachQuery || n -> getHobby() == serachQuery || n -> getLanguage() == serachQuery || n -> getNotes() == serachQuery || n -> getSubject() == serachQuery || n -> getPriority() == serachQuery || n -> getSensitivity() == serachQuery || n -> getFamily() == serachQuery || ( n -> getName() + " " + n -> getFamily() ) == serachQuery || n -> getEmail() == serachQuery || n -> getAddress() == serachQuery || n -> getGender() == serachQuery) {
			return n;
		}
	return n;
}
// same as it's corresponding class
void contactsList::insertAfter(contact* n_contact, string name, string family, string phone, string orgn, string orgyn, string orgt, string orgj, string orgl, string orgs, string org, string orgd, string emtype, string emtype1, string ptype, string ptype1, string ptype2, string ptype3, string email1, string phone2, string phone3, string phone4, string webtype, string givenname, string additionalname, string yominame, string givennameyomi, string additionalnameyomi, string familynameyomi, string shortname, string nickname, string namesuffix, string nameprefix, string maidenname, string birthday, string initials, string sensitivity, string priority, string mileage, string dirserver, string occup, string hobby, string subject, string notes, string language, string billing, string gender, string email, string address, string website){
	if (n_contact == NULL){
		cout << "\nNot Found!" << endl;
		return;
	}
// same as it's corresponding class
	contact* new_contact = new contact(name, family, phone, org, orgs, orgl, orgj, orgn, orgyn, orgd, orgt, emtype, emtype1, ptype, ptype1, ptype2, ptype3, email1, phone2, phone3, phone4, webtype, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, gender, email, address, website);
	new_contact -> next = n_contact -> next;
	n_contact -> next = new_contact;
	if (n_contact == last) last = n_contact;
	size++;
}
// same as it's corresponding class
contact* contactsList::findContact(string serachQuery){
	contact* f = find(serachQuery);
	if (f == NULL){
		cout << "\n\nNot found!" << endl;
	}
// same as it's corresponding class
	else {
		cout << "\n\n------------------------------------" << endl;
		f -> getContact();
		cout << "-----------------------------------" << endl;
	}
	return f;
}
// same as it's corresponding class
void contactsList::deleteContact(string serachQuery){
	if (head->getOrgs() == serachQuery || head->getOrgyn() == serachQuery || head->getOrgt() == serachQuery || head->getOrgn() == serachQuery || head->getOrgl() == serachQuery || head->getOrgj() == serachQuery || head->getOrgd() == serachQuery || head->getOrg() == serachQuery || head->getName() == serachQuery || head->getPtype3() == serachQuery || head->getPtype2() == serachQuery || head->getPtype1() == serachQuery || head->getPtype() == serachQuery || head->getPhone4() == serachQuery || head->getPhone3() == serachQuery || head->getPhone2() == serachQuery || head->getWebtype() == serachQuery || head->getEmail1() == serachQuery || head->getEmType1() == serachQuery || head->getEmType() == serachQuery || head -> getAdditionalName() == serachQuery || head -> getMaidenName() == serachQuery || head -> getShortName() == serachQuery || head -> getNickName() == serachQuery || head -> getYomiName() == serachQuery || head -> getFamilyNameYomi() == serachQuery || head -> getAdditionalNameYomi() == serachQuery || head -> getGivenName() == serachQuery || head -> getGivenNameYomi() == serachQuery || head -> getInitials() == serachQuery || head -> getBirthday() == serachQuery || head -> getOccupation() == serachQuery || head -> getNameSuffix() == serachQuery || head -> getNamePrefix() == serachQuery || head -> getDirServer() == serachQuery || head -> getMileage() == serachQuery || head -> getHobby() == serachQuery || head -> getLanguage() == serachQuery || head -> getNotes() == serachQuery || head -> getSubject() == serachQuery || head -> getPriority() == serachQuery || head -> getSensitivity() == serachQuery || head -> getEmail() == serachQuery || head -> getAddress() == serachQuery || head -> getGender() == serachQuery || head->getFamily() == serachQuery || (head->getName() + " " + head->getFamily()) == serachQuery) {
		contact* temp = head->next;
		delete head;
		head = temp;
		size--;
		return;
	}
// same as it's corresponding class
	contact* temp = head;
	if( temp->next == NULL ){
		 cout << "\n\nNot found!" << endl;
		 return;
	}
// same as it's corresponding class
	while(temp -> next -> getOrgl() != serachQuery && temp -> next -> getOrgyn() != serachQuery && temp -> next -> getOrgt() != serachQuery && temp -> next -> getOrgn() != serachQuery && temp -> next -> getOrgl() != serachQuery && temp -> next -> getOrgj() != serachQuery && temp -> next -> getOrgd() != serachQuery && temp -> next -> getOrg() != serachQuery && temp -> next -> getLanguage() != serachQuery && temp -> next -> getPtype3() != serachQuery && temp -> next -> getPtype2() != serachQuery && temp -> next -> getPtype1() != serachQuery && temp -> next -> getPtype() != serachQuery && temp -> next -> getPhone4() != serachQuery && temp -> next -> getPhone3() != serachQuery && temp -> next -> getPhone2() != serachQuery && temp -> next -> getEmail1() != serachQuery && temp -> next -> getEmType1() != serachQuery && temp -> next -> getEmType() != serachQuery && temp -> next -> getWebtype() != serachQuery && temp -> next -> getEmType() != serachQuery && temp -> next -> getShortName() != serachQuery && temp -> next -> getSubject() != serachQuery && temp -> next -> getFamilyNameYomi() != serachQuery && temp -> next -> getGender() != serachQuery && temp -> next -> getGivenName() != serachQuery && temp -> next -> getInitials() != serachQuery && temp -> next -> getPhone() != serachQuery && temp -> next -> getPriority() != serachQuery && temp -> next -> getSensitivity() != serachQuery && temp -> next -> getYomiName() != serachQuery && temp -> next -> getEmail() != serachQuery && temp -> next -> getName() != serachQuery && temp -> next -> getWebsite() != serachQuery && temp -> next -> getNotes() != serachQuery && temp -> next -> getNickName() != serachQuery && temp -> next -> getMileage() != serachQuery && temp -> next -> getMaidenName() != serachQuery && temp -> next -> getAddress() != serachQuery && temp -> next -> getAdditionalNameYomi() != serachQuery && temp -> next -> getAdditionalName() != serachQuery && temp -> next -> getBirthday() != serachQuery && temp -> next -> getBilling() != serachQuery && temp -> next -> getOccupation() != serachQuery && temp -> next -> getNameSuffix() != serachQuery && temp -> next -> getNamePrefix() != serachQuery && temp -> next -> getDirServer() != serachQuery && temp -> next -> getHobby() != serachQuery && temp -> next -> getFamily() != serachQuery && ( head -> getName() + " " + head -> getFamily() ) != serachQuery && temp != NULL ){ 
		temp = temp -> next;
		if ( temp -> next == NULL ) {
			 cout << "\n\nNot found!" << endl;
			 return;
		};
	}
// same as it's corresponding class
	if(temp != NULL){
	contact* temp2 = temp -> next;
	temp -> next = temp2 -> next;
	delete temp2;
	if (last -> getName() == serachQuery || last -> getPhone2() == serachQuery || last -> getPhone3() == serachQuery || last -> getPhone4() == serachQuery || last -> getPtype() == serachQuery || last -> getPtype1() == serachQuery || last -> getPtype2() == serachQuery || last -> getPtype3() == serachQuery || last -> getWebtype() == serachQuery || last -> getEmType1() == serachQuery || last -> getEmail1() == serachQuery || last -> getEmType() == serachQuery || last -> getAdditionalName() == serachQuery || last -> getMaidenName() == serachQuery || last -> getShortName() == serachQuery || last -> getNickName() == serachQuery || last -> getYomiName() == serachQuery || last -> getFamilyNameYomi() == serachQuery || last -> getAdditionalNameYomi() == serachQuery || last -> getGivenName() == serachQuery || last -> getGivenNameYomi() == serachQuery || last -> getInitials() == serachQuery || last -> getBirthday() == serachQuery || last -> getOccupation() == serachQuery || last -> getNameSuffix() == serachQuery || last -> getNamePrefix() == serachQuery || last -> getDirServer() == serachQuery || last -> getMileage() == serachQuery || last -> getHobby() == serachQuery || last -> getLanguage() == serachQuery || last -> getNotes() == serachQuery || last -> getSubject() == serachQuery || last -> getPriority() == serachQuery || last -> getSensitivity() == serachQuery || last -> getEmail() == serachQuery || last -> getAddress() == serachQuery || last -> getGender() == serachQuery || last->getFamily() == serachQuery || (last->getName() + " " + last->getFamily()) == serachQuery) {
		last = temp;
	}
	size--;
	}
}
// same as it's corresponding class
void contactsList::showContacts(){
	cout << "\n" << endl;
	if (last == NULL || head == NULL){
		cout << "No contacts!";
		return;
	}
// same as it's corresponding class
	int l = 1;
	for (contact* n = head; n != NULL ; n = n -> next) {
		cout << l << ") "; l++;
		n -> getContact();
		cout << "-------------------------------------------\n\n" << endl;
	}
};
// well .. class work is done so far
conan* z;
// these two lines were firstly present inside the main, and caused a
// silent error (something like variable not used, bla bla bla ...), but
// it works flawlessly outside the main .. maybe because it is part of
// the created class that can't be inside the main? not sure
contact* f;
// a menu created, and called before the enterance of main
bool menu();
// you seriously expect me to explain this??
int main(){
// variables defined in their most suitable way, holding either 
	int n, ed, con, sery, sho, de;
	string org, orgs, orgl, orgj, orgn, orgyn, orgd, orgt, name1, emtype, family1, phone1, phone4, phone2, phone3, webtype, email1, emtype1, emtype2, email2, ptype, ptype1, ptype2, ptype3, name, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, family, phone, gender, email, address, website, search, search1;
	contactsList a;
// hold the class in a variable, and other words in paper you should not
// care about, what we'll do with these strings is that, we gonna stick
// it to the various functions defined above, using the dot operator,
// which is used to reference individual members of classes, it is
// applied to the actual object
	conly b;
// loop through the given block as long as the given condition is true
	while(menu()){
		cout << "\nYor choice: ";
		cin >> n;
// using the switch statement to select one of many code blocks to be
// executed, you'll choose using solid numbers
		switch(n){
			case 1:
// using solid loop to call it and execute the same code again from a
// specific position
				loop:
				cout << "\n1- Simple" << endl;
				cout << "2- Advanced" << endl;
				cout << "============\n" << endl;
				cout << "Your choice: ";
				cin >> con;
// a small menu with options of using the complicated version or the
// mainstream one
				if (con == 1) {
					cout << "\nName: ";
					cin >> name1;
					cout << "Family: ";
					cin >> family1;
					cout << "Phone: ";
					cin >> phone1;
// you surely do remember lines 559 ~ 563, well .. here's the code in
// the field XD
					b.add1(name1, family1, phone1);
					a.add(name1, family1, phone1, org, orgs, orgl, orgj, orgn, orgyn, orgd, orgt, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, ptype, ptype1, phone2, ptype2, phone3, ptype3, phone4, gender, emtype, email, emtype1, email1, address, webtype, website);
				}
// the first one was for the simple, light version, which has only 3
// minor inputs, but this is for the advanced one, honestly I don't
// know anyone that would register a contact with all these inputs,
// I mean .. even coding and debugging is so booring :c|
				else if (con == 2) {
					cout << "\nName: ";
					cin >> name;
					cout << "Family: ";
					cin >> family;
					cout << "Phone 1 Number: ";
					cin >> phone;
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
					cout << "Phone 1 Type: ";
					cin >> ptype;
					cout << "Phone 2 Type: ";
					cin >> ptype1;
					cout << "Phone 2 Number: ";
					cin >> phone2;
					cout << "Phone 3 Type: ";
					cin >> ptype2;
					cout << "Phone 3 Number: ";
					cin >> phone3;
					cout << "Phone 4 Type: ";
					cin >> ptype3;
					cout << "Phone 4 Number: ";
					cin >> phone4;
					cout << "Gender: ";
					cin >> gender;
					cout << "E-Mail 1 Type: ";
					cin >> emtype;
					cout << "E-Mail 1: ";
					cin >> email;
					cout << "E-Mail 2 Type: ";
					cin >> emtype1;
					cout << "E-Mail 2: ";
					cin >> email1;
					cout << "Location: ";
					cin >> address;
					cout << "Website Type: ";
					cin >> webtype;
					cout << "Website: ";
					cin >> website;
					cout << "Organization Type: ";
					cin >> org;
					cout << "Organization Name: ";
					cin >> orgn;
					cout << "Organization Yomi Name: ";
					cin >> orgyn;
					cout << "Organization Title: ";
					cin >> orgt;
					cout << "Organization Department: ";
					cin >> orgd;
					cout << "Organization Symbol: ";
					cin >> orgs;
					cout << "Organization Location: ";
					cin >> orgl;
					cout << "Organization Job Describtion: ";
					cin >> orgj;
					a.add(name, family, phone, org, orgs, orgl, orgj, orgn, orgyn, orgd, orgt, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, ptype, ptype1, phone2, ptype2, phone3, ptype3, phone4, gender, emtype, email, emtype1, email1, address, webtype, website);
					b.add1(name, family, phone);
// same as lines 590 ~ 591
				}
				else {
					cout << "\nWrong Entry!" << endl;
					goto loop;
// repeat the entire case so long as if it's not yet satisfied
				}
// break the case, end the case, whatsoever
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
// a case concered with the idea of showing the saved contacts, the
// good thing is that, it has a combined contacts from the two different
// classes, simple and advanced
				else if (sho == 2) {
					a.showContacts();
				}
				else {
					cout << "\nWrong Entry!" << endl;
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
// a concerned case with the search functionality, providing the same
// availability of both classes
				else if (sery == 2) {
					cout << "\nSearch a Contact Using any Term: ";
					cin >> search;
					f = a.findContact(search);
				}
				else {
					cout << "\nWrong Entry!" << endl;
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
// manipulating the delete function in a live action task, has both the
// classes combined
				else if (de == 2) {
					cout << "\nSearch a Contact Using any Term: ";
					cin >> search;
					a.deleteContact(search);
				}
				else {
					cout << "\nWrong Entry!" << endl;
					goto loop3;
				}
				break;
			case 5:
				cout << "\n1- Simple" << endl;
				cout << "2- Advanced" << endl;
				cout << "============\n" << endl;
				cout << "Your choice: ";
				cin >> ed;
// well .. here comes the tricky part of the editing feature, it does
// contain 3 parts, the first part is to search for the contact, the
// second is to add a new info, the third is to erase the old one
				if (ed == 1) {
					cout << "\nWhich contact to edit: ";
					cin >> search1;
					cout << "\nEdit mode:" << endl;
					cout << "==========" << endl;
					cout << "\nName: ";
					cin >> name1;
					cout << "Family: ";
					cin >> family1;
					cout << "Phone: ";
					cin >> phone1;
					z = b.fCon(search1);
					b.ia(z, name1, family1, phone1);
					b.dCon(search1);
				}
// so basically it is the search, add, and delete features combined
				else if (ed == 2) {
					cout << "\nWhich contact to edit: ";
					cin >> search;
					cout << "\nEdit mode:" << endl;
					cout << "==========" << endl;
					cout << "\nName: ";
					cin >> name;
					cout << "Family: ";
					cin >> family;
					cout << "Phone 1 Number: ";
					cin >> phone;
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
					cout << "Phone 1 Type: ";
					cin >> ptype;
					cout << "Phone 2 Type: ";
					cin >> ptype1;
					cout << "Phone 2 Number: ";
					cin >> phone2;
					cout << "Phone 3 Type: ";
					cin >> ptype2;
					cout << "Phone 3 Number: ";
					cin >> phone3;
					cout << "Phone 4 Type: ";
					cin >> ptype3;
					cout << "Phone 4 Number: ";
					cin >> phone4;
					cout << "Gender: ";
					cin >> gender;
					cout << "E-Mail 1 Type: ";
					cin >> emtype;
					cout << "E-Mail 1: ";
					cin >> email;
					cout << "E-Mail 2 Type: ";
					cin >> emtype1;
					cout << "E-Mail 2: ";
					cin >> email1;
					cout << "Location: ";
					cin >> address;
					cout << "Website Type: ";
					cin >> webtype;
					cout << "Website: ";
					cin >> website;
					cout << "Organization Type: ";
					cin >> org;
					cout << "Organization Name: ";
					cin >> orgn;
					cout << "Organization Yomi Name: ";
					cin >> orgyn;
					cout << "Organization Title: ";
					cin >> orgt;
					cout << "Organization Department: ";
					cin >> orgd;
					cout << "Organization Symbol: ";
					cin >> orgs;
					cout << "Organization Location: ";
					cin >> orgl;
					cout << "Organization Job Describtion: ";
					cin >> orgj;
					f = a.findContact(search);
					a.insertAfter(f, name, family, phone, org, orgs, orgl, orgj, orgn, orgyn, orgd, orgt, givenname, additionalname, yominame, givennameyomi, additionalnameyomi, familynameyomi, shortname, nickname, namesuffix, nameprefix, maidenname, birthday, initials, sensitivity, priority, mileage, dirserver, occup, hobby, subject, notes, language, billing, ptype, ptype1, phone2, ptype2, phone3, ptype3, phone4, gender, emtype, email, emtype1, email1, address, webtype, website);
					a.deleteContact(search);
				}
				else {
// default error message, bla bla bla ...
					cout << "Wront entry!" << endl;
				}
				break;
//			case 6:
//				
//				break;
			case 7:
				exit(1);
			default:
// default error message too, haha
				cout << "\nWrong choice ...\n" << endl;
				break;
		}
	}
// identify the program was successfully executed, if any number other
// than 0 was returned, that means some error occurred which it's code
// is returned by main, if you are running on "Code::Block IDE" see in
// the build log, if any other value was returned, it will display
// status code in red, which means an error has occurred
	return 0;
}
// you probably do remember boolean data type of which holds either true
// or false, it is introduced here as a .. refashioning :)
bool menu(){
	cout << "\n\nMain Menu:" << endl;
	cout << "==========" << endl;
	cout << "\n\n1- Add a Contact" << endl;
	cout << "2- Show Contacts" << endl;
	cout << "3- Search a Contact" << endl;
	cout << "4- Delete a Contact" << endl;
	cout << "5- Edit a Contact" << endl;
	cout << "{coming soon ...} 6- Merge Two Contacts" << endl;
	cout << "7- Exit" << endl;
	cout << "==============================\n" << endl;
// wouldn't have written these lines to return something other than true
	return true;
}
