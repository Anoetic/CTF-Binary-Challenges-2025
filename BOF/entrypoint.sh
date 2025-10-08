#!/usr/bin/env bash
set -euo pipefail

ulimit -c 0

/usr/bin/socat -d -d TCP-LISTEN:1337,fork,reuseaddr \
  EXEC:"stdbuf -i0 -o0 -e0 /usr/local/sbin/vuln",pipes,stderr
