# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marcin/Pulpit/Bank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcin/Pulpit/Bank

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/marcin/Pulpit/Bank/CMakeFiles /home/marcin/Pulpit/Bank/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/marcin/Pulpit/Bank/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Bank

# Build rule for target.
Bank: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Bank
.PHONY : Bank

# fast build rule for target.
Bank/fast:
	$(MAKE) -f CMakeFiles/Bank.dir/build.make CMakeFiles/Bank.dir/build
.PHONY : Bank/fast

#=============================================================================
# Target rules for targets named Bank-lib

# Build rule for target.
Bank-lib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Bank-lib
.PHONY : Bank-lib

# fast build rule for target.
Bank-lib/fast:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/build
.PHONY : Bank-lib/fast

#=============================================================================
# Target rules for targets named Bank-ut

# Build rule for target.
Bank-ut: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Bank-ut
.PHONY : Bank-ut

# fast build rule for target.
Bank-ut/fast:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/build
.PHONY : Bank-ut/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) -f googletest-build/googlemock/CMakeFiles/gmock_main.dir/build.make googletest-build/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) -f googletest-build/googlemock/CMakeFiles/gmock.dir/build.make googletest-build/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) -f googletest-build/googletest/CMakeFiles/gtest_main.dir/build.make googletest-build/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) -f googletest-build/googletest/CMakeFiles/gtest.dir/build.make googletest-build/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

# target to build an object file
src/Bank.o:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Bank.o
.PHONY : src/Bank.o

# target to preprocess a source file
src/Bank.i:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Bank.i
.PHONY : src/Bank.i

# target to generate assembly for a file
src/Bank.s:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Bank.s
.PHONY : src/Bank.s

# target to build an object file
src/Kasjer.o:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Kasjer.o
.PHONY : src/Kasjer.o

# target to preprocess a source file
src/Kasjer.i:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Kasjer.i
.PHONY : src/Kasjer.i

# target to generate assembly for a file
src/Kasjer.s:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Kasjer.s
.PHONY : src/Kasjer.s

# target to build an object file
src/Klient.o:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Klient.o
.PHONY : src/Klient.o

# target to preprocess a source file
src/Klient.i:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Klient.i
.PHONY : src/Klient.i

# target to generate assembly for a file
src/Klient.s:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Klient.s
.PHONY : src/Klient.s

# target to build an object file
src/Narzedzia.o:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Narzedzia.o
.PHONY : src/Narzedzia.o

# target to preprocess a source file
src/Narzedzia.i:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Narzedzia.i
.PHONY : src/Narzedzia.i

# target to generate assembly for a file
src/Narzedzia.s:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Narzedzia.s
.PHONY : src/Narzedzia.s

# target to build an object file
src/Osoba.o:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Osoba.o
.PHONY : src/Osoba.o

# target to preprocess a source file
src/Osoba.i:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Osoba.i
.PHONY : src/Osoba.i

# target to generate assembly for a file
src/Osoba.s:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Osoba.s
.PHONY : src/Osoba.s

# target to build an object file
src/Przelew.o:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Przelew.o
.PHONY : src/Przelew.o

# target to preprocess a source file
src/Przelew.i:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Przelew.i
.PHONY : src/Przelew.i

# target to generate assembly for a file
src/Przelew.s:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Przelew.s
.PHONY : src/Przelew.s

# target to build an object file
src/Transakcje.o:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Transakcje.o
.PHONY : src/Transakcje.o

# target to preprocess a source file
src/Transakcje.i:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Transakcje.i
.PHONY : src/Transakcje.i

# target to generate assembly for a file
src/Transakcje.s:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Transakcje.s
.PHONY : src/Transakcje.s

# target to build an object file
src/Zarzadca.o:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Zarzadca.o
.PHONY : src/Zarzadca.o

# target to preprocess a source file
src/Zarzadca.i:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Zarzadca.i
.PHONY : src/Zarzadca.i

# target to generate assembly for a file
src/Zarzadca.s:
	$(MAKE) -f CMakeFiles/Bank-lib.dir/build.make CMakeFiles/Bank-lib.dir/src/Zarzadca.s
