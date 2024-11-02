#include "pch.h"
#include "FlatMap.h"
using namespace FLATMAP;

TEST(TestConstructors, TestVoidArray) {
	FlatMap a;
	std::string argument = "C++";
	EXPECT_EQ(a.size(), 0);
	EXPECT_EQ(a.contains(argument), false);
	EXPECT_EQ(a.erase(argument), 0);
}

TEST(TestConstructors, TestOperatorinVoidArray) {
	FlatMap a;
	std::string argument = "C++";
	a[argument] = "Test";
	EXPECT_EQ(a.size(), 1);
	EXPECT_EQ(a.contains(argument), true);
	EXPECT_EQ(a[argument], "Test");
	EXPECT_EQ(a.erase(argument), 1);
}

TEST(TestOperator, Testnotassignment) {
	FlatMap a;
	std::string argument = "C++";
	a[argument];
	EXPECT_EQ(a.size(), 1);
	EXPECT_EQ(a.contains(argument), true);
	EXPECT_EQ(a[argument], "");
	EXPECT_EQ(a.erase(argument), 1);
}

TEST(TestOperator, Testtwoassignmentinonewkey) {
	FlatMap a;
	std::string argument = "C++";
	a[argument] = "TEST1";
	a[argument] = "TEST2";
	EXPECT_EQ(a.size(), 1);
	EXPECT_EQ(a.contains(argument), true);
	EXPECT_EQ(a[argument], "TEST2");
	EXPECT_EQ(a.erase(argument), 1);
}

TEST(TestOperator, Testlotnewelements) {
	FlatMap a;
	a["TEST1"] = "TEST1";
	a["TEST2"] = "TEST2";
	a["TEST3"] = "TEST3";
	a["TEST4"] = "TEST4";
	a["TEST5"] = "TEST5";
	a["TEST6"] = "TEST6";
	a["TEST7"] = "TEST7";
	a["TEST8"] = "TEST8";
	a["TEST9"] = "TEST9";
	a["TEST10"] = "TEST10";
	a["TEST11"] = "TEST11";
	a["TEST12"] = "TEST12";
	EXPECT_EQ(a.size(), 12);
	EXPECT_EQ(a.contains("TEST1"), true);
	EXPECT_EQ(a.contains("TEST2"), true);
	EXPECT_EQ(a.contains("TEST3"), true);
	EXPECT_EQ(a.contains("TEST4"), true);
	EXPECT_EQ(a.contains("TEST5"), true);
	EXPECT_EQ(a.contains("TEST6"), true);
	EXPECT_EQ(a.contains("TEST7"), true);
	EXPECT_EQ(a.contains("TEST8"), true);
	EXPECT_EQ(a.contains("TEST9"), true);
	EXPECT_EQ(a.contains("TEST10"), true);
	EXPECT_EQ(a.contains("TEST11"), true);
	EXPECT_EQ(a.contains("TEST12"), true);
	EXPECT_EQ(a["TEST1"], "TEST1");
	EXPECT_EQ(a["TEST2"], "TEST2");
	EXPECT_EQ(a["TEST3"], "TEST3");
	EXPECT_EQ(a["TEST4"], "TEST4");
	EXPECT_EQ(a["TEST5"], "TEST5");
	EXPECT_EQ(a["TEST6"], "TEST6");
	EXPECT_EQ(a["TEST7"], "TEST7");
	EXPECT_EQ(a["TEST8"], "TEST8");
	EXPECT_EQ(a["TEST9"], "TEST9");
	EXPECT_EQ(a["TEST10"], "TEST10");
	EXPECT_EQ(a["TEST11"], "TEST11");
	EXPECT_EQ(a["TEST12"], "TEST12");
	EXPECT_EQ(a.erase("TEST6"), 1);
}

TEST(TestErase, Testvoidarray) {
	FlatMap a;
	EXPECT_EQ(a.size(), 0);
	EXPECT_EQ(a.erase("TEST"), 0);
	EXPECT_EQ(a.size(), 0);
}

TEST(TestErase, Testoneelement) {
	FlatMap a;
	std::string argument = "C++";
	a[argument] = "TEST1";
	EXPECT_EQ(a.size(), 1);
	EXPECT_EQ(a.erase(argument), 1);
	EXPECT_EQ(a.size(), 0);
	EXPECT_EQ(a.contains(argument), false);
}


