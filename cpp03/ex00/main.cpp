#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("p1");
	ClapTrap b("p2");

	ClapTrap c(a);

	c.info();
	b.info();
	c.attack(b.get_name());
	b.takeDamage(c.get_att_damage());
	b.beRepaired(2);
	c.info();
	b.info();
}