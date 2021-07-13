//I am aware of the University’s rules on plagiarism and collusion and I understand that, if I
//am found to have broken these rules, it will be treated as Academic Misconductand dealt
//with accordingly.I understand that if I lend this piece of work to another studentand they
//copy all or part of it, either with or without my knowledge or permission, I shall be guilty of
//collusion.In submitting this work I confirm that I am aware of, and am abiding by, the
//University’s expectations for proof - reading.
//Name: Anthony Langsdale-Foster ID No : n0650128
#pragma once
#include "Transaction.h"
class Cashpoint : public Transaction {
	public:
		Cashpoint(dateStruct date, timeStruct time, float Value, int id, int card);
		void display();
		std::string getID();
		float getValue();
		std::string getType();
		void saveTransaction();
	private:
		int locationID;
		int cardUsed;
};