#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct patient
{
    long long ID;
    string firstName;
    string lastName;
    int age;
    char blood[5];
    char gender;
    patient *next;
};

class queuelink
{
    patient *head, *last;

public:
    queuelink() // constructor
    {
        head = NULL;
        last = NULL;
    }
    patient input();
    void insertAtbegining();
    void insertAtend();
    void getPatientout();
    void patientList();
    int search(int);
    char departmentName[50];
};

int queuelink ::search(int item)
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        int flag = 0;
        patient *p = new patient;
        p = head;

        while (p->next != NULL && p->ID != item)
        {
            p = p->next;
        }
        if (p->ID == item)
        {
            flag = 1;
            return true;
        }
        if (flag == 0)
            return false;
    }
    return 0;
}
int readNum()
{
    char c[20];
    cin.getline(c, sizeof(c)); // for reading multiple line string from a file
    return atoi(c);            // used for converting value into a integer value
}

patient queuelink :: input()
{
    int flag = 0;
    patient *p = new patient;
    cout << " \n  Please Enter data for patient\n";
    cout << "   First Name     : ";
    getline(cin, p->firstName);
    cout << "   Last Name     : ";
    getline(cin, p->lastName);
    again:
    cout << "   Blood Group     : ";
    cin >> p->blood;
    if ((strcmp(p->blood, "A+") == 0) || (strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "A-") == 0) || (strcmp(p->blood, "a-") == 0) ||
        (strcmp(p->blood, "B+") == 0) || (strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "B-") == 0) || (strcmp(p->blood, "b-") == 0) ||
        (strcmp(p->blood, "O+") == 0) || (strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "O-") == 0) || (strcmp(p->blood, "o-") == 0) ||
        (strcmp(p->blood, "AB+") == 0) || (strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "AB-") == 0) || (strcmp(p->blood, "ab-") == 0))
        flag=1;
        if (flag == 0)
        {
            cout << "\n   Invalid Blood Group Please Try Again!..\n\n ";
            goto again;
        }

    cout << "   Gender(m/f)    : ";
    cin >> p->gender;
    cout << "   Age       : ";
    cin >> p->age;
    cout << "   Mobile Number   : ";
    cin >> p->ID;

    if (search(p->ID))
    {
        p->ID = 0;
        cout << "\n   Data not valid. Operation cancelled.";
       
    }
     return *p;
}

void output(patient *p)
{
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n   Patient Data:\n";
    cout << "\n   First Name      : " << p->firstName;
    cout << "\n   Last Name       : " << p->lastName;
    cout << "\n   Gender          : " << p->gender;
    cout << "\n   Age             : " << p->age;
    cout << "\n   Blood group     : " << p->blood;
    cout << "\n   Mobile Number   : " << p->ID;
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}
void queuelink ::insertAtbegining()
{
    patient *p = new patient();
    *p = input();

    if (p->ID == 0)
        return;

    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next == head;
        head = p;
    }
    system("cls");
    cout << "\n\tPatient Added:";
    output(p);
}

void queuelink ::insertAtend()
{
    patient *p = new patient();
    *p = input();

    if (p->ID == 0)
        return;

    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next == NULL;
        last->next = p;
        last = p;
    }
    system("cls");
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  ---------PATIENT ADDED----------";
    output(p);
}

void queuelink ::getPatientout()
{
    system("cls");
    if (head == NULL)
    {
        cout << "\n  No Patient to operate";
    }
    else
    {
        patient *p = new patient();
        p = head;
        head = head->next;
        cout << " \n Patient to operate:";
        output(p);
    }
}

void queuelink ::patientList()
{
    if (head == NULL)
    {
        cout << "\n  No Patient";
    }
    system("cls");
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    patient *p = new patient();
    p = head;

    while (p != NULL)
    {
        cout << "\n   Patient Data:\n";
        cout << "\n   First Name      : " << p->firstName;
        cout << "\n   Last Name       : " << p->lastName;
        cout << "\n   Gender          : " << p->gender;
        cout << "\n   Age             : " << p->age;
        cout << "\n   Blood group     : " << p->blood;
        cout << "\n   Mobile Number   : " << p->ID;
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        p = p->next;
    }
    cout << "\n";
}
void menuOfdepartment(queuelink *q)
{
    int choice = 0, sucess;
    patient p;
    while (choice != 5)
    {
        system("cls");
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n\n   " << q->departmentName;
        cout << "\n    [1] Add normal patient\n";
        cout << "    [2] Add critically ill patient\n";
        cout << "    [3] Take patient to Doctor\n";
        cout << "    [4] Display List\n";
        cout << "    [5] Change department and Exit\n";
        cout << "\n     Please Enter Your Choice : ";
        choice = readNum();
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

        switch (choice)
        {

        case 1:
            q->insertAtend();
            cout << "\n   Press Any Key";
            getch();
            break;

        case 2:
            q->insertAtbegining();
            cout << "\n   Press Any Key";
            getch();
            break;

        case 3:
            q->getPatientout();
            cout << "\n   Press Any Key";
            getch();
            break;

        case 4:
            system("cls");
            q->patientList();
            cout << "\n   Press Any Key";
            getch();
            break;
        }
    }
}

int main()
{

    int i, choice = 0;
    queuelink departments[4];

    while (choice != 5)
    {
        strcpy(departments[0].departmentName, "GENERAL CLINIC\n");
        strcpy(departments[1].departmentName, "HEART CLINIC\n");
        strcpy(departments[2].departmentName, "LUNG CLINIC\n");
        strcpy(departments[3].departmentName, "PLASTIC SURGERY\n");
        system("cls");
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "   Main Menu\n\n";

        for (int i = 0; i < 4; i++)
        {
            cout << " " << i + 1 << ": " << departments[i].departmentName;
        }
        cout << " 5: Exit";
        cout << "\n\n  Please enter your choice : ";
        choice = readNum();

        if (choice >= 1 && choice <= 4)
        {
            menuOfdepartment(&departments[choice - 1]);
        }
    }
    if (choice == 5)
    {
        cout << "\n\tThank You ! \n";
        exit(0);
    }
}