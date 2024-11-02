﻿#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "pch.h"
namespace FLATMAP {
    class FlatMap {
    private:
        std::string* values;
        std::string* keys;
        unsigned int sizemap;
        int findKey(const std::string& key) const;
        int findValue(const std::string& value) const;
        std::string& insert(const std::string& key);
        void erase(const int pos);
    public:

        // стандартный конструктор
        FlatMap();

        // конструктор копирования
        FlatMap(const FlatMap& other_map);

        // деструктор
        ~FlatMap();

        // оператор присваивания
        FlatMap& operator=(const FlatMap& other_map);   

        // получить количество элементов в таблице
        std::size_t size() const;

        // доступ / вставка элемента по ключу
        std::string& operator[](const std::string& key);

        // возвращает true, если запись с таким ключом присутствует в таблице
        bool contains(const std::string& key);

        // удаление элемента по ключу, возвращает количество удаленных элементов (0 или 1)
        std::size_t erase(const std::string& key);

        // очистка таблицы, после которой size() возвращает 0, а contains() - false на любой ключ
        void clear();
    };
}