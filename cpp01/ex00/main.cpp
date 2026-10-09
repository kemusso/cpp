#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heapZombie = newZombie("Heap");

	heapZombie->announce();
	randomChump("Stack");
	delete heapZombie;
	return 0;
}
