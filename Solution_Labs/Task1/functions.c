#include "functions.h"

double calc_bmr(int sex, double weight, double height, double age) {

	if (!sex) { // if male

		return 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	}

	return 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
}

double calc_cals(int activity, double bmr) {

	if (activity == 1) {
		return bmr * 1.2;
	}
	else if (activity == 2) {
		return bmr * 1.375;
	}
	else if (activity == 3) {
		return bmr * 1.55;
	}
	else if (activity == 4) {
		return bmr * 1.725;
	}
	else {
		return bmr * 1.9;
	}
}