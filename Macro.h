#pragma once
#include "Standard.h"

// Regex Patterns

#define WORDS "(?! )[A-z ]+"
#define NUMBERS "-?[0-9]+"
#define FLOAT "-?[0-9]+\\.{1}[0-9]+"

#define DAILY_EMPLOYEE "DailyEmployee"
#define HOURLY_EMPLOYEE "HourlyEmployee"
#define PRODUCT_EMPLOYEE "ProductEmployee"
#define MANAGER "Manager"

#define NAME " [A-z ]+"
#define PAYMENT "[0-9]+(?:\\$)"
#define UNIT "s=[0-9]+"

