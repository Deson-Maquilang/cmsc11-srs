#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct subject{
    int subID;
    char subCode[50];
    char subTitle[100];
}temp = {0, "none", " "},temp2 = {0, "none", " "},temp3 = {0, "none", " "}, temp1 = {0, " ", " "};

struct student{
    int studentID;
    char lastName[20];
    char firstName[20];
    char section[5];
    int exam1;
    int exam2;
    int exam3;
    struct subject *sub1;
    struct subject *sub2;
    struct subject *sub3;
    int hex;
    char grade[3];
}tempo, tempor = {0, " ", " ", " ", 0, 0, 0, &temp1, &temp1, &temp1, 0, " "};

struct stat{
    int low;
    int high;
    float ave;
    float sd;
}studentStats[4];

//Struct for exam statistics
struct stat statsEx1(struct stat st);
struct stat statsEx2(struct stat st);
struct stat statsEx3(struct stat st);
struct stat statsHex(struct stat st);

struct student studentInputKeyboard(struct student inputStudent);
struct student updateStudentRecordsKeyboard(struct student inputStudent);
void updateSubjectKeyboard(struct subject *inputSub);
void addSubjectKeyboard(struct subject *inputSub, char a[]);

struct student scoreGrade(struct student iS);
void cmscEnrol(struct student *s);
void studentNameSearch(char a[15]);
void studentSort(int n);
void displayStudent(int num);
void displaySubject(struct subject *inputSubPtr);
void inputSubjectData(char file[15]);
void inputStudentData(char file[15]);
void studentEnrolSubject(int idNum, char code[20]);
void displayAllStudents(int s);
void writeStudentRecordsToFile(char file[15]);
void writeSubjectRecordsToFile(char file[15]);
void inputStudentMasterData(char file[15]);
void deleteStudent(int n);
void emptyStudentChecker(void);
void deleteSubject(char a[]);
void updateGrades(void);
void drop(int n);
void dequeuSubject(void);
int findSub(char a[10]);
int findSub2(char a[10]);
int stringCompare(char s1[], char s2[]);
int checkSubjectFile(char file[15]);
int checkStudentFile(char file[15]);
int checkMasterStudentFile(char file[15]);
char toLower(char ch);

int cS = 0;
int cSub = 1;

struct student cs11[70];
struct subject sub[70];



