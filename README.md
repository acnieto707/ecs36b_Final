# ECS36B Fall 2022 Final - Self-Driving Car 
This program uses JSON-RPC to simulate multiple autonomous vehicles communicating with each other.
## Developers
Hanson Nguyen: 919227725  
Alfredo Nieto: 917137244  
Bryant Gonzalez: 918470625  
Aidan Tongco: 919388431
## How to run
Compile with make
```bash
make
```
Run servers in this order:
1. Left Motorcycle
```bash
./LeftMotorcycleServer
```
2. Right Motorcycle
```bash
./RightMotorcycleServer
```
3. Car
```bash
./CarServer
```
4. To see the decision End Car Server by pressing ENTER on it's active terminal

## Additional Notes
You can also change the intializing variables for each the car, left motorcycle, and right motorcycle, to get different results and final decision.