#include <iostream>
#include <conio.h>
#include "Notes.h"
#include <string>
#include <fstream>






int main() {

	/*NoteBook myBook;
	myBook.addNote()*/
	setlocale(0, "rus");
	char choice;
	char Exit;
	Notes a;
	NoteBook b;
	do {
		do {
			system("cls");
			show_menu();
			cout << "Выбери функцию: ";
			choice = _getch();
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6');
		switch (choice) {
			case '1': {
				system("cls");
				a.add_note();
				cout << "Note added!" << endl;
			}
					break;
			case '2': {
				system("cls");
				b.see_all_notes();
			}
					break;
			case '3': {
				system("cls");
				string note_to_find;
				cout << "Note to find: ";
				getline(cin, note_to_find);
				int n_found = 0;
				string* found_notes = a.find_note(note_to_find, n_found);
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
				//Получаем все заметки
				int count = 0;
				string* all_notes_arr = a.all_notes(count);
				//Выводим их в консоль
				cout << "All notes: " << endl;
				for (int i = 0; i < count; i++)
					cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
				cout << "Number of note to remove: ";
				int choice = 0;
				cin >> choice;
				a.remove_note(all_notes_arr, count, choice);
				cout << "Your note removed" << endl;
				delete[] all_notes_arr;
				break;
			}
					break;
			case '5': {
				system("cls");
				b.remove_all();
				cout << "Remove all notes!" << endl;
				break;
			}
					break;
			case '6': {
				system("cls");
				//Получаем все заметки
				int count = 0;
				string* all_notes_arr = a.all_notes(count);
				//Выводим их в консоль
				cout << "All notes: " << endl;
				for (int i = 0; i < count; i++)
					cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
				cout << "Number of note to edit: ";
				int choice = 0;
				cin >> choice;
				a.remove_note(all_notes_arr, count, choice);
				a.add_note();
				cout << "Note changed!" << endl;
				delete[] all_notes_arr;
			}
		}	
		cout << endl << "Do you want to make another operation? (1 - yes, 0 - no)" << endl;
		fflush(stdin);
		Exit = _getch();

	} while (Exit != '0');
}