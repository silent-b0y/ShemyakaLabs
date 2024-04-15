#include "AVLDictionary.h"
#include "AVLDictExceptions.h"

bool AVLDictionary::insert(const std::string& word, const std::string& translate)
{
  if (word == "")
  {
    throw EmptyWord();
  }
  if (translate == "")
  {
    throw EmptyTranslate();
  }
  for (char c : word)
  {
    if (!isalpha(c))
    {
      throw WrongWord();
    }
  }
  for (char c : translate)
  {
    if (!(c >= 'À' && c <= 'ÿ') )
    {
      throw WrongTranslate();
    }
  }
  bool inserted = dict_.insert(word, DictionaryList< std::string >());
  AVLTree< std::string, DictionaryList< std::string > >::Node* node = dict_.search(word);
  if (!inserted)
  {
    bool found = node->data_.search(translate);
    if (!found)
    {
      node->data_.insert(translate);
      return true;
    }
    return false;
  }
  node->data_.insert(translate);
  return true;
}

bool AVLDictionary::search(const std::string& word) const
{
  if (word == "")
  {
    throw EmptyWord();
  }
  for (char c : word)
  {
    if (!(std::tolower(c) >= 97 && std::tolower(c) <= 122))
    {
      throw WrongWord();
    }
  }
  if (dict_.search(word) != nullptr)
  {
    return true;
  }
  return false;
}

bool AVLDictionary::deleteKey(const std::string& word)
{
  if (word == "")
  {
    throw EmptyWord();
  }
  for (char c : word)
  {
    if (!(std::tolower(c) >= 97 && std::tolower(c) <= 122))
    {
      throw WrongWord();
    }
  }
  if (dict_.deleteKey(word))
  {
    return true;
  }
  return false;
}

int AVLDictionary::amountOfTranslates(const std::string& word)
{
  if (word == "")
  {
    throw EmptyWord();
  }
  for (char c : word)
  {
    if (!isalpha(c))
    {
      throw WrongWord();
    }
  }
  AVLTree< std::string, DictionaryList< std::string > >::Node* node = dict_.search(word);
  if (node != nullptr)
  {
    return node->data_.size();
  }
  throw NoWord();
}

const std::string& AVLDictionary::translate(const std::string& word, int num)
{
  if (word == "")
  {
    throw EmptyWord();
  }
  for (char c : word)
  {
    if (!isalpha(c))
    {
      throw WrongWord();
    }
  }
  if (num < 1)
  {
    throw WrongTranslate();
  }
  AVLTree< std::string, DictionaryList< std::string > >::Node* node = dict_.search(word);
  if (node != nullptr)
  {
    DictionaryList< std::string >::Node* translate = node->data_.head();
    int counter = 1;
    while (translate != nullptr && counter != num)
    {
      ++counter;
      translate = translate->next;
    }
    if (translate != nullptr)
    {
      return translate->key;
    }
    throw NoTranslate();
  }
  throw NoWord();
}

const DictionaryList<std::string>& AVLDictionary::allTranslates(const std::string& word)
{
  if (word == "")
  {
    throw EmptyWord();
  }
  for (char c : word)
  {
    if (!isalpha(c))
    {
      throw WrongWord();
    }
  }
  AVLTree< std::string, DictionaryList< std::string > >::Node* node = dict_.search(word);
  if (node != nullptr)
  {
    return node->data_;
  }
  throw NoWord();
}
