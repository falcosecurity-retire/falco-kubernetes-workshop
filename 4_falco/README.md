# Falco

### Logs 

The Falco logs can be found with the following command

```
k logs <pod> -f
```

Information on how to deploy Falco can be found [here](https://github.com/falcosecurity/falco/tree/dev/integrations/k8s-using-daemonset)

More information on installing Falco can be found in our documentation [here](https://falco.org/docs/installation/)

# Exercise

Show Falco alerting when you are hacking into Kubernetes.

Open the Falco config map 

```bash

k edit cm

```

Configure Falco to do something interesting on your system when an alert is received.

This is done by editing the following line in the config map.

```yaml

      program: "jq '{text: .output}' | curl -d @- -X POST https://hooks.slack.com/services/XXX"

```

Extra Credit: Have Falco delete the offending Pod. 
