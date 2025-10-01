//
// Created by perag on 24/09/2025.
//
#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <vector>
#include "Task.h"

using namespace std;

class To_do_List {
private:
    vector<Task> tasks;

public:
    void addTask(const string &name, const string &description, const string &expirationDate);
    void deleteTask(int index);
    void displayTask() const;
};

#endif