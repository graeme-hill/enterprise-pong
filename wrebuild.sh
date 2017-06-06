rm -rf wbuild
mkdir wbuild
pushd wbuild
cmake -DJS=On -DCMAKE_C_COMPILER=`which emcc` \
	-DCMAKE_CXX_COMPILER=`which em++` ..
make -j9
popd
