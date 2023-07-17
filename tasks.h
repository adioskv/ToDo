#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
using namespace std;

class Tasks
{
public:
	Tasks();
	Tasks(const filesystem::path& path);
	int get_size() const;
	filesystem::path getPath() const;
	void setPath(filesystem::path& ph);
	void setPath(string ph);
	void show_all() const;
	void show_folder(int i) const;
	void show_file(int folder, int file) const;
	~Tasks() = default;
private:
	struct Folder
	{
		string name;
		filesystem::path path;
		vector<filesystem::path> files;
		void clear()
		{
			path.clear();
		}
		bool is_empty() const
		{
			return files.size() == 0;
		}
		void show() const
		{
			if (this->is_empty())
			{
				std::cout << "\tFolder is empty.\n";
				return;
			}
			int counter = 1;
			for (const auto& file : files)
			{
				std::cout << '\t' << counter++ << " - " << file.stem() << std::endl;
			}
		}
		void show_file(int i) const 
		{
			if (files[i].empty())
			{
				std::cout << "\tFile is empty.\n";
				return;
			}
			i--;
			cout << name << " -> " << files[i].stem() << '\n';
			ifstream input;
			input.open(files[i]);
			if (!input.is_open())
			{
				cout << "file is not found.";
				return;
			}
			string text;
			while (getline(input, text)) 
			{
				cout << '\t' + text << endl;
			}
			input.close();
		}
	};
	filesystem::path path;
	vector<Folder> folders;
};