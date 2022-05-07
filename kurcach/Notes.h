#ifndef KURCACH_H
#define KURCACH_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//struct NoteBook{
//private:
//	vector <Notes> MyBook(5)




struct Notes {
private:
	string time_create;
	string data_create;
	string note;
	string dedline;
public:
	void Set_time_create() {
		string tc;
		getline(cin, tc);
		time_create = tc;
	}
	void Set_data_create() {
		string dc;
		getline(cin, dc);
		data_create = dc;
	}
	void Set_note() {
		string nt;
		getline(cin, nt);
		note = nt;
	}
	void Set_dedline() {
		string ded;
		getline(cin, ded);
		dedline = ded;
	}
	string Get_time_create() {
		return time_create;
	}
	string Get_data_create() {
		return data_create;
	}
	string Get_note() {
		return note;
	}
	string Get_dedline() {
		return dedline;
	}
	void add_note();
	void see_all_notes();
	string* find_note(const string& note_to_find, int& n_count);
	string* all_notes(int& count);
	void remove_note(string* all_notes_arr, int count, int choice);
	void remove_all();
};


void show_menu();

#endif