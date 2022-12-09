
# Makefile for f2022, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++14
CFLAGS = -g

# LDFLAGS = 	-L/Users/sfwu/vcpkg/installed/arm64-osx/lib -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

LDFLAGS = 	-I/usr/include/jsoncpp -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	ecs36b_Common.h
INC_CL	=	JvTime.h Person.h Thing.h Truck.h Car.h Motorcycle.h Automobile.h
OBJ	=	JvTime.o Person.o Thing.o Truck.o Car.o Motorcycle.o Automobile.o

# rules.
all: 	TruckServer RightMotorcycleServer LeftMotorcycleServer CarServer # hw5server # hw5client

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

hw5client.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5server.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5client.o:		hw5client.cpp hw5client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5client.cpp $(LDFLAGS)

hw5server.o:		hw5server.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5server.cpp $(LDFLAGS)

LeftMotorcycleServer.o:		LeftMotorcycleServer.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) LeftMotorcycleServer.cpp $(LDFLAGS)

RightMotorcycleServer.o:		RightMotorcycleServer.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) RightMotorcycleServer.cpp $(LDFLAGS)

TruckServer.o:		TruckServer.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) TruckServer.cpp $(LDFLAGS)

CarServer.o:		CarServer.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) CarServer.cpp $(LDFLAGS)

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp $(LDFLAGS)

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp $(LDFLAGS)

Person.o:	Person.cpp Person.h $(INC)
	$(CC) -c $(CFLAGS) Person.cpp $(LDFLAGS)

Thing.o:	Thing.cpp Thing.h $(INC)
	$(CC) -c $(CFLAGS) Thing.cpp $(LDFLAGS)

Truck.o:	Truck.cpp Truck.h $(INC)
	$(CC) -c $(CFLAGS) Truck.cpp $(LDFLAGS)

Motorcycle.o:	Motorcycle.cpp Motorcycle.h $(INC)
	$(CC) -c $(CFLAGS) Motorcycle.cpp $(LDFLAGS)

Car.o:	Car.cpp Car.h $(INC)
	$(CC) -c $(CFLAGS) Car.cpp $(LDFLAGS)

Automobile.o:	Automobile.cpp Automobile.h $(INC)
	$(CC) -c $(CFLAGS) Automobile.cpp $(LDFLAGS)

hw5server:	hw5server.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5server hw5server.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

LeftMotorcycleServer:	LeftMotorcycleServer.o ecs36b_JSON.o $(OBJ)
	$(CC) -o LeftMotorcycleServer LeftMotorcycleServer.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

RightMotorcycleServer:	RightMotorcycleServer.o ecs36b_JSON.o $(OBJ)
	$(CC) -o RightMotorcycleServer RightMotorcycleServer.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

TruckServer:	TruckServer.o ecs36b_JSON.o $(OBJ)
	$(CC) -o TruckServer TruckServer.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

CarServer:	CarServer.o ecs36b_JSON.o $(OBJ)
	$(CC) -o CarServer CarServer.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw5client:	hw5client.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5client hw5client.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o *~ core hw5client.h hw5server.h hw5client hw5server LeftMotorcycleServer RightMotorcycleServer TruckServer CarServer


