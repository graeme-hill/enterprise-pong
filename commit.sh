rm -rf .backup
mkdir -p .backup
cp -R * .backup

pushd xe/modules
git submodule foreach "git add .; git commit; git push origin HEAD; return 0"
popd

git submodule foreach "git add .; git commit; git push origin HEAD; return 0"
git add .; git commit; git push origin HEAD
git submodule foreach --recursive git branch
