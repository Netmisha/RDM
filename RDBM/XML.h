#ifndef XML_h_
#define XML_h_
#include"Debug\tinyxml.h"
#include"Table.h"

void XMLDecl()
{
	TiXmlDocument doc;
	doc.LoadFile("dbdata.xml");
	TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "UTF-8", "");
	doc.LinkEndChild(decl);
	TiXmlElement *list = new TiXmlElement("List");
	doc.LinkEndChild(list);
	doc.SaveFile("dbdata.xml");

	TiXmlDocument doc2;
	doc2.LoadFile("dbstructure.xml");
	TiXmlDeclaration *decl2 = new TiXmlDeclaration("1.0", "UTF-8", "");
	doc2.LinkEndChild(decl2);
	TiXmlElement *list2 = new TiXmlElement("List");
	doc2.LinkEndChild(list2);
	doc2.SaveFile("dbstructure.xml");
}

bool check(Table& tb)
{
	TiXmlDocument doc;
	doc.LoadFile("dbstructure.xml");
	std::vector<std::string> names;
	std::vector<char> types;

	TiXmlElement *root = doc.RootElement();
	if (NULL != root)
	{
		TiXmlElement *table = root->FirstChildElement("Table");
		if (NULL != table)
		{
			while (table)
			{
				const char *at = table->Attribute("ID");
				int at2 = tb.GetID();
				std::string str = std::to_string(at2);
				const char *at3 = str.c_str();
				if (strcmp(at, at3) == 0)
				{
					return false;
				}
				table = table->NextSiblingElement();
			}
		}

	}
	return true;
}

void AddStructure(Table& source)
{
	TiXmlDocument doc;
	doc.LoadFile("dbstructure.xml");
	TiXmlElement *root = doc.RootElement();
	if (NULL != root)
	{
		if (check(source))
		{
			TiXmlElement *table = new TiXmlElement("Table");
			table->SetAttribute("name", source.GetName());
			table->SetAttribute("ID", source.GetID());
			root->LinkEndChild(table);
			TiXmlElement *record = new TiXmlElement("Record");
			std::vector<char> ctype = source.GetCType();
			std::vector<std::string> cname = source.GetCName();
			for (unsigned int i = 0; i < source.GetCName().size(); i++)
			{
				if (ctype[i] == 'i')
				{
					record = new TiXmlElement("Record");
					record->SetAttribute("ID", i + 1);
					TiXmlElement *type = new TiXmlElement("Type");
					type->LinkEndChild(new TiXmlText("Integer"));
					record->LinkEndChild(type);
					TiXmlElement *name = new TiXmlElement("Name");
					name->LinkEndChild(new TiXmlText(cname[i].c_str()));
					record->LinkEndChild(name);
					table->LinkEndChild(record);
				}
				if (ctype[i] == 'd')
				{
					record = new TiXmlElement("Record");
					record->SetAttribute("ID", i + 1);
					TiXmlElement *type = new TiXmlElement("Type");
					type->LinkEndChild(new TiXmlText("Double"));
					record->LinkEndChild(type);
					TiXmlElement *name = new TiXmlElement("Name");
					name->LinkEndChild(new TiXmlText(cname[i].c_str()));
					record->LinkEndChild(name);
					table->LinkEndChild(record);
				}
				if (ctype[i] == 's')
				{
					record = new TiXmlElement("Record");
					record->SetAttribute("ID", i + 1);
					TiXmlElement *type = new TiXmlElement("Type");
					type->LinkEndChild(new TiXmlText("String"));
					record->LinkEndChild(type);
					TiXmlElement *name = new TiXmlElement("Name");
					name->LinkEndChild(new TiXmlText(cname[i].c_str()));
					record->LinkEndChild(name);
					table->LinkEndChild(record);
				}
			}
		}
		else
		{
			TiXmlElement *table = root->FirstChildElement("Table");
			while (table)
			{
				const char *at = table->Attribute("ID");
				int at2 = source.GetID();
				std::string str = std::to_string(at2);
				const char *at3 = str.c_str();
				if (strcmp(at, at3) == 0)
				{

				}
				else
				{
					table = table->NextSiblingElement(); /// -?mb root->next
					std::cout << "got it\n";
				}
			}
		}
	}
	doc.SaveFile("dbstructure.xml");
}
void AddData(Table& source)
{
	TiXmlDocument doc;
	doc.LoadFile("dbdata.xml");
	TiXmlElement *root = doc.RootElement();
	if (NULL != root)
	{
		if (check(source))
		{
			TiXmlElement *table = new TiXmlElement("Table");
			table->SetAttribute("name", source.GetName());
			table->SetAttribute("ID", source.GetID());
			root->LinkEndChild(table);
			TiXmlElement *record = new TiXmlElement("Record");
			std::vector<char> ctype = source.GetCType();
			std::vector<std::string> cname = source.GetCName();
			void* temp;
			for (unsigned int j = 1; j < source.Size() + 1; j++)
			{
				TiXmlElement *value = new TiXmlElement("Value");
				record = new TiXmlElement("Record");
				for (unsigned int i = 0; i < source.GetCName().size(); i++)
				{
					if (ctype[i] == 'i')
					{
						temp = source.GetRecord(j)->record[i]->Getv();
						int val = *(int*)temp;
						value->LinkEndChild(new TiXmlText(std::to_string(val).c_str()));
						record->LinkEndChild(value);
						if (i != source.GetCName().size() - 1)
						{
							value = new TiXmlElement("Value");
						}

					}
					else if (ctype[i] == 'd')
					{
						temp = source.GetRecord(j)->record[i]->Getv();
						double val = *(double*)temp;
						value->LinkEndChild(new TiXmlText(std::to_string(val).c_str()));
						record->LinkEndChild(value);
						if (i != source.GetCName().size() - 1)
						{
							value = new TiXmlElement("Value");
						}
					}
					else if (ctype[i] == 's')
					{
						temp = source.GetRecord(j)->record[i]->Getv();
						std::string val = *(std::string*)temp;
						value->LinkEndChild(new TiXmlText(val.c_str()));
						record->LinkEndChild(value);
						if (i != source.GetCName().size() - 1)
						{
							value = new TiXmlElement("Value");
						}
					}

				}
				table->LinkEndChild(record);
			}
		}
		else
		{
			TiXmlElement *table = root->FirstChildElement("Table");
			while (table)
			{
				const char *at = table->Attribute("ID");
				int at2 = source.GetID();
				std::string str = std::to_string(at2);
				const char *at3 = str.c_str();
				if (strcmp(at, at3) == 0)
				{

				}
				else
				{
					table = table->NextSiblingElement(); /// -?mb root->next
					std::cout << "got it\n";
				}
			}
		}
	}
	doc.SaveFile("dbdata.xml");
}

