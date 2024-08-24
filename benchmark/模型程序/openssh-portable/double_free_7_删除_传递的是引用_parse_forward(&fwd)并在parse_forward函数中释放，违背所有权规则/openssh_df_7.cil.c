/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 98 "openssh_df_7.c"
typedef unsigned short u_short___1;
#line 99 "openssh_df_7.c"
struct __anonstruct_Forward_37 {
   char *listen_host ;
   u_short___1 listen_port ;
   char *connect_host ;
   u_short___1 connect_port ;
};
#line 99 "openssh_df_7.c"
typedef struct __anonstruct_Forward_37 Forward;
#line 483 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 106 "openssh_df_7.c"
int compat13  =    0;
#line 107 "openssh_df_7.c"
int compat20  =    0;
#line 108 "openssh_df_7.c"
int datafellows  =    0;
#line 126
extern int ( /* missing proto */  memset)() ;
#line 128
extern int ( /* missing proto */  strdup)() ;
#line 131
extern int ( /* missing proto */  isspace)() ;
#line 135
extern int ( /* missing proto */  hpdelim)() ;
#line 144
extern int ( /* missing proto */  a2port)() ;
#line 149
extern int ( /* missing proto */  cleanhostname)() ;
#line 186
extern int ( /* missing proto */  strlen)() ;
#line 120 "openssh_df_7.c"
int parse_forward(Forward *fwd , char const   *fwdspec , int dynamicfwd ) 
{ 
  int i ;
  char *p ;
  char *cp ;
  char *fwdarg[4] ;
  int tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;

  {
#line 126
  memset(fwd, '\000', sizeof(*fwd));
#line 128
  tmp = strdup(fwdspec);
#line 128
  p = (char *)tmp;
#line 128
  cp = p;
#line 131
  while (1) {
#line 131
    tmp___0 = isspace((int )*cp);
#line 131
    if (! tmp___0) {
#line 131
      break;
    }
#line 132
    cp ++;
  }
#line 134
  i = 0;
#line 134
  while (i < 4) {
#line 135
    tmp___2 = hpdelim(& cp);
#line 135
    tmp___1 = (char *)tmp___2;
#line 135
    fwdarg[i] = tmp___1;
#line 135
    if ((unsigned long )tmp___1 == (unsigned long )((void *)0)) {
#line 136
      break;
    }
#line 134
    i ++;
  }
#line 139
  if ((unsigned long )cp != (unsigned long )((void *)0)) {
#line 140
    i = 0;
  }
#line 141
  switch (i) {
  case 1: 
#line 143
  fwd->listen_host = (char *)((void *)0);
#line 144
  tmp___3 = a2port(fwdarg[0]);
#line 144
  fwd->listen_port = (u_short___1 )tmp___3;
#line 145
  tmp___4 = strdup("socks");
#line 145
  fwd->connect_host = (char *)tmp___4;
#line 146
  break;
  case 2: 
#line 149
  tmp___5 = cleanhostname(fwdarg[0]);
#line 149
  tmp___6 = strdup(tmp___5);
#line 149
  fwd->listen_host = (char *)tmp___6;
#line 150
  tmp___7 = a2port(fwdarg[1]);
#line 150
  fwd->listen_port = (u_short___1 )tmp___7;
#line 151
  tmp___8 = strdup("socks");
#line 151
  fwd->connect_host = (char *)tmp___8;
#line 152
  break;
  case 3: 
#line 155
  fwd->listen_host = (char *)((void *)0);
#line 156
  tmp___9 = a2port(fwdarg[0]);
#line 156
  fwd->listen_port = (u_short___1 )tmp___9;
#line 157
  tmp___10 = cleanhostname(fwdarg[1]);
#line 157
  tmp___11 = strdup(tmp___10);
#line 157
  fwd->connect_host = (char *)tmp___11;
#line 158
  tmp___12 = a2port(fwdarg[2]);
#line 158
  fwd->connect_port = (u_short___1 )tmp___12;
#line 159
  break;
  case 4: 
#line 162
  tmp___13 = cleanhostname(fwdarg[0]);
#line 162
  tmp___14 = strdup(tmp___13);
#line 162
  fwd->listen_host = (char *)tmp___14;
#line 163
  tmp___15 = a2port(fwdarg[1]);
#line 163
  fwd->listen_port = (u_short___1 )tmp___15;
#line 164
  tmp___16 = cleanhostname(fwdarg[2]);
#line 164
  tmp___17 = strdup(tmp___16);
#line 164
  fwd->connect_host = (char *)tmp___17;
#line 165
  tmp___18 = a2port(fwdarg[3]);
#line 165
  fwd->connect_port = (u_short___1 )tmp___18;
#line 166
  break;
  default: 
#line 168
  i = 0;
  }
#line 171
  free((void *)p);
#line 173
  if (dynamicfwd) {
#line 174
    if (! (i == 1)) {
#line 174
      if (! (i == 2)) {
#line 175
        goto fail_free;
      }
    }
  } else {
#line 177
    if (! (i == 3)) {
#line 177
      if (! (i == 4)) {
#line 178
        goto fail_free;
      }
    }
#line 179
    if ((int )fwd->connect_port == 0) {
#line 180
      goto fail_free;
    }
  }
#line 183
  if ((int )fwd->listen_port == 0) {
#line 184
    goto fail_free;
  }
#line 186
  if ((unsigned long )fwd->connect_host != (unsigned long )((void *)0)) {
#line 186
    tmp___19 = strlen(fwd->connect_host);
#line 186
    if (tmp___19 >= 1025) {
#line 188
      goto fail_free;
    }
  }
#line 190
  return (i);
  fail_free: 
#line 193
  if ((unsigned long )fwd->connect_host != (unsigned long )((void *)0)) {
#line 194
    free((void *)fwd->connect_host);
  }
#line 196
  if ((unsigned long )fwd->listen_host != (unsigned long )((void *)0)) {
#line 197
    free((void *)fwd->listen_host);
  }
#line 200
  return (0);
}
}
#line 214
extern int ( /* missing proto */  bzero)() ;
#line 217
extern int ( /* missing proto */  leave_raw_mode)() ;
#line 218
extern int ( /* missing proto */  read_passphrase)() ;
#line 229
extern int ( /* missing proto */  logit)() ;
#line 245
extern int ( /* missing proto */  ssh_local_cmd)() ;
#line 290
extern int ( /* missing proto */  channel_request_rforward_cancel)() ;
#line 297
extern int ( /* missing proto */  channel_setup_local_fwd_listener)() ;
#line 304
extern int ( /* missing proto */  channel_request_remote_forwarding)() ;
#line 316
extern int ( /* missing proto */  enter_raw_mode)() ;
#line 204 "openssh_df_7.c"
static void process_cmdline(void) 
{ 
  char *s ;
  char *cmd ;
  char *cancel_host ;
  int delete ;
  int local ;
  int remote ;
  int dynamic ;
  u_short___1 cancel_port ;
  Forward fwd ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;

  {
#line 209
  delete = 0;
#line 210
  local = 0;
#line 210
  remote = 0;
#line 210
  dynamic = 0;
#line 214
  bzero(& fwd, sizeof(fwd));
#line 215
  fwd.connect_host = (char *)((void *)0);
#line 215
  fwd.listen_host = fwd.connect_host;
#line 217
  leave_raw_mode();
#line 218
  tmp = read_passphrase("\r\nssh> ", 1);
#line 218
  s = (char *)tmp;
#line 218
  cmd = s;
#line 219
  if ((unsigned long )s == (unsigned long )((void *)0)) {
#line 220
    goto out;
  }
#line 221
  while (1) {
#line 221
    tmp___0 = isspace((int )*s);
#line 221
    if (! tmp___0) {
#line 221
      break;
    }
#line 222
    s ++;
  }
#line 223
  if ((int )*s == 45) {
#line 224
    s ++;
  }
#line 225
  if ((int )*s == 0) {
#line 226
    goto out;
  }
#line 228
  if ((int )*s == 104) {
#line 228
    goto _L;
  } else
#line 228
  if ((int )*s == 72) {
#line 228
    goto _L;
  } else
#line 228
  if ((int )*s == 63) {
    _L: /* CIL Label */ 
#line 229
    logit("Commands:");
#line 230
    logit("      -L[bind_address:]port:host:hostport    Request local forward");
#line 232
    logit("      -R[bind_address:]port:host:hostport    Request remote forward");
#line 234
    logit("      -D[bind_address:]port                  Request dynamic forward");
#line 236
    logit("      -KR[bind_address:]port                 Cancel remote forward");
#line 238
    logit("      !args                                  Execute local command");
#line 240
    goto out;
  }
#line 243
  if ((int )*s == 33) {
#line 244
    s ++;
#line 245
    ssh_local_cmd(s);
#line 246
    goto out;
  }
#line 249
  if ((int )*s == 75) {
#line 250
    delete = 1;
#line 251
    s ++;
  }
#line 253
  if ((int )*s == 76) {
#line 254
    local = 1;
  } else
#line 255
  if ((int )*s == 82) {
#line 256
    remote = 1;
  } else
#line 257
  if ((int )*s == 68) {
#line 258
    dynamic = 1;
  } else {
#line 260
    logit("Invalid command.");
#line 261
    goto out;
  }
#line 264
  if (local) {
#line 264
    goto _L___0;
  } else
#line 264
  if (dynamic) {
    _L___0: /* CIL Label */ 
#line 264
    if (delete) {
#line 265
      logit("Not supported.");
#line 266
      goto out;
    }
  }
#line 268
  if (remote) {
#line 268
    if (delete) {
#line 268
      if (! compat20) {
#line 269
        logit("Not supported for SSH protocol version 1.");
#line 270
        goto out;
      }
    }
  }
#line 273
  while (1) {
#line 273
    s ++;
#line 273
    tmp___1 = isspace((int )*s);
#line 273
    if (! tmp___1) {
#line 273
      break;
    }
  }
#line 276
  if (delete) {
#line 277
    cancel_port = (u_short___1 )0;
#line 278
    tmp___2 = hpdelim(& s);
#line 278
    cancel_host = (char *)tmp___2;
#line 279
    if ((unsigned long )s != (unsigned long )((void *)0)) {
#line 280
      tmp___3 = a2port(s);
#line 280
      cancel_port = (u_short___1 )tmp___3;
#line 281
      tmp___4 = cleanhostname(cancel_host);
#line 281
      cancel_host = (char *)tmp___4;
    } else {
#line 283
      tmp___5 = a2port(cancel_host);
#line 283
      cancel_port = (u_short___1 )tmp___5;
#line 284
      cancel_host = (char *)((void *)0);
    }
#line 286
    if ((int )cancel_port == 0) {
#line 287
      logit("Bad forwarding close port");
#line 288
      goto out;
    }
#line 290
    channel_request_rforward_cancel(cancel_host, (int )cancel_port);
  } else {
#line 292
    if (dynamic) {
#line 292
      tmp___6 = 1;
    } else {
#line 292
      tmp___6 = 0;
    }
#line 292
    tmp___7 = parse_forward(& fwd, (char const   *)s, tmp___6);
#line 292
    if (! tmp___7) {
#line 293
      logit("Bad forwarding specification.");
#line 294
      goto out;
    }
#line 296
    if (local) {
#line 296
      goto _L___1;
    } else
#line 296
    if (dynamic) {
      _L___1: /* CIL Label */ 
#line 297
      tmp___8 = channel_setup_local_fwd_listener(fwd.listen_host, (int )fwd.listen_port,
                                                 fwd.connect_host, (int )fwd.connect_port);
#line 297
      if (tmp___8 < 0) {
#line 300
        logit("Port forwarding failed.");
#line 301
        goto out;
      }
    } else {
#line 304
      tmp___9 = channel_request_remote_forwarding(fwd.listen_host, (int )fwd.listen_port,
                                                  fwd.connect_host, (int )fwd.connect_port);
#line 304
      if (tmp___9 < 0) {
#line 307
        logit("Port forwarding failed.");
#line 308
        goto out;
      }
    }
#line 312
    logit("Forwarding port.");
  }
  out: 
#line 316
  enter_raw_mode();
#line 317
  if (cmd) {
#line 318
    free((void *)cmd);
  }
#line 319
  if ((unsigned long )fwd.listen_host != (unsigned long )((void *)0)) {
#line 320
    free((void *)fwd.listen_host);
  }
#line 321
  if ((unsigned long )fwd.connect_host != (unsigned long )((void *)0)) {
#line 322
    free((void *)fwd.connect_host);
  }
#line 323
  return;
}
}
#line 326 "openssh_df_7.c"
int main(void) 
{ 


  {
#line 327
  process_cmdline();
#line 328
  return (0);
}
}
