#include <stdio.h>
struct Employee {
    int id;
    char name[20];
    float salary;
};
int main() {
    struct Employee e;
    FILE *fp;
    int choice, pos;

    fp = fopen("emp.dat", "r+b");
    if (fp == NULL)
        fp = fopen("emp.dat", "w+b");
    while (1) {
        printf("\n1. Add Employee\n2. Read Employee by Position\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter ID Name Salary: ");
            scanf("%d %s %f", &e.id, e.name, &e.salary);

            fseek(fp, 0, SEEK_END);
            fwrite(&e, sizeof(e), 1, fp);
        }
        else if (choice == 2) {
            printf("Enter record number: ");
            scanf("%d", &pos);

            fseek(fp, (pos-1) * sizeof(e), SEEK_SET);

            if (fread(&e, sizeof(e), 1, fp))
                printf("\nID=%d Name=%s Salary=%.2f\n", e.id, e.name, e.salary);
            else
                printf("No record found.\n");
        }
        else
            break;
    }
    fclose(fp);
    return 0;
}

