
if(NOT "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-download/googlebenchmark-download-prefix/src/googlebenchmark-download-stamp/googlebenchmark-download-gitinfo.txt" IS_NEWER_THAN "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-download/googlebenchmark-download-prefix/src/googlebenchmark-download-stamp/googlebenchmark-download-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-download/googlebenchmark-download-prefix/src/googlebenchmark-download-stamp/googlebenchmark-download-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/google/benchmark.git" "googlebenchmark-src"
    WORKING_DIRECTORY "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/google/benchmark.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout master --
  WORKING_DIRECTORY "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-download/googlebenchmark-download-prefix/src/googlebenchmark-download-stamp/googlebenchmark-download-gitinfo.txt"
    "/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-download/googlebenchmark-download-prefix/src/googlebenchmark-download-stamp/googlebenchmark-download-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/rrodriguez/2021-2/compiladores/clases/semana-4/cs3402-lab1/build/googlebenchmark-download/googlebenchmark-download-prefix/src/googlebenchmark-download-stamp/googlebenchmark-download-gitclone-lastrun.txt'")
endif()

