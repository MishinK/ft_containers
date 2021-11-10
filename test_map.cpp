#include "map.hpp"
#include <map>
#include "assert.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void TestConstructor()
{
	bool(*fn_pt)(char,char) = fncomp;

	std::map<char,int> std_first;
	ft::map<char,int> ft_first;
	ASSERT_EQUAL(std_first, ft_first);

	std::map<char,int> std_second (std_first.begin(), std_first.end());
	ft::map<char,int> ft_second (ft_first.begin(), ft_first.end());
	ASSERT_EQUAL(std_second, ft_second);

	std::map<char,int> std_third (std_second);
	ft::map<char,int> ft_third (ft_second);
	ASSERT_EQUAL(std_third, ft_third);

	std::map<char,int,classcomp> std_fourth;
	ft::map<char,int,classcomp> ft_fourth;
	ASSERT_EQUAL(std_fourth, ft_fourth);

  	std::map<char,int,bool(*)(char,char)> std_fifth (fn_pt);
	ft::map<char,int,bool(*)(char,char)> ft_fifth (fn_pt);
	ASSERT_EQUAL(std_fifth, ft_fifth);
	
	std_first = std_third;
	ft_first = ft_third;
	ASSERT_EQUAL(std_first, ft_first);
	ASSERT_EQUAL(std_third, ft_third);
}

void TestAssignment()
{
	std::map<char,int> std_first;
  	std::map<char,int> std_second;
	ft::map<char,int> ft_first;
  	ft::map<char,int> ft_second;

 	std_first['x'] = 8;
  	std_first['y'] = 16;
  	std_first['z'] = 32;
	ft_first['x'] = 8;
  	ft_first['y'] = 16;
  	ft_first['z'] = 32;
	
	ASSERT_EQUAL(std_first, ft_first);
	ASSERT_EQUAL(std_second, ft_second);

	std_second = std_first;
	ft_second = ft_first;
	ASSERT_EQUAL(std_first, ft_first);
	ASSERT_EQUAL(std_second, ft_second);

  	std_first = std::map<char,int>();
	ft_first = ft::map<char,int>();
	ASSERT_EQUAL(std_first, ft_first);
	ASSERT_EQUAL(std_second, ft_second);
}

void TestCapacity()
{
	std::map<char,int> std_mymap;
	ft::map<char,int> ft_mymap;
	ASSERT_EQUAL(std_mymap, ft_mymap);
	ASSERT_EQUAL(std_mymap.empty(), ft_mymap.empty());
	ASSERT_EQUAL(std_mymap.size(), ft_mymap.size());
	ASSERT_EQUAL(std_mymap.max_size(), ft_mymap.max_size());
  	std_mymap['a'] = 10;
  	std_mymap['b'] = 20;
  	std_mymap['c'] = 30;
	ft_mymap['a'] = 10;
  	ft_mymap['b'] = 20;
  	ft_mymap['c'] = 30;
	ASSERT_EQUAL(std_mymap, ft_mymap);
	ASSERT_EQUAL(std_mymap.empty(), ft_mymap.empty());
	ASSERT_EQUAL(std_mymap.size(), ft_mymap.size());
	ASSERT_EQUAL(std_mymap.max_size(), ft_mymap.max_size());
  	while (!std_mymap.empty())
  	{
		ASSERT_EQUAL(std_mymap, ft_mymap);
		ASSERT_EQUAL(std_mymap.empty(), ft_mymap.empty());
		ASSERT_EQUAL(std_mymap.size(), ft_mymap.size());
		ASSERT_EQUAL(std_mymap.max_size(), ft_mymap.max_size());
		std_mymap.erase(std_mymap.begin());
		ft_mymap.erase(ft_mymap.begin());
	}
}

