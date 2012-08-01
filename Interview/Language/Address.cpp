/* Address.cpp */

#include <iostream>
#include <vector>

class test_addr {
public:
	int *a;
};

int main()
{
	int *a[10];
	std::vector<int> b(10, 0);	
	test_addr c;	

	std::cout << "a is " << a << std::endl;
	std::cout << "&a is " << &a << std::endl;
	std::cout << "&a[0] is " << &a[0] << std::endl;
	
	std::cout << std::endl;

	// std::cout << "b is " << b << std::endl;
	std::cout << "&b is " << &b << std::endl;
	std::cout << "&b[0] is " << &b[0] << std::endl;
	
	// just as below
	std::cout << "&c is" << &c << std::endl;
	std::cout << "&c.a is" << c.a << std::endl;
	return 0;
}

/* explaination 
      
    &vec-----
	  *p  ---> &vec[0]-----
	-----      	  vec[0]
                   	  -----
	-----      	  vec[1]
                   	  -----
	----- 		    ^
	  ^ 		    |
	  |		  heap
	stack		
*/
