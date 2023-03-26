//#include "tinyxml2.hpp"
//#include "Q1.h"
//#include<iostream>
//#include<string>
//#include <sstream>
//
//using namespace std;
//
//
//int main()
//{
//	tinyxml2::XMLDocument file;
//	file.LoadFile("inputfile.xml");
//
//	if (file.Error())
//	{
//		cout << "Failed in parsing!" << endl;
//		exit(-1);
//	}
//
//	const char* arr[3] = { "ArrivalTime", "Type","code" };
//	int arr_size = 3;
//	Maintain M;
//
//
//	tinyxml2::XMLElement* p = file.RootElement()->FirstChildElement("Configuration")->FirstChildElement("Processes");
//
//	if (p != nullptr)
//	{
//		tinyxml2::XMLElement* child = p->FirstChildElement("Process");
//		int x;
//		while (child != nullptr)
//		{
//			for (int i = 0; i < arr_size; ++i)
//			{
//				tinyxml2::XMLElement* text = child->FirstChildElement(arr[i]);
//
//				if (arr[i] == "code")
//				{
//					Process* P1 = new Process();
//					string s1;
//					stringstream ss(text->GetText());
//					P1->arrivaltime = x;
//					cout << arr[i] << ": " << endl;
//					while (getline(ss, s1, '\n'))
//					{
//						if (s1 == "")
//							continue;
//						P1->enqueue(P1->Create(s1));
//						cout << s1 << endl;
//					}
//					M.add_process(P1,M.waiting,M.W_end);
//				}
//
//				else if (arr[i] == "ArrivalTime") {
//					x = stoi(text->GetText());
//					cout << arr[i] << ": " << text->GetText() << endl;
//				}
//				else {
//					cout << arr[i] << ": " << text->GetText() << endl;
//				}
//			}
//
//			cout << endl;
//
//			child = child->NextSiblingElement("Process");
//		}
//	}
//
//	cout << "--------------------------------\n";
//	M.print();
//	cout << "--------------------------------\n";
//	M.run();
//	cout << "--------------------------------\n";
//	/*cout << " High Priority\n";
//	cout << "--------------------------------\n";
//	M.print_HP();
//	cout << "--------------------------------\n";
//	M.print();*/
//	//M.run();
//	/*M.print();
//
//	cout << "--------------------------------\n";
//	cout << " High Priority\n";
//	cout << "--------------------------------\n";
//	M.print_HP();
//	cout << "--------------------------------\n";
//	M.run();
//	M.print();*/
//
//
//	return 0;
//}