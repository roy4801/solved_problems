#!/bin/bash

git stash
git pull --rebase
git stash pop
