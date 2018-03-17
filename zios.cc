#include <iostream>
#include <stdlib.h>

int main()
{
	constexpr int mx = 52;
	constexpr int zios_legs = 3;
	constexpr int zept_legs = 7;

	for (int zepts = 0; zept_legs*zepts < mx; ++zepts) {
		div_t ans = div(mx - zept_legs*zepts, zios_legs);
		if (ans.rem == 0) {
			std::cout << ans.quot << " zios + " << zepts << " zepts have " << mx << " legs\n";
		}
	}
}
