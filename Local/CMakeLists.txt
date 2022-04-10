# 在 CMakeLists.txt 文件中添加头文件搜索路径：
include_directories(/home/li/NetworkProgramming/)

project(NetworkProgramming)

# add_executable(unixdataclient unixdataclient.c)
# # target_link_libraries(tcpclient NetworkProgramming)

# add_executable(unixdataserver unixdataserver.c)
# # target_link_libraries(tcpserver NetworkProgramming)

add_executable(unixstreamclient unixstreamclient.c)
# target_link_libraries(tcpclient NetworkProgramming)

add_executable(unixstreamserver unixstreamserver.c)
# target_link_libraries(tcpserver NetworkProgramming)
