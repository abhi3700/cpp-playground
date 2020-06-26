#include <sw/redis++/redis++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
// using namespace sw::redis;
using sw::redis::Redis;

const string redis_uri = "tcp://pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";

int main() {
	try {
		auto r = Redis(redis_uri);

		std::vector<string> v1{"Abhijit Roy", "Anuvesh", "Vijay", "Girish", "Abhishek"};

		// long long Redis::del("emp_list");
		
		r.rpush("emp_list", v1.begin(), v1.end());		// push from back, a 'v1' vector into a key - 'emp_list'
		r.rpush("emp_list", {"Abhijit Roy", "Anuvesh", "Vijay", "Girish", "Abhishek"});		// push from back an initializer list into a key - 'emp_list'
		v1.clear();		// clear the vector 'v1'

		r.lrange("emp_list", 0, -1, std::back_inserter(v1));		// put the 'emp_list' key data into that vector

		// print the newly inserted vector 'v1' after clearing
		for (auto it = v1.begin(); it != v1.end(); ++it) {
			std::cout << *it << "\n";
		}

	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}