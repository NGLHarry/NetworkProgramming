# 在 CMakeLists.txt 文件中添加头文件搜索路径：
include_directories(/home/li/NetworkProgramming/)

project(NetworkProgramming)

add_executable(streamclient streamclient.c)
# target_link_libraries(tcpclient NetworkProgramming)

add_executable(streamserver streamserver.c)
# target_link_libraries(tcpserver NetworkProgramming)

