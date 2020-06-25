#include <sw/redis++/redis++.h>
#include <iostream>

using namespace sw::redis;
using std::string;


// const string redis_uri = "redis://h:pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";
const string redis_uri = "tcp://pd4ecec34154bbca551fdeafb94421d0ec41147dab602a6a878e6509ae49f638a@ec2-54-209-85-193.compute-1.amazonaws.com:11989";

int main() {

	try {
		auto redis = Redis(redis_uri);
		std::cout << redis.ping() << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}