#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int getMonth();
void workingDays();
void generalPayroll();
void displayRecords();
void eraseRecords();
void aboutCreator();
void titleHeader();
void noRecordsdisplay();

int main()
{
    system ("COLOR 0F");
    char choice;
    int condit;
    condit = 1;
    do{
    system ("COLOR 0F");
    titleHeader();
    printf("[1] Start\n[2] Show Records\n[3] Delete Records\n[4] About Creator\n[5] Exit\n\n\n");
    printf("Your Choice: ");
    choice = getche();

    switch (choice)
    {

        case '1':
        system ("COLOR 0B");
        system ("cls");
        workingDays();
        generalPayroll();
        printf("\n");
        system ("pause");
        system ("cls");
        condit = 1;
        break;

        case '2':
        system ("cls");
        system ("COLOR 0B");
        displayRecords();
        printf("\n");
        system ("pause");
        system ("cls");
        condit = 1;
        break;

        case '3':
        system ("COLOR 0B");
        system ("cls");
        eraseRecords();
        system ("cls");
        condit = 1;
        break;

        case '4':
        system ("cls");
        system ("COLOR 0B");
        aboutCreator();
        printf("\n");
        system ("pause");
        system ("cls");
        condit = 1;
        break;

        case '5':
        exit (0);
        break;

        default:
        system ("cls");
        system ("COLOR 0B");
        printf("Invalid Choice. Please Try Again.\n\n");
        system ("pause");
        system ("cls");
        condit = 1;
        break;

    }
    }while (condit == 1);
    return 0;
}

int getMonth()
{

    int maxDaysworked, compare;
    char whatMonth [100];

    printf("(Please spell the name of the month you desired)\n\n");

    do{
    printf("Please enter what month of payroll: ");
    scanf("%s", whatMonth);
    if (strcmpi(whatMonth, "January") == 0){
        maxDaysworked = 27;
        compare = 0;
    }
    else if (strcmpi(whatMonth, "February") == 0){
        maxDaysworked = 25;
        compare = 0;
    }
    else if (strcmpi (whatMonth, "March") == 0){
        maxDaysworked = 26;
        compare = 0;
    }
    else if (strcmpi (whatMonth, "April") == 0){
        maxDaysworked = 26;
        compare = 0;
    }
    else if(strcmpi(whatMonth, "May") == 0){
        maxDaysworked = 26;
        compare = 0;
    }
    else if(strcmpi(whatMonth, "June") == 0){
        maxDaysworked = 26;
        compare = 0;
    }
    else if(strcmpi(whatMonth, "July") == 0){
        maxDaysworked = 27;
        compare = 0;
    }
    else if(strcmpi(whatMonth, "August") == 0)
    {
        maxDaysworked = 26;
        compare = 0;
    }
    else if(strcmpi(whatMonth, "September") == 0){
        maxDaysworked = 26;
        compare = 0;
    }
    else if(strcmpi(whatMonth, "October") == 0){
        maxDaysworked = 27;
        compare = 0;
    }
    else if(strcmpi(whatMonth, "November") == 0){
        maxDaysworked = 25;
        compare = 0;
    }
    else if(strcmpi(whatMonth, "December") == 0){
        maxDaysworked = 27;
        compare = 0;
    }
    else{
        printf("Error, try again.\n\n");
        compare = 1;
    }
    }while (compare == 1);

    FILE* fpMonth = fopen("whatMonth.DAT", "w");
    fprintf(fpMonth, "%s", whatMonth);
    fclose(fpMonth);
    system("cls");
    return maxDaysworked;
}

