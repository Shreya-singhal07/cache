// DS used: vectors
// implementing bruteforce LRU

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
	

	int evict_key_and_return()
	{
		return -1;
	}

	int get(int key)
	{
	    pair<int,int>ans(-1,-1);
	    for(int i=0; i < v.size(); i++) //max size of v = capacity
	    {
	      if(v[i].first == key)
	      {
	        ans = v[i];
	        v.erase(v.begin()+i);
	        v.push_back(ans);
	        break;
	      }
	    }
	    return ans.second;
     
	}
	void put(int key, int value)
	{
		pair<int, int> ans;
		for(int i = 0; i < v.size(); i++)
		{
			
			if(v[i].first == key)
			{
				ans = v[i];
				v.erase(v.begin() + i);
				ans.second = value;
				v.push_back(ans);
				return;
			}
		}
		
		if(v.size() == capacity)
		{
			v.erase(v.begin());
			v.push_back({key, value});
		}
		else
		{
			v.push_back({key, value});
		}
		
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
