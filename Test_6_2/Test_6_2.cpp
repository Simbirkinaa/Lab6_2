#include "pch.h"
#include <stdio.h>
#include "CppUnitTest.h"
#include "..\Lab6_2\Lab6_2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test62
{
	TEST_CLASS(Test62)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// �������� �������� ���������� ������
			ClothingFactory* sportswearFactory = new SportswearFactory();
			Shoes* sneakers = sportswearFactory->createShoes();
			Clothing* sportswear = sportswearFactory->createClothing();

			// �������� �������� ���������� ����� � ������
			Assert::AreEqual("���������", sneakers->description().c_str());
			Assert::AreEqual("���������� ������", sportswear->description().c_str());

			delete sneakers;
			delete sportswear;
			delete sportswearFactory;

			// �������� �������� ������� � �������� �������� �����
			ClothingFactory* eveningwearFactory = new EveningwearFactory();
			Shoes* dressShoes = eveningwearFactory->createShoes();
			Clothing* tuxedo = eveningwearFactory->createClothing();

			// �������� �������� �������� ����� � ������
			Assert::AreEqual("�����", dressShoes->description().c_str());
			Assert::AreEqual("�������", tuxedo->description().c_str());

			delete dressShoes;
			delete tuxedo;
			delete eveningwearFactory;
		}
	};
}