int main(void){
    system("COLOR F0");

        printf("\n\n");

        printf("\n\t=====================================================================================================================================================");
        printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
        printf("\n\t                                                                University of the Philippines                                                        ");
        printf("\n\t=====================================================================================================================================================");
        int choice = 1;
    int n;
    sub[0] = (struct subject){11, "CMSC11", "Introduction to Computer Science"};
    for(int i = 0; i < 70; i++){
        cs11[i].sub1 = &sub[0];
        cs11[i].sub2 = &temp;
        cs11[i].sub3 = &temp;
    }

    while(choice >=1 && choice <= 15){
        printf("\n\t=====================================================================================================================================================");
        printf("\n\t                                                                      M A I N     M E N U                                                          \n");
        printf("\n\t                                            1: Create Student Record Manually          9: Create Subject Record Manually                             ");
        printf("\n\t                                            2: Import Student Record                  10: Import Subject Record                                      ");
        printf("\n\t                                            3: Update Student Record                  11: Update Subject Record                                      ");
        printf("\n\t                                            4: Enroll Student                         12: Display All Subject Records                                ");
        printf("\n\t                                            5: Drop Subject                           13: Search Subject Record                                     ");
        printf("\n\t                                            6: Display All Student Record             14: Delete Subject Record                                      ");
        printf("\n\t                                            7: Search Student Record                  15: Export Masterlist                                          ");
        printf("\n\t                                            8: Delete Student Record                  16: Exit Program                                               ");
        printf("\n\t=====================================================================================================================================================");
        printf("\n\tInput Choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice){

        case 1:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            cs11[cS] = studentInputKeyboard(cs11[cS]);
            ++cS;
            printf("\n\t                                               S T U D E N T    S U C C E S S F U L L Y     E N R O L L E D                                        \n");
            printf("\n\t=====================================================================================================================================================");
            break;
        char a[15];

        case 2:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                            I M P O R T   S T U D E N T   R E C O R D                                              \n");
            printf("\n\tInput txt/csv file name: ");
            scanf(" %14[^\n]s", a);
            if(checkStudentFile(a) == -1){
                printf("\n\t                                                                     F I L E   I S   E M P T Y                                                       ");
                printf("\n\t=====================================================================================================================================================");
            }else if(checkStudentFile(a) == -0){
                printf("\n\t                                                                   F I L E    N O T    F O U N D                                                     ");
                printf("\n\t=====================================================================================================================================================");
            }else{
                inputStudentData(a);
                emptyStudentChecker();
            }
            break;

        case 3:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\tEnter Student 3-Digit ID number: ");
            scanf("%d", &n);
            int i;
            for(i = 0; cs11[i].studentID != n; i++);
            n = i;
            cs11[n] = updateStudentRecordsKeyboard(cs11[n]);
            break;

        case 4:
            system("cls");
            int see;
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                                   E N R O L L   S T U D E N T                                                     \n");
            printf("\tEnter Student 3-Digit ID number: ");
            scanf("%d", &n);
            for( i=0; i<cS; i++){
                if(n == cs11[i].studentID){
                    see = 1;
                    break;
                }
            }
            if(see == 1){
                see = 0;
                if(stringCompare(cs11[i].sub1->subCode, "none") == 0 || stringCompare(cs11[i].sub2->subCode, "none") == 0 || stringCompare(cs11[i].sub3->subCode, "none") == 0){
                    see++;
                }
                if(see == 1){
                    printf("\n\tAvailable Subjects:");
                    printf("\t\n\nID number\tSubject Code\tSubject Title\n");
                    for (int i = 0; i < cSub; i++){
                        if(stringCompare(sub[i].subCode, "none") != 0){
                            displaySubject(&sub[i]);
                        }
                    }
                    printf("\n\tInput Subject code: ");
                    scanf("%s",a);
                    studentEnrolSubject(n, a);
                }else{
                    printf("\n\tOverloaded\n");
                }
            }
            printf("\t=====================================================================================================================================================");
            break;

        case 5:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                                       D R O P   S T U D E N T                                                     \n");
            printf("\tEnter Student 3-Digit ID number: ");
            scanf("%d", &n);
            drop(n);
            printf("\t=====================================================================================================================================================");
            break;

        case 6:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            updateGrades();
            displayAllStudents(cS);
            break;

        case 7:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                          S E A R C H    S T U D E N T    R E C O R D                                            \n\n");
            printf("\tInput Student's Last Name: ");
            scanf("%s", a);
            studentNameSearch(a);
            printf("\n\t=====================================================================================================================================================");
            break;

        case 8:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                            D E L E T E   S T U D E N T   R E C O R D                                              \n");
            printf("\n\tEnter Student 3-Digit ID number to Delete: ");
            scanf("%d", &n);
            deleteStudent(n);
            printf("\n\t=====================================================================================================================================================");
            break;

        case 9:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                            C R E A T E   S U B J E C T   R E C O R D                                              \n");
            updateSubjectKeyboard(&sub[cSub]);
            ++cSub;
            printf("\n\t                                                   S U B J E C T   A D D E D   I N   T H E   D I R E C T O R Y");
            printf("\n\t=====================================================================================================================================================");
            break;

        case 10:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                            I M P O R T   S U B J E C T   R E C O R D                                              \n");
            printf("\n\tInput .txt/.csv file name: ");
            scanf(" %19[^\n]s", a);
            printf("\n");
            if(checkSubjectFile(a) == -1){
                printf("\n\t                                                                     F I L E   I S   E M P T Y                                                       ");
                printf("\n\t=====================================================================================================================================================");
            }else if(checkSubjectFile(a) == 0){
                printf("\n\t                                                                   F I L E    N O T    F O U N D                                                     ");
                printf("\n\t=====================================================================================================================================================");
            }else{
            inputSubjectData(a);
            }
            break;
        int found = 0;

        case 11:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                            U P D A T E   S U B J E C T   R E C O R D                                              \n");
            printf("\tEnter Subject Code: ");
            scanf("%s", a);
            printf("\n");
            for (n = 0; n < cSub; n++){
                if(stringCompare(sub[n].subCode, a) == 0){
                    found = 1;
                    break;
                }
            }
            if(found == 1){
                updateSubjectKeyboard(&sub[n]);
            }else{
                printf("\n\t                                                               N O    R E C O R D S    F O U N D                                                     ");
                printf("\n\t=====================================================================================================================================================");
            }
            break;

        case 12:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                       L I S T   O F    A L L    S U B J E C T S    I N    T H E    D I R E C T O R Y                             \n\n");
            printf("\t\t\tID Number\t\tSubject Code\t\tSubject Title\n");
            dequeuSubject();
            for (int i = 0; i < cSub; i++){
                if(stringCompare(sub[i].subCode, "none") != 0){
                    printf("\t\t\t");
                    displaySubject(&sub[i]);
                }
            }
            printf("\t=====================================================================================================================================================");
            break;

        case 13:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                            S E A R C H   S U B J E C T   R E C O R D                                              \n");
            printf("\tInput Subject Code: ");
            scanf("%s", &a);
            if (findSub(a) == -1){
                printf("Subject does not exists.\n");
                printf("Would you like to create subject record?.\n");
                printf("1 for yes, 0 for no: ");
                scanf("%d", &n);
                if(n == 1){
                    addSubjectKeyboard(&sub[cSub],a);
                    ++cSub;
                }
            }else{
                printf("\n\nID number\tSubject Code\tSubject Title\n");
                displaySubject(&sub[findSub(a)]);
            }
            printf("\n\t=====================================================================================================================================================");
			break;

        case 14:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                            D E L E T E   S U B J E C T   R E C O R D                                              \n");
            printf("\tAvailable Subjects to Delete:");
            printf("\t\n\nID number\tSubject Code\tSubject Title\n");
            for (int x = 1; x < cSub; x++){
                if(stringCompare(sub[x].subCode, "none") != 0){
                    displaySubject(&sub[x]);
                }
            }
            printf("\tEnter Subject Code to Delete: ");
            scanf("%s", a);
            if(stringCompare(a, sub[0].subCode) != 0){
                int deleted = 0;
                for(int i = 1; i<cSub; i++){
                    if(stringCompare(a, sub[i].subCode) == 0){
                        deleteSubject(a);
                        deleted = 1;
                        break;
                    }
                }
                if(deleted == 0){
                    printf("\nNo subject %s", a);
                }
            }else{
                printf("\nCannot delete CMSC11");
            }
            printf("\n\t=====================================================================================================================================================");
            break;

        case 15:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                           E X P O R T    M A S T E R L I S T    F I L E                                           \n");
            printf("\n\tEnter Masterlist File Name: ");
            scanf("%s", a);
            printf("\n\t=====================================================================================================================================================");
            break;

        default:
            system("cls");
            printf("\n\n");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                   S T U D E N T   R E G I S T R A T I O N   S Y S T E M                                             ");
            printf("\n\t                                                                University of the Philippines                                                        ");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t=====================================================================================================================================================");
            printf("\n\t                                                           P R O G R A M    T E R M I N A T E D                                                      ");
            printf("\n\t=====================================================================================================================================================");
            break;
    }
        printf("\n");
        for (int i = 0; i <= cS; i++){
        cs11[i] = scoreGrade(cs11[i]);
        }studentSort(cS);
    //Exam Statistcs
    studentStats[0] = statsEx1(studentStats[0]);
    studentStats[1] = statsEx2(studentStats[1]);
    studentStats[2] = statsEx3(studentStats[2]);
    studentStats[3] = statsHex(studentStats[3]);
    }
}
//==========================================================================================================================================

