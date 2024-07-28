.PHONY:all
all : udp_server udp_client
udp_server:Main.cc
	g++ -o $@  $^ -std=c++14
udp_client:UdpClient.cc
	g++ -o $@  $^ -std=c++14
.PHONY:clean
clean:
	rm -f udp_server udp_client