/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_16.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

//#include "std_testcase.h"

//#include <wchar.h>

//#ifndef OMITBAD
//#include <time.h>

fn printLine(line:#own())-> #voidTy{
    line; @{   //if statement
        line;   //printf arguments
    };
};
fn CWE415_Double_Free__malloc_free_int_16_bad()-> #voidTy{
    decl data;
    /* Initialize data */
    // transfer bot data;
    ! {   //while statement
        transfer newResource() data;      //malloc function
        /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
        deallocate data;      // free function
        
    };
    ! {   //while statement
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        deallocate data;      // free function
        
    };
};

//#endif /* OMITBAD */

//#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the sinks in the second while statement */
fn goodB2G()-> #voidTy{
    decl data;
    /* Initialize data */
    // transfer bot data;
    ! {   //while statement
        transfer newResource() data;      //malloc function
        /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
        deallocate data;      // free function
        
    };
    ! {   //while statement
        /* do nothing */
        /* FIX: Don't attempt to free the memory */
//        ; /* empty statement needed for some flow variants */
        
    };
};

/* goodG2B() - use goodsource and badsink by changing the sources in the first while statement */
fn goodG2B()-> #voidTy{
    decl data;
    /* Initialize data */
    // transfer bot data;
    ! {   //while statement
        transfer newResource() data;      //malloc function
        /* FIX: Do NOT free data in the source - the bad sink frees data */
        
    };
    ! {   //while statement
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        deallocate data;      // free function
        
    };
};

fn CWE415_Double_Free__malloc_free_int_16_good()-> #voidTy{
    call goodB2G();
    call goodG2B();
};

//#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its #own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

//#ifdef INCLUDEMAIN

fn main(argc:#own(copy), argv:#own()) -> #own(copy){
    /* seed randomness */
 //   srand( (unsigned)time(NULL) );
//#ifndef OMITGOOD
    //call printLine("Calling good()...");
    call CWE415_Double_Free__malloc_free_int_16_good();
    //call printLine("Finished good()");
//#endif /* OMITGOOD */
//#ifndef OMITBAD
    //call printLine("Calling bad()...");
    call CWE415_Double_Free__malloc_free_int_16_bad();
    //call printLine("Finished bad()");
//#endif /* OMITBAD */
    val(newResource(copy))    // return value
};

decl arg1;
decl argv1;

transfer newResource(copy) arg1;
transfer newResource() argv1;

call main(arg1, argv1) ;
//#endif
