#include "stdafx.h"
#include "calc.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;


namespace Tests
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///�������� ��� ������������� �������� �����, � ������� ���������������
		///�������� � ������� �������� ������� � �������������� ��� ����������������.
		///</summary>
		//property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		//{
		//	Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
		//	{
		//		return testContextInstance;
		//	}
		//	System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
		//	{
		//		testContextInstance = value;
		//	}
		//};

		#pragma region Additional test attributes
		//
		//��� ��������� ������ ����� ������������ ��������� �������������� ��������:
		//
		//ClassInitialize ������������ ��� ���������� ���� �� ������� ������� ����� � ������
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//ClassCleanup ������������ ��� ���������� ���� ����� ���������� ������ ���� ������ � ������
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//TestInitialize ������������ ��� ���������� ���� ����� �������� ������� �����
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//TestCleanup ������������ ��� ���������� ���� ����� ���������� ������� �����
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestMethod1()
		{
			//
			//Spisok TestA;
			//std::vector<char> myvec = { '1', '2', '2', '3', '3', '6', '6', '8', '1', '4', '4', '5', '5', '8', '1', '7', '0' };
			//TestA.MakeGraph(myvec);
			//std::vector<char> Res = { '5', '4', '1' };
			////EXPECT_EQ(TestA.Go_width(TestA.GetHead(), '1', '5'), Res);
			//Assert::AreEqual(TestA.Go_width(TestA.GetHead(), '1', '5'), Res);
			auto x = 50;
			auto y = 40;
			Assert::AreEqual(90, x + y);
		};
	};
}
