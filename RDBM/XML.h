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

void AddStructure(Table& source)
{
	TiXmlDocument doc;
	doc.LoadFile("dbstructure.xml");
	TiXmlElement *root = doc.FirstChildElement();
	TiXmlElement *table=new TiXmlElement("Table");
	table->SetAttribute("name",source.GetName());
	table->SetAttribute("ID", source.GetID());
	root->LinkEndChild(table);
	TiXmlElement *record = new TiXmlElement("Record");
	std::vector<char> ctype=source.GetCType();
	std::vector<std::string> cname = source.GetCName();
	for (unsigned int i = 0; i < source.GetCName().size();i++)
	{
		if (ctype[i] == 'i')
		{
			record=new TiXmlElement("Record");
			record->SetAttribute("ID", i+1);
			record->LinkEndChild(new TiXmlText("integer"));
			table->LinkEndChild(record);
		}
		if (ctype[i] == 'd')
		{
			record = new TiXmlElement("Record");
			record->SetAttribute("ID", i+1);
			record->LinkEndChild(new TiXmlText("double"));
			table->LinkEndChild(record);
		}
		if (ctype[i] == 's')
		{
			record = new TiXmlElement("Record");
			record->SetAttribute("ID", i+1);
			record->LinkEndChild(new TiXmlText("string"));
			table->LinkEndChild(record);
		}
	}
	doc.SaveFile("dbstructure.xml");
}
void AddData(Table& source)
{
	TiXmlDocument doc;
	doc.LoadFile("dbdata.xml");
	TiXmlElement *root = doc.FirstChildElement();
	TiXmlElement *table = new TiXmlElement("Table");
	table->SetAttribute("name", source.GetName());
	table->SetAttribute("ID", source.GetID());
	root->LinkEndChild(table);
	TiXmlElement *record = new TiXmlElement("Record");
	std::vector<char> ctype = source.GetCType();
	std::vector<std::string> cname = source.GetCName();
	void* temp;
	for (unsigned int j = 1; j < source.Size()+1; j++)
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
	doc.SaveFile("dbdata.xml");
}
#endif