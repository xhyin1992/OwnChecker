/* 
Filename: Data_Race_09.c
*/
/*
 * @description
 * Two variables borrow the same variable and at least one writing 
 * operation on variable through reference, that is one reference is mutable.
 * Flow Variant: 02 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */



decl GLOBAL_CONST_TRUE; transfer newResource(copy) GLOBAL_CONST_TRUE; /* true */
decl GLOBAL_CONST_FALSE; transfer newResource(copy) GLOBAL_CONST_FALSE; /* false */

fn Data_Race_09_bad() ->#voidTy{
    decl data1;
decl data2;

    decl share_var; transfer newResource(copy) share_var;
    transfer #uninit data1;
    transfer #uninit data2;
    GLOBAL_CONST_TRUE; @{   //if statement
      data1 mborrow share_var;
      data2 borrow share_var;
    };
    /* POTENTIAL FLAW: potential data race will happen because 
     * both variables data1 and data2 borrow the variable share_var, 
     * but the variable data1 mutably borrows the variable share_var, 
     * since there is a writing operation through data1 with *data1 = 10; 
     */
    GLOBAL_CONST_TRUE; @{   //if statement
        transfer newResource(copy) *data1;
    };
};

fn Data_Race_09_good() ->#voidTy{
    decl data3;
decl data4;

    decl share_var; transfer newResource(copy) share_var;
    transfer #uninit data3;
    transfer #uninit data4;
    GLOBAL_CONST_TRUE; @{   //if statement
      data3 mborrow share_var;
      data4 borrow share_var;
    };
    GLOBAL_CONST_FALSE; @{   //if statement   /* the code below will never run*/
        transfer newResource(copy) *data3;
    }
     , {
      *data3;   //printf arguments
      *data4;   //printf arguments
    };
};

fn main(argc:#own(copy), argv:#own()) -> #own(copy){
    
    call Data_Race_09_good();
    
    
    call Data_Race_09_bad();
    
    val(newResource(copy))    // return value
};

decl arg1;
decl argv1;

transfer newResource(copy) arg1;
transfer newResource() argv1;

call main(arg1, argv1) ;