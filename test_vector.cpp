#include <vector>
#include <iostream>
#include <fstream>

#include "assert.hpp"
#include "vector.hpp"

void TestConstructor()
{
	std::vector<int> std_first;
	ft::vector<int> ft_first;
	ASSERT_EQUAL(std_first, ft_first);                           
  	std::vector<int> std_second (4, 100);
	std::vector<int> ft_second (4, 100);
	ASSERT_EQUAL(std_second, ft_second);
  	std::vector<int> std_third (std_second.begin(), std_second.end());
	ft::vector<int> ft_third (ft_second.begin(), ft_second.end());
	ASSERT_EQUAL(std_third, ft_third);
  	std::vector<int> std_fourth (std_third);
	ft::vector<int> ft_fourth (ft_third);
	ASSERT_EQUAL(std_fourth, ft_fourth);
	int myints[] = {16,2,77,29};
  	std::vector<int> std_fifth (myints, myints + sizeof(myints) / sizeof(int) );
	ft::vector<int> ft_fifth (myints, myints + sizeof(myints) / sizeof(int) );
	ASSERT_EQUAL(std_fifth, ft_fifth);
}

void TestOperatorAssignment()
{
	std::vector<int> std_foo (3,0);
  	std::vector<int> std_bar (5,0);
	std_bar = std_foo;
  	std_foo = std::vector<int>();
	
	ft::vector<int> ft_foo (3,0);
  	ft::vector<int> ft_bar (5,0);
	ft_bar = ft_foo;
  	ft_foo = ft::vector<int>();
	ASSERT_EQUAL(std_bar, ft_bar);
	ASSERT_EQUAL(std_foo, ft_foo);
}

void TestCapacity()
{
	std::vector<int> std_myints;
	ft::vector<int> ft_myints;
	ASSERT_EQUAL(std_myints, ft_myints);
	ASSERT_EQUAL(std_myints.size(), ft_myints.size());
	ASSERT_EQUAL(std_myints.empty(), ft_myints.empty());
  	for (int i=0; i<10; i++) std_myints.push_back(i);
	for (int i=0; i<10; i++) ft_myints.push_back(i);
	ASSERT_EQUAL(std_myints, ft_myints);
	ASSERT_EQUAL(std_myints.size(), ft_myints.size());
	ASSERT_EQUAL(std_myints.empty(), ft_myints.empty());
	std_myints.insert (std_myints.end(), 10, 100);
	ft_myints.insert (ft_myints.end(), 10, 100);
	ASSERT_EQUAL(std_myints, ft_myints);
	ASSERT_EQUAL(std_myints.size(), ft_myints.size());
 	std_myints.pop_back();
	ft_myints.pop_back();
	ASSERT_EQUAL(std_myints, ft_myints);
	ASSERT_EQUAL(std_myints.size(), ft_myints.size());

	std::vector<int> std_myvector;
	for (int i=0; i<100; i++) std_myvector.push_back(i);
	ft::vector<int> ft_myvector;
	for (int i=0; i<100; i++) ft_myvector.push_back(i);
	ASSERT_EQUAL(std_myvector, ft_myvector);
	ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
	ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	ASSERT_EQUAL(std_myvector.max_size(), ft_myvector.max_size());

	std_myvector.resize(5);
	ft_myvector.resize(5);
	ASSERT_EQUAL(std_myvector, ft_myvector);
	ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
	ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	ASSERT_EQUAL(std_myvector.max_size(), ft_myvector.max_size());
	std_myvector.resize(8,100);
	ft_myvector.resize(8,100);
	ASSERT_EQUAL(std_myvector, ft_myvector);
	ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
	ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	ASSERT_EQUAL(std_myvector.max_size(), ft_myvector.max_size());
	std_myvector.resize(12);
	ft_myvector.resize(12);
	ASSERT_EQUAL(std_myvector, ft_myvector);
	ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
	ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	ASSERT_EQUAL(std_myvector.max_size(), ft_myvector.max_size());

	std_myvector.reserve(1);
	ft_myvector.reserve(1);
	ASSERT_EQUAL(std_myvector, ft_myvector);
	ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
	ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	ASSERT_EQUAL(std_myvector.max_size(), ft_myvector.max_size());

	std_myvector.reserve(1000);
	ft_myvector.reserve(1000);
	ASSERT_EQUAL(std_myvector, ft_myvector);
	ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
	ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	ASSERT_EQUAL(std_myvector.max_size(), ft_myvector.max_size());
	{
		std::vector<int>::size_type std_sz;
		ft::vector<int>::size_type ft_sz;
		std::vector<int> std_foo;
		ft::vector<int> ft_foo;
  		std_sz = std_foo.capacity();
		ft_sz = ft_foo.capacity();
  		for (int i=0; i<100; ++i)
		{
    		std_foo.push_back(i);
			ft_foo.push_back(i);
    		if (std_sz!=std_foo.capacity())
      			std_sz = std_foo.capacity();
			if (ft_sz!=ft_foo.capacity())
      			ft_sz = ft_foo.capacity();
          	ASSERT_EQUAL(std_sz, ft_sz);
			ASSERT_EQUAL(std_foo, ft_foo);
			ASSERT_EQUAL(std_foo.capacity(), ft_foo.capacity());
  		}
		std::vector<int> std_bar;
		ft::vector<int> ft_bar;
  		std_sz = std_bar.capacity();
		ft_sz = ft_bar.capacity();
  		std_bar.reserve(100);
		ft_bar.reserve(100); 
  		for (int i=0; i<100; ++i) {
    		std_bar.push_back(i);
			ft_bar.push_back(i);
    		if (std_sz!=std_bar.capacity())
      			std_sz = std_bar.capacity();
			if (ft_sz!=ft_bar.capacity())
      			ft_sz = ft_bar.capacity();
			ASSERT_EQUAL(std_sz, ft_sz);
			ASSERT_EQUAL(std_bar, ft_bar);
			ASSERT_EQUAL(std_bar.capacity(), ft_bar.capacity());
  		}
	}

}