//==========================================================================================================================================
//Create Student Record Manually (Case 1)
struct student studentInputKeyboard(struct student inputStudent){
    char a[10];
    int lo = 1;

    printf("\n\t=====================================================================================================================================================");
    printf("\n\t                                                            C R E A T E   S T U D E N T   R E C O R D                                              \n");
    while(lo == 1){
        int hold, cnt = 0;
        reEnterID:
        printf("\tEnter a unique student 3 digit ID number: ");
        scanf("%d", &hold);
        if(hold > 999 || hold < 100){
            printf("\tPlease enter 3 digit number.\n");
            goto reEnterID;
        }
        for(int i = 0; i < cS + 1; i++){
            if (cs11[i].studentID == hold)
            {
                printf("\tID number is used. Input another ID number.\n");
                break;
            }else{
                ++cnt;
            }
        }
        if(cnt == cS + 1){
            inputStudent.studentID = hold;
            lo = 0;
            break;
        }
    }
    printf("\tEnter Last Name of Student              : ");
    scanf(" %14[^\n]s", inputStudent.lastName);
    printf("\tEnter First Name of Student             : ");
    scanf(" %14[^\n]s", inputStudent.firstName);
    printf("\tEnter Lecture Section of Student        : ");
    scanf(" %4[^\n]s", inputStudent.section);
    printf("\tEnter Hands-On Exam 1 Score             : ");
    scanf("%d", &inputStudent.exam1);
    printf("\tEnter Hands-On Exam 2 Score             : ");
    scanf("%d", &inputStudent.exam2);
    printf("\tEnter Hands-On Exam 3 Score             : ");
    scanf("%d", &inputStudent.exam3);
    printf("\n\tEnter Subject Code                      : ");
    scanf(" %9[^\n]s", a);
    if (findSub(a) == 0 && stringCompare(a, "none") != 0){
                printf("\t\tSubject Does Not Exists.\n");
                printf("\t\tWould You Like to Create Subject Record? ");
                printf("1 = Yes, 0 = No: ");
                int n;
                scanf("%d", &n);
                if(n == 1){
                    addSubjectKeyboard(&sub[cSub],a);
                    ++cSub;
                }
    }else{
        if(stringCompare(a, "none") == 0 ){
            inputStudent.sub2 = &temp;
        }else if(stringCompare(inputStudent.sub2->subCode,a) == 0 || stringCompare(inputStudent.sub1->subCode, a) == 0){
            printf("\n\tStudent Already Enrolled in that Subject.\n");
        }else{
            inputStudent.sub2 =&sub[findSub2(a)];
        }
    }
    printf("\n\tEnter Subject Code                      : ");
    scanf(" %9[^\n]s", a);
    if (findSub(a) == 0 && stringCompare(a, "none") != 0){
                printf("\t\tSubject Does Not Exists.\n");
                printf("\t\tWould You Like to Create Subject Record? ");
                printf("1 = Yes, 0 = No: ");
                int n;
                scanf("%d", &n);
                if(n == 1){
                    addSubjectKeyboard(&sub[cSub],a);
                    inputStudent.sub2 = & sub[cSub];
                    ++cSub;
                }
    }else{
        if(stringCompare(a, "none") == 0 ){
            inputStudent.sub2 = &temp;
        }else if(stringCompare(inputStudent.sub3->subCode, a) == 0 || stringCompare(inputStudent.sub2->subCode,a) == 0 || stringCompare(inputStudent.sub1->subCode, a) == 0){
            printf("\n\tStudent Already Enrolled in that Subject.\n");
        }else{
            inputStudent.sub2 =&sub[findSub2(a)];
        }
    }

    printf("\n");
    return inputStudent;
}

