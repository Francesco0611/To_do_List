//
// Created by perag on 24/09/2025.
//
#include "Task.h"
#include <regex>
#include <stdexcept>

string Task::getName() const {
    return name;
}

string Task::getDescription() const {
    return description;
}

string Task::getExpirationDate() const {
    return expirationDate;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setName(const std::string &newName) {
    name = newName;
}

void Task::setDescription(const std::string &newDescription) {
    description = newDescription;
}

bool Task::isValidDate(const std::string &date) {
    std::regex datePattern(R"(^(\d{2})-(\d{2})-(\d{4})$)");
    std::smatch match;

    if (!std::regex_match(date, match, datePattern))
        return false;

    if (match.size() != 4) // match[0] è l'intera stringa
        return false;

    int day = std::stoi(match[1].str());
    int month = std::stoi(match[2].str());
    int year = std::stoi(match[3].str());

    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int maxDay;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: maxDay = 31; break;
        case 4: case 6: case 9: case 11: maxDay = 30; break;
        case 2:
            maxDay = ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
            break;
        default: return false;
    }

    return day <= maxDay;
}

void Task::setExpirationDate(const std::string &newExpirationDate) {
    if (!isValidDate(newExpirationDate)) {
        throw std::invalid_argument("Data di scadenza non valida. Formato atteso: dd-mm-yyyy e data esistente.");
    }
    expirationDate = newExpirationDate;
}

void Task::markCompleted() {
    completed = true;
}

void Task::showTask() const {
    cout << "----------------------------------------" << endl;
    cout << "Titolo: " << name << endl;
    cout << "Stato: " << (completed ? "Completata" : "Non completata") << endl;
    cout << "Data di scadenza: " << expirationDate << endl;
    cout << "Descrizione: " << description << endl;
    cout << "----------------------------------------" << endl;
}