Table* BuildTable(Table& tb)
{
	TiXmlDocument doc;
	doc.LoadFile("dbstructure.xml");
	std::vector<std::string> names;
	std::vector<char> types;
	
	TiXmlElement *root = doc.RootElement();
	if (NULL != root)
	{
		TiXmlElement *table = root->FirstChildElement("Table");
		if (NULL != table)
		{
			while (table)
			{
				TiXmlElement *record = table->FirstChildElement("Record");
				while (record)
				{
					TiXmlElement *type = record->FirstChildElement("Type");
					std::cout << type->GetText() << " ";
					TiXmlElement *name = record->FirstChildElement("Name");
					std::cout << name->GetText() << " ";
					names.push_back(name->GetText());
					std::string stype = type->GetText();
					if (stype == "Integer")
						types.push_back('i');
					else if (stype == "Double")
						types.push_back('d');
					else if (stype == "String")
						types.push_back('s');
					record = record->NextSiblingElement();
				}
				std::cout << std::endl;
				table = table->NextSiblingElement();
			}
		}
	}
	tb.Create(names, types);
	doc.LoadFile("dbdata.xml");
	root = doc.RootElement();
	if (NULL != root)
	{
		TiXmlElement *table = root->FirstChildElement("Table");
		if (NULL != table)
		{
			while (table)
			{
				TiXmlElement *record = table->FirstChildElement("Record");
				while (record)
				{
					TiXmlElement *value = record->FirstChildElement("Value");
					while (value)
					{
						std::cout << value->GetText() << " ";
						value = value->NextSiblingElement();
					}
					record = record->NextSiblingElement();
					std::cout << std::endl;
				}
				std::cout << std::endl;
				table = table->NextSiblingElement();
			}
		}
	}
	return nullptr;
}

#endif