void workingDays()
{
    FILE* fpEmpnam = fopen("NameEmployee.DAT", "r");
    FILE* fpDaysworked = fopen("DaysWorked.DAT", "w");
    char nameEmp [200];
    int i, maxDays, compare;
    float daysWorked;
    if (!fpEmpnam)
    {
        printf("Error on opening the NameEmployee file.\n");
        exit (100);
    }
    if (!fpDaysworked)
    {
        printf("Error on opening the Daysworked file.\n");
        exit (101);
    }

    maxDays = getMonth();

    printf("(Please enter between 0 - %d days)\n\n", maxDays);
    printf("Name: \t\tDays worked:\n");
    while ((fscanf(fpEmpnam,"%s", nameEmp)) == 1){
        for(i=1; i < 2; i++){
            printf("\n%s      \t", nameEmp);
            do{
                if ( scanf("%f", &daysWorked) != 1)
                {
                    printf("Reenter.   \t");
                    compare = fflush(stdin);
                }
                else
                {
                    if (daysWorked > maxDays || daysWorked < 0)
                    {
                        printf("Reenter.   \t");
                        compare = fflush(stdin);
                    }
                    else
                    {
                        compare = 1;
                    }
                }
            }while (compare == 0);
            fprintf(fpDaysworked,"%.2f \n", daysWorked);
        }
    }

    printf("\n\nDone, That's All your employees!\n\n");

    fclose(fpDaysworked);
    fclose(fpEmpnam);
}

void generalPayroll()
{
    FILE* fpDaysworked = fopen("DaysWorked.DAT", "r");
    FILE* fpDailypay = fopen("DailySalary.DAT", "r");
    FILE* fpEmpfile = fopen("Employee File.DAT", "w");
    FILE* fpReduction = fopen("GeneralPayroll.DAT", "w");

    if (!fpReduction){
        printf("Error on opening the AllReduction file.\n");
        exit (106);
    }
    if (!fpDaysworked)
    {
        printf("Error on opening the Daysworked file.\n");
        exit (101);
    }
    if (!fpDailypay)
    {
        printf("Error on opening the DailySalary file.\n");
        exit (102);
    }

    if (!fpEmpfile)
    {
        printf("Error on opening the Employee file.\n");
        exit (105);
    }
    int i;
    char nameEmp [100];
    float paymentDay, monthlySalary, daysWorked, salary, sssReduc, netPay, totalAmount = 0,reducedSSSAmount,pagibigReduc,taxReduc,reducedTaxamount;

    fprintf(fpReduction,"Name:     \tSSS:     \tPAGIBIG:     \tTAX:     \tNet Pay:\n\n");
    fprintf(fpEmpfile,"Name:   \tMonthly Salary:\n");
    for(i=1; i < 2; i++){
        while ((fscanf(fpDailypay,"%s %f", nameEmp, &paymentDay)) == 2)
        {
        fscanf(fpDaysworked,"%f", &daysWorked);
        monthlySalary = daysWorked * paymentDay;
        salary = monthlySalary;

        if (salary == 0){
            sssReduc = 0;
            pagibigReduc = 0;
            taxReduc = 0;
        }
        else if (salary < 20000 && salary > 0){
            sssReduc = 0.01;
            pagibigReduc = 200;
            taxReduc = 0;
        }
        else if (salary >= 20000 && salary < 30000){
            sssReduc = 0.02;
            pagibigReduc = 200;
            taxReduc = 0.05;
        }
        else if (salary >= 30000 && salary < 40000){
            sssReduc = 0.03;
            pagibigReduc = 200;
            taxReduc = 0.07;
        }
        else if (salary >= 40000){
            sssReduc = 0.05;
            pagibigReduc = 200;
            taxReduc = 0.09;
        }
        else{
            printf("Error, please try again.");
            exit (100);
        }

        reducedSSSAmount = salary * sssReduc;
        reducedTaxamount = salary * taxReduc;
        netPay = salary - (reducedSSSAmount + pagibigReduc + reducedTaxamount);
        totalAmount += netPay;
        fprintf(fpReduction,"%s      \t%.2f       \t%.2f       \t%.2f       \t%.2f\n\n", nameEmp, reducedSSSAmount, pagibigReduc, reducedTaxamount, netPay);
        fprintf(fpEmpfile, "%s      \t%.2f\n\n", nameEmp, netPay);
        }
    }
    fprintf(fpReduction, "Total:     \t\t\t\t\t\t\t%.2f\n", totalAmount);
    fprintf(fpEmpfile, "Total:     \t%.2f\n", totalAmount);
    fclose(fpReduction);
    fclose(fpDailypay);
    fclose(fpEmpfile);
    fclose(fpDaysworked);
}

