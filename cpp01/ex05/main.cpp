#include "Harl.hpp"

int main()
{
    Harl h;

    h.complain("Hello");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");
    h.complain("DEBUG");
    h.complain("test");
    return 0;
}