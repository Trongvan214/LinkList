make: main.cpp node.cpp link_list.cpp
	  g++ -Wall main.cpp node.cpp node.hpp link_list.cpp link_list.hpp -o grocerylist
	  ./grocerylist
