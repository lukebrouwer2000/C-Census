#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "census.h"

int main(){
    int lines = findLines(fPtr);
    readFile(fPtr);


    printf("Number of adults: %d\nNumber of children: %d\n", countAdults(fPtr), lines+1-countAdults(fPtr));
    printf("Ratio of men to women: %d : %d\n", ratioCalc(fPtr), lines+1-ratioCalc(fPtr));
    printf("The average income of all individuals in the census is: $%d\n", averageIncome(fPtr));

}


int readFile(FILE *fPtr){
    int i;
    char fileName[100];

    int lines = findLines(fPtr);

    //printf("Enter file name to open: \n");
    //scanf("%s", fileName);

    // set ptr to first element
    cPtr = &censusArr[0];

    if ((fPtr = fopen("Final-Q2.txt", "r"))){

        scanAndPrint(fPtr);




        fclose(fPtr);
        return 0;
    }

    else {
        printf("File not found. Exiting now.");
        return 0;
    }

}

int findLines(FILE *fPtr){
    cPtr = &censusArr[0];
    char l;
    int lines = 0;
    if ((fPtr = fopen("Final-Q2.txt", "r"))){



        for (l = getc(fPtr); l != EOF; l = getc(fPtr)){
            if (l == '\n'){
                lines++;
            }
        }

    return lines;
    }
}

int countAdults(FILE *fPtr){
    //cPtr = &censusArr[0];
    int lines = findLines(fPtr);

    int adult = 0;
    for (int i = 0; i < lines+1; i++){
            if (cPtr->year <= 1999){
                adult++;
                cPtr++;

            }
            else {

                cPtr++;
            }
        }
    return adult;
}

int ratioCalc(FILE *fPtr){
    //cPtr = &censusArr[0];
    int i;
    int male = 0;
    int lines = findLines(fPtr);
    // ratio of men to women
    cPtr = &censusArr[0];
    for (i = 0; i < lines+1; i++){
        if (cPtr->gender == 'M'){
            male++;
            cPtr++;
        }
        else {

            cPtr++;
        }
    }
    return male;
}

int averageIncome(FILE *fPtr){
    //cPtr = &censusArr[0];
    int i;
    int lines = findLines(fPtr);
    int average = 0;
    // average income
    float sum = 0;
    //cPtr = &censusArr[0];
    for (i = 0; i < lines+1; i++){
        sum += cPtr->income;
        cPtr++;
    }
    average = sum / (lines+1);

    return average;
}

void scanAndPrint(FILE *fPtr){
    int i;
    int lines = findLines(fPtr);
    printf("---------------FILE INFORMATION---------------\n\n");
    for (i = 0; i < lines+1; i++){

        fscanf(fPtr, "%s", cPtr->firstName);
        printf("%s ", cPtr->firstName);
        fscanf(fPtr, "%s", cPtr->lastName);
        printf("%s ", cPtr->lastName);
        fscanf(fPtr, " %c", &cPtr->gender);
        printf("%c ", cPtr->gender);
        fscanf(fPtr, "%d/%d", &cPtr->month, &cPtr->year);
        printf("%d/%d ", cPtr->month, cPtr->year);
        fscanf(fPtr, "%d", &cPtr->income);
        printf("$%d", cPtr->income);
        printf("\n");


        cPtr++;
    }
    printf("\n---------------END FILE INFORMATION---------------\n\n");

}