.PHONY : src/Zarzadca.s

# target to build an object file
src/main.o:
	$(MAKE) -f CMakeFiles/Bank.dir/build.make CMakeFiles/Bank.dir/src/main.o
.PHONY : src/main.o

# target to preprocess a source file
src/main.i:
	$(MAKE) -f CMakeFiles/Bank.dir/build.make CMakeFiles/Bank.dir/src/main.i
.PHONY : src/main.i

# target to generate assembly for a file
src/main.s:
	$(MAKE) -f CMakeFiles/Bank.dir/build.make CMakeFiles/Bank.dir/src/main.s
.PHONY : src/main.s

# target to build an object file
tests/BankTests.o:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/BankTests.o
.PHONY : tests/BankTests.o

# target to preprocess a source file
tests/BankTests.i:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/BankTests.i
.PHONY : tests/BankTests.i

# target to generate assembly for a file
tests/BankTests.s:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/BankTests.s
.PHONY : tests/BankTests.s

# target to build an object file
tests/NarzedziaTests.o:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/NarzedziaTests.o
.PHONY : tests/NarzedziaTests.o

# target to preprocess a source file
tests/NarzedziaTests.i:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/NarzedziaTests.i
.PHONY : tests/NarzedziaTests.i

# target to generate assembly for a file
tests/NarzedziaTests.s:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/NarzedziaTests.s
.PHONY : tests/NarzedziaTests.s

# target to build an object file
tests/ZarzadcaTests.o:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/ZarzadcaTests.o
.PHONY : tests/ZarzadcaTests.o

# target to preprocess a source file
tests/ZarzadcaTests.i:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/ZarzadcaTests.i
.PHONY : tests/ZarzadcaTests.i

# target to generate assembly for a file
tests/ZarzadcaTests.s:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/ZarzadcaTests.s
.PHONY : tests/ZarzadcaTests.s

# target to build an object file
tests/test_main.o:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/test_main.o
.PHONY : tests/test_main.o

# target to preprocess a source file
tests/test_main.i:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/test_main.i
.PHONY : tests/test_main.i

# target to generate assembly for a file
tests/test_main.s:
	$(MAKE) -f CMakeFiles/Bank-ut.dir/build.make CMakeFiles/Bank-ut.dir/tests/test_main.s
.PHONY : tests/test_main.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... install"
	@echo "... Bank"
	@echo "... Bank-lib"
	@echo "... list_install_components"
	@echo "... Bank-ut"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... gmock_main"
	@echo "... gmock"
	@echo "... gtest_main"
	@echo "... gtest"
	@echo "... src/Bank.o"
	@echo "... src/Bank.i"
	@echo "... src/Bank.s"
	@echo "... src/Kasjer.o"
	@echo "... src/Kasjer.i"
	@echo "... src/Kasjer.s"
	@echo "... src/Klient.o"
	@echo "... src/Klient.i"
	@echo "... src/Klient.s"
	@echo "... src/Narzedzia.o"
	@echo "... src/Narzedzia.i"
	@echo "... src/Narzedzia.s"
	@echo "... src/Osoba.o"
	@echo "... src/Osoba.i"
	@echo "... src/Osoba.s"
	@echo "... src/Przelew.o"
	@echo "... src/Przelew.i"
	@echo "... src/Przelew.s"
	@echo "... src/Transakcje.o"
	@echo "... src/Transakcje.i"
	@echo "... src/Transakcje.s"
	@echo "... src/Zarzadca.o"
	@echo "... src/Zarzadca.i"
	@echo "... src/Zarzadca.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... tests/BankTests.o"
	@echo "... tests/BankTests.i"
	@echo "... tests/BankTests.s"
	@echo "... tests/NarzedziaTests.o"
	@echo "... tests/NarzedziaTests.i"
	@echo "... tests/NarzedziaTests.s"
	@echo "... tests/ZarzadcaTests.o"
	@echo "... tests/ZarzadcaTests.i"
	@echo "... tests/ZarzadcaTests.s"
	@echo "... tests/test_main.o"
	@echo "... tests/test_main.i"
	@echo "... tests/test_main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

