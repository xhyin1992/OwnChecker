/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 196 "../stdio.h"
typedef unsigned int u_int___0;
#line 200 "../stdio.h"
typedef int int32_t___0;
#line 207 "../stdio.h"
typedef unsigned char u_char___0;
#line 245 "../stdio.h"
struct passwd {
   char *pw_name ;
   char *pw_passwd ;
   int pw_uid ;
   int pw_gid ;
   int pw_change ;
   char *pw_class ;
   char *pw_gecos ;
   char *pw_dir ;
   char *pw_shell ;
   int pw_expire ;
};
#line 364 "../openssh.h"
typedef u_int___0 BN_ULONG;
#line 365 "../openssh.h"
struct __anonstruct_Buffer_25 {
   u_char___0 *buf ;
   u_int___0 alloc ;
   u_int___0 offset ;
   u_int___0 end ;
};
#line 365 "../openssh.h"
typedef struct __anonstruct_Buffer_25 Buffer;
#line 372 "../openssh.h"
struct bignum_st {
   BN_ULONG *d ;
   int top ;
   int dmax ;
   int neg ;
   int flags ;
};
#line 390 "../openssh.h"
typedef struct bignum_st BIGNUM;
#line 391 "../openssh.h"
struct rsa_st {
   int pad ;
   int32_t___0 version ;
   void const   *meth ;
   void *engine ;
   BIGNUM *n ;
   BIGNUM *e ;
   BIGNUM *d ;
   BIGNUM *p ;
   BIGNUM *q ;
   BIGNUM *dmp1 ;
   BIGNUM *dmq1 ;
   BIGNUM *iqmp ;
   void *pss ;
   int ex_data ;
   int references ;
   int flags ;
   void *_method_mod_n ;
   void *_method_mod_p ;
   void *_method_mod_q ;
   char *bignum_data ;
   void *blinding ;
   void *mt_blinding ;
   void *lock ;
};
#line 391 "../openssh.h"
typedef struct rsa_st RSA;
#line 168 "openssh_df_5.c"
struct Authctxt;
#line 168 "openssh_df_5.c"
typedef struct Authctxt Authctxt;
#line 170 "openssh_df_5.c"
typedef int *KTEXT;
#line 171 "openssh_df_5.c"
typedef int KTEXT_ST;
#line 172 "openssh_df_5.c"
typedef int AUTH_DAT[10];
#line 176 "openssh_df_5.c"
struct Authctxt {
   int success ;
   int postponed ;
   int valid ;
   int attempt ;
   int failures ;
   char *user ;
   char *service ;
   struct passwd *pw ;
   char *style ;
   void *kbdintctxt ;
   char *krb4_ticket_file ;
};
#line 242
struct sockaddr_in;
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 386
extern  __attribute__((__nothrow__)) int ( /* format attribute */  snprintf)(char * __restrict  __s ,
                                                                             size_t __maxlen ,
                                                                             char const   * __restrict  __format 
                                                                             , ...) ;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 174 "openssh_df_5.c"