void TestAccess()
{
	std::map<char,std::string> std_mymap;
	ft::map<char,std::string> ft_mymap;
	std_mymap['a'] = "an element";
	ft_mymap['a'] = "an element";
	ASSERT_EQUAL(std_mymap, ft_mymap);
	ASSERT_EQUAL(std_mymap['a'], ft_mymap['a']);
	std_mymap['b'] = "another element";
	ft_mymap['b'] = "another element";
	ASSERT_EQUAL(std_mymap, ft_mymap);
	ASSERT_EQUAL(std_mymap['a'], ft_mymap['a']);
	ASSERT_EQUAL(std_mymap['b'], ft_mymap['b']);
	std_mymap['c'] = std_mymap['b'];
	ft_mymap['c'] = ft_mymap['b'];
	ASSERT_EQUAL(std_mymap, ft_mymap);
	ASSERT_EQUAL(std_mymap['a'], ft_mymap['a']);
	ASSERT_EQUAL(std_mymap['b'], ft_mymap['b']);
	ASSERT_EQUAL(std_mymap['c'], ft_mymap['c']);
}

void TestModifiers()
{
	{
		std::map<char,int> std_mymap;
		ft::map<char,int> ft_mymap;
		std_mymap.insert ( std::pair<char,int>('a',100) );
		std_mymap.insert ( std::pair<char,int>('z',200) );
		ft_mymap.insert ( ft::pair<char,int>('a',100) );
		ft_mymap.insert ( ft::pair<char,int>('z',200) );
		ASSERT_EQUAL(std_mymap, ft_mymap);

		std::pair<std::map<char,int>::iterator,bool> std_ret;
		ft::pair<ft::map<char,int>::iterator, bool> ft_ret;

		std_ret = std_mymap.insert ( std::pair<char,int>('z',500) );
		ft_ret = ft_mymap.insert ( ft::pair<char,int>('z',500) );
		ASSERT_EQUAL(std_mymap, ft_mymap);
		
		std::map<char,int>::iterator std_it = std_mymap.begin();
		ft::map<char,int>::iterator ft_it = ft_mymap.begin();
		std_mymap.insert (std_it, std::pair<char,int>('b',300)); 
		ft_mymap.insert (ft_it, ft::pair<char,int>('b',300));
		ASSERT_EQUAL(std_mymap, ft_mymap);
		
		std::map<char,int> std_anothermap;
		ft::map<char,int> ft_anothermap;
		std_anothermap.insert(std_mymap.begin(), std_mymap.find('c'));
		ft_anothermap.insert(ft_mymap.begin(), ft_mymap.find('c'));
		ASSERT_EQUAL(std_mymap, ft_mymap);
	}
	{
		std::map<char,int> std_mymap;
  		std::map<char,int>::iterator std_it;
		ft::map<char,int> ft_mymap;
  		ft::map<char,int>::iterator ft_it;
		std_mymap['a']=10;
 	 	std_mymap['b']=20;
  		std_mymap['c']=30;
  		std_mymap['d']=40;
  		std_mymap['e']=50;
  		std_mymap['f']=60;
		ft_mymap['a']=10;
 	 	ft_mymap['b']=20;
  		ft_mymap['c']=30;
  		ft_mymap['d']=40;
  		ft_mymap['e']=50;
  		ft_mymap['f']=60;
		ASSERT_EQUAL(std_mymap, ft_mymap);
  		std_it=std_mymap.find('b');
		ft_it=ft_mymap.find('b');
  		std_mymap.erase (std_it);
		ft_mymap.erase (ft_it);
		ASSERT_EQUAL(std_mymap, ft_mymap);                
		std_mymap.erase ('c');
		ft_mymap.erase ('c');
		ASSERT_EQUAL(std_mymap, ft_mymap);          
		std_it = std_mymap.find ('e');
		ft_it = ft_mymap.find ('e');
		ASSERT_EQUAL(std_mymap, ft_mymap);
  		std_mymap.erase (std_it, std_mymap.end());
		ft_mymap.erase (ft_it, ft_mymap.end());
		ASSERT_EQUAL(std_mymap, ft_mymap);
	}
	{
		std::map<char,int> std_foo, std_bar;
		ft::map<char,int> ft_foo, ft_bar;
		std_foo['x']=100;
  		std_foo['y']=200;
		std_bar['a']=11;
  		std_bar['b']=22;
  		std_bar['c']=33;
		ft_foo['x']=100;
  		ft_foo['y']=200;
		ft_bar['a']=11;
  		ft_bar['b']=22;
  		ft_bar['c']=33;
		ASSERT_EQUAL(std_foo, ft_foo);
		ASSERT_EQUAL(std_bar, ft_bar);
		std_foo.swap(std_bar);
		ft_foo.swap(ft_bar);
		ASSERT_EQUAL(std_foo, ft_foo);
		ASSERT_EQUAL(std_bar, ft_bar);
	}
	{
		std::map<char,int> std_mymap;
		ft::map<char,int> ft_mymap;
  		std_mymap['x']=100;
  		std_mymap['y']=200;
  		std_mymap['z']=300;
		ft_mymap['x']=100;
  		ft_mymap['y']=200;
  		ft_mymap['z']=300;
		ASSERT_EQUAL(std_mymap, ft_mymap);
  		std_mymap.clear();
		ft_mymap.clear();
		ASSERT_EQUAL(std_mymap, ft_mymap);
  		std_mymap['a']=1101;
  		std_mymap['b']=2202;
		ft_mymap['a']=1101;
  		ft_mymap['b']=2202;
		ASSERT_EQUAL(std_mymap, ft_mymap);
	}
}

