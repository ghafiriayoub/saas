#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of the task
struct Task {
    int id;
    char title[100];
    char description[100];
    char deadline[100];
    char status[100];
};

int tas_i = 0;
struct Task tasks[100];

// Function to make a new task
void addTask() {
    printf("Enter the title of the task: ");
    scanf("%99s", tasks[tas_i].title);

    printf("Enter the description of the task: ");
    scanf("%99s", tasks[tas_i].description);

    printf("Enter the status of the task 'completed' or 'incompleted' or 'in progress': ");
    scanf("%99s", tasks[tas_i].status);

    printf("Enter the deadline for the task (DD/MM/YYYY): ");
    scanf("%99s", tasks[tas_i].deadline);

    tasks[tas_i].id = tas_i + 1;
    tas_i++;
    printf("Task added successfully!\n");
}

// Function to edit the task
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

// Function to delete the task
void deleteTask(int taskID) {
    int check = 0;
    for (int i = 0; i < tas_i; i++) {
        if (tasks[i].id == taskID) {
            check = 1;

            for (int j = i; j < tas_i - 1; j++) {
                tasks[j] = tasks[j + 1];
            }

            tas_i--;

            printf("Task with ID %d has been deleted.\n", taskID);
            break;
        }
    }

    if (!check) {
        printf("Task with ID %d not found.\n", taskID);
    }
}

// Function to compare tasks by deadline for sorting
int compareByDeadline(const struct Task a, const struct Task b) {
    // Assuming the deadline format is "DD/MM/YYYY" for both tasks
    // You can extract day, month, and year and compare them
    int day_a, month_a, year_a;
    int day_b, month_b, year_b;

    // Use sscanf to parse the deadline strings
    sscanf(a.deadline, "%d/%d/%d", &day_a, &month_a, &year_a);
    sscanf(b.deadline, "%d/%d/%d", &day_b, &month_b, &year_b);

    // Compare years first
    if (year_a > year_b) {
        return 1; // 'a' has a later deadline
    } else if (year_a < year_b) {
        return -1; // 'b' has a later deadline
    }

    // If years are the same, compare months
    if (month_a > month_b) {
        return 1;
    } else if (month_a < month_b) {
        return -1;
    }

    // If months are the same, compare days
    if (day_a > day_b) {
        return 1;
    } else if (day_a < day_b) {
        return -1;
    }

    // If all components are the same, the deadlines are equal
    return 0;
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
        for (int i = 0; i < tas_i; i++) {
            for (int j = 1; j < tas_i - i; j++) {
                if (strcmp(tasks[j - 1].title, tasks[j].title) > 0) {
                    temp = tasks[j];
                    tasks[j] = tasks[j - 1];
                    tasks[j - 1] = temp;
                }
            }
        }
    } else if (choice == 2) {
        struct Task temp;
        for (int i = 0; i < tas_i; i++) {
            for (int j = 1; j < tas_i - i; j++) {
                if (compareByDeadline(tasks[j - 1], tasks[j]) > 0) {
                    temp = tasks[j];
                    tasks[j] = tasks[j - 1];
                    tasks[j - 1] = temp;
                }
            }
        }
    } else {
        printf("Incorrect choice. Please enter 1 or 2.\n");
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

        int check = 0;
        for (int i = 0; i < tas_i; i++) {
            if (tasks[i].id == taskID) {
                check = 1;
                printf("Task found:\n");
                printf("ID: %d\n", tasks[i].id);
                printf("Title: %s\n", tasks[i].title);
                printf("Description: %s\n", tasks[i].description);
                printf("Status: %s\n", tasks[i].status);
                printf("Deadline: %s\n", tasks[i].deadline);
                break;
            }
        }

        if (!check) {
            printf("Task with ID %d not found.\n", taskID);
        }
    } else if (choice2 == 2) {
        // Search by Title
        char searchTitle[100];
        printf("Enter the title of the task you want to search for: ");
        scanf("%99s", searchTitle);

        int check = 0;
        for (int i = 0; i < tas_i; i++) {
            if (strcmp(tasks[i].title, searchTitle) == 0) {
                check = 1;
                printf("Task found:\n");
                printf("ID: %d\n", tasks[i].id);
                printf("Title: %s\n", tasks[i].title);
                printf("Description: %s\n", tasks[i].description);
                printf("Status: %s\n", tasks[i].status);
                printf("Deadline: %s\n", tasks[i].deadline);
            }
        }

        if (!check) {
            printf("Task with title '%s' not found.\n", searchTitle);
        }
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
}

void statistics() {
    int c; // Declare c here
    printf("Choose:\n");
    printf("1 - Show the total number of tasks\n");
    printf("2 - Show the number of completed and incomplete tasks\n");
    scanf("%d", &c);
    if (c == 1) {
        printf("The total number of your tasks is %d\n", tas_i);
    } else if (c == 2) {
        int comp = 0;
        int incomp = 0;
        for (int i = 0; i < tas_i; i++) {
            if (strcmp(tasks[i].status, "completed") == 0) 
                comp++;
            else
                incomp++;
        }
        printf("Number of completed tasks: %d\n", comp);
        printf("Number of incomplete tasks: %d\n", incomp);
    }
}

int main() {
    int choice;
    int deleteID; // Declare deleteID here

    while (1) {
        printf("What can we do for you:\n");
        printf("1 - Add a new task\n");
        printf("2 - Edit a task\n");
        printf("3 - Delete a task\n");
        printf("4 - Show tasks\n");
        printf("5 - Search for a task\n");
        printf("6 - Show statistics\n");
        printf("7 - Exit\n");
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
                printf("Enter the ID of the task you want to delete: ");
                scanf("%d", &deleteID);
                deleteTask(deleteID);
                break;
            case 4:
                ShowTasks();
                break;
            case 5:
                searchTask();
                break;
            case 6:
                statistics();
                break;
            case 7:
                return 0;
            default:
                printf("Incorrect choice. Please choose another one.\n");
        }
    }
    return 0;
}
