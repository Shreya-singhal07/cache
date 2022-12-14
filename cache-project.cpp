#include <bits/stdc++.h>
using namespace std;

class Cache
{
	public:
		int capacity;
		int size;
		
		virtual int evict_key_and_return(){};
		virtual int get(int key){};
		virtual void put(int key, int value){};

};


class RandomPolicyCache: public Cache
{
	public:
		map<int, int> mp;
		
	RandomPolicyCache(int _capacity)
	{
		capacity = _capacity; 
		mp.clear();
	}
		
		
	int evict_key_and_return()
	{
		int key = mp.begin()->first;
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
		
		if(mp.size() < capacity)
		{
			mp[key] = value;
		}
		else 
		{ 
			if(mp.find(key) != mp.end())
			{
				mp[key] = value;
			}
			else
			{
				evict_key_and_return();
				mp[key] = value;
			}
		}

	}
	
	
};
int main() 
{
	RandomPolicyCache r = RandomPolicyCache(2);
	cout<< r.get(1) << endl;
	r.put(-3, 5);
	r.put(1, 4);
	r.put(45, 1);
	cout << r.get(-3) << endl;
	cout << r.get(45) << endl;
	
	return 0;
}