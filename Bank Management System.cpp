#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;

const int max_account = 100;

int acc_num[max_account];
string name[max_account];
int deposit[max_account];
int balance[max_account];
int accountCount = 0;


//function prototype
void create_account();
void display_Allaccounts();
void deposit_withdraw(int search_acc, int option);
void balance_inquiry(int search_acc);
void remove_account(int search_acc);


int main() {
	int choice;
	int search_acc;
	
	while (true) {
		cout << "\n\n\n\n\n\n\t\t\t" << setw(20) << "=== MAIN MENU ===";
        cout << "\n\n\t\t\t1. CREATE NEW ACCOUNT";
        cout << "\n\n\t\t\t2. DEPOSIT AMOUNT";
        cout << "\n\n\t\t\t3. WITHDRAW AMOUNT";
        cout << "\n\n\t\t\t4. BALANCE ENQUIRY";
        cout << "\n\n\t\t\t5. REMOVE ACCOUNT";
        cout << "\n\n\t\t\t6. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\t\t\t7. EXIT";
        cout << "\n\n\t\tSelect Your Option (1-7): ";
        cin >> choice;
        cout << "\n\n";
        
        switch (choice) {
        	case 1 :
        		create_account();
        		break;
        	case 2 :
        		cout << "\n\n\t=== TO DEPOSIT AMOUNT ===";
        		cout << "\n\n\tEnter account number : ";
        		cin >> search_acc;
        		deposit_withdraw(search_acc, 1);
        		break;
        	case 3 :
        		cout<< "\n\n\t=== TO WITHDRAW AMOUNT ===";
				cout << "\n\n\t\tEnter account number : ";
        		cin >> search_acc;
        		deposit_withdraw(search_acc, 2);
        		break;
        	case 4 :
        		cout<< "\n\n\t=== BALANCE INQUIRY ===";
        		cout << "\n\n\tEnter account number : ";
        		cin >> search_acc;
        		balance_inquiry(search_acc);
        		break;
        	case 5 :
        		cout<< "\n\n\t=== CLOSE AN ACCOUNT ===";
        		cout << "\n\n\tEnter account number : "; 
				cin >> search_acc;
        		remove_account(search_acc);
        		break;
        	case 6 :
        		display_Allaccounts();
        		break;
        	case 7:
        		cout << "Exiting...";
        		return 0;
        	default : 
        		cout << "\n\t\aInvalid choice. Please enter a number between 1 and 7.";
        			cout << "\n\tPress enter to continue...";
        			cin.ignore();
	    			cin.get();
		} 
	}
}


void create_account() {
	cout << "Enter account number(must be 6 digit) : "; cin >> acc_num[accountCount];
	cin.ignore();
	cout << "Enter account holder name : "; 
	getline(cin, name[accountCount]);
	cout << "Enter initial amount : ";
	cin >> balance[accountCount];
		
	accountCount++;
		
	cout << "\n\tAccount created succesfully..." << endl;
	cout << "\n\tPress enter to continue...";
    cin.ignore();
    cin.get();

}



void display_Allaccounts() {
	if (accountCount != 0) {
		cout << "\n\n\t\t\t\t\tACCOUNT HOLDER LIST\n\n";
	    cout << "\t\t\t==========================================================\n";
	    cout << "\t\t\t   A/c no.              NAME\t               Balance\n";
	    cout << "\t\t\t==========================================================\n";
	    for (int i = 0; i < accountCount; ++i) {
	    	cout << "\t\t\t";
	    	cout << i+1 << ".  " << acc_num[i] << setw(12+name[i].length()) << name[i] << setw(17) << balance[i] << endl;
	    } 
		cin.ignore();
	    cin.get();
	    
	} else {
		cout << "\n\n\t\t===== ACCOUNT HOLDER LIST =====\n\n";
		cout << "\a\n\t\t       ! NO RECORD YET !";
		cout << "\n\n\t\t===============================";
		cout << "\n\n\t\tPress Enter to continue...";
		cin.ignore();
		cin.get();
	}
}


void deposit_withdraw(int search_acc, int option) {
	int index = -1;
	int amount;
	
    for (int i = 0; i < accountCount; ++i) {
        if (acc_num[i] == search_acc && accountCount > 0) {
            index = i;
            break;
		}	
    }
	if (option == 1) {
		if (index != -1) {
			cout <<"\n\n\tACCOUNT HOLDER : " << name[index];
			cout <<"\n\tBALANCE : $ " << balance[index] << endl; 
	        cout << "\n\nEnter amount to deposit: ";
	        cin >> amount;
	
	        balance[index] += amount;
	
	        cout << "\n\tDeposit of $" << amount << " successful." << endl;
	    } else {
	        cout << "\a\n\t! Account not found !" << endl;
	        cin.ignore();
	        cin.get();
	    }
	} else if (option == 2) {
		if (index != -1) {
			cout <<"\n\n\tACCOUNT HOLDER : " << name[index];
			cout <<"\n\tBALANCE : $ " << balance[index] << endl; 
	        cout << "\n\nEnter amount to withdraw: ";
	        cin >> amount;
	
	        balance[index] -= amount;
			
			if (amount < balance[accountCount]) {
				cout << "\a\n\t! Insufficient balance !";
				cin.ignore();
				cin.get();
			} else {
				cout << "\n\tWithdraw of $" << amount << " successful." << endl;
			}

	    } else {
	        cout << "\a\n\t\t! Account not found !" << endl;
	        cin.ignore();
	        cin.get();
	    }
	}
}
	
	
void balance_inquiry(int search_acc) {
    int index = -1;
    
    for (int i = 0; i < accountCount; ++i) {
        if (acc_num[i] == search_acc) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "\n\n\tAccount holder: " << name[index] << endl;
        cout << "\n\tAccount balance: $ " << balance[index] << endl;
        cout << "\n\n\tPress enter to continue...";
        cin.ignore();
        cin.get();
    } else {
        cout << "\a\n\t\t! Account not found !" << endl;
        cout << "\n\tPress enter to continue...";
        cin.ignore();
        cin.get();
    }
}


void remove_account(int search_acc) {
    int index = -1;
    
    for (int i = 0; i < accountCount; ++i) {
        if (acc_num[i] == search_acc) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < accountCount - 1; ++i) {
            acc_num[i] = acc_num[i + 1];
            name[i] = name[i + 1];
            balance[i] = balance[i + 1];
        }
        accountCount--;

        cout << "\n\n\tAccount removed successfully." << endl;
        cout << "\n\tPress enter to continue...";
        cin.ignore();
        cin.get();
    } else if (accountCount > 0) {
        cout << "\a\n\t! Account not found !" << endl;
        cout << "\n\tPress enter to continue...";
        cin.ignore();
        cin.get();
    }else {
    	cout << "\a\n\t! NO RECORDS YET !" << endl;
        cout << "\n\tPress enter to continue...";
        cin.ignore();
        cin.get();
	}
}

