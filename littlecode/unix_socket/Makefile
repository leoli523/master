all:server client

server:
	gcc -o server local_s.c

client:
	gcc -o client local_c.c

clean:
	-rm ./server;
	-rm ./client;
	-rm ./server.sock;
	-rm ./client.sock;
