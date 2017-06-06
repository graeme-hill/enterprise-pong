rm -rf web-build
mkdir web-build
pushd web-build
cmake -DJS=On -DCMAKE_C_COMPILER=`which emcc` \
	-DCMAKE_CXX_COMPILER=`which em++` ..
make -j9
popd
