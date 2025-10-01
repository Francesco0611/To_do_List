#include "To_do_List.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    To_do_List myList;

        myList.addTask("Comprare latte", "Andare al supermercato e comprare del latte", "25-10-2025");
        myList.addTask("Studiare C++", "Rivedere i concetti base di C++", "26-10-2025");
        myList.addTask("Fare esercizio", "Allenamento in palestra", "27-10-2025");

        myList.displayTask();

        myList.deleteTask(3);

        myList.displayTask();


    return 0;    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}