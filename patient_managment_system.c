#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//structure
typedef struct hafiz_coder
{
    char hospital_name[50];
    char hospital_address[50];
    char patient_fname[10];
    char patient_lname[10];
    int patient_age;
    char patient_phoneNo[15];
    char filename[30];
    char doctor_fname[10];
    char doctor_lname[10];
    char doctor_phoneNo[15];
    char disease_details[200];
    char test_details[200];
    char medicine_details[200];

} patientt;

//functions
void hospital(patientt *p1);
void patient(patientt *p1);
void doctor(patientt *p1);
void disease(patientt *p1);
void test(patientt *p1);
void medicine(patientt *p1);
int report(patientt *p1);
void writeReport(patientt *p1, FILE *ptr);
void readReport(patientt *p1, FILE *ptr);
int endofprogram();

int main()
{

play:
    // system("cls");
    printf("\n\n");
    printf("\n\n*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\n\n");
    printf("\t *** *** *** Welcome To Patient Management System *** *** *** ");
    printf("\n\n*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\n\n");
    printf("\t\t ==> Enter Your Choice! <==\n\n");
    printf("\t==> 1:Hospital Details\n");
    printf("\t==> 2:Doctor Details \n");
    printf("\t==> 3:Patient Details\n");
    printf("\t==> 4:Disease Details\n");
    printf("\t==> 5:Test Details\n");
    printf("\t==> 6:Medicine Details\n");
    printf("\t==> 7:Report\n");
    printf("\t==> 8:Exit\n");
    int choice;                                      //variable to use in switch statement for further decisions
    printf("\n\t***** Enter Your Choice *****\n\n"); //showing message to user
    scanf("%d", &choice);                            //takisng user choice for further use of program
    int flag = 0;                                    //this variable will bring us to resue over main entity or program

    //creating variable of custom data type
    patientt p;
    switch (choice) //declaration of switch
    {
    case 1:
        hospital(&p);
        //this function will return a value for further decision
        //that how to deal with program either exit or reuse
        break;
    case 2:
        doctor(&p);
        //this function will return a value for further decision
        //that how to deal with program either exit or reuse
        break;
    case 3:
        patient(&p);
        break;
    case 4:
        disease(&p);
        break;
    case 5:
        test(&p);
        break;
    case 6:
        medicine(&p); //this function will return a value for further decision
        //that how to deal with program either exit or reuse
        break;
    case 7:
        report(&p);

        break;
    case 8:
        flag = endofprogram();
        return 0;
        break;

    default:
        printf("Invalid choice!\n");
        break;
    }
    if (flag == 1) //if any function return 1 it mean user want to reuse program
    {
        goto play; //mean reuse main program
    }
    else //we will ask user that he/she want to reuse or exit
    {

        printf("Press y/Y to Continue OR To Exit Enter 'n/N'\n"); //showing suggestion to user
        char choose;                                              //variable to take user choice
        fflush(stdin);                                            //library function to clear buffer
        scanf("%c", &choose);                                     //taking user input/choice
        if (choose == 'y' || choose == 'Y')                       //if user select y/Y mean user want to reuse program
        {
            goto play;

        } //any other charcter consider as continue of program
        else
        {
            return 0;
        }
    }

    return 0;
}
void patient(patientt *p1)
{
    //creating variable of custom data type

    //taking patient details
    printf("Enter Patient 1st Name\n");
    fflush(stdin);
    gets(p1->patient_fname);
    printf("Enter Patient 2nd Name\n");
    fflush(stdin);
    gets(p1->patient_lname);
    printf("Enter Patient Age\n");
    fflush(stdin);
    scanf("%d", &p1->patient_age);
    printf("Enter Patient Phone Number(0312-1234567)\n");
    fflush(stdin);
    gets(p1->patient_phoneNo);
}
void hospital(patientt *p1)
{
    printf("Enter Hospital Name\n");
    fflush(stdin);
    gets(p1->hospital_name);
    printf("Enter Hospital Address\n");
    fflush(stdin);
    gets(p1->hospital_address);
}
void doctor(patientt *p1)
{
    //taking doctor details
    printf("Enter Doctor 1st Name\n");
    fflush(stdin);
    gets(p1->doctor_fname);
    printf("Enter Doctor 2nd Name\n");
    fflush(stdin);
    gets(p1->doctor_lname);
    printf("Enter Doctor Phone Number(0312-1234567)\n");
    fflush(stdin);
    gets(p1->doctor_phoneNo);
}
void disease(patientt *p1)
{
    //taking disease details
    printf("Enter Disease complete details (like paragraph etc)\n");
    printf("Enter Doller sign ( $ ) to end\n\n");
    fflush(stdin);
    scanf("%[^ $]s", p1->disease_details);
    printf("\n\nFollowing Disease Data Recorded\n\n%s\n", p1->disease_details);
}
void test(patientt *p1)
{
    //taking test details
    printf("Enter Test complete details (like paragraph etc)\n");
    printf("Enter Doller sign ( $ ) to end\n\n");
    fflush(stdin);
    scanf("%[^ $]s", p1->test_details);
    printf("\n\nFollowing TEST Recorded\n\n%s\n", p1->test_details);
}
void medicine(patientt *p1)
{
    //taking medicine details
    printf("Enter Medicine complete details (like paragraph etc)\n");
    printf("Enter Doller sign ( $ ) to end\n\n");
    fflush(stdin);
    scanf("%[^ $]s", p1->medicine_details);
    printf("\n\nFollowing Medicine Recorded\n\n%s\n", p1->medicine_details);
}
int report(patientt *p1)
{

    //genratin file name
    // char filename[30];
    char fileExtension[] = ".txt";
    strcpy(p1->filename, p1->patient_fname);
    strcat(p1->filename, p1->patient_lname);
    strcat(p1->filename, fileExtension);
    //generating file of patient
    FILE *ptr;
    ptr = fopen(p1->filename, "a"); //opening file
    if (ptr == NULL)
    {
        printf("\n\t ***** Error in opening file ***** \n");
    }
    else
    {
        writeReport(p1, ptr);
    }
    fclose(ptr);
    //reading patient file
    ptr = fopen(p1->filename, "r"); //opening file
    if (ptr == NULL)
    {
        printf("\n\t ***** Error in opening file ***** \n");
    }
    else
    {
        readReport(p1, ptr);

        printf("Press y/Y to Reuse software OR To Exit Enter 'n/N'\n\n"); //showing suggestion to user
        char choose;                                                      //variable to take user choice
        fflush(stdin);                                                    //library function to clear buffer
        scanf("%c", &choose);                                             //taking user input/choice
        if (choose == 'n' || choose == 'N')                               //if user select y/Y mean user want to reuse program
        {
            return 0;

        } //any other charcter consider as continue of program
        else
        {
            return 1;
        }
    }
    fclose(ptr);
}
void writeReport(patientt *p1, FILE *ptr)
{

    fprintf(ptr, "HOSPITAL NAME: %-25s Hospital Address: %-30s\n\n\nDoctor Name: %-10s %-10s \t\t Doctor Phone Number: %-15s \n\nPatient Name: %-10s %-10s \tAge: %-3d  Patient PhNO: %-15s\n\n\t\tDISEASE DETAILS ARE:\n%-200s\n\t\tTEST DETAILS ARE:\n%-200s\n\t\tMEDICINE DETAILS ARE:\n%-200s\n\n\nDate:%-20s\t\tTime:%-20s", p1->hospital_name, p1->hospital_address, p1->doctor_fname, p1->doctor_lname, p1->doctor_phoneNo, p1->patient_fname, p1->patient_lname, p1->patient_age, p1->patient_phoneNo, p1->disease_details, p1->test_details, p1->medicine_details,__DATE__,__TIME__);
}
void readReport(patientt *p1, FILE *ptr)
{
    char stringg[200];
    fgets(stringg, 200, ptr);
    while (!feof(ptr))
    {
        printf("%s", stringg);
        fgets(stringg, 200, ptr);
    }
    printf("\nprinting Above file\n\n");
    char printing_data[40];
    strcpy(printing_data,"notepad /p  ");
    strcat(printing_data,p1->filename);
    system(p1->filename);
    printf("printing...");
}

int endofprogram()
{
    printf("\n\n\t\tThank You For Using This Software.....\n\n");
    printf("*****\t*****\t*****\t*****\t*****\t*****\t*****\t*****\t* ****\t*****\n\n");
    return 0;
}