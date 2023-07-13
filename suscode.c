1. Using only structures:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DataBase
{
    int roll;
    char name[100];
    char semester[100];
    char dept[100];
    double sgpa;
};

int main()
{
    int size, i;
    struct DataBase *ptr;

    printf("::Enter the number of students who appeared in the recent semester exam::\n");
    scanf("%d", &size);

    ptr = (struct DataBase *)malloc(sizeof(struct DataBase) * size);

    for (i = 0; i < size; i++)
    {
        printf("Student %d\n", (i + 1));

        printf("Enter roll no.: ");
        scanf("%d", &(ptr + i)->roll);

        printf("Enter Name of the student: ");
        scanf("%s", (ptr + i)->name);

        printf("Enter his/her current semester: ");
        scanf("%s", (ptr + i)->semester);

        printf("Enter his/her department: ");
        scanf("%s", (ptr + i)->dept);

        printf("Enter his/her SGPA: ");
        scanf("%lf", &(ptr + i)->sgpa);
    }

    printf("Therefore, the Database created for %d students is:\n", size);
    printf("Roll No.\t\t\t\tName\t\t\t\tSemester\t\t\t\tDepartment\t\t\t\tSGPA value\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%.2lf\n",
               (ptr + i)->roll, (ptr + i)->name, (ptr + i)->semester, (ptr + i)->dept, (ptr + i)->sgpa);
    }

    free(ptr); // Free the allocated memory

    return 0;
}


2. Using both structures and file handling in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DataBase
{
    int roll;
    char name[100];
    char semester[100];
    char dept[100];
    double sgpa;
};

int main()
{
    int size, i;
    struct DataBase *ptr;

    printf("::Enter the number of students who appeared in the recent semester exam::\n");
    scanf("%d", &size);

    ptr = (struct DataBase *)malloc(sizeof(struct DataBase) * size);

    FILE *file;
    file = fopen("database.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file.");
        return 1;
    }

    for (i = 0; i < size; i++)
    {
        printf("Student %d\n", (i + 1));

        printf("Enter roll no.: ");
        scanf("%d", &(ptr + i)->roll);
        fprintf(file, "%d\n", (ptr + i)->roll);

        printf("Enter Name of the student: ");
        scanf("%s", (ptr + i)->name);
        fprintf(file, "%s\n", (ptr + i)->name);

        printf("Enter his/her current semester: ");
        scanf("%s", (ptr + i)->semester);
        fprintf(file, "%s\n", (ptr + i)->semester);

        printf("Enter his/her department: ");
        scanf("%s", (ptr + i)->dept);
        fprintf(file, "%s\n", (ptr + i)->dept);

        printf("Enter his/her SGPA: ");
        scanf("%lf", &(ptr + i)->sgpa);
        fprintf(file, "%.2lf\n", (ptr + i)->sgpa);

        fprintf(file, "\n");
    }

    fclose(file);

    printf("Therefore, the Database created for %d students is:\n", size);
    printf("Roll No.\t\t\t\tName\t\t\t\tSemester\t\t\t\tDepartment\t\t\t\tSGPA value\n");

    file = fopen("database.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.");
        return 1;
    }

    for (i = 0; i < size; i++)
    {
        fscanf(file, "%d", &(ptr + i)->roll);
        fscanf(file, "%s", (ptr + i)->name);
        fscanf(file, "%s", (ptr + i)->semester);
        fscanf(file, "%s", (ptr + i)->dept);
        fscanf(file, "%lf", &(ptr + i)->sgpa);

        printf("%d\t\t\t\t%s\t\t\t\t%s\t\t\t\t%s\t\t\t\t%.2lf\n",
               (ptr + i)->roll, (ptr + i)->name, (ptr + i)->semester, (ptr + i)->dept, (ptr + i)->sgpa);
    }

    fclose(file);
    free(ptr);

    return 0;
}

3. In C++ 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataBase
{
public:
    int roll;
    string name;
    string semester;
    string dept;
    double sgpa;

    void input()
    {
        cout << "Enter roll no.: ";
        cin >> roll;
        cout << "Enter Name of the student: ";
        cin >> name;
        cout << "Enter his/her current semester: ";
        cin >> semester;
        cout << "Enter his/her department: ";
        cin >> dept;
        cout << "Enter his/her SGPA: ";
        cin >> sgpa;
    }

    void display()
    {
        cout << roll << "\t\t\t\t" << name << "\t\t\t\t" << semester << "\t\t\t\t" << dept << "\t\t\t\t" << sgpa << endl;
    }

    void writeToFile(ofstream& file)
    {
        file << roll << endl;
        file << name << endl;
        file << semester << endl;
        file << dept << endl;
        file << sgpa << endl;
        file << endl;
    }
};

int main()
{
    int size, i;

    cout << "::Enter the number of students who appeared in the recent semester exam::" << endl;
    cin >> size;

    DataBase* ptr = new DataBase[size];

    ofstream file("database.txt");
    if (!file)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    for (i = 0; i < size; i++)
    {
        cout << "Student " << (i + 1) << endl;

        ptr[i].input();
        ptr[i].writeToFile(file);
    }

    file.close();

    cout << "Therefore, the Database created for " << size << " students is:" << endl;
    cout << "Roll No.\t\t\t\tName\t\t\t\tSemester\t\t\t\tDepartment\t\t\t\tSGPA value" << endl;

    ifstream readFile("database.txt");
    if (!readFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    for (i = 0; i < size; i++)
    {
        readFile >> ptr[i].roll;
        readFile >> ptr[i].name;
        readFile >> ptr[i].semester;
        readFile >> ptr[i].dept;
        readFile >> ptr[i].sgpa;

        ptr[i].display();
    }

    readFile.close();

    delete[] ptr;

    return 0;
}
