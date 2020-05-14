#pragma once

class TestLogin {
private:
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
public:
	void testAll();
};