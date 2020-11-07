#include <stdio.h>

double m[] = { 7709179928849219.0, 771 };

void main() {
	//m[1]-- ? m[0]*=2,main() : printf((char*)m);
	if (m[1]-- != 0)
	{
		m[0] *= 2;
		main();
	}
	else
		printf((char*)m);
}