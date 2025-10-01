//
// Created by perag on 24/09/2025.
//
#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H
#include <iostream>

using namespace std;

class Task {
private:
    string name;
    string description;
    string expirationDate;
    bool completed;

    bool isValidDate(const std::string &date);

public:
    Task(const string& name, const string& description, const string& expirationDate) :
            name(name), description(description), completed(false) {
        setExpirationDate(expirationDate);
    }

    string getName() const;

    void setExpirationDate(const string& newExpirationDate);

    void showTask() const;
};

#endif //TODOLIST_TASK_H