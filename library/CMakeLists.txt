cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
		src/model/Uczen.cpp
		include/model/Uczen.h
		src/repositories/ZajeciaRepozytorium.cpp
		include/repositories/ZajeciaRepozytorium.h
		include/typedefs.h
		src/model/Jezyki.cpp
		include/model/Jezyki.h
		src/model/PozostalePrzedmioty.cpp
		include/model/PozostalePrzedmioty.h
		src/model/Przedmiot.cpp
		include/model/Przedmiot.h
		src/model/Zajecia.cpp
		include/model/Zajecia.h
		src/repositories/UczenRepozytorium.cpp
		include/repositories/UczenRepozytorium.h
		../program/src/main.cpp
        src/managers/ZarzadcaUczniow.cpp
		include/managers/ZarzadcaUczniow.h
		src/managers/ZarzadcaZajec.cpp
		include/managers/ZarzadcaZajec.h

)

# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing()
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)
find_package (Boost 1.60.0 COMPONENTS "date_time" REQUIRED)

include_directories(
		${CMAKE_CURRENT_SOURCE_DIR}/include
		${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
		test/master.cpp
		test/ZajeciaTest.cpp
		test/PrzedmiotTest.cpp
		test/UczenTest.cpp
        test/RepozytoriumUczniaTest.cpp
		test/ZarzadcaUczniowTest.cpp
		test/ZarzadcaZajecTest.cpp
		test/RepozytoriumZajecTest.cpp

) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTester ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTester
		Library
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

#dodaj test LibraryTest. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest LibraryTester
		--report_level=detailed
		--log_level=all
		--color_output=yes
)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
		${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR})