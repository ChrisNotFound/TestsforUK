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
		///Получает или устанавливает контекст теста, в котором предоставляются
		///сведения о текущем тестовом запуске и обеспечивается его функциональность.
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
		//При написании тестов можно использовать следующие дополнительные атрибуты:
		//
		//ClassInitialize используется для выполнения кода до запуска первого теста в классе
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//ClassCleanup используется для выполнения кода после завершения работы всех тестов в классе
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//TestInitialize используется для выполнения кода перед запуском каждого теста
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//TestCleanup используется для выполнения кода после завершения каждого теста
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