void TestModifiers()
{
	{
	std::vector<int> std_first;
  	std::vector<int> std_second;
  	std::vector<int> std_third;
	ft::vector<int> ft_first;
  	ft::vector<int> ft_second;
  	ft::vector<int> ft_third;

  	std_first.assign (7,100);
	ft_first.assign (7,100);
	ASSERT_EQUAL(std_first, ft_first);
	ASSERT_EQUAL(std_first.size(), ft_first.size());
	ASSERT_EQUAL(std_first.capacity(), ft_first.capacity());

	std::vector<int>::iterator std_it;
	ft::vector<int>::iterator ft_it;
  	std_it = std_first.begin()+1;
	ft_it = ft_first.begin()+1;
	
	std_second.assign(std_it, std_first.end()-1);
	ft_second.assign(ft_it, ft_first.end()-1);
	ASSERT_EQUAL(std_second, ft_second);
	ASSERT_EQUAL(std_second.size(), ft_second.size());
	ASSERT_EQUAL(std_second.capacity(), ft_second.capacity());
	
	int myints[] = {1776,7,4};
  	std_third.assign (myints,myints+3);
	ft_third.assign (myints,myints+3);
	ASSERT_EQUAL(std_third, ft_third);
	ASSERT_EQUAL(std_third.size(), ft_third.size());
	ASSERT_EQUAL(std_third.capacity(), ft_third.capacity());

	std::vector<int> std_myvector;
	ft::vector<int> ft_myvector;
	for (int i=1; i<=10; i++) std_myvector.push_back(i);
	for (int i=1; i<=10; i++) ft_myvector.push_back(i);
	std_myvector.erase (std_myvector.begin()+5);
	ft_myvector.erase (ft_myvector.begin()+5);
	ASSERT_EQUAL(std_myvector, ft_myvector);
	ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
	ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	std_myvector.erase (std_myvector.begin(),std_myvector.begin()+3);
	ft_myvector.erase (ft_myvector.begin(),ft_myvector.begin()+3);
	ASSERT_EQUAL(std_myvector, ft_myvector);
	ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
	ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	}
	{
		std::vector<int> std_foo (3,100);   
  		std::vector<int> std_bar (5,200);
		ft::vector<int> ft_foo (3,100);   
  		ft::vector<int> ft_bar (5,200);
		ASSERT_EQUAL(std_bar, ft_bar);
		ASSERT_EQUAL(std_foo, ft_foo);
		ASSERT_EQUAL(std_bar.size(), ft_bar.size());
		ASSERT_EQUAL(std_foo.size(), ft_foo.size());
		ASSERT_EQUAL(std_bar.capacity(), ft_bar.capacity());
		ASSERT_EQUAL(std_foo.capacity(), ft_foo.capacity());
		std_foo.swap(std_bar);
		ft_foo.swap(ft_bar);
		ASSERT_EQUAL(std_bar, ft_bar);
		ASSERT_EQUAL(std_foo, ft_foo);
		ASSERT_EQUAL(std_bar.size(), ft_bar.size());
		ASSERT_EQUAL(std_foo.size(), ft_foo.size());
		ASSERT_EQUAL(std_bar.capacity(), ft_bar.capacity());
		ASSERT_EQUAL(std_foo.capacity(), ft_foo.capacity());
	}
	{
		std::vector<int> std_myvector;
  		std_myvector.push_back (100);
  		std_myvector.push_back (200);
		ft::vector<int> ft_myvector;
  		ft_myvector.push_back (100);
  		ft_myvector.push_back (200);
		ASSERT_EQUAL(std_myvector, ft_myvector);
		ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
		ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
		std_myvector.clear();
  		std_myvector.push_back (1101);
		ft_myvector.clear();
  		ft_myvector.push_back (1101);
		ASSERT_EQUAL(std_myvector, ft_myvector);
		ASSERT_EQUAL(std_myvector.size(), ft_myvector.size());
		ASSERT_EQUAL(std_myvector.capacity(), ft_myvector.capacity());
	}
	
}

