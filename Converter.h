#pragma once
//#include "Date.h"
//#include "Fraction.h"
#include "Macro.h"
#include "Standard.h"
#include "State.h"

class Converter
{
public:
	static tuple<State, string> tryParse(string, regex);

public:
	static int parseInt(string str);
	static float parseFloat(string str);
};
