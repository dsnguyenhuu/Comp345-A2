#include "VictoryTokenPack.h"
#include <iostream>

using namespace std;

VictoryTokenPack::VictoryTokenPack() {
	int tens, fives, threes, ones, i;
	tens = 30;
	fives = 24;
	threes = 20;
	ones = 35;

	for (i = 0; i < tens; i++) {
	v10TokenPack.push_back(new TenVictoryTokens);
	v10TokenPack[i]->setValue(0);
	}

	for (i = 0; i < fives; i++) {
		v5TokenPack.push_back(new FiveVictoryTokens);
		v5TokenPack[i]->setValue(0);
	}

	for (i = 0; i < threes; i++) {
		v3TokenPack.push_back(new ThreeVictoryTokens);
		v3TokenPack[i]->setValue(0);
	}

	for (i = 0; i < ones; i++) {
		v1TokenPack.push_back(new OneVictoryTokens);
		v1TokenPack[i]->setValue(0);
	}

}

void VictoryTokenPack::printRemainingTokens() {
	int tens, fives, threes, ones;
	tens = v10TokenPack.size();
	fives = v5TokenPack.size();
	threes = v3TokenPack.size();
	ones = v1TokenPack.size();

	cout << "There are:" << endl;
	cout << tens << " TenVictoryCoins left" << endl;
	cout << fives << " FiveVictoryCoins left" << endl;
	cout << threes << " ThreeVictoryCoins left" << endl;
	cout << ones << " OneVictoryCoins left" << endl;
}

vector<VictoryTokens*> VictoryTokenPack::tokenAllocate(int x) {

	vector<VictoryTokens*> out;

	int num10, num5, num3, num1;
	num10 = x / 10;
	if (num10 * 10 != x) {
		num5 = (x % 10) / 5;
		if (num5 * 5 + num10 * 10 != x) {
			num3 = (x - (num10 * 10 + num5 * 5)) / 3;
			if (num10 * 10 + num5 * 5 + num3 * 3 != x) {
				num1 = x - (num10 * 10 + num5 * 5 + num3 * 3);
			}
		}
	}

	int i;

	if (num10 > v10TokenPack.size()) {
		for (i = 0; i < v10TokenPack.size(); i++) {
			out.push_back(v10TokenPack.pop_back);
		}

		int left = (num10 - v10TokenPack.size())*2;
		if (left > v5TokenPack.size()) {
			for (i = 0; i < v5TokenPack.size(); i++) {
				out.push_back(v5TokenPack.pop_back);
			}

			int left3 = (left - v5TokenPack.size())%3;
			if (left3 > v3TokenPack.size()) {
				for (i = 0; i < v3TokenPack.size(); i++) {
					out.push_back(v3TokenPack.pop_back);
				}
				int left1 = (left3 - v3TokenPack.size()) * 3;
				for (i = 0; i < left1; i++) {
					out.push_back(v1TokenPack.pop_back);
				}
			}
			else {
				for (i = 0; i < left3; i++) {
					out.push_back(v3TokenPack.pop_back);
				}
				int left1 = (left3 - v3TokenPack.size()) * 3;
				for (i = 0; i < left1; i++) {
					out.push_back(v1TokenPack.pop_back);
				}
			}

		}
		else {
			for (i = 0; i < left; i++) {
				out.push_back(v5TokenPack.pop_back);
			}
		}
	}
	else {
		for (i = 0; i < num10; i++) {
			out.push_back(v10TokenPack.pop_back);
		}
	}
	
	if (num5 <= v5TokenPack.size()) {
		for (i = 0; i < num5; i++) {
			out.push_back(v5TokenPack.push_back);
		}
	}
	else {
		for (i = 0; i < v5TokenPack.size(); i++) {
			out.push_back(v5TokenPack.push_back);
		}
		int left3 = (num5 - v5TokenPack.size());
	}


	return out;
}