//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//ofstream write;
//fstream tfile;
//template<class V,class S>
//class Sales_Management_System {
//	S name,cnic,phone,type;
//	V day, month, year,limit;
//public:
//	Sales_Management_System(){
//		name = '\0', cnic = '\0', phone = '\0', type = '\0';
//		day = 0, month = 0, year = 0, limit = 0;
//	}
//	void setname(S name) {
//		this->name = name;
//	}
//	void setcnic(S cnic) {
//		this->cnic = cnic;
//	}
//	void setphone(S phone) {
//		this->phone = phone;
//	}
//	void setlimit(V limit) {
//		this->limit = limit;
//	}
//	S getname() {
//		return name;
//	}
//	S getphone() { 
//		return phone; }
//	S getcnic() {
//		return cnic;
//	}
//	void settype(S type) {
//		this->type = type;
//	}
//	S gettype() {
//		return type;
//	}
//	void setdate(V d, V m, V y) {
//		day = 20;
//		month = 05;
//		year = y;
//	}
//	V getday() { return day; }
//	V getmonth() { return month; }
//	V getyear() { return year; }
//	void showdate() {
//		cout << "Date: " << day << "/" << month << "/" << year << endl;
//	}
//	virtual void menu() = 0;
//	virtual ~Sales_Management_System() {}
//};
//
//template<class T, class U>
//class customer :public virtual Sales_Management_System<int,string> {
//	T name, email, cnic, phone, type;
//protected:
//	U limit;
//public:
//	customer( T cnic = "0",T name = "0", T email = "0", T phone = "0") {
//
//		this->cnic = cnic;
//		this->email = email;
//		this->name = name;
//		this->phone = phone;
//	}
//	void add_customer()
//	{
//		cout << "Enter CNIC: ";
//		cin >> cnic;
//		cout << "Enter Name: ";
//		cin >> name;
//		cout << "Enter E-mail: ";
//		cin >> email;
//		cout << "Enter Phone: ";
//		cin >> phone;
//		if (limit == 0)
//		{
//			cout << "Enter Sales Limit: ";
//			cin >> limit;
//		}
//		try {
//			if (!tfile)
//				throw runtime_error("Failed to open the file");
//
//		}
//		catch (const exception& e) {
//			cerr << "Error: " << e.what() << endl;
//		}
//		if(tfile)
//		{
//			try {
//				write.open("customer.txt", ios::app);
//				if(!write)
//					throw runtime_error("Failed to open the file");
//			}
//			catch (const exception& e) {
//				cerr << "Error: " << e.what() << endl;
//			}
//			write << cnic << "\t\t";
//			write << name << "\t\t";
//			write << email << "\t\t";
//			write << phone << "\t\t";
//			write << limit << endl;
//			write.close();
//			cout << "Customer information saved successfully." << endl;
//		}
//	}
//	void update_customer()
//	{
//		T temp, temp1, temp2, temp3, n, e, p, c, oldcnic;
//		int temp_limit = 0, choice = 0;
//		if (find_customer())
//		{
//			oldcnic = cnic;
//			while (choice != 5){
//				cout << "Enter one of the following details of customer to be updated" << endl;
//				cout << "1 - Update customer cnic" << endl;
//				cout << "2 - Update customer name" << endl;
//				cout << "3 - Update customer email" << endl;
//				cout << "4 - Update customer phone" << endl;
//				cout << "5 - If no more updates" << endl;
//				cout << "Select Option: ";
//				cin >> choice;
//				switch (choice) {
//					case 1:
//					cout << "Enter updated cnic ";
//					cin >> cnic;
//					case 2:
//						cout << "Enter updated name ";
//						cin >> name;
//					case 3:
//						cout << "Enter updated  email ";
//						cin >> email;
//					case 4:
//						cout << "Enter updated  phone ";
//						cin >> phone;
//				}
//			}
//			tfile.open("customer.txt", ios::in | ios::out);
//			write.open("temporary.txt");
//			getline(tfile, temp);
//			write << temp << endl;
//			while (tfile >> temp >> temp1 >> temp2 >> temp3 >> temp_limit) {
//				if (temp == oldcnic)
//					write << cnic << "\t\t" << name << "\t\t" << email
//					<< "\t\t" << phone << "\t\t" << limit << endl;
//				else
//					write << temp << "\t\t" << temp1 << "\t\t" << temp2
//					<< "\t\t" << temp3 << "\t\t" << temp_limit << endl;
//
//			}
//			write.close();
//			tfile.close();
//			remove("customer.txt");
//			int t = rename("temporary.txt", "customer.txt");
//			cout << "customer " << name << " successfully updated" << endl;
//		}
//		else
//			cout << "customer cannot be updated" << endl;
//	}
//	void delete_customer() {
//		if (find_customer())
//		{
//			int templim, choice = 0;
//			string temp, temp1, temp2, temp3;
//			cout << "Press 1 to confirm delete" << endl;
//			cin >> choice;
//			if (choice == 1)
//			{
//				tfile.open("customer.txt", ios::in | ios::out);
//				write.open("temporary.txt");
//				getline(tfile, temp);
//				write << temp << endl;
//				while (tfile >> temp >> temp1 >> temp2 >> temp3 >> templim) {
//					if (temp != cnic)
//						write << temp << "\t\t" << temp1 << "\t\t" << temp2 << "\t\t" << temp3 << "\t\t" << templim << endl;
//				}
//				write.close();
//				tfile.close();
//				remove("customer.txt");
//				int t = rename("temporary.txt", "customer.txt");
//				cout << "Customer " << name << " successfully removed!" << endl << endl;
//			}
//
//		}
//		else
//			cout << "Customer cannot be removed" << endl;
//	}
//	bool find_customer() {
//		int choice, liminp = -1;
//		string temp, input;
//		cout << "Enter one of the following details of customer " << endl;
//		cout << "1 - Enter CNIC" << endl;
//		cout << "2 - Enter Name" << endl;
//		cout << "3 - Enter E-Mail" << endl;
//		cout << "4 - Enter Phone" << endl;
//		cout << "5 - Enter Sales Limit" << endl;
//		cout << "Select Option: ";
//		cin >> choice;
//		cout << endl << endl;
//		if (choice == 1)
//			cout << "Enter CNIC: ";
//		if (choice == 2)
//			cout << "Enter Name: ";
//		if (choice == 3)
//			cout << "Enter E-Mail: ";
//		if (choice == 4)
//			cout << "Enter Phone: ";
//		if (choice == 5) {
//			cout << "Enter Sales Limit: ";
//			cin >> liminp;
//		}
//		if (choice >= 1 && choice <= 4)
//			cin >> input;
//		tfile.open("customer.txt", ios::in | ios::out);
//		getline(tfile, temp);
//		while (tfile >> cnic >> name >> email >> phone >> limit) {
//			if (cnic == input || name == input || email == input ||
//				phone == input || (limit == liminp && liminp != -1)) {
//				cout << cnic << "\t\t" << name << "\t\t" << email <<
//					"\t\t" << phone << "\t\t" << limit << endl;
//				return true;
//				break;
//			}
//		}
//		tfile.close();
//		return false;
//	}
//	void menu()override{
//		//system("CLS");
//		cout << "-------------------------------" << endl
//			<< "|       CUSTOMER MENU          |" << endl
//			<< "-------------------------------" << endl
//			<< "|                              |" << endl
//			<< "|  Press 1 to Add customer     |" << endl
//			<< "|  Press 2 to Remove customer  |" << endl
//			<< "|  Press 3 to Find customer    |" << endl
//			<< "|  Press 4 to Update customer  |" << endl
//			<< "|  Press 5 to Exit             |" << endl
//			<< "-------------------------------" << endl;
//
//	}
//	U getlimit() {
//		return limit;
//	}
//	void setlimit(U limit) {
//		this->limit = limit;
//	}
//	virtual int getdiscount() {
//		return 0;
//	}
//	virtual ~customer() {
//		//cout << "In customer" << endl;
//	}
//};
//
//template<class U>
//class SilverCustomer :public customer<string, int> {
//	U discount;
//public:
//	SilverCustomer() {
//		discount = 0;
//		setlimit(10000);
//		settype("Silver");
//	}
//	
//	int getdiscount() override{
//		return 0;
//	}
//	~SilverCustomer() {
//		//cout << "In silver";
//	}
//};
//
//template<class U>
//class GoldCustomer :public customer<string, int> {
//	U discount;
//	
//public:
//	GoldCustomer() {
//		discount = 3;
//		setlimit(30000);
//		settype("Gold");
//	}
//	int getdiscount() {
//		return 3;
//	}
//	~GoldCustomer() {
//
//	}
//};
//
//template <class U>
//class PlatinumCustomer :public customer<string, int> {
//	U discount;
//public:
//	PlatinumCustomer() {
//		discount = 5;
//		setlimit(50000);
//		settype("Silver");
//	}
//	virtual int getdiscount() {
//		return 5;
//	}
//	~PlatinumCustomer() {
//
//	}
//};
//
//template<class T, class U>
//class item :public virtual Sales_Management_System<int,string> {
//protected:
//	T sku_no, price, quantity;
//	U description;
//public:
//	item(T num = 0, U descr = "0", T price = 0, T quantity = 0) {
//		sku_no = num;
//		description = descr;
//		this->price = price;
//		this->quantity = quantity;
//	}
//	void add_item() {
//		cout << "Enter Item sku_no: ";
//		cin >> sku_no;
//		cout << "Enter Description of item: ";
//		cin >> description;
//		cout << "Enter Price: ";
//		cin >> price;
//		cout << "Enter Quantity: ";
//		cin >> quantity;
//		if (!tfile)
//			cout << "File not created." << endl;
//		else
//		{
//			write.open("menu.txt", ios::app);
//			write << sku_no << "\t" << description << "\t" << price << "\t" << quantity << endl;
//			write.close();
//			cout << "Item saved successfully." << endl;
//		}
//	}
//	void update_item()
//	{
//		if (find_item())
//		{
//			U temp;
//			T old_skuno, temp1, temp2, temp3, choice = 0;
//			while (choice != 5) {
//				old_skuno = sku_no;
//				cout << "Enter one of the following details of item to be updated";
//				cout << "1 - Update item s_no" << endl;
//				cout << "2 - Update item description" << endl;
//				cout << "3 - Update item price" << endl;
//				cout << "4 - Update item quantity" << endl;
//				cout << "5 - If no more updates" << endl;
//				cout << "Select Option: ";
//				cin >> choice;
//				if (choice == 1)
//				{
//					cout << "Enter updated item_sku: ";
//					cin >> sku_no;
//				}
//				if (choice == 2)
//				{
//					cout << "Enter updated description: ";
//					cin >> description;
//				}
//				if (choice == 3)
//				{
//					cout << "Enter updated price: ";
//					cin >> price;
//				}
//				if (choice == 4)
//				{
//					cout << "Enter updated quantity ";
//					cin >> quantity;
//				}
//			}
//			tfile.open("menu.txt", ios::in | ios::out);
//			write.open("temp.txt");
//			getline(tfile, temp);
//			write << temp << endl;
//			while (tfile >> temp1 >> temp >> temp2 >> temp3) {
//				if (temp1 == old_skuno) {
//					write << sku_no << "\t" << description << "\t" << price << "\t" << quantity << endl;
//				}
//				else
//					write << temp1 << "\t" << temp << "\t" << temp2 << "\t" << temp3 << endl;
//			}
//			write.close();
//			tfile.close();
//			remove("menu.txt");
//			int t = rename("temp.txt", "menu.txt");
//			cout << "item " << description << " successfully updated" << endl;
//		}
//		else
//			cout << "Item cannot be updated" << endl;
//	}
//	void delete_item() {
//		if (find_item()) {
//			U temp;
//			T temp1, temp2, temp3, choice = 0;
//			cout << "Press 1 to confirm delete" << endl;
//			cin >> choice;
//			if (choice == 1)
//			{
//				tfile.open("menu.txt", ios::in | ios::out);
//				write.open("temp.txt");
//				getline(tfile, temp);
//				write << temp << endl;
//				while (tfile >> temp1 >> temp >> temp2 >> temp3) {
//					if (temp1 != sku_no)
//						write << temp1 << "\t" << temp << "\t" << temp2 << "\t" << temp3 << endl;
//				}
//				write.close();
//				tfile.close();
//				remove("menu.txt");
//				int t = rename("temp.txt", "menu.txt");
//				cout << "Item " << description << " successfully removed" << endl;
//			}
//		}
//		else
//			cout << "item cannot be removed" << endl;
//	}
//	bool find_item() {
//		T inputp = -1, inputq = -1, choice = -1, inputs = -1;
//		U temp, input;
//		cout << "Enter one of the following details of item  ";
//		cout << "1 - Enter item s_no" << endl;
//		cout << "2 - Enter item description" << endl;
//		cout << "3 - Enter item price" << endl;
//		cout << "4 - Enter item quantity" << endl;
//		cout << "Select Option: ";
//		cin >> choice;
//		if (choice == 1) {
//			cout << "Enter item sku_no";
//			cin >> inputs;
//		}
//		if (choice == 2) {
//			cout << "Enter description ";
//			cin >> input;
//		}
//		if (choice == 3) {
//			cout << "Enter price ";
//			cin >> inputp;
//		}
//		if (choice == 4) {
//			cout << "Enter quantity ";
//			cin >> inputq;
//		}
//		tfile.open("menu.txt", ios::in | ios::out);
//		getline(tfile, temp);
//		while (tfile >> sku_no >> description >> price >> quantity) {
//			if (sku_no == inputs || description == input || price == inputp || quantity == inputq) {
//				cout << sku_no << "\t" << description << "\t" << price << "\t" << quantity << "\t" << endl;
//				return true;
//			}
//		}
//		tfile.close();
//		return false;
//	}
//	void menu() override{
//		//system("CLS");
//		cout << "----------------------------" << endl
//			<< "|	 ITEM MENU          |" << endl
//			<< "----------------------------" << endl
//			<< "|                           |" << endl
//			<< "|  Press 1 to Add items     |" << endl
//			<< "|  Press 2 to Remove items  |" << endl
//			<< "|  Press 3 to Find item     |" << endl
//			<< "|  Press 4 to Update item   |" << endl
//			<< "|  Press 5 to Exit          |" << endl
//			<< "----------------------------" << endl;
//
//	}
//};
//
//template<class T, class U>
//class sales :public customer<string, int>, public item<int, string> {
//	T sales_cnic, sales_name, sales_email, sales_phone;
//	U temp, new_price, new_quantity, new_limit;
//	double subtotal = 0;
//	bool found = false;
//protected:
//	U saleid;
//public:
//	sales(U d, U m, U y, U saleid) :item(), customer() {
//		sales_name = '\0', sales_email = '\0', sales_phone = '\0';
//		cout << "Enter cnic of sales" << endl;
//		cin >> sales_cnic;
//		setcnic(sales_cnic);
//		this->saleid = saleid;
//		write.open("sale.txt");
//		write.close();
//		setdate(d, m, y);
//	}
//	int getdiscount()override{
//		if (getlimit() <= 10000)
//			return 0;
//		else if (getlimit() <= 30000)
//			return 3;
//		else
//			return 5;
//	}
//	void add_sales(int sno) {
//		sku_no = sno;
//		tfile.open("menu.txt", ios::in | ios::out);
//		write.open("sale.txt", ios::app);
//		getline(tfile, sales_cnic);
//		while (tfile >> temp >> sales_cnic >> new_price >> new_quantity)
//		{
//			if (temp == sku_no)
//			{
//				price = new_price;
//				description = sales_cnic;
//				quantity = new_quantity;
//				found = true;
//				break;
//			}
//		}
//		tfile.close();
//		tfile.open("customer.txt", ios::in | ios::out);
//		getline(tfile, sales_cnic);
//		while (tfile >> sales_cnic >> sales_name >> sales_email >> sales_phone >> new_limit)
//		{
//			if (getcnic() == sales_cnic)
//			{
//				setname(sales_name);
//				setlimit(new_limit);
//				found = true;
//				break;
//			}
//		}
//		if (found == true)
//		{
//			cout << "Enter quantity you want to buy:" << endl;
//			cin >> new_quantity;
//			while (new_quantity > quantity) {
//				cout << "Reqired quantity is grater then available quantity." << endl;
//				cin >> new_quantity;
//			}
//			subtotal += new_quantity * price;
//			if (subtotal <= getlimit()) {
//				write << sku_no << "\t" << description << "\t"
//					<< new_quantity << "\t" << new_quantity * price << endl;
//				cout << "Item_sku: " << sku_no << endl
//					<< "Description: " << description << endl
//					<< "Price: " << price << endl
//					<< "Quantity: " << new_quantity << endl
//					<< "Sub_total: " << new_quantity * price << endl;
//			}
//			else
//				cout << "You have Exceeded sales limit" << endl;
//		}
//		if (!found)
//			cout << "Item is not present in menu." << endl;
//		write.close();
//		tfile.close();
//	}
//	void end_sale() {
//		cout << "Sales_id: " << saleid << "\t\t"
//			<< "Cnic: " << getcnic() << endl;
//		showdate();
//		cout << "----------------------------------------------------------------------------------------------" << endl;
//		cout << "Item_sku\t\t\tDescription\t\tQuantity\t\tAmount" << endl;
//		cout << "----------------------------------------------------------------------------------------------" << endl;
//		tfile.open("sale.txt", ios::in | ios::out);
//		while (tfile >> temp >> sales_cnic >> new_quantity >> new_price) {
//			cout << temp << "\t\t\t\t" << sales_cnic << "\t\t\t" << new_quantity << "\t\t\t" << new_price << endl;
//		}
//		cout << "----------------------------------------------------------------------------------------------" << endl;
//		cout << "Total sales: " << subtotal << endl;
//		cout << "----------------------------------------------------------------------------------------------" << endl;
//		tfile.close();
//	}
//	void delete_sale(int sno) {
//		sku_no = sno;
//		tfile.open("sale.txt", ios::in | ios::out);
//		write.open("s1.txt");
//		while (tfile >> temp >> sales_cnic >> new_quantity >> new_price)
//		{
//			if (temp != sku_no)
//				write << temp << "\t" << sales_cnic << "\t" << new_quantity << "\t" << new_price << endl;
//		}
//		write.close();
//		tfile.close();
//		remove("sale.txt");
//		int t = rename("s1.txt", "sale.txt");
//
//	}
//	void discount() {
//		string s1, name;
//		int lim;
//		tfile.open("customer.txt", ios::in | ios::out);
//		getline(tfile, sales_cnic);
//		while (tfile >> sales_cnic >> name >> s1 >> s1 >> lim) {
//			if (sales_cnic == getcnic())
//			{
//				setname(name);
//				setlimit(lim);
//				break;
//			}
//		}
//		tfile.close();
//		if (getdiscount() != 0)
//		{
//			cout << "In discount" << endl << "Toatal before discount: " << subtotal << endl;
//			subtotal = subtotal * (100.0 - getdiscount()) / 100.0;
//			cout << "Total after discount: " << subtotal << endl;
//		}
//		write.open("payment.txt", ios::app);
//		write << saleid << "\t\t" << getname() << "\t\t" <<
//			subtotal << "\t\t0\t\t" << subtotal << endl;
//		write.close();
//	}
//	~sales() {}
//	void menu() {
//		cout << "----------------------------------------------" << endl;
//		cout << "|         SALES MENU                 |" << endl;
//		cout << "----------------------------------------------" << endl;
//		cout << "|                                             |" << endl;
//		cout << "|   Press 1  to Enter new item                |" << endl;
//		cout << "|   Press 2 to End sale                       |" << endl;
//		cout << "|   Press 3 to Remove existing item from sale |" << endl;
//		cout << "|   Press 4 to Exit                           |" << endl;
//		cout << "----------------------------------------------" << endl;
//	}
//
//};
//
//template<class T, class U>
//class POS {
//	T total, paid, remaining, to_be_paid, sales_id;
//	U name;
//public:
//	POS() {
//		this->total = 0;
//		this->paid = 0;
//		this->remaining = 0;
//		this->to_be_paid = 0;
//		this->sales_id = 0;
//		this->name = '\0';
//	}
//	void payment(int id){
//		tfile.open("payment.txt", ios::in | ios::out);
//		getline(tfile, name);
//		write.open("temp.txt", ios::app);
//		write << name << endl;
//		while (tfile >> sales_id >> name >> total >> paid >> remaining)
//		{
//			if (sales_id == id)
//			{
//				cout << "Sales id: " << sales_id << endl
//					<< "Customer name: " << name << endl
//					<< "Total amount: " << total << endl
//					<< "Amount paid: " << paid << endl
//					<< "Amount remaining: " << remaining << endl
//					<< "Enter amount you want to pay: ";
//				cin >> to_be_paid;
//				remaining -= to_be_paid;
//				paid += to_be_paid;
//			}
//			write << sales_id << "\t\t" << name << "\t\t" << total << "\t\t" << paid << "\t\t" << remaining << endl;
//		}
//		tfile.close();
//		write.close();
//		remove("payment.txt");
//		int t = rename("temp.txt", "payment.txt");
//	}
//	void show(int id) {
//		tfile.open("payment.txt", ios::in | ios::out);
//		getline(tfile, name);
//		while (tfile >> sales_id >> name >> total >> paid >> remaining)
//		{
//			if (sales_id == id)
//				cout << "Sales id: " << sales_id << endl
//				<< "Customer name: " << name << endl
//				<< "Total amount: " << total << endl
//				<< "Amount paid: " << paid << endl
//				<< "Amount remaining: " << remaining << endl;
//		}
//		tfile.close();
//	}
//	~POS(){}
//};
//
//void menu() {
//	//system("CLS");
//	cout << "--------------------------------" << endl;
//	cout << "|          MAIN MENU            |" << endl;
//	cout << "--------------------------------" << endl;
//	cout << "|                               |" << endl;
//	cout << "|  Press 1 to manage items      |" << endl;
//	cout << "|  Press 2 to manage customers  |" << endl;
//	cout << "|  Press 3 to make new sale     |" << endl;
//	cout << "|  Press 4 to make payemnt      |" << endl;
//	cout << "|  Press 5 to exit              |" << endl;
//	cout << "--------------------------------" << endl;
//}
//
//void customertype() {
//	system("CLS");
//	cout << "-----------------------------------" << endl;
//	cout << "|       CHOOSE CUSTOMER            |" << endl;
//	cout << "-----------------------------------" << endl;
//	cout << "|                                  |" << endl;
//	cout << "|  Press 1 for silver customer     |" << endl;
//	cout << "|  Press 2 for gold customer       |" << endl;
//	cout << "|  Press 3 for platinum customer   |" << endl;
//	cout << "-----------------------------------" << endl;
//}
//
//void dateinput(int& d, int& m, int& y) {
//	cout << "Enter day = ";
//	cin >> d;
//	cout << "Enter month = ";
//	cin >> m;
//	cout << "Enter year = ";
//	cin >> y;
//}
//
//int main() {
//	int choice = 0, schoice = 0, d=25, m=5, y=2023;
//	//dateinput(d, m, y);
//	while (choice != 5) {
//		menu();
//		cin >> choice;
//		system("CLS");
//		if (choice == 1)
//		{
//			item<int, string> obj;
//			while (schoice != 5)
//			{
//				obj.menu();
//				cin >> schoice;
//				if (schoice == 1) { obj.add_item(); }
//				if (schoice == 2) { obj.delete_item(); }
//				if (schoice == 3) { obj.find_item(); }
//				if (schoice == 4) { obj.update_item(); }
//			}
//
//		}
//		if (choice == 2)
//		{
//			schoice = 0;
//			int type = 0;
//			customer<string, int>* object = new customer<string, int>;
//			while (schoice != 5)
//			{
//				object->menu();
//				cin >> schoice;
//				if (schoice == 1) {
//					customertype();
//					cin >> type;
//					if (type == 1) {
//						SilverCustomer<double>* obj = new SilverCustomer<double>;
//						object = obj;
//						object->add_customer();
//					}
//					if (type == 2) {
//						GoldCustomer<double>* obj = new GoldCustomer<double>;
//						object = obj;
//						object->add_customer();
//					}
//					if (type == 3) {
//						PlatinumCustomer<double>* obj = new PlatinumCustomer<double>;
//						object = obj;
//						object->add_customer();
//					}
//				}
//				if (schoice == 2) { object->delete_customer(); }
//				if (schoice == 3) {
//					if (object->find_customer())
//						cout << "The customer has been found."<<endl;
//					else
//						cout << "The customer not found." << endl;;
//				}
//				if (schoice == 4) { object->update_customer(); }
//			}
//			delete object;
//		}
//		if (choice == 3)
//		{
//			schoice = 0;
//			int id;
//			cout << "Enter sales id" << endl;
//			cin >> id;
//			sales<string, int> obj(d, m, y, id);
//			while (schoice != 5 && schoice != 2)
//			{
//				obj.menu();
//				cin >> schoice;
//				if (schoice == 1) {
//					cout << "Enter item sku_no";
//					cin >> id;
//					obj.add_sales(id);
//				}
//				if (schoice == 2) {
//					obj.end_sale();
//				}
//				if (schoice == 3) {
//					cout << "Enter item_sku to remove " << endl;
//					cin >> id;
//					obj.delete_sale(id);
//				}
//				obj.discount();
//			}
//		}
//		if (choice == 4){
//			schoice = 0;
//			cout << "Enter sales id" << endl;
//			cin >> d;
//			POS <int, string>obj;
//			obj.payment(d);
//			obj.show(d);
//		}
//	}
//	return 0;
//}