void TestNonmemberFunctionOverloads()
{
	std::vector<int> std_foo (3,100);   
  	std::vector<int> std_bar (2,200);
	ft::vector<int> ft_foo (3,100);   
  	ft::vector<int> ft_bar (2,200);
	
	ASSERT_EQUAL((std_foo == std_bar), (ft_foo == ft_bar));
	ASSERT_EQUAL((std_foo != std_bar), (ft_foo != ft_bar));
	ASSERT_EQUAL((std_foo > std_bar), (ft_foo > ft_bar));
	ASSERT_EQUAL((std_foo < std_bar), (ft_foo < ft_bar));
	ASSERT_EQUAL((std_foo <= std_bar), (ft_foo <= ft_bar));
	ASSERT_EQUAL((std_foo >= std_bar), (ft_foo >= ft_bar));
}

void TestIterator()
{
	std::vector<int> std_myvector;
  	std_myvector.push_back (100);
  	std_myvector.push_back (200);
	std_myvector.push_back (300);
	ft::vector<int> ft_myvector;
  	ft_myvector.push_back (100);
  	ft_myvector.push_back (200);
	ft_myvector.push_back (300);
	
	{
		std::vector<int>::iterator std_it = std_myvector.begin();
		ft::vector<int>::iterator ft_it = ft_myvector.begin();
		ASSERT_EQUAL(*std_it, *ft_it);
		std_it++;
		ft_it++;
		ASSERT_EQUAL(*std_it, *ft_it);
		std_it++;
		ft_it++;
		ASSERT_EQUAL(*std_it, *ft_it);
		//std::cout << *std_it << " " << *ft_it << "\n";
	}
	{
		std::vector<int>::iterator std_it = std_myvector.end();
		ft::vector<int>::iterator ft_it = ft_myvector.end();
		std_it--;
		ft_it--;
		ASSERT_EQUAL(*std_it, *ft_it);
		std_it--;
		ft_it--;
		ASSERT_EQUAL(*std_it, *ft_it);
		std_it--;
		ft_it--;
		ASSERT_EQUAL(*std_it, *ft_it);
		//std::cout << *std_it << " " << *ft_it << "\n";
	}

	{
		std::vector<int>::reverse_iterator std_it = std_myvector.rbegin();
		ft::vector<int>::reverse_iterator ft_it = ft_myvector.rbegin();
		//std::cout << *std_it << " " << *ft_it << "\n";
		ASSERT_EQUAL(*std_it, *ft_it);
		std_it++;
		ft_it++;
		//std::cout << *std_it << " " << *ft_it << "\n";
		ASSERT_EQUAL(*std_it, *ft_it);
		std_it++;
		ft_it++;
		//std::cout << *std_it << " " << *ft_it << "\n";
		ASSERT_EQUAL(*std_it, *ft_it);
	}
	{
		std::vector<int>::reverse_iterator std_it = std_myvector.rend();
		ft::vector<int>::reverse_iterator ft_it = ft_myvector.rend();
		std_it--;
		ft_it--;
		//std::cout << *std_it << " " << *ft_it << "\n";
		ASSERT_EQUAL(*std_it, *ft_it);
		std_it--;
		ft_it--;
		//std::cout << *std_it << " " << *ft_it << "\n";
		ASSERT_EQUAL(*std_it, *ft_it);
		std_it--;
		ft_it--;
		//std::cout << *std_it << " " << *ft_it << "\n";
		ASSERT_EQUAL(*std_it, *ft_it);
	}
	{
		std::vector<int>::reverse_iterator std_it = std_myvector.rend();
		ft::vector<int>::reverse_iterator ft_it = ft_myvector.rend();
		std_it -= 2;
		ft_it -= 2;
		//std::cout << *std_it << " " << *ft_it << "\n";
		ASSERT_EQUAL(*std_it, *ft_it);
	}
	{
		std::vector<int>::reverse_iterator std_it = std_myvector.rbegin();
		ft::vector<int>::reverse_iterator ft_it = ft_myvector.rbegin();
		std_it += 2;
		ft_it += 2;
		//std::cout << *std_it << " " << *ft_it << "\n";
		ASSERT_EQUAL(*std_it, *ft_it);
	}
	{
		std::vector<int>::reverse_iterator std_it = std_myvector.rbegin();
		ft::vector<int>::reverse_iterator ft_it = ft_myvector.rbegin();
		//std::cout << std_it[1] << " " << ft_it[1] << "\n";
		ASSERT_EQUAL(std_it[1], ft_it[1]);
	}
	{
		std::vector<int>::reverse_iterator std_it = std_myvector.rbegin();
		ft::vector<int>::reverse_iterator ft_it = ft_myvector.rbegin();
		//std::cout << std_it[1] << " " << ft_it[1] << "\n";
		ASSERT_EQUAL(std_it[1], ft_it[1]);
	}
	{
		std::vector<int>::reverse_iterator std_it = std_myvector.rend();
		ft::vector<int>::reverse_iterator ft_it = ft_myvector.rend();
		std_it = std_it - 3;
		ft_it = ft_it - 3;
		//std::cout << *std_it << " " << *ft_it<< "\n";
		ASSERT_EQUAL(std_it[0], ft_it[0]);
	}
	{
		std::vector<int>::iterator std_it = std_myvector.end();
		ft::vector<int>::iterator ft_it = ft_myvector.end();
		std_it = std_it - 3;
		ft_it = ft_it - 3;
		//std::cout << *std_it << " " << *ft_it<< "\n";
		ASSERT_EQUAL(std_it[0], ft_it[0]);
	}
	{
		std::vector<int>::iterator std_it1 = std_myvector.begin();
		std::vector<int>::iterator std_it2 = std_myvector.end() - 1;
		ft::vector<int>::iterator ft_it1 = ft_myvector.begin();
		ft::vector<int>::iterator ft_it2 = ft_myvector.end() - 1;
		ASSERT_EQUAL((std_it1 == std_it2), (ft_it1 == ft_it2));
		ASSERT_EQUAL((std_it1 != std_it2), (ft_it1 != ft_it2));
		ASSERT_EQUAL((std_it1 > std_it2), (ft_it1 > ft_it2));
		ASSERT_EQUAL((std_it1 < std_it2), (ft_it1 < ft_it2));
		ASSERT_EQUAL((std_it1 >= std_it2), (ft_it1 >= ft_it2));
		ASSERT_EQUAL((std_it1 <= std_it2), (ft_it1 <= ft_it2));
		std_it2 = std_it1;
		ft_it2 = ft_it1;
		ASSERT_EQUAL((std_it1 == std_it2), (ft_it1 == ft_it2));
		ASSERT_EQUAL((std_it1 != std_it2), (ft_it1 != ft_it2));
		ASSERT_EQUAL((std_it1 > std_it2), (ft_it1 > ft_it2));
		ASSERT_EQUAL((std_it1 < std_it2), (ft_it1 < ft_it2));
		ASSERT_EQUAL((std_it1 >= std_it2), (ft_it1 >= ft_it2));
		ASSERT_EQUAL((std_it1 <= std_it2), (ft_it1 <= ft_it2));
	}
	{
		std::vector<int>::reverse_iterator std_it1 = std_myvector.rbegin();
		std::vector<int>::reverse_iterator std_it2 = std_myvector.rend() - 1;
		ft::vector<int>::reverse_iterator ft_it1 = ft_myvector.rbegin();
		ft::vector<int>::reverse_iterator ft_it2 = ft_myvector.rend() - 1;
		ASSERT_EQUAL((std_it1 == std_it2), (ft_it1 == ft_it2));
		ASSERT_EQUAL((std_it1 != std_it2), (ft_it1 != ft_it2));
		ASSERT_EQUAL((std_it1 > std_it2), (ft_it1 > ft_it2));
		ASSERT_EQUAL((std_it1 < std_it2), (ft_it1 < ft_it2));
		ASSERT_EQUAL((std_it1 >= std_it2), (ft_it1 >= ft_it2));
		ASSERT_EQUAL((std_it1 <= std_it2), (ft_it1 <= ft_it2));
		std_it1 = std_it2;
		ft_it1 = ft_it2;
		ASSERT_EQUAL((std_it1 == std_it2), (ft_it1 == ft_it2));
		ASSERT_EQUAL((std_it1 != std_it2), (ft_it1 != ft_it2));
		ASSERT_EQUAL((std_it1 > std_it2), (ft_it1 > ft_it2));
		ASSERT_EQUAL((std_it1 < std_it2), (ft_it1 < ft_it2));
		ASSERT_EQUAL((std_it1 >= std_it2), (ft_it1 >= ft_it2));
		ASSERT_EQUAL((std_it1 <= std_it2), (ft_it1 <= ft_it2));
	}
}

