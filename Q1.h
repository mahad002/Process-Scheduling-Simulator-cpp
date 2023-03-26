#pragma once
#include "maze.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "tinyxml2.hpp"

using namespace std;
//using namespace pugixml;


struct node1 {
	string data;
	node1* next;
};

class Process {
public:
	int arrivaltime;
	int bursttime;
	node1* Instruction;
	node1* end;
	int wait;
	int turntime;
	string status;
	Process* next1;

public:
	Process();
	node1* Create(string);
	void enqueue(node1*);
	node1* dequeue();
	bool Isempty();
};

class Maintain {
public:
	Process* waiting;
	Process* W_end;

	Process* HP;
	Process* H_end;

	Process* LP;
	Process* L_end;

	Process* Ready;
	Process* R_end;

	Process* screen;
	Process* S_end;
	int s_time;

	Process* keyboard;
	Process* K_end;
	int k_time;

	Process* file;
	Process* F_end;
	int f_time;

	Process* printer;
	Process* P_end;
	int p_time;

	Process* disk;
	Process* D_end;
	int d_time;

public:
	Maintain();
	void add_process(Process*,Process*&,Process*&);
	Process*& delete_process(Process*&);
	void run();
	void print();
	void print(Process*&);
	void print_HP();
};

