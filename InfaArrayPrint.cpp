#include "stdafx.h"
#include <fstream>
#include "array.h"
#include"mas_one.h"
#include"mas_double.h"

using namespace std;

namespace arrays 
{
	void ReadMasDouble(mas_double &mas_double, ifstream &ifst);
	void ReadMasOne(mas_one  &mas_one, ifstream &ifst);
	
	array* InfaArrayPrint(ifstream &ifst) 
	{
		array *readarray;
		int key;
		ifst >> key;
		int pr;
		ifst >> pr;
		
		readarray = new array;
		readarray->p = (array::process)pr;

		switch (key) 
		{
		case 1:			
			readarray->key = array::key::Mas_one;
			ReadMasOne(readarray->mas_one, ifst);
			return readarray;
			
		case 2:
			readarray->key = array::key::Mas_double;
			ReadMasDouble(readarray->mas_double, ifst);
			return readarray;
		default:
			return NULL;
		}


		return readarray;
	}
}

