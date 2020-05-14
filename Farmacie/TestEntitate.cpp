#include "TestEntitate.h"
#include "Entitate.h"
#include <cassert>

void TestEntitate::testImplicitConstructor() {
	Entitate e;
	assert(e.getId() == 0);
	assert(e.getNume().empty());
}

void TestEntitate::testConstructorWithParameters() {
	Entitate e(1, "aaa");
	assert(e.getId() == 1);
	assert(e.getNume() == "aaa");
}

void TestEntitate::testCopyConstructor() {
	Entitate e1(1, "aaa");
	Entitate e2(e1);
	assert(e2.getId() == e1.getId());
	assert(e2.getNume() == e1.getNume());
}

void TestEntitate::testClone() {
	Entitate e(1, "aaa");
	Entitate* eClone = e.clone();
	assert(e == *eClone);
	assert(&e != eClone);
}

void TestEntitate::testGetId() {
	Entitate e(1, "aaa");
	assert(e.getId() == 1);
}

void TestEntitate::testGetNume() {
	Entitate e(1, "aaa");
	assert(e.getNume() == "aaa");
}

void TestEntitate::testSetId() {
	Entitate e;
	e.setId(1);
	assert(e.getId() == 1);
}

void TestEntitate::testSetNume() {
	Entitate e;
	e.setNume("aaa");
	assert(e.getNume() == "aaa");
}

void TestEntitate::testAssignmentOpperator() {
	Entitate e1(1, "aaa");
	Entitate e2;
	e2 = e1;
	assert(e1.getId() == e2.getId());
	assert(e1.getNume() == e2.getNume());
}

void TestEntitate::testEqualityOperator() {
	Entitate e1(1, "aaa");
	Entitate e2 = e1;
	assert(e1 == e2);
	e2.setId(2);
	assert(!(e1 == e2));
	e2.setId(e1.getId());
	assert(e1 == e2);
	e2.setNume("bbb");
	assert(!(e1 == e2));
	e2.setNume(e1.getNume());
	assert(e1 == e2);
}

void TestEntitate::testToString() {
	Entitate e(1, "aaa");
	assert(e.toString(" ") == "1 aaa");
	assert(e.toString(",") == "1,aaa");
}

void TestEntitate::testAll() {
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetId();
	this->testGetNume();
	this->testSetId();
	this->testSetNume();
	this->testAssignmentOpperator();
	this->testEqualityOperator();
	this->testToString();
}