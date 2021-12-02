#include <iostream>


int main() {

//Task 1
    char c = 0;
    unsigned char uc = 'G';

    int i = 0;
    unsigned ui = 0;
    short s = 0;
    unsigned short us = 0;
    long li = 0;
    unsigned long uli = 0;

    float a = 0.5;
    double pi = 3.14;

    bool check = false;

//Task 2
    enum Motion {empty,zero,cross};
	
//Task 3
	Motion motion[3][3]= {};

//Task 4
    struct Playing_field {
        enum Motion {empty,zero,cross};
        Motion motion[3][3];
        bool win;
    };
	struct Playing_field field;
	
//Task 5
    union choice {
		int i;
		char c;
		float f;
	};
	struct Exdata {
		union choice x; 
		int is_int   : 1; 
		int is_char  : 1;
		int is_float : 1;
	};
	struct Exdata exdata;
	exdata.is_int = 1;		// Флаг того, что член экземпляра exdata - целое число.
	exdata.is_char = 0;		// Флаг того, что член экземпляра exdata - символ.
	exdata.is_float = 0;	// Флаг того, что член экземпляра exdata - вещественное число.
	
    return 0;
}