//Find Subject and Compare
int findSub(char a[10]){
    int n, found = 0;

    for (n = 0; n < cSub; n++){
        if(stringCompare(sub[n].subCode, a) == 0){
            found = 1;
            break;
        }
    }

    if(found == 1){
        return 1;
    }else{
        return 0;
    }
}
int findSub2(char a[10]){
    int n, found = 0;

    for (n = 0; n <= cSub; n++){
        if(stringCompare(sub[n].subCode, a) == 0){
            return n;
            break;
        }
    }
}
//==========================================================================================================================================
// Checks if .txt/.csv exists or if empty.
int checkStudentFile(char file[15]){
    int test;
    FILE * data;
    data = fopen(file, "r");
    if ((data = fopen(file, "r")) == NULL){
        return 0;
    }else{
        int d = fscanf(data, "%d", &test);
        return d;
    }

}
int checkSubjectFile(char file[15]){
    FILE * data;
    data = fopen(file, "r");
        if ((data = fopen(file, "r")) == NULL){
        return 0;
    }else{
        int d = fscanf(data, "%d, %[^,], %[^\n]", &sub[19].subID, sub[19].subCode, sub[19].subTitle);
        return d;
    }
}
//==========================================================================================================================================
//Import Student Record (Case 2)
void inputStudentData(char file[15]){
    char a[50], b[50], c[50], lName[20], fName[20]; int at, max, idNum;
    FILE * data;
    data = fopen(file, "r");

    if ((data = fopen(file, "r")) == NULL){
        printf("\n\t                                                                     I N V A L I D    F I L E                                                        ");
        printf("\n\t=====================================================================================================================================================");
    }else{
        while(!feof(data)){
        int same = 0;
        fscanf(data, "%d, %[^,], %[^,], %[^,], %d, %d, %d, %[^,], %[^,], %[^\n]\n", &cs11[cS].studentID, cs11[cS].firstName, cs11[cS].lastName, cs11[cS].section, &cs11[cS].exam1, &cs11[cS].exam2, &cs11[cS].exam3, a, b, c);


        for(int x = 0; x < cS; x++){
                if((cs11[x].studentID == cs11[cS].studentID && stringCompare(cs11[x].firstName, cs11[cS].firstName) != 0 && stringCompare(cs11[x].lastName, cs11[cS].lastName) != 0)||(cs11[x].studentID == cs11[cS].studentID && stringCompare(cs11[x].firstName, cs11[cS].firstName) == 0 && stringCompare(cs11[x].lastName, cs11[cS].lastName) != 0)||(cs11[x].studentID == cs11[cS].studentID && stringCompare(cs11[x].firstName, cs11[cS].firstName) != 0 && stringCompare(cs11[x].lastName, cs11[cS].lastName) == 0)){
                    max = cs11[0].studentID;
                    for(int y = 0; y < cS; y++){
                        if(cs11[y].studentID > max){
                            max = cs11[y].studentID;
                        }
                    }
                    cs11[cS].studentID = max + 1;
                    break;
                }
            }
            if (findSub(a) == 0 && stringCompare(a, "none") != 0){
                printf("\t\tSubject %s Does Not Exists.\n", a);
                printf("\t\tWould You Like to Create Subject Record? ");
                printf("1 = Yes, 0 = No: ");
                int n;
                scanf("%d", &n);
                if(n == 1){
                    addSubjectKeyboard(&sub[cSub],a);
                    cs11[cS].sub1 = &sub[cSub];
                    ++cSub;
                }
            }else{
                if(stringCompare(a, "none") == 0){
                    cs11[cS].sub2 = &temp;
                }else if(stringCompare(cs11[cS].sub2->subCode,a) == 0 || stringCompare(cs11[cS].sub1->subCode, a) == 0){
                    printf("\n\tStudent Already Enrolled in that Subject.\n");
                }else{
                    cs11[cS].sub2 = &sub[findSub2(a)];
                }
            }
            printf("\n%d find b\n", findSub(b));
            if (findSub(b) == 0 && stringCompare(b, "none") != 0){
                printf("\t\tSubject %s Does Not Exists.\n", b);
                printf("\t\tWould You Like to Create Subject Record? ");
                printf("1 = Yes, 0 = No: ");
                int n;
                scanf("%d", &n);
                if(n == 1){
                    addSubjectKeyboard(&sub[cSub],b);
                    cs11[cS].sub2 = &sub[cSub];
                    ++cSub;
                }
            }else{
                if(stringCompare(b, "none") == 0 ){
                    cs11[cS].sub2 = &temp;
                }else if(stringCompare(cs11[cS].sub1->subCode, b) == 0){
                    printf("\n\tStudent Already Enrolled in that Subject.\n");
                }else{
                    cs11[cS].sub2 =&sub[findSub2(b)];
                }
            }
            if (findSub(c) == 0 && stringCompare(c, "none") != 0){
                printf("\t\tSubject %s Does Not Exists.\n", c);
                printf("\t\tWould You Like to Create Subject Record? ");
                printf("1 = Yes, 0 = No: ");
                int n;
                scanf("%d", &n);
                if(n == 1){
                    addSubjectKeyboard(&sub[cSub],c);
                    cs11[cS].sub3 = &sub[cSub];
                    ++cSub;
                }
            }else{
                if(stringCompare(c, "none") == 0 ){
                    cs11[cS].sub2 = &temp;
                }else if(stringCompare(cs11[cS].sub2->subCode,c) == 0 || stringCompare(cs11[cS].sub1->subCode, c) == 0){
                    printf("\n\tStudent Already Enrolled in that Subject.\n");
                }else{
                    cs11[cS].sub2 =&sub[findSub2(c)];
                }
            }
            for(int x = 0; x < cS; x++){
                if(stringCompare(cs11[cS].lastName, cs11[x].lastName) == 0 && stringCompare(cs11[cS].firstName, cs11[x].firstName) == 0){
                    printf("Student %s %s already exists in student records.\n", cs11[cS].firstName, cs11[cS].lastName);
                    same = 1;
                    break;
                }
            }
            if(same == 0){
                cS++;
            }
        }
        printf("\n\t                                        S U C C E S S F U L L Y    I M P O R T E D    S T U D E N T    R E C O R D    F I L E                        ");
        printf("\n\t=====================================================================================================================================================");
    }
}
//==========================================================================================================================================

