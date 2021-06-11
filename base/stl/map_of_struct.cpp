/*
		About 
		=====
		- bidder bids for an auction
		- set values & display
		- data structure: map of structs (with 3 fields)
		{ 83567, (0, 726 EOS), 78 },
		{ 321432, (0, 343 EOS), 43 },
*/


#include <iostream>
#include <map>

using std::string;
using std::map;
using std::make_pair;


typedef struct {
	bool claimed_by_bidder;
	string bid_crypto_price;
	float bid_fiat_price_usd;
public:
	// void set_claimed_by_bidder(bool val) {
	// 	this->claimed_by_bidder = val;
	// }

} bid_t;

	void set_claimed_by_bidder(bid_t& b, bool val) {
		b.claimed_by_bidder = val;
	}

int main() {
	map<uint64_t, bid_t> map_bidderid_info;

	// bid_t b1{};
	// M-1
/*	b1.claimed_by_bidder = 0;
	b1.bid_crypto_price = "343 EOS";
	b1.bid_fiat_price_usd = 43;
*/	
	// M-2
	bid_t b1{0, "343 EOS", 43};
	map_bidderid_info.insert(make_pair(321432, b1));

	bid_t b2;
	b2.claimed_by_bidder = 1;
	b2.bid_crypto_price = "726 EOS";
	b2.bid_fiat_price_usd = 78;
	map_bidderid_info.insert(make_pair(83567, b2));


	for(auto&& i : map_bidderid_info) {
		std::cout << "{ " << i.first << ", (" << i.second.claimed_by_bidder 
		<< ", " << i.second.bid_crypto_price << "), " << i.second.bid_fiat_price_usd << " },\n";
	}

	return 0;
}