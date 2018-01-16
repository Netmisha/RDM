#ifndef XML_h_
#define XML_h_
#include"Debug\tinyxml.h"
#include"Table.h"

void XMLDecl()
{
	TiXmlDocument doc;
	doc.LoadFile("dbstructure.xml");
	TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "UTF-8", "");
	doc.LinkEndChild(decl);
	TiXmlElement *list = new TiXmlElement("List");
	doc.LinkEndChild(list);
	doc.SaveFile("dbstructure.xml");
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
	TiXmlElement *table = new TiXmlElement("Table");
	table->SetAttribute("name", source.GetName());
	table->SetAttribute("ID", source.GetID());
	doc.LinkEndChild(table);
	TiXmlElement *record = new TiXmlElement("Record");
	std::vector<char> ctype = source.GetCType();
	std::vector<std::string> cname = source.GetCName();
	//for (unsigned int i = 0; i < source.GetCName().size(); i++)
	{
	//	if (ctype[i]=='i')
	}
}
#endif