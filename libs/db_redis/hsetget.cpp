/*
				Set & Get Hash with single pair at once using `hset` & `hget`
				- Data Structure
				{
					"person1": {
						"name": "Vincent"
					}
					"person2": {
						"name": "Vincent"
					}
				}
				- M-1: using initializer pair
				- M-2: using `std::make_pair()`
				- Set keys - "person1", "person2", each with (key, value) pair
				- Get values of the values of key of nodal key
				- Delete the node key(s) - "person1"
				- Delete the key inside node key - "name"
				- 
*/

#include <sw/redis++/redis++.h>
#include <iostream>

using std::string;
using sw::redis::Redis;

const string redis_uri = "tcp://pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";

int main() {
	try {
		auto r = Redis(redis_uri);

		r.hset("person1", {"name", "Vincent"});		// M-1
		r.hset("person2", std::make_pair("name", "Catherine"));		// M-2

		auto val_it1 = r.hget("person1", "name");
		auto val_it2 = r.hget("person2", "name");

		// print The values set are
		std::cout << "The values set are==============" << "\n";
		if(val_it1) {
			std::cout << *val_it1 << "\n";
		}
		if(val_it2) {
			std::cout << *val_it2 << "\n";
		}
		r.del({"person1", "person2"});		// delete the main keys created
		r.hdel("person1", "name");			// delete the internal key 'name'

		// output values into iterator
		auto val_it3 = r.hget("person1", "name");
		auto val_it4 = r.hget("person2", "name");

		// print The values after deleting keys
		std::cout << "The values after deleting nodal key are==============" << "\n";
		if(val_it3) {
			std::cout << *val_it3 << "\n";
		}
		if(val_it4) {
			std::cout << *val_it4 << "\n";
		}


	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}


	return 0;
}