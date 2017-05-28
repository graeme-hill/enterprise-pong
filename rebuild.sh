rm -rf build
mkdir build
pushd build
cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_BUILD_TYPE=Debug ..
make
popd