TEST(TestErase, Testlotnewelements) {
	FlatMap a;
	a["TEST1"] = "TEST1";
	a["TEST2"] = "TEST2";
	a["TEST3"] = "TEST3";
	a["TEST4"] = "TEST4";
	a["TEST5"] = "TEST5";
	a["TEST6"] = "TEST6";
	a["TEST7"] = "TEST7";
	a["TEST8"] = "TEST8";
	a["TEST9"] = "TEST9";
	a["TEST10"] = "TEST10";
	a["TEST11"] = "TEST11";
	a["TEST12"] = "TEST12";
	EXPECT_EQ(a.size(), 12);
	EXPECT_EQ(a.erase("TEST6"), 1);
	EXPECT_EQ(a.contains("TEST6"), false);
	EXPECT_EQ(a.erase("TEST3"), 1);
	EXPECT_EQ(a.contains("TEST3"), false);
	EXPECT_EQ(a.erase("TEST2"), 1);
	EXPECT_EQ(a.contains("TEST2"), false);
	EXPECT_EQ(a.erase("TEST1"), 1);
	EXPECT_EQ(a.contains("TEST1"), false);
	EXPECT_EQ(a.erase("TEST12"), 1);
	EXPECT_EQ(a.contains("TEST12"), false);
	EXPECT_EQ(a.erase("TEST10"), 1);
	EXPECT_EQ(a.contains("TEST10"), false);
	EXPECT_EQ(a.erase("TEST9"), 1);
	EXPECT_EQ(a.contains("TEST9"), false);
	EXPECT_EQ(a.erase("TEST7"), 1);
	EXPECT_EQ(a.contains("TEST7"), false);
	EXPECT_EQ(a.erase("TEST8"), 1);
	EXPECT_EQ(a.contains("TEST8"), false);

	EXPECT_EQ(a.contains("TEST4"), true);
	EXPECT_EQ(a.contains("TEST5"), true);
	EXPECT_EQ(a.contains("TEST11"), true);
	EXPECT_EQ(a.size(), 3);
}

TEST(TestConstructorCopy, TestTwoVOID) {
	FlatMap a;
	FlatMap b(a);

	EXPECT_EQ(a.size(), 0);
	EXPECT_EQ(b.size(), 0);

	EXPECT_EQ(a.contains("TEST"), false);
	EXPECT_EQ(b.contains("TEST"), false);
}

TEST(TestConstructorCopy, TestLotnewelements) {
	FlatMap a;

	a["TEST1"] = "TEST1";
	a["TEST2"] = "TEST2";
	a["TEST3"] = "TEST3";
	a["TEST4"] = "TEST4";
	a["TEST5"] = "TEST5";
	a["TEST6"] = "TEST6";
	a["TEST7"] = "TEST7";
	a["TEST8"] = "TEST8";
	a["TEST9"] = "TEST9";
	a["TEST10"] = "TEST10";
	a["TEST11"] = "TEST11";
	a["TEST12"] = "TEST12";
	EXPECT_EQ(a.size(), 12);

	FlatMap b(a);

	EXPECT_EQ(a.size(), 12);
	EXPECT_EQ(b.size(), 12);

	EXPECT_EQ(a.contains("TEST1"), true);
	EXPECT_EQ(a.contains("TEST2"), true);
	EXPECT_EQ(a.contains("TEST3"), true);
	EXPECT_EQ(a.contains("TEST4"), true);
	EXPECT_EQ(a.contains("TEST5"), true);
	EXPECT_EQ(a.contains("TEST6"), true);
	EXPECT_EQ(a.contains("TEST7"), true);
	EXPECT_EQ(a.contains("TEST8"), true);
	EXPECT_EQ(a.contains("TEST9"), true);
	EXPECT_EQ(a.contains("TEST10"), true);
	EXPECT_EQ(a.contains("TEST11"), true);
	EXPECT_EQ(a.contains("TEST12"), true);

	EXPECT_EQ(b.contains("TEST1"), true);
	EXPECT_EQ(b.contains("TEST2"), true);
	EXPECT_EQ(b.contains("TEST3"), true);
	EXPECT_EQ(b.contains("TEST4"), true);
	EXPECT_EQ(b.contains("TEST5"), true);
	EXPECT_EQ(b.contains("TEST6"), true);
	EXPECT_EQ(b.contains("TEST7"), true);
	EXPECT_EQ(b.contains("TEST8"), true);
	EXPECT_EQ(b.contains("TEST9"), true);
	EXPECT_EQ(b.contains("TEST10"), true);
	EXPECT_EQ(b.contains("TEST11"), true);
	EXPECT_EQ(b.contains("TEST12"), true);
}


