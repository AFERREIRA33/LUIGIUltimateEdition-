#pragma once
#include <iostream>

struct FClass {
public:
	std::string ClassID;
	FClass* Parent;
	FClass(std::string id, FClass p) {
		ClassID = id;
		Parent = &p;
	};
	FClass(std::string id) {
		ClassID = id;
		Parent = nullptr;
	};
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

