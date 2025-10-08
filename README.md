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

## Spinning up the Docker Containers

In the folder for the desired challenge:
```
docker build -t bof .
docker run --rm bof
```

If you want to expose the port:
```
docker run -d --rm -p 1337:1337 bof
```

Enjoy. If these challeneges are used in your own CTF then please credit me :)
