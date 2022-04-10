# 在 CMakeLists.txt 文件中添加头文件搜索路径：
include_directories(/home/li/NetworkProgramming/)

project(NetworkProgramming)

add_executable(pingclient pingclient.c)
# target_link_libraries(tcpclient NetworkProgramming)

add_executable(pingserver pingserver.c)
# target_link_libraries(tcpserver NetworkProgramming)
