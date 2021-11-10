#pragma once
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <deque>

#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"

template<typename T>
bool operator==(const std::vector<T> &lhs, const ft::vector<T> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename std::vector<T>::const_iterator left = lhs.begin();
	typename ft::vector<T>::const_iterator right = rhs.begin();
	while (left != lhs.end())
	{
		if (*left == *right)
		{
			++left;
			++right;
			continue;
		}
		return (false);
	}
	return (true);
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s) {
    os << "{";
    bool first = true;
    for (typename std::vector<T>::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << *it;
    }
    return os << "}";
}

template <class T>
std::ostream& operator << (std::ostream& os, const ft::vector<T>& s) {
	os << "{";
	bool first = true;
	for (typename ft::vector<T>::const_iterator it = s.begin(); it != s.end();
	++it) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << *it;
	}
	return os << "}";
}

template<typename Key, typename Value, typename Compare, typename Compare2>
bool operator==(const std::map<Key, Value, Compare> &lhs, const ft::map<Key, Value, Compare2> &rhs)
{
  typename std::map<Key, Value, Compare>::const_iterator lbegin = lhs.begin();
  typename std::map<Key, Value, Compare>::const_iterator lend = lhs.end();
  
  typename ft::map<Key, Value, Compare>::const_iterator rbegin = rhs.begin();

  if (lhs.size() != rhs.size())
	return false;
  while (lbegin != lend) {
    if (*lbegin != *rbegin)
	  return false;
    ++lbegin;
    ++rbegin;
  }
  return true;
}

template <class K, class V, class Compare>
std::ostream& operator << (std::ostream& os, const std::map<K, V, Compare>& m) {
    os << "{";
    bool first = true;
	for (typename std::map<K, V, Compare>::const_iterator it = m.begin(); it != m.end();
	++it) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << it->first << ": " << it->second;
    }
    return os << "}";
}

template <class K, class V, class Compare>
std::ostream& operator << (std::ostream& os, const ft::map<K, V, Compare>& m) {
  os << "{";
  bool first = true;
  for (typename ft::map<K, V, Compare>::const_iterator it = m.begin(); it != m.end();
  ++it) {
	if (!first) {
	  os << ", ";
	}
	first = false;
	os << it->first << ": " << it->second;
  }
  return os << "}";
}

template<typename Key, typename Compare, typename Compare2>
bool operator==(const std::set<Key, Compare> &lhs, const ft::set<Key, Compare2> &rhs)
{
  	typename std::set<Key, Compare>::const_iterator lbegin = lhs.begin();
  	typename std::set<Key, Compare>::const_iterator lend = lhs.end();
	typename ft::set<Key, Compare>::const_iterator rbegin = rhs.begin();

  if (lhs.size() != rhs.size())
	return false;
  while (lbegin != lend) {
	if (*lbegin != *rbegin)
	  return false;
	++lbegin;
	++rbegin;
  }
  return true;
}

template <typename Key, typename Compare>
std::ostream& operator << (std::ostream& os, const std::set<Key, Compare>& s) {
    os << "{";
    bool first = true;
	for (typename std::set<Key, Compare>::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << *it;
    }
    return os << "}";
}

template <typename Key, typename Compare>
std::ostream& operator<< (std::ostream& os, const ft::set<Key, Compare>& s) {
  os << "{";
  bool first = true;
  for (typename ft::set<Key, Compare>::const_iterator it = s.begin(); it != s.end(); ++it) {
	if (!first) {
	  os << ", ";
	}
	first = false;
	os << *it;
  }
  return os << "}";
}


template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = "") {
    if (!(t == u)) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw std::runtime_error(os.str());
    }
}

inline void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    	TestRunner() : fail_count(0) {}

    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
        try {
            func();
            std::cout << test_name << "\033[0;32m OK\033[0m" << std::endl;
        } catch (std::exception& e) {
            ++fail_count;
            std::cout << test_name << "\033[0;31m fail: " << e.what() << "\033[0m"
            << std::endl;
        } catch (...) {
            ++fail_count;
            std::cout << "\033[0;31mUnknown exception caught\033[0m" << std::endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            std::cout << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
    }

private:
    int fail_count;
};

#define ASSERT_EQUAL(x, y) {            \
  std::ostringstream __assert_equal_private_os;                     \
  __assert_equal_private_os << #x << " != " << #y << ", "      \
    << __FILE__ << ":" << __LINE__;     \
  AssertEqual(x, y, __assert_equal_private_os.str());          \
}

#define ASSERT(x) {                     \
  ostringstream os;                     \
  os << #x << " is false, "             \
    << __FILE__ << ":" << __LINE__;     \
  Assert(x, os.str());                  \
}

#define RUN_TEST(tr, func) \
  tr.RunTest(func, #func)