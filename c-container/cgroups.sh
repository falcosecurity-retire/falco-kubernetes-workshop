#!/bin/bash



PID=${PID:-1}
CGROUPNAME=${CGROUPNAME:-demo}

echo "Create cgroup.."
echo "sudo mkdir -p /sys/fs/cgroup/memory/${CGROUPNAME}"
echo ""

echo "Set the memory limit at a reasonable level"
echo "echo 50000000 > /sys/fs/cgroup/memory/${CGROUPNAME}/memory.limit_in_bytes"
echo ""

echo "Add a process to our newly create cgroup"
echo "echo ${PID} > /sys/fs/cgroup/memory/${CGROUPNAME}/cgroup.procs"
echo ""

echo "Show process cgroups"
echo "ps -o cgroup ${PID}"
echo ""

echo "Show our file for memory config"
echo "cat /sys/fs/cgroup/memory/${CGROUPNAME}/memory.usage_in_bytes"
echo ""

echo "Watch the kernel terminate the process based on an impossible memory limitation"
echo "echo 1 > /sys/fs/cgroup/memory/${CGROUPNAME}/memory.limit_in_bytes"
echo ""