//==========================================================================================================================================
//Update Student Record (Case 3)
struct student updateStudentRecordsKeyboard(struct student inputStudent){
    int choice2;

    do{
        printf("\n\t=====================================================================================================================================================");
        printf("\n\t                                                            U P D A T E   S T U D E N T   R E C O R D                                              \n");
        printf("\n\t                                            1: Update Last Name                        5: Update Second Hands on Exam Score                           ");
        printf("\n\t                                            2: Update First Name                       6: Update Third Hands on Exam Score                            ");
        printf("\n\t                                            3: Update CMSC11 Lecture Section           0: Return to Main Menu                                         ");
        printf("\n\t                                            4: Update First Hands on Exam Score                                                                       ");
        printf("\n\t=====================================================================================================================================================");
        printf("\n\tEnter Choice: ");
        scanf(" %d", &choice2);

            if(choice2 == 1){
                printf("\n\tInput Updated Last Name: ");
                scanf(" %14[^\n]s", inputStudent.lastName);
            }else if(choice2 == 2){
                printf("\n\tInput Updated First Name: ");
                scanf(" %14[^\n]s", inputStudent.firstName);
            }else if(choice2 == 3){
                printf("\n\tInput Updated CMSC11 Lecture Section: ");
                scanf(" %4[^\n]s", inputStudent.section);
            }else if(choice2 == 4){
                printf("\n\tInput Updated First Hands on Exam Score: ");
                scanf("%d", &inputStudent.exam1);
            }else if(choice2 == 5){
                printf("\n\tInput Updated Second Hands on Exam Score: ");
                scanf("%d", &inputStudent.exam2);
            }else if(choice2 == 6){
                printf("\n\tInput Updated Third Hands on Exam Score: ");
                scanf("%d", &inputStudent.exam3);
            }else if(choice2 == 0){
                printf("\n\t\t\t\t\t\t\t\t\tR E D I R E C T I N G    T O    M A I N    M E N U");
            }else{
                printf("\n\t\t\t\t\t\t\t\t\t    I N V A L I D    C H O I C E");
            }

    }while(choice2 != 0);

    return inputStudent;
}
//==========================================================================================================================================

//==========================================================================================================================================
//Enroll Student (Case 4)
void studentEnrolSubject(int idNum, char code[20]){
    int found = 0, find = 0;

    for(int i = 0; i <= cS; i++){
        if(cs11[i].studentID == idNum){
            found = 1;
            if(stringCompare(code, cs11[i].sub1->subCode) == 0 || stringCompare(code, cs11[i].sub2->subCode) == 0 || stringCompare(code, cs11[i].sub3->subCode) == 0){
                printf("\t\tStudent is already enrolled in this subject.\n");
                break;
            }

            for(int j = 1; j <= cSub; j++){
                if(stringCompare(code, sub[j].subCode) == 0){
                    if(cs11[i].sub2->subID == 0){
                        cs11[i].sub2 = &sub[j];
                        find = 1;
                        printf("\t\tSuccessfully Enrolled\n");
                        break;
                    }else if (cs11[i].sub3->subID == 0){
                        cs11[i].sub3 = &sub[j];
                        find = 1;
                        printf("\t\tSuccessfully Enrolled\n");
                        break;
                    }else{
                        printf("\t\tStudent Enrolled in Maximum Subjects\n");
                        find = 1;
                        break;
                    }
                }
            }
            if(find == 0){printf("\t\tSubject Code Does Not Exists\n");}

            break;
        }
    }if(found == 0){printf("Student ID number not found\n");}
}

void cmscEnrol(struct student *cs11Student){
    cs11Student->sub1 = &sub[0];
}
//==========================================================================================================================================
//==========================================================================================================================================

//Drop Subject (Case 5)
void drop(int n){
    int i;
    char a[50];
    for(i = 0; cs11[i].studentID != n; i++);
    if(stringCompare(cs11[i].sub1->subCode, "none") == 0 && stringCompare(cs11[i].sub2->subCode, "none") == 0 && stringCompare(cs11[i].sub3->subCode, "none") == 0){
        printf("Student is not enrolled in any subjects.\n");
    }else{
        printf("\n\tSubjects of Student            : %s, %s, %s\n\n", cs11[i].sub1->subCode, cs11[i].sub2->subCode, cs11[i].sub3->subCode);
        printf("\tEnter Subject Code to Drop      : ");
        scanf(" %s", a);

        if(stringCompare(a, sub[0].subCode) == 0){
            printf("\t\tSubject cannot be dropped.\n");
        }else if(stringCompare(cs11[i].sub2->subCode, a) == 0){
            printf("%s is dropped.\n", cs11[i].sub2->subCode);
            cs11[i].sub2 = cs11[i].sub3;
            cs11[i].sub3 = &temp;
        }else if(stringCompare(cs11[i].sub3->subCode, a) == 0){
            printf("\t\t%s is dropped.\n", cs11[i].sub3->subCode);
            cs11[i].sub3 = &temp;
        }else{
        printf("\t\tSubject Does Not Exists\n");
        }
    }
}
//==========================================================================================================================================

