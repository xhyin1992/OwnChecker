/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_05.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c_array.label.xml
Template File: sources-sinks-05.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

//#include "std_testcase.h"
//#include <time.h>
/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
decl staticTrue:#own(copy); transfer newResource(copy) staticTrue; /* true */
decl staticFalse:#own(copy); transfer newResource(copy) staticFalse; /* false */

fn printLine(line:#own()) -> #voidTy{
    line; @{   //if statement
        line;   //printf arguments
    };
};
fn printIntLine(intNumber:#own(copy)) -> #voidTy{
    intNumber;   //printf arguments
};
//#ifndef OMITBAD

fn CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_05_bad() -> #voidTy{
    decl data;
    transfer newResource() data;      //malloc function
    staticTrue; @{   //if statement
        /* POTENTIAL FLAW: Don't initialize data */
    //    ; /* empty statement needed for some flow variants */
    };
    staticTrue; @{   //if statement
        /* POTENTIAL FLAW: Use data without initializing it */
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                call printIntLine(data);
            i; transfer i newResource(copy);
            };
        }
    };
};

//#endif /* OMITBAD */

//#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second staticTrue to staticFalse */
fn goodB2G1() -> #voidTy{
    decl data;
    transfer newResource() data;      //malloc function
    staticTrue; @{   //if statement
        /* POTENTIAL FLAW: Don't initialize data */
    //    ; /* empty statement needed for some flow variants */
    };
    staticFalse; @{   //if statement
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
     //   call printLine("Benign, fixed string");
    }
     , {
        /* FIX: Ensure data is initialized before use */
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                transfer i data;     // array element assignment
            i; transfer i newResource(copy);
            };
        }
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                call printIntLine(data);
            i; transfer i newResource(copy);
            };
        }
    };
};

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
fn goodB2G2() -> #voidTy{
    decl data;
    transfer newResource() data;      //malloc function
    staticTrue; @{   //if statement
        /* POTENTIAL FLAW: Don't initialize data */
    //    ; /* empty statement needed for some flow variants */
    };
    staticTrue; @{   //if statement
        /* FIX: Ensure data is initialized before use */
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                transfer i data;     // array element assignment
            i; transfer i newResource(copy);
            };
        }
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                call printIntLine(data);
            i; transfer i newResource(copy);
            };
        }
    };
};

/* goodG2B1() - use goodsource and badsink by changing the first staticTrue to staticFalse */
fn goodG2B1() -> #voidTy{
    decl data;
    transfer newResource() data;      //malloc function
    staticFalse; @{   //if statement
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    //    call printLine("Benign, fixed string");
    }
     , {
        /* FIX: Completely initialize data */
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                transfer i data;     // array element assignment
            i; transfer i newResource(copy);
            };
        }
    };
    staticTrue; @{   //if statement
        /* POTENTIAL FLAW: Use data without initializing it */
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                call printIntLine(data);
            i; transfer i newResource(copy);
            };
        }
    };
};

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
fn goodG2B2() -> #voidTy{
    decl data;
    transfer newResource() data;      //malloc function
    staticTrue; @{   //if statement
        /* FIX: Completely initialize data */
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                transfer i data;     // array element assignment
            i; transfer i newResource(copy);
            };
        }
    };
    staticTrue; @{   //if statement
        /* POTENTIAL FLAW: Use data without initializing it */
        {
            decl i:#own(copy);
            transfer newResource(copy) i;
i; !{   //for statement
                call printIntLine(data);
            i; transfer i newResource(copy);
            };
        }
    };
};

fn CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_05_good() -> #voidTy{
    call goodB2G1();
    call goodB2G2();
    call goodG2B1();
    call goodG2B2();
};

//#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its #own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

//#ifdef INCLUDEMAIN

fn main(argc:#own(copy), argv:#own()) -> #own(copy){
    /* seed randomness */
    //srand( (unsigned)time(NULL) );
//#ifndef OMITGOOD
//    call printLine("Calling good()...");
    call CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_05_good();
 //   call printLine("Finished good()");
//#endif /* OMITGOOD */
//#ifndef OMITBAD
//    call printLine("Calling bad()...");
    call CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_05_bad();
//    call printLine("Finished bad()");
//#endif /* OMITBAD */
    val(newResource(copy))    // return value
};

decl arg1;
decl argv1;

transfer newResource(copy) arg1;
transfer newResource() argv1;

call main(arg1, argv1) ;
//#endif
