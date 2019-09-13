# The Code

We use this code to demonstrate the `clone` system call. 
We demonstrate how we are able to spawn new processes with different namespaces defined [here](http://man7.org/linux/man-pages/man2/clone.2.html)

The three examples used in this code snippet are:

```bash
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
```

It is important to not that `unshare` has similar functionality and features a convenient command line tool.
More information on `unshare` can be found [here](http://man7.org/linux/man-pages/man1/unshare.1.html).

# Building the code

```bash 

gcc container.c -o container

```

# Running the code

```bash 

(sudo) ./container

```

# Start exploring 

Reference the available `clone` flags from the `clone` manpage (linked above) and begin to explore what each of the namespaces have access to.

The `fn()` function contains various `system()` references. Use these to explore what you can and can't see from an isolated process.

# Exercise (7 groups)

Every team is assigned a namespace. Every team finds a way to demonstrate that the `clone`d process is running in a different 

### 1 Mount (mnt)

### 2 PID (pid)

### 3 Network (net)

### 4 Interprocess Communication (ipc)

### 5 UTS

### 6 User ID (user)

### 7 Control Group (cgroup) Namespace