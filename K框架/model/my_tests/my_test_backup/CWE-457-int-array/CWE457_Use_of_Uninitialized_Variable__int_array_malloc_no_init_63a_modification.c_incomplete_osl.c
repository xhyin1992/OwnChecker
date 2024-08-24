fn printLine(line:#own()) -> #voidTy{
    line; @{   //if statement
        line;   //printf arguments
    };
};
fn printIntLine(intNumber:#own(copy)) -> #voidTy{
    intNumber;   //printf arguments
};

fn CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63b_badSink(dataPtr:#own()) -> #voidTy{
    decl data; transfer *dataPtr *data;
    /* POTENTIAL FLAW: Use data without initializing it */
    {
        decl i;
        transfer newResource(copy) i;
i; !{   //for statement
            call printIntLine(data);
        i; transfer i newResource(copy);
        };
    }
};

/* goodG2B uses the GoodSource with the BadSink */
fn CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63b_goodG2BSink(dataPtr:#own()) -> #voidTy{
    decl data; transfer *dataPtr *data;
    /* POTENTIAL FLAW: Use data without initializing it */
    {
        decl i;
        transfer newResource(copy) i;
i; !{   //for statement
            call printIntLine(data);
        i; transfer i newResource(copy);
        };
    }
};

/* goodB2G uses the BadSource with the GoodSink */
fn CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63b_goodB2GSink(dataPtr:#own()) -> #voidTy{
    decl data; transfer *dataPtr *data;
    /* FIX: Ensure data is initialized before use */
    {
        decl i;
        transfer newResource(copy) i;
i; !{   //for statement
            transfer newResource(copy) data;     // array element assignment
        i; transfer i newResource(copy);
        };
    }
    {
        decl i;
        transfer newResource(copy) i;
i; !{   //for statement
            call printIntLine(data);
        i; transfer i newResource(copy);
        };
    }
};

fn CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63_bad() -> #voidTy{
    decl data;
    transfer newResource() data;      //malloc function
    /* POTENTIAL FLAW: Don't initialize data */
 //   ; /* empty statement needed for some flow variants */
    call CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63b_badSink(data);
};

//#endif /* OMITBAD */

//#ifndef OMITGOOD
fn goodG2B() -> #voidTy{
    decl data;
    transfer newResource() data;      //malloc function
    /* FIX: Completely initialize data */
    {
        decl i;
        transfer newResource(copy) i;
i; !{   //for statement
            transfer newResource(copy) data;     // array element assignment
        i; transfer i newResource(copy);
        };
    }
    call CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63b_goodG2BSink(data);
};

fn goodB2G() -> #voidTy{
    decl data;
    transfer newResource() data;      //malloc function
    /* POTENTIAL FLAW: Don't initialize data */
//    ; /* empty statement needed for some flow variants */
    call CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63b_goodB2GSink(data);
};

fn CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63_good() -> #voidTy{
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
    call printLine(newResource(copy));
    call CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63_good();
    call printLine(newResource(copy));
//#endif /* OMITGOOD */
//#ifndef OMITBAD
    call printLine(newResource(copy));
    call CWE457_Use_of_Uninitialized_Variable__int_array_malloc_no_init_63_bad();
    call printLine(newResource(copy));
//#endif /* OMITBAD */
    val(newResource(copy))    // return value
};

decl arg1;
decl argv1;

transfer newResource(copy) arg1;
transfer newResource() argv1;

call main(arg1, argv1) ;
//#endif
