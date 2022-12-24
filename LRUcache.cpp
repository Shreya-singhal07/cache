//optimised solution

#include <bits/stdc++.h>
using namespace std;

class Cache
{
	public:
		int capacity;
		//int size;
		
		virtual int evict_key_and_return(){}; 
		virtual int get(int key){};
		virtual void put(int key, int value){};

};
