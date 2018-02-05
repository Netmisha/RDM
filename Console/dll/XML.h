#ifndef XML_h_
#define XML_h_
#include"tinyxml.h"
#include"Table.h"

__declspec(dllexport) void CreateXML();
__declspec(dllexport) bool NeedsToBeUpdated(Table& tb);
__declspec(dllexport) void AddStructure(Table& source);
__declspec(dllexport) void AddData(Table& source);
__declspec(dllexport) Table* BuildTable(Table& tb, unsigned int id);
__declspec(dllexport) void DeleteTable(unsigned int id);
__declspec(dllexport) void Clear();
	
#endif