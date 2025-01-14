###########################################################################
# CMakeLists.txt generated for component armvone
# Product type: SHARED library
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(armvone)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR ../../.. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT /home/ayush/Applications/matlab CACHE PATH "")

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# Definition of target "armvone".
add_library(armvone SHARED ${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src/ccd_ccd.c
    ${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src/ccd_mpr.c
    ${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src/ccd_polytope.c
    ${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src/ccd_vec3.c
    ${MATLAB_ROOT}/toolbox/shared/robotics/robotcore/builtins/libsrc/collisioncodegen/collisioncodegen_CollisionGeometry.cpp
    ${MATLAB_ROOT}/toolbox/shared/robotics/robotcore/builtins/libsrc/collisioncodegen/collisioncodegen_api.cpp
    ${MATLAB_ROOT}/toolbox/shared/robotics/robotcore/builtins/libsrc/collisioncodegen/collisioncodegen_ccdExtensions.cpp
    ${MATLAB_ROOT}/toolbox/shared/robotics/robotcore/builtins/libsrc/collisioncodegen/collisioncodegen_checkCollision.cpp
    ${START_DIR}/codegen/dll/armvone/coder_posix_time.c
    ${START_DIR}/codegen/dll/armvone/armvone_data.c
    ${START_DIR}/codegen/dll/armvone/rt_nonfinite.c
    ${START_DIR}/codegen/dll/armvone/rtGetNaN.c
    ${START_DIR}/codegen/dll/armvone/rtGetInf.c
    ${START_DIR}/codegen/dll/armvone/armvone_initialize.c
    ${START_DIR}/codegen/dll/armvone/armvone_terminate.c
    ${START_DIR}/codegen/dll/armvone/armvone.c
    ${START_DIR}/codegen/dll/armvone/rand.c
    ${START_DIR}/codegen/dll/armvone/eml_rand_mt19937ar.c
    ${START_DIR}/codegen/dll/armvone/RigidBody.c
    ${START_DIR}/codegen/dll/armvone/rigidBodyJoint.c
    ${START_DIR}/codegen/dll/armvone/CollisionSet.c
    ${START_DIR}/codegen/dll/armvone/structConstructorHelper.c
    ${START_DIR}/codegen/dll/armvone/inverseKinematics.c
    ${START_DIR}/codegen/dll/armvone/RigidBodyTree.c
    ${START_DIR}/codegen/dll/armvone/validatestring.c
    ${START_DIR}/codegen/dll/armvone/trvec2tform.c
    ${START_DIR}/codegen/dll/armvone/SystemCore.c
    ${START_DIR}/codegen/dll/armvone/find.c
    ${START_DIR}/codegen/dll/armvone/tic.c
    ${START_DIR}/codegen/dll/armvone/DampedBFGSwGradientProjection.c
    ${START_DIR}/codegen/dll/armvone/IKHelpers.c
    ${START_DIR}/codegen/dll/armvone/svd.c
    ${START_DIR}/codegen/dll/armvone/xzlangeM.c
    ${START_DIR}/codegen/dll/armvone/xnrm2.c
    ${START_DIR}/codegen/dll/armvone/xdotc.c
    ${START_DIR}/codegen/dll/armvone/xzsvdc.c
    ${START_DIR}/codegen/dll/armvone/mtimes.c
    ${START_DIR}/codegen/dll/armvone/toc.c
    ${START_DIR}/codegen/dll/armvone/mldivide.c
    ${START_DIR}/codegen/dll/armvone/norm.c
    ${START_DIR}/codegen/dll/armvone/inv.c
    ${START_DIR}/codegen/dll/armvone/diag.c
    ${START_DIR}/codegen/dll/armvone/minOrMax.c
    ${START_DIR}/codegen/dll/armvone/any.c
    ${START_DIR}/codegen/dll/armvone/isPositiveDefinite.c
    ${START_DIR}/codegen/dll/armvone/randn.c
    ${START_DIR}/codegen/dll/armvone/handle.c
    ${START_DIR}/codegen/dll/armvone/eml_rand_mt19937ar_stateful.c
    ${START_DIR}/codegen/dll/armvone/CoderTimeAPI.c
    ${START_DIR}/codegen/dll/armvone/strcmp.c
    ${START_DIR}/codegen/dll/armvone/importrobot.c
    ${START_DIR}/codegen/dll/armvone/CharacterVector.c
    ${START_DIR}/codegen/dll/armvone/sqrt.c
    ${START_DIR}/codegen/dll/armvone/xaxpy.c
    ${START_DIR}/codegen/dll/armvone/xrotg.c
    ${START_DIR}/codegen/dll/armvone/xrot.c
    ${START_DIR}/codegen/dll/armvone/xswap.c
    ${START_DIR}/codegen/dll/armvone/xgeqp3.c
    ${START_DIR}/codegen/dll/armvone/xzgetrf.c
    ${START_DIR}/codegen/dll/armvone/xzlascl.c
    ${START_DIR}/codegen/dll/armvone/div.c
    ${START_DIR}/codegen/dll/armvone/armvone_emxutil.c
    $<$<BOOL:${MSVC}>:${START_DIR}/codegen/dll/armvone/armvone.def>)

# Set properties for target "armvone".
set_target_properties(armvone PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH_USE_LINK_PATH TRUE)

# Specify language features required for target "armvone".
target_compile_features(armvone PUBLIC c_std_99)

# Specify compiler preprocessor definitions for target "armvone".
target_compile_definitions(armvone PRIVATE -Dccd_EXPORTS
    -DMODEL=armvone)

# Specify include directories for target "armvone".
target_include_directories(armvone PUBLIC $<BUILD_INTERFACE:${START_DIR}/codegen/dll/armvone>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/codegen/dll/armvone>
    $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include/shared_robotics>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src/ccd>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>)

# Specify library link dependencies for target "armvone". CMake generator 
# expressions are used to create a CMakeLists.txt file that supports 
# multiple platforms with differently named system library dependencies.
target_link_libraries(armvone PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)


###########################################################################
## Target install rules
###########################################################################

# Install shared library for target "armvone"
#  	'RUNTIME' - for Windows .dll files
#  	'LIBRARY' - for shared libs on non DLL platforms
#  	'ARCHIVE' - for DLL import libs on Windows
install(TARGETS armvone
    EXPORT armvoneTargets
    RUNTIME DESTINATION "codegen/dll/armvone"
    LIBRARY DESTINATION "codegen/dll/armvone"
    ARCHIVE DESTINATION "codegen/dll/armvone")

# Write a rule that generates a wrapper around exported targets to 
# preserve tokenization of "special" directories (e.g., MATLAB_ROOT). This 
# avoids hard-coding absolute paths in the CMake file with the code used 
# to import the targets, and avoids errors when include paths that do not 
# exist in the current filesystem are defined, for example, after 
# relocating code using PackNGo.
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/armvone.cmake" [=[include("${CMAKE_CURRENT_LIST_DIR}/armvoneTargets.cmake")]=] \n)
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/armvone.cmake" [=[set(ARMVONE_TOK_INC_DIRS_ALL]=] \n
    [=[    ${MATLAB_ROOT}/extern/include/shared_robotics]=] \n
    [=[    ${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src]=] \n
    [=[    ${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src/ccd]=] \n
    [=[    ${MATLAB_ROOT}/extern/include)]=] \n
    [=[foreach(TOKDIR_LOOP IN LISTS ARMVONE_TOK_INC_DIRS_ALL)]=] \n
    [=[    if(IS_DIRECTORY ${TOKDIR_LOOP})]=] \n
    [=[        list(APPEND ARMVONE_TOK_INC_DIRS ${TOKDIR_LOOP})]=] \n
    [=[    endif()]=] \n
    [=[endforeach()]=] \n
    [=[target_include_directories(armvone::armvone INTERFACE ${ARMVONE_TOK_INC_DIRS})]=] \n)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/armvone.cmake"
    DESTINATION "codegen/dll/armvone/export")

# Generate and install a file that allows the targets generated from this 
# CMakeLists.txt file to be imported into another project.
install(EXPORT armvoneTargets NAMESPACE armvone:: DESTINATION codegen/dll/armvone/export)

###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET armvone POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created SHARED library: $<TARGET_FILE:armvone>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(armvone)
endif()
