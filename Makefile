all: client receive
client:client.c encoder.c keyboard.c receive.c
	gcc -c client.c 
	gcc -c receive.c
	gcc -c encoder.c
	gcc -c keyboard.c
	ar -rc encoder.a encoder.o
	ar -rc keyboard.a keyboard.o
	gcc -o client client.o encoder.a keyboard.a
	gcc -o receive receive.o encoder.a keyboard.a
clean:
	rm -f *.o *.a