//==========================================================================================================================================
//Display All Student Record (Case 6)
// Displays all student's records with statistics(lowest, highest and standard deviation)
void displayAllStudents(int s){
    printf("\n\t                                       L I S T   O F    A L L    S T U D E N T S    I N    T H E    D I R E C T O R Y                             \n\n");
    printf("\tID   Last Name              First Name             Section   Subjects                      Hex 1   Hex 2   Hex 3   Total   Grade\n");

    for (int i = 0; i < s; i++){
        int index1, index2,index3, index4;
        printf("\t%03d  %s", cs11[i].studentID, cs11[i].lastName);
        index1 = strcspn(cs11[i].lastName, "\n");
        for (int j = 1; j <= 23-index1; j++){
            printf(" ");
        }
        printf("%s", cs11[i].firstName);
        index1 = strcspn(cs11[i].firstName, "\n");
        for (int j = 1; j <= 23-index1; j++){
            printf(" ");
        }
        printf("%s", cs11[i].section);
        index1 = strcspn(cs11[i].section, "\n");
        for (int j = 1; j <= 10-index1; j++){
            printf(" ");
        }
        printf("%s,", cs11[i].sub1->subCode);
        index1 = strcspn(cs11[i].sub1->subCode, "\n");
        printf("%s,", cs11[i].sub2->subCode);
        index2 = strcspn(cs11[i].sub2->subCode, "\n");
        printf("%s", cs11[i].sub3->subCode);
        index3 = strcspn(cs11[i].sub3->subCode, "\n");
        for (int j = 1; j <= 30-index1-index2-index3-2; j++){
            printf(" ");
        }
        printf("%d      %d      %d      %d     %s\n", cs11[i].exam1, cs11[i].exam2, cs11[i].exam3,cs11[i].hex,cs11[i].grade);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tLowest:    %d\t   %d\t   %d\t    %d\n",studentStats[0].low, studentStats[1].low ,studentStats[2].low,studentStats[3].low);
    printf("\t\t\t\t\t\t\t\t\t\t       Highest:    %d\t   %d\t   %d\t    %d\n",studentStats[0].high, studentStats[1].high ,studentStats[2].high,studentStats[3].high);
    printf("\t\t\t\t\t\t\t\t\t\t       Average:  %.3f\t %.3f\t %.3f   %.3f\n",studentStats[0].ave, studentStats[1].ave ,studentStats[2].ave,studentStats[3].ave);
    printf("\t\t\t\t\t\t\t\t\t    Standard Deviation:  %.3f\t %.3f\t %.3f    %.3f\n",studentStats[0].sd, studentStats[1].sd ,studentStats[2].sd,studentStats[3].sd);
    printf("\t=====================================================================================================================================================");
    printf("\n");
}

// Determines student's grade from exam scores.
struct student scoreGrade(struct student iS){
    iS.hex = iS.exam1 + iS.exam2 + iS.exam3;
    if(iS.hex >= 135){
        strcpy (iS.grade, "HD");
    }else if (iS.hex >= 120)
    {
        strcpy (iS.grade, "D");
    }else if (iS.hex >= 100)
    {
        strcpy (iS.grade, "P");
    }else if (iS.hex >= 75)
    {
        strcpy (iS.grade, "C");
    }else{
        strcpy (iS.grade, "F");
    }

    return iS;
}
// Statistics for Exam 1
struct stat statsEx1(struct stat st){
    int scores[cS];
    int min = cs11[0].exam1;
    int max = cs11[0].exam1;
    float ave = 0,stD = 0;

    // Lowest and highest
    for (int i = 0; i < cS; i++){
        scores[i] = cs11[i].exam1;
        ave += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    ave /= cS;
    // Standard deviation
    for (int i = 0; i < cS; i++){
        stD += pow(cs11[i].exam1 - ave, 2);
    }
    st.sd = sqrt(stD/cS);
    st.ave = ave;
    st.high = max;
    st.low = min;
    return st;
}
//Statistics for Exam 2
struct stat statsEx2(struct stat st){
    int scores[cS];
    int min = cs11[0].exam2;
    int max = cs11[0].exam2;
    float ave = 0,stD = 0;

    // Lowest and highest
    for (int i = 0; i < cS; i++){
        scores[i] = cs11[i].exam2;
        ave += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    ave /= cS;

    // Standard deviation
    for (int i = 0; i < cS; i++){
        stD += pow(cs11[i].exam2 - ave, 2);
    }
    st.sd = sqrt(stD/cS);
    st.ave = ave;
    st.high = max;
    st.low = min;
    return st;
}
// Statistics for Exam 3
struct stat statsEx3(struct stat st){
    int scores[cS];
    int min = cs11[0].exam3;
    int max = cs11[0].exam3;
    float ave = 0,stD = 0;

    // Lowest and highest
    for (int i = 0; i < cS; i++){
        scores[i] = cs11[i].exam3;
        ave += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    ave /= cS;

    // Standard deviation
    for (int i = 0; i < cS; i++){
        stD += pow(cs11[i].exam3 - ave, 2);
    }
    st.sd = sqrt(stD/cS);
    st.ave = ave;
    st.high = max;
    st.low = min;
    return st;
}
// Statistics for total scores
struct stat statsHex(struct stat st){
    int scores[cS];
    int min = cs11[0].hex;
    int max = cs11[0].hex;
    float ave = 0,stD = 0;

    // Lowest and highest
    for (int i = 0; i < cS; i++){
        scores[i] = cs11[i].hex;
        ave += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    ave /= cS;

    // Standard deviation
    for (int i = 0; i < cS; i++){
        stD += pow(cs11[i].hex - ave, 2);
    }
    st.sd = sqrt(stD/cS);
    st.ave = ave;
    st.high = max;
    st.low = min;
    return st;
}
//Display All Student Records Alphabetically (Bubble Sort)
void studentSort(int n){
for (int i = 0; i < n - 1; i++){
    for (int c = i; c < n - 1; c++){
        if (stringCompare(cs11[c].lastName,cs11[c+1].lastName) == 1){
            tempo = cs11[c + 1];
            cs11[c + 1] = cs11[c];
            cs11[c] = tempo;
            }
        }
    }
}

//==========================================================================================================================================

//==========================================================================================================================================
//Search Student Record (Case 7)
void studentNameSearch(char a[15]){
    int cnt = 0;
    if(cnt==0){
        printf("\tID   Last Name              First Name             Section   Subjects                      Hex 1   Hex 2   Hex 3   Total   Grade\n");
    }

    for(int i = 1; i < cS; i++){
        if(stringCompare(a,cs11[i].lastName) == 0){
            displayStudent(i);
            cnt++;
        }
    }

    if(cnt == 0){
        printf("\n\tStudent Does Not Exists\n");
    }
    printf("\n\t=====================================================================================================================================================");
}
//Compare Small Case and Big Case Letter of Last Name

int stringCompare(char c1[], char c2[]){
    char s1[15], s2[15];
    strcpy(s1, c1);
    strcpy(s2, c2);
    for (int d = 0; d<15; d++){
        if ((s1[d]>='A' && s1[d]<='Z')){
            s1[d] = s1[d] + 32;
        }
        if ((s2[d]>='A' && s2[d]<='Z')){
            s2[d] = s2[d] + 32;
        }
    }
    int a=0;
    for(int b=0; s1[b]!='\0'; b++){
        if (s1[b+1] == '\0' && s2[b+1]!= '\0'){
            a = -1;
            break;
        }if(s1[b]>s2[b]){
            a = 1;
           break;
        }if(s1[b]<s2[b]){
           a = -1;
            break;
        }if(s1[b] == s2[b]){
          a = 0;
        }
    }
    return (a);
}
char toLower(char ch){
        if(ch >= 'a' && ch<= 'z'){
        return ch;
    }else{
        return(ch + 32);
    }
}
//Display Search Record
void displayStudent(int num){
        for (int i = 1; i < num; i++){
        int index1, index2,index3, index4;
        printf("\t%03d  %s", cs11[num].studentID, cs11[num].lastName);
        index1 = strcspn(cs11[num].lastName, "\n");
        for (int j = 1; j <= 23-index1; j++){
            printf(" ");
        }
        printf("%s", cs11[num].firstName);
        index1 = strcspn(cs11[num].firstName, "\n");
        for (int j = 1; j <= 23-index1; j++){
            printf(" ");
        }
        printf("%s", cs11[num].section);
        index1 = strcspn(cs11[num].section, "\n");
        for (int j = 1; j <= 10-index1; j++){
            printf(" ");
        }
        printf("%s,", cs11[num].sub1->subCode);
        index1 = strcspn(cs11[num].sub1->subCode, "\n");
        printf("%s,", cs11[num].sub2->subCode);
        index2 = strcspn(cs11[num].sub2->subCode, "\n");
        printf("%s", cs11[num].sub3->subCode);
        index3 = strcspn(cs11[num].sub3->subCode, "\n");
        for (int j = 1; j <= 30-index1-index2-index3-2; j++){
            printf(" ");
        }
        printf("%d      %d      %d      %d     %s\n", cs11[num].exam1, cs11[num].exam2, cs11[num].exam3,cs11[num].hex,cs11[num].grade);
        break;
    }
}
//==========================================================================================================================================

//==========================================================================================================================================
//Delete Student Record (Case 8)
void deleteStudent(int n){
    int i;
    for(i = 0; i <= cS; i++){
        if (cs11[i].studentID == n){
            break;
        }
    }
    for(int x = i; x < cS; x++){
        cs11[x] = cs11[x + 1];
    }
    --cS;
}
//==========================================================================================================================================

//==========================================================================================================================================
//Create Subject Record Manually (Case 9)
void updateSubjectKeyboard(struct subject *inputSub){
    int lo = 1, cnt = 1;
    while(lo == 1){
        int hold;
        cnt= 1;
        printf("\n\tEnter Subject ID number: ");
        scanf("%d", &hold);
        for(int i = 0; i < cSub; i++){
            if (sub[i].subID == hold){
                printf("ID number is used. Input another ID number.\n");
                cnt = 0;
                break;
            }
        }
        if(cnt == 1){
            inputSub->subID = hold;
            lo = 0;
        }
    }
    printf("\tEnter Subject Code: ");
    scanf(" %9[^\n]s", inputSub->subCode);
    printf("\tEnter Subject Title: ");
    scanf(" %49[^\n]s", inputSub->subTitle);
}

void addSubjectKeyboard(struct subject *inputSub, char a[]){
    printf("\n\t\tCreate Subject Record\n", a);
    strcpy(inputSub->subCode, a);
    int lo = 1;
    while(lo == 1){
        int hold, cnt = 0;
        reEnterSub:
        printf("\tEnter 4-digit Subject ID number: ");
        scanf("%d", &hold);
        for(int i = 0; i < 70; i++){
            if (sub[i].subID == hold)
            {
                printf("\t\tID number is used. Input another ID number.\n");
                break;
            }else{
                ++cnt;
            }
        }
        if(cnt == 70){
            inputSub->subID = hold;
            lo = 0;
        }
    }
    printf("\tEnter Subject Title: ");
    scanf(" %49[^\n]s", inputSub->subTitle);
}

//==========================================================================================================================================

//==========================================================================================================================================
//Import Subject Record (Case 10)
void inputSubjectData(char file[15]){
    FILE * data;
    data = fopen(file, "r");
    int inside;
    if ((data = fopen(file, "r")) == NULL){
        printf("\n\t                                                                     I N V A L I D    F I L E                                                        ");
        printf("\n\t=====================================================================================================================================================");
    }else{
    while(!feof(data) && cSub <= 21){
    inside = 0;
    fscanf(data, "%d, %[^,], %[^\n]", &sub[cSub].subID, sub[cSub].subCode, sub[cSub].subTitle);

    if(sub[cSub].subID == 0){
            break;
    }
    ++cSub;

    }
    for(int i = 0; i<cSub; i++){
        for(int j=i; j<cSub; j++){
            if(sub[i].subID != 0 && j!= i){
                if(stringCompare(sub[i].subCode, sub[j].subCode)==0){
                    sub[j] = temp;
                }
            }
        }

    }
    printf("\n\t                                        S U C C E S S F U L L Y    I M P O R T E D    S U B J E C T    R E C O R D    F I L E                        ");
    printf("\n\t=====================================================================================================================================================");
    }
}
//==========================================================================================================================================

//==========================================================================================================================================
//Display All Subject Records (Case 12)
void displaySubject(struct subject *inputSubPtr){
    if(inputSubPtr->subID != 0){
    printf("%d\t\t", inputSubPtr->subID);
    printf("\t%s\t\t\t", inputSubPtr->subCode);
    printf("%s\t\t\n", inputSubPtr->subTitle);
    }
}
//==========================================================================================================================================

//==========================================================================================================================================
//Search Subject Record (Case 13)
void subjectSearch(char z[15]){
    int cnt = 0;
    int i;
    for(i = 0; i < cSub; i++){
        if(stringCompare(z,sub[i].subCode) == 0){
            displaySubject(&sub[i]);
            printf("\n");
            cnt++;
        }
    }
    if(cnt == 0){
        printf("\n\tSubject Does Not Exists");
    }
    printf("\n\t=====================================================================================================================================================");
}
//==========================================================================================================================================

//==========================================================================================================================================
//Delete Subject Record (Case 14)
void deleteSubject(char a[]){
    int i;
    for(i = 0; i <= cSub; i++){
        if (stringCompare(sub[i].subCode, a)==0){
            for (int x = i; x <= cSub; x++){
                sub[x] = sub[x + 1];
            }
            printf("\n\t                                        S U C C E S S F U L L Y    D E L E T E D     S U B J E C T    R E C O R D     F I L E                        ");
            printf("\n\t=====================================================================================================================================================");
            cSub -= 1;
            break;
        }
    }
}
//==========================================================================================================================================

//==========================================================================================================================================
//Export Masterlist (Case 15)
void writeTxt(char file[15]){
    FILE * data;
    data = fopen(file, "w");
    for (int i = 0; i < cS; i++){
        fprintf(data, "%d, %s, %s, %s, %d, %d, %d, %s, %s, %s, %d, %s\n", cs11[i].studentID, cs11[i].firstName, cs11[i].lastName, cs11[i].section, cs11[i].exam1, cs11[i].exam2, cs11[i].exam3, cs11[i].sub1->subCode, cs11[i].sub2->subCode, cs11[i].sub3->subCode, cs11[i].hex, cs11[i].grade);
        if(cs11[i].studentID == 0){

            break;
        }
    }
    fclose(data);
    printf("\n\t                                       S U C C E S S F U L L Y    E X P O R T E D    M A S T E R L I S T     F I L E                                 ");
    printf("\n\t=====================================================================================================================================================");
}
//==========================================================================================================================================
void dequeuSubject(void){
    int i;
    for(i = 1; i < cSub; i++){
        if (sub[i].subID == 0){
            for (int x = i; x <= cSub; x++){
                sub[x] = sub[x + 1];
            }
            cSub -= 1;
            break;
        }
    }
}
// Function that updates student's grades and score statistics.
void updateGrades(void){
    for (int i = 0; i <= cS; i++)
    {
        cs11[i] = scoreGrade(cs11[i]);
    }
    studentSort(cS);
    //Exam Statistcs
    studentStats[0] = statsEx1(studentStats[0]);
    studentStats[1] = statsEx2(studentStats[1]);
    studentStats[2] = statsEx3(studentStats[2]);
    studentStats[3] = statsHex(studentStats[3]);
}
void emptyStudentChecker(void){
    for(int x = 0; x < cS; x++){
        if(cs11[x].studentID == 0){
                int i;
        for(i = 0; i <= cS; i++){
            if(cs11[i].studentID == 0){
                break;
            }
        }
        for(int x = i; x < cS; x++){
            cs11[x] = cs11[x + 1];
        }
        --cS;
        }
    }
}
