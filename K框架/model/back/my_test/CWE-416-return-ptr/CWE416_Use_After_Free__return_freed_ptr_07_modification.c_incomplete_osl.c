/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__return_freed_ptr_07.c
Label Definition File: CWE416_Use_After_Free__return_freed_ptr.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * Sinks:
 *    GoodSink: Use a block of memory returned from a function
 *    BadSink : Use a block of memory returned from a function after it has been freed
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

//#include "std_testcase.h"
//#include <time.h>

fn printLine(line:#own()) -> #voidTy{
    line; @{   //if statement
        line;   //printf arguments
    };
};

fn helperBad(aString:#own()) -> #own(){
    decl i:#own(copy); transfer newResource(copy) i;
    decl j:#own(copy);
    decl reversedString; transfer bot reversedString;
    aString; @{   //if statement
        call strlen(aString); transfer newResource(copy) i;
        transfer newResource() reversedString;      //malloc function
        transfer newResource(copy) j;
j; i; !{   //for statement
            transfer aString reversedString;
        j; transfer j newResource(copy);
        };
        transfer newResource() reversedString;      // array element assignment
        /* FLAW: Freeing a memory block and then returning a pointer to the freed memory */
        deallocate reversedString;      // free function
        reversedString; val(newResource())     // return value
    }
     , {
        
    };
};

fn helperGood(aString:#own()) -> #own(){
    decl i:#own(copy); transfer newResource(copy) i;
    decl j:#own(copy);
    decl reversedString; transfer bot reversedString;
    aString; @{   //if statement
        call strlen(aString); transfer newResource(copy) i;
        transfer newResource() reversedstring;      //malloc function
        transfer newResource(copy) j;
j; i; !{   //for statement
            transfer aString reversedString;
        j; transfer j newResource(copy);
        };
        transfer newResource() reversedstring;      // array element assignment
        /* FIX: Do not free the memory before returning */
        reversedString; val(newResource())     // return value
    }
     , {
        
    };
};

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
decl staticFive:#own(copy); transfer newResource(copy) staticFive;

//#ifndef OMITBAD

fn CWE416_Use_After_Free__return_freed_ptr_07_bad() -> #voidTy{
    staticFive; @{   //if statement
        {
            /* Call the bad helper function */
            decl reversedString; 
            //call helperBad("BadSink"); 
            decl aString;
            transfer newResource() aString;
            call helperBad(aString);
            transfer newResource() reversedstring;
            call printLine(reversedString);
            /* free(reversedString);
             * This call to free() was removed because we want the tool to detect the use after free,
             * but we don't want that function to be free(). Essentially we want to avoid a double free
             */
        }
    };
};

//#endif /* OMITBAD */

//#ifndef OMITGOOD

/* good1() uses if(staticFive!=5) instead of if(staticFive==5) */
fn good1() -> #voidTy{
    staticFive; @{   //if statement
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
     //   call printLine("Benign, fixed string");
    }
     , {
        {
            /* Call the good helper function */
            decl reversedString; 
            //call helperGood("GoodSink"); 
            decl aString;
            transfer newResource() aString;
            call helperGood(aString);
            transfer newResource() reversedstring;
            call printLine(reversedString);
            /* free(reversedString);
             * This call to free() was removed because we want the tool to detect the use after free,
             * but we don't want that function to be free(). Essentially we want to avoid a double free
             */
        }
    };
};

/* good2() reverses the bodies in the if statement */
fn good2() -> #voidTy{
    staticFive; @{   //if statement
        {
            /* Call the good helper function */
            decl reversedString; 
            //call helperGood("GoodSink"); 
            decl aString;
            transfer newResource() aString;
            call helperGood(aString);
            transfer newResource() reversedstring;
            call printLine(reversedString);
            /* free(reversedString);
             * This call to free() was removed because we want the tool to detect the use after free,
             * but we don't want that function to be free(). Essentially we want to avoid a double free
             */
        }
    };
};

fn CWE416_Use_After_Free__return_freed_ptr_07_good() -> #voidTy{
    call good1();
    call good2();
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
    call CWE416_Use_After_Free__return_freed_ptr_07_good();
//    call printLine("Finished good()");
//#endif /* OMITGOOD */
//#ifndef OMITBAD
 //   call printLine("Calling bad()...");
    call CWE416_Use_After_Free__return_freed_ptr_07_bad();
 //   call printLine("Finished bad()");
//#endif /* OMITBAD */
    val(newResource(copy))    // return value
};

decl arg1;
decl argv1;

transfer newResource(copy) arg1;
transfer newResource() argv1;

call main(arg1, argv1) ;
//#endif
