#include "TestLogin.h"
#include "Login.h"
#include <cassert>

void TestLogin::testImplicitConstructor() {
	Login u;
	assert(u.getUsername().empty());
	assert(u.getParola().empty());
}

void TestLogin::testConstructorWithParameters() {
	Login u("aaaa", "1234");
	assert(u.getUsername() == "aaaa");
	assert(u.getParola() == "1234");
}

void TestLogin::testCopyConstructor() {
	Login u1("aaaa", "1234");
	Login u2(u1);
	assert(u2.getUsername() == "aaaa");
	assert(u2.getParola() == "1234");
}

void TestLogin::testClone() {
	Login u("aaaa", "1234");
	Login* uClone = u.clone();
	assert(u == *uClone);
	assert(&u != uClone);
}

void TestLogin::testGetUsername() {
	Login u("aaaa", "1234");
	assert(u.getUsername() == "aaaa");
}

void TestLogin::testGetParola() {
	Login u("aaaa", "1234");
	assert(u.getParola() == "1234");
}

void TestLogin::testSetUsername() {
	Login u;
	u.setUsername("aaaa");
	assert(u.getUsername() == "aaaa");
}

void TestLogin::testSetParola() {
	Login u;
	u.setParola("1234");
	assert(u.getParola() == "1234");
}

void TestLogin::testAssignmentOpperator() {
	Login u1("aaaa", "1234");
	Login u2;
	u2 = u1;
	assert(u1.getUsername() == u2.getUsername());
	assert(u1.getParola() == u2.getParola());
}

void TestLogin::testEqualityOperator() {
	Login u1("aaaa", "1234");
	Login u2 = u1;
	assert(u1 == u2);
	u2.setParola("0000");
	assert(!(u1 == u2));
	u2.setParola(u1.getParola());
	assert(u1 == u2);
}

void TestLogin::testToString() {
	Login u("aaaa", "1234");
	assert(u.toString(" ") == "aaaa 1234");
	assert(u.toString(",") == "aaaa,1234");
}

void TestLogin::testAll() {
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testGetUsername();
	void testGetParola();
	void testSetUsername();
	void testSetParola();
	void testAssignmentOpperator();
	void testEqualityOperator();
	void testToString();
}