#pragma once
#include <vector>
#include <string>

struct FClass {
public:


	std::string ClassID;
	std::vector<FClass> Parents;

	FClass() = default;

	FClass(std::string id, FClass p) {
		ClassID = id;
		Parents.push_back(p);
	};
	FClass(std::string id) {
		ClassID = id;
		Parents.clear();
	};
	bool IsSameClass(std::string classToCompare) {
		return classToCompare == ClassID;
	}


};


class RTTI
{
public:
	RTTI() = default;
	virtual ~RTTI() = default;
	virtual FClass GetClass() = 0;
};


#define DECLARE_RTTI(ClassID, Parent)\
    virtual FClass GetClass() override {return FClass(#ClassID, {Parent::StaticClass()});};\
    static FClass StaticClass() {return FClass(#ClassID, {Parent::StaticClass()});};

