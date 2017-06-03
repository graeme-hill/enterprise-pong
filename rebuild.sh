rm -rf build
mkdir build
pushd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j9
popd
