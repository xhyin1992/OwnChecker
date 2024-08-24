/* The variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
decl globalFive; transfer newResource(copy) globalFive; 

fn printLine(line:#own()) -> #voidTy{
    line; @{   //if statement
        line;   //printf arguments
    },{};
};

/*fn printIntLine(intNumber:#own(copy)) -> #voidTy{
    intNumber;   //printf arguments
};*/

fn CWE457_Use_of_Uninitialized_Variable__int_14_bad() -> #voidTy{
    decl data;
    //globalFive; 
    @{   //if statement
        /* POTENTIAL FLAW: Don't initialize data */
     //   ; /* empty statement needed for some flow variants */
    },{};
    //globalFive; 
    @{   //if statement
        /* POTENTIAL FLAW: Use data without initializing it */
        //call printIntLine(data);
        data;
    },{};
};

//#endif /* OMITBAD */

//#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second globalFive==5 to globalFive!=5 */
fn goodB2G1() -> #voidTy{
    decl data;
    //globalFive; 
    @{   //if statement
        /* POTENTIAL FLAW: Don't initialize data */
    //    ; /* empty statement needed for some flow variants */
    },{};
    //globalFive; 
    @{   //if statement
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        call printLine(newResource(copy));
    }
     , {
        /* FIX: Ensure data is initialized before use */
        transfer newResource(copy) data;
        //call printIntLine(data);
        data;
    };
};

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
fn goodB2G2() -> #voidTy{
    decl data;
    //globalFive; 
    @{   //if statement
        /* POTENTIAL FLAW: Don't initialize data */
    //    ; /* empty statement needed for some flow variants */
    },{};
    //globalFive; 
    @{   //if statement
        /* FIX: Ensure data is initialized before use */
        transfer newResource(copy) data;
        //call printIntLine(data);
        data;
    },{};
};

/* goodG2B1() - use goodsource and badsink by changing the first globalFive==5 to globalFive!=5 */
fn goodG2B1() -> #voidTy{
    decl data;
    //globalFive; 
    @{   //if statement
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        call printLine(newResource(copy));
    }
     , {
        /* FIX: Initialize data */
        transfer newResource(copy) data;
    };
    //globalFive; 
    @{   //if statement
        /* POTENTIAL FLAW: Use data without initializing it */
        //call printIntLine(data);
        data;
    },{};
};

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
fn goodG2B2() -> #voidTy{
    decl data;
    //globalFive; 
    @{   //if statement
        /* FIX: Initialize data */
        transfer newResource(copy) data;
    },{};
    //globalFive; 
    @{   //if statement
        /* POTENTIAL FLAW: Use data without initializing it */
        //call printIntLine(data);
        data;
    },{};
};

fn CWE457_Use_of_Uninitialized_Variable__int_14_good() -> #voidTy{
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
    ////srand( (unsigned)time(NULL) );
//#ifndef OMITGOOD
    //call printLine(newResource(copy));
    call CWE457_Use_of_Uninitialized_Variable__int_14_good();
    //call printLine(newResource(copy));
//#endif /* OMITGOOD */
//#ifndef OMITBAD
    //call printLine(newResource(copy));
    call CWE457_Use_of_Uninitialized_Variable__int_14_bad();
    //call printLine(newResource(copy));
//#endif /* OMITBAD */
    val(newResource(copy))    // return value
};

decl arg1;
decl argv1;

transfer newResource(copy) arg1;
transfer newResource() argv1;

call main(arg1, argv1) ;
//#endif