TEST(TestEqualSign, TestTwoVOID) {
	FlatMap a;
	FlatMap b;

	b = a;

	EXPECT_EQ(a.size(), 0);
	EXPECT_EQ(b.size(), 0);

	EXPECT_EQ(a.contains("TEST"), false);
	EXPECT_EQ(b.contains("TEST"), false);
}

TEST(TestEqualSign, TestFirstVOID) {
	FlatMap a;
	a["TEST1"] = "TEST1";
	a["TEST2"] = "TEST2";
	a["TEST3"] = "TEST3";
	a["TEST4"] = "TEST4";
	a["TEST5"] = "TEST5";
	a["TEST6"] = "TEST6";
	a["TEST7"] = "TEST7";
	a["TEST8"] = "TEST8";
	a["TEST9"] = "TEST9";
	a["TEST10"] = "TEST10";
	a["TEST11"] = "TEST11";
	a["TEST12"] = "TEST12";
	EXPECT_EQ(a.size(), 12);

	FlatMap b;

	b = a;

	EXPECT_EQ(b.size(), 12);


	EXPECT_EQ(b["TEST1"], "TEST1");
	EXPECT_EQ(b["TEST2"], "TEST2");
	EXPECT_EQ(b["TEST3"], "TEST3");
	EXPECT_EQ(b["TEST4"], "TEST4");
	EXPECT_EQ(b["TEST5"], "TEST5");
	EXPECT_EQ(b["TEST6"], "TEST6");
	EXPECT_EQ(b["TEST7"], "TEST7");
	EXPECT_EQ(b["TEST8"], "TEST8");
	EXPECT_EQ(b["TEST9"], "TEST9");
	EXPECT_EQ(b["TEST10"], "TEST10");
	EXPECT_EQ(b["TEST11"], "TEST11");
	EXPECT_EQ(b["TEST12"], "TEST12");

	EXPECT_EQ(b.contains("TEST1"), true);
	EXPECT_EQ(b.contains("TEST2"), true);
	EXPECT_EQ(b.contains("TEST3"), true);
	EXPECT_EQ(b.contains("TEST4"), true);
	EXPECT_EQ(b.contains("TEST5"), true);
	EXPECT_EQ(b.contains("TEST6"), true);
	EXPECT_EQ(b.contains("TEST7"), true);
	EXPECT_EQ(b.contains("TEST8"), true);
	EXPECT_EQ(b.contains("TEST9"), true);
	EXPECT_EQ(b.contains("TEST10"), true);
	EXPECT_EQ(b.contains("TEST11"), true);
	EXPECT_EQ(b.contains("TEST12"), true);
}

TEST(TestEqualSign, TestSecondVOID) {
	FlatMap a;
	FlatMap b;
	b["TEST1"] = "TEST1";
	b["TEST2"] = "TEST2";
	b["TEST3"] = "TEST3";
	b["TEST4"] = "TEST4";
	b["TEST5"] = "TEST5";
	b["TEST6"] = "TEST6";
	b["TEST7"] = "TEST7";
	b["TEST8"] = "TEST8";
	b["TEST9"] = "TEST9";
	b["TEST10"] = "TEST10";
	b["TEST11"] = "TEST11";
	b["TEST12"] = "TEST12";

	EXPECT_EQ(b.size(), 12);

	b = a;

	EXPECT_EQ(a.size(), 0);
	EXPECT_EQ(b.size(), 0);


	EXPECT_EQ(a.contains("TEST1"), false);
	EXPECT_EQ(a.contains("TEST2"), false);
	EXPECT_EQ(a.contains("TEST3"), false);
	EXPECT_EQ(a.contains("TEST4"), false);
	EXPECT_EQ(a.contains("TEST5"), false);
	EXPECT_EQ(a.contains("TEST6"), false);
	EXPECT_EQ(a.contains("TEST7"), false);
	EXPECT_EQ(a.contains("TEST8"), false);
	EXPECT_EQ(a.contains("TEST9"), false);
	EXPECT_EQ(a.contains("TEST10"), false);
	EXPECT_EQ(a.contains("TEST11"), false);
	EXPECT_EQ(a.contains("TEST12"), false);

	EXPECT_EQ(b.contains("TEST1"), false);
	EXPECT_EQ(b.contains("TEST2"), false);
	EXPECT_EQ(b.contains("TEST3"), false);
	EXPECT_EQ(b.contains("TEST4"), false);
	EXPECT_EQ(b.contains("TEST5"), false);
	EXPECT_EQ(b.contains("TEST6"), false);
	EXPECT_EQ(b.contains("TEST7"), false);
	EXPECT_EQ(b.contains("TEST8"), false);
	EXPECT_EQ(b.contains("TEST9"), false);
	EXPECT_EQ(b.contains("TEST10"), false);
	EXPECT_EQ(b.contains("TEST11"), false);
	EXPECT_EQ(b.contains("TEST12"), false);
}

