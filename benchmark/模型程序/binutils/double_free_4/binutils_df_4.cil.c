/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 29 "../include/common.h"
typedef int bool;
#line 34 "../include/common.h"
typedef void make_cleanup_ftype(void * );
#line 36 "../include/common.h"
struct cleanup {
   struct cleanup *next ;
   void (*function)(void * ) ;
   void (*free_arg)(void * ) ;
   void *arg ;
};
#line 12 "binutils_df_4.c"
typedef int bfd;
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 374 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) rand)(void) ;
#line 376
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) srand)(unsigned int __seed ) ;
#line 466
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 564
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) getenv)(char const   *__name ) ;
#line 31 "../include/common.h"
bool true  =    1;
#line 32 "../include/common.h"
bool false  =    0;
#line 44 "../include/common.h"
static struct cleanup  const  sentinel_cleanup  =    {(struct cleanup *)0, (void (*)(void * ))0, (void (*)(void * ))0, (void *)0};
#line 49 "../include/common.h"
static struct cleanup *cleanup_chain  =    (struct cleanup *)(& sentinel_cleanup);
#line 50 "../include/common.h"
static struct cleanup *final_cleanup_chain  ;
#line 52
void discard_cleanups(struct cleanup *old_chain ) ;
#line 53
void discard_my_cleanups(struct cleanup **pmy_chain , struct cleanup *old_chain ) ;
#line 55
void discard_final_cleanups(struct cleanup *old_chain ) ;
#line 56
static void do_my_cleanups(struct cleanup **pmy_chain , struct cleanup *old_chain ) ;
#line 58
void do_cleanups(struct cleanup *old_chain ) ;
#line 59
static struct cleanup *make_my_cleanup2(struct cleanup **pmy_chain , make_cleanup_ftype *function ,
                                        void *arg , void (*free_arg)(void * ) ) ;
#line 62
static struct cleanup *make_my_cleanup(struct cleanup **pmy_chain , make_cleanup_ftype *function ,
                                       void *arg ) ;
#line 65
struct cleanup *make_cleanup(make_cleanup_ftype *function , void *arg ) ;
#line 68 "../include/common.h"
void discard_cleanups(struct cleanup *old_chain ) 
{ 


  {
#line 71
  discard_my_cleanups(& cleanup_chain, old_chain);
#line 72
  return;
}
}
#line 74 "../include/common.h"
void discard_final_cleanups(struct cleanup *old_chain ) 
{ 


  {
#line 77
  discard_my_cleanups(& final_cleanup_chain, old_chain);
#line 78
  return;
}
}
#line 80 "../include/common.h"
void discard_my_cleanups(struct cleanup **pmy_chain , struct cleanup *old_chain ) 
{ 
  struct cleanup *ptr ;

  {
#line 86
  while (1) {
#line 86
    ptr = *pmy_chain;
#line 86
    if (! ((unsigned long )ptr != (unsigned long )old_chain)) {
#line 86
      break;
    }
#line 88
    *pmy_chain = ptr->next;
#line 89
    if (ptr->free_arg) {
#line 90
      (*(ptr->free_arg))(ptr->arg);
    }
#line 91
    free((void *)ptr);
  }
#line 94
  printf((char const   * __restrict  )"freearg: %x\n", ptr->arg);
#line 95
  return;
}
}
#line 97 "../include/common.h"
static void do_my_cleanups(struct cleanup **pmy_chain , struct cleanup *old_chain ) 
{ 
  struct cleanup *ptr ;

  {
#line 103
  while (1) {
#line 103
    ptr = *pmy_chain;
#line 103
    if (! ((unsigned long )ptr != (unsigned long )old_chain)) {
#line 103
      break;
    }
#line 105
    *pmy_chain = ptr->next;
#line 106
    (*(ptr->function))(ptr->arg);
#line 107
    printf((char const   * __restrict  )"cleanup!!!!! =========\n");
#line 108
    printf((char const   * __restrict  )"%x\n", ptr->arg);
#line 109
    if (ptr->free_arg) {
#line 110
      (*(ptr->free_arg))(ptr->arg);
    }
#line 112
    free((void *)ptr);
  }
#line 114
  return;
}
}
#line 116 "../include/common.h"
void do_cleanups(struct cleanup *old_chain ) 
{ 


  {
#line 118
  do_my_cleanups(& cleanup_chain, old_chain);
#line 119
  return;
}
}
#line 121 "../include/common.h"
static struct cleanup *make_my_cleanup2(struct cleanup **pmy_chain , make_cleanup_ftype *function ,
                                        void *arg , void (*free_arg)(void * ) ) 
{ 
  struct cleanup *new ;
  void *tmp ;
  struct cleanup *old_chain ;

  {
#line 125
  tmp = malloc(sizeof(struct cleanup ));
#line 125
  new = (struct cleanup *)tmp;
#line 127
  old_chain = *pmy_chain;
#line 129
  new->next = *pmy_chain;
#line 130
  new->function = function;
#line 131
  new->free_arg = free_arg;
#line 132
  new->arg = arg;
#line 133
  *pmy_chain = new;
#line 135
  if ((unsigned long )old_chain == (unsigned long )((void *)0)) {
#line 136
    exit(1);
  }
#line 138
  return (old_chain);
}
}
#line 141 "../include/common.h"
static struct cleanup *make_my_cleanup(struct cleanup **pmy_chain , make_cleanup_ftype *function ,
                                       void *arg ) 
{ 
  struct cleanup *tmp ;

  {
#line 145
  tmp = make_my_cleanup2(pmy_chain, function, arg, (void (*)(void * ))((void *)0));
#line 145
  return (tmp);
}
}
#line 148 "../include/common.h"
struct cleanup *make_cleanup(make_cleanup_ftype *function , void *arg ) 
{ 
  struct cleanup *tmp ;

