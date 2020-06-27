/*
					Set & Get Multiple Pairs at once using `mset` & `mget`
					- Data Structure
					{
						"name", "Vincent", 
						"empcode", "CL00343", 
						"profession", "Doctor" 
					}
					- M-1: mset using vector of pairs
					- M-2: mset usin map
					- Output the keys' values into a new vector<string>
					- print the newly inserted vector values.
*/

#include <sw/redis++/redis++.h>
#include <iostream>

using std::string;
using sw::redis::Redis;

const string redis_uri = "tcp://pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";

int main() {
	auto r = Redis(redis_uri);

	// M-1
	std::vector<std::pair<string, string>> v1 = { 
											{"name", "Vincent"}, 
											{"empcode", "CL00343"}, 
											{"profession", "Doctor"} 
										};
	r.mset(v1.begin(), v1.end());

	// M-2
	std::map<string, string> m1 = {
									{"name", "Catherine"}, 
									{"empcode", "CL4325"}, 
									{"profession", "Police"} 
	};

	r.mset(m1.begin(), m1.end());


	std::vector<string> v_out;		// declar

	// get the key's values into a vector 'v_out'
	r.mget({"name", "empcode", "profession"}, std::back_inserter(v_out));

	// print the output
	for(auto&& i : v_out) {
		std::cout << i << "\n";
	}

	return 0;
}