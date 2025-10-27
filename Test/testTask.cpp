#include <gtest/gtest.h>
#include "Task.h"

TEST(TaskTest, constructorAndGetters) {
    Task task("Titolo", "Descrizione", "01-01-2025");
    EXPECT_EQ(task.getName(), "Titolo");
    EXPECT_EQ(task.getDescription(), "Descrizione");
    EXPECT_EQ(task.getExpirationDate(), "01-01-2025");
    EXPECT_FALSE(task.isCompleted());
}

TEST(TaskTest, createTaskWithInvalidDate) {
    EXPECT_THROW(Task("Compito 1", "Descrizione", "32-01-2025"), std::invalid_argument);
    EXPECT_THROW(Task("Compito 2", "Descrizione", "00-12-2025"), std::invalid_argument);
    EXPECT_THROW(Task("Compito 3", "Descrizione", "15-13-2025"), std::invalid_argument);
    EXPECT_THROW(Task("Compito 4", "Descrizione", "29-02-2023"), std::invalid_argument);
    EXPECT_THROW(Task("Compito 5", "Descrizione", "31-04-2025"), std::invalid_argument);
    EXPECT_THROW(Task("Compito 6", "Descrizione", "2025-12-01"), std::invalid_argument);
    EXPECT_THROW(Task("Compito 7", "Descrizione", "invalid-date"), std::invalid_argument);
}

TEST(TaskTest, setters) {
    Task task("Titolo", "Descrizione", "01-01-2025");
    task.setName("Nuovo Titolo");
    task.setDescription("Nuova Descrizione");
    task.setExpirationDate("02-02-2025");
    EXPECT_EQ(task.getName(), "Nuovo Titolo");
    EXPECT_EQ(task.getDescription(), "Nuova Descrizione");
    EXPECT_EQ(task.getExpirationDate(), "02-02-2025");
}

TEST(TaskTest, markCompleted) {
    Task task("Titolo", "Descrizione", "01-01-2025");
    EXPECT_FALSE(task.isCompleted());
    task.markCompleted();
    EXPECT_TRUE(task.isCompleted());
}