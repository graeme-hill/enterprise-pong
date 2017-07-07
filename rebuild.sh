rm -rf build
mkdir build
pushd build
cmake \
	-DCMAKE_C_COMPILER=/usr/bin/gcc \
	-DCMAKE_CXX_COMPILER=/usr/bin/g++ \
	-DCMAKE_BUILD_TYPE=Debug \
	..
make -j9
popd
