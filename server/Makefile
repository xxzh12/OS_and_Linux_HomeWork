export CPLUS_INCLUDE_PATH = /home/xxzh-3/HomeWork8/OS_and_Linux_HomeWork/server/include:$CPLUS_INCLUDE_PATH
cc = g++
OBJ = ./out/main.o ./out/DataProcesser.o ./out/HeadData.o ./out/Online.o

main:$(OBJ)
	$(cc) $(OBJ) -o main

./out/main.o: main.cpp
	$(cc) -c main.cpp -o ./out/main.o

./out/DataProcesser.o: ./DataProcesser/DataProcesser.cpp
	$(cc) -c ./DataProcesser/DataProcesser.cpp -o ./out/DataProcesser.o

./out/HeadData.o: ./ProtocolHead/HeadData.cpp
	$(cc) -c ./ProtocolHead/HeadData.cpp -o ./out/HeadData.o

./out/Online.o: ./Online/Online.cpp
	$(cc) -c ./Online/Online.cpp -o ./out/Online.o

.PHONY:clean
clean:
	rm -f $(OBJ) main