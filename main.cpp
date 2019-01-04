//This code is from https://www.geeksforgeeks.org/c-program-hashing-chaining/
#include <iostream>
#include <list>
using namespace std;

class Hash
{
public:
	Hash(int size);
	~Hash();
	void InsertItem(int key);
	void DeleteItem(int key);
	int GenerateHashCode(int x);
	void DisplayHash();
private:
	int mBucket;
	list<int>* mTable;
};

Hash::Hash(int size)
{
	mBucket = size;
	mTable = new list<int>[mBucket];
}

Hash::~Hash()
{
	delete[] mTable;
}

void Hash::InsertItem(int key)
{
	int index = GenerateHashCode(key);
	mTable[index].push_back(key);
}

void Hash::DeleteItem(int key)
{
	int index = GenerateHashCode(key);

	list<int>::iterator i;

	for (i = mTable[index].begin(); i != mTable[index].end(); i++)
	{
		if (*i == key)
		{
			break;
		}
	}

	if (i != mTable[index].end())
	{
		mTable[index].erase(i);
	}
}

int Hash::GenerateHashCode(int x)
{
	return x % mBucket;
}

void Hash::DisplayHash()
{
	for (int i = 0; i < mBucket; i++)
	{
		cout << i;
		for (auto x : mTable[i])
		{
			cout << " --> " << x;
		}
		cout << endl;
	}
}

// Driver program  
int main()
{
	// array that contains keys to be mapped 
	int a[] = {15, 11, 27, 8, 12, 2};
	int n = sizeof(a) / sizeof(a[0]);

	// insert the keys into the hash table 
	Hash h(7);   // 7 is count of buckets in 
				 // hash table 
	for (int i = 0; i < n; i++)
	{
		h.InsertItem(a[i]);
	}

	// delete 12 from hash table 
	h.DeleteItem(12);

	// display the Hash table 
	h.DisplayHash();

	return 0;
}