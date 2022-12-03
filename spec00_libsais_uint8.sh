#!/bin/sh 
#PBS -l nodes=1:ppn=2 -l walltime=240:00:00
#PBS -M renau@ucsc.edu
ESESC_BIN=${1:-../main/esesc}
export ESESC_ReportFile="spec00_libsais"
export ESESC_BenchName="./libsais/bench_uint8.rv 33554432"
if [ -f $ESESC_BIN ]; then
  $ESESC_BIN
else
  $ESESC_BenchName
fi
exit 0
