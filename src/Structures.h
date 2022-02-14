#pragma once

struct Locator {
	float position[3];   // 3 * 4 = 12 octets
	float rotation[3];   // 3 * 4 = 12 octets
	float proportion[3]; // 3 * 4 = 12 octets
};                       //       = 36 octets

