//optimised solution

#include <bits/stdc++.h>
using namespace std;

class Cache
{
	public:
		int capacity;
		//int size;
		
		virtual int evict_key_and_return(){}; //virtual [keyword] : compulsory for derived classes to implement
		virtual int get(int key){};
		virtual void put(int key, int value){};

};

class LRUcache: public Cache
{
	public:
		map<int,list<pair<int,int>>::iterator>mp;           //key, key address
		list<pair<int,int>>l;   //doubly linked list 
		
	
	LRUcache(int _capacity)
	{
		capacity = _capacity; 
		mp.clear();
	}
	
	
	int evict_key_and_return()
	{
		pair<int,int>p = *l.begin();       //*l.begin() = key,value PAIR
		l.erase(l.begin());
		mp.erase(p.first);
		return p.second;  //to find the last evicted element value
	}
	
	int get(int key)
	{
		if(mp.find(key) == mp.end())
			return -1;
		auto a = mp[key];
		pair<int,int>p = *a;
		int val = p.second;
		l.erase(a);
		l.push_back({key, val});
		auto it= l.end();
		mp[key] = --it;
		return val;
	}
	
	void put(int key, int value)
	{
		if(mp.find(key) != mp.end())
		{
			auto a = mp[key] ;
			pair<int,int>p = *a;
			l.erase(a);
			l.push_back({key, value});
			auto it= l.end();
			mp[key] = --it;
			return;
		}

		if(mp.size() == capacity)
			evict_key_and_return();
			
		l.push_back({key, value});
		auto it= l.end();
		mp[key] = --it;  //adding new key, key address in map

	}

};

int main() 
{
	
	LRUcache lr = LRUcache(3);
	cout<< lr.get(1) << endl;
	lr.put(-3, 5);
	lr.put(1, 4);
	lr.put(1, 7);
	cout<< lr.get(1)<<endl;
	lr.put(45, 1);
	lr.put(7,1);
	cout << lr.get(-3) << endl;
	cout << lr.get(7) << endl;
	
	return 0;
}
