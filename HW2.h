//
//  HW2.h
//  
//
//  Created by Terry Delaney on 2/28/21.
//

#ifndef HW2_h
#define HW2_h

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int picks;
int winner = 0;
int swap = 1;
int win = 0;
int test = 0;
int wstatus;
pid_t cpid, w;
char response;
char * argv[] = { &response };
char * env[] = { NULL };

#endif /* HW2_h */
