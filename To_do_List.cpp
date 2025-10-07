//
// Created by perag on 30/09/2025.
//
#include "To_do_List.h"
#include <stdexcept>
#include <iostream>
using namespace std;

void To_do_List::addTask(const string &name, const string &description, const string &expirationDate) {
    if(name.empty()) {
        throw invalid_argument("Non è possibile creare task senza nome");
    } else {
        tasks.emplace_back(name, description, expirationDate);
        cout << "Task aggiunta: " << name << endl;
    }
}

void To_do_List::deleteTask(int index) {
    if (tasks.empty()) {
        throw runtime_error("Non è presente nessuna Task da eliminare!");
    }
    int i = index - 1;
    if (i < 0 || i >= tasks.size()) {
        throw out_of_range("Indice non valido per la Task.");
    }
    string taskName = tasks[i].getName();
    tasks.erase(tasks.begin() + i);
    cout << "\nTask eliminata: " << taskName << endl;
}

void To_do_List::displayTask() const {
    if (tasks.empty()) {
        throw runtime_error("Non è presente nessuna Task da mostrare!");
    }
    cout << "\nLista delle Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "\nTask " << (i + 1) << ":" << endl;
        tasks[i].showTask();
    }
}

void To_do_List::markTaskCompleted(int index) {
    if (tasks.empty()) {
        throw runtime_error("Non è presente nessuna Task da segnare come 'Completata'!");
    }
    int i = index - 1;
    if (i < 0 || i >= tasks.size()) {
        throw out_of_range("Indice non valido per la Task.");
    }
    tasks[i].markCompleted();
    cout << "\nTask segnata come 'Completata': " << tasks[i].getName() << endl;
}

void To_do_List::editTask(int index, const string &newName, const string &newDescription, const string &newExpirationDate) {
    if (tasks.empty()) {
        throw runtime_error("Non è presente nessuna Task da modificare!");
    }
    int i = index - 1;
    if (i < 0 || i >= tasks.size()) {
        throw out_of_range("Indice non valido per la Task.");
    }
    tasks[i].setName(newName);
    tasks[i].setDescription(newDescription);
    tasks[i].setExpirationDate(newExpirationDate);
    cout << "\nTask modificata: " << newName << endl;
}

std::vector<Task> To_do_List::showNotCompletedTasks() const {
    std::vector<Task> results;
    for (const auto &task : tasks) {
        if (!task.isCompleted()) {
            results.push_back(task);
        }
    }
    return results;
}