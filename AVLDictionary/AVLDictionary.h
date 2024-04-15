#ifndef AVLDICTIONARY_H
#define AVLDICTIONARY_H

#include "AVLTree.h"
#include "DictionaryList.h"
#include <string>

class AVLDictionary
{
public:
  AVLDictionary() :
    dict_(AVLTree< std::string, DictionaryList< std::string > >())
  {}
  bool insert(const std::string&, const std::string&);
  bool search(const std::string&) const;
  bool deleteKey(const std::string&);
  int amountOfTranslates(const std::string&);
  const std::string& translate(const std::string&, int);
  const DictionaryList< std::string >& allTranslates(const std::string&);
private:
  AVLTree< std::string, DictionaryList< std::string > > dict_;
};

#endif
