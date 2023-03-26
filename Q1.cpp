#include "Q1.h"
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;
using namespace std;

Process::Process() {
	arrivaltime = 0;
	bursttime = 0;
	Instruction = NULL;
	wait = 0;
	turntime = 0;
	status = "";
}

Maintain::Maintain() {
	waiting = NULL;
	W_end = NULL;
	HP = NULL;
	H_end = NULL;
	LP = NULL;
	L_end = NULL;
	Ready = NULL;
	R_end = NULL;
	screen = NULL;
	S_end = NULL;
	s_time = 0;
	keyboard = NULL;
	K_end = NULL;
	k_time = 0;
	file = NULL;
	F_end = NULL;
	f_time = 0;
	printer = NULL;
	P_end = NULL;
	p_time = 0;
	disk = NULL;
	D_end = NULL;
	d_time = 0;
}

node1* Process::Create(string x) {
	node1* newNode = new node1();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void Process::enqueue(node1* temp) {
	if (Isempty()) {
		Instruction = temp;
		end = temp;
		Instruction->next = NULL;
		end->next = NULL;
	}
	else {
		end->next = temp;
		end = temp;
		end->next = NULL;
	}
}

node1* Process::dequeue() {
	int num = -1;
	if (Isempty()) {
		cout << "EMPTY!\n";
		return NULL;
	}
	else {
		node1* temp = Instruction->next;
		node1* newnode = new node1;
		newnode->data = Instruction->data;
		delete Instruction;
		newnode->next = NULL;
		Instruction = temp;
		if (!Instruction) {
			Instruction = NULL;
		}
		return newnode;
	}
}

bool Process::Isempty() {
	if (Instruction) return false;

	return true;
}

void Maintain::print() {
	cout << "\n\nWaiting\n";
	Process* M = waiting;
	while (M) {
		node1* P = M->Instruction;
		while (P) {
			cout << P->data << endl;
			P = P->next;
		}

		cout << "\nArrival Time : " << M->arrivaltime << endl;
		cout << "\nBurst Time : " << M->bursttime << endl;
		M = M->next1;
	}
}

void Maintain::print_HP() {
	cout << "--------------------------------\n";
	cout << "HIGH PRIORITY\n";
	cout << "--------------------------------\n";
	Process* M = HP;
	while (M) {
		node1* P = M->Instruction;
		while (P) {
			cout << P->data << endl;
			P = P->next;
		}

		cout << "\nArrival Time : " << M->arrivaltime << endl;
		cout << "\nBurst Time : " << M->bursttime << endl;
		M = M->next1;

		cout << "--------------------------------\n";
	}
}

void Maintain::print(Process*& PP) {
	Process* M = PP;
	while (M) {
		node1* P = M->Instruction;
		while (P) {
			cout << P->data << endl;
			P = P->next;
		}

		cout << "\nArrival Time : " << M->arrivaltime << endl;
		cout << "\nBurst Time : " << M->bursttime << endl;
		M = M->next1;
	}
}


void Maintain::add_process(Process* P, Process*& PP, Process*& end) {
	if (PP == NULL) {
		PP = P;
		end = P;
		end->next1 = NULL;
	}
	else {
		end->next1 = P;
		end = end->next1;
		//end->next1 = NULL;
	}

	end->bursttime = 0;
	node1* curr = end->Instruction;
	while (curr) {
		//PP->bursttime++;
		if (curr->data == "WRITESCREEN" || curr->data == "WRITEKEYBOARD" || curr->data == "WRITEFILE" || curr->data == "WRITEPRINTER" || curr->data == "WRITEDISK") {
			end->bursttime += 3;
		}
		else if (curr->data == "READSCREEN" || curr->data == "READKEYBOARD" || curr->data == "READFILE" || curr->data == "READPRINTER" || curr->data == "READDISK") {
			end->bursttime += 3;
		}
		else if (curr->data == "BREAKPOINT") {
			
		}
		else {
			end->bursttime++;
		}

		curr = curr->next;
	}



}

//void Process :: 

Process*& Maintain::delete_process(Process*& PP) {
	int num = -1;
	Process* temp;
	if (!PP) {
		cout << "EMPTY!\n";
		temp = NULL;
		return temp;
	}
	else {
		temp = PP;
		PP = PP->next1;
		//delete temp;

		return *&temp;
	}
}

void Maintain::run() {
	int l = 0, m = 0, n = 0, o = 0;
	int time = 0;
	int x = 1, y = 0;
	string check;
	int total = 0;
	Process* curr = waiting;
	while (curr) {
		total += curr->bursttime;
		curr = curr->next1;
	}
	//Process* curr = waiting;
	time = 0;
	while(waiting||HP||LP||screen||keyboard||file||printer||disk) {
	//while (total != time) {
		if (waiting && waiting->arrivaltime == time) {
			add_process(delete_process(waiting), HP, H_end);
		}

		//print_HP();
		//print();
		if (HP) {
			if (HP->Instruction) {
				if (HP->Instruction->data == "WRITESCREEN" || HP->Instruction->data == "READSCREEN") {
					s_time++;
					HP->bursttime--;
					if (s_time >= 3) {
						s_time = 0;
						node1* temp1 = HP->dequeue();
						delete temp1;
					}
				}
				else if (HP->Instruction->data == "WRITEKEYBOARD" || HP->Instruction->data == "READKEYBOARD") {
					k_time++;
					HP->bursttime--;
					if (k_time >= 3) {
						k_time = 0;
						node1* temp1 = HP->dequeue();
						delete temp1;
					}
				}
				else if (HP->Instruction->data == "WRITEFILE" || HP->Instruction->data == "READFILE") {
					f_time++;
					HP->bursttime--;
					if (f_time >= 3) {
						f_time = 0;
						node1* temp1 = HP->dequeue();
						delete temp1;
					}
				}
				else if (HP->Instruction->data == "WRITEPRINTER" || HP->Instruction->data == "READPRINTER") {
					p_time++;
					HP->bursttime--;
					if (p_time >= 3) {
						p_time = 0;
						node1* temp1 = HP->dequeue();
						delete temp1;
					}
				}
				else if (HP->Instruction->data == "WRITEDISK" || HP->Instruction->data == "READDISK") {
					d_time++;
					HP->bursttime--;
					if (d_time >= 3) {
						d_time = 0;
						node1* temp1 = HP->dequeue();
						delete temp1;
					}
				}
				else if (HP->Instruction->data == "BREAKPOINT") {
					cout << "----------------------------------\n";
					cout << "            BREAKPOINT\n";
					cout << "----------------------------------\n";
					cout << "    Waiting\n";
					cout << "----------------------------------\n";
					print(waiting);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    High Priority\n";
					cout << "----------------------------------\n";
					print(HP);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    Low Priority\n";
					cout << "----------------------------------\n";
					print(LP);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    Screen\n";
					cout << "----------------------------------\n";
					print(screen);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    Keyboard\n";
					cout << "----------------------------------\n";
					print(keyboard);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    File\n";
					cout << "----------------------------------\n";
					print(file);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    Printer\n";
					cout << "----------------------------------\n";
					print(printer);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "Disk\n";
					cout << "----------------------------------\n";
					print(disk);
					cout << "----------------------------------\n";
				}
				else if (HP->bursttime == 0) {
					//HP->bursttime--;
					HP->turntime = time - HP->arrivaltime;
					cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
					cout << "Turn Around Time : " << HP->turntime << endl;
					cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
					Process*& temp1 = delete_process(HP);
					delete temp1;
				}
				else {
					HP->bursttime--;
					node1* temp1 = HP->dequeue();
					delete temp1;
				}
			}
		}

		if (HP) {
			if (HP->next1) {
				if (HP->bursttime > HP->next1->bursttime) {
					if (HP->Instruction->data == "WRITESCREEN" || HP->Instruction->data == "READSCREEN") {
						add_process(delete_process(HP), screen, S_end);
					}
					else if (HP->Instruction->data == "WRITEKEYBOARD" || HP->Instruction->data == "READKEYBOARD") {
						add_process(delete_process(HP), keyboard, K_end);
					}
					else if (HP->Instruction->data == "WRITEFILE" || HP->Instruction->data == "READFILE") {
						add_process(delete_process(HP), file, F_end);
					}
					else if (HP->Instruction->data == "WRITEPRINTER" || HP->Instruction->data == "READPRINTER") {
						add_process(delete_process(HP), printer, P_end);
					}
					else if (HP->Instruction->data == "WRITEDISK" || HP->Instruction->data == "READDISK") {
						add_process(delete_process(HP), disk, D_end);
					}
					else if (HP->Instruction->data == "BREAKPOINT") {
						cout << "----------------------------------\n";
						cout << "            BREAKPOINT\n";
						cout << "----------------------------------\n";
						cout << "    Waiting\n";
						cout << "----------------------------------\n";
						print(waiting);
						cout << "----------------------------------\n";
						cout << "----------------------------------\n";
						cout << "    High Priority\n";
						cout << "----------------------------------\n";
						print(HP);
						cout << "----------------------------------\n";
						cout << "----------------------------------\n";
						cout << "    Low Priority\n";
						cout << "----------------------------------\n";
						print(LP);
						cout << "----------------------------------\n";
						cout << "----------------------------------\n";
						cout << "    Screen\n";
						cout << "----------------------------------\n";
						print(screen);
						cout << "----------------------------------\n";
						cout << "----------------------------------\n";
						cout << "    Keyboard\n";
						cout << "----------------------------------\n";
						print(keyboard);
						cout << "----------------------------------\n";
						cout << "----------------------------------\n";
						cout << "    File\n";
						cout << "----------------------------------\n";
						print(file);
						cout << "----------------------------------\n";
						cout << "----------------------------------\n";
						cout << "    Printer\n";
						cout << "----------------------------------\n";
						print(printer);
						cout << "----------------------------------\n";
						cout << "----------------------------------\n";
						cout << "Disk\n";
						cout << "----------------------------------\n";
						print(disk);
						cout << "----------------------------------\n";
					}
					else {
						add_process(delete_process(HP), LP, L_end);
					}
				}
				if (HP->bursttime == 0) {
					HP->turntime = time - HP->arrivaltime;
					cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
					cout << "Turn Around Time : " << HP->turntime << endl;
					cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
					HP = NULL;
				}
			}
			else if(HP->Instruction) {
				if (HP->Instruction->data == "WRITESCREEN" || HP->Instruction->data == "READSCREEN") {
					add_process(delete_process(HP), screen, S_end);
				}
				else if (HP->Instruction->data == "WRITEKEYBOARD" || HP->Instruction->data == "READKEYBOARD") {
					add_process(delete_process(HP), keyboard, K_end);
				}
				else if (HP->Instruction->data == "WRITEFILE" || HP->Instruction->data == "READFILE") {
					add_process(delete_process(HP), file, F_end);
				}
				else if (HP->Instruction->data == "WRITEPRINTER" || HP->Instruction->data == "READPRINTER") {
					add_process(delete_process(HP), printer, P_end);
				}
				else if (HP->Instruction->data == "WRITEDISK" || HP->Instruction->data == "READDISK") {
					add_process(delete_process(HP), disk, D_end);
				}
			}
			else {
				if (HP->bursttime == 0) {
					HP->turntime = time - HP->arrivaltime;
					cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
					cout << "Turn Around Time : " << HP->turntime << endl;
					cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
					HP = NULL;
				}
			}

		}
		

		if (LP) {
			if (LP->Instruction) {
				if (LP->Instruction->data == "BREAKPOINT") {
					cout << "----------------------------------\n";
					cout << "            BREAKPOINT\n";
					cout << "----------------------------------\n";
					cout << "    Waiting\n";
					cout << "----------------------------------\n";
					print(waiting);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    High Priority\n";
					cout << "----------------------------------\n";
					print(HP);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    Low Priority\n";
					cout << "----------------------------------\n";
					print(LP);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    Screen\n";
					cout << "----------------------------------\n";
					print(screen);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    Keyboard\n";
					cout << "----------------------------------\n";
					print(keyboard);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    File\n";
					cout << "----------------------------------\n";
					print(file);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "    Printer\n";
					cout << "----------------------------------\n";
					print(printer);
					cout << "----------------------------------\n";
					cout << "----------------------------------\n";
					cout << "Disk\n";
					cout << "----------------------------------\n";
					print(disk);
					cout << "----------------------------------\n";
					node1* t = LP->dequeue();
					delete t;
				}
				if (LP->Instruction->data == "WRITESCREEN" || LP->Instruction->data == "READSCREEN") {
					add_process(delete_process(LP), screen, S_end);
				}
				else if (LP->Instruction->data == "WRITEKEYBOARD" || LP->Instruction->data == "READKEYBOARD") {
					add_process(delete_process(LP), keyboard, K_end);
				}
				else if (LP->Instruction->data == "WRITEFILE" || LP->Instruction->data == "READFILE") {
					add_process(delete_process(LP), file, F_end);
				}
				else if (LP->Instruction->data == "WRITEPRINTER" || LP->Instruction->data == "READPRINTER") {
					add_process(delete_process(LP), printer, P_end);
				}
				else if (LP->Instruction->data == "WRITEDISK" || LP->Instruction->data == "READDISK") {
					add_process(delete_process(LP), disk, D_end);
				}
				else {
					//add_process(delete_process(HP), LP, L_end);
					LP->bursttime--;
					node1* temp2 = LP->dequeue();
					delete temp2;
				}
				/*if (LP->bursttime == 0) {
					LP = NULL;

				}*/
			}
			else if (LP->bursttime == 0) {
				LP->turntime = time - LP->arrivaltime;
				cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
				cout << "Turn Around Time : " << LP->turntime << endl;
				cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
				LP = NULL;
			}
			
		}

		if (screen) {
			//Process* temp = screen;
			screen->bursttime--;
			l++;
			if ((l + s_time) > 3) {
				node1* temp1 = screen->dequeue();
				delete temp1;
				add_process(delete_process(screen), LP, L_end);
			}
		}
		if (keyboard) {
			//Process* temp = keyboard;
			keyboard->bursttime--;
			m++;
			if ((m + k_time) > 3) {
				node1* temp1 = keyboard->dequeue();
				delete temp1;
				add_process(delete_process(keyboard), LP, L_end);
			}
		}
		if (file) {
			//Process* temp = file;
			file->bursttime--;
			n++;
			if ((n + f_time) > 3) {
				node1* temp1 = file->dequeue();
				delete temp1;
				add_process(delete_process(file), LP, L_end);
			}
		}
		if (printer) {
			//Process* temp = printer;
			printer->bursttime--;
			y++;
			if ((y + p_time) > 3) {
				node1* temp1 = printer->dequeue();
				delete temp1;
				add_process(delete_process(printer), LP, L_end);
			}
		}
		if (disk) {
			//Process* temp = screen;
			disk->bursttime--;
			o++;
			if ((o + d_time) > 3) {
				node1* temp1 = disk->dequeue();
				delete temp1;
				add_process(delete_process(disk), LP, L_end);
			}
		}
		cout << "\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
		cout << "----------------------------------\n";
		cout << "    Waiting\n";
		cout << "----------------------------------\n";
		print(waiting);
		cout << "----------------------------------\n";
		cout << "----------------------------------\n";
		cout << "    High Priority\n";
		cout << "----------------------------------\n";
		print(HP);
		cout << "----------------------------------\n";
		cout << "----------------------------------\n";
		cout << "    Low Priority\n";
		cout << "----------------------------------\n";
		print(LP);
		cout << "----------------------------------\n";
		cout << "----------------------------------\n";
		cout << "    Screen\n";
		cout << "----------------------------------\n";
		print(screen);
		cout << "----------------------------------\n";
		cout << "----------------------------------\n";
		cout << "    Keyboard\n";
		cout << "----------------------------------\n";
		print(keyboard);
		cout << "----------------------------------\n";
		cout << "----------------------------------\n";
		cout << "    File\n";
		cout << "----------------------------------\n";
		print(file);
		cout << "----------------------------------\n";
		cout << "----------------------------------\n";
		cout << "    Printer\n";
		cout << "----------------------------------\n";
		print(printer);
		cout << "----------------------------------\n";
		cout << "----------------------------------\n";
		cout << "    Disk\n";
		cout << "----------------------------------\n";
		print(disk);
		cout << "----------------------------------\n";
		time++;
	}


	

	cout << "--------------------------------\n";
	cout << "TIME : " << time << endl;
	cout << "--------------------------------\n";
}


