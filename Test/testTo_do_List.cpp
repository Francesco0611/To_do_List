#include <gtest/gtest.h>
#include "To_do_List.h"
#include <stdexcept>


TEST(ToDoListTest, AddTaskEmptyName) {
    To_do_List todolist;
    EXPECT_THROW(todolist.addTask("", "Descrizione", "01-01-2025"), std::invalid_argument);
}

TEST(ToDoListTest, AddTaskValid) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    auto results = todolist.searchByDate("01-01-2025");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0].getName(), "Titolo1");
}


TEST(ToDoListTest, DeleteTaskEmptyList) {
    To_do_List todolist;
    EXPECT_THROW(todolist.deleteTask(1), std::runtime_error);
}

TEST(ToDoListTest, DeleteTaskValid) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    todolist.deleteTask(1);
    auto results = todolist.searchByDate("01-01-2025");
    EXPECT_TRUE(results.empty());
}


TEST(ToDoListTest, DeleteTaskInvalidIndex) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    EXPECT_THROW(todolist.deleteTask(5), std::out_of_range);
}


TEST(ToDoListTest, MarkTaskCompletedValid) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    todolist.markTaskCompleted(1);
    auto results = todolist.searchByDate("01-01-2025");
    EXPECT_EQ(results[0].isCompleted(), true);
}

TEST(ToDoListTest, MarkTaskCompletedEmptyList) {
    To_do_List todolist;
    EXPECT_THROW(todolist.markTaskCompleted(1), std::runtime_error);
}

TEST(ToDoListTest, MarkTaskCompletedInvalidIndex) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    EXPECT_THROW(todolist.markTaskCompleted(5), std::out_of_range);
}

TEST(ToDoListTest, EditTaskValid) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    todolist.editTask(1, "Nuovo Titolo", "Nuova Descrizione", "02-02-2025");
    auto results = todolist.searchByDate("02-02-2025");
    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0].getName(), "Nuovo Titolo");
    EXPECT_EQ(results[0].getDescription(), "Nuova Descrizione");
    EXPECT_EQ(results[0].getExpirationDate(), "02-02-2025");
}

TEST(ToDoListTest, EditTaskEmptyList) {
    To_do_List todolist;
    EXPECT_THROW(todolist.editTask(1, "Nuovo Titolo", "Nuova Descrizione", "02-02-2025"), std::runtime_error);
}

TEST(ToDoListTest, EditTaskInvalidIndex) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    EXPECT_THROW(todolist.editTask(5, "Nuovo Titolo", "Nuova Descrizione", "02-02-2025"), std::out_of_range);
}

TEST(ToDoListTest, SearchByDateFound) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    todolist.addTask("Titolo2", "Descrizione2", "02-02-2025");
    auto results = todolist.searchByDate("01-01-2025");
    EXPECT_EQ(results.size(), 1);
}

TEST(ToDoListTest, SearchByDateNotFound) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    todolist.addTask("Titolo2", "Descrizione2", "02-02-2025");
    auto results = todolist.searchByDate("03-03-2025");
    EXPECT_TRUE(results.empty());
}

TEST(ToDoListTest, ShowNotCompletedTasks) {
    To_do_List todolist;
    todolist.addTask("Titolo1", "Descrizione1", "01-01-2025");
    todolist.addTask("Titolo2", "Descrizione2", "02-02-2025");
    todolist.markTaskCompleted(1);
    auto results = todolist.showNotCompletedTasks();
    EXPECT_EQ(results.size(), 1);
}