void TestElementAccess()
{
	std::vector<int> std_myvector;
  	std_myvector.push_back (100);
  	std_myvector.push_back (200);
	std_myvector.push_back (300);
	ft::vector<int> ft_myvector;
  	ft_myvector.push_back (100);
  	ft_myvector.push_back (200);
	ft_myvector.push_back (300);
	ASSERT_EQUAL(std_myvector[0], ft_myvector[0]);
	ASSERT_EQUAL(std_myvector[1], ft_myvector[1]);
	ASSERT_EQUAL(std_myvector[2], ft_myvector[2]);
	
	ASSERT_EQUAL(std_myvector.front(), ft_myvector.front());
	ASSERT_EQUAL(std_myvector.back(), ft_myvector.back());
	ASSERT_EQUAL(std_myvector.at(0), ft_myvector.at(0));
	std_myvector.at(0) += 10;
	ft_myvector.at(0) += 10;
	ASSERT_EQUAL(std_myvector.at(0), ft_myvector.at(0));
}

void	test_vector()
{
	std::cout << "\033[1;36m\n--------TEST VECTOR--------\n\033[0m";
	TestRunner tr;
	RUN_TEST(tr, TestConstructor);
	RUN_TEST(tr, TestOperatorAssignment);
	RUN_TEST(tr, TestCapacity);
	RUN_TEST(tr, TestModifiers);
	RUN_TEST(tr, TestNonmemberFunctionOverloads);
	RUN_TEST(tr, TestIterator);
	RUN_TEST(tr, TestElementAccess);
}

int main()
{
	test_vector();
	return (0);
}
