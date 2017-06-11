mkdir -p capnp
pushd capnp
cmake -DBUILD_TESTING=Off .. && make -j9
popd
