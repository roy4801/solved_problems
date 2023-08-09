#!/bin/bash

find . -type f -name '*.cpp' | grep 'leetcode' | grep "/$1.cpp"

