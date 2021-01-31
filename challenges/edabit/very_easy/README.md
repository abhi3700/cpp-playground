# Question banks
## 1. Very easy
* Problem
	- fix the code
```cpp
bool checkEquals(vector<int> arr1, vector<int> arr2) {
	for(int i = 0; i < arr1.size(); ++i) {
		if(arr1[i] == arr2[i]) {
			return true;
		}
	}

	return false;
}
```
	- [solution](./1.cpp)