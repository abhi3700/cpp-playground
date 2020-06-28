/*
				Set & Get Hash with multiple pairs at once using `hmset` `hgetall` & `hmget`
				- Data Structure
				{
					"person1": {
						"name": "Vincent"
					}
					"person2": {
						"name": "Vincent"
					}
				}
				- set multiple pairs into 1 hash key using `unordered_map`
				- Set keys - "person1", "person2", each with (key, value) pairs
				- Get a val of a key of hash key using `hget`
				- Get values of respective keys of a hash key using `hmget`
				- Get all the key, value pairs of a hash key using `hgetall`
				- Delete the hash key(s) - "person1" using `del`
				- Delete a key inside a hash key - "name" using 'hdel'
*/

#include <sw/redis++/redis++.h>
#include <iostream>

using std::string;
using sw::redis::Redis;

const string redis_uri = "tcp://pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";

int main() {
	try {
		auto r = Redis(redis_uri);

		// ---------------------------------------------------------------------------
		// adding 1st hash key
		std::unordered_map<string, string> m1 = {
											{"name", "Vincent"}, 
											{"empcode", "CL00343"}, 
											{"profession", "Doctor"} 
		};
		r.hmset("person1", m1.begin(), m1.end());

		// adding 2nd hash key
		std::unordered_map<string, string> m2 = {
									{"name", "Catherine"}, 
									{"empcode", "CL4325"}, 
									{"profession", "Police"} 
		};
		r.hmset("person2", m2.begin(), m2.end());

		// ---------------------------------------------------------------------------
		// get single key's value
		std::cout << "=======Get single key's value======" << "\n";
		auto name1 = r.hget("person1", "name");
		auto proffession1 = r.hget("person1", "profession");

		if(name1) {
			std::cout << "Person1's name: " << *name1 << "\n";
		}

		if(proffession1) {
			std::cout << "Person1's profession: " << *proffession1 << "\n";
		}
		// ---------------------------------------------------------------------------
		// get multiple key's values into 1 vector
		std::cout << "\n=====Get multiple key's value======" << "\n";

		std::vector<string> v_out1{}, v_out2{};
		r.hmget("person1", {"name", "empcode"}, std::back_inserter(v_out1));		// here, you can select the keys
		r.hvals("person1", std::back_inserter(v_out2));				// here, you can't select, but get all

		// print the v_out values
		for(auto&& i : v_out1) {
			std::cout << i << "\n";
		}
		std::cout << "----------------" << "\n";
		for(auto&& i : v_out2) {
			std::cout << i << "\n";
		}
		// ---------------------------------------------------------------------------
		// get all keys, values of hash key as a list into 1 vector
		std::cout << "\n=====Get all key, value pairs of a hash key======" << "\n";
		std::unordered_map<string, string> m_out;
		r.hgetall("person1", std::inserter(m_out, m_out.begin()));

		// print all the (key, value pairs)
		for(auto&& [k, v] : m_out) {
			std::cout << k << ": " << v << "\n";
		}	


		// ---------------------------------------------------------------------------
		std::cout << "\n=====Get all key, value pairs of a hash key after del \"name\" & \"proffession\" keys======" << "\n";
		m_out.clear();	// clear the old data to fill the data after delete

		// r.hdel("person1", "name");		// delete the "name" & "profession" keys of "person1" hash key
		r.hdel("person1", {"name", "profession"});
		r.hgetall("person1", std::inserter(m_out, m_out.begin()));

		// print all the (key, value pairs)
		for(auto&& [k, v] : m_out) {
			std::cout << k << ": " << v << "\n";
		}	


	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}


	return 0;
}