void TestIterator()
{
		std::map<char,int> std_mymap;
		ft::map<char,int> ft_mymap;

		std_mymap['a']=50;
 		std_mymap['b']=200;
		std_mymap['c'] = 60;

		ft_mymap['a']=50;
 		ft_mymap['b']=200;
		ft_mymap['c'] = 60;

		std::map<char,int>::iterator std_it = std_mymap.begin();
		ft::map<char,int>::iterator ft_it = ft_mymap.begin();
		
		ASSERT_EQUAL(std_it->first, ft_it->first);
		ASSERT_EQUAL(std_it->second, ft_it->second);
		std_it++;
		ft_it++;
		ASSERT_EQUAL(std_it->first, ft_it->first);
		ASSERT_EQUAL(std_it->second, ft_it->second);
		std_it--;
		ft_it--;
		ASSERT_EQUAL(std_it->first, ft_it->first);
		ASSERT_EQUAL(std_it->second, ft_it->second);
		std_it = std_mymap.end();
		ft_it = ft_mymap.end();
		std_it--;
		ft_it--;
		ASSERT_EQUAL(std_it->first, ft_it->first);
		ASSERT_EQUAL(std_it->second, ft_it->second);
		std_it--;
		ft_it--;
		ASSERT_EQUAL(std_it->first, ft_it->first);
		ASSERT_EQUAL(std_it->second, ft_it->second);
		std::map<char,int>::reverse_iterator std_rit = std_mymap.rbegin();
		ft::map<char,int>::reverse_iterator ft_rit = ft_mymap.rbegin();
		ASSERT_EQUAL(std_rit->first, ft_rit->first);
		ASSERT_EQUAL(std_rit->second, ft_rit->second);
		std_rit++;
		ft_rit++;
		ASSERT_EQUAL(std_rit->first, ft_rit->first);
		ASSERT_EQUAL(std_rit->second, ft_rit->second);
		std_rit++;
		ft_rit++;
		ASSERT_EQUAL(std_rit->first, ft_rit->first);
		ASSERT_EQUAL(std_rit->second, ft_rit->second);
		std_rit = std_mymap.rend();
		ft_rit = ft_mymap.rend();
		std_rit--;
		ASSERT_EQUAL(std_rit->first, ft_rit->first);
		ASSERT_EQUAL(std_rit->second, ft_rit->second);
		std_rit--;
		ft_rit--;
		std_rit--;
		ft_rit--;
		ASSERT_EQUAL(std_rit->first, ft_rit->first);
		ASSERT_EQUAL(std_rit->second, ft_rit->second);
}

