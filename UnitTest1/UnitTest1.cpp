#include "pch.h"
#include "CppUnitTest.h"
#include "../PDS_6/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
        TEST_METHOD(TestReadGraph)
        {
            std::ofstream testInput("testInput.txt");
            testInput << "3 3\n1 2\n2 3\n3 1\n";
            testInput.close();

            int n, m;
            int** edges = nullptr;

            readGraph("testInput.txt", n, m, edges);

            Assert::AreEqual(3, n);
            Assert::AreEqual(3, m);
            Assert::AreEqual(1, edges[0][0]);
            Assert::AreEqual(2, edges[0][1]);
            Assert::AreEqual(2, edges[1][0]);
            Assert::AreEqual(3, edges[1][1]);
            Assert::AreEqual(3, edges[2][0]);
            Assert::AreEqual(1, edges[2][1]);

            for (int i = 0; i < m; ++i)
                delete[] edges[i];

            delete[] edges;
        }
	};
}
