#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
	int frequency;
	char data;
public:
	Pair() {}
	Pair(char _data, int _freq);
	~Pair() {}
	Pair(const Pair& other);

	int getFrequency() const { return frequency; }
	char getData() const { return data; }

	bool setData(char c) { data = c; return true; }
	bool setFreq(int freq) { frequency = freq; return true; }

	void increaseFreq() { frequency++; }
	void operator=(const Pair& other);
};

