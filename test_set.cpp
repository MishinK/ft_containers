#include "assert.hpp"
#include "set.hpp"
#include <set>


bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};


void TestConstructor()
{
	int myints[]= {10,20,30,40,50};
	bool(*fn_pt)(int,int) = fncomp;
	
	std::set<int> std_first;
	ft::set<int> ft_first;
	ASSERT_EQUAL(std_first, ft_first);

	std::set<int> std_second (myints,myints+5);
	ft::set<int> ft_second (myints,myints+5);
	ASSERT_EQUAL(std_second, ft_second);

	std::set<int> std_third (std_second);
	ft::set<int> ft_third (ft_second);
	ASSERT_EQUAL(std_third, ft_third);

	std::set<int> std_fourth (std_second.begin(), std_second.end());
	ft::set<int> ft_fourth (ft_second.begin(), ft_second.end()); 
	ASSERT_EQUAL(std_fourth, ft_fourth);

	std::set<int,classcomp> std_fifth;
	ft::set<int,classcomp> ft_fifth;
	ASSERT_EQUAL(std_fifth, ft_fifth);

  	std::set<int,bool(*)(int,int)> std_sixth (fn_pt);
	ft::set<int,bool(*)(int,int)> ft_sixth (fn_pt);
	ASSERT_EQUAL(std_sixth, ft_sixth);

}

void TestAssign()
{
	int myints[]={ 12,82,37,64,15 };
  	std::set<int> std_first (myints,myints+5); 
	ft::set<int> ft_first (myints,myints+5); 
  	std::set<int> std_second;
	ft::set<int> ft_second;                 
	ASSERT_EQUAL(std_first, ft_first);
	ASSERT_EQUAL(std_second, ft_second);
  	std_second = std_first;
	ft_second = ft_first;
	ASSERT_EQUAL(std_first, ft_first);
	ASSERT_EQUAL(std_second, ft_second);                     
  	std_first = std::set<int>();
	ft_first = ft::set<int>();
	ASSERT_EQUAL(std_first, ft_first);
	ASSERT_EQUAL(std_second, ft_second);           
}

void TestCapacity()
{
	std::set<int> std_myset;
	ft::set<int> ft_myset;
	ASSERT_EQUAL(std_myset, ft_myset);
	ASSERT_EQUAL(std_myset.empty(), ft_myset.empty());
	ASSERT_EQUAL(std_myset.size(), ft_myset.size());
	ASSERT_EQUAL(std_myset.max_size(), ft_myset.max_size());
	std_myset.insert(20);
	std_myset.insert(30);
	std_myset.insert(10);
	ft_myset.insert(20);
	ft_myset.insert(30);
	ft_myset.insert(10);
	ASSERT_EQUAL(std_myset, ft_myset);
	ASSERT_EQUAL(std_myset.empty(), ft_myset.empty());
	ASSERT_EQUAL(std_myset.size(), ft_myset.size());
	ASSERT_EQUAL(std_myset.max_size(), ft_myset.max_size());
}

void TestModifiers()
{
	{
		std::set<int> std_myset;
  		std::set<int>::iterator std_it;
  		std::pair<std::set<int>::iterator,bool> std_ret;
		ft::set<int> ft_myset;
  		ft::set<int>::iterator ft_it;
  		ft::pair<ft::set<int>::iterator,bool> ft_ret;
		ASSERT_EQUAL(std_myset, ft_myset);

  		for (int i=1; i<=5; ++i) std_myset.insert(i*10);   
		for (int i=1; i<=5; ++i) ft_myset.insert(i*10);
		ASSERT_EQUAL(std_myset, ft_myset);

  		std_ret = std_myset.insert(20);
		ft_ret = ft_myset.insert(20);                       
		ASSERT_EQUAL(std_myset, ft_myset);
		ASSERT_EQUAL(std_ret.second, ft_ret.second);

 		if (std_ret.second==false) std_it=std_ret.first;
		if (ft_ret.second==false) ft_it=ft_ret.first; 
		ASSERT_EQUAL(std_myset, ft_myset);
		ASSERT_EQUAL(std_ret.second, ft_ret.second);
		
		std_myset.insert (std_it,25); 
  		std_myset.insert (std_it,24); 
  		std_myset.insert (std_it,26);
		
		ft_myset.insert (ft_it,25); 
  		ft_myset.insert (ft_it,24); 
  		ft_myset.insert (ft_it,26);
		ASSERT_EQUAL(std_myset, ft_myset);

  		int myints[]= {5,10,15};    	
  		std_myset.insert (myints, myints+3);
		ft_myset.insert (myints, myints+3);
		ASSERT_EQUAL(std_myset, ft_myset);
	}
	{
		std::set<int> std_myset;
  		std::set<int>::iterator std_it;
		ft::set<int> ft_myset;
  		ft::set<int>::iterator ft_it;

  		for (int i=1; i<10; i++) std_myset.insert(i*10);
		for (int i=1; i<10; i++) ft_myset.insert(i*10);
		
		ASSERT_EQUAL(std_myset, ft_myset);
  		std_it = std_myset.begin();
  		++std_it;
		ft_it = ft_myset.begin();
  		++ft_it;                                         
  		std_myset.erase (std_it);
		ft_myset.erase (ft_it);
		ASSERT_EQUAL(std_myset, ft_myset);

  		std_myset.erase (40);
		ft_myset.erase (40);
		ASSERT_EQUAL(std_myset, ft_myset);

  		std_it = std_myset.find (60);
  		std_myset.erase (std_it, std_myset.end());
		ft_it = ft_myset.find (60);
  		ft_myset.erase (ft_it, ft_myset.end());
		ASSERT_EQUAL(std_myset, ft_myset);
	}
	{
		int myints[]={12,75,10,32,20,25};
  		std::set<int> std_first (myints,myints+3);   
  		std::set<int> std_second (myints+3,myints+6);  
		
  		ft::set<int> ft_first (myints,myints+3);   
  		ft::set<int> ft_second (myints+3,myints+6);  
  		ASSERT_EQUAL(std_first, ft_first);
		ASSERT_EQUAL(std_second, ft_second);
		std_first.swap(std_second);
		ft_first.swap(ft_second);
		ASSERT_EQUAL(std_first, ft_first);
		ASSERT_EQUAL(std_second, ft_second);

		std_first.clear();
		ft_first.clear();
		ASSERT_EQUAL(std_first, ft_first);
		
		std_first.insert (1101);
  		std_first.insert (2202);
		ft_first.insert (1101);
  		ft_first.insert (2202);
		ASSERT_EQUAL(std_first, ft_first);
	}
}

