/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_struct_64a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

//#include "std_testcase.h"

//#include <wchar.h>

#ifndef OMITBAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
/* bad function declaration */
void CWE415_Double_Free__malloc_free_struct_64b_badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    twoIntsStruct * * dataPtr = (twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    twoIntsStruct * data = (*dataPtr);
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_struct_64b_goodG2BSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    twoIntsStruct * * dataPtr = (twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    twoIntsStruct * data = (*dataPtr);
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_struct_64b_goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    twoIntsStruct * * dataPtr = (twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    twoIntsStruct * data = (*dataPtr);
    /* do nothing */
    /* FIX: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

void CWE415_Double_Free__malloc_free_struct_64_bad()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    CWE415_Double_Free__malloc_free_struct_64b_badSink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void goodG2B()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    /* FIX: Do NOT free data in the source - the bad sink frees data */
    CWE415_Double_Free__malloc_free_struct_64b_goodG2BSink(&data);
}

static void goodB2G()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    CWE415_Double_Free__malloc_free_struct_64b_goodB2GSink(&data);
}

void CWE415_Double_Free__malloc_free_struct_64_good()
{
    goodG2B();
    goodB2G();
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
    CWE415_Double_Free__malloc_free_struct_64_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_struct_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
