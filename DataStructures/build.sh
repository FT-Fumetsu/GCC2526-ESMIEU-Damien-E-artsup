#!/bin/bash

if [[ $# -eq 0 ]]; then
  echo "Usage: ./build.sh [-a|-m|-r]"
  exit 1
fi

current_dir=$(pwd)
cd "$(dirname "$0")"

if [[ $1 = "-a" ]]; then
  if [ -d "build" ]; then
    echo "# Deleting existing build directory"
    chmod -R 740 "./build"
    rm -rf ./build
  fi
  echo "# Creating new build directory"
  mkdir build
  cd build
  echo "# Running cmake"
  cmake  -DCMAKE_BUILD_TYPE=Debug ..
  echo "# Building the projet"
  make
elif [[ $1 = "-m" ]]; then
  cd build
  echo "# Building the projet"
  make
elif [[ $1 = "-r" ]]; then
  cd build
  echo "# Running the projet"
  # On retire l'argument du script [-a|-m|-r] pour ne garder que ceux passé aux programme
  shift
  ./tp-data $@
else
  echo "Usage: ./build.sh [-a|-m|-r]"
fi

cd "$current_dir"