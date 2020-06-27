/*
			Set & Get Single Pair at once using `set` & `get`
			- The data structure is:
			{
				"name": "abhijit"
			}
*/

#include <sw/redis++/redis++.h>
#include <iostream>

using std::string;
using namespace sw::redis;

const string redis_uri = "tcp://pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";

int main() {
	try {
		auto r = Redis(redis_uri);
		// std::cout << r.ping() << "\n";		// to verify whether the redis_db is working.

		r.set("name", "abhijit");
		auto name_val = r.get("name");

		if(name_val) {
			std::cout << *name_val << "\n";
		}

	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}