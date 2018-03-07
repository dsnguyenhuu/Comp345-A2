#pragma once

#include "VictoryTokens.h"
#include <vector>
#include <string>

using namespace std;

class VictoryTokenPack {
private:
	vector<VictoryTokens*>  v10TokenPack;
	vector<VictoryTokens*>  v5TokenPack;
	vector<VictoryTokens*>  v3TokenPack;
	vector<VictoryTokens*>  v1TokenPack;

public:
	VictoryTokenPack();
	void printRemainingTokens();

	vector<VictoryTokens*> tokenAllocate(int x);
	
};
