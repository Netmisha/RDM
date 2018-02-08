#include"Logger.h"
#include"Table.h"
#include"XML.h"

#include<sstream>
#include<map>


bool SizeCheck(std::vector<std::string>& vec,int size,std::ostream& out)
{
	if (vec.size() < size)
	{
		out << "please provide full input\n";
		return true;
	}
	else
		return false;
}

void Fill(std::map<int, Table*>& mapa)
{
	int *idarr = new int[Count()];
	idarr = GetID();
	int i = idarr[0];
	int j = 0;
	while (j < Count() )
	{
		j++;
		if (j == Count())
		{
			Table *tb = new Table(GetName(i));
			BuildTable(*tb, i);
			tb->ChangeID(i);
			mapa.insert(std::pair<int, Table*>(idarr[j - 1], tb));
		}
		else
		{
			Table *tb=new Table(GetName(idarr[j-1]));
			BuildTable(*tb, idarr[j - 1]);
			tb->ChangeID(idarr[j - 1]);
			mapa.insert(std::pair<int, Table*>(idarr[j-1], tb));
		}
		
		i = idarr[j];
	}
}

int main(int argc, char** argv)
{
	LOG_INFO("Build started, thread ID=" + std::to_string(GetCurrentThreadId()));
	static int ID = GetLastID() + 1;
	std::map<int, Table*> database;
	Fill(database);
	Logger *log = NULL;
	log = Logger::getInstance();
	log->updateLogLevel(LOG_LEVEL_INFO);
	std::ostream out(nullptr);
	out.rdbuf(std::cout.rdbuf());
	if (!IsExist())
	{
		out << "XML files missing.\nNew dbdata.xml and dbstructure.xml were created automaticaly \n";
		CreateXML();
	}

	bool tablecheck = false;
	Table *tb = new Table("temp_table");
	std::string input;
	out << "create new table(create_t -i)or build table from XML(build_t ID) \n";
	static int xmlTableID = 1;
	static int TID;
	if (argc != 1)
	{
		if (strcmp(argv[1], "create_t") == 0 && strcmp(argv[2], "-i") == 0)
		{
			tablecheck = true;
			std::vector<char> coltypes;
			std::vector<std::string> colnames;
			tb->ChangeName(argv[3]);
			*(argv++);
			*(argv++);
			*(argv++);
			while (*(++argv) != NULL)
			{
				if (strcmp(*argv, "Integer") == 0 || strcmp(*argv, "integer") == 0)
				{
					coltypes.push_back('i');
					colnames.push_back(*(++argv));
				}
				else if (strcmp(*argv, "Double") == 0 || strcmp(*argv, "double") == 0)
				{
					coltypes.push_back('d');
					colnames.push_back(*(++argv));
				}
				else if (strcmp(*argv, "String") == 0 || strcmp(*argv, "string") == 0)
				{
					coltypes.push_back('s');
					colnames.push_back(*(++argv));
				}
			}
			tb->ChangeID(GetLastID() + 1);
			tb->Create(colnames, coltypes);
			out << "table created \n";
			tb->Show(out);
			database.insert(std::pair<int, Table*>(GetLastID() + 1, tb));
			TID = tb->GetID();
		}
		else if (strcmp(argv[1], "build_t") == 0)
		{
			tablecheck = true;
			delete tb;
			int x = atoi(argv[2]);
			tb = database[x];
			xmlTableID = x;
			tb->ChangeID(GetLastID() + 1);
			out << "table built \n";
			tb->Show(out);
			TID = tb->GetID();
		}
		else if (strcmp(argv[1], "create_xml") == 0)
		{
			CreateXML();
		}
	}
	while (true)
	{
		getline(std::cin, input);
		std::string buff;
		std::string output = "";
		std::stringstream ss(input);
		std::vector<std::string> inputs;
		while (ss >> buff)
			inputs.push_back(buff);
		if (inputs[0] == "help")
		{
			out << "\nto work with table:\n";
			out << "\t create_t -i 'table name' 'column type' 'column name'... - create new table\n";
			out << "\t build_t ID - build table from XML\n";
			out << "\t create_xml - create new XML files\n";
			out << "\t clear - clear the content of current table\n";
			out << "\t addrec -i 'value' ... - add new record to current table\n";
			out << "\t addcol 'column type' 'column name' - add new colemn to current table\n";
			out << "\t delrec ID - delete record from current table\n";
			out << "\t delcol ID - delete column from current table\n";
			out << "\t delete_t - delete current table\n";
			out << "\t show -t - show current table content\n";
			out << "\t show -a - show content of all tables\n";
			out << "\t find -d ID - show record at ID position\n";
			out << "\t find -s 'value' - show first record that contain 'value'\n";
			out << "\t findall -s 'value' - show all recolds that contain 'value'\n";
			out << "\t select 'column name' 'column name'-show choosed columns content\n";
			out << "\t set -s rowindex columnindex 'value' -set cell at 'rowindex' 'columnindex' position to value\n";
			out << "\t set -c rowindex 'column name' 'value' - set cell \n";
			out << "\t set -r 'index' 'value' ... - set record with index position 'value'...\n";
			out << "\t update_xml - update content of XML files\n";
			out << "\t get -id - show id of current table\n";
			out << "\t get -name - show name of current table\n";
			out << "\t get -size - show size of current table\n";
			out << "\t inherit_t ID - update current table with table[ID] structure\n";
			out << "\nto work with chosen record:\n";
			out << "\t getrec index - choose record with index posirion\n";
			out << "\t add 'value' - add 'value' to current record\n";
			out << "\t show - show current record\n";
			out << "\t set -s 'ID' 'index' 'value' - set cell in current table record woth position 'index' to 'value'\n";
			out << "\t back - go back to work with table\n";
			out << "\nto work with logger:\n";
			out << "\t logger - go to logger settings\n";
			out << "\t error type 'message' - insert error type message\n";
			out << "\t alarm type 'message' - insert alarm type message\n";
			out << "\t always type 'message' - insert always type message\n";
			out << "\t info type 'message' - insert info type message\n";
			out << "\t buffer type 'message' - insert buffer type message\n";
			out << "\t trace type 'message' - insert trace type message\n";
			out << "\t debug type 'message' - insert debug typemessage\n";
			out << "\t update_log_level 'level type' - change logging level to 'level type'\n";
			out << "\n\t level types:\n";
			out << "\t\t disable\n";
			out << "\t\t level_info\n";
			out << "\t\t level_buffer\n";
			out << "\t\t level_trace\n";
			out << "\t\t level_debug\n";
			out << "\t\t enable\n";
			out << "\n\t update_log_type 'log type' - change logging type typ 'log type'\n";
			out << "\n\t log levels:\n";
			out << "\t\t console - log into console\n";
			out << "\t\t file - log into logfile\n";
			out << "\t\t no_log - disable logging\n";
			out << "\t back - go back to work with table\n";
		}
		else if (inputs[0] == "show")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			if (inputs[1] == "-a")
			{
				int i = 0;
				for (auto p = database.begin(); p != database.end(); p++)
				{
					i = p->first;
					out << database[i]->GetName() << " ID=" << database[i]->GetID() << "\n";
					database[i]->Show(out);
					out << "\n";
				}
			}
			else if (inputs[1] == "-t")
			{
				if (!tablecheck)
				{
					out << "there is no current table,please create or build one\n";
					continue;
				}
				out << "Table " << tb->GetName() << " ID=" << tb->GetID() << "\n";
				tb->Show(out);
			}
		}

		else if (inputs[0] == "logger")
		{
			out << "you now work with logger\n";
			std::string loginput;
			while (true)
			{
				getline(std::cin, loginput);
				std::string logbuff;
				std::stringstream logss(loginput);
				std::vector<std::string> loginputs;
				while (logss >> logbuff)
					loginputs.push_back(logbuff);
				if (loginputs[0] == "error")
				{
					for (unsigned int i = 1; i < loginputs.size(); i++)
					{
						output += loginputs[i] + " ";
					}
					LOG_ERROR(output);
				}
				else if (loginputs[0] == "alarm")
				{
					for (unsigned int i = 1; i < loginputs.size(); i++)
					{
						output += loginputs[i] + " ";
					}
					LOG_ALARM(output);
				}
				else if (loginputs[0] == "always")
				{
					for (unsigned int i = 1; i < loginputs.size(); i++)
					{
						output += loginputs[i] + " ";
					}
					LOG_ALWAYS(output);
				}
				else if (loginputs[0] == "info")
				{
					for (unsigned int i = 1; i < loginputs.size(); i++)
					{
						output += loginputs[i] + " ";
					}
					LOG_INFO(output);
				}
				else if (loginputs[0] == "buffer")
				{
					for (unsigned int i = 1; i < loginputs.size(); i++)
					{
						output += loginputs[i] + " ";
					}
					LOG_BUFFER(output);
				}
				else if (loginputs[0] == "trace")
				{
					for (unsigned int i = 1; i < loginputs.size(); i++)
					{
						output += loginputs[i] + " ";
					}
					LOG_TRACE(output);
				}
				else if (loginputs[0] == "debug")
				{
					for (unsigned int i = 1; i < loginputs.size(); i++)
					{
						output += loginputs[i] + " ";
					}
					LOG_DEBUG(output);
				}
				else if (loginputs[0] == "update_log_level")
				{
					if (loginputs[1] == "disable")
					{
						LOG_ALARM("LOG_LEVEL changed to DISABLE");
						log->updateLogLevel(DISABLE_LOG);
					}
					else if (loginputs[1] == "level_info")
					{
						LOG_ALARM("LOG_LEVEL changed to INFO");
						log->updateLogLevel(LOG_LEVEL_INFO);
					}
					else if (loginputs[1] == "level_buffer")
					{
						LOG_ALARM("LOG_LEVEL changed to BUFFER");
						log->updateLogLevel(LOG_LEVEL_BUFFER);
					}
					else if (loginputs[1] == "level_trace")
					{
						LOG_ALARM("LOG_LEVEL changed to TRACE");
						log->updateLogLevel(LOG_LEVEL_TRACE);
					}
					else if (loginputs[1] == "level_debug")
					{
						LOG_ALARM("LOG_LEVEL changed to DEBUG");
						log->updateLogLevel(LOG_LEVEL_DEBUG);
					}
					else if (loginputs[1] == "enable")
					{
						LOG_ALARM("LOG_LEVEL changed to ENABLE");
						log->updateLogLevel(ENABLE_LOG);
					}
				}
				else if (loginputs[0] == "update_log_type")
				{
					if (loginputs[1] == "console")
					{
						LOG_ALARM("log type changed to CONSOLE");
						log->updateLogType(CONSOLE);
					}
					else if (loginputs[1] == "file")
					{
						LOG_ALARM("log type changed to FILE");
						log->updateLogType(FILE_LOG);
					}
					else if (loginputs[1] == "no_log")
					{
						LOG_ALARM("log type changed to NO_LOG");
						log->updateLogType(NO_LOG);
					}
				}
				else if (loginputs[0] == "back")
				{
					out << "you now work with table\n";
					break;
				}
			}
		}
		else if (inputs[0] == "create_xml")
		{
			CreateXML();
			out << "XML files created\n";
		}
		else if (inputs[0] == "create_t" && inputs[1] == "-i")
		{
			if (SizeCheck(inputs, 5, out))
				continue;
			tablecheck = true;
			tb = new Table(inputs[2]);
			std::vector<char> coltypes;
			std::vector<std::string> colnames;
			for (unsigned int i = 3; i < inputs.size(); i++)
			{
				if (i % 2 == 0)
					colnames.push_back(inputs[i]);
				else
				{
					if (inputs[i] == "Integer" || inputs[i] == "integer")
						coltypes.push_back('i');
					else if (inputs[i] == "Double" || inputs[i] == "double")
						coltypes.push_back('d');
					else if (inputs[i] == "String" || inputs[i] == "string")
						coltypes.push_back('s');
				}
			}
			tb->ChangeID(ID);
			tb->Create(colnames, coltypes);
			out << "table created \n";
			tb->Show(out);
			xmlTableID = tb->GetID();
			database.insert(std::pair<int, Table*>(ID++, tb));
			TID = tb->GetID();
		}
		else if (inputs[0] == "build_t")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			bool check = false;
			int *idarr = GetID();
			for (unsigned int i = 1; i < database.size() + 1; i++)
			{
				if (database[idarr[i - 1]]->GetID() == std::stoi(inputs[1]))
					check = true;
			}
			if (!check)
			{
				out << "there is no table with " << inputs[1] << " ID\n";
				continue;
			}
			else
			{
				tablecheck = true;
				int x = stoi(inputs[1]);
				tb = database[x];
				xmlTableID = x;
				out << "table built \n";
				tb->Show(out);
				TID = tb->GetID();
			}
		}
		else if (inputs[0] == "update_xml")
		{
			int i = 0;
			for (auto p = database.begin(); p != database.end(); p++)
			{
				i = p->first;
				AddData(*database[i]);
				AddStructure(*database[i]);
				GColector();
			}
			out << "XML updated \n";
		}
		else if (inputs[0] == "delete_t")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			bool check = false;
			if (database.count(std::stoi(inputs[1])) == 1)
				check = true;
			if (!check)
			{
				out << "there is no table with " << inputs[1] << " ID\n";
				continue;
			}
			else
			{
				out << "Table " << database[std::stoi(inputs[1])]->GetName() << " deleted \n";
				database.erase(std::stoi(inputs[1]));
				tablecheck = false;
				//int *idarr = GetID();
			}
		}
		else if (inputs[0] == "end")
			break;
		if (!tablecheck)
		{
			out << "there is no current table, please create or build one to proceed(show -a to show all tables)\n";
		}
		else if (inputs[0] == "addrec" && inputs[1] == "-i")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			std::string temp;
			getline(std::cin, temp);
			std::string buff2;
			std::stringstream ss2(temp);
			std::vector<std::string> values;
			int i = 0;
			std::vector<char> types = tb->GetCType();
			while (ss2 >> buff2)
				values.push_back(buff2);
			if (values.size() < types.size())
			while (values.size() < types.size())
			{
				if (types[values.size()] == 'i')
					values.push_back("0");
				else if (types[values.size()] == 'd')
					values.push_back("0");
				else if (types[values.size()] == 's')
					values.push_back("_");
			}
			else if (values.size()>types.size())
			while (values.size() > types.size())
			{
				values.erase(values.begin() + values.size() - 1);
			}
			while (i < values.size())
			{
				if (types[i] == 'i'&&TypeFinder(values[i]) != 'i')
					values[i] = "0";
				else if (types[i] == 'd' && (TypeFinder(values[i]) != 'd' && TypeFinder(values[i]) != 'i'))
					values[i] = "0";
				else if (types[i] == 's'&&TypeFinder(values[i]) != 's')
					values[i] = "_";
				i++;
			}
			tb->AddRecord(values);
			database[TID] = tb;
			out << "new record added \n";
		}
		else if (inputs[0] == "addcol")
		{
			if (SizeCheck(inputs, 3, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			std::string type;
			if (inputs[1] == "integer")
			{
				type = "integer";
				tb->AddColumn(type, inputs[2]);
			}
			else if (inputs[1] == "double")
			{
				type = "double";
				tb->AddColumn(type, inputs[2]);
			}
			else if (inputs[1] == "string")
			{
				type = "string";
				tb->AddColumn(type, inputs[2]);
			}
			out << "new column added\n";
		}
		else if (inputs[0] == "delrec")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			std::string::size_type sz;
			tb->DeleteRecord(std::stoi(inputs[1], &sz));
			out << "record deleted\n";
		}
		else if (inputs[0] == "delcol")
		{
			if (SizeCheck(inputs, 3, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			if (inputs[1] == "id")
				tb->DeleteColumn(std::stoi(inputs[2]));
			else if (inputs[1] == "-s")
				tb->DeleteColumn(inputs[2]);
			out << "column deleted \n";
		}
		else if (inputs[0] == "find")
		{
			if (SizeCheck(inputs, 3, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			std::string::size_type sz;
			if (inputs[1] == "-d")
				tb->FindRecord(std::stoi(inputs[2], &sz))->Show(out);
			else if (inputs[1] == "-s")
				tb->FindRecord(inputs[2])->Show(out);
		}
		else if (inputs[0] == "select")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			std::vector<std::string> columns;
			for (unsigned int i = 1; i < inputs.size(); i++)
			{
				columns.push_back(inputs[i]);
			}
			tb->Select(columns, out);
		}

		else if (inputs[0] == "findall" && inputs[1] == "-s")
		{
			if (SizeCheck(inputs, 3, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			tb->FindRecords(inputs[2], out);
		}
		else if (inputs[0] == "clear")
		{
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			tb->Clear();
			out << "table cleared";
		}
		else if (inputs[0] == "set")
		{
			if (SizeCheck(inputs, 5, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			if (std::stoi(inputs[2]) > tb->GetCName().size())
			{
				out << "there is no record with " << inputs[2] << " index\n";
				continue;
			}
			if (inputs[1] == "-s")
			{
				tb->Set(std::stoi(inputs[2]), std::stoi(inputs[3]), inputs[4]);
				out << "new value set \n";
			}
			else if (inputs[1] == "-c")
			{
				tb->Set(std::stoi(inputs[2]), inputs[3], inputs[4]);
				out << "new value set \n";
			}
			else if (inputs[1] == "-r")
			{
				for (unsigned int i = 3; i < inputs.size(); i++)
				{
					if (i>tb->GetCName().size() + 2)
						continue;
					else
						tb->Set(std::stoi(inputs[2]), i - 2, inputs[i]);
				}
			}
		}
		else if (inputs[0] == "inherit_t")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			tb->AddTable(*database[std::stoi(inputs[1])]);
			out << "table inherited \n";
		}
		else if (inputs[0] == "get")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			if (!tablecheck)
			{
				out << "there is no current table,please create or build one\n";
				continue;
			}
			if (inputs[1] == "-id")
				out << tb->GetID() << "\n";
			else if (inputs[1] == "-name")
				out << tb->GetName() << "\n";
			else if (inputs[1] == "-size")
				out << tb->Size() << "\n";
		}
		else if (inputs[0] == "getrec")
		{
			if (SizeCheck(inputs, 2, out))
				continue;
			if (!tablecheck)
			{
				out << "you need a table first, please create or build one\n";
				continue;
			}
			else
			{
				out << "you now work with record\n";
				while (true)
				{
					std::string temp;
					getline(std::cin, temp);
					std::string buff3;
					std::stringstream ss3(temp);
					std::vector<std::string> input;
					while (ss3 >> buff3)
						input.push_back(buff3);
					if (input[0] == "add")
						tb->GetRecord(std::stoi(inputs[1]))->Add(input[1]);
					else if (input[0] == "show")
						tb->GetRecord(std::stoi(inputs[1]))->Show(out);
					else if (input[0] == "set")
					{
						if (SizeCheck(inputs, 3, out))
							continue;
						if (input[1] == "-s")
							tb->GetRecord(std::stoi(inputs[1]))->Set(std::stoi(input[2]), input[3]);
					}
					else if (input[0] == "back")
					{
						out << "you now work with tables\n";
						break;
					}
				}
			}
		}

	}
	LOG_INFO("Build ended, thread ID=" + std::to_string(GetCurrentThreadId()));
	return 0;
}