void displayRecords()
{
    FILE *fpDisempfile = fopen("Employee File.DAT", "r");
    FILE *fpDispayroll = fopen("GeneralPayroll.DAT", "r");
    FILE *fpMonth = fopen("whatMonth.DAT", "r");

    int ch, loop;
    char monthName [20];
    char decision;

    fscanf(fpMonth, "%s", monthName);
    strupr(monthName);
    do{
    printf("Which of the following records would you like to see?\n\n");
    printf("[1] Employee Records\n[2] General Payroll Records\n[3] Return to Main Menu\n\n");
    printf ("Your choice: ");
    decision = getche();

    switch (decision)
    {
        case '1':

            system ("cls");
            titleHeader();
            if (!fpMonth)
            {
                printf("\nEMPLOYEE RECORDS FOR THE MONTH:   , 2020\n");
                printf("=============================================\n\n");
            }
            else
            {
                printf("\nEMPLOYEE RECORDS FOR THE MONTH: %s, 2020\n", monthName);
                printf("=============================================\n\n");
            }


            if (!fpDisempfile)
            {
                noRecordsdisplay();
            }

            do{
                ch = getc(fpDisempfile);
                putchar(ch);
            }while (ch != EOF);

            loop = 0;
            break;

        case '2':
            system ("cls");

            titleHeader();
            if (!fpMonth)
            {
                printf("\nFOR THE MONTH:   , 2020\n");
                printf("=============================\n\n");
            }
            else
            {
                printf("\nFOR THE MONTH: %s, 2020\n", monthName);
                printf("=============================\n\n");
            }

            if (!fpDispayroll){
                noRecordsdisplay();
            }

            do{
                ch = getc(fpDispayroll);
                putchar(ch);
            }while (ch != EOF);

            loop = 0;
            break;

        case '3':
            system("cls");
            main();
            loop = 0;
            break;

        default:
            system ("cls");
            printf("Invalid Choice. Please Try Again.\n\n");
            loop = 1;
            system ("pause");
            system ("cls");
            break;
    }
    }while (loop == 1);

    fclose(fpDisempfile);
    fclose(fpDispayroll);
    fclose(fpMonth);
}

void eraseRecords()
{
    int loop, erase, erase2, erase3, erase4;
    char decision;
    loop = 1;
    do{
    printf("Are you sure you want to delete the records? \n\n[1] YES\n[2] NO\n\n");
    printf ("Your choice: ");
    decision = getche();
    printf("\n\n");

    switch (decision)
    {
        case '1':
            erase = remove ("GeneralPayroll.DAT");
            erase2 = remove ("whatMonth.DAT");
            erase3 = remove ("Employee File.DAT");
            erase4 = remove ("DaysWorked.DAT");
            if (erase == 0 && erase2 == 0 && erase3 == 0 && erase4 == 0)
                printf("The file is deleted successfully.\n\n");
            else
                printf("Records are already deleted.\n\n");
            loop = 0;
            system("pause");
            break;

        case '2':
            printf("Deletion cancelled.\n\n");
            loop = 0;
            system ("pause");
            system ("cls");
            break;
        default:
            system ("cls");
            printf("Invalid Choice. Please Try Again.\n\n");
            loop = 1;
            system ("pause");
            system ("cls");
            break;
    }
    }while (loop == 1);
}

void aboutCreator()
{
    FILE *fpDisplay = fopen("Aboutcreator.DAT", "r");
    int ch;
    do{
        ch = getc(fpDisplay);
        putchar(ch);
    }while (ch != EOF);

    fclose(fpDisplay);
}

void titleHeader()
{
    printf("\t\t\t\t **********************************\n");
    printf("\t\t\t\t *  G E N E R A L  P A Y R O L L  *\n");
    printf("\t\t\t\t **********************************\n");
}

void noRecordsdisplay()
{
    printf("\t\t\t\t      ************************\n");
    printf("\t\t\t\t      **  NO RECORDS SAVED  **\n");
    printf("\t\t\t\t      ************************\n\n\n");
}

