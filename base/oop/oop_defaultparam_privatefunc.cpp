/*

        Learnings:
        - default parameter value should be mentioned in either place (during declaration or definition), not both.
        - private function can only be accessed by the public function 
*/
#include <iostream>

using std::string;

class home
{
private:
    int get_num(){
        return 20;
    }

public:

    void address(string country);                   // Ok
    // void address(string country = "India");     // Ok
    
};


void home::address(string country = "India") {
    std::cout << country << "\n";
    std::cout << get_num() << "\n";
}

int main() {
    home h;
    h.address("France");
    h.address();
    // h.get_num();         // private function can be accessed only from public functions

    return 0;
}