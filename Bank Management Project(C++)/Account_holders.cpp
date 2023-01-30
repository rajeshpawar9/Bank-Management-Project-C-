#include"Account_holders.h"
Account_holders::Account_holders() {
	Acc_No=1500;
	ifstream fin;
	fin.open("Account.dat",ios::binary|ios::in);
	if(!fin) {
		return;
	}
	fin.read((char *)(this),sizeof(*this));
	while(!fin.eof()) {
		this->Acc_No=Acc_No;
		fin.read((char *)(this),sizeof(*this));

	}
};
/////////////////////////////////////////
void Account_holders::write_Acc() {
	cout<<"\n\t\tEnter First Name and Last Name ";
	cin>>fname>>lname;
	cout<<"\n\n\t Deposit Inital Amount:";
	cin>>Acc_Balance;
	cout<<"\n\n\t Enter Password:";
	cin>>Password;
	Acc_No++;
	char Name[10];
	strcpy(Name,fname);
	strcat(Name,".dat");
	ofstream f(Name);
	f.close();


};
//////////////////////////////////////////
void Account_holders::show_All_Acc() {
	ifstream f;
	f.open("Account.dat",ios::binary|ios::in);
	if(f.peek()==EOF)
	{
		cout<<"\n\t\t No Data";
		return;
	}
	cout<<"\n\t\tFirst Name\t Last Name \t Account NO \t Balance \t Password";
	f.read((char *)(this),sizeof(*this));
	while(!f.eof()) {
		show();
		f.read((char *)(this),sizeof(*this));
	}
	f.close();
}
//////////////////////////////////////////
void Account_holders::show() {
	cout<<"\n\n\t\t"<<fname<<"\t\t"<<lname<<"\t\t"<<Acc_No<<"\t\t"<<Acc_Balance<<"\t\t"<<Password;
};
/////////////////////////////////////////////
////////////      create Account
void Account_holders::create_Acc() {
	ofstream outf;
	outf.open("Account.dat",ios::binary|ios::app);
	write_Acc();
	outf.write((char *)(this),sizeof(*this));
	welcome();
	outf.close();
}
//////////////////////////////////////////////
////////          search Account
void Account_holders::search_Acc(int Acc_No) {
	bool flag=true;
	ifstream f;
	f.open("Account.dat",ios::binary|ios::in);
	if(!f) {
		cout<<"\n\t\t File Not Found";
		return;
	}
	f.read((char *)(this),sizeof(*this));
	while(!f.eof()) {
		if(this->Acc_No==Acc_No) {
			cout<<"\n\t\tFirst Name\t Last Name \t Account NO \t Balance \t Password";
			show();
			flag=false;
			break;
		}
		f.read((char *)(this),sizeof(*this));
	}
	f.close();
	if(flag) {
		cout<<"\n\t\t Account Not Found\n";
	}

}
////////////////////////////////////////////////////////////
//               Delete Account
void Account_holders::delete_Acc(int Acc) {
	bool flag=true;
	ifstream fin;
	fin.open("Account.dat",ios::binary|ios::in);
	if(!fin) {
		cout<<"\n\t\t File Not Found";
		return;
	}
	ofstream fout;
	fout.open("Temp.dat",ios::binary|ios::out);
	//fout.write("Temp.dat",ios::binary);
	fin.read((char *)(this),sizeof(*this));
	while(!fin.eof()) {
		if(Acc_No==Acc) {
			flag=false;
			break;
		}
		fin.read((char *)(this),sizeof(*this));
	}
	if(flag) {
		cout<<"\n\t\t Account Not found";
		return;
	}
	while(!fin.eof()) {
		if(Acc_No!=Acc) {
			fout.write((char *)(this),sizeof(*this));

		}
		fin.read((char *)(this),sizeof(*this));

	}
	fin.close();
	fout.close();
	remove("Account.dat");
	rename("Temp.dat","Account.dat");
	cout<<"\n\n\t Account is deleted.........";
};
////////////////////////////////////////////////////////////////////////
//                  Password check
int Account_holders::check_pass(int Mode) {
	switch(Mode) {
		case 1: {
			int Id;
			char Password[10];
			cout<<"\n\t\t Enter Login Id:  ";
			cin>>Id;
			cout<<"\n\t\t Enter Password:  ";
			cin>>Password;
			if(Id==1213&&strcmp(Password,"Mahesh")==0) {
				return 1;
			} 
			else
			 {
				return 11;
			}
			break;
		}
		case 2: {
			int Id;
			char Password[10];

			cout<<"\n\t\t Enter Account Number: ";
			cin>>Id;
			cout<<"\n\t\t Enter Password: ";
			cin>>Password;
			ifstream fin;
			fin.open("Account.dat",ios::binary|ios::in);
			if(!fin) {
				cout<<"\n\t\t File Not Found";
				break;
			}
			fin.read((char *)(this),sizeof(*this));
			while(!fin.eof()) {
				if(this->Acc_No==Id&& strcmp(this->Password,Password)==0) {
					welcome();

					return 2;
				}
				fin.read((char *)(this),sizeof(*this));
			}
			return 11;

			break;
		}
		case 3: {
			return 3;
			break;
		}
		case 10: {
			return 10;
			break;
		}
		default: {
			return 11;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
// welcome
void Account_holders::welcome() {
	cout<<"\n\t\t\t\t Welcome  "<<fname<<"     \n";
	cout<<"\n\t\tFirst Name\t Last Name \t Account NO \t Balance\t Password";
	cout<<"\n\n\t\t"<<fname<<"\t\t"<<lname<<"\t\t"<<Acc_No<<"\t\t"<<Acc_Balance<<"\t\t"<<Password;

}
//////////////////////////////////////////////////////////////////////
//              update
void Account_holders::update() {
	int Acc_No=this->Acc_No;
	char Password[7];
	char fname[10],lname[10];
	fstream fin;
	fin.open("Account.dat",ios::binary|ios::in|ios::out);
	if(!fin) {
		cout<<"\n\t\t File Not Found";
		return;
	}
		if(fin.peek()==EOF)
	{
		cout<<"\n\t\t No Data";
		return;
	}
	fin.read((char *)(this),sizeof(*this));
	while(!fin.eof()) {
		if(this->Acc_No==Acc_No) {
			break;
		}
		fin.read((char *)(this),sizeof(*this));
	}
	cout<<"\n\t\t Enter First Name and Last Name:";
	cin>>fname>>lname;
	cout<<"\n\t\t Enter Enter New Password:";
	cin>>Password;
	strcpy(this->fname,fname);
	strcpy(this->lname,lname);
	strcpy(this->Password,Password);
	int pos=(-1)*static_cast<int>(sizeof(*this));
	fin.seekp(pos,ios::cur);
	fin.write((char*)(this), sizeof(*this));
	fin.close();

}
///////////////////////////////////////////////////////////////////////////////////
/////////////////// Debit money
void Account_holders::debit() {
	fstream f;
	int debit;
	f.open("Account.dat",ios::binary|ios::in|ios::out);
	cout<<"\n\t\t Enter Amount To Debit:";
	cin>>debit;
	if(this->Acc_Balance<debit) {
		cout<<"\n\t\t Insufficient Balance";
		return;
	}
	this->Acc_Balance=this->Acc_Balance-debit;
	cout<<"\n\n\t Account Balance:  "<<this->Acc_Balance;
	f.write((char *)(this),sizeof(*this));
	T_history h;
	h.setTransaction(-debit,this->fname,"self_debit",0);
	f.close();
}
////////////////////////////////////////////////////////////////////////////////////
///////////////credit Money
void Account_holders::credit() {
	fstream f;
	int credit;
	f.open("Account.dat",ios::binary|ios::in|ios::out);
	cout<<"\n\t\t Enter Amount To credit:";
	cin>>credit;
	this->Acc_Balance=this->Acc_Balance+credit;
	f.write((char *)(this),sizeof(*this));
	T_history T;
	T.setTransaction(+credit,this->fname,"Self_credit",0);
	f.close();
}////////////////////////////////////////////////////////////////////////////
////////////check balance
void Account_holders::check_bal() {
	cout<<"\n\n\t Account Balance is:  "<<this->Acc_Balance<<"\n";
}
/////////////////////////////////////////////////////////////////////////////
/////////////// Transfer money
void Account_holders::transfer_money() {
	int Acc,choice;
	int T_Acc=this->Acc_No;
	char S_name[10];
	strcpy(S_name,this->fname);
	bool flag=true;
	cout<<"\n\t\t Enter Account Number:";
	cin>>Acc;
	int Amount;
	cout<<"\n\t\t Enter Amount:";
	cin>>Amount;
	if(this->Acc_Balance<Amount) {
		cout<<"\n\n\t\t Insufficient Balance";
		return;
	}
	fstream fin;
	fin.open("Account.dat",ios::binary|ios::in|ios::out);
	fin.read((char *)(this),sizeof(*this));
	while(!fin.eof()) {
		if(this->Acc_No==Acc) {
			flag=false;
			break;
		}
		fin.read((char *)(this),sizeof(*this));
	}
	if(flag) {
		Account_holders h;
		cout<<"\n\t\t Account Not found";
		fin.seekg(0,ios::beg);
		fin.read((char *)(this),sizeof(*this));
		while(!fin.eof()) {
			if(this->Acc_No==T_Acc) {
				int pos=(-1)*static_cast<int>(sizeof(*this));
				fin.seekp(pos,ios::cur);
				break;
			}
			fin.read((char *)(&h),sizeof(h));
			cout<<"hii";
		}
		return;
	}
	cout<<"\n\t\t Check Account Details";
	cout<<"\n\t\tFirst Name\t Last Name \t Account NO ";
	cout<<"\n\n\t\t"<<fname<<"\t\t"<<lname<<"\t\t"<<Acc_No;
	cout<<"\n\n\t\t Press 0 To cancel Payment";
	cout<<"\n\n\t\t Press 1 To Continue Payment";
	cin>>choice;
	if(choice==0) {
		return;
	}
	int pos=(-1)*static_cast<int>(sizeof(*this));
	fin.seekp(pos,ios::cur);
	this->Acc_Balance=this->Acc_Balance+Amount;
	strcpy(S_name,this->fname);
	//////////////////////////////////
	//write history
	T_history T;
	T.setTransaction(+Amount,this->fname,S_name,T_Acc);
	////////////////////////////////////////////
	fin.write((char*)(this), sizeof(*this));
	fin.seekg(0,ios::beg);
	fin.read((char *)(this),sizeof(*this));
	while(!fin.eof()) {
		if(this->Acc_No==T_Acc) {
			int pos=(-1)*static_cast<int>(sizeof(*this));
			fin.seekp(pos,ios::cur);
			break;
		}
		fin.read((char *)(this),sizeof(*this));
	}
	strcpy(S_name,this->fname);
	this->Acc_Balance=this->Acc_Balance-Amount;
		//////////////////////////////////
	//write history
//	T_history T;
	T.setTransaction(-Amount,this->fname,S_name,T_Acc);
	////////////////////////////////////////////
	fin.write((char*)(this), sizeof(*this));
	cout<<"\n\t\t Payment Successfull";
	fin.close();

}
//////////////////////////////////////////////////////////////////////////////
void Account_holders::Admin_update() {
	char Password[7];
	char fname[10],lname[10];
	int Acc_No;
	cout<<"\n\t\t Enter Account Number:";
	cin>>Acc_No;
	fstream fin;
	fin.open("Account.dat",ios::binary|ios::in|ios::out);
	if(!fin) {
		cout<<"\n\t\t File Not Found";
		return;
	}
	fin.read((char *)(this),sizeof(*this));
	while(!fin.eof()) {
		if(this->Acc_No==Acc_No) {
			break;
		}
		fin.read((char *)(this),sizeof(*this));
	}
	cout<<"\n\t\t Enter First Name and Last Name:";
	cin>>fname>>lname;
	cout<<"\n\t\t Enter Enter New Password:";
	cin>>Password;
	strcpy(this->fname,fname);
	strcpy(this->lname,lname);
	strcpy(this->Password,Password);
	int pos=(-1)*static_cast<int>(sizeof(*this));
	fin.seekp(pos,ios::cur);
	fin.write((char*)(this), sizeof(*this));
	fin.close();

}
///////////////////////////////////////////////////
char *Account_holders:: getfname()
{
	return this->fname;
};

////////////////////////////////////////////////////
//////////////set Transaction history
void T_history::setTransaction(int t,char *Name,char *S_name,int S_Acc)
{
		ofstream f;
		 f.open(Name,ios::app|ios::out|ios::binary);
		time_t tt= time(NULL);
		strcpy(this->Time_,ctime(&tt));
		strcpy(this->S_name,S_name);
		this->S_Acc=S_Acc;
		this->Amount=t;
		f.write((char *) this,sizeof(*this));
		f.close();
}
//////////////////////////////////////////////////////
///show Transaction history

void T_history::show_Thistory(char *Name)
{
	ifstream f;
	f.open(Name,ios::in|ios::binary);
	if(f.peek()==EOF)
	{
		cout<<"\n\t\t NO DATA FOUND";
		return;
	}
	cout<<"\n\n\t\tAmount\t\tSender Name \t\t Sender Acc\t\t Time\n\n";
	f.read((char *)(this),sizeof(*this));
	while(!f.eof())
	{
		cout<<"\t\t"<<this->Amount<<"\t\t"<<this->S_name<<"\t\t\t"<<this->S_Acc<<"\t\t\t"<<this->Time_;
		f.read((char *)(this),sizeof(*this));	
	}
}
