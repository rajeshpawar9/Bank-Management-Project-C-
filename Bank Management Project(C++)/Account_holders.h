#include<iostream>
#include<string.h>
#include<time.h>
#include<fstream>
using namespace std;

class Account_holders{
	int Acc_No;
	char Password[7];
	char fname[10],lname[10];
	int Acc_Balance;
	public:
	Account_holders();
	void write_Acc();
	void show_All_Acc();
	void show();
	void create_Acc();
	void search_Acc(int );
	void delete_Acc(int);
	void credit();
	void debit();
	int check_pass(int Mode);
	void welcome();
	void update();
	void check_bal();
	void transfer_money();
	void Admin_update();
	char *getfname();

};
class T_history{
	char Time_[17];
	int Amount;
	int S_Acc;
	char S_name[15];
	public:
		void setTransaction(int ,char *,char *,int);
		void show_Thistory(char *);
};

