#include "pch.h"
#include "FlatMap.h"
using namespace FLATMAP;

int FlatMap::findKey(const std::string& key) const {
	if (sizemap == 0) {
		return -1;
	}
	int left = 0, right = sizemap - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (keys[mid] == key) {
			return mid;
		}
		else if (keys[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
};

int FlatMap::findValue(const std::string& value) const {
	if (sizemap == 0) {
		return -1;
	}
	int left = 0, right = sizemap - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (keys[mid] == value) {
			return mid;
		}
		else if (keys[mid] > value) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
};

std::string& FlatMap::insert(const std::string& key) {
	if (sizemap == 0) {
		delete[] values;
		delete[] keys;
		sizemap = 1;
		values = new std::string[1];
		keys = new std::string[1];
		keys[0] = key;
		values[0] = "";
		return values[0];
	}
	int pos = 0;
	for (int i = 0; pos < sizemap && keys[i] < key; i++) {
		++pos;
	}

	if (pos == sizemap) {
		std::string* intermediate;
		intermediate = new std::string[sizemap + 1];
		std::copy(values, values + sizemap, intermediate);
		intermediate[pos] = "";
		delete[] values;

		values = new std::string[sizemap + 1];
		std::copy(intermediate, intermediate + sizemap + 1, values);
		delete[] intermediate;

		intermediate = new std::string[sizemap + 1];
		std::copy(keys, keys + sizemap, intermediate);
		intermediate[sizemap] = key;
		delete[] keys;

		keys = new std::string[sizemap + 1];
		std::copy(intermediate, intermediate + sizemap + 1, keys);
		delete[] intermediate;


		++sizemap;
		return values[pos];
	}

	std::string* intermediate;
	intermediate = new std::string[sizemap + 1];
	std::copy(values, values + pos, intermediate);
	std::copy(values + pos, values + sizemap, intermediate + pos + 1);
	intermediate[pos] = "";
	delete[] values;

	values = new std::string[sizemap + 1];
	std::copy(intermediate, intermediate + sizemap + 1, values);
	delete[] intermediate;

	intermediate = new std::string[sizemap + 1];
	std::copy(keys, keys + pos, intermediate);
	std::copy(keys + pos, keys + sizemap, intermediate + pos + 1);
	intermediate[pos] = key;
	delete[] keys;

	keys = new std::string[sizemap + 1];
	std::copy(intermediate, intermediate + sizemap + 1, keys);
	delete[] intermediate;


	++sizemap;
	return values[pos];
};

FlatMap::FlatMap() {
	sizemap = 0;
	values = new std::string[sizemap];
	keys = new std::string[sizemap];
};

FlatMap::FlatMap(const FlatMap& other_map) {
	values = new std::string[other_map.sizemap];
	keys = new std::string[other_map.sizemap];
	std::copy(other_map.keys, other_map.keys + other_map.sizemap, keys);
	std::copy(other_map.values, other_map.values + other_map.sizemap, values);
	sizemap = other_map.sizemap;
};

FlatMap::~FlatMap() {
	delete[] values;
	delete[] keys;
};

FlatMap& FlatMap::operator=(const FlatMap& other_map) {
	delete[] keys;
	delete[] values;
	sizemap = other_map.sizemap;
	values = new std::string[sizemap];
	keys = new std::string[sizemap];
	std::copy(other_map.values, other_map.values + sizemap, values);
	std::copy(other_map.keys, other_map.keys + sizemap, keys);
	return *this;
};

std::size_t FlatMap::size() const {
	return sizemap;
};

std::string& FlatMap::operator[](const std::string& key) {
	int positionkey = findKey(key);
	if (positionkey == -1) {
		return insert(key);
	}
	else {
		return values[positionkey];
	}
};

bool FlatMap::contains(const std::string& key) {
	if (findKey(key) >= 0) {
		return true;
	}
	else {
		return false;
	}
};


void FlatMap::erase(int pos) {
	if (sizemap == 1) {
		delete[] keys;
		delete[] values;
		sizemap = 0;
		values = new std::string[0];
		keys = new std::string[0];
		return;
	}

	std::string* intermediate;
	intermediate = new std::string[sizemap - 1];
	std::copy(values, values + pos, intermediate);
	std::copy(values + pos + 1, values + sizemap, intermediate + pos);
	delete[] values;

	values = new std::string[sizemap - 1];
	std::copy(intermediate, intermediate + sizemap - 1, values);
	delete[] intermediate;

	intermediate = new std::string[sizemap - 1];
	std::copy(keys, keys + pos, intermediate);
	std::copy(keys + pos + 1, keys + sizemap, intermediate + pos);
	delete[] keys;

	keys = new std::string[sizemap - 1];
	std::copy(intermediate, intermediate + sizemap - 1, keys);
	delete[] intermediate;


	--sizemap;
};

std::size_t FlatMap::erase(const std::string& key) {
	int pos = findKey(key);
	if (pos == -1) {
		return 0;
	}

	erase(pos);

	return 1;
};

void FlatMap::clear() {
	delete[] keys;
	delete[] values;
	sizemap = 0;
};