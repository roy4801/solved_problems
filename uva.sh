#!/bin/bash

# uva.sh - open specific problem in uva/ with subl
# usage: ./uva.sh <problem>

./gen.sh uva ${1}
./edit.sh uva ${1}
