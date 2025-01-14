include("${CMAKE_CURRENT_LIST_DIR}/armvoneTargets.cmake")
set(ARMVONE_TOK_INC_DIRS_ALL
    ${MATLAB_ROOT}/extern/include/shared_robotics
    ${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src
    ${MATLAB_ROOT}/toolbox/shared/robotics/externalDependency/libccd/src/ccd
    ${MATLAB_ROOT}/extern/include)
foreach(TOKDIR_LOOP IN LISTS ARMVONE_TOK_INC_DIRS_ALL)
    if(IS_DIRECTORY ${TOKDIR_LOOP})
        list(APPEND ARMVONE_TOK_INC_DIRS ${TOKDIR_LOOP})
    endif()
endforeach()
target_include_directories(armvone::armvone INTERFACE ${ARMVONE_TOK_INC_DIRS})
