#include <stdio.h>
#include "prim.h"
#include "UVOPS.h"

int main(int argc, char* argv[]){
	
	uint32_t rngseed = time(NULL);
	printf("Random Seed: %u\n",rngseed);
	srand(rngseed);

	GenShipOneParams(&shipParams);
	MakeShipOne(&ship,shipParams);
	MergeMesh(ship.nose, ship.mid, &ship.obj,0);
	MergeMesh(ship.obj, ship.tail, &ship.obj,0);
	MergeMesh(ship.obj, ship.wings, &ship.obj,1);
	GenerateUVs(&ship.obj);
	ShipToObj(ship);
	//RenderLoop();
	FreeShip(&ship);
	
	return 1;
	
}


