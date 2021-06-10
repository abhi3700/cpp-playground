/*
			ABOUT
			=====
			- The investor is funding in both crypto (many types) & fiat for an asset & instead receives a share from the asset creator's royalty.
			- Each investor has a different user ID
			- So, the data structure is like this:

				{ 43546, {0.05, { (TLOS, 34), }, 4000} }
				{ 213652, {0.2, { (EOS, 24324), (WAX, 243), }, 0.9} }
*/

#include <iostream>
#include <map>
#include <algorithm>



using std::string;
using std::map;
using std::make_pair;

typedef struct {
	float share;
	map<string, uint64_t> fund_crypto; 	// [OPTIONAL] map with extended_symbol, uint64_t. if works fine, otherwise, the transferred amount will be searched by telegram_id from the history api
	float fund_usd;
} investor_t;


// template<typename T1, typename T2>
inline void creatify_investor_map( map<uint64_t, investor_t>& m, uint64_t item_key, const investor_t& item_val, 
									const string& item_val_fcrypto_symbol, uint64_t item_val_fcrypto_qty ) 
{
	// auto s_it = std::find_if(m.begin(), m.end(), [&](auto& ms) {return ms.first == item_key;});
	auto s_it = m.find(item_key);
	if(s_it != m.end()) {		// key found in map
		s_it->second.share += item_val.share;		// add the share

		// auto inv_fundcrypto_it = std::find_if(s_it->second.fund_crypto.begin(), s_it->second.fund_crypto.end(), 
		// 				[&](auto& ms) {return ms.first == item_val_fcrypto_symbol;});			// M-1
		auto inv_fundcrypto_it = s_it->second.fund_crypto.find(item_val_fcrypto_symbol);		// M-2
		if(inv_fundcrypto_it != s_it->second.fund_crypto.end()) {		// fund_crypto key found
			inv_fundcrypto_it->second += item_val_fcrypto_qty;			// add the crypto fund
		}
		else {						// fund_crypto key NOT found
			// s_it->second.fund_crypto.insert( make_pair(extended_symbol(qty.item_val_fcrypto_symbol, get_first_receiver()), qty.amount) );
			s_it->second.fund_crypto.insert( make_pair(item_val_fcrypto_symbol, item_val_fcrypto_qty) );
		}
		s_it->second.fund_usd += item_val.fund_usd;			// add the fiat fund
	}
	else {						// key NOT found in map
		investor_t i1{};
		i1.share = item_val.share;
		i1.fund_crypto.insert(make_pair(item_val_fcrypto_symbol, item_val_fcrypto_qty));
		i1.fund_usd = item_val.fund_usd;
		m.insert( make_pair(item_key, i1) );
	}
}


int main() {
	map<uint64_t, investor_t> map_investorid_info{};

	// ------------------------
	// investor 1
	investor_t i1{};
	i1.share = 0.1;
	i1.fund_usd = 0.45;
	creatify_investor_map(map_investorid_info, 213652, i1, "EOS", 24324);
	creatify_investor_map(map_investorid_info, 213652, i1, "WAX", 243);				// added all share into the previous set value

	// ------------------------
	// investor 2
	investor_t i2{};
	i1.share = 0.05;
	i1.fund_usd = 4000;
	creatify_investor_map(map_investorid_info, 43546, i1, "TLOS", 34);


	// ------------------------
	// display all the investors with it's share, fund_crypto(s), fund_fiatusd
	for(auto&& i : map_investorid_info) {
		std::cout << "{ " << i.first << ", {" << i.second.share << ", { ";
		for (auto&& j : i.second.fund_crypto) {
			std::cout << "(" << j.first << ", " << j.second << "), ";
		}
		std::cout << "}, " << i.second.fund_usd << "} }\n";
	}

	return 0;
}