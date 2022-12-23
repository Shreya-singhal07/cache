
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

class bruteLRU: public Cache
{
	public:
  
  vector<pair<int, int>>v; //vector of pairs
 	bruteLRU(int _capacity)
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
    for(int i=0;i <v.size(); i++) //max size of v = capacity
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
	
	void put(int k, int val)
	{
    int flag = 0;
    pair<int,int>ans(-1,-1);
	  for(int i=0; i <v.size(); i++)
    {
      if(v[i].first == key)
      {
        ans = v[i];
        ans.second = val;
        v.erase(v.begin()+i);
        v.push_back(ans);
      }
      
    }
    
    if(ans.first != -1)
    {
      return;
    }
    
    if(v.size() = capacity)
    {
      v.erase(v.begin());
      v.push_back(k,val);
    }
    else
    {
      v.push_back(k,val);
    }
      
	}
	
	
};
int main() 
{
	
	MaximumKeyRemovePolicyCache v = MaximumKeyRemovePolicyCache(2);
	cout<< v.get(1) << endl;
	v.put(3, 5);
	v.put(1, 6);
	v.put(4, 8);
	cout << v.get(3) << endl;
	cout << v.get(4) << endl;
	
	return 0;
}
