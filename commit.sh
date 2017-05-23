rm -rf .backup
mkdir -p .backup
cp -R * .backup

function addCommitPush {
   git add . && \
   git commit && \
   git push origin HEAD
}

git submodule foreach addCommitPush
addCommitPush
git submodule foreach git branch

