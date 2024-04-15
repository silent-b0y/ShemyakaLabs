#include <iostream>
#include <Windows.h>
#include "AVLDictionary.h"
#include <string>

int main()
{
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  std::cout << "LEFT TURN:\n";
  AVLTree< int, int > tree;
  std::cout << tree.insert(1, 0);
  std::cout << tree.insert(2, 0);
  std::cout << tree.insert(3, 0) << '\n';
  std::cout << "RIGHT TURN:\n";
  AVLTree< int, int > tree2;
  std::cout << tree2.insert(3, 0);
  std::cout << tree2.insert(2, 0);
  std::cout << tree2.insert(1, 0) << '\n';
  std::cout << "BIG LEFT TURN:\n";
  AVLTree< int, int > tree3;
  std::cout << tree3.insert(2, 0);
  std::cout << tree3.insert(1, 0);
  std::cout << tree3.insert(5, 0);
  std::cout << tree3.insert(6, 0);
  std::cout << tree3.insert(4, 0);
  std::cout << tree3.insert(3, 0) << '\n';
  std::cout << "BIG RIGHT TURN:\n";
  AVLTree< int, int > tree4;
  std::cout << tree4.insert(5, 0);
  std::cout << tree4.insert(6, 0);
  std::cout << tree4.insert(2, 0);
  std::cout << tree4.insert(1, 0);
  std::cout << tree4.insert(3, 0);
  std::cout << tree4.insert(4, 0) << '\n';
  std::cout << "CORRECT DELETE:\n";
  AVLTree< int, int > tree5;
  tree5.insert(2, 0);
  tree5.insert(1, 0);
  tree5.insert(3, 0);
  tree5.insert(4, 0);
  std::cout << tree5.deleteKey(1) << '\n';
  AVLDictionary dictionary;
  std::cout << "SEARCH IN EMPTY DICT:\n";
  std::cout << dictionary.search("word") << '\n';
  std::cout << "DELETE IN EMPTY DICT:\n";
  std::cout << dictionary.deleteKey("word") << '\n';
  std::cout << "EMPTY WORD INSERT:\n";
  try
  {
    std::cout << dictionary.insert("", "перевод");
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  std::cout << "EMPTY TRANSLATE INSERT:\n";
  try
  {
    std::cout << dictionary.insert("word", "");
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  std::cout << "WRONG WORD INSERT:\n";
  try
  {
    std::cout << dictionary.insert("word7", "перевод");
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  std::cout << "WRONG TRANSLATE INSERT:\n";
  try
  {
    std::cout << dictionary.insert("word", "перевод7");
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  std::cout << "SEARCH:\n";
  AVLDictionary dict;
  dict.insert("car", "машина");
  dict.insert("ammo", "боеприпасы");
  dict.insert("trench", "канава");
  dict.insert("year", "год");
  dict.insert("ear", "ухо");
  dict.insert("cat", "кошка");
  dict.insert("dog", "собака");
  dict.insert("face", "лицо");
  dict.insert("team", "команда");
  dict.insert("dream", "мечта");
  dict.insert("dream", "сон");
  dict.insert("cookie", "печенье");
  dict.insert("you", "ты");
  dict.insert("you", "вы");
  dict.insert("we", "мы");
  dict.insert("ad", "реклама");
  dict.insert("be", "быть");
  dict.insert("do", "делать");
  dict.insert("go", "идти");
  dict.insert("no", "нет");
  dict.insert("or", "или");
  dict.insert("pen", "перо");
  dict.insert("oil", "масло");
  dict.insert("owl", "сова");
  dict.insert("ten", "десять");
  dict.insert("six", "шесть");
  dict.insert("oil", "масло");
  dict.insert("one", "один");
  dict.insert("up", "вверх");
  dict.insert("day", "день");
  dict.insert("toy", "игрушка");
  dict.insert("die", "умереть");
  dict.insert("eye", "глаз");
  dict.insert("man", "мужчина");
  dict.insert("paw", "лапа");
  dict.insert("hot", "горячий");
  dict.insert("us", "нас");
  dict.insert("or", "или");
  dict.insert("sun", "солнце");
  dict.insert("bed", "кровать");
  dict.insert("fox", "лиса");
  dict.insert("fox", "лисичка");
  dict.insert("fox", "лисица");
  dict.insert("fox", "лис");
  dict.insert("fox", "лисята");
  dict.insert("fox", "лис");
  dict.insert("sea", "море");
  dict.insert("can", "мочь");
  dict.insert("door", "дверь");
  std::cout << dict.search("door");
  std::cout << dict.search("car");
  std::cout << dict.search("ammo");
  std::cout << dict.search("trench");
  std::cout << dict.search("year");
  std::cout << dict.search("ear");
  std::cout << dict.search("nothing") << '\n';
  std::cout << "1 KEY - 36 TRANSLATES:\n";
  AVLDictionary translates;
  std::cout << translates.insert("awesome", "классно");
  std::cout << translates.insert("awesome", "здорово");
  std::cout << translates.insert("awesome", "потрясающий");
  std::cout << translates.insert("awesome", "впечатляющий");
  std::cout << translates.insert("awesome", "устрашающий");
  std::cout << translates.insert("awesome", "крутой");
  std::cout << translates.insert("awesome", "отличный");
  std::cout << translates.insert("awesome", "прекрасный");
  std::cout << translates.insert("awesome", "великолепный");
  std::cout << translates.insert("awesome", "удивительный");
  std::cout << translates.insert("awesome", "замечательный");
  std::cout << translates.insert("awesome", "красивый");
  std::cout << translates.insert("awesome", "изумительный");
  std::cout << translates.insert("awesome", "поразительный");
  std::cout << translates.insert("awesome", "сногсшибательный");
  std::cout << translates.insert("awesome", "ошеломительный");
  std::cout << translates.insert("awesome", "блестящий");
  std::cout << translates.insert("awesome", "дивный");
  std::cout << translates.insert("awesome", "исключительный");
  std::cout << translates.insert("awesome", "фантастический");
  std::cout << translates.insert("awesome", "первосходный");
  std::cout << translates.insert("awesome", "невероятный");
  std::cout << translates.insert("awesome", "восхитительный");
  std::cout << translates.insert("awesome", "чудесный");
  std::cout << translates.insert("awesome", "неимоверный");
  std::cout << translates.insert("awesome", "упоительный");
  std::cout << translates.insert("awesome", "головокружительный");
  std::cout << translates.insert("awesome", "шикарный");
  std::cout << translates.insert("awesome", "грандиозаный");
  std::cout << translates.insert("awesome", "сказочный");
  std::cout << translates.insert("awesome", "волшебный");
  std::cout << translates.insert("awesome", "бесподобный");
  std::cout << translates.insert("awesome", "трагический");
  std::cout << translates.insert("awesome", "драматичный");
  std::cout << translates.insert("awesome", "феерический");
  std::cout << translates.insert("awesome", "баснословный") << '\n';
  std::cout << "TRANSLATE:\n";
  try
  {
    std::cout << translates.translate("awesome", 36) << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  std::cout << "ALL TRANSLATES:\n";
  try
  {
    std::cout << translates.allTranslates("awesome") << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  std::cout << "AMOUNT OF TRANSLATES:\n";
  std::cout << translates.amountOfTranslates("awesome");
  return 0;
}
