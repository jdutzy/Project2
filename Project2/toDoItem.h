#pragma once
#define toDoItem_h
#include <iostream> 
#include <string> 
#include <ctime> 
#include <fstream>
#include <iomanip>

using namespace std;

enum class type {
	shopping,
	housing,
	work
};

enum class status {
	done,
	in_progress,
	hold
};

class toDoItem
{
private:

	int Id;
	string title;
	string description;
	type Type;
	int priority;
	status Status;
	time_t createDate = time(0);
	time_t dueDate;
	time_t lastMod;
	

	
public:

	toDoItem(int Id, string title, type Type, string description) {
		this->Id = Id;
		this->title = title;
		this->Type = Type;
		this->description = description;
		
	}

	toDoItem(int Id, string title, type Type, int priority) {
		this->Id = Id;
		this->title = title;
		this->priority = priority;
		this->Type = Type;
	}

	toDoItem(int Id, string title, type Type, int priority, time_t dueDate) {
		this->Id = Id;
		this->title = title;
		this->priority = priority;
		this->Type = Type;
		this->dueDate = dueDate;
	}
	
	toDoItem();

	toDoItem(int& toDoId, string& toDoTitle, string& toDoDesc, type& toDoType, int& toDoPriority, status& toDoStatus, time_t& toDoCreateDate, time_t& toDoDueDate, time_t& toDoLastMod);

	int getId();
	void setId(int toDoID);

	string getTitle();
	void setTitle(string toDoTitle);

	string getDescription();
	void setDescription(string toDoDescription);

	type getType();
	void setType(type toDoType);

	int getPriority();
	void setPriority(int toDoPriority);

	status getStatus();
	void setStatus(status toDoStatus);

	time_t getCreateDate();
	void setCreateDate(time_t toDoCreateDate);

	time_t getDueDate();
	void setDueDate(time_t toDoDueDate);

	time_t getLastMod();
	void setLastMod(time_t toDoLastMod);

};