void TestObservers()
{
	{
		std::map<char,int> std_mymap;
		ft::map<char,int> ft_mymap;
		std::map<char,int>::key_compare std_mycomp = std_mymap.key_comp();
		ft::map<char,int>::key_compare ft_mycomp = ft_mymap.key_comp();
		std_mymap['a']=100;
  		std_mymap['b']=200;
  		std_mymap['c']=300;
		ft_mymap['a']=100;
  		ft_mymap['b']=200;
  		ft_mymap['c']=300;

  		char std_highest = std_mymap.rbegin()->first;
		char ft_highest = ft_mymap.rbegin()->first;

		ASSERT_EQUAL(std_highest, ft_highest);
		std::map<char,int>::iterator std_it = std_mymap.begin();
		ft::map<char,int>::iterator ft_it = ft_mymap.begin();
		ASSERT_EQUAL(std_it->first, ft_it->first);
		ASSERT_EQUAL(std_it->second, ft_it->second);
		do {
			ASSERT_EQUAL(std_it->first, ft_it->first);
			ASSERT_EQUAL(std_it->second, ft_it->second);
			//std::cout << std_it->first << " " << ft_it->first;
			//std::cout << std_it->second << " " << ft_it->second;
			} while (std_mycomp((*std_it++).first, std_highest) && ft_mycomp((*ft_it++).first, ft_highest));
	}
	{
		std::map<char,int> std_mymap;
		ft::map<char,int> ft_mymap;
  		std_mymap['a']=50;
 		std_mymap['b']=200;
		std_mymap['c'] = 60;

		ft_mymap['a']=50;
 		ft_mymap['b']=200;
		ft_mymap['c'] = 60;

		ASSERT_EQUAL(std_mymap.find('a')->second, ft_mymap.find('a')->second);
		ASSERT_EQUAL(std_mymap.find('b')->second, ft_mymap.find('b')->second);
		ASSERT_EQUAL(std_mymap.count('d'), ft_mymap.count('d'));
		ASSERT_EQUAL(std_mymap.count('b'), ft_mymap.count('b'));
		ASSERT_EQUAL(std_mymap.count('a'), ft_mymap.count('a'));

		ASSERT_EQUAL(std_mymap.lower_bound('a')->second, ft_mymap.lower_bound('a')->second);
		ASSERT_EQUAL(std_mymap.lower_bound('b')->second, ft_mymap.lower_bound('b')->second);
		ASSERT_EQUAL(std_mymap.lower_bound('c')->second, ft_mymap.lower_bound('c')->second);
		
		ASSERT_EQUAL(std_mymap.upper_bound('a')->second, ft_mymap.upper_bound('a')->second);
		ASSERT_EQUAL(std_mymap.upper_bound('b')->second, ft_mymap.upper_bound('b')->second);

		ASSERT_EQUAL(std_mymap.equal_range('a').second->second, ft_mymap.equal_range('a').second->second);
		ASSERT_EQUAL(std_mymap.equal_range('a').second->first, ft_mymap.equal_range('a').second->first);
		ASSERT_EQUAL(std_mymap.equal_range('a').first->second, ft_mymap.equal_range('a').first->second);
		ASSERT_EQUAL(std_mymap.equal_range('a').first->first, ft_mymap.equal_range('a').first->first);

		ASSERT_EQUAL(std_mymap.equal_range('b').second->second, ft_mymap.equal_range('b').second->second);
		ASSERT_EQUAL(std_mymap.equal_range('b').second->first, ft_mymap.equal_range('b').second->first);
		ASSERT_EQUAL(std_mymap.equal_range('b').first->second, ft_mymap.equal_range('b').first->second);
		ASSERT_EQUAL(std_mymap.equal_range('b').first->first, ft_mymap.equal_range('b').first->first);
	}
}



void test_map()
{
	std::cout << "\033[1;36m\n--------TEST MAP--------\n\033[0m";
	TestRunner tr;
	RUN_TEST(tr, TestConstructor);
	RUN_TEST(tr, TestAssignment);
	RUN_TEST(tr, TestCapacity);
	RUN_TEST(tr, TestAccess);
	RUN_TEST(tr, TestModifiers);
	RUN_TEST(tr, TestObservers);
	RUN_TEST(tr, TestIterator);
}

int main()
{
	test_map();
	return (0);
}
