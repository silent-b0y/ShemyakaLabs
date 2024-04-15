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
    std::cout << dictionary.insert("", "�������");
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
    std::cout << dictionary.insert("word7", "�������");
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  std::cout << "WRONG TRANSLATE INSERT:\n";
  try
  {
    std::cout << dictionary.insert("word", "�������7");
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  std::cout << "SEARCH:\n";
  AVLDictionary dict;
  dict.insert("car", "������");
  dict.insert("ammo", "����������");
  dict.insert("trench", "������");
  dict.insert("year", "���");
  dict.insert("ear", "���");
  dict.insert("cat", "�����");
  dict.insert("dog", "������");
  dict.insert("face", "����");
  dict.insert("team", "�������");
  dict.insert("dream", "�����");
  dict.insert("dream", "���");
  dict.insert("cookie", "�������");
  dict.insert("you", "��");
  dict.insert("you", "��");
  dict.insert("we", "��");
  dict.insert("ad", "�������");
  dict.insert("be", "����");
  dict.insert("do", "������");
  dict.insert("go", "����");
  dict.insert("no", "���");
  dict.insert("or", "���");
  dict.insert("pen", "����");
  dict.insert("oil", "�����");
  dict.insert("owl", "����");
  dict.insert("ten", "������");
  dict.insert("six", "�����");
  dict.insert("oil", "�����");
  dict.insert("one", "����");
  dict.insert("up", "�����");
  dict.insert("day", "����");
  dict.insert("toy", "�������");
  dict.insert("die", "�������");
  dict.insert("eye", "����");
  dict.insert("man", "�������");
  dict.insert("paw", "����");
  dict.insert("hot", "�������");
  dict.insert("us", "���");
  dict.insert("or", "���");
  dict.insert("sun", "������");
  dict.insert("bed", "�������");
  dict.insert("fox", "����");
  dict.insert("fox", "�������");
  dict.insert("fox", "������");
  dict.insert("fox", "���");
  dict.insert("fox", "������");
  dict.insert("fox", "���");
  dict.insert("sea", "����");
  dict.insert("can", "����");
  dict.insert("door", "�����");
  std::cout << dict.search("door");
  std::cout << dict.search("car");
  std::cout << dict.search("ammo");
  std::cout << dict.search("trench");
  std::cout << dict.search("year");
  std::cout << dict.search("ear");
  std::cout << dict.search("nothing") << '\n';
  std::cout << "1 KEY - 36 TRANSLATES:\n";
  AVLDictionary translates;
  std::cout << translates.insert("awesome", "�������");
  std::cout << translates.insert("awesome", "�������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "������������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "������");
  std::cout << translates.insert("awesome", "��������");
  std::cout << translates.insert("awesome", "����������");
  std::cout << translates.insert("awesome", "������������");
  std::cout << translates.insert("awesome", "������������");
  std::cout << translates.insert("awesome", "�������������");
  std::cout << translates.insert("awesome", "��������");
  std::cout << translates.insert("awesome", "������������");
  std::cout << translates.insert("awesome", "�������������");
  std::cout << translates.insert("awesome", "����������������");
  std::cout << translates.insert("awesome", "��������������");
  std::cout << translates.insert("awesome", "���������");
  std::cout << translates.insert("awesome", "������");
  std::cout << translates.insert("awesome", "��������������");
  std::cout << translates.insert("awesome", "��������������");
  std::cout << translates.insert("awesome", "������������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "��������������");
  std::cout << translates.insert("awesome", "��������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "������������������");
  std::cout << translates.insert("awesome", "��������");
  std::cout << translates.insert("awesome", "������������");
  std::cout << translates.insert("awesome", "���������");
  std::cout << translates.insert("awesome", "���������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "�����������");
  std::cout << translates.insert("awesome", "������������") << '\n';
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
