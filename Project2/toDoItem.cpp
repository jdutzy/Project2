#include <iostream> 
#include <string> 
#include <ctime> 
#include <fstream>
#include <iomanip>
#include "toDoList.h"
#include "toDoItem.h"

toDoItem::toDoItem() {}

toDoItem::toDoItem(int& toDoId, string& toDoTitle, string& toDoDesc, type& toDoType, int& toDoPriority, status& toDoStatus, time_t& toDoCreateDate, time_t& toDoDueDate, time_t& toDoLastMod) {
	Id = toDoId;
	title = toDoTitle;
	description = toDoDesc;
	Type = toDoType;
	priority = toDoPriority;
	Status = toDoStatus;
	createDate = toDoCreateDate;
	dueDate = toDoDueDate;
	lastMod = toDoLastMod;
}

int toDoItem::getId() { return Id; }
void toDoItem::setId(int toDoId) { Id = toDoId; }

string toDoItem::getTitle() { return title; }
void toDoItem::setTitle(string toDoTitle) { title = toDoTitle; }

string toDoItem::getDescription() { return description; }
void toDoItem::setDescription(string toDoDesc) { description = toDoDesc; }

type toDoItem::getType() { return Type; }
void toDoItem::setType(type toDoType) { Type = toDoType; }

int toDoItem::getPriority() { return priority; }
void toDoItem::setPriority(int toDoPriority) { priority = toDoPriority; }

status toDoItem::getStatus() { return Status; }
void toDoItem::setStatus(status toDoStatus) { Status = toDoStatus; }

time_t toDoItem::getCreateDate() { return createDate; }
void toDoItem::setCreateDate(time_t toDoCreateDate) { createDate = toDoCreateDate; }

time_t toDoItem::getDueDate() { return dueDate; }
void toDoItem::setDueDate(time_t toDoDueDate) { dueDate = toDoDueDate; }

time_t toDoItem::getLastMod() { return lastMod; }
void toDoItem::setLastMod(time_t toDoLastMod) { lastMod = toDoLastMod; }
