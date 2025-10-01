//
// Created by perag on 30/09/2025.
//
#include "To_do_List.h"
#include <iostream>
using namespace std;

void To_do_List::addTask(const string &name, const string &description, const string &expirationDate) {
    if(name.empty()) {
        printf("Non è possibile creare task senza nome");
    } else {
        tasks.emplace_back(name, description, expirationDate);
        cout << "Task aggiunta: " << name << endl;
    }
}

void To_do_List::deleteTask(int index) {
    if (tasks.empty()) {
        printf("Non è presente nessuna Task da eliminare!");
    }
    int i = index - 1;
    if (i < 0 || i >= tasks.size()) {
        printf("Indice non valido per la Task.");
    }
    string taskName = tasks[i].getName();
    tasks.erase(tasks.begin() + i);
    cout << "\nTask eliminata: " << taskName << endl;
}

void To_do_List::displayTask() const {
    if (tasks.empty()) {
        printf("Non è presente nessuna Task da mostrare!");
    }
    cout << "\nLista delle Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "\nTask " << (i + 1) << ":" << endl;
        tasks[i].showTask();
    }
}