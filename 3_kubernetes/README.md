# Kubernetes

The `scary.yaml` Pod allows for a lot of escalation to the host system. 

Using the lessons above: hack into a Kubernetes host.

Some commands you might be interested in running in the Pod are:

```

chroot
mount 
nsenter
$$

```


# Exercise

Deploy the pod to Kubernetes, and gain access to the root system from the default namespace. 