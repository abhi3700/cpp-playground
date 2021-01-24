/*
      Vector
      - emplace front

*/

// vector::emplace
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;

int main ()
{
  std::vector<int> myvector = {10,20,30};

  std::vector<int> new_vector = {50, 40};
	new_vector.emplace(new_vector.begin(), myvector.back());		// add the winner's last one to the loser's front side, which actually belonged to the loser
	
  for(auto&& i : new_vector) {
		std::cout << i << "\n";
	}

  return 0;
}