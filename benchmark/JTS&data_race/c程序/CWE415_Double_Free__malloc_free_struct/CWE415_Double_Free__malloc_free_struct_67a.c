/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_struct_67a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

//#include "std_testcase.h"

//#include <wchar.h>
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

typedef struct _CWE415_Double_Free__malloc_free_struct_67_structType
{
    twoIntsStruct * structFirst;
} CWE415_Double_Free__malloc_free_struct_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE415_Double_Free__malloc_free_struct_67b_badSink(CWE415_Double_Free__malloc_free_struct_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_struct_67b_goodG2BSink(CWE415_Double_Free__malloc_free_struct_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_struct_67b_goodB2GSink(CWE415_Double_Free__malloc_free_struct_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    /* do nothing */
    /* FIX: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

void CWE415_Double_Free__malloc_free_struct_67_bad()
{
    twoIntsStruct * data;
    CWE415_Double_Free__malloc_free_struct_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_struct_67b_badSink(myStruct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_struct_67b_goodG2BSink(CWE415_Double_Free__malloc_free_struct_67_structType myStruct);

static void goodG2B()
{
    twoIntsStruct * data;
    CWE415_Double_Free__malloc_free_struct_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    /* FIX: Do NOT free data in the source - the bad sink frees data */
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_struct_67b_goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_struct_67b_goodB2GSink(CWE415_Double_Free__malloc_free_struct_67_structType myStruct);

static void goodB2G()
{
    twoIntsStruct * data;
    CWE415_Double_Free__malloc_free_struct_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_struct_67b_goodB2GSink(myStruct);
}

void CWE415_Double_Free__malloc_free_struct_67_good()
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
    CWE415_Double_Free__malloc_free_struct_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_struct_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
