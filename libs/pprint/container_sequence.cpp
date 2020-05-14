/*
eg 1: matrix 3 x 3
eg 2: vector of pair
*/

#include <pprint/include/pprint.hpp>
#include <boost/assign/list_of.hpp>

using std::string;
using boost::assign::map_list_of;

pprint::PrettyPrinter p;

int main() {
	typedef std::array< std::array<int, 3>, 3> Mat3x3;
	Mat3x3 matrix;
	matrix[0] = {1, 2, 3};
	matrix[1] = {4, 5, 6};
	matrix[2] = {7, 8, 9};

	p.compact(true);
	p.print("Matrix: ", matrix);
	p.compact(false);

	// =============================================
	typedef std::pair<int, string> pair_t;
	std::vector<pair_t> v1 = map_list_of(1, "abhijit") (2, "vincent") (3, "victor") (4, "catherine");

	p.print("Vector: ", v1);

	p.compact(true);
	p.print("Vector: ", v1);
	p.compact(false);



	return 0;
}