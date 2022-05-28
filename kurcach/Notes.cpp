#include "Notes.h"

using namespace std;



void show_menu() {
	cout << "[1] Добавить запись." << endl;
	cout << "[2] Показать все записи." << endl;
	cout << "[3] Найти запись." << endl;
	cout << "[4] Удалить запись." << endl;
	cout << "[5] Удалить все записи." << endl;;
}




void NoteBook::add_note() {
	Notes a;
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "[-] File is note opened!";
		exit(EXIT_FAILURE);
	}
	cout << "Note to add: " << endl;
	cout << "Дата создания записи: "<<endl;
	a.Set_data_create();
	file << "Дата создания записи: " << a.Get_data_create() << ' ';
	cout << "Время создания записи: "<<endl;
	a.Set_time_create();
	file << "Время создания записи: " << a.Get_time_create() << ' ';
	cout << "Запись: "<< endl;
	a.Set_note();
	file << "Запись: " << a.Get_note() << ' ';
	cout << "Дедлайн: " << endl;
	a.Set_dedline();
	file << "Дедлайн: " << a.Get_dedline() << endl;
	file.close();
}





void NoteBook::see_all_notes() {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "No notes or file no find!"<<endl;
		return;
	}
	string one_note;
	cout << "Мои заметки: " << endl;
	for (int i = 1; !file.eof(); i++) {
		getline(file, one_note);
		if (one_note.empty())
			continue;
		cout << "[" << i << "]" << one_note << endl;
	}
	file.close();
}




string* NoteBook::find_note(const string& note_to_find, int &n_count) {
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "No notes! Add them!" << endl;
		return nullptr;
	}
	string one_note;
	string* found_notes = nullptr;
	string* found_notes_tmp = nullptr;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_note);
		if (one_note.find(note_to_find) != -1) {
			count++;
			found_notes_tmp = new string[count];
			// Копируем все найденные заметки
			for (int i = 0; i < count - 1; i++)
				found_notes_tmp[i] = found_notes[i];
			// добавляем найденную заметку
			found_notes_tmp[count - 1] = one_note;
			// Удаляем старое содержимое found_notes
			delete[] found_notes;
			// found_notes указывает на новый массив
			found_notes = found_notes_tmp;
		}
	}
	file.close();
	n_count = count;
	return found_notes;
}




string* NoteBook::all_notes(int& n_count) {
	string* all_notes = nullptr;
	string* all_notes_ptr = nullptr;
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "File is not opened!";
		exit(EXIT_FAILURE);
	}
	string one_note;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_note);
		if (one_note.empty())
			continue;
		count++;
		all_notes_ptr = new string[count];
		//Копируем уже считанные заметки
		for (int i = 0; i < count - 1; i++)
			all_notes_ptr[i] = all_notes[i];
		//Добавляем новую заметку
		all_notes_ptr[count - 1] = one_note;
		//Очищаем старый массив all_notes
		delete[] all_notes;
		//all_notes указывает на новый массив;
		all_notes = all_notes_ptr;
		all_notes_ptr = nullptr;
	}
	file.close();
	n_count = count;
	return all_notes;
}





void NoteBook::remove_note(string* all_notes_arr, int count, int choice) {
	ofstream file("notes.txt");
	if (!file.is_open()) {
		cout << "[-]Error! File is not opened!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < count; i++) {
		if (i + 1 == choice)
			continue;
		file << all_notes_arr[i] << endl;
	}
	file.close();
}




void NoteBook::remove_all() {
	fstream file("notes.txt", ios::out | ios::trunc);
	if (!file.is_open()) {
		cout << "File is not opened!" << endl;
		exit(EXIT_FAILURE);
	}
	file.close();
}