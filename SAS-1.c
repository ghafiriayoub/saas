#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a task
struct Task {
    int id;
    char title[100];
    char description[100];
    char deadline[100];
    char status[100];
};

int tas_i = 0;
struct Task tasks[100];

// Function to add a new task
void addTask() {
    printf("Enter the title of the task: ");
    scanf("%99s", tasks[tas_i].title);

    printf("Enter the description of the task: ");
    scanf("%99s", tasks[tas_i].description);

    printf("Enter the status of the task: ");
    scanf("%99s", tasks[tas_i].status);

    printf("Enter the deadline for the task (DD/MM/YYYY): ");
    scanf("%99s", tasks[tas_i].deadline);
    //task id
    tasks[tas_i].id = tas_i + 1;
    //total tasks
    tas_i++;
    printf("Task added successfully!\n");
}

// Function to edit a task
void editTask() {
    int taskID;
    printf("Enter the ID of the task you want to edit: ");
    scanf("%d", &taskID);

    for (int i = 0; i < tas_i; i++) {
        if (tasks[i].id == taskID) {
            printf("Enter the new title, description, status, and deadline for your task:\n");
            scanf("%99s %99s %99s %99s", tasks[i].title, tasks[i].description, tasks[i].status, tasks[i].deadline);
            printf("Task with ID %d has been updated!\n", taskID);
            printf("This is how your task looks after the modifications:\n");
            printf("ID: %d\n", tasks[i].id);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Status: %s\n", tasks[i].status);
            printf("Deadline: %s\n", tasks[i].deadline);
            return;
        }
    }

    printf("Task with ID %d not found.\n", taskID);
}

// Function to delete a task
void deleteTask(int taskID) {
    int found = 0;
    int deleteID;
     printf("Enter the ID of the task you want to delete: ");
     scanf("%d", &deleteID);
    for (int i = 0; i < tas_i; i++) {
        if (tasks[i].id == taskID) {
            found = 1;

            for (int j = i; j < tas_i - 1; j++) {
                tasks[j] = tasks[j + 1];
            }

            tas_i--;

            printf("Task with ID %d has been deleted.\n", taskID);
            break;
        }
    }

    if (!found) {
        printf("Task with ID %d not found.\n", taskID);
    }
}

// Function to compare tasks by title for sorting
//int compareByTitle(const struct Task a, const struct Task b) {
//    return strcmp(a.title, b.title);
//}

// Function to compare tasks by deadline for sorting
int compareByDeadline(const struct Task a, const struct Task b) {
    return strcmp(a.deadline, b.deadline);
}

// Function to display tasks
void ShowTasks() {
    int choice;
    printf("Show tasks by:\n");
    printf("1 - Alphabetical order\n");
    printf("2 - Deadline order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Sort tasks based on user choice
    if (choice == 1) {
        struct Task temp;
        for (int i = 0; i < tas_i - 1; i++) {
            for (int j = i + 1; j < tas_i; j++) {
                if (strcmp(tasks[i].title, tasks[j].title)> 0) {
                    temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }
    } else if (choice == 2) {
        struct Task temp;
        for (int i = 0; i < tas_i - 1; i++) {
            for (int j = i + 1; j < tas_i; j++) {
                if (compareByDeadline(tasks[i], tasks[j]) > 0) {
                    temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
        return;
    }

    printf("Tasks:\n");
    for (int i = 0; i < tas_i; i++) {
        printf("Task found:\n");
        printf("ID: %d\n", tasks[i].id);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Status: %s\n", tasks[i].status);
        printf("Deadline: %s\n", tasks[i].deadline);
    }
}

// Function to search for a task by title
void searchTask() {
    int choice2;
    printf("Search by:\n");
    printf("1 - ID\n");
    printf("2 - Title\n");
    printf("Enter your choice: ");
    scanf("%d", &choice2);

    if (choice2 == 1) {
        // Search by ID
        int taskID;
        printf("Enter the ID of the task you want to search for: ");
        scanf("%d", &taskID);

        int found = 0;
        for (int i = 0; i < tas_i; i++) {
            if (tasks[i].id == taskID) {
                found = 1;
                printf("Task found:\n");
                printf("ID: %d\n", tasks[i].id);
                printf("Title: %s\n", tasks[i].title);
                printf("Description: %s\n", tasks[i].description);
                printf("Status: %s\n", tasks[i].status);
                printf("Deadline: %s\n", tasks[i].deadline);
                break;
            }
        }

        if (!found) {
            printf("Task with ID %d not found.\n", taskID);
        }
    } else if (choice2 == 2) {
        // Search by Title
        char searchTitle[100];
        printf("Enter the title of the task you want to search for: ");
        scanf("%99s", searchTitle);

        int found = 0;
        for (int i = 0; i < tas_i; i++) {
            if (strcmp(tasks[i].title, searchTitle) == 0) {
                found = 1;
                printf("Task found:\n");
                printf("ID: %d\n", tasks[i].id);
                printf("Title: %s\n", tasks[i].title);
                printf("Description: %s\n", tasks[i].description);
                printf("Status: %s\n", tasks[i].status);
                printf("Deadline: %s\n", tasks[i].deadline);
            }
        }

        if (!found) {
            printf("Task with title '%s' not found.\n", searchTitle);
        }
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("What can we do for you:\n");
        printf("1 - Add a new task\n");
        printf("2 - Edit a task\n");
        printf("3 - Delete a task\n");
        printf("4 - Show tasks\n");
        printf("5 - Search for a task\n");
        printf("6 - Exit\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                editTask();
                break;
            case 3:
                
                deleteTask(deleteID);
                break;
            case 4:
                ShowTasks();
                break;
            case 5:
                searchTask();
                break;
            case 6:
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}