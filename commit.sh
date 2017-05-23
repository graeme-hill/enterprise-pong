rm -rf .backup
mkdir -p .backup
cp -R * .backup

git submodule foreach "git add .; git commit; git push origin HEAD; return 0"
git add .; git commit; git push origin HEAD
git submodule foreach git branch
