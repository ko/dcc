#!/bin/bash

make clean
make
./lexi test/$1/test.c
