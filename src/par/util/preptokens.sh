#!/bin/bash

FILE=$1
OUTFILE=tokens

grep "\->" $FILE                \
    | egrep '{.*}'              \
    | sed -e 's,\\s \-> ,,g'    \
    | sed -e 's,(.*),\$\$,g'    \
    > $OUTFILE

