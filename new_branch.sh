#!/bin/bash

git add .
git commit -m"new branch"
git checkout -b bassam_branch
git push origin bassam_branch
git push --set-upstream origin bassam_branch
