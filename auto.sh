#!/bin/sh
riscv64-linux-gnu-gcc -O3 -static ./libsais/bench_$1.c -o ./libsais/bench_$1.rv
echo "build ok"
./spec00_libsais_$1.sh
echo "run ok"
./scripts/report.pl -last
