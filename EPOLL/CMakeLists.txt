# 在 CMakeLists.txt 文件中添加头文件搜索路径：
include_directories(/home/li/NetworkProgramming/)

project(NetworkProgramming)

add_executable(epoll01 epoll01.c)
# target_link_libraries(tcpclient NetworkProgramming)

add_executable(epoll_edge-triggered epoll_edge-triggered.c)
# target_link_libraries(tcpclient NetworkProgramming)

add_executable(epoll_level-triggered epoll_level-triggered.c)
# target_link_libraries(tcpclient NetworkProgramming)
