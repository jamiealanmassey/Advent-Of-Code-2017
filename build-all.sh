#!/bin/bash
#find * -type f -name '*.cpp' -exec sh -c 'g++ $0 -o $(pwd)/solutions/${$(basename $0)%.*}' {} \;
#find * -type f -name '*.cpp' -exec sh -c 'echo "$1"' _ {} \;

find * -type f -name '*.cpp' | while read nextfile; do
  filename0=$(basename "$nextfile")
  filename1="${filename0%.*}"

  echo "compiling solution ${filename0} to $(pwd)/solutions/${filename1}" 
  g++ ${nextfile} -o $(pwd)/solutions/${filename1}
done
