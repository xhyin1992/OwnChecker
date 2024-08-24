/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__struct_pointer_15.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

//#include "std_testcase.h"

//#include <wchar.h>

#ifndef OMITBAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* struct used in some test cases as a custom type */
typedef struct _twoIntsStruct
{
    int intOne;
    int intTwo;
} twoIntsStruct;

void printLine (const char * line)
{
    if(line != NULL) 
    {
        printf("%s\n", line);
    }
}
void printIntLine (int intNumber)
{
    printf("%d\n", intNumber);
}

void CWE457_Use_of_Uninitialized_Variable__struct_pointer_15_bad()
{
    twoIntsStruct * data;
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
        break;
	
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
        break;
	
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    twoIntsStruct * data;
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
        break;
	
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    default:
        /* FIX: Ensure data is initialized before use */
        /* initialize both the pointer and the data pointed to */
        data = (twoIntsStruct *)malloc(sizeof(twoIntsStruct));
        data->intOne = 5;
        data->intTwo = 6;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
        break;
	
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    twoIntsStruct * data;
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
        break;
	
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    }
    switch(7)
    {
    case 7:
        /* FIX: Ensure data is initialized before use */
        /* initialize both the pointer and the data pointed to */
        data = (twoIntsStruct *)malloc(sizeof(twoIntsStruct));
        data->intOne = 5;
        data->intTwo = 6;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
        break;
	
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    twoIntsStruct * data;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    default:
        /* FIX: Initialize data */
        /* initialize both the pointer and the data pointed to */
        data = (twoIntsStruct *)malloc(sizeof(twoIntsStruct));
        data->intOne = 5;
        data->intTwo = 6;
        break;
	
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
        break;
	
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    twoIntsStruct * data;
    switch(6)
    {
    case 6:
        /* FIX: Initialize data */
        /* initialize both the pointer and the data pointed to */
        data = (twoIntsStruct *)malloc(sizeof(twoIntsStruct));
        data->intOne = 5;
        data->intTwo = 6;
        break;
	
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
        break;
	
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
	
    }
}

void CWE457_Use_of_Uninitialized_Variable__struct_pointer_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE457_Use_of_Uninitialized_Variable__struct_pointer_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_pointer_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
