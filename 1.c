#include <stdio.h>
#include <string.h>

struct Patient {
    char name[100];
    int age;
    char gender;
    int id;
    char condition[100];
};


struct Patient patients[100];
int patient_count = 0;


void add_patient() {
    if (patient_count >= 100) {
        printf("Error: Cannot add more patients, the limit is 100.\n");
        return;
    }

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patients[patient_count].name);
    printf("Enter Patient Age: ");
    scanf("%d", &patients[patient_count].age);
    printf("Enter Patient Gender (M/F): ");
    scanf(" %c", &patients[patient_count].gender);
    printf("Enter Patient ID: ");
    scanf("%d", &patients[patient_count].id);
    printf("Enter Patient Condition: ");
    scanf(" %[^\n]", patients[patient_count].condition);

    patient_count++;
    printf("Patient added successfully.\n");
}


void search_patient_by_id() {
    int id;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("Patient found:\n");
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %c\n", patients[i].gender);
            printf("ID: %d\n", patients[i].id);
            printf("Condition: %s\n", patients[i].condition);
            return;
        }
    }
    printf("Patient with ID %d not found.\n", id);
}


void update_patient_condition() {
    int id;
    printf("Enter Patient ID to update condition: ");
    scanf("%d", &id);

    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("Enter new condition: ");
            scanf(" %[^\n]", patients[i].condition);
            printf("Patient condition updated successfully.\n");
            return;
        }
    }
    printf("Patient with ID %d not found.\n", id);
}


void display_patients() {
    printf("List of Patients:\n");
    for (int i = 0; i < patient_count; i++) {
        printf("Name: %s, Age: %d, Gender: %c, ID: %d, Condition: %s\n",
               patients[i].name, patients[i].age, patients[i].gender, patients[i].id, patients[i].condition);
    }
    if (patient_count == 0) {
        printf("No patients in the system.\n");
    }
}


int main() {
    int choice;
    do {
        printf("\nHospital Patient Management System\n");
        printf("1. Add a New Patient\n");
        printf("2. Search Patient by ID\n");
        printf("3. Update Patient Condition by ID\n");
        printf("4. Display List of All Patients\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                search_patient_by_id();
                break;
            case 3:
                update_patient_condition();
                break;
            case 4:
                display_patients();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
