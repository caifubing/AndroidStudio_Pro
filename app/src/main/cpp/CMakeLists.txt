# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)


set(distribution_DIR ${CMAKE_SOURCE_DIR}/../../../)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.



add_library(PocoFoundation SHARED IMPORTED)
set_target_properties(PocoFoundation PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}libs/${ANDROID_ABI}/libPocoFoundation.so)

add_library(PocoNet SHARED IMPORTED)
set_target_properties(PocoNet PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}libs/${ANDROID_ABI}/libPocoNet.so)

add_library(Demo SHARED IMPORTED)
set_target_properties(Demo PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}libs/${ANDROID_ABI}/libDemo.so
        )
# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp )

target_include_directories(native-lib PRIVATE
        ${distribution_DIR}/include)

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
        Demo
        PocoFoundation
        PocoNet

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )