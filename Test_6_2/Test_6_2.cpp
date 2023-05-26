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
			// Создание объектов спортивной одежды
			ClothingFactory* sportswearFactory = new SportswearFactory();
			Shoes* sneakers = sportswearFactory->createShoes();
			Clothing* sportswear = sportswearFactory->createClothing();

			// Проверка описания спортивной обуви и одежды
			Assert::AreEqual("Кроссовки", sneakers->description().c_str());
			Assert::AreEqual("Спортивный костюм", sportswear->description().c_str());

			delete sneakers;
			delete sportswear;
			delete sportswearFactory;

			// Создание вечерней фабрики и объектов Вечерний наряд
			ClothingFactory* eveningwearFactory = new EveningwearFactory();
			Shoes* dressShoes = eveningwearFactory->createShoes();
			Clothing* tuxedo = eveningwearFactory->createClothing();

			// Проверка описаний вечерней обуви и одежды
			Assert::AreEqual("Туфли", dressShoes->description().c_str());
			Assert::AreEqual("Смокинг", tuxedo->description().c_str());

			delete dressShoes;
			delete tuxedo;
			delete eveningwearFactory;
		}
	};
}
