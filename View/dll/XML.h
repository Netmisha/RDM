#ifndef XML_h_
#define XML_h_
#include"tinyxml.h"
#include"Table.h"

MYLIBRARY_EXPORT void CreateXML();
MYLIBRARY_EXPORT unsigned int Count();
MYLIBRARY_EXPORT bool NeedsToBeUpdated(Table& tb);
MYLIBRARY_EXPORT void AddStructure(Table& source);
MYLIBRARY_EXPORT void AddData(Table& source);
MYLIBRARY_EXPORT Table* BuildTable(Table& tb, unsigned int id);
MYLIBRARY_EXPORT void DeleteTable(unsigned int id);
MYLIBRARY_EXPORT void Clear();
MYLIBRARY_EXPORT std::string& GetName(unsigned int ID);
MYLIBRARY_EXPORT int* GetID();
MYLIBRARY_EXPORT int GetLastID();
MYLIBRARY_EXPORT void GColector();
MYLIBRARY_EXPORT bool IsExist();
MYLIBRARY_EXPORT bool IsEmpty();
	
#endif