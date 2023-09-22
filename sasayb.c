#include <stdio.h>
#include <stdlib.h>

struct Task {
    int id;
    char title[100];
    char description[100];
    char deadline[100];
    char status[100];
};

int tas_i = 0;   // int var used to keep track of the current position in the tasks array.
int numoftasks = 1;   //int var used to specify how many tasks you want to add.
struct Task tasks[100]; // Declare an array of tasks in the main function

void addtask() {  //function bach knzed les tasks
        printf("Enter the number of tasks you want to add: \n");
        scanf("%d", &numoftasks);

    for (int i = tas_i; i < numoftasks; i++) {
        printf("Enter the title of the task:\n");
        scanf("%99s", tasks[i].title);

        printf("Enter the description of the task:\n");
        scanf("%99s", tasks[i].description);

        printf("Enter the status of the task:\n");
        scanf("%99s", tasks[i].status);

        printf("Enter the deadline for the task (DD/MM/YYYY):\n");
        scanf("%99s", tasks[i].deadline);

        tasks[i].id = i + 1; // ktdir lina id l kola task
        tas_i++; // bach l id kib9a ytzad m3a kol task
    }
   printf("task added sucessfuly\n");
}


 editTask(){   //function to edit task
int taskID;
printf("enter the id of the task u want to edit:\n");
scanf("%d",&taskID);
    for (int i = 0; i < tas_i; i++) {  //loop to track the correct id
    if (tasks[i].id == taskID) {
    printf("Enter the new title, description, status, and deadline for your task:\n");
    scanf(" %99s %99s %99s %99s", tasks[i].title, tasks[i].description, tasks[i].status, tasks[i].deadline);  // the new value entered by the user for  the title, description, status, and deadline

    printf("the task with the %d id has been updated !\n",taskID);
    printf("this is how your task looks after the modifications:\n");
    printf(" the new title :%s\n",tasks[i].title);
    printf(" the new description : %s\n",tasks[i].description);
    printf(" the new status : %s\n",tasks[i].status);
    printf(" the new deadline : %s\n",tasks[i].deadline);

  }
  }
   }
void deleteTask(int taskID) {
    int found = 0;

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

int main() {
    int choice;

    while (1) {
        printf(" what can we do for you:\n");
        printf("1 - Add a new task\n");
        printf("2 - Edit a task\n");
        printf("3 - Delete a task\n");
        printf("4 - Show tasks\n");
        printf("5 - Research for a task\n");
        printf("6 - Show completed and incomplete tasks\n");
        printf("7 - Exit\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addtask();
                break;
            case 2:
                editTask();
                break;
            case 3:
                int deleteID;
                printf("Enter the ID of the task you want to delete: ");
                scanf("%d", &deleteID);
                 deleteTask(deleteID); // Call the deleteTask function with the provided task ID.
                break;
            case 7:
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

































