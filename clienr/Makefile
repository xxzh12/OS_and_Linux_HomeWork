all: client
client:client.c encoder.c
	gcc -c client.c 
	gcc -c encoder.c
	ar -rc encoder.a encoder.o
	gcc -o client client.o encoder.a
clean:
	rm -f *.o *.a
