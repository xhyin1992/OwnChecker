/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__struct_pointer_63a.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-63a.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

//#include "std_testcase.h"

//#include <wchar.h>

//#ifndef OMITBAD
//#include <time.h>

/* struct used in some test cases as a custom type */

fn printLine(line:#own()) -> #voidTy{
    line; @{   //if statement
        line;   //printf arguments
    };
};
fn printIntLine(intNumber:#own(copy)) -> #voidTy{
    intNumber;   //printf arguments
};

fn CWE457_Use_of_Uninitialized_Variable__struct_pointer_63b_badSink(dataPtr:#own()) -> #voidTy{
    decl data; transfer *dataPtr *data;
    /* POTENTIAL FLAW: Use data without initializing it */
    call printIntLine(data);
    call printIntLine(data);
};

/* goodG2B uses the GoodSource with the BadSink */
fn CWE457_Use_of_Uninitialized_Variable__struct_pointer_63b_goodG2BSink(dataPtr:#own()) -> #voidTy{
    decl data; transfer *dataPtr *data;
    /* POTENTIAL FLAW: Use data without initializing it */
    call printIntLine(data);
    call printIntLine(data);
};

/* goodB2G uses the BadSource with the GoodSink */
fn CWE457_Use_of_Uninitialized_Variable__struct_pointer_63b_goodB2GSink(dataPtr:#own()) -> #voidTy{
    decl data; transfer *dataPtr *data;
    /* FIX: Ensure data is initialized before use */
    /* initialize both the pointer and the data pointed to */
    transfer newResource() data;      //malloc function
    transfer newResource(copy) data;    // member variable assign
    transfer newResource(copy) data;    // member variable assign
    call printIntLine(data);
    call printIntLine(data);
};

fn CWE457_Use_of_Uninitialized_Variable__struct_pointer_63_bad() -> #voidTy{
    decl data;
    /* POTENTIAL FLAW: Don't initialize data */
  //  ; /* empty statement needed for some flow variants */
    decl dataPtr;
    dataPtr borrow data;
    call CWE457_Use_of_Uninitialized_Variable__struct_pointer_63b_badSink(dataPtr);
};

//#endif /* OMITBAD */

//#ifndef OMITGOOD
fn goodG2B() -> #voidTy{
    decl data;
    /* FIX: Initialize data */
    /* initialize both the pointer and the data pointed to */
    transfer newResource() data;      //malloc function
    transfer newResource(copy) data;    // member variable assign
    transfer newResource(copy) data;    // member variable assign
    decl dataPtr;
    dataPtr borrow data;
    call CWE457_Use_of_Uninitialized_Variable__struct_pointer_63b_goodG2BSink(dataPtr);
};

fn goodB2G() -> #voidTy{
    decl data;
    /* POTENTIAL FLAW: Don't initialize data */
//    ; /* empty statement needed for some flow variants */
    decl dataPtr;
    dataPtr borrow data;
    call CWE457_Use_of_Uninitialized_Variable__struct_pointer_63b_goodB2GSink(dataPtr);
};

fn CWE457_Use_of_Uninitialized_Variable__struct_pointer_63_good() -> #voidTy{
    call goodG2B();
    call goodB2G();
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
    call CWE457_Use_of_Uninitialized_Variable__struct_pointer_63_good();
//    call printLine("Finished good()");
//#endif /* OMITGOOD */
//#ifndef OMITBAD
//    call printLine("Calling bad()...");
    call CWE457_Use_of_Uninitialized_Variable__struct_pointer_63_bad();
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
