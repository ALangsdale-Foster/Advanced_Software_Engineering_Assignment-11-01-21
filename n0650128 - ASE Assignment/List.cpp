//I am aware of the University’s rules on plagiarism and collusion and I understand that, if I
//am found to have broken these rules, it will be treated as Academic Misconductand dealt
//with accordingly.I understand that if I lend this piece of work to another studentand they
//copy all or part of it, either with or without my knowledge or permission, I shall be guilty of
//collusion.In submitting this work I confirm that I am aware of, and am abiding by, the
//University’s expectations for proof - reading.
//Name: Anthony Langsdale-Foster ID No : n0650128
#include "List.h"
#include "Transaction.h"
#include <iostream>
#include <vector>

List::List()
{
	head = 0;//empty list
}

int List::add(Transaction* inp) { //iterate through list until head is reached, then create new node
	Link* temp = new Link(inp);
	if (temp == 0) {
		return 0; //0 value used to show error
	}
	temp->NextLink = head;
	head = temp;
	return 1;
}

int List::remove() { //remove top level transaction object
	Link* temp;
	Link* current;

	if (head == 0) {
		return 0;//list = empty
	}

	temp = head;
	head = head->NextLink;
	delete temp;

	return 1;
}

void List::saveList()//store list in external file
{
	Link* temp;
	for (temp = head; temp != 0; temp = temp->NextLink) {
		temp->linkObj->saveTransaction();//saveTransaction() function called from transaction object
	}
}

void List::linearSearch(dateStruct date) //perform linear search through list for matching date
{
	Link* temp;
	for (temp = head; temp != 0; temp = temp->NextLink) {//iterate through list
		dateStruct currDate = temp->linkObj->transactionDate;
		if ((currDate.day == date.day) && (currDate.month == date.month) && (currDate.year == date.year)){//check if date matches
			temp->linkObj->display();
		}
	}
}

void List::sortList() //copy contents of list into new vector and perform sorting algorithm on vector
{
	Link* temp;
	Transaction* sortTemp;
	int size = 0;
	std::vector<Transaction*> transactionVec;
	for (temp = head; temp != 0; temp = temp->NextLink) { //find size of list and populate vector
		transactionVec.push_back(temp->linkObj);
	}
	size = transactionVec.size();

	for (int gap = size / 2; 0 < gap; gap /= 2) { //sort vector 
		for (int i = gap; i < size; i++) {
			for (int j = i - gap; 0 <= j; j -= gap) {//store information on current vector item and next vector item
				bool needsMove = false;
				int year1 = transactionVec[j]->transactionDate.year;
				int year2 = transactionVec[j + gap]->transactionDate.year;
				int month1 = transactionVec[j]->transactionDate.month;
				int month2 = transactionVec[j + gap]->transactionDate.month;
				int day1 = transactionVec[j]->transactionDate.day;
				int day2 = transactionVec[j + gap]->transactionDate.day;

				if (year1 > year2) { //compare vector items 1 & 2
					needsMove = true;
				}
				if ((year1 == year2) && (month1 > month2)) {
					needsMove = true;
				}
				if ((year1 == year2) && (month1 == month2) && (day1 > day2)) {
					needsMove = true;
				}

				/*if (transactionVec[j]->absoluteDate() < transactionVec[j+gap]->absoluteDate()) {
					sortTemp = transactionVec[j+gap];
					transactionVec[j+gap] = transactionVec[j];
					transactionVec[j] = sortTemp;
				}*/

				if (needsMove) { //if needsmove boolean is set to true, swap vector items
					sortTemp = transactionVec[j + gap];
					transactionVec[j + gap] = transactionVec[j];
					transactionVec[j] = sortTemp;
				}
			}
		}
	}
	this->clearList();
	for (int i = 0; i < transactionVec.size(); i++) { //display vector
		this->add(transactionVec.at(i));
	}

}

void List::clearList() //revert to empty list
{
	this->head = 0;
}

void List::display() //iterate through list and call display function from transaction object
{
	Link* temp;
	for (temp = head; temp != 0; temp = temp->NextLink) {
		std::cout << temp->linkObj->getType() << std::endl;
		temp->linkObj->display();
		std::cout << " " << std::endl;
	}
}

void List::displayUpper() //iterate through list and call display function from transaction object with upper bound
{
	Link* temp;
	int i = 0;
	for (temp = head; temp != 0; temp = temp->NextLink) {
		if (i == 10) {//magic number - should be using variable instead
			break;
		}
		temp->linkObj->display();
		std::cout << " " << std::endl;
		i++;
	}
	std::cout << "Loop ran " << i << " times" << std::endl;
}


