a.out:main.o utrello_interface.o  connector.o list.o user.o task.o
	g++ -std=c++11 main.o utrello_interface.o  connector.o list.o user.o task.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
utrello_interface.o: utrello_interface.cpp
	g++ -std=c++11 -c utrello_interface.cpp  
connector.o: connector.cpp
	g++ -std=c++11 -c connector.cpp  
list.o: list.cpp
	g++ -std=c++11 -c list.cpp
user.o: user.cpp
	g++ -std=c++11 -c user.cpp 
task.o: task.cpp
	g++ -std=c++11 -c task.cpp  
clean:
	rm -f *.o 

 
