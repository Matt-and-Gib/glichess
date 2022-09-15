#Unit tests for Chessmen

SET(testname "chessmen")

add_executable(${testname} "ut_pawn.cpp")
target_include_directories(${testname} PRIVATE "${PROJECT_SOURCE_DIR}/src/include")
set_target_properties(${testname} PROPERTIES LINKER_LANGUAGE CXX)

add_test(pawn ${testname} 0)

set_tests_properties(
	pawn
	PROPERTIES LABELS chessmen)

#add_test(success_test ${testname} 0)
#set_tests_properties(success_test PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

#add_test(fail_test ${testname} 1)
#set_tests_properties(fail_test PROPERTIES WILL_FAIL TRUE)

#add_test(fail_test_output ${testname} 1)
#set_tests_properties(fail_test_output PROPERTIES PASS_REGULAR_EXPRESSION "FAIL")
