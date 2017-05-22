function addCommitPush {
   pushd `git rev-parse --show-toplevel`/$1
   git add .
   git commit
   git push origin HEAD
   popd
}

#git config --file .gitmodules --get-regexp path | awk '{ print $2 }' \
#    | while read in; do addCommitPush $in; done

addCommitPush modules/xe
addCommitPush modules/xr
addCommitPush .


