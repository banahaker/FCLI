@echo off
git status
git add .
IF NOT (%1) == () ( git commit -m %1 ) else ( git commit -m "auto commit" )
git push