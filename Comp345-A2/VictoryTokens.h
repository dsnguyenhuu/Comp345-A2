#pragma once

class VictoryTokens {
protected:
	int value;
public:
	virtual void setValue(int x) { value = x; };
	int getValue() { return value; };
};

class TenVictoryTokens : public VictoryTokens {
public:
	void setValue(int x) { value = x + 10; };
};

class FiveVictoryTokens : public VictoryTokens {
public:
	void setValue(int x) { value = x + 5; };
};

class ThreeVictoryTokens : public VictoryTokens {
public:
	void setValue(int x) { value = x + 3; };
};

class OneVictoryTokens : public VictoryTokens {
public:
	void setValue(int x) { value = x + 1; };
};