int arr[10]  ;
#line 191 "openssh_df_5.c"
static Buffer incoming_packet  ;
#line 192 "openssh_df_5.c"
int check  =    0;
#line 211
extern int ( /* missing proto */  buffer_get_int)() ;
#line 217
extern int ( /* missing proto */  buffer_get)() ;
#line 205 "openssh_df_5.c"
char *buffer_get_string(Buffer *buffer , u_int___0 *length_ptr ) 
{ 
  u_int___0 len ;
  char *value ;
  int tmp ;
  void *tmp___0 ;

  {
#line 211
  tmp = buffer_get_int(buffer);
#line 211
  len = (u_int___0 )tmp;
#line 212
  if (len > 262144U) {
#line 213
    printf((char const   * __restrict  )"Received packet with bad string length %d",
           len);
#line 213
    exit(1);
  }
#line 215
  tmp___0 = malloc((size_t )(len + 1U));
#line 215
  value = (char *)tmp___0;
#line 217
  buffer_get(buffer, value, len);
#line 219
  *(value + len) = (char)0;
#line 221
  if (length_ptr) {
#line 222
    *length_ptr = len;
  }
#line 223
  return (value);
}
}
#line 232 "openssh_df_5.c"
char *packet_get_string(u_int___0 *length_ptr ) 
{ 
  char *tmp ;

  {
#line 235
  tmp = buffer_get_string(& incoming_packet, length_ptr);
#line 235
  return (tmp);
}
}
#line 248
extern int ( /* missing proto */  krb_rd_req)() ;
#line 257
extern int ( /* missing proto */  log)() ;
#line 256
extern int ( /* missing proto */  kuserok)() ;
#line 238 "openssh_df_5.c"
int auth_krb4(Authctxt *authctxt , KTEXT auth , char **client ) 
{ 
  AUTH_DAT adat ;
  unsigned int tmp ;
  char instance[10] ;
  int r ;
  void *tmp___0 ;
  int tmp___1 ;

  {
#line 241
  adat[0] = 0;
#line 241
  tmp = 1U;
#line 241
  while (! (tmp >= 10U)) {
#line 241
    adat[tmp] = 0;
#line 241
    tmp ++;
  }
#line 248
  r = krb_rd_req(auth, "rcmd", instance, 0, & adat, "");
#line 248
  if (r) {
#line 250
    return (0);
  }
#line 253
  tmp___0 = malloc((size_t )10);
#line 253
  *client = (char *)tmp___0;
#line 256
  tmp___1 = kuserok(& adat, authctxt->user);
#line 256
  if (tmp___1 != 0) {
#line 257
    log("Kerberos v4 .klogin authorization failed for %s to account %s", *client,
        authctxt->user);
#line 259
    free((void *)*client);
#line 260
    return (0);
  }
#line 262
  return (1);
}
}
#line 284
extern int ( /* missing proto */  debug)() ;
#line 289
extern int ( /* missing proto */  auth_log)() ;
#line 288
extern int ( /* missing proto */  auth_password)() ;
#line 303
extern int ( /* missing proto */  packet_read)() ;
#line 310
extern int ( /* missing proto */  verbose)() ;
#line 314
extern int ( /* missing proto */  packet_integrity_check)() ;
#line 332
extern int ( /* missing proto */  packet_send_debug)() ;
#line 350
extern int ( /* missing proto */  auth_rhosts)() ;
#line 368
extern int ( /* missing proto */  RSA_new)() ;
#line 371
extern int ( /* missing proto */  BN_new)() ;
#line 375
extern int ( /* missing proto */  packet_get_int)() ;
#line 376
extern int ( /* missing proto */  packet_get_bignum)() ;
#line 380
extern int ( /* missing proto */  BN_num_bits)() ;
#line 384
extern int ( /* missing proto */  auth_rhosts_rsa)() ;
#line 385
extern int ( /* missing proto */  RSA_free)() ;
#line 399
extern int ( /* missing proto */  auth_rsa)() ;
#line 400
extern int ( /* missing proto */  BN_clear_free)() ;
#line 418
extern int ( /* missing proto */  auth_pam_password)() ;
#line 428
extern int ( /* missing proto */  memset)() ;
#line 428
extern int ( /* missing proto */  strlen)() ;
#line 435
extern int ( /* missing proto */  get_challenge)() ;
#line 438
extern int ( /* missing proto */  packet_start)() ;
#line 439
extern int ( /* missing proto */  packet_put_cstring)() ;
#line 441
extern int ( /* missing proto */  packet_send)() ;
#line 442
extern int ( /* missing proto */  packet_write_wait)() ;
#line 453
extern int ( /* missing proto */  verify_response)() ;
#line 478
extern int ( /* missing proto */  do_pam_account)() ;
#line 483
extern int ( /* missing proto */  get_authname)() ;
#line 499
extern int ( /* missing proto */  packet_disconnect)() ;
#line 269 "openssh_df_5.c"
static void do_authloop(Authctxt *authctxt ) 
{ 
  int authenticated ;
  u_int___0 bits ;
  RSA *client_host_key ;
  BIGNUM *n ;
  char *client_user ;
  char *password ;
  char info[1024] ;
  u_int___0 dlen ;
  int plen ;
  int nlen ;
  int elen ;
  u_int___0 ulen ;
  int type ;
  struct passwd *pw ;
  char const   *tmp ;
  int tmp___0 ;
  char *kdata ;
  char *tmp___1 ;
  KTEXT_ST tkt ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  char *challenge ;
  int tmp___11 ;
  char *response ;
  char *tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;

  {
#line 272
  authenticated = 0;
#line 281
  type = 0;
#line 282
  pw = authctxt->pw;
#line 284
  if (authctxt->valid) {
#line 284
    tmp = "";
  } else {
#line 284
    tmp = "illegal user ";
  }
#line 284
  debug("Attempting authentication for %s%.100s.", tmp, authctxt->user);
#line 288
  tmp___0 = auth_password(authctxt, "");
#line 288
  if (tmp___0) {
#line 289
    auth_log(authctxt, 1, "without authentication", "");
#line 290
    return;
  }
#line 294
  client_user = (char *)((void *)0);
#line 296
  while (1) {
#line 298
    authenticated = 0;
#line 300
    info[0] = (char )'\000';
#line 303
    type = packet_read(& plen);
#line 306
    switch (type) {
    case 42: 
#line 309
    if (type) {
#line 310
      verbose("Kerberos authentication disabled.");
    } else {
#line 312
      tmp___1 = packet_get_string(& dlen);
#line 312
      kdata = tmp___1;
#line 314
      packet_integrity_check(plen, 4U + dlen, type);
#line 316
      if ((int )*(kdata + 0) == 4) {
#line 319
        tmp___2 = auth_krb4(authctxt, & tkt, & client_user);
#line 319
        if (tmp___2) {
#line 320
          authenticated = 1;
#line 321
          snprintf((char * __restrict  )(info), sizeof(info), (char const   * __restrict  )" tktuser %.100s",
                   client_user);
#line 324
          free((void *)client_user);
        }
      }
#line 327
      free((void *)kdata);
    }
#line 329
    break;
    case 65: 
#line 332
    packet_send_debug("AFS token passing disabled before authentication.");
#line 333
    break;
    case 5: 
#line 336
    if (type) {
#line 337
      verbose("Rhosts authentication disabled.");
#line 338
      break;
    }
#line 346
    client_user = packet_get_string(& ulen);
#line 347
    packet_integrity_check(plen, 4U + ulen, type);
#line 350
    authenticated = auth_rhosts(pw, client_user);
#line 352
    snprintf((char * __restrict  )(info), sizeof(info), (char const   * __restrict  )" ruser %.100s",
             client_user);
#line 353
    break;
    case 35: 
#line 356
    if (type) {
#line 357
      verbose("Rhosts with RSA authentication disabled.");
#line 358
      break;
    }
#line 365
    client_user = packet_get_string(& ulen);
#line 368
    tmp___3 = RSA_new();
#line 368
    client_host_key = (RSA *)tmp___3;
#line 369
    if ((unsigned long )client_host_key == (unsigned long )((void *)0)) {
#line 370
      printf((char const   * __restrict  )"RSA_new failed%s", "");
#line 370
      exit(1);
    }
#line 371
    tmp___4 = BN_new();
#line 371
    client_host_key->e = (BIGNUM *)tmp___4;
#line 372
    tmp___5 = BN_new();
#line 372
    client_host_key->n = (BIGNUM *)tmp___5;
#line 373
    if ((unsigned long )client_host_key->e == (unsigned long )((void *)0)) {
#line 374
      printf((char const   * __restrict  )"BN_new failed%s", "");
#line 374
      exit(1);
    } else
#line 373
    if ((unsigned long )client_host_key->n == (unsigned long )((void *)0)) {
#line 374
      printf((char const   * __restrict  )"BN_new failed%s", "");
#line 374
      exit(1);
    }
#line 375
    tmp___6 = packet_get_int();
#line 375
    bits = (u_int___0 )tmp___6;
#line 376
    packet_get_bignum(client_host_key->e, & elen);
#line 377
    packet_get_bignum(client_host_key->n, & nlen);
#line 379
    tmp___8 = BN_num_bits(client_host_key->n);
#line 379
    if (bits != (u_int___0 )tmp___8) {
#line 380
      tmp___7 = BN_num_bits(client_host_key->n);
#line 380
      verbose("Warning: keysize mismatch for client_host_key: actual %d, announced %d",
              tmp___7, bits);
    }
#line 382
    packet_integrity_check(plen, (((4U + ulen) + 4U) + (u_int___0 )elen) + (u_int___0 )nlen,
                           type);
#line 384
    authenticated = auth_rhosts_rsa(pw, client_user, client_host_key);
#line 385
    RSA_free(client_host_key);
#line 387
    snprintf((char * __restrict  )(info), sizeof(info), (char const   * __restrict  )" ruser %.100s",
             client_user);
#line 388
    break;
    case 6: 
#line 391
    if (type) {
#line 392
      verbose("RSA authentication disabled.");
#line 393
      break;
    }
#line 396
    tmp___9 = BN_new();
#line 396
    n = (BIGNUM *)tmp___9;
#line 397
    packet_get_bignum(n, & nlen);
#line 398
    packet_integrity_check(plen, nlen, type);
#line 399
    authenticated = auth_rsa(pw, n);
#line 400
    BN_clear_free(n);
#line 401
    break;
    case 9: 
#line 404
    if (type) {
#line 405
      verbose("Password authentication disabled.");
#line 406
      break;
    }
#line 413
    password = packet_get_string(& dlen);
#line 414
    packet_integrity_check(plen, 4U + dlen, type);
#line 418
    authenticated = auth_pam_password(pw, password);
#line 428
    tmp___10 = strlen(password);
#line 428
    memset(password, 0, tmp___10);
#line 429
    free((void *)password);
#line 430
    break;
    case 39: 
#line 433
    debug("rcvd SSH_CMSG_AUTH_TIS");
#line 434
    if (type == 1) {
#line 435
      tmp___11 = get_challenge(authctxt);
#line 435
      challenge = (char *)tmp___11;
#line 436
      if ((unsigned long )challenge != (unsigned long )((void *)0)) {
#line 437
        debug("sending challenge \'%s\'", challenge);
#line 438
        packet_start(40);
#line 439
        packet_put_cstring(challenge);
#line 440
        free((void *)challenge);
#line 441
        packet_send();
#line 442
        packet_write_wait();
#line 443
        goto __Cont;
      }
    }
#line 446
    break;
    case 41: 
#line 448
    debug("rcvd SSH_CMSG_AUTH_TIS_RESPONSE");
#line 449
    if (type == 1) {
#line 450
      tmp___12 = packet_get_string(& dlen);
#line 450
      response = tmp___12;
#line 451
      debug("got response \'%s\'", response);
#line 452
      packet_integrity_check(plen, 4U + dlen, type);
#line 453
      authenticated = verify_response(authctxt, response);
#line 454
      memset(response, 'r', dlen);
#line 455
      free((void *)response);
    }
#line 457
    break;
    default: 
#line 464
    log("Unknown message during authentication: type %d", type);
#line 465
    break;
    }
#line 473
    if (! authctxt->valid) {
#line 473
      if (authenticated) {
#line 474
        printf((char const   * __restrict  )"INTERNAL ERROR: authenticated invalid user %s",
               authctxt->user);
#line 474
        exit(1);
      }
    }
#line 478
    if (authenticated) {
#line 478
      tmp___13 = do_pam_account(pw->pw_name, client_user);
#line 478
      if (! tmp___13) {
#line 479
        authenticated = 0;
      }
    }
#line 483
    tmp___14 = get_authname(type);
#line 483
    auth_log(authctxt, authenticated, tmp___14, info);
#line 485
    if ((unsigned long )client_user != (unsigned long )((void *)0)) {
#line 486
      free((void *)client_user);
#line 487
      client_user = (char *)((void *)0);
    }
#line 490
    if (authenticated) {
#line 491
      return;
    }
#line 493
    tmp___15 = authctxt->failures;
#line 493
    (authctxt->failures) ++;
#line 493
    if (tmp___15 > 6) {
#line 499
      packet_disconnect("Too many authentication failures for %.100s", authctxt->user);
    }
#line 502
    packet_start(15);
#line 503
    packet_send();
#line 504
    packet_write_wait();
    __Cont: /* CIL Label */ ;
  }
}
}
#line 508 "openssh_df_5.c"
int main(void) 
{ 
  Authctxt authctxt ;

  {
#line 511
  do_authloop(& authctxt);
#line 512
  return (0);
}
}
