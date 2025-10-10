cmake_minimum_required(VERSION 3.14)
project(To_do_List)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)

set(SOURCE_FILES
        Task.cpp
        To_do_List.cpp
)

# Crea una libreria statica "core" con i file sorgente
add_library(core ${SOURCE_FILES})

# Crea l'eseguibile principale
add_executable(To_do_List main.cpp
        Task.h Task.cpp To_do_List.h To_do_List.cpp)


# Collega la libreria "core" all'eseguibile
target_link_libraries(To_do_List core)

add_subdirectory(Test)