  {
#line 151
  tmp = make_my_cleanup(& cleanup_chain, function, arg);
#line 151
  return (tmp);
}
}
#line 16 "binutils_df_4.c"
extern int ( /* missing proto */  strncmp)() ;
#line 14 "binutils_df_4.c"
int remote_filename_p(char const   *filename ) 
{ 
  int tmp ;

  {
#line 16
  tmp = strncmp(filename, "remote:", 7);
#line 16
  return (tmp == 0);
}
}
#line 25
extern int ( /* missing proto */  strdup)() ;
#line 19 "binutils_df_4.c"
int openp(char const   *path , char const   *name , char **filename_opened ) 
{ 
  int tmp ;
  int tmp___1 ;
  int tmp___2 ;

  {
#line 23
  if (filename_opened) {
#line 25
    tmp = strdup(name);
#line 25
    *filename_opened = (char *)tmp;
  }
#line 28
  tmp___2 = rand();
#line 28
  if (tmp___2 % 2 == 1) {
#line 28
    tmp___1 = 1;
  } else {
#line 28
    tmp___1 = 0;
  }
#line 28
  return (tmp___1);
}
}
#line 32 "binutils_df_4.c"
void error(char const   *msg , char const   *s ) 
{ 


  {
#line 33
  printf((char const   * __restrict  )"%s: %s\n", msg, s);
#line 34
  return;
}
}
#line 36 "binutils_df_4.c"
bfd *gdb_bfd_open(char const   *name ) 
{ 
  bfd *abfd ;
  void *tmp ;
  int tmp___1 ;
  int tmp___2 ;

  {
#line 37
  printf((char const   * __restrict  )"%d\n", *((int *)name));
#line 39
  tmp___2 = rand();
#line 39
  if (tmp___2 % 2 == 1) {
#line 39
    tmp___1 = 1;
  } else {
#line 39
    tmp___1 = 0;
  }
#line 39
  if (tmp___1) {
#line 40
    tmp = malloc(sizeof(bfd ));
#line 40
    abfd = (bfd *)tmp;
#line 41
    return (abfd);
  } else {
#line 43
    return ((bfd *)((void *)0));
  }
}
}
#line 47 "binutils_df_4.c"
bfd *remote_bfd_open(char const   *name ) 
{ 
  bfd *tmp ;

  {
#line 48
  tmp = gdb_bfd_open(name);
#line 48
  return (tmp);
}
}
#line 51 "binutils_df_4.c"
bfd *symfile_bfd_open(char *name ) 
{ 
  bfd *sym_bfd ;
  char *absolute_name ;
  int desc ;
  int tmp ;
  int tmp___0 ;
  char *tmp___1 ;

  {
#line 57
  tmp = remote_filename_p((char const   *)name);
#line 57
  if (tmp) {
#line 59
    sym_bfd = remote_bfd_open((char const   *)name);
#line 60
    if (! sym_bfd) {
#line 61
      error("can\'t open to read symbols", (char const   *)name);
    }
#line 63
    return (sym_bfd);
  }
#line 66
  tmp___0 = strdup(name);
#line 66
  name = (char *)tmp___0;
#line 68
  tmp___1 = getenv("PATH");
#line 68
  desc = openp((char const   *)tmp___1, (char const   *)name, & absolute_name);
#line 70
  if (desc < 0) {
#line 72
    make_cleanup((make_cleanup_ftype *)(& free), (void *)name);
#line 73
    error("", (char const   *)name);
  }
#line 76
  free((void *)name);
#line 77
  name = absolute_name;
#line 78
  make_cleanup((make_cleanup_ftype *)(& free), (void *)name);
#line 80
  sym_bfd = gdb_bfd_open((char const   *)name);
#line 81
  if (! sym_bfd) {
#line 84
    make_cleanup((make_cleanup_ftype *)(& free), (void *)name);
#line 85
    error("can\'t open to read symbols", (char const   *)name);
  }
#line 91
  return (sym_bfd);
}
}
#line 95
extern int ( /* missing proto */  time)() ;
#line 94 "binutils_df_4.c"
int main(void) 
{ 
  int tmp ;
  struct cleanup *old_chain ;

  {
#line 95
  tmp = time((void *)0);
#line 95
  srand((unsigned int )tmp);
#line 97
  old_chain = (struct cleanup *)(& sentinel_cleanup);
#line 98
  symfile_bfd_open((char *)"test");
#line 100
  do_cleanups(old_chain);
#line 101
  return (0);
}
}
