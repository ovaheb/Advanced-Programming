a.out: main.o tree.o  node.o operators.o operand.o
	g++ -std=c++11 main.o tree.o  node.o operators.o operand.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
tree.o: tree.cpp
	g++ -std=c++11 -c tree.cpp  
node.o: node.cpp
	g++ -std=c++11 -c node.cpp  
operators.o: operators.cpp
	g++ -std=c++11 -c operators.cpp
operand.o: operand.cpp
	g++ -std=c++11 -c operand.cpp 
clean:
	rm -f *.o 

 
