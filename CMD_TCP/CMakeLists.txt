# 在 CMakeLists.txt 文件中添加头文件搜索路径：
include_directories(/home/li/NetworkProgramming/)

project(NetworkProgramming)

add_executable(cmd_client cmd_client.c)
# target_link_libraries(tcpclient NetworkProgramming)

add_executable(cmd_server cmd_server.c)
# target_link_libraries(tcpserver NetworkProgramming)

