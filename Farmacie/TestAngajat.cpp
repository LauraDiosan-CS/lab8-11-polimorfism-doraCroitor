#include "Angajat.h"
#include "TestAngajat.h"
#include <cassert>

void TestAngajat::testImplicitConstructor() {
	Angajat m;
	assert(m.getId() == 0);
	assert(m.getNume().empty());
	assert(m.getEmail().empty());
}

void TestAngajat::testConstructorWithParameters() {
	Angajat m(1, "Pop Marius", "pm@yahoo.com", 6);
	assert(m.getId() == 1);
	assert(m.getNume() == "Pop Marius");
	assert(m.getEmail() == "pm@yahoo.com");
	assert(m.getGrad() == 6);

}

void TestAngajat::testCopyConstructor() {
	Angajat m1(1, "Pop Marius", "pm@yahoo.com", 6);
	Angajat m2(m1);
	assert(m1.getId() == m2.getId());
	assert(m1.getNume() == m2.getNume());
	assert(m1.getEmail() == m2.getEmail());
	assert(m1.getGrad() == m2.getGrad());
	
}

void TestAngajat::testClone() {
	Angajat m(1, "Pop Marius", "pm@yahoo.com", 6);
	Angajat* mClone = (Angajat*)m.clone();
	assert(m == *mClone);
	assert(&m != mClone);
}

void TestAngajat::testGetEmail() {
	Angajat m(1, "Pop Marius", "pm@yahoo.com", 6);
	assert(m.getEmail() == "pm@yahoo.com");
}

void TestAngajat::testSetEmail() {
	Angajat m;
	m.setEmail("pm@yahoo.com");
	assert(m.getEmail() == "pm@yahoo.com");
}

void TestAngajat::testGetGrad() {
	Angajat m(1, "Pop Marius", "pm@yahoo.com", 6);
	assert(m.getGrad() == 6);
}

void TestAngajat::testSetGrad() {
	Angajat m;
	m.setGrad(2);
	assert(m.getGrad() == 2);
}

void TestAngajat::testAssignmentOperator() {
	Angajat m1(1, "Pop Marius", "pm@yahoo.com", 6);
	Angajat m2;
	m2 = m1;
	assert(m2.getId() == m1.getId());
	assert(m2.getNume() == m1.getNume());
	assert(m2.getEmail() == m1.getEmail());
	assert(m2.getGrad() == m1.getGrad());
}

void TestAngajat::testEqualityOperator() {
	Angajat m1(1, "Pop Marius", "pm@yahoo.com", 6);
	Angajat m2 = m1;
	assert(m1 == m2);

	m2.setId(2);
	assert(!(m1 == m2));
	m2.setId(m1.getId());
	assert(m1 == m2);

	m2.setNume("Nurofen");
	assert(!(m1 == m2));
	m2.setNume(m1.getNume());
	assert(m1 == m2);

	m2.setEmail("Da");
	assert(!(m1 == m2));
	m2.setEmail(m1.getEmail());
	assert(m1 == m2);

	m2.setGrad(2);
	assert(!(m1 == m2));
	m2.setGrad(m1.getGrad());
	assert(m1 == m2);
}

void TestAngajat::testToString() {
	Angajat m(1, "Pop Marius", "pm@yahoo.com", 6);
	assert(m.toString(",") == "ANG,1,Pop Marius,pm@yahoo.com,6");
}

void TestAngajat::testAll() {
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetEmail();
	this->testSetEmail();
	this->testGetGrad();
	this->testSetGrad();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}