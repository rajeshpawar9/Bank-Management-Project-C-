#include"Account_holders.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
 {
	Account_holders a;
	int ch1=0,ch2=0,ch3=0,Mode;
	do
	{
		cout<<"\n\n\t\t\t\t======================\n";
		cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout<<"\n\t\t\t\t======================\n";
		cout<<"\n\t\t::MAIN MENU::";
		cout<<"\n\n\n\t\t1.Admin";
		cout<<"\n\n\t\t2.Login";
		cout<<"\n\n\t\t3.Register New Account:";
		cout<<"\n\n\t\t10.EXIT:";
		cout<<"\n\n\t\tEnter choice  ";
		cin>>Mode;
		system("CLS");
		ch1=a.check_pass(Mode);
		
		switch(ch1)
		{
			case 1:
				{
					do
					{	
						//system("CLS");
						cout<<"\n\n\t\t ADMIN:";
						cout<<"\n\n\t1.Show All Accounts:";
						cout<<"\n\n\t2.Delete Account";
						cout<<"\n\n\t3.Update";
						cout<<"\n\n\t4.Search Account";
						cout<<"\n\n\t10.Back To Main Menu:";
						cout<<"\n\n\t\tEnter choice  ";	
						cin>>ch2;
						system("CLS");
						switch(ch2)
							{
							case 1:
								
								a.show_All_Acc();
								break;
							case 2:
								{
								
								int Acc_NO;
								cout<<"\n\n\tEnter Account Number:";
								cin>>Acc_NO;
								a.delete_Acc(Acc_NO);
								break;
								}
							case 3:
								
								a.Admin_update();
								break;
							case 4:
								int Acc_NO;
								cout<<"\n\n\tEnter Account Number:";
								cin>>Acc_NO;
								a.search_Acc(Acc_NO);
								break;
							default:
								cout<<"\n\n\t Invalid choice";
							}
						
						}
						while(ch2!=10);
					break;
				}
			case 2:
				{
				 
					do
					{
						cout<<"\n\n\t\t 1.Debit Money:";
						cout<<"\n\n\t\t 2.credit Money:";
						cout<<"\n\n\t\t 3.Check Balance:";
						cout<<"\n\n\t\t 4.Update :";
						cout<<"\n\n\t\t 5.Transfer Money:";
						cout<<"\n\n\t\t 6.History:";
						cout<<"\n\n\t\t 10.Back To Main Menu";
						cin>>ch3;
						system("CLS");
						switch(ch3)
						{ 
							case 1:
								{
									
									a.debit();
									break;
								}
							case 2:
								{
									
									a.credit();
									break;
								}
							case 3:
								{
								
								a.check_bal();
								break;	
								}
							case 4:
								
								a.update();
								break;
							case 5:
								{
								
									a.transfer_money();
									break;
								}
							case 6:
								{
									T_history T;
									T.show_Thistory(a.getfname());
									break;
								}
							case 10:
								{
									break;
								}
							default:
								{	
									cout<<"\n\t\t Invalid choice";
									break;
								}
									
						}
					
					
					}
					while(ch3!=10);
				}
				
					break;
			case 3:
				{
					
					a.create_Acc();
					break;
					
				}
			case 10:
				{
					//cout<<"\n\t\t Bye";
					break;
				}
			case 11:
				{
					
					cout<<"\n\t\t Wrong Id and Password:";
					break;
				}
			default:
				{
					
					cout<<"\n\t\t Invalid choice";
				}
				
		}
			
	}
	while(ch1!=10);	
}


