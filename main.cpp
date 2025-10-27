#include "To_do_List.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    To_do_List myList;

    try {
        myList.addTask("Comprare latte", "Andare al supermercato e comprare del latte", "25-10-2025");
        myList.addTask("Studiare C++", "Rivedere i concetti base di C++", "26-10-2025");
        myList.addTask("Fare esercizio", "Allenamento in palestra", "27-10-2025");

        myList.displayTask();

    myList.editTask(2, "Studiare C++ avanzato", "Rivedere concetti avanzati di C++", "28-10-2025");


        vector<Task> tasksByDate = myList.searchByDate("27-03-2025");
        cout << "\nTasks con data '27-03-2025':" << endl;
        if (tasksByDate.empty()) {
            cout << "Non è presente nessuna task per la data inserita!" << endl;
        } else {
            for (const auto &task : tasksByDate) {
                task.showTask();
            }
        }
        vector<Task> tasksByKeyword = myList.searchByKeyword("Comprare");
        cout << "\nTasks contenenti 'Comprare' nel titolo:" << endl;
        if (tasksByKeyword.empty()) {
            cout << "Non è presente nessuna task che ha nel titolo la parola inserita!" << endl;
        } else {
            for (const auto &task : tasksByKeyword) {
                task.showTask();
            }
        }

    myList.markTaskCompleted(1);

    vector<Task> notCompletedTasks = myList.showNotCompletedTasks();
    cout << "\nTask da completare:" << endl;
    if (notCompletedTasks.empty()) {
        cout << "Non è presente nessuna task da completare!" << endl;
    } else {
        for (const auto &task : notCompletedTasks) {
            task.showTask();
        }
    }

        myList.deleteTask(3);

        myList.displayTask();
} catch (const exception &e) {
    cout << "Errore: " << e.what() << endl;
}

    return 0;
}