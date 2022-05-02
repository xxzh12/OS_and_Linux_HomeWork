all: client
client:client.cpp encoder.cpp keyboard.cpp
	gcc -c client.cpp 
	gcc -c encoder.cpp
	gcc -c keyboard.cpp
	ar -rc encoder.a encoder.o
	ar -rc keyboard.a keyboard.o
	gcc -o client client.o encoder.a keyboard.a
clean:
	rm -f *.o *.a
