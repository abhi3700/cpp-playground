#include <eigen/Dense>
#include <iostream>

using Eigen::MatrixXd;

int main() {
	MatrixXd m(3, 3);

	// setting & displaying values for the matrix
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m(i, j) = i + j;
			std::cout << m(i, j) << " ";
		}
		std::cout << "\n";
	}


	return 0;
}