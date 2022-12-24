// DS used: vectors
// implementing bruteforce LRU
// ----------------------------
//         ASSUMPTIONS
// ----------------------------
// end = most recently used pair
// front = least recently used pair


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

class BruteLRU: public Cache
{
	public:
  
	vector<pair<int, int>>v; //vector of pairs
 	BruteLRU(int _capacity)
	{
		capacity = _capacity; 
		v.clear();
	}
	bool check_rearrange(int key)          //true = if the element is present & rearrange : false = not present
	{
		pair<int, int> ans;

		for(int i = 0; i < v.size(); i++)  //max size of v = capacity
		{
			if(v[i].first == key)
			{
				ans = v[i];
				v.erase(v.begin() + i);   //deleting the ith entry (key,value) 
				v.push_back(ans);         //positioning ans at the end 
				return 1;
			}
		}
		return 0; //invalid index
	}
	int evict_key_and_return()
	{
		int x = v[0].first;
		v.erase(v.begin());
		return x;
	}
 
	int get(int key)
	{
	    if( check_rearrange(key) == 1)
	    	return v.back().second;
		return -1;

	}

	void put(int key, int value)
	{
		pair<int, int> ans;
		if(check_rearrange(key) == 1)
		{
			v.back().second = value;
			return;
		}
		
		if(v.size() == capacity)
			evict_key_and_return();

		v.push_back({key, value});
		return;
	}
	
	
};

int main() 
{
	
	BruteLRU c = BruteLRU(2);
	cout << c.get(1) << endl;
	c.put(3, 5);
	c.put(1, 6);
	c.put(4, 8);
	cout << c.get(3) << endl;
	cout << c.get(4) << endl;	
	return 0;
}
