#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char description[100];
    int isCompleted;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    Task newTask;
    printf("Enter task description: ");
    fgets(newTask.description, sizeof(newTask.description), stdin);
    newTask.description[strcspn(newTask.description, "\n")] = '\0';
    newTask.id = taskCount + 1;
    newTask.isCompleted = 0;

    tasks[taskCount] = newTask;
    taskCount++;

    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("Current Tasks:\n");
    printf("+----+---------------------------+-----------+\n");
    printf("| ID |        Description        | Completed |\n");
    printf("+----+---------------------------+-----------+\n");

    for (int i = 0; i < taskCount; i++) {
        printf("| %2d | %-25s |   %s   |\n", tasks[i].id, tasks[i].description,
               tasks[i].isCompleted ? "Yes" : "No");
        printf("+----+---------------------------+-----------+\n");
    }
}

void removeTask() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    int taskId;
    printf("Enter task ID to remove: ");
    scanf("%d", &taskId);

    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            found = 1;
            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            printf("Task removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Task not found.\n");
    }
}

void markTaskAsCompleted() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    int taskId;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &taskId);

    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            found = 1;
            tasks[i].isCompleted = 1;
            printf("Task marked as completed!\n");
            break;
        }
    }

    if (!found) {
        printf("Task not found.\n");
    }
}

void viewCompleteTasks() {
    printf("Completed Tasks:\n");
    printf("+----+---------------------------+\n");
    printf("| ID |        Description        |\n");
    printf("+----+---------------------------+\n");

    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].isCompleted) {
            found = 1;
            printf("| %2d | %-25s |\n", tasks[i].id, tasks[i].description);
            printf("+----+---------------------------+\n");
        }
    }

    if (!found) {
        printf("No completed tasks.\n");
    }
}

void viewIncompleteTasks() {
    printf("Incomplete Tasks:\n");
    printf("+----+---------------------------+\n");
    printf("| ID |        Description        |\n");
    printf("+----+---------------------------+\n");

    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (!tasks[i].isCompleted) {
            found = 1;
            printf("| %2d | %-25s |\n", tasks[i].id, tasks[i].description);
            printf("+----+---------------------------+\n");
        }
    }

    if (!found) {
        printf("No incomplete tasks.\n");
    }
}

int main() {
    int option;

    do {
        printf("\nMinions Task Manager\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Mark Task as Completed\n");
        printf("5. View Complete Tasks\n");
        printf("6. view incomplete tasks\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar();  // Consume the newline character left in the input buffer

        switch (option) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                markTaskAsCompleted();
                break;
            case 5:
                viewCompleteTasks();
                break;
            case 6:
                viewIncompleteTasks();
                break;
            case 7:
                printf("Exiting Minions Task Manager. Have a great day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 7);

    return 0;
}
