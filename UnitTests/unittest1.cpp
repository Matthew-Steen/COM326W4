#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(ModuleTests)
	{
	public:
		
		TEST_METHOD(CustomConstructorTest)
		{
			Module m("OOP", "COM326", 15, 100);

			std::string expectedModuleTitle{ "OOP" };
			std::string expectedModuleCode{"COM326"};
			int expectedModuleCredits{ 15 };
			int expectedModuleMarks{ 100 };

			/*std::string actualModuleTitle{m.getModuleTitle};
			std::string actualModuleCode{ m.getModuleCode };
			int actualModuleCredits{ m.getModuleCreditPoints };
			int actualModuleMarks{ m.getModuleMark };*/

			Assert::AreEqual(m.getModuleTitle(), expectedModuleTitle);
			Assert::AreEqual(m.getModuleCode(), expectedModuleCode);
			Assert::AreEqual(m.getModuleCreditPoints(), expectedModuleCredits);
			Assert::AreEqual(m.getModuleMark(), expectedModuleMarks);


		}

		TEST_METHOD(GetModuleCodeTest) 
		{
			Module m("OOP", "COM326", 15, 100);

			std::string expectedModuleCode{ "COM326" };

			Assert::AreEqual(m.getModuleCode(), expectedModuleCode);
		}

		TEST_METHOD(SetModuleCode) 
		{
			Module m("OOP", "COM326", 15, 100);
			std::string expectedModuleCode{"COM115"};

			m.setModuleCode(expectedModuleCode);

			Assert::AreEqual(m.getModuleCode(), expectedModuleCode);
		}

		TEST_METHOD(GetModuleCreditPoints) 
		{
			Module m("OOP", "COM326", 15, 100);

			int expectedCreditPoints{ 15 };

			Assert::AreEqual(m.getModuleCreditPoints(), expectedCreditPoints);
		}

		TEST_METHOD(SetModuleCreditPoints) 
		{
			Module m("OOP", "COM326", 15, 100);

			int expectedModuleCreditPoints{ 25 };

			m.setModuleCreditPoints(expectedModuleCreditPoints);

			Assert::AreEqual(m.getModuleCreditPoints(), expectedModuleCreditPoints);
		}

	};

	TEST_CLASS(StudentTests) 
	{
	public:
		TEST_METHOD(CustomConstructor) 
		{
			std::string expectedName{ "Matthew" };
			std::string expectedRegistration{"11/12/2018"};
			std::string expectedCourse{"Computer Science"};
			int expectedYOS{2};

			Student m("Matthew", "11/12/2018", "Computer Science", 2);

			Assert::AreEqual(m.GetName(), expectedName);
			Assert::AreEqual(m.GetRegistrationID(), expectedRegistration);
			Assert::AreEqual(m.GetCourse(), expectedCourse);
			Assert::AreEqual(m.GetYearofStudy(), expectedYOS);
		}

		TEST_METHOD(AddModuleTest) 
		{
			Module m("OOP", "COM326", 15, 100);
			Student s("Matthew", "11/12/2018", "Computer Science", 2);

			int expectedModuleNumber{ 1 };

			s.AddModule(m);

			Assert::AreEqual(s.GetNumOfModules(), expectedModuleNumber);
		}

		TEST_METHOD(AddModuleTest2) 
		{
			Student s("Matthew", "11/12/2018", "Computer Science", 2);

			int expectedModuleNumber{ 1 };

			s.AddModule("Object Oriented Stuffs", "COM801", 45, 90);

			Assert::AreEqual(s.GetNumOfModules(), expectedModuleNumber);
		}

		TEST_METHOD(CalculateClassification) 
		{
			Student s("Matthew", "11/12/2018", "Computer Science", 2);

			s.AddModule("OOP", "COM326", 15, 65);
			s.AddModule("OOM", "COM121", 15, 74);
			s.AddModule("OOF", "COM191", 15, 82);

			std::string expectedClassification{ "1st class" };


			Assert::AreEqual(s.CalculateClassification(), expectedClassification);
		}

		TEST_METHOD(DeleteModule) 
		{
			Student s("Matthew", "11/12/2018", "Computer Science", 2);
			int expectedNumberOfModules{1};

			s.AddModule("Object Oriented Stuffs", "COM801", 45, 90);
			s.AddModule("Object Oriented Stuffs2", "COM8021", 45, 90);

			s.DeleteModule("COM8021");

			Assert::AreEqual(s.GetNumOfModules(), expectedNumberOfModules);
		}

	};
}