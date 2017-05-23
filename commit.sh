rm -rf ./.backup
cp -R `pwd`  ./.backup

function addCommitPush {
   git add . && \
   git commit && \
   git push origin HEAD
}

git submodule foreach addCommitPush
addCommitPush


