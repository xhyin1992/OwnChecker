/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__int_12.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

//#include "std_testcase.h"

//#include <wchar.h>

#ifndef OMITBAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* The two functions always return 1 or 0, so a tool should be able to 
   identify that uses of these functions will always return these values */
int globalReturnsTrueOrFalse() 
{
    int a = rand();
	int b = a % 2;
	return b;
}

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

void CWE457_Use_of_Uninitialized_Variable__int_12_bad()
{
    int data;
    if(globalReturnsTrueOrFalse()){
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else{
        /* FIX: Initialize data */
        data = 5;
    }
    if(globalReturnsTrueOrFalse()){
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data);
    }
    else{
        /* FIX: Ensure data is initialized before use */
        data = 5;
        printIntLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    int data;
    if(globalReturnsTrueOrFalse()){
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else{
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(globalReturnsTrueOrFalse()){
        /* FIX: Ensure data is initialized before use */
        data = 5;
        printIntLine(data);
    }
    else{
        /* FIX: Ensure data is initialized before use */
        data = 5;
        printIntLine(data);
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    int data;
    if(globalReturnsTrueOrFalse()){
        /* FIX: Initialize data */
        data = 5;
    }
    else{
        /* FIX: Initialize data */
        data = 5;
    }
    if(globalReturnsTrueOrFalse()){
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data);
    }
    else{
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__int_12_good()
{
    goodB2G();
    goodG2B();
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
    CWE457_Use_of_Uninitialized_Variable__int_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__int_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
