#include <iostream>
#include <conio.h>
#include "kurcach.h"
#include <string>
#include <fstream>






int main() {
	setlocale(0, "rus");
	char choice;
	char Exit;
	do {
		do {
			system("cls");
			show_menu();
			cout << "������ �������: ";
			choice = _getch();
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6');
		switch (choice) {
		case '1': {
			Notes a;
			system("cls");
			string new_note;
			cout << "Note to add: "<<endl;
			/*getline(cin, new_note);
			getline(cin, new_note);*/
			add_note();
			cout << "Note added!" << endl;
		}
				break;
		case '2': {
			system("cls");
			see_all_notes();}
				break;
		case '3': {
			system("cls");
			string note_to_find;
			cout << "Note to find: ";
			getline(cin, note_to_find);
			int n_found = 0;
			string* found_notes = find_one_note(note_to_find, n_found);
			if (found_notes) {
				cout << "Found notes: ";
				for (int i = 0; i < n_found; i++)
					cout << found_notes[i] << endl;
				delete[] found_notes;
			}
			else {
				cout << "no such note!" << endl;
			};
		}
				break;
		case '4': {
			system("cls");
			//�������� ��� �������
			int count = 0;
			string* all_notes_arr = all_notes(count);
			//������� �� � �������
			cout << "All notes: " << endl;
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
			cout << "Number of note to remove: ";
			int choice = 0;
			cin >> choice;
			remove_one_note(all_notes_arr, count, choice);
			cout << "Your note removed" << endl;
			delete[] all_notes_arr;;
		}
				break;
		case '5': {
			system("cls");
			remove_all_notes();
			cout << "Remove all notes!" << endl;
		}
				break;
		case '6': {
			system("cls");
			//�������� ��� �������
			int count = 0;
			string* all_notes_arr = all_notes(count);
			//������� �� � �������
			cout << "All notes: " << endl;
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
			cout << "Number of note to edit: ";
			int choice = 0;
			cin >> choice;
			remove_one_note(all_notes_arr, count, choice);
			add_note();
			cout << "Note changed!" << endl;
			delete[] all_notes_arr;
		}
		}	cout << endl << "Do you want to make another operation? (1 - yes, 0 - no)" << endl;
		fflush(stdin);
		Exit = _getch();
	} while (Exit != '0');
}