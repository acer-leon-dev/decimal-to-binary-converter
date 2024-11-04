#include "binary.hpp"
#include <math.h>

// Scratch variables:
//     decimal
//     binary_characters
//     number_binary_power
//     count
//     exponent
//     value
std::string int_to_binary(int decimal) {
	int number_binary_power = 0;
	std::string binary_characters = "";
	while (!(pow(2, number_binary_power) > decimal)) {
		number_binary_power++;
	}
	// ^^^ Scratch implementation ^^^
	// set(binary_characters, "")
	// set(number_binary_power, 0)
	// repeat_until (10^(number_binary_power * (log10(abs(2)))) > decimal) {
	//     set(number_binary_power, number_binary_power + 1)
	// }

	int count = 0;
	for (int exponent = number_binary_power; exponent >= 0; exponent--) {
		int value = pow(2, exponent);
		if (count + value > decimal) {
			if (count != 0) {
				binary_characters += ('0');
			}
		} else {
			count += value;
			binary_characters += ('1');
		}
	}
	// ^^^ Scratch implementation ^^^
	// set(count, 0)
	// set(exponent, number_binary_power)
	// repeat_until (exponent < 0) {
	//     set(value, (10_exp(exponent * (log_of(abs_of(2))))))
	//     if (count + value > decimal) then {
	//         if (not(count = 0)) then {
	//             set(binary_characters, join(binary_characters, '0'))
	//         }
	//     } else {
	//         count = count + value;
	//         set(binary_characters, join(binary_characters, '1'))
	//     }
	//     set(exponent, exponent - 1)
	// }

	return binary_characters;
}