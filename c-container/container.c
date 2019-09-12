// clone.c
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// This program is basically a lazy form of "unshare"



// -------------------------------------------------------------------------------
// fn
//
// The function we use to pass to clone()
//
int fn(void *arg) {
  printf("Child  PID: %d\n\n", getpid());
  system("sleep 1 && echo 'Child Disk:' && df -h && echo ''");
  //system("emacs");
  //system("bash");
  return 0;
}


// -------------------------------------------------------------------------------
// main
//
//
void main(int argc, char *argv[]) {





  // -----------------------------------------------------------------------------
  // Allocate memory
  //
  void *pchild_stack = malloc(1024 * 1024);
  if ( pchild_stack == NULL ) {
    printf("ERROR: Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
  }
  //
  // -----------------------------------------------------------------------------








  // -----------------------------------------------------------------------------
  // clone() calls
  //
  //int pid = clone(fn, pchild_stack + (1024 * 1024), SIGCHLD, NULL); // Same Pid, Same Disk
  //
  //int pid = clone(fn, pchild_stack + (1024 * 1024), CLONE_NEWPID | SIGCHLD, NULL); // Different Pid, Same Disk
  //
  int pid = clone(fn, pchild_stack + (1024 * 1024), CLONE_NEWPID | CLONE_NEWNET | CLONE_NEWNS | SIGCHLD, NULL); // Different Pid, Different Disk
  //
  // -----------------------------------------------------------------------------







  // -----------------------------------------------------------------------------
  // Check if clone() successful
  //
  if ( pid < 0 ) {
    printf("%d", pid);
    printf("ERROR: Unable to create the child process. Pid: %d\n", pid);
    exit(EXIT_FAILURE);
  }
  //
  // -----------------------------------------------------------------------------







  // -----------------------------------------------------------------------------
  // Wrap up the program
  //
  printf("Parent PID: %d\n", pid);
  system("echo 'Parent Disk:' && df -h");
  printf("\n");
  wait(NULL);
  free(pchild_stack);
  //
  // -----------------------------------------------------------------------------






  system("sleep 100");
}