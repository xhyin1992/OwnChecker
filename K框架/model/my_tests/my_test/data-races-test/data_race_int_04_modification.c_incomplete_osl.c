/* 
Filename: Data_Race_04.c
*/
/*
 * @description
 * Two variables borrow the same variable and at least one writing 
 * operation on variable through reference, that is one reference is mutable.
 * Flow Variant: 02 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

//#include <stdio.h>
//#include <stdlib.h>

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
decl STATIC_CONST_TRUE; transfer newResource(copy) STATIC_CONST_TRUE; /* true */
decl STATIC_CONST_FALSE; transfer newResource(copy) STATIC_CONST_FALSE; /* false */

fn Data_Race_04_bad() -> #voidTy{
    decl data1;
decl data2;

    decl share_var; transfer newResource(copy) share_var;
    STATIC_CONST_TRUE; @{   //if statement
      data1 mborrow share_var;
      data2 borrow share_var;
    };
    /* POTENTIAL FLAW: potential data race will happen because 
     * both variables data1 and data2 borrow the variable share_var, 
     * but the variable data1 mutably borrows the variable share_var, 
     * since there is a writing operation through data1 with *data1 = 10; 
     */
    STATIC_CONST_TRUE; @{   //if statement
        transfer newResource(copy) *data1;
    };
};

fn Data_Race_04_good() -> #voidTy{
    decl data1;
decl data2;

    decl share_var; transfer newResource(copy) share_var;
    STATIC_CONST_TRUE; @{   //if statement
      data1 mborrow share_var;
      data2 borrow share_var;
    };
    STATIC_CONST_FALSE; @{   //if statement   /* the code below will never run*/
        
    }
     , {
      *data1;   //printf arguments
      *data2;   //printf arguments
    };
};

fn main(argc:#own(copy), argv:#own()) -> #own(copy){
    
    call Data_Race_04_good();
    
    
    call Data_Race_04_bad();
    
    val(newResource(copy))    // return value
};
decl arg1;
decl argv1;
 
transfer newResource(copy) arg1;
transfer newResource() argv1;
 
call main(arg1, argv1);

