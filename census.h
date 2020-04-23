#ifndef CENSUS_H_INCLUDED
#define CENSUS_H_INCLUDED
struct Census {
    char firstName[100];
    char lastName[100];
    char fullName[200];
    char gender;
    int month;
    int year;
    int income;

};
struct Census censusArr[100];
struct Census *cPtr;
FILE *fPtr;

int readFile(FILE *fPtr);

int findLines(FILE *fPtr);

int countAdults(FILE *fPtr);

int ratioCalc(FILE *fPtr);

int averageIncome(FILE *fPtr);

void scanAndPrint(FILE *fPtr);


#endif // CENSUS_H_INCLUDED
