cmake_minimum_required(VERSION 2.8.2)

project(googlebenchmark-download NONE)

include(ExternalProject)
ExternalProject_Add(googlebenchmark-download
                    GIT_REPOSITORY;https://github.com/google/benchmark.git;GIT_TAG;master;UPDATE_DISCONNECTED 1
                    SOURCE_DIR          "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-src"
                    BINARY_DIR          "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
)