TEST(TestEqualSign, TestZeroVOID) {
	FlatMap a;

	a["TEST1"] = "TEST4";
	a["TEST2"] = "TEST2";
	a["TEST3"] = "TEST6";
	a["TEST4"] = "TEST745";
	a["TEST5"] = "TEST35";
	a["TEST6"] = "TESTghdf";
	a["TEST7"] = "TESTdghrc";
	a["TEST8"] = "TEST313rgbd";
	a["TEST9"] = "TESTfghjkl.,mnbg";
	a["TEST10"] = "TEST1thterdffbdv ";
	a["TEST11"] = "TEST1rfsdghyjrtesdf";
	a["TEST12"] = "TE";
	a["gdhdf"] = "dfsgTEST1rfsdghyjrtesdf";

	FlatMap b;
	b["TEST1"] = "TEST1";
	b["TEST2"] = "TEST2";
	b["TEST3"] = "TEST3";
	b["TEST4"] = "TEST4";
	b["TEST5"] = "TEST5";
	b["TEST6"] = "TEST6";
	b["TEST7"] = "TEST7";
	b["TEST8"] = "TEST8";
	b["TEST9"] = "TEST9";
	b["TEST10"] = "TEST10";
	b["TEST11"] = "TEST11";
	b["TEST12"] = "TEST12";

	EXPECT_EQ(b.size(), 12);

	b = a;

	EXPECT_EQ(a.size(), 13);
	EXPECT_EQ(b.size(), 13);

	EXPECT_EQ(a["TEST1"], "TEST4");
	EXPECT_EQ(a["TEST2"], "TEST2");
	EXPECT_EQ(a["TEST3"], "TEST6");
	EXPECT_EQ(a["TEST4"], "TEST745");
	EXPECT_EQ(a["TEST5"], "TEST35");
	EXPECT_EQ(a["TEST6"], "TESTghdf");
	EXPECT_EQ(a["TEST7"], "TESTdghrc");
	EXPECT_EQ(a["TEST8"], "TEST313rgbd");
	EXPECT_EQ(a["TEST9"], "TESTfghjkl.,mnbg");
	EXPECT_EQ(a["TEST10"], "TEST1thterdffbdv ");
	EXPECT_EQ(a["TEST11"], "TEST1rfsdghyjrtesdf");
	EXPECT_EQ(a["TEST12"], "TE");
	EXPECT_EQ(a["gdhdf"], "dfsgTEST1rfsdghyjrtesdf");

	EXPECT_EQ(b["TEST1"], "TEST4");
	EXPECT_EQ(b["TEST2"], "TEST2");
	EXPECT_EQ(b["TEST3"], "TEST6");
	EXPECT_EQ(b["TEST4"], "TEST745");
	EXPECT_EQ(b["TEST5"], "TEST35");
	EXPECT_EQ(b["TEST6"], "TESTghdf");
	EXPECT_EQ(b["TEST7"], "TESTdghrc");
	EXPECT_EQ(b["TEST8"], "TEST313rgbd");
	EXPECT_EQ(b["TEST9"], "TESTfghjkl.,mnbg");
	EXPECT_EQ(b["TEST10"], "TEST1thterdffbdv ");
	EXPECT_EQ(b["TEST11"], "TEST1rfsdghyjrtesdf");
	EXPECT_EQ(b["TEST12"], "TE");
	EXPECT_EQ(b["gdhdf"], "dfsgTEST1rfsdghyjrtesdf");

}