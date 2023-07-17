#include "tasks.h"
#include <iterator>
#include <cctype>

Tasks::Tasks() 
{
	filesystem::path path{filesystem::current_path() };
	this->path = filesystem::current_path();
	if (!(filesystem::exists(path.string() + "\\myTODO")))
	{
		filesystem::create_directory("myTODO");
	}
	for (const filesystem::path& file : filesystem::directory_iterator(path.string() + "\\myTODO"))
	{
		if (file.extension() == "")
		{
			Folder f;
			f.path = file;
			f.name = file.stem().string();
			for (const filesystem::path& file : filesystem::directory_iterator(file))
			{
				if (file.extension() == ".txt")
				{
					f.files.push_back(file);
				}
			}
			folders.push_back(f);
		}
	}
}
Tasks::Tasks(const filesystem::path &path_)
{
	if (filesystem::exists(path_.string() + "\\myTODO"))
	{
		this->path = path_;

		for (const filesystem::path& file : filesystem::directory_iterator(path.string() + "\\myTODO"))
		{
			if (file.extension() == "")
			{
				Folder f;
				f.path = file;
				f.name = file.stem().string();
				for (const filesystem::path& file : filesystem::directory_iterator(file))
				{
					if (file.extension() == ".txt")
					{
						f.files.push_back(file);
					}
				}
				folders.push_back(f);
			}
		}
	}
}
int Tasks::get_size() const
{
	return folders.size();
}
filesystem::path Tasks::getPath() const
{
	return path;
}
void Tasks::setPath(filesystem::path& path_) 
{
	this->path = path_;
	folders.clear();
	for (const filesystem::path& file : filesystem::directory_iterator(path_.string() + "\\myTODO"))
	{
		if (file.extension() == "")
		{
			Folder f;
			f.path = file;
			f.name = file.stem().string();
			if (file.empty())
			{
				continue;
			}
			else
			{
				for (const filesystem::path& file : filesystem::directory_iterator(file))
				{
					if (file.extension() == ".txt")
					{
						f.files.push_back(file);
					}
				}
			}
			folders.push_back(f);
		}
	}
}
void Tasks::setPath(string path_)
{
	this->path = path_;
	folders.clear();
	for (const filesystem::path& file : filesystem::directory_iterator(path_ + "\\myTODO"))
	{
		if (file.extension() == "")
		{
			Folder f;
			f.path = file;
			f.name = file.stem().string();
			if (file.empty())
			{
				continue;
			}
			else
			{
				for (const filesystem::path& file : filesystem::directory_iterator(file))
				{
					if (file.extension() == ".txt")
					{
						f.files.push_back(file);
					}
				}
			}
			folders.push_back(f);
		}
	}
}
void Tasks::show_all() const 
{
	int counter = 1;
	for (const auto& folder : folders) 
	{
		cout << counter++ << ". " << folder.name << ": \n";
		folder.show();
	}
}
void Tasks::show_folder(int i) const
{
	i--;
	cout << folders[i].name << ": \n";
	folders[i].show();
}
void Tasks::show_file(int folder, int file) const 
{
	folders[--folder].show_file(file);
}