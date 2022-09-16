SET(testname "chessmen")

add_executable(${testname} "ut_pawn.cpp")
target_include_directories(${testname} PRIVATE "${PROJECT_SOURCE_DIR}/src/include")
target_sources(${testname}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/Pawn.cpp
)
set_target_properties(${testname} PROPERTIES LINKER_LANGUAGE CXX)

add_test(pawn ${testname} 0)

set_tests_properties(
	pawn
	PROPERTIES LABELS chessmen)
