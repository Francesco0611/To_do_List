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

    myList.deleteTask(3);


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

        myList.displayTask();
} catch (const exception &e) {
    cout << "Errore: " << e.what() << endl;
}

    return 0;    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}