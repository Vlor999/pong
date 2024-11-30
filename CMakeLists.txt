cmake_minimum_required(VERSION 3.10)

project(ping_pong)
enable_testing()


find_package(SDL2 REQUIRED)
set(SDL_INCLUDE_CFLAGS -I${SDL2_INCLUDE_DIR})


# Debug build

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${SDL_INCLUDE_CFLAGS} -Wall  -Wextra -Werror -std=gnu17 -lpthread -lncurses")

#########
# Vous devez editer les lignes suivantes pour y mettre vos logins
#########
set(VARIANTE_LOGINS log log log)

#########

list(SORT VARIANTE_LOGINS)
if (VARIANTE_LOGINS MATCHES "login[123]")
  message(FATAL_ERROR "** ERREUR **: Vous devez modifier CMakeLists.txt pour y mettre vos logins")
endif()

#########

##
# Si vous utilisez plusieurs fichiers, en plus de shmem_pong.c, pour votre
# shell il faut les ajouter ici
##
add_executable(ping_pong src/ping_pong.c)
target_link_libraries(ping_pong ${SDL2_LIBRARIES} -lrt -lpthread -lncurses)

