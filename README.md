# CTF-Binary-Challenges-2025
A couple of the docker containers I made for a personal CTF with my mates. Just an XOR and BOF challenge.

## Compiling
Folders will already have the compiled x86_64 binaries in them, but if you want to compile them yourself then its fairly simple.

### MGMT

```
gcc -o mgmt vuln.c -static
```

### BOF
Requires a few more flags to get rid of some of the memory protections.

```
gcc -fno-stack-protector -z execstack -no-pie -Wl,-z,norelro -o vuln vuln.c -static
```

Enjoy. If these challeneges are used in your own CTF then please credit me :)
