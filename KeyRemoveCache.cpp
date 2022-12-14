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

class MinimumKeyRemovePolicyCache: public Cache
{
	public:
		map<int, int> mp; //key,value
	
	MinimumKeyRemovePolicyCache(int _capacity)
	{
		capacity = _capacity; 
		mp.clear();
	}
	
	// MaximumKeyRemovePolicyCache(int _capacity)
	// {
	// 	capacity = _capacity; 
	// 	mp.clear();
	// }	

	// int evict_key_and_return()
	// {
	// 	int key = mp.rbegin()->first; //iterator for key of map mp
	// 	mp.erase(mp.rbegin()->first);
	// 	// cout << "evicted is" << key << endl;
	// 	return key;
	// }

	int evict_key_and_return()
	{
		int key = mp.begin()->first; //iterator for key of map mp
		mp.erase(mp.begin()->first);
		// cout << "evicted is" << key << endl;
		return key;
	}
	
	int get(int key)
	{
		if(mp.find(key) == mp.end())
			return -1;
		return mp[key];
	}
	
	void put(int key, int value)
	{
		if(mp.find(key) != mp.end())
		{
			mp[key] = value;
			return;
		}

		if(mp.size() < capacity)
		{
			mp[key] = value; //if key,value exists -> update key,new_value
		}
		else 
		{ 
				evict_key_and_return();
				mp[key] = value;
		}

	}
	
	
};
int main() {
	
	MinimumKeyRemovePolicyCache r = MinimumKeyRemovePolicyCache(2);
	cout<< r.get(1) << endl;
	r.put(-3, 5);
	r.put(1, 4);
	r.put(45, 1);
	cout << r.get(-3) << endl;
	cout << r.get(45) << endl;
	
	return 0;
}
