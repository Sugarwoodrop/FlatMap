1 Лабораторная НГУ ФИТ 2 курс.
Есть недочёты и места в которые можно исправить, но в общем для первой работы на c++ нормально.

Класс ассоциативного массива (другие названия: map, словарь, таблица, мэпа) на основе отсортированного массива и бинарного поиска по нему.

В качестве ключей и значений контейнер принимает строки (std::string).

Нужно реализовать как минимум следующие методы:

class FlatMap {
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
}
Класс хранит записи в одном (или нескольких) массивах, детали продумайте сами. Запрещается использовать контейнеры STL (кроме std::string). 
Это должны быть обычные массивы, которые вы создаете с помощью оператора new[] и удаляете оператором delete[].
Класс обеспечивает логарифмическую сложность (O(logN)) доступа по ключу (operator[] в случае, когда ключ уже есть, contains) за счет бинарного поиска.
Сложность вставки (operator[] в случае, когда ключа еще нет) и удаления (erase) элементов - линейная.
