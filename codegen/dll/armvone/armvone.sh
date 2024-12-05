#!/bin/sh
export CMAKE_EXPORT_COMPILE_COMMANDS="TRUE"
PATH=/home/pritesh0/matlab24/toolbox/shared/coder/ninja/glnxa64:$PATH
"/home/pritesh0/matlab24/bin/glnxa64/cmake/bin/cmake" -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=/home/pritesh0/matlab24/toolbox/coder/compile/cmake/linux_gnu_gcc_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -DENABLE_SSE2=1 -DCMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1 -DCMAKE_INSTALL_PREFIX="../../.." --no-warn-unused-cli
COMMAND_STATUS=$?
if [ $COMMAND_STATUS -ne 0 ]
then
    echo "The cmake command returned a non-zero exit code $COMMAND_STATUS" >&2
    exit $COMMAND_STATUS
fi

"/home/pritesh0/matlab24/bin/glnxa64/cmake/bin/cmake" --build build
COMMAND_STATUS=$?
if [ $COMMAND_STATUS -ne 0 ]
then
    echo "The cmake command returned a non-zero exit code $COMMAND_STATUS" >&2
    exit $COMMAND_STATUS
fi

"/home/pritesh0/matlab24/bin/glnxa64/cmake/bin/cmake" --install build --prefix ../../..
COMMAND_STATUS=$?
if [ $COMMAND_STATUS -ne 0 ]
then
    echo "The cmake command returned a non-zero exit code $COMMAND_STATUS" >&2
    exit $COMMAND_STATUS
fi

