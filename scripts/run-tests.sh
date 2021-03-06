#!/bin/bash
AMICI_PATH="`dirname \"$0\"`"
AMICI_PATH="`( cd \"$AMICI_PATH/..\" && pwd )`"

# Build dependencies

# SuiteSpare
SUITESPARSE_ROOT="${AMICI_PATH}/SuiteSparse"
cd ${SUITESPARSE_ROOT}/SuiteSparse_config
make library

cd ${SUITESPARSE_ROOT}/AMD
make library

cd ${SUITESPARSE_ROOT}/BTF
make library

cd ${SUITESPARSE_ROOT}/CAMD
make library

cd ${SUITESPARSE_ROOT}/COLAMD
make library

cd ${SUITESPARSE_ROOT}/KLU
make library

# Sundials
SUNDIALS_BUILD_PATH="${AMICI_PATH}/sundials/build/"
mkdir -p ${SUNDIALS_BUILD_PATH}
cd ${SUNDIALS_BUILD_PATH}

cmake -DCMAKE_INSTALL_PREFIX="${SUNDIALS_BUILD_PATH}" \
-DBUILD_ARKODE=OFF \
-DBUILD_CVODE=OFF \
-DBUILD_IDA=OFF \
-DBUILD_KINSOL=OFF \
-DBUILD_SHARED_LIBS=ON \
-DBUILD_STATIC_LIBS=ON \
-DEXAMPLES_ENABLE=OFF \
-DEXAMPLES_INSTALL=OFF \
-DKLU_ENABLE=ON \
-DKLU_LIBRARY_DIR="${SUITESPARSE_ROOT}/lib" \
-DKLU_INCLUDE_DIR="${SUITESPARSE_ROOT}/include" \
.. 

make 
make install

cd ../../

# Cpputest
mkdir -p ${AMICI_PATH}/ThirdParty
cd ${AMICI_PATH}/ThirdParty 
if [ ! -d "cpputest-3.8" ]; then
    if [ ! -e "cpputest-3.8.tar.gz" ]; then
        wget https://github.com/cpputest/cpputest/releases/download/v3.8/cpputest-3.8.tar.gz
    fi
    tar -xzf cpputest-3.8.tar.gz
    cd cpputest-3.8/cpputest_build/
    ../configure && make
fi

# done building dependencies

# Prepare tests

TESTMODELS="model_dirac model_steadystate model_jakstat_adjoint model_jakstat_adjoint_o2"
for MODEL in $TESTMODELS; do 
	mkdir -p ${AMICI_PATH}/models/${MODEL}/build
	cd ${AMICI_PATH}/models/${MODEL}/build
	cmake -DCMAKE_CXX_STANDARD=11 -DCMAKE_CXX_STANDARD_REQUIRED=ON ..
	make
done;


# Build test suite

cd ${AMICI_PATH}/tests/cpputest/
mkdir -p build
cd build
cmake -DCMAKE_CXX_STANDARD=11 -DCMAKE_CXX_STANDARD_REQUIRED=ON ..
make

# Run tests
export DYLD_LIBRARY_PATH="${DYLD_LIBRARY_PATH}:${SUNDIALS_BUILD_PATH}/lib:${SUITESPARSE_ROOT}/lib"

ctest -V
