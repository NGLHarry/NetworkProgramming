# 在 CMakeLists.txt 文件中添加头文件搜索路径：
include_directories(/home/li/NetworkProgramming/)

project(NetworkProgramming)

# add_executable(pthread_hello pthread_hello.c)
# target_link_libraries(pthread_hello pthread)

# add_executable(pthread_detach pthread_detach.c echo.c)
# target_link_libraries(pthread_detach pthread)

add_executable(pthread_threadpool pthread_threadpool.c  echo.c)
target_link_libraries(pthread_threadpool pthread)