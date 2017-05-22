function addCommitPush {
   pushd $1
   git add .
   git commit
   git push origin HEAD
   popd
}

addCommitPush `git rev-parse --show-toplevel`

#git config --file .gitmodules --get-regexp path | awk '{ print $2 }' \
#    | while read in; do addCommitPush $in; done