void TestIterator()
{
	std::set<int> std_myset;
  	std::set<int>::iterator std_it;
	ft::set<int> ft_myset;
  	ft::set<int>::iterator ft_it;

  	for (int i=1; i<10; i++) std_myset.insert(i*10);
	for (int i=1; i<10; i++) ft_myset.insert(i*10);

	std_it = std_myset.begin();
	ft_it = ft_myset.begin();
	ASSERT_EQUAL(*std_it, *ft_it);
	std_it++;
	ft_it++;
	ASSERT_EQUAL(*std_it, *ft_it);
	std_it--;
	ft_it--;
	ASSERT_EQUAL(*std_it, *ft_it);

	std_it = std_myset.end();
	ft_it = ft_myset.end();
	std_it--;
	ft_it--;
	ASSERT_EQUAL(*std_it, *ft_it);

	std::set<int>::reverse_iterator std_rit = std_myset.rbegin();
	ft::set<int>::reverse_iterator ft_rit = ft_myset.rbegin();
	ASSERT_EQUAL(*std_rit, *ft_rit);
	std_rit++;
	ft_rit++;
	ASSERT_EQUAL(*std_it, *ft_it);
	std_rit--;
	ft_rit--;
	ASSERT_EQUAL(*std_it, *ft_it);
	std_rit = std_myset.rend();
	ft_rit = ft_myset.rend();
	std_rit--;
	ft_rit--;
	ASSERT_EQUAL(*std_it, *ft_it);
	std_rit--;
	ft_rit--;
	ASSERT_EQUAL(*std_it, *ft_it);
}

void TestObservers()
{
	std::set<int> std_myset;
  	int std_highest;
	ft::set<int> ft_myset;
  	int ft_highest;

  	std::set<int>::key_compare std_mycomp = std_myset.key_comp();
	ft::set<int>::key_compare ft_mycomp = ft_myset.key_comp();

  	for (int i=0; i<=5; i++) std_myset.insert(i);
	for (int i=0; i<=5; i++) ft_myset.insert(i);

  	std_highest = *std_myset.rbegin();
	ft_highest = *ft_myset.rbegin();
	ASSERT_EQUAL(std_highest, ft_highest);

  	std::set<int>::iterator std_it=std_myset.begin();
	ft::set<int>::iterator ft_it=ft_myset.begin();
  	do {
		ASSERT_EQUAL(*std_it, *ft_it);
  	} while ( std_mycomp(*(++std_it), std_highest) && ft_mycomp(*(++ft_it), ft_highest));
}

void TestOperations()
{
	
		std::set<int> std_myset;
  		std::set<int>::iterator std_it;
		ft::set<int> ft_myset;
  		ft::set<int>::iterator ft_it;

  		for (int i=1; i<10; i++) std_myset.insert(i*10);
		for (int i=1; i<10; i++) ft_myset.insert(i*10);

		std_it=std_myset.find(20);
		ft_it=ft_myset.find(20);
		ASSERT_EQUAL(*std_it, *ft_it);
		ASSERT_EQUAL(std_myset.count(0), ft_myset.count(0));
		ASSERT_EQUAL(std_myset.count(20), ft_myset.count(20));
		ASSERT_EQUAL(*std_myset.upper_bound(20), *ft_myset.upper_bound(20));
		ASSERT_EQUAL(*std_myset.upper_bound(-200), *ft_myset.upper_bound(-200));
		ASSERT_EQUAL(*std_myset.lower_bound(20), *ft_myset.lower_bound(20));
		ASSERT_EQUAL(*std_myset.equal_range(-200).first, *ft_myset.equal_range(-200).first);
		ASSERT_EQUAL(*std_myset.equal_range(-200).second, *ft_myset.equal_range(-200).second);
		ASSERT_EQUAL(*std_myset.equal_range(20).first, *ft_myset.equal_range(20).first);
		ASSERT_EQUAL(*std_myset.equal_range(20).second, *ft_myset.equal_range(20).second);
	
}



void test_set()
{
	std::cout << "\033[1;36m\n--------TEST SET--------\n\033[0m";
	TestRunner tr;
	RUN_TEST(tr, TestConstructor);
	RUN_TEST(tr, TestAssign);
	RUN_TEST(tr, TestCapacity);
	RUN_TEST(tr, TestModifiers);
	RUN_TEST(tr, TestObservers);
	RUN_TEST(tr, TestOperations);
	RUN_TEST(tr, TestIterator);
}

int main()
{
	test_set();
	return (0);
}