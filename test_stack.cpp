#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <deque>

#include "stack.hpp"
int main()
{
	std::cout << "===TEST CONSTRUCTOR===\n";
	{
		std::cout << "STD:\n";
		std::deque<int> mydeque (3,100);
		std::vector<int> myvector (2,200);
		std::stack<int> first;
		std::stack<int> second (mydeque);
		std::stack<int,std::vector<int> > third;
		std::stack<int,std::vector<int> > fourth (myvector);
		std::cout << "size of first: " << first.size() << '\n';
  		std::cout << "size of second: " << second.size() << '\n';
  		std::cout << "size of third: " << third.size() << '\n';
  		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	{
		std::cout << "FT:\n";
		ft::vector<int> mydeque (3,100);
		std::vector<int> myvector (2,200);
		ft::stack<int> first;
		ft::stack<int> second (mydeque);
		ft::stack<int,std::vector<int> > third;
		ft::stack<int,std::vector<int> > fourth (myvector);
		std::cout << "size of first: " << first.size() << '\n';
  		std::cout << "size of second: " << second.size() << '\n';
  		std::cout << "size of third: " << third.size() << '\n';
  		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	std::cout << "===TEST EMPTY, PUSH, TOP, POP, SIZE===\n";
	{
		std::cout << "STD:\n";
		std::stack<int> mystack;
  		int sum (0);
		for (int i=1;i<=10;i++) mystack.push(i);
		std::cout << "size: " << mystack.size() << '\n';
		while (!mystack.empty())
  		{
     		sum += mystack.top();
     		mystack.pop();
  		}
		std::cout << "total: " << sum << '\n';
	}
	{
		std::cout << "FT:\n";
		ft::stack<int> mystack;
  		int sum (0);
		for (int i=1;i<=10;i++) mystack.push(i);
		std::cout << "size: " << mystack.size() << '\n';
		while (!mystack.empty())
  		{
     		sum += mystack.top();
     		mystack.pop();
  		}
		std::cout << "total: " << sum << '\n';
	}
	std::cout << "===TEST OPERATOR===\n";
	{
		std::cout << "STD:\n";
		std::string str1 = "Ab";
		std::string str2 = "AB";
		std::stack<char, std::string > stack1(str1);
		std::stack<char, std::string > stack2(str2);
		
		if (stack1 > stack2)
			std::cout << str1 << " > " << str2 << "\n";
		else
			std::cout << str1 <<  " <= " << str2 << "\n";
		
		if (stack1 == stack2)
			std::cout << str1 << " == " << str2 << "\n";
		else
			std::cout << str1 <<  " != " << str2 << "\n";
		
		if (stack1 != stack2)
			std::cout << str1 << " != " << str2 << "\n";
		else
			std::cout << str1 <<  " == " << str2 << "\n";
		
		if (stack1 < stack2)
			std::cout << str1 << " < " << str2 << "\n";
		else
			std::cout << str1 <<  " >= " << str2 << "\n";
	}
	{
		std::cout << "FT:\n";
		std::string str1 = "Ab";
		std::string str2 = "AB";
		ft::stack<char, std::string > stack1(str1);
		ft::stack<char, std::string > stack2(str2);
		
		if (stack1 > stack2)
			std::cout << str1 << " > " << str2 << "\n";
		else
			std::cout << str1 <<  " <= " << str2 << "\n";
		
		if (stack1 == stack2)
			std::cout << str1 << " == " << str2 << "\n";
		else
			std::cout << str1 <<  " != " << str2 << "\n";
		
		if (stack1 != stack2)
			std::cout << str1 << " != " << str2 << "\n";
		else
			std::cout << str1 <<  " == " << str2 << "\n";
		
		if (stack1 < stack2)
			std::cout << str1 << " < " << str2 << "\n";
		else
			std::cout << str1 <<  " >= " << str2 << "\n";
	}
	return (0);
}