# Cgroups

The `cgroup` directory:

```bash

/sys/fs/cgroup

```

You can see handy commands to run against a process by running PID=123 sh cgroups.sh 

```bash

Start a process
sleep 500 &

Get the pid
echo $?

Create cgroup..
sudo mkdir -p /sys/fs/cgroup/memory/demo

Set the memory limit at a reasonable level
echo 50000000 > /sys/fs/cgroup/memory/demo/memory.limit_in_bytes

Add a process to our newly create cgroup
echo 123 > /sys/fs/cgroup/memory/demo/cgroup.procs

Show process cgroups
ps -o cgroup 123

Show our file for memory config
cat /sys/fs/cgroup/memory/demo/memory.usage_in_bytes

Watch the kernel terminate the process based on an impossible memory limitation
echo 1 > /sys/fs/cgroup/memory/demo/memory.limit_in_bytes

```

# Exercise (5 groups)

For each of the following sets of `cgroup` configuration, demonstrate the kernel killing a process by defining an impossible limitation in a newly created `cgroup`. 

### 1 CPU

### 2 Memory

### 3 Blockio (disk)

### 4 PID

### 5 Network 

### 6 Memory 

### 7 CPU

