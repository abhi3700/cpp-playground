#include <pprint/include/pprint.hpp>

pprint::PrettyPrinter p;


struct Vector3
{
	int x, y, z;
};

struct Mesh
{
	std::vector<Vector3> vertices;
};

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
	pprint::PrettyPrinter p(os);
	p.print_inline(std::make_tuple(v.x, v.y, v.z));
	return os;
}

std::ostream& operator<<(std::ostream& os, const Mesh& mesh) {
	pprint::PrettyPrinter p(os);
	p.print("Mesh {");
	p.indent(2);
	p.print_inline("vertices: ", mesh.vertices);
	p.print("}");
	return os;
}

int main() {
	Mesh mesh = {{
		{0, 0, 1},
		{0, 1, 1},
		{1, 0, 1},
		{1, 1, 1},
		{1, 1, 0},
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	}};

	p.print(mesh);

	return 0;
}