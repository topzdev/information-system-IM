#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define MAX_SUB 20
#define FILENAME "file.txt"


int count = 0;
FILE *file;


typedef struct enlist{

    char subjectCode[40];
    char venue[40];
    char time[20];
    char subjectDescription[40];

}SUBJECT;

typedef struct student{

    int subCount;
    char studentNumber[40];
    SUBJECT subject[MAX_SUB];

}STUDENT;

STUDENT L[MAX];

void save();
void retrieve();
void menu();
void inputSubject();
void insert(STUDENT student, SUBJECT *input);
void pressAnyKey();
int findStudent(char * search);
char * inputStudent();

void main(){
    retrieve();
    menu();

}

void menu(){
    system("cls");
    int choose;

    printf("Choose any options\n");
    printf("[1] Enlist Subject\n");
    printf("[2] Display Subject Enlisted\n");
    printf("[3] Student COR\n");
    printf("[4] Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choose);

    system("cls");
    switch(choose){

    case 1:
        inputSubject();
        break;

    case 2:
         displaySubjects();
        break;

    case 3:
        break;
        cor();

    case 4:
        break;
        system(0);
    default:
        printf("Your input is not in the options");
        pressAnyKey();
        break;
    }

}

char * inputStudent(){
    char studentNumber[40];

    printf("Enter student Student no: ");
    scanf("%s", studentNumber);

    return studentNumber;
}

void inputSubject(){
    int stop = 1;
    SUBJECT input[MAX_SUB];
    STUDENT student;


    int sub_count = 0;

    printf("SUBJECT ENLISTMENT\n");
    printf("-------------------------------------\n");

    printf("Enter student Student no: ");
    scanf("%s", &student.studentNumber);

    printf("Enter the student's subjects %d \n", sub_count);

    while(1){
        printf("Enter Subject Code: ");
        scanf("%s", &input[sub_count].subjectCode);

        printf("Enter Venue: ");
        scanf("%s", &input[sub_count].venue);

        printf("Enter Time: ");
        scanf("%s", &input[sub_count].time);

        printf("Enter Subject Description: ");
        scanf("%s", &input[sub_count].subjectDescription);

        printf("Add more subjects type [1] if YES and [0] if no: ");
        scanf("%d", &stop);

        if(stop != 1){
            break;
        }

        sub_count++;
    }

    student.subCount = sub_count;
    insert(student,input);

}

void insert(STUDENT student, SUBJECT *input){
    int i;
    L[count].subCount = student.subCount;
    *L[count].subject = *input;

    /*for(i = 0; i < student.subCount; i++){
        strcpy(L[count].subject[i].studentNumber, input.studentNumber);
        strcpy(L[count].subjectCode, input.subjectCode);
        strcpy(L[count].venue, input.venue);
        strcpy(L[count].time, input.time);
        strcpy(L[count].subjectDescription, input.subjectDescription);

    }*/

    save();
    printf("Successfully Added");
    count++;
    pressAnyKey();

}

void pressAnyKey(){
    printf("\nPress any key....\n");
    getch();
    menu();
}

int findStudent(char * search){
    int i;

    for(i = 0; i <= count; i++){
        if(strcmpi(L[i].studentNumber, search) == 1){
            return i;
        }
    }

    return -1;
}

void cor(){
    char search[40];

    printf("Enter student number ID: ");
    scanf("%s", &search);

    int indx = findStudent(search);

    if(indx == -1){
        printf("Student not found...");
        return;
    }


    printf("The student number is: %d", L[indx].studentNumber);




}

void displaySubjects(){
    int i = 0, e;
    printf("Subject Code | Venue | Time | Subject Description\n");
    for(i = 0; i <= count; i++){
        printf("%s %d\n", L[i].studentNumber, L[i].subCount);

        for(e = 0; e <= L[i].subCount; e++){
            fprintf("%s %s %s %s\n", L[i].subject[e].subjectCode, L[i].subject[e].venue, L[i].subject[e].time, L[i].subject[e].subjectDescription);
        }

    }

    printf("\nEnd of results");
    pressAnyKey();
}


void retrieve(){
    int i, e;
    file = fopen(FILENAME, "r");

    fscanf(file, "%d", &count);
    for(i = 0; i <= count; i++){
        fscanf(file, "%s %d", L[i].studentNumber, &L[i].subCount);

        for(e = 0; e <= L[i].subCount; e++){
            fscanf(file, "%s %s %s %s", L[i].subject[e].subjectCode, L[i].subject[e].venue, L[i].subject[e].time, L[i].subject[e].subjectDescription);
        }

    }
    fclose(file);
}

void save(){
    int i, e;
    file = fopen(FILENAME, "w");

    fprintf(file, "%d\n", count);
    for(i = 0; i <= count; i++){
        fprintf(file, "%s %d\n", L[i].studentNumber, L[i].subCount);

        for(e = 0; e <= L[i].subCount; e++){
            fprintf(file, "%s %s %s %s\n", L[i].subject[e].subjectCode, L[i].subject[e].venue, L[i].subject[e].time, L[i].subject[e].subjectDescription);
        }

    }
    fclose(file);
}


